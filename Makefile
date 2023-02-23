# =========================================================================
# 主要なターゲットは以下の通り。
#
#  make test       : 本体プログラム、テストコード をコンパイルし単体テスト実行
#  make publish    : 最終出力先のプログラム（ライブラリ）、includes を作成
#  make clean      : 生成物を全てクリアする
#


# コンパイラ
CXX  = g++

# コンパイルオプション
#  -g         : デバッグ情報付与
#  -pthread   : std::thread 利用
#  -std=c++17 : C++17 規格でコンパイル
#  -Wall      : 警告を出力
CFLAGS    = -g
CFLAGS   += -pthread
CFLAGS   += -std=c++17
CFLAGS   += -Wall

# テストコード用コンパイルオプション
TEST_CLAGS = -pthread
TEST_CLAGS = -std=c++17

# デバッグ用メッセージの ESCAPE SEQUENCE カラー設定
MSG_B="\033[0;36m[INFO `date "+%H:%M:%S"`] "
MSG_E=" \033[0m"

# お試しエントリポイント用実行ファイル名
RUN_TMP_ENTRY_EXEC_FILE  = ./debug/tmp_entry.out

# コンパイル対象のソースコード一覧を作成
# SECROOTから再帰的にソースファイルを検索 し
OBJROOT = tmp/compile/src
ifeq "$(strip $(OBJROOT))" ""
	OBJROOT=.
endif

# ===============================================
# プログラム本体のソースコード、ターゲット設定
# SECROOTから再帰的にソースファイルを検索する
SRCROOT = src
SRCDIRS = $(shell find $(SRCROOT) -type d)
SOURCES = $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.cpp))

OBJSRCS = $(SOURCES:$(SRCROOT)/%=%)
OBJECTS = $(addprefix $(OBJROOT)/, $(OBJSRCS:.cpp=.o))

DEPENDS = $(OBJECTS:.o=.d)

# ===============================================
# テスト用 SRC / OBJECT を定義
TEST_OBJROOT = tmp/compile/test
ifeq "$(strip $(TEST_OBJROOT))" ""
	TEST_OBJROOT=.
endif

TEST_SRCROOT = test
TEST_SRCDIRS = $(shell find $(TEST_SRCROOT) -type d)
TEST_SOURCES = $(foreach dir, $(TEST_SRCDIRS), $(wildcard $(dir)/test_*.cpp))

TEST_OBJSRCS = $(TEST_SOURCES:$(TEST_SRCROOT)/%=%)
TEST_OBJECTS = $(addprefix $(TEST_OBJROOT)/, $(TEST_OBJSRCS:.cpp=.o))

# ===============================================
# 本番ライブラリ出力用 ビルド設定
# ライブラリを生成し、リリース用 include ファイルを publish にコピーする
PUBLISH_TARGET = ./publish/libs/libNdclibs.a
$(PUBLISH_TARGET): $(OBJECTS)
	@echo -e ${MSG_B}============================================${MSG_E}
	@echo -e ${MSG_B}Publishing Library files and Includes files.${MSG_E}
	@echo -e ${MSG_B}============================================${MSG_E}
	-mkdir ./publish/libs
	ar rcs $@ $^
	-mkdir ./publish/includes
	find ./src -type d | xargs -I{} mkdir -p ./publish/includes/{}
	find ./src -type f -name "*.hpp" | xargs -I{} cp {} ./publish/includes/{}
	@echo -e ${MSG_B}DONE.${MSG_E}

.PHONY: ObjectTargetFlow
ObjectTargetFlow: ObjectPre $(OBJECTS)
	@echo -e ${MSG_B}DONE.${MSG_E}

.PHONY: ObjectPre
ObjectPre:
	@echo -e ${MSG_B}Compile Sources.${MSG_E}

# ===============================================
# 単体テスト実行用 ビルド設定
# Google Test 用実行プログラムを生成する
TEST_TARGET = ./debug/test.out
$(TEST_TARGET): ObjectTargetFlow TestTargetPre TestTargetMain
		@echo -e ${MSG_B}DONE.${MSG_E}

.PHONY: TestTargetPre
TestTargetPre:
	@echo -e ${MSG_B}Compile Test Sources.${MSG_E}

# テスト用オブジェクト、メインモジュール用オブジェクトをリンクして UT 用 EXE を出力する
.PHONY: TestTargetMain
TestTargetMain: $(TEST_OBJECTS) $(OBJECTS)
	@echo -e ${MSG_B}Compile DONE.${MSG_E}
	@echo -e ${MSG_B}Linking Unit-Test Executable.${MSG_E}
	$(CXX) $(CFLAGS) -L./lib/dev/gtest/lib  -lgtest_main -lgtest -o $(TEST_TARGET) $^

# src 内のビルド（cpp → object）定義
$(OBJROOT)/%.o : $(SRCROOT)/%.cpp
	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
	$(CXX) $(CFLAGS) -o $@ -c $<

# test 内のビルド（cpp → object）定義
$(TEST_OBJROOT)/%.o : $(TEST_SRCROOT)/%.cpp
	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
	$(CXX) $(TEST_CLAGS) -I./lib/dev/gtest/include -I./lib/dev  -o $@ -c $<

publish: $(PUBLISH_TARGET)
	@echo -e ${MSG_B}Publish DONE.${MSG_E}

.PHONY: clean_publish
clean_publish:
	@echo -e ${MSG_B}Clean publish contents.${MSG_E}
	-rm -rf ./publish/libs ./publish/includes
	@echo -e ${MSG_B}DONE.${MSG_E}

test: $(TEST_TARGET) clean_test
	@echo -e ${MSG_B}Exec Test.${MSG_E}
	$(TEST_TARGET)
	@echo -e ${MSG_B}DONE.${MSG_E}

.PHONY: clean_test
clean_test:
	@echo -e ${MSG_B}Clear Debug Objects like BMP,TXT,BIN, etc..${MSG_E}
	-rm -f ./debug/*.bmp ./debug/*.txt ./debug/*.bin
	@echo -e ${MSG_B}DONE.${MSG_E}

.PHONY: clean_objects
clean_objects:
	@echo -e ${MSG_B}Clear c++ compiled objects files BEGIN.${MSG_E}
	-rm -rf ./tmp/compile/src/* ./tmp/compile/test/*
	@echo -e ${MSG_B}DONE.${MSG_E}

.PHONY: clean
clean: clean_publish clean_test clean_objects
	@echo -e ${MSG_B}Clear All Test Files, Objects Files, Temp Files, DONE.${MSG_E}

-include $(DEPENDS)
