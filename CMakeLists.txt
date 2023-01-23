cmake_minimum_required(VERSION 3.21)

set(acc_VERSION 1.8.12)

project(acc
        VERSION ${acc_VERSION}
        DESCRIPTION "Assetto Corsa Competizione shared memory"
        HOMEPAGE_URL "https://github.com/wilrickrt/acc"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
option(BUILD_EXAMPLES "Build examples" OFF)

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

## Static builds on Windows
if (MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

include_directories(include)
add_subdirectory(src)
if (BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()


## Project installation
configure_package_config_file(cmake/config.cmake.in
	${CMAKE_CURRENT_BINARY_DIR}/wrt-acc-config.cmake
	INSTALL_DESTINATION ${CMAKE_INSTALL_DATADIR}/wrt-acc
	NO_SET_AND_CHECK_MACRO)

write_basic_package_version_file(
	${CMAKE_CURRENT_BINARY_DIR}/wrt-acc-config-version.cmake
	VERSION ${acc_VERSION}
	COMPATIBILITY SameMajorVersion)

# CMake files
install(
	FILES
		${CMAKE_CURRENT_BINARY_DIR}/wrt-acc-config.cmake
		${CMAKE_CURRENT_BINARY_DIR}/wrt-acc-config-version.cmake
	DESTINATION
		${CMAKE_INSTALL_DATADIR}/wrt-acc)
# Include directories
install(
    DIRECTORY include/ 
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
# Targets
install(EXPORT wrt-acc-targets
	NAMESPACE wrt::
	DESTINATION ${CMAKE_INSTALL_DATADIR}/wrt-acc)
