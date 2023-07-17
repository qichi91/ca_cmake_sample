#pragma once

#include <stdexcept>

/**
 * @brief 値オブジェクトの基底クラス
 * 値オブジェクトで共通の処理を実装する
 */
class ValueObject
{
public:
protected:
    /**
     * @brief 値オブジェクトの検証
     * サブクラスのコンストラクタで必ず呼び出し、完全コンストラクタを実現する
     *
     * @return true
     * @return false    検証に失敗した場合は、呼び出し側で例外を投げること
     */
    virtual bool validation() = 0;
};
