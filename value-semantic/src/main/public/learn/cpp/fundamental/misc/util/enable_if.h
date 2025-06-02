
#ifndef __LEARN_CPP_FUNDAMENTAL_MISC_VALUE_SEMANTIC_UTIL_ENABLE_IF_H
#define __LEARN_CPP_FUNDAMENTAL_MISC_VALUE_SEMANTIC_UTIL_ENABLE_IF_H

#include <type_traits>
#include <string>

namespace learn::cpp::fundamental::misc::value_semantic::util {

    template<typename T>
    struct IsStringConvertible : std::is_convertible<T, std::string> {};

    template<typename...>
    struct IsAllStringConvertible;

    template<>
    struct IsAllStringConvertible<> : std::true_type {};

    template<typename T, typename... Rest>
    struct IsAllStringConvertible<T, Rest...> :
        std::integral_constant<bool,
            IsStringConvertible<T>::value && IsAllStringConvertible<Rest...>::value> {};

    template<typename... Ts>
    using EnableIfAllStringConvertibleT =
        typename std::enable_if<IsAllStringConvertible<Ts...>::value, void>::type;

}

#endif