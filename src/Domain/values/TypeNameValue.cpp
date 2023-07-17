#include <regex>

#include "TypeNameValue.hpp"

TypeNameValue::TypeNameValue(std::string value)
    : m_value(value)
{
    if (!validation())
    {
        throw std::invalid_argument("invalid argument : TypeNameValue");
    }
}

std::string TypeNameValue::getValue() const
{
    return m_value;
}

bool TypeNameValue::operator==(const TypeNameValue &other) const
{
    return this->m_value == other.getValue();
}

bool TypeNameValue::operator!=(const TypeNameValue &other) const
{
    return this->m_value != other.getValue();
}

/**
 * @brief 以下の書式の文字列かどうかを判定する
 * 英小文字2文字+数字3桁+英大文字4文字で構成されていること
 *
 * @return true
 * @return false
 */
bool TypeNameValue::validation()
{
    std::regex re("^[a-z]{2}[0-9]{3}[A-Z]{4}$");
    if (std::regex_match(m_value, re))
    {
        return true;
    }
    return false;
}
