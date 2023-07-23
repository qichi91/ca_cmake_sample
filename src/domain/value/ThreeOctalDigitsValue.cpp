#include "ThreeOctalDigitsValue.hpp"

#include <regex>

ThreeOctalDigitsValue::ThreeOctalDigitsValue(ValueType value)
{
    if (!validation())
    {
        throw std::invalid_argument("invalid argument : ThreeOctalDigitsValue");
    }
}

/**
 * @brief 文字列が空でないことを確認する
 *
 * @return true
 * @return false
 */
bool ThreeOctalDigitsValue::validation() const
{
    std::regex re("^[0-7]{3}$");
    if (std::regex_match(this->derived().getValue(), re))
    {
        return true;
    }
    return false;
}
