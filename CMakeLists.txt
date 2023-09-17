cmake_minimum_required(VERSION 2.9)

project(particles)


set(CMAKE_MACOSX_RPATH 1)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_library(particles SHARED
	src/utilities.cpp
	src/io.cpp
	src/particle.cpp
	src/database.cpp
)

# message(STATUS ${CMAKE_CURRENT_SOURCE_DIR})
# message(STATUS ${PROJECT_SOURCE_DIR})

target_include_directories(particles PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(particles PROPERTIES COMPILE_FLAGS "-fPIC")


# example
add_executable(example examples/example1.cpp)
target_link_libraries(example particles )
# target_compile_options(example particles PUBLIC ${particles})

# add_executable(testGalacticMagneticLens test/testMagneticLens.cpp)
# target_link_libraries(testGalacticMagneticLens crpropa gtest gtest_main pthread ${COVERAGE_LIBS})


add_definitions(-DPARTICLES_INSTALL_PREFIX="${CMAKE_INSTALL_PREFIX}")
# install(TARGETS particles DESTINATION lib)
# install(DIRECTORY include/ DESTINATION include FILES_MATCHING PATTERN "*.h")
# install(DIRECTORY ${CMAKE_BINARY_DIR}/include/ DESTINATION include FILES_MATCHING PATTERN "*.h")
# install(DIRECTORY ${CMAKE_BINARY_DIR}/data/ DESTINATION share/particles/ PATTERN ".git" EXCLUDE)

install(TARGETS particles DESTINATION lib)
install(DIRECTORY include/ DESTINATION include FILES_MATCHING PATTERN "*.h")
install(DIRECTORY ${PROJECT_SOURCE_DIR}/data/ DESTINATION data/particles/ PATTERN ".git" EXCLUDE)
