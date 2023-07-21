#pragma once

#include <string>
#include "ValueObject.hpp"

/**
 * @brief 文字列の値オブジェクト
 * 
 */
class StringValue : public ValueObject
{
public:
    explicit StringValue(std::string value);
    virtual ~StringValue() = default;
    std::string getValue() const;
    virtual std::unique_ptr<ValueObject> clone() const override;
    virtual bool compare(const ValueObject &other) const override;

protected:
    virtual bool validation() const override;

private:
    std::string m_value;
};