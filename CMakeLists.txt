cmake_minimum_required (VERSION 2.6)
project (moonstone)

add_definitions(-Wno-c++11-extensions)

# GLOB the files
file(GLOB_RECURSE HEADER_FILES RELATIVE "${PROJECT_SOURCE_DIR}" ${PROJECT_SOURCE_DIR}/include/*.h)
file(GLOB_RECURSE SRC_FILES RELATIVE "${PROJECT_SOURCE_DIR}" ${PROJECT_SOURCE_DIR}/src/*.cpp)

# Include all directories
foreach(CURRENT_FILE ${HEADER_FILES} ${SRC_FILES})
	get_filename_component(CURRENT_PATH ${CURRENT_FILE} PATH)
	set(INCLUDE_DIRS ${INCLUDE_DIRS} ${CURRENT_PATH})
endforeach()

include_directories(${INCLUDE_DIRS})

add_executable(Moonstone ${SRC_FILES} ${HEADER_FILES})

# Create the project directories for the files.
foreach(CURRENT_FILE ${HEADER_FILES} ${SRC_FILES})
	get_filename_component(CURRENT_PATH ${CURRENT_FILE} PATH)
	get_filename_component(CURRENT_NAME ${CURRENT_FILE} NAME)
	string(REPLACE "/" "\\\\" PARSED_PATH ${CURRENT_PATH})
	source_group(${PARSED_PATH} FILES ${CURRENT_FILE})
endforeach()