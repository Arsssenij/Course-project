cmake_minimum_required(VERSION 3.14)

project(Course-project)
set(CMAKE_OBJECT_PATH_MAX 250)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Указываем исходные файлы для main, палиндрома и тестов
set(MAIN_SOURCES src/main.cpp src/palindrome.cpp)  # Добавили palindrome.cpp для основной программы
set(TEST_SOURCES src/tests.cpp src/palindrome.cpp)  # Добавили palindrome.cpp для тестов

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

# Добавление исполняемых файлов
add_executable(main ${MAIN_SOURCES})
add_executable(tests ${TEST_SOURCES})
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
