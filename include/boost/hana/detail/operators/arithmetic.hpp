/*!
@file
Defines arithmetic operators.

@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_DETAIL_OPERATORS_ARITHMETIC_HPP
#define BOOST_HANA_DETAIL_OPERATORS_ARITHMETIC_HPP

#include <boost/hana/core/datatype.hpp>
#include <boost/hana/fwd/concept/group.hpp>
#include <boost/hana/fwd/concept/integral_domain.hpp>
#include <boost/hana/fwd/concept/monoid.hpp>
#include <boost/hana/fwd/concept/ring.hpp>

#include <type_traits>


namespace boost { namespace hana {
    namespace detail {
        template <typename Tag>
        struct arithmetic_operators {
            static constexpr bool value = false;
        };
    }

    namespace operators {
        template <typename X, typename Y, typename = typename std::enable_if<
            detail::arithmetic_operators<typename datatype<X>::type>::value ||
            detail::arithmetic_operators<typename datatype<Y>::type>::value
        >::type>
        constexpr auto operator+(X&& x, Y&& y)
        { return hana::plus(static_cast<X&&>(x), static_cast<Y&&>(y)); }


        template <typename X, typename Y, typename = typename std::enable_if<
            detail::arithmetic_operators<typename datatype<X>::type>::value ||
            detail::arithmetic_operators<typename datatype<Y>::type>::value
        >::type>
        constexpr auto operator-(X&& x, Y&& y)
        { return hana::minus(static_cast<X&&>(x), static_cast<Y&&>(y)); }

        template <typename X, typename = typename std::enable_if<
            detail::arithmetic_operators<typename datatype<X>::type>::value
        >::type>
        constexpr auto operator-(X&& x)
        { return hana::negate(static_cast<X&&>(x)); }


        template <typename X, typename Y, typename = typename std::enable_if<
            detail::arithmetic_operators<typename datatype<X>::type>::value ||
            detail::arithmetic_operators<typename datatype<Y>::type>::value
        >::type>
        constexpr auto operator*(X&& x, Y&& y)
        { return hana::mult(static_cast<X&&>(x), static_cast<Y&&>(y)); }


        template <typename X, typename Y, typename = typename std::enable_if<
            detail::arithmetic_operators<typename datatype<X>::type>::value ||
            detail::arithmetic_operators<typename datatype<Y>::type>::value
        >::type>
        constexpr auto operator/(X&& x, Y&& y)
        { return hana::quot(static_cast<X&&>(x), static_cast<Y&&>(y)); }

        template <typename X, typename Y, typename = typename std::enable_if<
            detail::arithmetic_operators<typename datatype<X>::type>::value ||
            detail::arithmetic_operators<typename datatype<Y>::type>::value
        >::type>
        constexpr auto operator%(X&& x, Y&& y)
        { return hana::rem(static_cast<X&&>(x), static_cast<Y&&>(y)); }
    }
}} // end namespace boost::hana

#endif // !BOOST_HANA_DETAIL_OPERATORS_ARITHMETIC_HPP
