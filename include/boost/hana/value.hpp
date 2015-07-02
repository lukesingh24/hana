/*!
@file
Defines `boost::hana::value`.

@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_VALUE_HPP
#define BOOST_HANA_VALUE_HPP

#include <boost/hana/fwd/value.hpp>

#include <boost/hana/core/datatype.hpp>
#include <boost/hana/core/default.hpp>
#include <boost/hana/core/models.hpp>
#include <boost/hana/core/when.hpp>
#include <boost/hana/detail/dispatch_if.hpp>

#include <type_traits>


namespace boost { namespace hana {
    template <typename C, bool condition>
    struct value_impl<C, when<condition>> : default_ {
        template <typename ...Args>
        static constexpr auto apply(Args&& ...args) = delete;
    };

    template <typename T>
    constexpr decltype(auto) value() {
        using RawT = typename std::remove_cv<
            typename std::remove_reference<T>::type
        >::type;
        using C = typename datatype<RawT>::type;
        using Value = BOOST_HANA_DISPATCH_IF(
            value_impl<C>, _models<Constant, C>::value
        );

    #ifndef BOOST_HANA_CONFIG_DISABLE_CONCEPT_CHECKS
        static_assert(_models<Constant, C>::value,
        "hana::value<T>() requires 'T' to be a Constant");
    #endif

        return Value::template apply<RawT>();
    }
}} // end namespace boost::hana

#endif // !BOOST_HANA_VALUE_HPP
