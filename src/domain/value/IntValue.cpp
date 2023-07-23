#include "IntValue.hpp"

IntValue::IntValue(ValueType value)
{
    if (!validation())
    {
        throw std::invalid_argument("invalid argument : IntValue");
    }
}

bool IntValue::validation() const
{
    if (INT32_MIN <= this->derived().getValue() && this->derived().getValue() <= INT32_MAX)
    {
        return true;
    }
    return false;
}

