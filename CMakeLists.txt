cmake_minimum_required(VERSION 3.20)

# Enable Hot Reload for MSVC compilers if supported.
if(POLICY CMP0141)
    cmake_policy(SET CMP0141 NEW)
    set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project(statistics-app VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(statistics-lib
    src/statistics-app.cpp
    src/statistics-lib.cpp
)

target_include_directories(statistics-lib PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(statistics-app app/main.cpp)
target_link_libraries(statistics-app PRIVATE statistics-lib)

set_property(TARGET statistics-app PROPERTY CXX_STANDARD 23)

include(CTest)
enable_testing()
add_executable(statistics-tests "tests/statistics-tests.cpp")
target_link_libraries(statistics-tests PRIVATE statistics-lib)

add_test(NAME statistics-tests COMMAND statistics-test)
