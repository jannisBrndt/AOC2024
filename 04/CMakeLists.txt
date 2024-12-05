cmake_minimum_required(VERSION 3.10)

project(04)

file(GLOB_RECURSE SOURCES "src/*.cpp")

file(GLOB_RECURSE HEADERS "include/*.h")

include_directories(include)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

set_target_properties(${PROJECT_NAME} PROPERTIES 
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

target_compile_options(${PROJECT_NAME} PRIVATE
  $<$<CONFIG:Debug>:-g3 -O0>
  $<$<CONFIG:Release>:-O3>
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
  $<$<CONFIG:Debug>:DEBUG>
)
