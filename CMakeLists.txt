cmake_minimum_required (VERSION 2.8)
project (polynomial)

include(CTest)

include ("../build/base.cmake")
include ("../build/gtest.cmake")

message("PROJECT ${PROJECT_SOURCE_DIR}")
set(HEADER_PATH "${PROJECT_SOURCE_DIR}/include" )
set(SOURCE_PATH ${PROJECT_SOURCE_DIR}/src)
set(DIST_PATH ${PROJECT_SOURCE_DIR}/dist)
set(DIST_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/dist/include)
set(PROJECT_TEST_DIR ${PROJECT_SOURCE_DIR}/test)


include_directories("${HEADER_PATH}")
include_directories("${BASE_PATH}/nativearray/dist/include")
include_directories(/usr/include)

#add_library(polynomial SHARED IMPORTED)
# set_property(TARGET nativearray PROPERTY IMPORTED_LOCATION "${BASE_PATH}/nativearray/dist/libnativearray.so")

add_library(polynomial SHARED 
		${SOURCE_PATH}/Polynomial.cpp
		)


add_executable(polynomial_test ${PROJECT_TEST_DIR}/Polynomial_test.cpp)
target_link_libraries(polynomial_test pthread ${GTEST_BOTH_LIBRARIES} polynomial)

add_test( polynomial_test polynomial_test )


#install (TARGETS numina DESTINATION ${DIST_PATH})
#install (FILES ${HEADER_PATH}/.h DESTINATION ${DIST_INCLUDE_PATH})
