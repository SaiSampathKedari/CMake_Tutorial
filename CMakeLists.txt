cmake_minimum_required(VERSION 3.16.3)

project(OLAS VERSION 1.0) # (VERSION 1.0) we want the source code know what version
add_executable(${PROJECT_NAME} main.cpp)


# adder use logic
option(USE_ADDER "A simple library for adding 2 floats." ON)
if(USE_ADDER)
    add_subdirectory(Adder)

    # list(APPEND EXTRA_LIBS Adder)
    # list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/Adder")

    target_include_directories(${PROJECT_NAME} PUBLIC Adder)
    target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_BINARY_DIR}/Adder)
    target_link_libraries(${PROJECT_NAME} adder)
endif()

configure_file(OLASConfig.h.in OLASConfig.h)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})


# # DOWNLOAD ALL THE SUBMODULES

# find_package(Git QUIET)
# if(GIT_FOUND and EXISTS "${PROJECT_SOURCE_DIR}/.git")
# #Update submodules as needed
#     option(GIT_SUBMODULE "Check submodules during build" ON)
#     if(GIT_SUBMODULE)
#         message(STATUS "Submodule update")
#         execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --int --recursive
#                         WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
#                         RESULT_VARIABLE GIT_SUBMOD_RESULT)
#         if(NOT GIT_SUBMOD_RESULT EQUAL "0")
#             message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
#         endif()
#     endif()
# endif()

# # CHECK ALL THE SUBMODULES


# add_subdirectory(external/glfw)


install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/OLASConfig.h" DESTINATION include)

