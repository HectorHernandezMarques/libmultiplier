add_subdirectory(googletest)

add_executable(libmultiplier_test
        MultiplierTs.cpp
        )

target_link_libraries(libmultiplier_test
        PRIVATE
            libmultiplier_include_libmultiplier
            libmultiplier_static
            gtest_main
        )

add_test(NAME libmultiplier_test
        COMMAND libmultiplier_test
        )