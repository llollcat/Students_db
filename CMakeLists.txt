cmake_minimum_required(VERSION 2.9)
project(students_db)

find_package(Git REQUIRED)

if (NOT EXISTS "${CMAKE_SOURCE_DIR}/cryptopp")
    execute_process(
            COMMAND "${GIT_EXECUTABLE}" clone https://github.com/weidai11/cryptopp.git
            WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
    )
    execute_process(COMMAND wget -O CMakeLists.txt https://raw.githubusercontent.com/noloader/cryptopp-cmake/master/CMakeLists.txt
            WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/cryptopp"
            )
    execute_process(COMMAND wget -O cryptopp-config.cmake https://raw.githubusercontent.com/noloader/cryptopp-cmake/master/cryptopp-config.cmake
            WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/cryptopp"
            )
endif ()

add_subdirectory(cryptopp)

set(CMAKE_CXX_STANDARD 17)
add_executable(students_db main.cpp Data/Student.h Data/StudentsContainer.h Data/Human.h ERROR_CODES.h Data/Date.h Savable.h Data/SessionsContainer.h Data/MainStudentContainer.h encrypt.h decrypt.h)

target_link_libraries(${PROJECT_NAME} cryptopp-static)