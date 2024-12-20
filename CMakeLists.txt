cmake_minimum_required(VERSION 3.14) 

project(Course-project) 
set(SOURCE_FILES D:/univer/Course-project/src/*.cpp)
set(CMAKE_OBJECT_PATH_MAX 250)

set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавление исходников Catch2 через FetchContent
include(FetchContent)
FetchContent_Declare(
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.3.2
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(Catch2)

# Добавление исполняемого файла и подключение Catch2
add_executable(tests main.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
target_include_directories(tests PRIVATE ${CMAKE_BINARY_DIR}/_deps/catch2-src/src)

# Регистрация тестов
include(CTest)
include(Catch)
catch_discover_tests(tests)
