#pragma once

#include <memory>
#include "Entity.hpp"
#include "IntValue.hpp"
#include "TypeNameValue.hpp"

class IntValue;
class TypeNameValue;

class User : public Entity
{
public:
    // User(std::unique_ptr<IntValue> id, std::unique_ptr<TypeNameValue> name);
    User(int id, std::string name);
    virtual ~User() = default;
    virtual std::unique_ptr<Entity> clone() const override;
    virtual bool compare(const Entity &other) const override;

    //! TODO: ここでは値オブジェクトのみを返すべきか？
    // int getId() const;
    // std::string getName() const;
    std::unique_ptr<IntValue> getId() const;
    std::unique_ptr<TypeNameValue> getName() const;

protected:
    virtual bool validation() const override;

private:
    std::unique_ptr<IntValue> m_id;
    std::unique_ptr<TypeNameValue> m_name;
};
