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
mkdir ../publish/libs
mkdir ../publish/includes
mv *a ../publish/libs

# make directories of include files
cd ../src/

# create dirs recursively
find . -type d | xargs -I{} mkdir -p ../publish/includes/{}

# copy include files to publish
find ./ -type f | grep .hpp | xargs -I{} cp {} ../publish/includes/{}
