@echo off

mkdir ..\build
pushd ..\build
cl /FC /EHsc /MDd /D_ITERATOR_DEBUG_LEVEL=2 /I ..\submodules\SFML\include ..\src\main.cpp /DSFML_STATIC /link /LIBPATH:"C:\Program Files (x86)\Windows Kits\10\Lib\10.0.17763.0\um\x64" OpenGL32.lib WinMM.lib Gdi32.lib user32.lib advapi32.lib /LIBPATH:"../submodules/SFML/extlibs/libs-msvc-universal/x64" OpenAL32.lib flac.lib vorbisfile.lib ogg.lib vorbisenc.lib vorbis.lib /LIBPATH:"../submodules/build/SFML/lib/Debug" sfml-main-d.lib sfml-system-s-d.lib sfml-window-s-d.lib sfml-graphics-s-d.lib sfml-audio-s-d.lib
popd