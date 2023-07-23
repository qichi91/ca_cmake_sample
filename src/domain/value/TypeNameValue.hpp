#pragma once

#include "ValueObject.hpp"

class TypeNameValue;

/**
 * @brief TypeNameValueのポリシークラス
 *
 */
struct TypeNameValuePolicy
{
    using DerivedType = TypeNameValue;
    using ValueType = std::string;
};

/**
 * @brief 型名の値オブジェクト
 *
 */
class TypeNameValue : public ValueObject<TypeNameValuePolicy>
{
public:
    explicit TypeNameValue(ValueType value);
    virtual ~TypeNameValue() = default;

protected:
    bool validation() const override;

private:
};