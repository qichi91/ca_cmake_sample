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

std::unique_ptr<ValueObject> IntValue::clone() const
{
    return std::make_unique<IntValue>(this->getValue());
}

/**
 * @brief オブジェクトの比較
 * 
 * @param other 
 * @return true 
 * @return false 
 */
bool IntValue::compare(const ValueObject &other) const
{
    const auto target = dynamic_cast<const IntValue *>(&other);
    if (target == nullptr)
    {
        return false;
    }
    return this->m_value == target->getValue();
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
