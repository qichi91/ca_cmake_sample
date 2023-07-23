#pragma once

#include <string>

class ILogger
{
public:
    enum LogLevel
    {
        Critical = 10,
        Error = 20,
        Warn = 30,
        Info = 40,
        Debug = 50,
        Trace = 80,
        None = 99
    };

    virtual ~ILogger() = default;

    virtual void setLogLevel(LogLevel level) { m_logLevel = level; }
    /**
     * @brief   ログ出力
     *
     * @param level ログレベル
     * @param message ログメッセージ
     */
    virtual void Log(LogLevel level, const std::string &message) = 0;

    virtual void critical(const std::string &message) { Log(LogLevel::Critical, message); }
    virtual void error(const std::string &message) { Log(LogLevel::Error, message); }
    virtual void warn(const std::string &message) { Log(LogLevel::Warn, message); }
    virtual void info(const std::string &message) { Log(LogLevel::Info, message); }
    virtual void debug(const std::string &message) { Log(LogLevel::Debug, message); }
    virtual void trace(const std::string &message) { Log(LogLevel::Trace, message); }

private:
    LogLevel m_logLevel = LogLevel::None;
};
