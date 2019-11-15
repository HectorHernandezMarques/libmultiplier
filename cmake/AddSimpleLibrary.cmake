function(add_simple_library)
    add_library(${ARGN})

    target_include_directories(${ARGV0}
            INTERFACE
            $<INSTALL_INTERFACE:include/${PROJECT_NAME}/${PROJECT_VERSION}>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
            )

    if (NOT ${ARGV1} STREQUAL INTERFACE)
        set_target_properties(${ARGV0} PROPERTIES
                POSITION_INDEPENDENT_CODE ON
                )

        if (MSVC)
            target_compile_options(${ARGV0}
                    PRIVATE
                    -W4
                    -WX
                    )
        else ()
            target_compile_options(${ARGV0}
                    PRIVATE
                    -Wall
                    -Wextra
                    -Werror
                    -pedantic
                    )
        endif ()
    endif ()

endfunction()