cmake_minimum_required(VERSION 3.17)
project(untitled)

set(CMAKE_CXX_STANDARD 17)
add_executable(untitled main.cpp Data/Student.h Data/StudentsContainer.h Data/Human.h ERROR_CODES.h Data/Date.h Savable.h Data/SessionsContainer.h Data/MainStudentContainer.h)