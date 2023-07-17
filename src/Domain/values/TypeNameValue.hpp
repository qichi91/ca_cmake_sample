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

    //! 等価演算子
    bool operator==(const TypeNameValue& other) const;
    bool operator!=(const TypeNameValue& other) const;

protected:
    bool validation() override;

private:
    std::string m_value;
};
