#pragma once

#include "ValueObject.hpp"

/**
 * @brief 整数の値オブジェクト
 * 
 */
class IntValue : public ValueObject
{
public:
    explicit IntValue(int value);
    virtual ~IntValue() = default;
    int getValue() const;

    //! 等価演算子
    bool operator==(const IntValue& other) const;
    bool operator!=(const IntValue& other) const;

protected:
    bool validation() override;

private:
    int m_value;
};
