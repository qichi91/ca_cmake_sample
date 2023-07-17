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

std::unique_ptr<ValueObject> StringValue::clone() const
{
    return std::make_unique<StringValue>(this->getValue());
}

/**
 * @brief オブジェクトの比較
 * 
 * @param other 
 * @return true 
 * @return false 
 */
bool StringValue::compare(const ValueObject &other) const
{
    const auto target = dynamic_cast<const StringValue *>(&other);
    if (target == nullptr)
    {
        return false;
    }
    return this->m_value == target->getValue();
}

/**
 * @brief 文字列が空でないことを確認する
 *
 * @return true
 * @return false
 */
bool StringValue::validation() const
{
    return 0 < m_value.size();
}
