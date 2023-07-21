#pragma once

#include <stdexcept>

class Entity
{
public:
    /**
     * @brief コピーコンストラクタは禁止
     *
     * @return Entity&
     */
    Entity &operator=(const Entity &) = delete;

    /**
     * @brief 等価演算
     *
     * @param other
     * @return true
     * @return false
     */
    bool operator==(const Entity &other) const
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
    bool operator!=(const Entity &other) const
    {
        return !compare(other);
    }

    /**
     * @brief エンティティオブジェクトのクローン
     * 
     * @return std::unique_ptr<Entity> 
     */
    virtual std::unique_ptr<Entity> clone() const = 0;

    /**
     * @brief エンティティオブジェクトの比較
     *
     * @param other 比較対象のエンティティオブジェクト
     * @return true 一致
     * @return false 不一致
     */
    virtual bool compare(const Entity &other) const = 0;

protected:
    /**
     * @brief エンティティオブジェクトの検証
     * サブクラスのコンストラクタで必ず呼び出し、完全コンストラクタを実現する
     *
     * @return true
     * @return false    検証に失敗した場合は、呼び出し側で例外を投げること
     */
    virtual bool validation() const = 0;
};
