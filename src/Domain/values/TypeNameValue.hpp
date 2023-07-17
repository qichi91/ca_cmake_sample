#pragma once

#include "ValueObject.hpp"

/**
 * @brief 型名の値オブジェクト
 *
 */
class TypeNameValue : public ValueObject
{
public:
    explicit TypeNameValue(std::string value);
    virtual ~TypeNameValue() = default;
    std::string getValue() const;
    virtual std::unique_ptr<ValueObject> clone() const override;
    virtual bool compare(const ValueObject &other) const override;

protected:
    virtual bool validation() const override;

private:
    std::string m_value;
};
