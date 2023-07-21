#include <regex>
#include "ThreeOctalDigitsValue.hpp"

ThreeOctalDigitsValue::ThreeOctalDigitsValue(std::string value)
    : m_value(value)
{
    if (!validation())
    {
        throw std::invalid_argument("invalid argument : ThreeOctalDigitsValue");
    }
}

std::string ThreeOctalDigitsValue::getValue() const
{
    return m_value;
}

std::unique_ptr<ValueObject> ThreeOctalDigitsValue::clone() const
{
    return std::make_unique<ThreeOctalDigitsValue>(this->getValue());
}

/**
 * @brief オブジェクトの比較
 * 
 * @param other 
 * @return true 
 * @return false 
 */
bool ThreeOctalDigitsValue::compare(const ValueObject &other) const
{
    const auto target = dynamic_cast<const ThreeOctalDigitsValue *>(&other);
    if (target == nullptr)
    {
        return false;
    }
    return this->m_value == target->getValue();
}

/**
 * @brief 以下の書式の文字列かどうかを判定する
 * 8進数の3桁で構成されていること
 *
 * @return true
 * @return false
 */
bool ThreeOctalDigitsValue::validation() const
{
    std::regex re("^[0-7]{3}$");
    if (std::regex_match(m_value, re))
    {
        return true;
    }
    return false;
}
