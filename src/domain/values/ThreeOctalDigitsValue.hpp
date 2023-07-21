#pragma once

#include "ValueObject.hpp"

/**
 * @brief 3桁の8進数の値オブジェクト
 *
 */
class ThreeOctalDigitsValue : public ValueObject
{
public:
    explicit ThreeOctalDigitsValue(std::string value);
    virtual ~ThreeOctalDigitsValue() = default;
    std::string getValue() const;
    virtual std::unique_ptr<ValueObject> clone() const override;
    virtual bool compare(const ValueObject &other) const override;

protected:
    virtual bool validation() const override;

private:
    std::string m_value;
};
