find_package(LibAdder 2.0.2 EXACT REQUIRED)

add_library(libmultiplier_lib OBJECT
        Multiplier.cpp
        )

target_include_directories(libmultiplier_lib
        INTERFACE
            $<INSTALL_INTERFACE:include>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        )

target_link_libraries(libmultiplier_lib
        PRIVATE
            libmultiplier_include_libmultiplier
            LibAdder::libadder_static
        )
