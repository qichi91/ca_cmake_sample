#include <catch.hpp>


/**
 * @brief IntValueのテスト
 * 
 */
#include "User.hpp"
TEMPLATE_TEST_CASE("User", "[Entity][template]", User)
{
    SECTION("正常系")
    {
        REQUIRE(std::make_unique<TestType>(1, "ab987OKIJ"));
        REQUIRE(std::make_unique<TestType>(-1, "ab987OKIJ"));
        REQUIRE(std::make_unique<TestType>(-100, "ab123ABCD"));
        REQUIRE(std::make_unique<TestType>(100, "ga451HAOW"));
        
        auto p1 = std::make_unique<TestType>(53, "ab987OKIJ");
        auto p2 = std::make_unique<TestType>(53, "ab987OKIJ");
        auto p3 = std::make_unique<TestType>(46, "ab987OKIJ");
        auto p4 = std::make_unique<TestType>(53, "ga123AKOJ");
        REQUIRE(p1 != p2);
        REQUIRE(*p1 == *p2);
        REQUIRE(*p1 != *p3);
        REQUIRE(*p1 != *p4);

        REQUIRE(*p1 != *p3->clone());
        REQUIRE(*p3 == *p3->clone());
    }

    SECTION("異常系")
    {
        REQUIRE_THROWS(std::make_unique<TestType>(1, ""));
        REQUIRE_THROWS(std::make_unique<TestType>(-1, "ga051HAO"));
        REQUIRE_THROWS(std::make_unique<TestType>(-1, "ga05GHAO"));
        REQUIRE_THROWS(std::make_unique<TestType>(-1, "g005GHAO"));
        REQUIRE_THROWS(std::make_unique<TestType>(-1, "ag005aHAO"));
        REQUIRE_THROWS(std::make_unique<TestType>(-1, "aS005FHAO"));
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