#include <iostream>

#include "LoggerSpdlog.hpp"

int main(int, char **)
{
    ILogger& logger = LoggerSpdlog::getInstance();
    logger.warn("Hello, World!");
    
    return 0;
}
