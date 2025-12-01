CMAKE_MINIMUM_REQUIRED(VERSION 3.25 FATAL_ERROR)
PROJECT(TEST_APP_3)

SET(APP_NAME "test-app-3")
SET(APP_NAMESPACE "${APP_NAME}::")
SET(APP_VERSION 1.0.0)

FIND_PACKAGE(CMLIB COMPONENTS CMDEF CMUTIL STORAGE REQUIRED)

# Dependencies
BA_PACKAGE_LIBRARY(test_package_1 v1.0.0)
BA_PACKAGE_LIBRARY(test_package_2 v1.0.0)
BA_PACKAGE_LIBRARY(test_package_4 v1.0.0)
BA_PACKAGE_LIBRARY(test_package_5 v1.0.0)

FIND_PACKAGE(test-package-1-shared 1.0.0 REQUIRED)
FIND_PACKAGE(test-package-2-shared 1.0.0 REQUIRED)
FIND_PACKAGE(test-package-4-shared 1.0.0 REQUIRED)
FIND_PACKAGE(test-package-5-shared 1.0.0 REQUIRED)

CMDEF_ADD_EXECUTABLE(
    TARGET ${APP_NAME}
    SOURCES main.cpp
    VERSION ${APP_VERSION}
)

TARGET_LINK_LIBRARIES(
    ${APP_NAME}
    PRIVATE
    test-package-1-shared::test-package-1-shared
    test-package-2-shared::test-package-2-shared
    test-package-4-shared::test-package-4-shared
    test-package-5-shared::test-package-5-shared
)

CMDEF_INSTALL(
    TARGET ${APP_NAME}
    NAMESPACE ${APP_NAMESPACE}
)
BA_PACKAGE_DEPS_IMPORTED(${APP_NAME})

CMDEF_PACKAGE(
    MAIN_TARGET ${APP_NAME}
    VERSION ${APP_VERSION}
)
