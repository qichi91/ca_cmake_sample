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

protected:
    virtual bool validation() const override;

private:
    int m_value;
};
