#include "User.hpp"

#include "IntValue.hpp"
#include "TypeNameValue.hpp"

// User::User(std::unique_ptr<IntValue> id, std::unique_ptr<TypeNameValue> name)
//     : m_id(std::move(id)), m_name(std::move(name))
// {
//     if (!validation())
//     {
//         throw std::invalid_argument("invalid argument : User");
//     }
// }

User::User(int id, std::string name)
    : m_id(std::make_unique<IntValue>(id)), m_name(std::make_unique<TypeNameValue>(name))
{
    if (!validation())
    {
        throw std::invalid_argument("invalid argument : User");
    }
}

std::unique_ptr<Entity> User::clone() const
{
    return std::make_unique<User>(this->m_id->getValue(), this->m_name->getValue());
}

bool User::compare(const Entity &other) const
{
    const auto target = dynamic_cast<const User *>(&other);
    if (target == nullptr)
    {
        return false;
    }
    return this->m_id->compare(*target->m_id) && this->m_name->compare(*target->m_name);
}

// int User::getId() const
// {
//     return this->m_id->getValue();
// }

// std::string User::getName() const
// {
//     return this->m_name->getValue();
// }

std::unique_ptr<IntValue> User::getId() const
{
    return std::make_unique<IntValue>(this->m_id->getValue());
}

std::unique_ptr<TypeNameValue> User::getName() const
{
    return std::make_unique<TypeNameValue>(this->m_name->getValue());
}

/**
 * @brief エンティティオブジェクトの検証
 * ValueObjectのみを使うので、ここでは何もしない
 *
 * @return true
 * @return false
 */
bool User::validation() const
{
    return true;
}
