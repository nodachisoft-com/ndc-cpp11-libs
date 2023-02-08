#/usr/bin/sh

# Clean
rm -rf ./debug/*

# create compile script
cd ./debug
find ../src/ -name *.cpp | xargs gcc -c

# Create DLL
ar rcs libNdclibs.a *.o
rm -f *.o
