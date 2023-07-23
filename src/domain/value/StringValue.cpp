#include "StringValue.hpp"

StringValue::StringValue(ValueType value)
{
    if (!validation())
    {
        throw std::invalid_argument("invalid argument : StringValue");
    }
}

/**
 * @brief 文字列が空でないことを確認する
 *
 * @return true
 * @return false
 */
bool StringValue::validation() const
{
    return 0 < this->derived().getValue().size();
}
