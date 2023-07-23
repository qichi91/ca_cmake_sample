#include "LoggerSpdlog.hpp"

#include <iostream>
#include <spdlog_setup/conf.h>
#include <spdlog/sinks/null_sink.h>

class LoggerSpdlog::Impl
{
public:
    Impl();

    std::shared_ptr<spdlog::logger> getLogger() { return m_logger; }

private:
    std::shared_ptr<spdlog::logger> m_logger;
};

LoggerSpdlog::Impl::Impl()
{
    try
    {
        // spdlog_setup::setup_error thrown if file not found
        spdlog_setup::from_file("logging.toml");

        // setup logger
        m_logger = spdlog::get("root");
    }
    catch (const spdlog_setup::setup_error &e)
    {
        std::cout << e.what() << std::endl;
        m_logger = std::make_shared<spdlog::logger>("null-logger", std::make_shared<spdlog::sinks::null_sink_st>());
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
        m_logger = std::make_shared<spdlog::logger>("null-logger", std::make_shared<spdlog::sinks::null_sink_st>());
    }
}

LoggerSpdlog::LoggerSpdlog()
    : m_impl(std::make_shared<Impl>())
{
}

void LoggerSpdlog::setLogLevel(LogLevel level)
{
    ILogger::setLogLevel(level);
    auto newLevel = spdlog::level::off;

    switch (level)
    {
    case LogLevel::Critical:
        newLevel = spdlog::level::critical;
        break;
    case LogLevel::Error:
        newLevel = spdlog::level::err;
        break;
    case LogLevel::Warn:
        newLevel = spdlog::level::warn;
        break;
    case LogLevel::Info:
        newLevel = spdlog::level::info;
        break;
    case LogLevel::Debug:
        newLevel = spdlog::level::debug;
        break;
    case LogLevel::Trace:
        newLevel = spdlog::level::trace;
        break;
    case LogLevel::None:
        break;
    default:
        break;
    }

    m_impl->getLogger()->set_level(newLevel);
}

void LoggerSpdlog::Log(ILogger::LogLevel level, const std::string &message)
{
    switch (level)
    {
    case LogLevel::Critical:
        m_impl->getLogger()->critical(message);
        break;
    case LogLevel::Error:
        m_impl->getLogger()->error(message);
        break;
    case LogLevel::Warn:
        m_impl->getLogger()->warn(message);
        break;
    case LogLevel::Info:
        m_impl->getLogger()->info(message);
        break;
    case LogLevel::Debug:
        m_impl->getLogger()->debug(message);
        break;
    case LogLevel::Trace:
        m_impl->getLogger()->trace(message);
        break;
    case LogLevel::None:
        break;
    default:
        break;
    }
}