cmake_minimum_required(VERSION 3.24)
project(CPP_Task_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(CPP_Task_2 main.cpp Sources/SystemElement.cpp Headers/SystemElement.h Sources/File.cpp Headers/File.h Sources/Dir.cpp Headers/Dir.h Sources/Link.cpp Headers/Link.h Sources/SymbolicLink.cpp Headers/SymbolicLink.h Sources/HardLink.cpp Headers/HardLink.h Sources/FileSystem.cpp Headers/FileSystem.h Sources/FileSystemModeling.cpp Headers/FileSystemModeling.h)
