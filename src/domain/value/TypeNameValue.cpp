#include "TypeNameValue.hpp"

#include <regex>

TypeNameValue::TypeNameValue(ValueType value)
{
    if (!validation())
    {
        throw std::invalid_argument("invalid argument : TypeNameValue");
    }
}

/**
 * @brief 文字列が空でないことを確認する
 *
 * @return true
 * @return false
 */
bool TypeNameValue::validation() const
{
    std::regex re("^[a-z]{2}[0-9]{3}[A-Z]{4}$");
    if (std::regex_match(this->derived().getValue(), re))
    {
        return true;
    }
    return false;
}
