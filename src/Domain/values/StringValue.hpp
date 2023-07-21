#pragma once

#include <string>
#include "ValueObject.hpp"

template <typename Derived>
class StringValue : public ValueObject
{
public:
    explicit StringValue(const std::string &value);
    virtual ~StringValue() = default;

    std::string value() const;
    virtual std::unique_ptr<ValueObject> clone() const override;

protected:
    virtual bool compare(const ValueObject &other) const override;

protected:
    std::string m_value;
};

template <typename Derived>
inline StringValue<Derived>::StringValue(const std::string &value)
    : m_value(value)
{
}

template <typename Derived>
inline std::string StringValue<Derived>::value() const
{
    return m_value;
}

template <typename Derived>
inline std::unique_ptr<ValueObject> StringValue<Derived>::clone() const
{
    return std::make_unique<Derived>(m_value);
}

template <typename Derived>
inline bool StringValue<Derived>::compare(const ValueObject &other) const
{
    auto derived = dynamic_cast<const Derived *>(&other);
    if (derived == nullptr)
    {
        return false;
    }
    return m_value == derived->m_value;
}
