#pragma once

#include <memory>
#include <stdexcept>

/**
 * @brief CRTP(Curiously Recurring Template Pattern)とポリシーベースデザインによる値オブジェクトの実装
 *  値オブジェクトの条件
 *  ・値オブジェクトは値を一つだけ保持する => ポリシーで外部定義可能
 *  ・代入演算子は削除
 *  ・コピーコンストラクタで値をコピーする => ポリシーで外部定義可能
 *  ・その値がオブジェクトの値として妥当かどうかの検証を行う => 派生クラスでvalidation()を実装.　呼び出しはCRTPで可
 *
 * @tparam Policy 派生クラスと値の型を定義するポリシークラス
 */
template <typename Policy>
class ValueObject
{
protected:
    using DerivedType = typename Policy::DerivedType; //! 派生クラス定義
    using ValueType = typename Policy::ValueType;     //! 値の型

    /**
     * @brief 派生クラスの参照取得
     *
     * @return DerivedType&
     */
    DerivedType &derived() noexcept
    {
        return static_cast<DerivedType &>(*this);
    }

    /**
     * @brief 派生クラスの参照取得
     *
     * @return const DerivedType&
     */
    const DerivedType &derived() const noexcept
    {
        return static_cast<const DerivedType &>(*this);
    }

public:
    virtual ~ValueObject() = default;
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

    //!
    //! TODO: < opreator必要?
    //!

    /**
     * @brief 値オブジェクトの比較
     *
     * @param other 比較対象の値オブジェクト
     * @return true 一致
     * @return false 不一致
     */
    virtual bool compare(const ValueObject &other) const
    {
        if (typeid(derived()) == typeid(other.derived()))
        {
            return false; // 型が異なる
        }
        return derived().getValue() == other.derived().getValue();
    }

    /**
     * @brief 値オブジェクトのクローン
     *
     * @return ValueObject*
     */
    virtual ValueObject *clone() const
    {
        return new DerivedType(derived().getValue());
    }

    /**
     * @brief 値の取得
     *
     * @return ValueType
     */
    ValueType getValue() const
    {
        return m_value;
    }

protected:
    /**
     * @brief 値オブジェクトの検証
     *
     * @return true
     * @return false    検証に失敗した場合は、呼び出し側で例外を投げること
     */
    virtual bool validation() const = 0;

private:
    /**
     * @brief 代入演算子は削除
     */
    ValueObject &operator=(const ValueObject &) = delete;
    DerivedType &operator=(const DerivedType &) = delete;
    ValueObject &operator=(ValueObject &) = delete;
    DerivedType &operator=(DerivedType &) = delete;

protected:
    ValueType m_value; //! 値
};