CMAKE_MINIMUM_REQUIRED(VERSION 3.25 FATAL_ERROR)
PROJECT(TEST_APP_C)

SET(APP_NAME "test-app-c")
SET(APP_NAMESPACE "${APP_NAME}::")
SET(APP_VERSION 1.0.0)

FIND_PACKAGE(CMLIB COMPONENTS CMDEF CMUTIL STORAGE REQUIRED)

# Dependencies
BA_PACKAGE_LIBRARY(test-package-a v1.0.0)
BA_PACKAGE_LIBRARY(test-package-b v1.0.0)
BA_PACKAGE_LIBRARY(test-package-d v1.0.0)
BA_PACKAGE_LIBRARY(test-package-e v1.0.0)

FIND_PACKAGE(test-package-a-shared 1.0.0 REQUIRED)
FIND_PACKAGE(test-package-b-shared 1.0.0 REQUIRED)
FIND_PACKAGE(test-package-d-shared 1.0.0 REQUIRED)
FIND_PACKAGE(test-package-e-shared 1.0.0 REQUIRED)

CMDEF_ADD_EXECUTABLE(
    TARGET ${APP_NAME}
    SOURCES main.cpp
    VERSION ${APP_VERSION}
)

TARGET_LINK_LIBRARIES(
    ${APP_NAME}
    PRIVATE
    test-package-a-shared::test-package-a-shared
    test-package-b-shared::test-package-b-shared
    test-package-d-shared::test-package-d-shared
    test-package-e-shared::test-package-e-shared
)

CMDEF_INSTALL(
    TARGET ${APP_NAME}
    NAMESPACE ${APP_NAMESPACE}
)

CMDEF_PACKAGE(
    MAIN_TARGET ${APP_NAME}
    VERSION ${APP_VERSION}
)
