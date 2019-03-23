// Copyright (c) 2019 Andreas Jung
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// some tests, only to check for specific MSVC issues with magic_get, i.e. not compiling at all or C1202

#define BOOST_PFR_USE_CPP17 1
#include <boost/pfr.hpp>
#include <stdint.h>
#include <array>
#include <random>
#include <algorithm>
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
};

TEST_CASE("boost::pfr Structure 255")
{
    StructSz255 test;

    REQUIRE(sizeof(StructSz255) == 255);
    REQUIRE(boost::pfr::tuple_size_v<StructSz255> == 1);
}

TEST_CASE("boost::pfr Structure 256")
{
    StructSz256 test;

    REQUIRE(sizeof(StructSz256) == 256);
    REQUIRE(boost::pfr::tuple_size_v<StructSz256> == 1);
}

TEST_CASE("boost::pfr Structure 512")
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

TEST_CASE("boost::pfr Structure 513")
{
    StructSz513 test;

    REQUIRE(sizeof(StructSz513) == 513);

    fun<StructSz513, 1024>(1L); // no C1202
    //fun<StructSz513, 1025>(1L); // C1202

    REQUIRE(boost::pfr::tuple_size_v<StructSz513> == 1); // used to be C1202 
}

TEST_CASE("boost::pfr BigStruct")
{
    BigStruct test;
    REQUIRE(boost::pfr::tuple_size_v<BigStruct> == 1); // C1202 freedom
}

// maximum boost::pfr::for_each_field size that works w/o compiler error (by experiment)
struct Struct85
{
    int field0; int field1; int field2; int field3; int field4; int field5; int field6; int field7; int field8; int field9; int field10; int field11; int field12; int field13; int field14; int field15;
    int field16; int field17; int field18; int field19; int field20; int field21; int field22; int field23; int field24; int field25; int field26; int field27; int field28; int field29; int field30; int field31;
    int field32; int field33; int field34; int field35; int field36; int field37; int field38; int field39; int field40; int field41; int field42; int field43; int field44; int field45; int field46; int field47;
    int field48; int field49; int field50; int field51; int field52; int field53; int field54; int field55; int field56; int field57; int field58; int field59; int field60; int field61; int field62; int field63;
    int field64; int field65; int field66; int field67; int field68; int field69; int field70; int field71; int field72; int field73; int field74; int field75; int field76; int field77; int field78; int field79;
    int field80; int field81; int field82; int field83; int field84;
};

// maximum boost::pfr::tuple_size_v w/o bug
struct Struct341
{
    int field0; int field1; int field2; int field3; int field4; int field5; int field6; int field7; int field8; int field9; int field10; int field11; int field12; int field13; int field14; int field15;
    int field16; int field17; int field18; int field19; int field20; int field21; int field22; int field23; int field24; int field25; int field26; int field27; int field28; int field29; int field30; int field31;
    int field32; int field33; int field34; int field35; int field36; int field37; int field38; int field39; int field40; int field41; int field42; int field43; int field44; int field45; int field46; int field47;
    int field48; int field49; int field50; int field51; int field52; int field53; int field54; int field55; int field56; int field57; int field58; int field59; int field60; int field61; int field62; int field63;
    int field64; int field65; int field66; int field67; int field68; int field69; int field70; int field71; int field72; int field73; int field74; int field75; int field76; int field77; int field78; int field79;
    int field80; int field81; int field82; int field83; int field84; int field85; int field86; int field87; int field88; int field89; int field90; int field91; int field92; int field93; int field94; int field95;
    int field96; int field97; int field98; int field99; int field100; int field101; int field102; int field103; int field104; int field105; int field106; int field107; int field108; int field109; int field110; int field111;
    int field112; int field113; int field114; int field115; int field116; int field117; int field118; int field119; int field120; int field121; int field122; int field123; int field124; int field125; int field126; int field127;
    int field128; int field129; int field130; int field131; int field132; int field133; int field134; int field135; int field136; int field137; int field138; int field139; int field140; int field141; int field142; int field143;
    int field144; int field145; int field146; int field147; int field148; int field149; int field150; int field151; int field152; int field153; int field154; int field155; int field156; int field157; int field158; int field159;
    int field160; int field161; int field162; int field163; int field164; int field165; int field166; int field167; int field168; int field169; int field170; int field171; int field172; int field173; int field174; int field175;
    int field176; int field177; int field178; int field179; int field180; int field181; int field182; int field183; int field184; int field185; int field186; int field187; int field188; int field189; int field190; int field191;
    int field192; int field193; int field194; int field195; int field196; int field197; int field198; int field199; int field200; int field201; int field202; int field203; int field204; int field205; int field206; int field207;
    int field208; int field209; int field210; int field211; int field212; int field213; int field214; int field215; int field216; int field217; int field218; int field219; int field220; int field221; int field222; int field223;
    int field224; int field225; int field226; int field227; int field228; int field229; int field230; int field231; int field232; int field233; int field234; int field235; int field236; int field237; int field238; int field239;
    int field240; int field241; int field242; int field243; int field244; int field245; int field246; int field247; int field248; int field249; int field250; int field251; int field252; int field253; int field254; int field255;
    int field256; int field257; int field258; int field259; int field260; int field261; int field262; int field263; int field264; int field265; int field266; int field267; int field268; int field269; int field270; int field271;
    int field272; int field273; int field274; int field275; int field276; int field277; int field278; int field279; int field280; int field281; int field282; int field283; int field284; int field285; int field286; int field287;
    int field288; int field289; int field290; int field291; int field292; int field293; int field294; int field295; int field296; int field297; int field298; int field299; int field300; int field301; int field302; int field303;
    int field304; int field305; int field306; int field307; int field308; int field309; int field310; int field311; int field312; int field313; int field314; int field315; int field316; int field317; int field318; int field319;
    int field320; int field321; int field322; int field323; int field324; int field325; int field326; int field327; int field328; int field329; int field330; int field331; int field332; int field333; int field334; int field335;
    int field336; int field337; int field338; int field339; int field340;
};

TEST_CASE("boost::pfr SuperBigStruct")
{
    // check boost::pfr::tuple_size_v with 341 int elements
    REQUIRE(boost::pfr::tuple_size_v<Struct341> == 341);

    // check boost::pfr::for_each_field with 85 int elements
    Struct85 aStruct{};
    std::array<int, 85> anArray;
    std::fill(anArray.begin(), anArray.end(), 0);

    REQUIRE(sizeof(aStruct) == sizeof(anArray));

    auto it = anArray.begin();
    const auto itEnd = anArray.end();

    // compare zero initialised struct <-> array the same	
    boost::pfr::for_each_field(aStruct,
        [&it, &itEnd](auto& val)
        {
            REQUIRE(it != itEnd);
            REQUIRE(*it == val);
            it++;
        }
    );

    std::mt19937 engine;
    std::uniform_int_distribution<int> dist;

    // insert random numbers into array
    std::generate(anArray.begin(), anArray.end(), [&engine, &dist]() {return dist(engine); });

    // insert random numbers struct array, create the same numbers again to
    engine = std::mt19937{};
    dist = std::uniform_int_distribution<int>{};

    boost::pfr::for_each_field(aStruct,
        [&engine, &dist](auto& val)
        {
            val = dist(engine);
        }
    );

    // check the result
    REQUIRE(aStruct.field0 == anArray[0]);
    REQUIRE(aStruct.field84 == anArray[84]);

    it = anArray.begin();
    boost::pfr::for_each_field(aStruct,
        [&it, &itEnd](auto& val)
        {
            REQUIRE(it != itEnd);
            REQUIRE(*it == val);
            it++;
        }
    );
}


// all test cases which would still fail
struct Struct86Fail
{
    int field0; int field1; int field2; int field3; int field4; int field5; int field6; int field7; int field8; int field9; int field10; int field11; int field12; int field13; int field14; int field15;
    int field16; int field17; int field18; int field19; int field20; int field21; int field22; int field23; int field24; int field25; int field26; int field27; int field28; int field29; int field30; int field31;
    int field32; int field33; int field34; int field35; int field36; int field37; int field38; int field39; int field40; int field41; int field42; int field43; int field44; int field45; int field46; int field47;
    int field48; int field49; int field50; int field51; int field52; int field53; int field54; int field55; int field56; int field57; int field58; int field59; int field60; int field61; int field62; int field63;
    int field64; int field65; int field66; int field67; int field68; int field69; int field70; int field71; int field72; int field73; int field74; int field75; int field76; int field77; int field78; int field79;
    int field80; int field81; int field82; int field83; int field84; int field85;
};

struct Struct342Fail
{
    int field0; int field1; int field2; int field3; int field4; int field5; int field6; int field7; int field8; int field9; int field10; int field11; int field12; int field13; int field14; int field15;
    int field16; int field17; int field18; int field19; int field20; int field21; int field22; int field23; int field24; int field25; int field26; int field27; int field28; int field29; int field30; int field31;
    int field32; int field33; int field34; int field35; int field36; int field37; int field38; int field39; int field40; int field41; int field42; int field43; int field44; int field45; int field46; int field47;
    int field48; int field49; int field50; int field51; int field52; int field53; int field54; int field55; int field56; int field57; int field58; int field59; int field60; int field61; int field62; int field63;
    int field64; int field65; int field66; int field67; int field68; int field69; int field70; int field71; int field72; int field73; int field74; int field75; int field76; int field77; int field78; int field79;
    int field80; int field81; int field82; int field83; int field84; int field85; int field86; int field87; int field88; int field89; int field90; int field91; int field92; int field93; int field94; int field95;
    int field96; int field97; int field98; int field99; int field100; int field101; int field102; int field103; int field104; int field105; int field106; int field107; int field108; int field109; int field110; int field111;
    int field112; int field113; int field114; int field115; int field116; int field117; int field118; int field119; int field120; int field121; int field122; int field123; int field124; int field125; int field126; int field127;
    int field128; int field129; int field130; int field131; int field132; int field133; int field134; int field135; int field136; int field137; int field138; int field139; int field140; int field141; int field142; int field143;
    int field144; int field145; int field146; int field147; int field148; int field149; int field150; int field151; int field152; int field153; int field154; int field155; int field156; int field157; int field158; int field159;
    int field160; int field161; int field162; int field163; int field164; int field165; int field166; int field167; int field168; int field169; int field170; int field171; int field172; int field173; int field174; int field175;
    int field176; int field177; int field178; int field179; int field180; int field181; int field182; int field183; int field184; int field185; int field186; int field187; int field188; int field189; int field190; int field191;
    int field192; int field193; int field194; int field195; int field196; int field197; int field198; int field199; int field200; int field201; int field202; int field203; int field204; int field205; int field206; int field207;
    int field208; int field209; int field210; int field211; int field212; int field213; int field214; int field215; int field216; int field217; int field218; int field219; int field220; int field221; int field222; int field223;
    int field224; int field225; int field226; int field227; int field228; int field229; int field230; int field231; int field232; int field233; int field234; int field235; int field236; int field237; int field238; int field239;
    int field240; int field241; int field242; int field243; int field244; int field245; int field246; int field247; int field248; int field249; int field250; int field251; int field252; int field253; int field254; int field255;
    int field256; int field257; int field258; int field259; int field260; int field261; int field262; int field263; int field264; int field265; int field266; int field267; int field268; int field269; int field270; int field271;
    int field272; int field273; int field274; int field275; int field276; int field277; int field278; int field279; int field280; int field281; int field282; int field283; int field284; int field285; int field286; int field287;
    int field288; int field289; int field290; int field291; int field292; int field293; int field294; int field295; int field296; int field297; int field298; int field299; int field300; int field301; int field302; int field303;
    int field304; int field305; int field306; int field307; int field308; int field309; int field310; int field311; int field312; int field313; int field314; int field315; int field316; int field317; int field318; int field319;
    int field320; int field321; int field322; int field323; int field324; int field325; int field326; int field327; int field328; int field329; int field330; int field331; int field332; int field333; int field334; int field335;
    int field336; int field337; int field338; int field339; int field340; int field341;
};

// a layout from a "real world" struct, that failed in msvc
struct RealWorldStruct
{
public:
   uint32_t field0{ 0 };
   uint32_t field1{ 0 };
   uint8_t field2{ 0 };
   std::array<uint8_t, 31> field3;
   uint32_t field4{ 0 };
   uint32_t field5{ 0 };
   uint32_t field6{ 0 };
   uint32_t field7{ 0 };
   uint32_t field8{ 0 };
   uint32_t field9{ 0 };
   uint32_t field10{ 0 };
   std::array<uint8_t, 60> padding;
};

// fails on both MSVC 2017 15.9.9 & MSVC 2019 RC3 (x86 & x64)
// -> Pass with 2nd patch
TEST_CASE("Fails")
{
#if 1
    auto volatile sz = boost::pfr::tuple_size_v<Struct342Fail>; // returns 341 instead of 342
    static_assert(boost::pfr::tuple_size_v<Struct342Fail> == 342);
#endif

#if 1
    // tries to instantiate:
    // "auto boost::pfr::detail::tie_as_tuple<T>(T &,std::integral_constant<unsigned __int64,85>) noexcept"
    // but required
    // "auto boost::pfr::detail::tie_as_tuple<T>(T &,std::integral_constant<unsigned __int64,86>) noexcept"
    // -> compilation failure
    Struct86Fail aStruct{};
    boost::pfr::for_each_field(aStruct,
        [](auto& val)
        {
            REQUIRE(val == 0);
        }
    );
#endif
       
#if 1
    RealWorldStruct img{0};
    volatile auto sz2 = boost::pfr::tuple_size_v<RealWorldStruct>;
    boost::pfr::for_each_field(img,
       [](auto& val)
       {
          REQUIRE(1); // just happy when it compiles at all :)
       }
    );
#endif
}