include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2
    GIT_TAG v3.7.1 
)
FetchContent_MakeAvailable(Catch2)

# Подключение Catch2 как тестовой библиотеки
target_link_libraries(YourTarget PRIVATE Catch2::Catch2WithMain)
