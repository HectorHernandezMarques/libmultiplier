find_package(LibAdder 2.0.8 EXACT REQUIRED)

add_simple_library(libmultiplier_lib OBJECT
        Multiplier.cpp
        )

target_link_libraries(libmultiplier_lib
        PRIVATE
            LibAdder::libadder_static
            libmultiplier_include_libmultiplier
        )
