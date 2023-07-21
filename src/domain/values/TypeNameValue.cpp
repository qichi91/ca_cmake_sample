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

std::unique_ptr<ValueObject> TypeNameValue::clone() const
{
    return std::make_unique<TypeNameValue>(this->getValue());
}

/**
 * @brief オブジェクトの比較
 * 
 * @param other 
 * @return true 
 * @return false 
 */
bool TypeNameValue::compare(const ValueObject &other) const
{
    const auto target = dynamic_cast<const TypeNameValue *>(&other);
    if (target == nullptr)
    {
        return false;
    }
    return this->m_value == target->getValue();
}

/**
 * @brief 以下の書式の文字列かどうかを判定する
 * 英小文字2文字+数字3桁+英大文字4文字で構成されていること
 *
 * @return true
 * @return false
 */
bool TypeNameValue::validation() const
{
    std::regex re("^[a-z]{2}[0-9]{3}[A-Z]{4}$");
    if (std::regex_match(m_value, re))
    {
        return true;
    }
    return false;
}
