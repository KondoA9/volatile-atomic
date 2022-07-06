cmake_minimum_required (VERSION 3.1)

enable_language(CXX)
enable_testing()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(THREADS_PREFER_PTHREAD_FLAG ON)              
find_package(Threads REQUIRED)    

if (MSVC)
	set(CMAKE_CXX_FLAGS "/W4 /EHsc")
else()
	set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wno-unknown-pragmas")
endif()

project(project)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ../bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ../bin)

include_directories(
	"./include/"
)

add_executable(project "src/main.cpp")
add_test(NAME project COMMAND project)

target_link_libraries(project PUBLIC "-pthread")