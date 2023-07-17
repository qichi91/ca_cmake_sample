#include <catch.hpp>

#include "User.hpp"

/**
 * @brief IntValueのテスト
 * 
 */
TEST_CASE("User", "")
{
    SECTION("正常系")
    {
        REQUIRE(std::make_unique<User>(1, "ab987OKIJ"));
        REQUIRE(std::make_unique<User>(-1, "ab987OKIJ"));
        REQUIRE(std::make_unique<User>(-100, "ab123ABCD"));
        REQUIRE(std::make_unique<User>(100, "ga451HAOW"));
        
        auto p1 = std::make_unique<User>(53, "ab987OKIJ");
        auto p2 = std::make_unique<User>(53, "ab987OKIJ");
        auto p3 = std::make_unique<User>(46, "ab987OKIJ");
        auto p4 = std::make_unique<User>(53, "ga123AKOJ");
        REQUIRE(p1 != p2);
        REQUIRE(*p1 == *p2);
        REQUIRE(*p1 != *p3);
        REQUIRE(*p1 != *p4);

        REQUIRE(*p1 != *p3->clone());
        REQUIRE(*p3 == *p3->clone());
    }

    SECTION("異常系")
    {
        REQUIRE_THROWS(std::make_unique<User>(1, ""));
        REQUIRE_THROWS(std::make_unique<User>(-1, "ga051HAO"));
        REQUIRE_THROWS(std::make_unique<User>(-1, "ga05GHAO"));
        REQUIRE_THROWS(std::make_unique<User>(-1, "g005GHAO"));
        REQUIRE_THROWS(std::make_unique<User>(-1, "ag005aHAO"));
        REQUIRE_THROWS(std::make_unique<User>(-1, "aS005FHAO"));
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