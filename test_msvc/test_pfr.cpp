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

//crash for MSVC 2017 / 2019 with permissive - (until patches)
struct StructSz513
{
	std::array<uint8_t, 513> array;
};

// OK for (MSVC 2017 /) 2019 with permissive - with patches
struct BigStruct
{
	std::array<uint8_t, 2048> array;
	unsigned u0;
	unsigned u1;
	unsigned u2;
	unsigned u3;
	unsigned u4;
	unsigned u5;
	unsigned u6;
	unsigned u7;
	unsigned u8;
	unsigned u9;
	unsigned u10;
	unsigned u11;
};

TEST_CASE("Structure 255")
{
	StructSz255 test;

	REQUIRE(sizeof(StructSz255) == 255);
	REQUIRE(boost::pfr::tuple_size_v<StructSz255> == 1);
}

TEST_CASE("Structure 256")
{
	StructSz256 test;

	REQUIRE(sizeof(StructSz256) == 256);
	REQUIRE(boost::pfr::tuple_size_v<StructSz256> == 1);
}

TEST_CASE("Structure 512")
{
	StructSz512 test;

	REQUIRE(sizeof(StructSz512) == 512);
	REQUIRE(boost::pfr::tuple_size_v<StructSz512> == 1);
}

template <class T, std::size_t N, class = boost::pfr::detail::enable_if_constructible_helper_t<T, N>>
void fun(long)
{}

template<class T, std::size_t N>
void fun(int)
{}

TEST_CASE("Structure 513")
{
	StructSz513 test;

	REQUIRE(sizeof(StructSz513) == 513);

	fun<StructSz513, 1024>(1L); // no C1202
	//fun<StructSz513, 1025>(1L); // C1202

	REQUIRE(boost::pfr::tuple_size_v<StructSz513> == 1); // used to be C1202 
}

TEST_CASE("BigStruct")
{
	BigStruct test;	
	REQUIRE(boost::pfr::tuple_size_v<BigStruct> == 1); // C1202 freedom
}


