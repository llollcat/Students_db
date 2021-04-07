cmake_minimum_required(VERSION 3.17)
project(untitled)

set(CMAKE_CXX_STANDARD 17)
add_executable(untitled main.cpp Data/Student.h Data/StudentsManager.h Data/Human.h ERROR_CODES.h Data/Date.h IO/IOManager.h IO/AbstactClasses/Savable.h IO/AbstactClasses/Outputable.h IO/DataKeeper.h Includes.h Data/SessionsContainer.h)