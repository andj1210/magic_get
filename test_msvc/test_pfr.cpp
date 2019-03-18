// Copyright (c) 2019 Andreas Jung
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// some tests, only to check for specific MSVC issues with magic_get, i.e. not compiling at all or C1202

#define BOOST_PFR_USE_CPP17 1
#include <boost/pfr.hpp>
#include <array>
#include <stdint.h>
#include <iostream>
#include "catch.hpp"

// OK for MSVC 2017 w/o permissive-
struct StructSz255
{
	std::array<uint8_t, 255> array;
};

// Crash for MSVC 2017 w/o permissive-, OK for MSVC 2017/2019 with permissive-
struct StructSz256
{
	std::array<uint8_t, 256> array;
};

//OK for MSVC 2017 / 2019 with permissive -
struct StructSz512
{
	std::array<uint8_t, 512> array;
};

//crash for MSVC 2017 / 2019 with permissive -
struct StructSz513
{
	std::array<uint8_t, 513> array;
};

TEST_CASE("Structure 255")
{
	StructSz255 test;

	REQUIRE(boost::pfr::tuple_size_v<StructSz255> == 255);
}

