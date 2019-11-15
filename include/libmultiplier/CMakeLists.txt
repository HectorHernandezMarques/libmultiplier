add_simple_library(libmultiplier_include_libmultiplier INTERFACE)

install(DIRECTORY .
        DESTINATION include/${PROJECT_NAME}/${PROJECT_VERSION}
        FILES_MATCHING
        PATTERN "*.h"
        )