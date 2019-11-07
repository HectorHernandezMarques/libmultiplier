add_library(libmultiplier_include_libmultiplier INTERFACE)

target_include_directories(libmultiplier_include_libmultiplier
        INTERFACE
            $<INSTALL_INTERFACE:include>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        )

install(DIRECTORY .
        DESTINATION include
        FILES_MATCHING
        PATTERN "*.h"
        )