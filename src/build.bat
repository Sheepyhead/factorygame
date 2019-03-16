@echo off

mkdir ..\build
pushd ..\build
cl -FC -Zi ..\src\main.cpp user32.lib
popd