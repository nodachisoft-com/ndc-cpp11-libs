CC="g++"
CLAGS="-g -pthread"

TEST_INCDIR="-I./lib/dev/gtest/include -I./lib/dev"
TEST_LIBDIR="-L./lib/dev/gtest/lib"
TEST_LIBS="-lgtest_main -lgtest"


mkdir ./tmp/compile/src/
find ./src/ -type d | xargs -I{} mkdir -p ./tmp/compile/{}
find ./src/ -name *.cpp | xargs -I{} gcc -c {} -o ./tmp/compile/{}.o
find ./test/ -type d | xargs -I{} mkdir -p ./tmp/compile/{}
find ./test/ -name test_*.cpp | xargs -I{} gcc -c {} -o ./tmp/compile/{}.o ${TEST_INCDIR}
find ./tmp/compile/ -name *.o -print0 | xargs -0 | xargs -I{} ${CC} ${CFLAGS} {} -o ./tmp/compile/test.exe ${TEST_LIBDIR} ${TEST_LIBS}
./tmp/compile/test.exe
