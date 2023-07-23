#pragma once

#include "ValueObject.hpp"

class StringValue;

/**
 * @brief ポリシークラス
 * 
 */
struct StringValuePolicy
{
    using DerivedType = StringValue;
    using ValueType = std::string;
};

/**
 * @brief 文字列の値オブジェクト
 * 
 */
class StringValue : public ValueObject<StringValuePolicy>
{
public:
    explicit StringValue(ValueType value);
    virtual ~StringValue() = default;

protected:
    bool validation() const override;

private:
};