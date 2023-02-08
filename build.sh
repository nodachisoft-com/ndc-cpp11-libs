#/usr/bin/sh

# Clean
rm -rf ./debug/*
rm -rf ./publish/*

# create compile script
cd ./debug
find ../src/ -name *.cpp | xargs gcc -c

# Create DLL
ar rcs libNdclibs.a *.o
rm -f *.o

# copy to publish dirs
mv *a ../publish
