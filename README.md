# cpp11-ndc-libs

C++11 用のよく使用する基本ライブラリ群を定義しています。

# 機能一覧

1. Noise 機能
2. HeightMap 操作
3. Random 機能
4. TimeWatch 機能
5. Crypt/Decrypt 機能
6. Hash 機能
7. File 操作機能




# 環境構築

- gcc コンパイル用
- gtest 自動テスト用


# gtest インストール

wget 'https://github.com/google/googletest/archive/release-1.8.1.tar.gz'
tar zxvf release-1.8.1.tar.gz
mkdir -p /usr/local/src
ll
cd googletest-release-1.8.1/
ls
mkdir build
cd build
cmake ..
make
make install # 権限ないと失敗。手動で header と lib を取得可能

以下がコンパイルされている
/tmp/googletest-release-1.8.1/build/googlemock/
   gtest/libgtest.a
   gtest/libgtest_main.a
   libgmock.a
   libgmock_main.a

インクルードファイルはいか
/tmp/googletest-release-1.8.1/googlemock/include/*
/tmp/googletest-release-1.8.1/googletest/include/*

コピーする
mkdir -p {PROJECT}/lib/dev/gtest/include
cp -r /tmp/googletest-release-1.8.1/googlemock/include/* ./lib/dev/gtest/include

mkdir -p {PROJECT}/lib/dev/gtest/lib
cp -r /tmp/googletest-release-1.8.1/googletest/include/* ./lib/dev/gtest/include

cp /tmp/googletest-release-1.8.1/build/googlemock/gtest/libgtest*.a ./lib/dev/gtest/lib/
cp /tmp/googletest-release-1.8.1/build/googlemock/libgmock*.a ./lib/dev/gtest/lib/

テストの実行
> g++ add.cc add_test.cc -o test -I /workspaces/cpp11-ndc-libs/lib/dev/gtest/include -L /workspaces/cpp11-ndc-libs/lib/dev/gtest/lib -g -pthread -lgtest_main -lgtest
> ./test  （これでテスト結果を出力）

