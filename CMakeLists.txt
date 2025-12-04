cmake_minimum_required(VERSION 3.16)
project(studentai)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include katalogai
include_directories(.)

# Biblioteka iš projektų failų
add_library(studentas_lib
	funkcijos.cpp
	skaiciavimai.cpp
	studentas.cpp
	spausdinimas.cpp
	failu_skaitymas.cpp
	failu_generavimas.cpp
)

# Pagrindinė programa
add_executable(studentas_programa  main.cpp)
target_link_libraries(studentas_programa PRIVATE studentas_lib)


# Google test integracija
include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
	DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Unit testų programa
add_executable(unit_tests tests/test_studentas.cpp)
target_link_libraries(unit_tests PRIVATE studentas_lib gtest gtest_main)

add_test(NAME AllTests COMMAND unit_tests)
