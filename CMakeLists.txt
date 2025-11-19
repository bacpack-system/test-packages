CMAKE_MINIMUM_REQUIRED(VERSION 3.25 FATAL_ERROR)
PROJECT(TEST_PACKAGES)

OPTION(USE_PACKAGE_1 "Use test_package_1" OFF)
OPTION(USE_PACKAGE_2 "Use test_package_2" OFF)

if(USE_PACKAGE_1)
    MESSAGE(STATUS "Building test_package_2")
    ADD_SUBDIRECTORY(test_package_1)
elseif(USE_PACKAGE_2)
    MESSAGE(STATUS "Building test_package_2")
    ADD_SUBDIRECTORY(test_package_2)
endif()