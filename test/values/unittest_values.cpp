#define CATCH_CONFIG_MAIN //! main()はCatch2が作ってくれる
#include <catch.hpp>      //! 環境に合わせて
#include <memory>         //! make_unique

#include "IntValue.hpp"
#include "StringValue.hpp"
#include "TypeNameValue.hpp"
#include "ThreeOctalDigitsValue.hpp"

/**
 * @brief IntValueのテスト
 * 
 */
TEST_CASE("IntValues", "")
{
    SECTION("正常系")
    {
        REQUIRE(std::make_unique<IntValue>(1)->getValue() == 1);
        REQUIRE(std::make_unique<IntValue>(-1)->getValue() == -1);
        auto p1 = std::make_unique<IntValue>(123);
        auto p2 = std::make_unique<IntValue>(123);
        auto p3 = std::make_unique<IntValue>(124);
        REQUIRE(p1 != p2);
        REQUIRE(*p1 == *p2);
        REQUIRE(*p1 != *p3);
    }

    SECTION("異常系")
    {
        // REQUIRE_THROWS(std::make_unique<IntValue>(1));
    }
}

/**
 * @brief StringValueのテスト
 * 
 */
TEST_CASE("StringValues", "")
{
    SECTION("正常系")
    {
        REQUIRE(std::make_unique<StringValue>("a")->getValue() == "a");
        REQUIRE(std::make_unique<StringValue>("bc")->getValue() == "bc");
        REQUIRE(std::make_unique<StringValue>("def")->getValue() == "def");
        REQUIRE(std::make_unique<StringValue>("G")->getValue() == "G");
        REQUIRE(std::make_unique<StringValue>("HIJ")->getValue() == "HIJ");
        REQUIRE(std::make_unique<StringValue>("ZW")->getValue() == "ZW");
        REQUIRE(std::make_unique<StringValue>("aFkV")->getValue() == "aFkV");

        REQUIRE(std::make_unique<StringValue>("1")->getValue() == "1");
        REQUIRE(std::make_unique<StringValue>("1a")->getValue() == "1a");
        REQUIRE(std::make_unique<StringValue>("b3H")->getValue() == "b3H");
        REQUIRE(std::make_unique<StringValue>("0x2A")->getValue() == "0x2A");
        
        auto p1 = std::make_unique<StringValue>("aBc");
        auto p2 = std::make_unique<StringValue>("aBc");
        auto p3 = std::make_unique<StringValue>("abc");
        REQUIRE(p1 != p2);
        REQUIRE(*p1 == *p2);
        REQUIRE(*p1 != *p3);
    }

    SECTION("異常系")
    {
        REQUIRE_THROWS(std::make_unique<StringValue>(""));
    }
}

/**
 * @brief TypeNameValueのテスト
 * 
 */
TEST_CASE("TypeNameValue", "")
{
    SECTION("正常系")
    {
        REQUIRE(std::make_unique<TypeNameValue>("aa123AAAA")->getValue() == "aa123AAAA");
        REQUIRE(std::make_unique<TypeNameValue>("bc456EFGH")->getValue() == "bc456EFGH");
        
        auto p1 = std::make_unique<TypeNameValue>("ab123CDEF");
        auto p2 = std::make_unique<TypeNameValue>("ab123CDEF");
        auto p3 = std::make_unique<TypeNameValue>("ab456CDEF");
        REQUIRE(p1 != p2);
        REQUIRE(*p1 == *p2);
        REQUIRE(*p1 != *p3);
    }

    SECTION("異常系")
    {
        REQUIRE_THROWS(std::make_unique<TypeNameValue>(""));
        REQUIRE_THROWS(std::make_unique<TypeNameValue>("aa000ABC"));
        REQUIRE_THROWS(std::make_unique<TypeNameValue>("a000ABCD"));
        REQUIRE_THROWS(std::make_unique<TypeNameValue>("aa00ABCD"));

        REQUIRE_THROWS(std::make_unique<TypeNameValue>("aA000abcd"));
        REQUIRE_THROWS(std::make_unique<TypeNameValue>("Aa000abcd"));

        REQUIRE_THROWS(std::make_unique<TypeNameValue>("aaa00Abcd"));
        REQUIRE_THROWS(std::make_unique<TypeNameValue>("aa0a0Abcd"));
        REQUIRE_THROWS(std::make_unique<TypeNameValue>("aa00aAbcd"));

        REQUIRE_THROWS(std::make_unique<TypeNameValue>("aa000Abcd"));
        REQUIRE_THROWS(std::make_unique<TypeNameValue>("aa000aBcd"));
        REQUIRE_THROWS(std::make_unique<TypeNameValue>("aa000abCd"));
        REQUIRE_THROWS(std::make_unique<TypeNameValue>("aa000abcD"));
    }
}

/**
 * @brief ThreeOctalDigitsValueのテスト
 * 
 */
TEST_CASE("ThreeOctalDigitsValue", "")
{
    SECTION("正常系")
    {
        REQUIRE(std::make_unique<ThreeOctalDigitsValue>("000")->getValue() == "000");
        REQUIRE(std::make_unique<ThreeOctalDigitsValue>("123")->getValue() == "123");
        REQUIRE(std::make_unique<ThreeOctalDigitsValue>("456")->getValue() == "456");
        REQUIRE(std::make_unique<ThreeOctalDigitsValue>("777")->getValue() == "777");

        auto p1 = std::make_unique<ThreeOctalDigitsValue>("012");
        auto p2 = std::make_unique<ThreeOctalDigitsValue>("012");
        auto p3 = std::make_unique<ThreeOctalDigitsValue>("321");
        REQUIRE(p1 != p2);
        REQUIRE(*p1 == *p2);
        REQUIRE(*p1 != *p3);
    }

    SECTION("異常系")
    {
        REQUIRE_THROWS(std::make_unique<ThreeOctalDigitsValue>(""));
        REQUIRE_THROWS(std::make_unique<ThreeOctalDigitsValue>("0"));
        REQUIRE_THROWS(std::make_unique<ThreeOctalDigitsValue>("00"));
        REQUIRE_THROWS(std::make_unique<ThreeOctalDigitsValue>("0000"));
        REQUIRE_THROWS(std::make_unique<ThreeOctalDigitsValue>("778"));
    }
}

// TEST_CASE("xxxxx", "")
// {
//     SECTION("正常系")
//     {
//     }

//     SECTION("異常系")
//     {
//     }
// }