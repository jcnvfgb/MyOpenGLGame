@echo off

if not exist build (
    mkdir build
    echo The "build" folder has been successfully created
)

cd build

cmake ..

pause