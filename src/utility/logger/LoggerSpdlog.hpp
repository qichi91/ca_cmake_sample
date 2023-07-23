#pragma once

// #include "ILogger.hpp"
// #include <memory>
// #include <mutex>

// class LoggerSpdlog : public ILogger
// {
// private:
//     static LoggerSpdlog *m_instance;
//     static std::once_flag m_initFlag;

//     LoggerSpdlog();
//     ~LoggerSpdlog() = default;

// public:
//     static LoggerSpdlog *GetInstance();

//     void Log(LogLevel level, const std::string &message) override;
// };

// #include <memory>

// #include <mutex>
// class Log
// {
// // singleton
// private:
//     static Log* m_instance;
//     static std::once_flag m_initFlag;

// public:
//     static Log* getInstance()
//     {
//         std::call_once(m_initFlag, []() { m_instance = new Log(); });
//         return m_instance;
//     }

// // function
// private:
//     // std::shared_ptr<spdlog::logger>	m_loggerConsole;

// public:
//     Log()
//     {
//         // m_loggerConsole = spdlog::stdout_color_mt("console");
//     }

//     template <typename... Args>
//     void info(const char* message, const Args&... args)
//     {
//         // m_loggerConsole->info(message, args...);
//     }
// };

// // macro
// template <typename... Args>
// void Info(const char* message, const Args&... args)
// {
//     Log::getInstance()->info(message, args...);
// }

#include "SingletonHelper.hpp"
#include "ILogger.hpp"
#include <memory>
#include <mutex>

class LoggerSpdlog : public ILogger, public SingletonHelper<LoggerSpdlog>
{
private:
    friend class SingletonHelper<LoggerSpdlog>;
    LoggerSpdlog();

    class Impl;
    std::shared_ptr<Impl> m_impl;

public:
    virtual void setLogLevel(LogLevel level) override;
    virtual void Log(LogLevel level, const std::string &message) override;
};