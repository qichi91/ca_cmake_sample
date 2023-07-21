#pragma once

#include "StringValue.hpp"

/**
 * @brief 型名の値オブジェクト
 *
 */
class TypeNameValue : public StringValue<TypeNameValue>
{
public:
    explicit TypeNameValue(std::string value);
    virtual ~TypeNameValue() = default;

protected:
    virtual bool validation() const override;

private:
};
