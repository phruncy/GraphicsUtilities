add_library(${PROJECT_NAME}_lib INTERFACE "Vector3.h")

target_include_directories(${PROJECT_NAME}_lib INTERFACE "${PROJECT_SOURCE_DIR}/src")