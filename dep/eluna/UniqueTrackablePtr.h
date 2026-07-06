#ifndef UNIQUETRACKABLEPTR_H
#define UNIQUETRACKABLEPTR_H

#include <memory>

namespace Trinity
{
    template<typename T>
    class unique_strong_ref_ptr;

    template<typename T>
    class unique_trackable_ptr : public std::shared_ptr<T>
    {
    public:
        unique_trackable_ptr() = default;
        unique_trackable_ptr(std::nullptr_t) : std::shared_ptr<T>(nullptr) {}
        unique_trackable_ptr(std::shared_ptr<T> const& shared) : std::shared_ptr<T>(shared) {}
        template<typename U> unique_trackable_ptr(unique_trackable_ptr<U> const& other) : std::shared_ptr<T>(std::static_pointer_cast<T>(std::shared_ptr<U>(other))) {}
    };

    template<typename T>
    class unique_weak_ptr : public std::weak_ptr<T>
    {
    public:
        unique_weak_ptr() = default;
        unique_weak_ptr(unique_trackable_ptr<T> const& other) : std::weak_ptr<T>(other) {}
        unique_strong_ref_ptr<T> lock() const;
    };

    template<typename T>
    class unique_strong_ref_ptr : public std::shared_ptr<T>
    {
    public:
        unique_strong_ref_ptr() = default;
        unique_strong_ref_ptr(unique_strong_ref_ptr const&) = default;
        template<typename U> unique_strong_ref_ptr(std::shared_ptr<U> const& other) : std::shared_ptr<T>(other) {}
    };

    template<typename T>
    unique_strong_ref_ptr<T> unique_weak_ptr<T>::lock() const
    {
        return unique_strong_ref_ptr<T>(std::weak_ptr<T>::lock());
    }

    template<typename T, typename U>
    unique_weak_ptr<T> static_pointer_cast(unique_weak_ptr<U> const& r)
    {
        unique_weak_ptr<T> result;
        std::shared_ptr<U> locked = r.lock();
        if (locked)
            result = unique_trackable_ptr<T>(std::static_pointer_cast<T>(std::shared_ptr<U>(locked)));
        return result;
    }
}

#endif
