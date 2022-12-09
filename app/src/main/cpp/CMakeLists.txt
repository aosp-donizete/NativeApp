cmake_minimum_required(VERSION 3.18.1)

project(native-app)

set(CMAKE_SHARED_LINKER_FLAGS
        "${CMAKE_SHARED_LINKER_FLAGS} -u ANativeActivity_onCreate")

add_library( # Sets the name of the library.
        native-activity

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        main-lib.cpp)

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

target_link_libraries( # Specifies the target library.
        native-activity

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})