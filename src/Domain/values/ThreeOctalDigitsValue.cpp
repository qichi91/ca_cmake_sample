#include <regex>
#include "ThreeOctalDigitsValue.hpp"

ThreeOctalDigitsValue::ThreeOctalDigitsValue(const std::string& value)
    : StringValue<ThreeOctalDigitsValue>(value)
{
    if (!validation())
    {
        throw std::invalid_argument("invalid argument : ThreeOctalDigitsValue");
    }
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
