cmake_minimum_required(VERSION 2.9)
project(particleDB)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
set(CMAKE_ENABLE_EXPORTS)


# fix rpath for OSX
set(CMAKE_MACOSX_RPATH 1)
option(USE_ABSOLUTE_RPATH "Add absolute rpath to all libraries and executables" ON)
if(APPLE OR USE_ABSOLUTE_RPATH)
	set(CMAKE_SKIP_BUILD_RPATH  FALSE)
	set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
	set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
	set(ABSOLUTE_RPATH "${CMAKE_INSTALL_PREFIX}/lib${LIB_SUFFIX}")
	if(NOT IS_ABSOLUTE ${ABSOLUTE_RPATH})
		set(ABSOLUTE_RPATH ${CMAKE_BINARY_DIR}/${ABSOLUTE_RPATH})
	endif()
	list(FIND CMAKE_PLATFORM_IMPLICIT_LINK_DIRECTORIES "${ABSOLUTE_RPATH}" isSystemDir)
	if("${isSystemDir}" STREQUAL "-1")
		message(STATUS "Use absolute RPATH ${ABSOLUTE_RPATH}")
		set(CMAKE_INSTALL_RPATH "${ABSOLUTE_RPATH}")
	endif("${isSystemDir}" STREQUAL "-1")
endif()


add_library(particleDB SHARED
	src/utilities.cpp
	src/io.cpp
	src/particle.cpp
	src/database.cpp
)

target_include_directories(particleDB PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(particleDB PROPERTIES COMPILE_FLAGS "-fPIC")

option(BUILD_EXAMPLES "Build examples" OFF)
if(BUILD_EXAMPLES)
	add_executable(example1 examples/example1.cpp)
	target_link_libraries(example1 particleDB)

	add_executable(example2 examples/example2.cpp)
	target_link_libraries(example2 particleDB)
endif(BUILD_EXAMPLES)


# install
add_definitions(-DPARTICLEDB_INSTALL_PREFIX="${CMAKE_INSTALL_PREFIX}")
add_definitions(-DPARTICLEDB_DATA_PATH="${PROJECT_SOURCE_DIR}/data/")
install(TARGETS particleDB DESTINATION lib)
install(DIRECTORY include/ DESTINATION include FILES_MATCHING PATTERN "*.h")
install(DIRECTORY data/ DESTINATION data PATTERN ".git" EXCLUDE)

