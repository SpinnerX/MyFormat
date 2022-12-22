# Set the project name
set(PROJECT_NAME Formatter)
SET(CMAKE_CXX_FLAGS "-std=c++20")

project (${PROJECT_NAME})

# Add a library with the above sources
# add_library(${PROJECT_NAME} src/Logger.cpp)
add_library(${PROJECT_NAME} INTERFACE)
add_library(Form:Form1 ALIAS ${PROJECT_NAME}) # This is the alias that we used in "PersonalizedLogger" folder

# What this does is let us access all the include directories through these folders.
# This is what lets us do these kinds of includes #include <LoggerMessage.h>
target_include_directories( ${PROJECT_NAME}
    INTERFACE ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/include/format
    ${PROJECT_SOURCE_DIR}/include/details
    ${PROJECT_SOURCE_DIR}/include/core
    ${PROJECT_SOURCE_DIR}/include/timer
)
