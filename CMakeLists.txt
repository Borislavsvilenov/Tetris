cmake_minimum_required(VERSION 3.30)
project(Tetris CXX)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)

function(include_dependency libName gitURL gitTag)
    FetchContent_Declare(${libName}
            GIT_REPOSITORY ${gitURL}
            GIT_TAG        ${gitTag}
            GIT_SHALLOW    TRUE
            GIT_PROGRESS   TRUE
    )

    FetchContent_MakeAvailable(${libName})
endfunction()

set(LIB1 raylib)
find_package(${LIB1} QUIET)
if (NOT ${LIB1}_FOUND)
    message(STATUS "Getting ${LIB1} from Github")
    include_dependency(${LIB1} https://github.com/raysan5/raylib.git 5.5)
else()
    message(STATUS "Using local ${LIB1}")
endif()

add_executable(${PROJECT_NAME} main.cpp
        UI/UI.cpp
        UI/UI.hpp
        Vector/Vec2.cpp
        Vector/Vec2.hpp
        UI/Element.cpp
        UI/Element.hpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${raylib_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} PRIVATE ${LIB1})