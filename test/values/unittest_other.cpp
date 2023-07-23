#include <catch.hpp>

/**
 * @brief LoggerSpdlogのテスト
 *
 */
#include "LoggerSpdlog.hpp"
TEST_CASE("LoggerSpdlog", "")
{
    //! 実際の出力はテストしない
    REQUIRE_NOTHROW(LoggerSpdlog::getInstance());

    SECTION("正常系")
    {
        REQUIRE_NOTHROW(LoggerSpdlog::getInstance().Log(ILogger::LogLevel::None, "None"));
        REQUIRE_NOTHROW(LoggerSpdlog::getInstance().critical("critical"));
        REQUIRE_NOTHROW(LoggerSpdlog::getInstance().error("error"));
        REQUIRE_NOTHROW(LoggerSpdlog::getInstance().warn("warn"));
        REQUIRE_NOTHROW(LoggerSpdlog::getInstance().info("info"));
        REQUIRE_NOTHROW(LoggerSpdlog::getInstance().debug("debug"));
        REQUIRE_NOTHROW(LoggerSpdlog::getInstance().trace("trace"));
    }

    SECTION("異常系")
    {
    }
}
#include "testobject.hpp"
TEST_CASE("testobject", "")
{
    Plane *plane = new Plane(100, 200);
    Car *car = new Car(100);

    REQUIRE(dynamic_cast<Plane *>(plane));
    REQUIRE(dynamic_cast<Vehicle *>(plane));
    REQUIRE(dynamic_cast<Car *>(car));
    REQUIRE(dynamic_cast<Vehicle *>(car));

    std::unique_ptr<Vehicle> plane2 = plane->clone();
    plane2->describe();
    std::unique_ptr<Vehicle> plane3 = plane->clone();
    plane3->describe();
    auto plane4 = plane->clone();
    plane4->describe();
    
    REQUIRE(dynamic_cast<Vehicle *>(plane2.get()));
    REQUIRE(dynamic_cast<Plane *>(plane2.get()));
    REQUIRE(dynamic_cast<Vehicle *>(plane3.get()));
    REQUIRE(dynamic_cast<Plane *>(plane3.get()));

    FighterPlane *fp = new FighterPlane(100, 200, 300);
    fp->describe();
    std::unique_ptr<Vehicle> fp2 = fp->clone();
    fp2->describe();
    auto fp3 = fp2->clone();
    fp3->describe();
    REQUIRE(dynamic_cast<Vehicle *>(fp2.get()));
    REQUIRE(dynamic_cast<Plane *>(fp2.get()));
    REQUIRE(dynamic_cast<FighterPlane *>(fp2.get()));
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

// #include "xxxxx.hpp"
// TEMPLATE_TEST_CASE("xxxxx", "[tttt][yyyy]", xxxxx)
// {
//     SECTION("正常系")
//     {
//         REQUIRE(std::make_unique<TestType>(1, "ab987OKIJ"));
//     }

//     SECTION("異常系")
//     {
//         REQUIRE_THROWS(std::make_unique<TestType>(1, ""));
//     }
// }