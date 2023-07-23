#pragma once

#include "ValueObject.hpp"

class IntValue;

/**
 * @brief IntValueのポリシークラス
 *
 */
struct IntValuePolicy
{
    using DerivedType = IntValue;
    using ValueType = int;
};

/**
 * @brief 整数の値オブジェクト
 *
 */
class IntValue : public ValueObject<IntValuePolicy>
{
public:
    explicit IntValue(ValueType value);
    virtual ~IntValue() = default;

protected:
    bool validation() const override;

private:
};