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
#include <random>
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

// struct with 1023 fields
struct BigStruct1023
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
/*	int field288; int field289; int field290; int field291; int field292; int field293; int field294; int field295; int field296; int field297; int field298; int field299; int field300; int field301; int field302; int field303;
	int field304; int field305; int field306; int field307; int field308; int field309; int field310; int field311; int field312; int field313; int field314; int field315; int field316; int field317; int field318; int field319;
	int field320; int field321; int field322; int field323; int field324; int field325; int field326; int field327; int field328; int field329; int field330; int field331; int field332; int field333; int field334; int field335;
	int field336; int field337; int field338; int field339; int field340; int field341; int field342; int field343; int field344; int field345; int field346; int field347; int field348; int field349; int field350; int field351;
	int field352; int field353; int field354; int field355; int field356; int field357; int field358; int field359; int field360; int field361; int field362; int field363; int field364; int field365; int field366; int field367;
	int field368; int field369; int field370; int field371; int field372; int field373; int field374; int field375; int field376; int field377; int field378; int field379; int field380; int field381; int field382; int field383;
	int field384; int field385; int field386; int field387; int field388; int field389; int field390; int field391; int field392; int field393; int field394; int field395; int field396; int field397; int field398; int field399;
	int field400; int field401; int field402; int field403; int field404; int field405; int field406; int field407; int field408; int field409; int field410; int field411; int field412; int field413; int field414; int field415;
	int field416; int field417; int field418; int field419; int field420; int field421; int field422; int field423; int field424; int field425; int field426; int field427; int field428; int field429; int field430; int field431;
	int field432; int field433; int field434; int field435; int field436; int field437; int field438; int field439; int field440; int field441; int field442; int field443; int field444; int field445; int field446; int field447;
	int field448; int field449; int field450; int field451; int field452; int field453; int field454; int field455; int field456; int field457; int field458; int field459; int field460; int field461; int field462; int field463;
	int field464; int field465; int field466; int field467; int field468; int field469; int field470; int field471; int field472; int field473; int field474; int field475; int field476; int field477; int field478; int field479;
	int field480; int field481; int field482; int field483; int field484; int field485; int field486; int field487; int field488; int field489; int field490; int field491; int field492; int field493; int field494; int field495;
	int field496; int field497; int field498; int field499; int field500; int field501; int field502; int field503; int field504; int field505; int field506; int field507; int field508; int field509; int field510; int field511;
	int field512; int field513; int field514; int field515; int field516; int field517; int field518; int field519; int field520; int field521; int field522; int field523; int field524; int field525; int field526; int field527;
	int field528; int field529; int field530; int field531; int field532; int field533; int field534; int field535; int field536; int field537; int field538; int field539; int field540; int field541; int field542; int field543;
	int field544; int field545; int field546; int field547; int field548; int field549; int field550; int field551; int field552; int field553; int field554; int field555; int field556; int field557; int field558; int field559;
	int field560; int field561; int field562; int field563; int field564; int field565; int field566; int field567; int field568; int field569; int field570; int field571; int field572; int field573; int field574; int field575;
	int field576; int field577; int field578; int field579; int field580; int field581; int field582; int field583; int field584; int field585; int field586; int field587; int field588; int field589; int field590; int field591;
	int field592; int field593; int field594; int field595; int field596; int field597; int field598; int field599; int field600; int field601; int field602; int field603; int field604; int field605; int field606; int field607;
	int field608; int field609; int field610; int field611; int field612; int field613; int field614; int field615; int field616; int field617; int field618; int field619; int field620; int field621; int field622; int field623;
	int field624; int field625; int field626; int field627; int field628; int field629; int field630; int field631; int field632; int field633; int field634; int field635; int field636; int field637; int field638; int field639;
	int field640; int field641; int field642; int field643; int field644; int field645; int field646; int field647; int field648; int field649; int field650; int field651; int field652; int field653; int field654; int field655;
	int field656; int field657; int field658; int field659; int field660; int field661; int field662; int field663; int field664; int field665; int field666; int field667; int field668; int field669; int field670; int field671;
	int field672; int field673; int field674; int field675; int field676; int field677; int field678; int field679; int field680; int field681; int field682; int field683; int field684; int field685; int field686; int field687;
	int field688; int field689; int field690; int field691; int field692; int field693; int field694; int field695; int field696; int field697; int field698; int field699; int field700; int field701; int field702; int field703;
	int field704; int field705; int field706; int field707; int field708; int field709; int field710; int field711; int field712; int field713; int field714; int field715; int field716; int field717; int field718; int field719;
	int field720; int field721; int field722; int field723; int field724; int field725; int field726; int field727; int field728; int field729; int field730; int field731; int field732; int field733; int field734; int field735;
	int field736; int field737; int field738; int field739; int field740; int field741; int field742; int field743; int field744; int field745; int field746; int field747; int field748; int field749; int field750; int field751;
	int field752; int field753; int field754; int field755; int field756; int field757; int field758; int field759; int field760; int field761; int field762; int field763; int field764; int field765; int field766; int field767;
	int field768; int field769; int field770; int field771; int field772; int field773; int field774; int field775; int field776; int field777; int field778; int field779; int field780; int field781; int field782; int field783;
	int field784; int field785; int field786; int field787; int field788; int field789; int field790; int field791; int field792; int field793; int field794; int field795; int field796; int field797; int field798; int field799;
	int field800; int field801; int field802; int field803; int field804; int field805; int field806; int field807; int field808; int field809; int field810; int field811; int field812; int field813; int field814; int field815;
	int field816; int field817; int field818; int field819; int field820; int field821; int field822; int field823; int field824; int field825; int field826; int field827; int field828; int field829; int field830; int field831;
	int field832; int field833; int field834; int field835; int field836; int field837; int field838; int field839; int field840; int field841; int field842; int field843; int field844; int field845; int field846; int field847;
	int field848; int field849; int field850; int field851; int field852; int field853; int field854; int field855; int field856; int field857; int field858; int field859; int field860; int field861; int field862; int field863;
	int field864; int field865; int field866; int field867; int field868; int field869; int field870; int field871; int field872; int field873; int field874; int field875; int field876; int field877; int field878; int field879;
	int field880; int field881; int field882; int field883; int field884; int field885; int field886; int field887; int field888; int field889; int field890; int field891; int field892; int field893; int field894; int field895;
	int field896; int field897; int field898; int field899; int field900; int field901; int field902; int field903; int field904; int field905; int field906; int field907; int field908; int field909; int field910; int field911;
	int field912; int field913; int field914; int field915; int field916; int field917; int field918; int field919; int field920; int field921; int field922; int field923; int field924; int field925; int field926; int field927;
	int field928; int field929; int field930; int field931; int field932; int field933; int field934; int field935; int field936; int field937; int field938; int field939; int field940; int field941; int field942; int field943;
	int field944; int field945; int field946; int field947; int field948; int field949; int field950; int field951; int field952; int field953; int field954; int field955; int field956; int field957; int field958; int field959;
	int field960; int field961; int field962; int field963; int field964; int field965; int field966; int field967; int field968; int field969; int field970; int field971; int field972; int field973; int field974; int field975;
	int field976; int field977; int field978; int field979; int field980; int field981; int field982; int field983; int field984; int field985; int field986; int field987; int field988; int field989; int field990; int field991;
	int field992; int field993; int field994; int field995; int field996; int field997; int field998; int field999; int field1000; int field1001; int field1002; int field1003; int field1004; int field1005; int field1006; int field1007;
	int field1008; int field1009; int field1010; int field1011; int field1012; int field1013; int field1014; int field1015; int field1016; int field1017; int field1018; int field1019; int field1020; int field1021; int field1022;*/
};

// struct with 1024 fields
struct BigStruct1024
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
	int field336; int field337; int field338; int field339; int field340; int field341; int field342; int field343; int field344; int field345; int field346; int field347; int field348; int field349; int field350; int field351;
	int field352; int field353; int field354; int field355; int field356; int field357; int field358; int field359; int field360; int field361; int field362; int field363; int field364; int field365; int field366; int field367;
	int field368; int field369; int field370; int field371; int field372; int field373; int field374; int field375; int field376; int field377; int field378; int field379; int field380; int field381; int field382; int field383;
	int field384; int field385; int field386; int field387; int field388; int field389; int field390; int field391; int field392; int field393; int field394; int field395; int field396; int field397; int field398; int field399;
	int field400; int field401; int field402; int field403; int field404; int field405; int field406; int field407; int field408; int field409; int field410; int field411; int field412; int field413; int field414; int field415;
	int field416; int field417; int field418; int field419; int field420; int field421; int field422; int field423; int field424; int field425; int field426; int field427; int field428; int field429; int field430; int field431;
	int field432; int field433; int field434; int field435; int field436; int field437; int field438; int field439; int field440; int field441; int field442; int field443; int field444; int field445; int field446; int field447;
	int field448; int field449; int field450; int field451; int field452; int field453; int field454; int field455; int field456; int field457; int field458; int field459; int field460; int field461; int field462; int field463;
	int field464; int field465; int field466; int field467; int field468; int field469; int field470; int field471; int field472; int field473; int field474; int field475; int field476; int field477; int field478; int field479;
	int field480; int field481; int field482; int field483; int field484; int field485; int field486; int field487; int field488; int field489; int field490; int field491; int field492; int field493; int field494; int field495;
	int field496; int field497; int field498; int field499; int field500; int field501; int field502; int field503; int field504; int field505; int field506; int field507; int field508; int field509; int field510; int field511;
	int field512; int field513; int field514; int field515; int field516; int field517; int field518; int field519; int field520; int field521; int field522; int field523; int field524; int field525; int field526; int field527;
	int field528; int field529; int field530; int field531; int field532; int field533; int field534; int field535; int field536; int field537; int field538; int field539; int field540; int field541; int field542; int field543;
	int field544; int field545; int field546; int field547; int field548; int field549; int field550; int field551; int field552; int field553; int field554; int field555; int field556; int field557; int field558; int field559;
	int field560; int field561; int field562; int field563; int field564; int field565; int field566; int field567; int field568; int field569; int field570; int field571; int field572; int field573; int field574; int field575;
	int field576; int field577; int field578; int field579; int field580; int field581; int field582; int field583; int field584; int field585; int field586; int field587; int field588; int field589; int field590; int field591;
	int field592; int field593; int field594; int field595; int field596; int field597; int field598; int field599; int field600; int field601; int field602; int field603; int field604; int field605; int field606; int field607;
	int field608; int field609; int field610; int field611; int field612; int field613; int field614; int field615; int field616; int field617; int field618; int field619; int field620; int field621; int field622; int field623;
	int field624; int field625; int field626; int field627; int field628; int field629; int field630; int field631; int field632; int field633; int field634; int field635; int field636; int field637; int field638; int field639;
	int field640; int field641; int field642; int field643; int field644; int field645; int field646; int field647; int field648; int field649; int field650; int field651; int field652; int field653; int field654; int field655;
	int field656; int field657; int field658; int field659; int field660; int field661; int field662; int field663; int field664; int field665; int field666; int field667; int field668; int field669; int field670; int field671;
	int field672; int field673; int field674; int field675; int field676; int field677; int field678; int field679; int field680; int field681; int field682; int field683; int field684; int field685; int field686; int field687;
	int field688; int field689; int field690; int field691; int field692; int field693; int field694; int field695; int field696; int field697; int field698; int field699; int field700; int field701; int field702; int field703;
	int field704; int field705; int field706; int field707; int field708; int field709; int field710; int field711; int field712; int field713; int field714; int field715; int field716; int field717; int field718; int field719;
	int field720; int field721; int field722; int field723; int field724; int field725; int field726; int field727; int field728; int field729; int field730; int field731; int field732; int field733; int field734; int field735;
	int field736; int field737; int field738; int field739; int field740; int field741; int field742; int field743; int field744; int field745; int field746; int field747; int field748; int field749; int field750; int field751;
	int field752; int field753; int field754; int field755; int field756; int field757; int field758; int field759; int field760; int field761; int field762; int field763; int field764; int field765; int field766; int field767;
	int field768; int field769; int field770; int field771; int field772; int field773; int field774; int field775; int field776; int field777; int field778; int field779; int field780; int field781; int field782; int field783;
	int field784; int field785; int field786; int field787; int field788; int field789; int field790; int field791; int field792; int field793; int field794; int field795; int field796; int field797; int field798; int field799;
	int field800; int field801; int field802; int field803; int field804; int field805; int field806; int field807; int field808; int field809; int field810; int field811; int field812; int field813; int field814; int field815;
	int field816; int field817; int field818; int field819; int field820; int field821; int field822; int field823; int field824; int field825; int field826; int field827; int field828; int field829; int field830; int field831;
	int field832; int field833; int field834; int field835; int field836; int field837; int field838; int field839; int field840; int field841; int field842; int field843; int field844; int field845; int field846; int field847;
	int field848; int field849; int field850; int field851; int field852; int field853; int field854; int field855; int field856; int field857; int field858; int field859; int field860; int field861; int field862; int field863;
	int field864; int field865; int field866; int field867; int field868; int field869; int field870; int field871; int field872; int field873; int field874; int field875; int field876; int field877; int field878; int field879;
	int field880; int field881; int field882; int field883; int field884; int field885; int field886; int field887; int field888; int field889; int field890; int field891; int field892; int field893; int field894; int field895;
	int field896; int field897; int field898; int field899; int field900; int field901; int field902; int field903; int field904; int field905; int field906; int field907; int field908; int field909; int field910; int field911;
	int field912; int field913; int field914; int field915; int field916; int field917; int field918; int field919; int field920; int field921; int field922; int field923; int field924; int field925; int field926; int field927;
	int field928; int field929; int field930; int field931; int field932; int field933; int field934; int field935; int field936; int field937; int field938; int field939; int field940; int field941; int field942; int field943;
	int field944; int field945; int field946; int field947; int field948; int field949; int field950; int field951; int field952; int field953; int field954; int field955; int field956; int field957; int field958; int field959;
	int field960; int field961; int field962; int field963; int field964; int field965; int field966; int field967; int field968; int field969; int field970; int field971; int field972; int field973; int field974; int field975;
	int field976; int field977; int field978; int field979; int field980; int field981; int field982; int field983; int field984; int field985; int field986; int field987; int field988; int field989; int field990; int field991;
	int field992; int field993; int field994; int field995; int field996; int field997; int field998; int field999; int field1000; int field1001; int field1002; int field1003; int field1004; int field1005; int field1006; int field1007;
	int field1008; int field1009; int field1010; int field1011; int field1012; int field1013; int field1014; int field1015; int field1016; int field1017; int field1018; int field1019; int field1020; int field1021; int field1022; int field1023;
};

struct BigStruct1025
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
	int field336; int field337; int field338; int field339; int field340; int field341; int field342; int field343; int field344; int field345; int field346; int field347; int field348; int field349; int field350; int field351;
	int field352; int field353; int field354; int field355; int field356; int field357; int field358; int field359; int field360; int field361; int field362; int field363; int field364; int field365; int field366; int field367;
	int field368; int field369; int field370; int field371; int field372; int field373; int field374; int field375; int field376; int field377; int field378; int field379; int field380; int field381; int field382; int field383;
	int field384; int field385; int field386; int field387; int field388; int field389; int field390; int field391; int field392; int field393; int field394; int field395; int field396; int field397; int field398; int field399;
	int field400; int field401; int field402; int field403; int field404; int field405; int field406; int field407; int field408; int field409; int field410; int field411; int field412; int field413; int field414; int field415;
	int field416; int field417; int field418; int field419; int field420; int field421; int field422; int field423; int field424; int field425; int field426; int field427; int field428; int field429; int field430; int field431;
	int field432; int field433; int field434; int field435; int field436; int field437; int field438; int field439; int field440; int field441; int field442; int field443; int field444; int field445; int field446; int field447;
	int field448; int field449; int field450; int field451; int field452; int field453; int field454; int field455; int field456; int field457; int field458; int field459; int field460; int field461; int field462; int field463;
	int field464; int field465; int field466; int field467; int field468; int field469; int field470; int field471; int field472; int field473; int field474; int field475; int field476; int field477; int field478; int field479;
	int field480; int field481; int field482; int field483; int field484; int field485; int field486; int field487; int field488; int field489; int field490; int field491; int field492; int field493; int field494; int field495;
	int field496; int field497; int field498; int field499; int field500; int field501; int field502; int field503; int field504; int field505; int field506; int field507; int field508; int field509; int field510; int field511;
	int field512; int field513; int field514; int field515; int field516; int field517; int field518; int field519; int field520; int field521; int field522; int field523; int field524; int field525; int field526; int field527;
	int field528; int field529; int field530; int field531; int field532; int field533; int field534; int field535; int field536; int field537; int field538; int field539; int field540; int field541; int field542; int field543;
	int field544; int field545; int field546; int field547; int field548; int field549; int field550; int field551; int field552; int field553; int field554; int field555; int field556; int field557; int field558; int field559;
	int field560; int field561; int field562; int field563; int field564; int field565; int field566; int field567; int field568; int field569; int field570; int field571; int field572; int field573; int field574; int field575;
	int field576; int field577; int field578; int field579; int field580; int field581; int field582; int field583; int field584; int field585; int field586; int field587; int field588; int field589; int field590; int field591;
	int field592; int field593; int field594; int field595; int field596; int field597; int field598; int field599; int field600; int field601; int field602; int field603; int field604; int field605; int field606; int field607;
	int field608; int field609; int field610; int field611; int field612; int field613; int field614; int field615; int field616; int field617; int field618; int field619; int field620; int field621; int field622; int field623;
	int field624; int field625; int field626; int field627; int field628; int field629; int field630; int field631; int field632; int field633; int field634; int field635; int field636; int field637; int field638; int field639;
	int field640; int field641; int field642; int field643; int field644; int field645; int field646; int field647; int field648; int field649; int field650; int field651; int field652; int field653; int field654; int field655;
	int field656; int field657; int field658; int field659; int field660; int field661; int field662; int field663; int field664; int field665; int field666; int field667; int field668; int field669; int field670; int field671;
	int field672; int field673; int field674; int field675; int field676; int field677; int field678; int field679; int field680; int field681; int field682; int field683; int field684; int field685; int field686; int field687;
	int field688; int field689; int field690; int field691; int field692; int field693; int field694; int field695; int field696; int field697; int field698; int field699; int field700; int field701; int field702; int field703;
	int field704; int field705; int field706; int field707; int field708; int field709; int field710; int field711; int field712; int field713; int field714; int field715; int field716; int field717; int field718; int field719;
	int field720; int field721; int field722; int field723; int field724; int field725; int field726; int field727; int field728; int field729; int field730; int field731; int field732; int field733; int field734; int field735;
	int field736; int field737; int field738; int field739; int field740; int field741; int field742; int field743; int field744; int field745; int field746; int field747; int field748; int field749; int field750; int field751;
	int field752; int field753; int field754; int field755; int field756; int field757; int field758; int field759; int field760; int field761; int field762; int field763; int field764; int field765; int field766; int field767;
	int field768; int field769; int field770; int field771; int field772; int field773; int field774; int field775; int field776; int field777; int field778; int field779; int field780; int field781; int field782; int field783;
	int field784; int field785; int field786; int field787; int field788; int field789; int field790; int field791; int field792; int field793; int field794; int field795; int field796; int field797; int field798; int field799;
	int field800; int field801; int field802; int field803; int field804; int field805; int field806; int field807; int field808; int field809; int field810; int field811; int field812; int field813; int field814; int field815;
	int field816; int field817; int field818; int field819; int field820; int field821; int field822; int field823; int field824; int field825; int field826; int field827; int field828; int field829; int field830; int field831;
	int field832; int field833; int field834; int field835; int field836; int field837; int field838; int field839; int field840; int field841; int field842; int field843; int field844; int field845; int field846; int field847;
	int field848; int field849; int field850; int field851; int field852; int field853; int field854; int field855; int field856; int field857; int field858; int field859; int field860; int field861; int field862; int field863;
	int field864; int field865; int field866; int field867; int field868; int field869; int field870; int field871; int field872; int field873; int field874; int field875; int field876; int field877; int field878; int field879;
	int field880; int field881; int field882; int field883; int field884; int field885; int field886; int field887; int field888; int field889; int field890; int field891; int field892; int field893; int field894; int field895;
	int field896; int field897; int field898; int field899; int field900; int field901; int field902; int field903; int field904; int field905; int field906; int field907; int field908; int field909; int field910; int field911;
	int field912; int field913; int field914; int field915; int field916; int field917; int field918; int field919; int field920; int field921; int field922; int field923; int field924; int field925; int field926; int field927;
	int field928; int field929; int field930; int field931; int field932; int field933; int field934; int field935; int field936; int field937; int field938; int field939; int field940; int field941; int field942; int field943;
	int field944; int field945; int field946; int field947; int field948; int field949; int field950; int field951; int field952; int field953; int field954; int field955; int field956; int field957; int field958; int field959;
	int field960; int field961; int field962; int field963; int field964; int field965; int field966; int field967; int field968; int field969; int field970; int field971; int field972; int field973; int field974; int field975;
	int field976; int field977; int field978; int field979; int field980; int field981; int field982; int field983; int field984; int field985; int field986; int field987; int field988; int field989; int field990; int field991;
	int field992; int field993; int field994; int field995; int field996; int field997; int field998; int field999; int field1000; int field1001; int field1002; int field1003; int field1004; int field1005; int field1006; int field1007;
	int field1008; int field1009; int field1010; int field1011; int field1012; int field1013; int field1014; int field1015; int field1016; int field1017; int field1018; int field1019; int field1020; int field1021; int field1022; int field1023;
	int field1024;
};

TEST_CASE("SuperBigStruct")
{
	BigStruct1023 src;
	BigStruct1023 dest;
	BigStruct s2;

	volatile auto sz = boost::pfr::tuple_size_v <BigStruct1023>; // delivers the correct answer up to 288 fields, then outputs too small values

	REQUIRE(boost::pfr::tuple_size_v<BigStruct1023> == 1023); // C1202 freedom
	REQUIRE(boost::pfr::tuple_size_v<BigStruct1024> == 1024); // compiles w/o static assert because the answer is wrong
	REQUIRE(boost::pfr::tuple_size_v<BigStruct1025> == 1025); // compiles w/o static assert because the answer is wrong

	std::mt19937 engine;
	std::uniform_int_distribution<int> dist;

	// only possible until 100 fields as per generated code for C++17
	/*
	boost::pfr::for_each_field(src,
		[&engine, &dist](auto& val)
		{
			val = dist(engine);
		}
	);
	*/


}