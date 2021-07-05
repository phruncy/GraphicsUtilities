set(targetName ${PROJECT_NAME}_lib)

add_library(${targetName} INTERFACE "Vector3.h")

target_include_directories(${targetName} INTERFACE "${PROJECT_SOURCE_DIR}/src")

#installing the library
install(TARGETS ${targetName} DESTINATION lib)
install(FILES "Vector3.h" DESTINATION include)