# Copyright 2020 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

########################################################################
# Check if there is C++ code at all
########################################################################
if(NOT kb3gtn_sources)
    MESSAGE(STATUS "No C++ sources... skipping python bindings")
    return()
endif(NOT kb3gtn_sources)

########################################################################
# Check for pygccxml
########################################################################
GR_PYTHON_CHECK_MODULE_RAW(
    "pygccxml"
    "import pygccxml"
    PYGCCXML_FOUND
    )

include(GrPybind)

########################################################################
# Python Bindings
########################################################################

list(APPEND kb3gtn_python_files
    win_min_max_python.cc python_bindings.cc)

GR_PYBIND_MAKE_OOT(kb3gtn
   ../../..
   gr::kb3gtn
   "${kb3gtn_python_files}")

# copy in bindings .so file for use in QA test module
add_custom_target(
  copy_bindings_for_tests ALL
  COMMAND
    ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/*.so"
    ${CMAKE_BINARY_DIR}/test_modules/gnuradio/kb3gtn/
  DEPENDS kb3gtn_python)

install(TARGETS kb3gtn_python DESTINATION ${GR_PYTHON_DIR}/gnuradio/kb3gtn COMPONENT pythonapi)
