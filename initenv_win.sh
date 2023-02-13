# Windows + MinGW + gcc 環境で gtest を実行可能な環境を構築する
# 前提: git, mingw, cmake, make(mingw32-make) を choco でインストールしておくこと
rm -rf ./tmp/*
cd tmp
git clone https://github.com/google/googletest.git
cd googletest
mkdir build
cd build
cmake -G "MinGW Makefiles" ..
# コンパイル実施
make

# 出来上がったライブラリをプロジェクト参照先ライブラリのパスにコピー
cd ../../../
rm -rf lib/dev/gtest/lib/*
cp -r tmp/googletest/build/lib/lib*.a lib/dev/gtest/lib/

rm -rf lib/dev/gtest/include/*
cp -r tmp/googletest/googlemock/include/gmock lib/dev/gtest/include/
cp -r tmp/googletest/googletest/include/gtest lib/dev/gtest/include/
rm -rf tmp/*
