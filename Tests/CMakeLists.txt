# add submodules 
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        message(${PROJECT_SOURCE_DIR})
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/googletest/CMakeLists.txt")
    message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()



# name the test binary
set (TEST_BINARY ${PROJECT_NAME}_test)
# test executable
add_executable(${TEST_BINARY}
    "Vector3Test.cpp"
    "main.cpp"
)

target_include_directories(${TEST_BINARY} PUBLIC ${PROJECT_SOURCE_DIR}/src)

# add test and set its execution (tat is running the test executable)
add_test(NAME ${TEST_BINARY} COMMAND ${TEST_BINARY})

# link library to be tested
target_link_libraries(${TEST_BINARY} PUBLIC ${PROJECT_NAME}_lib gtest)
