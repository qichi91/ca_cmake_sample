#pragma once

#include "ValueObject.hpp"

class ThreeOctalDigitsValue;

/**
 * @brief ThreeOctalDigitsValueのポリシークラス
 * 
 */
struct ThreeOctalDigitsValuePolicy
{
    using DerivedType = ThreeOctalDigitsValue;
    using ValueType = std::string;
};

/**
 * @brief 3桁の8進数の値オブジェクト
 * 
 */
class ThreeOctalDigitsValue : public ValueObject<ThreeOctalDigitsValuePolicy>
{
public:
    explicit ThreeOctalDigitsValue(ValueType value);
    virtual ~ThreeOctalDigitsValue() = default;

protected:
    bool validation() const override;

private:
};