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

    //! 等価演算子
    bool operator==(const StringValue& other) const;
    bool operator!=(const StringValue& other) const;

protected:
    bool validation() override;

private:
    std::string m_value;
};