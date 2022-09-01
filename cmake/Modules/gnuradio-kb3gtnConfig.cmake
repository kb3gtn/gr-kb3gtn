find_package(PkgConfig)

PKG_CHECK_MODULES(PC_GR_KB3GTN gnuradio-kb3gtn)

FIND_PATH(
    GR_KB3GTN_INCLUDE_DIRS
    NAMES gnuradio/kb3gtn/api.h
    HINTS $ENV{KB3GTN_DIR}/include
        ${PC_KB3GTN_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    GR_KB3GTN_LIBRARIES
    NAMES gnuradio-kb3gtn
    HINTS $ENV{KB3GTN_DIR}/lib
        ${PC_KB3GTN_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/gnuradio-kb3gtnTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GR_KB3GTN DEFAULT_MSG GR_KB3GTN_LIBRARIES GR_KB3GTN_INCLUDE_DIRS)
MARK_AS_ADVANCED(GR_KB3GTN_LIBRARIES GR_KB3GTN_INCLUDE_DIRS)
