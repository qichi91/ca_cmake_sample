#pragma once

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