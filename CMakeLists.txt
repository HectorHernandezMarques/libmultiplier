cmake_minimum_required(VERSION 3.14.7)
set(CMAKE_CXX_STANDARD 17)

project(libmultiplier
        VERSION 1.0.3
        LANGUAGES CXX
        )

include(cmake/AddSimpleLibrary.cmake)
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
        PREFIX ""
        OUTPUT_NAME libmultiplier_static_$<CONFIG>
        OUTPUT_NAME_RELEASE libmultiplier_static
        SUFFIX ${CMAKE_STATIC_LIBRARY_SUFFIX}.${PROJECT_VERSION}
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
        PREFIX ""
        OUTPUT_NAME libmultiplier_$<CONFIG>
        OUTPUT_NAME_RELEASE libmultiplier
        SUFFIX ${CMAKE_SHARED_LIBRARY_SUFFIX}.${PROJECT_VERSION}
        )

# Installation
set(LIBMULTIPLIER_CMAKE_INSTALL_DIR lib/cmake/LibMultiplier-${PROJECT_VERSION})

install(TARGETS
            libmultiplier
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
            ${LIBMULTIPLIER_CMAKE_INSTALL_DIR}
        )

include(CMakePackageConfigHelpers)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/LibMultiplierConfigVersion.cmake
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY AnyNewerVersion
        )

configure_package_config_file(cmake/LibMultiplierConfig.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/LibMultiplierConfig.cmake
        INSTALL_DESTINATION ${LIBMULTIPLIER_CMAKE_INSTALL_DIR}
        )

install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/LibMultiplierConfig.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/LibMultiplierConfigVersion.cmake
        DESTINATION ${LIBMULTIPLIER_CMAKE_INSTALL_DIR}
        )