#include <memory>

template <class T>
class SingletonHelper
{
public:
    static T &getInstance()
    {
        static typename T::singleton_pointer_type s_singleton(T::createInstance());

        return getReference(s_singleton);
    }

private:
    typedef std::shared_ptr<T> singleton_pointer_type;

    inline static T *createInstance() { return new T(); }

    inline static T &getReference(const singleton_pointer_type &ptr) { return *ptr; }

protected:
    SingletonHelper() {}

private:
    SingletonHelper(const SingletonHelper &) = delete;
    SingletonHelper &operator=(const SingletonHelper &) = delete;
    SingletonHelper(SingletonHelper &&) = delete;
    SingletonHelper &operator=(SingletonHelper &&) = delete;
};