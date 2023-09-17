cmake_minimum_required(VERSION 2.9)

project(particleDB)


set(CMAKE_MACOSX_RPATH 1)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_library(particleDB SHARED
	src/utilities.cpp
	src/io.cpp
	src/particle.cpp
	src/database.cpp
)

# message(STATUS ${CMAKE_CURRENT_SOURCE_DIR})
# message(STATUS ${PROJECT_SOURCE_DIR})

target_include_directories(particleDB PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(particleDB PROPERTIES COMPILE_FLAGS "-fPIC")


# example
add_executable(example1 examples/example1.cpp)
target_link_libraries(example1 particleDB)


add_definitions(-DPARTICLES_INSTALL_PREFIX="${CMAKE_INSTALL_PREFIX}")
# install(TARGETS particles DESTINATION lib)
# install(DIRECTORY include/ DESTINATION include FILES_MATCHING PATTERN "*.h")
# install(DIRECTORY ${CMAKE_BINARY_DIR}/include/ DESTINATION include FILES_MATCHING PATTERN "*.h")
# install(DIRECTORY ${CMAKE_BINARY_DIR}/data/ DESTINATION share/particles/ PATTERN ".git" EXCLUDE)

install(TARGETS particleDB DESTINATION lib)
install(DIRECTORY include/ DESTINATION include FILES_MATCHING PATTERN "*.h")
install(DIRECTORY ${PROJECT_SOURCE_DIR}/data/ DESTINATION data PATTERN ".git" EXCLUDE)
