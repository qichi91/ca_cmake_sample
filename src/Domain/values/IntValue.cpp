#include "IntValue.hpp"

IntValue::IntValue(int value)
    : m_value(value)
{
    if (!validation())
    {
        throw std::invalid_argument("invalid argument : IntValue");
    }
}

int IntValue::getValue() const
{
    return m_value;
}

/**
 * @brief 整数の範囲内であることを確認する
 *
 * @return true
 * @return false
 */
bool IntValue::validation() const
{
    if (INT32_MIN <= m_value && m_value <= INT32_MAX)
    {
        return true;
    }
    return false;
}
