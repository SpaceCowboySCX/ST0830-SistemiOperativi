cmake_minimum_required(VERSION 3.22)
project(ST0830_O_S_Project C)

set(CMAKE_C_STANDARD 11)

include_directories(Steno)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")
add_executable(ST0830_O_S_Project
            Steno/byteType.h
            Steno/main.c
            Steno/utilities.c Steno/utilities.h
            Steno/commandList.h Steno/commandList.c
            Steno/stenography.c Steno/stenography.h
            Steno/list.c Steno/list.h
            Steno/manageFile.c Steno/manageFile.h
            Steno/implementationThread.c Steno/implementationThread.h
            )
