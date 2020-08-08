cmake_minimum_required (VERSION 3.0)

# print switch
set (DEBUG_MSG true)

#*********** Common Configurationr ***********
#--------begin if----------
if (NOT PROJECT_PATH)
set (CURRENT_PATH ${CMAKE_SOURCE_DIR})
find_path (TEMP_PATH cmake_common.txt ${CURRENT_PATH}/Linux/Project)
#--------begin while----------
while (NOT TEMP_PATH)
set (CURRENT_PATH ${CURRENT_PATH}/..)
find_path (TEMP_PATH cmake_common.txt ${CURRENT_PATH}/Linux/Project)
if (${DEBUG_MSG})
message("CURRENT_PATH: " ${CURRENT_PATH})
message (STATUS "TEMP_PATH: ${TEMP_PATH}")
endif(${DEBUG_MSG})
endwhile(NOT TEMP_PATH)
#--------end while----------
endif(NOT PROJECT_PATH)
#--------end if----------
set (PROJECT_PATH ${TEMP_PATH})
if (NOT ROOT_PATH)
  set (ROOT_PATH ${PROJECT_PATH}/../../../..)
endif()
# include common setting
include (${PROJECT_PATH}/cmake_common.txt)
#*********************************************

project (ut)

# set cpp list
aux_source_directory(. SRC_LIST)
aux_source_directory(../fun SRC_LIST)
#set (SRC_LIST *.cpp)
set (TARGET_NAME demo_ut)
# create execute file
add_executable (${TARGET_NAME} ${SRC_LIST})

# link library
target_link_libraries (${TARGET_NAME} gtest pthread)
