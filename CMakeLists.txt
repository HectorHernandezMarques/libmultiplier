cmake_minimum_required(VERSION 3.14.7)

project(libmultiplier
        VERSION 1.0.0
        LANGUAGES CXX
        )

add_subdirectory(include)
add_subdirectory(lib)
add_subdirectory(test)

# Static library
add_library(libmultiplier_static STATIC)

target_link_libraries(libmultiplier_static
        PUBLIC
            libmultiplier_include_libmultiplier
        PRIVATE
            libmultiplier_lib
        )

set_target_properties(libmultiplier_static PROPERTIES
        POSITION_INDEPENDENT_CODE ON
        OUTPUT_NAME "libmultiplier_static_$<CONFIG>"
        OUTPUT_NAME_RELEASE "libmultiplier_static"
        )

# Shared library
add_library(libmultiplier SHARED)

target_link_libraries(libmultiplier
        PUBLIC
            libmultiplier_include_libmultiplier
        PRIVATE
            libmultiplier_lib
        )

set_target_properties(libmultiplier PROPERTIES
        POSITION_INDEPENDENT_CODE ON
        OUTPUT_NAME "libmultiplier_$<CONFIG>"
        OUTPUT_NAME_RELEASE "libmultiplier"
        )

install(TARGETS
            #libmultiplier
            libmultiplier_static
            libmultiplier_lib
            libmultiplier_include_libmultiplier
        EXPORT libmultiplier_export
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static
        )

install(EXPORT libmultiplier_export
        FILE
            LibMultiplierTargets.cmake
        NAMESPACE
            LibMultiplier::
        DESTINATION
            cmake/LibMultiplier
        )

include(CMakePackageConfigHelpers)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/LibMultiplierConfigVersion.cmake
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY AnyNewerVersion
        )

configure_package_config_file(cmake/LibMultiplierConfig.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/LibMultiplierConfig.cmake
        INSTALL_DESTINATION cmake/LibMultiplier
        )

install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/LibMultiplierConfig.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/LibMultiplierConfigVersion.cmake
        DESTINATION cmake/LibMultiplier
        )