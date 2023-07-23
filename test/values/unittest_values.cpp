#include <catch.hpp>


/**
 * @brief IntValueのテスト
 * 
 */
#include "IntValue.hpp"
TEMPLATE_TEST_CASE("IntValue", "[ValueObject][template]", IntValue)
{
    SECTION("正常系")
    {
        REQUIRE(std::make_unique<TestType>(1)->getValue() == 1);
        REQUIRE(std::make_unique<TestType>(-1)->getValue() == -1);
        auto p1 = std::make_unique<TestType>(123);
        auto p2 = std::make_unique<TestType>(123);
        auto p3 = std::make_unique<TestType>(124);
        REQUIRE(p1 != p2);
        REQUIRE(*p1 == *p2);
        REQUIRE(*p1 != *p3);

        REQUIRE(*p1 != *p3->clone());
        REQUIRE(*p3 == *p3->clone());
    }

    SECTION("異常系")
    {
        // REQUIRE_THROWS(std::make_unique<TestType>(1));
    }
}

/**
 * @brief TestTypeのテスト
 * 
 */
#include "StringValue.hpp"
TEMPLATE_TEST_CASE("StringValues", "[ValueObject][template]", StringValue)
{
    SECTION("正常系")
    {
        REQUIRE(std::make_unique<TestType>("a")->getValue() == "a");
        REQUIRE(std::make_unique<TestType>("bc")->getValue() == "bc");
        REQUIRE(std::make_unique<TestType>("def")->getValue() == "def");
        REQUIRE(std::make_unique<TestType>("G")->getValue() == "G");
        REQUIRE(std::make_unique<TestType>("HIJ")->getValue() == "HIJ");
        REQUIRE(std::make_unique<TestType>("ZW")->getValue() == "ZW");
        REQUIRE(std::make_unique<TestType>("aFkV")->getValue() == "aFkV");

        REQUIRE(std::make_unique<TestType>("1")->getValue() == "1");
        REQUIRE(std::make_unique<TestType>("1a")->getValue() == "1a");
        REQUIRE(std::make_unique<TestType>("b3H")->getValue() == "b3H");
        REQUIRE(std::make_unique<TestType>("0x2A")->getValue() == "0x2A");
        
        auto p1 = std::make_unique<TestType>("aBc");
        auto p2 = std::make_unique<TestType>("aBc");
        auto p3 = std::make_unique<TestType>("abc");
        REQUIRE(p1 != p2);
        REQUIRE(*p1 == *p2);
        REQUIRE(*p1 != *p3);

        REQUIRE(*p1 != *p3->clone());
        REQUIRE(*p3 == *p3->clone());
    }

    SECTION("異常系")
    {
        REQUIRE_THROWS(std::make_unique<TestType>(""));
    }
}

/**
 * @brief TypeNameValueのテスト
 * 
 */
#include "TypeNameValue.hpp"
TEMPLATE_TEST_CASE("TypeNameValue", "[ValueObject][template]", TypeNameValue)
{
    SECTION("正常系")
    {
        REQUIRE(std::make_unique<TestType>("aa123AAAA")->getValue() == "aa123AAAA");
        REQUIRE(std::make_unique<TestType>("bc456EFGH")->getValue() == "bc456EFGH");
        
        auto p1 = std::make_unique<TestType>("ab123CDEF");
        auto p2 = std::make_unique<TestType>("ab123CDEF");
        auto p3 = std::make_unique<TestType>("ab456CDEF");
        REQUIRE(p1 != p2);
        REQUIRE(*p1 == *p2);
        REQUIRE(*p1 != *p3);

        REQUIRE(*p1 != *p3->clone());
        REQUIRE(*p3 == *p3->clone());
    }

    SECTION("異常系")
    {
        REQUIRE_THROWS(std::make_unique<TestType>(""));
        REQUIRE_THROWS(std::make_unique<TestType>("aa000ABC"));
        REQUIRE_THROWS(std::make_unique<TestType>("a000ABCD"));
        REQUIRE_THROWS(std::make_unique<TestType>("aa00ABCD"));

        REQUIRE_THROWS(std::make_unique<TestType>("aA000abcd"));
        REQUIRE_THROWS(std::make_unique<TestType>("Aa000abcd"));

        REQUIRE_THROWS(std::make_unique<TestType>("aaa00Abcd"));
        REQUIRE_THROWS(std::make_unique<TestType>("aa0a0Abcd"));
        REQUIRE_THROWS(std::make_unique<TestType>("aa00aAbcd"));

        REQUIRE_THROWS(std::make_unique<TestType>("aa000Abcd"));
        REQUIRE_THROWS(std::make_unique<TestType>("aa000aBcd"));
        REQUIRE_THROWS(std::make_unique<TestType>("aa000abCd"));
        REQUIRE_THROWS(std::make_unique<TestType>("aa000abcD"));
    }
}

/**
 * @brief ThreeOctalDigitsValueのテスト
 * 
 */
#include "ThreeOctalDigitsValue.hpp"
TEMPLATE_TEST_CASE("ThreeOctalDigitsValue", "[ValueObject][template]", ThreeOctalDigitsValue)
{
    SECTION("正常系")
    {
        REQUIRE(std::make_unique<TestType>("000")->getValue() == "000");
        REQUIRE(std::make_unique<TestType>("123")->getValue() == "123");
        REQUIRE(std::make_unique<TestType>("456")->getValue() == "456");
        REQUIRE(std::make_unique<TestType>("777")->getValue() == "777");

        auto p1 = std::make_unique<TestType>("012");
        auto p2 = std::make_unique<TestType>("012");
        auto p3 = std::make_unique<TestType>("321");
        REQUIRE(p1 != p2);
        REQUIRE(*p1 == *p2);
        REQUIRE(*p1 != *p3);

        REQUIRE(*p1 != *p3->clone());
        REQUIRE(*p3 == *p3->clone());
    }

    SECTION("異常系")
    {
        REQUIRE_THROWS(std::make_unique<TestType>(""));
        REQUIRE_THROWS(std::make_unique<TestType>("0"));
        REQUIRE_THROWS(std::make_unique<TestType>("00"));
        REQUIRE_THROWS(std::make_unique<TestType>("0000"));
        REQUIRE_THROWS(std::make_unique<TestType>("778"));
    }
}

// // TEST_CASE("xxxxx", "")
// // {
// //     SECTION("正常系")
// //     {
// //     }

// //     SECTION("異常系")
// //     {
// //     }
// // }