cmake_minimum_required(VERSION 3.0)
project(students_db)

include(FetchContent)
FetchContent_Declare(
        cryptopp
        GIT_REPOSITORY https://github.com/weidai11/cryptopp.git

)
FetchContent_GetProperties(cryptopp)
if (NOT cryptopp_POPULATED)
    FetchContent_Populate(cryptopp)


    file(DOWNLOAD https://raw.githubusercontent.com/noloader/cryptopp-cmake/master/CMakeLists.txt ${cryptopp_SOURCE_DIR}/CMakeLists.txt)
    file(DOWNLOAD https://raw.githubusercontent.com/noloader/cryptopp-cmake/master/cryptopp-config.cmake ${cryptopp_SOURCE_DIR}/cryptopp-config.cmake)
    add_subdirectory(${cryptopp_SOURCE_DIR} ${cryptopp_BINARY_DIR})
endif ()


FetchContent_MakeAvailable(cryptopp)


set(CMAKE_CXX_STANDARD 17)
add_executable(students_db main.cpp Data/Student.h Data/StudentsContainer.h Data/Human.h ERROR_CODES.h Data/Date.h Savable.h Data/SessionsContainer.h Data/MainStudentContainer.h encrypt.h decrypt.h generate_student.h)


target_link_libraries(${PROJECT_NAME} cryptopp-static)