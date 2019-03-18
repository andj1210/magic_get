# Copyright (c) 2019 Andreas Jung
#
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

cmake_minimum_required (VERSION 3.0)
project (pfrTest)

set( CMAKE_CXX_FLAGS  "/std:c++latest /permissive- /EHsc")

# add the executable
add_executable(pfr_msvc
test_main.cpp
test_pfr.cpp
)

include_directories(../include)