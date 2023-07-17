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

    //! 等価演算子
    bool operator==(const ThreeOctalDigitsValue& other) const;
    bool operator!=(const ThreeOctalDigitsValue& other) const;

protected:
    bool validation() override;

private:
    std::string m_value;
};
