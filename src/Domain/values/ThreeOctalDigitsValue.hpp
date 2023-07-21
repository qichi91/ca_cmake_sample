#pragma once

#include "StringValue.hpp"

/**
 * @brief 3桁の8進数の値オブジェクト
 *
 */
class ThreeOctalDigitsValue : public StringValue<ThreeOctalDigitsValue>
{
public:
    explicit ThreeOctalDigitsValue(const std::string& value);
    virtual ~ThreeOctalDigitsValue() = default;

protected:
    virtual bool validation() const override;
};
