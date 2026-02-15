cmake_minimum_required(VERSION 4.1)
project(blocconote)

set(CMAKE_CXX_STANDARD 20)

add_executable(blocconote main.cpp
        subject.h
        observer.h
        Note.h
        Note.cpp
        Collezione.h
        Collezione.cpp
        ContatoreNote.h
        ContatoreNote.cpp
        NoteImportanti.h
        NoteImportanti.cpp)
