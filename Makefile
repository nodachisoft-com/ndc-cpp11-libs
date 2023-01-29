# コンパイラ
CC  = g++
# コンパイルオプション
CFLAGS    = -g
CFLAGS   += -pthread

# 実行ファイル名
RUN_TEST_EXEC_FILE  = ./debug/test.out

# コンパイル対象のソースコード一覧を作成
# SECROOTから再帰的にソースファイルを検索 し
SRCROOT = ./src
SOURCES = $(shell find $(SRCROOT) -type f -name "*.cpp")


# テスト対象のソースコード
TEST_SRCROOT = ./test
TEST_SOURCES = $(shell find $(TEST_SRCROOT) -type f -name "test_*.cpp")


# オブジェクトファイル名
# OBJS    = $(SRCS:.cpp=.o)

# インクルードファイルのあるディレクトリパス
INCDIR  = -I./lib/dev/gtest/include # Google Test 用インクルード
INCDIR += -I./lib/prod/cereal-1.3.2/include # Cereal 用

# ライブラリファイルのあるディレクトリパス
LIBDIR  = -L./lib/dev/gtest/lib	# Google Test 用ライブラリ

# 追加するライブラリファイル
LIBS    = -lgtest_main
LIBS   += -lgtest

# ターゲット：コンパイル＆リンク で Google Test 実行ファイルを作成
$(RUN_TEST_EXEC_FILE): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) $(TEST_SOURCES) -o $(RUN_TEST_EXEC_FILE) $(INCDIR) $(LIBDIR) $(LIBS)


# テスト用ソースコードのコンパイル＆実行
all: clean $(RUN_TEST_EXEC_FILE) runtest

# 一時ファイル、実行ファイルを削除
clean:
	-rm -f $(RUN_TEST_EXEC_FILE)

# Google Test の実行
runtest:
	$(RUN_TEST_EXEC_FILE)
