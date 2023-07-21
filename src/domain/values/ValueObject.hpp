#pragma once

#include <memory>
#include <stdexcept>

/**
 * @brief 値オブジェクトの基底クラス
 * 値オブジェクトで共通の処理を実装する
 */
class ValueObject
{
public:
    /**
     * @brief コピーコンストラクタは禁止
     *
     * @return ValueObject&
     */
    ValueObject &operator=(const ValueObject &) = delete;

    /**
     * @brief 等価演算
     *
     * @param other
     * @return true
     * @return false
     */
    bool operator==(const ValueObject &other) const
    {
        return compare(other);
    }
    /**
     * @brief 非等価演算
     *
     * @param other
     * @return true
     * @return false
     */
    bool operator!=(const ValueObject &other) const
    {
        return !compare(other);
    }

    /**
     * @brief 値オブジェクトの比較
     *
     * @param other 比較対象の値オブジェクト
     * @return true 一致
     * @return false 不一致
     */
    virtual bool compare(const ValueObject &other) const = 0;

    /**
     * @brief 値オブジェクトのクローン
     * 
     * @return std::unique_ptr<ValueObject> 
     */
    virtual std::unique_ptr<ValueObject> clone() const = 0;

protected:
    /**
     * @brief 値オブジェクトの検証
     * サブクラスのコンストラクタで必ず呼び出し、完全コンストラクタを実現する
     *
     * @return true
     * @return false    検証に失敗した場合は、呼び出し側で例外を投げること
     */
    virtual bool validation() const = 0;
};
