cmake_minimum_required(VERSION 3.20)
project(blocconote)

set(CMAKE_CXX_STANDARD 20)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(LOGICA_PROGETTO
        Note.cpp
        Collezione.cpp
        ContatoreNote.cpp
        NoteImportanti.cpp
)

add_executable(blocconote main.cpp ${LOGICA_PROGETTO})

add_executable(esegui_test ${CMAKE_CURRENT_SOURCE_DIR}/test_note.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test_collezione.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test_contatorenote.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test_noteimportanti.cpp
        ${LOGICA_PROGETTO}
)

target_link_libraries(esegui_test GTest::gtest GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(esegui_test)