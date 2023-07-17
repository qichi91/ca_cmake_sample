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

bool ThreeOctalDigitsValue::operator==(const ThreeOctalDigitsValue &other) const
{
    return this->m_value == other.getValue();
}

bool ThreeOctalDigitsValue::operator!=(const ThreeOctalDigitsValue &other) const
{
    return this->m_value != other.getValue();
}

/**
 * @brief 以下の書式の文字列かどうかを判定する
 * 8進数の3桁で構成されていること
 *
 * @return true
 * @return false
 */
bool ThreeOctalDigitsValue::validation()
{
    std::regex re("^[0-7]{3}$");
    if (std::regex_match(m_value, re))
    {
        return true;
    }
    return false;
}
