#include "StringValue.hpp"

StringValue::StringValue(std::string value)
    : m_value(value)
{
    if (!validation())
    {
        throw std::invalid_argument("invalid argument : StringValue");
    }
}

std::string StringValue::getValue() const
{
    return m_value;
}

bool StringValue::operator==(const StringValue &other) const
{
    return this->m_value == other.getValue();
}

bool StringValue::operator!=(const StringValue &other) const
{
    return this->m_value != other.getValue();
}

/**
 * @brief 文字列が空でないことを確認する
 *
 * @return true
 * @return false
 */
bool StringValue::validation()
{
    return 0 < m_value.size();
}
