/*!
@file
Forward declares `boost::hana::max`.

@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_FWD_MAX_HPP
#define BOOST_HANA_FWD_MAX_HPP

#include <boost/hana/core/when.hpp>


namespace boost { namespace hana {
    //! Returns the greatest of its arguments according to the `less` ordering.
    //! @relates Orderable
    //!
    //!
    //! @todo Can't specify the signature here either. See `min` for details.
    //!
    //! Example
    //! -------
    //! @snippet example/orderable.cpp max
#ifdef BOOST_HANA_DOXYGEN_INVOKED
    constexpr auto max = [](auto&& x, auto&& y) -> decltype(auto) {
        return tag-dispatched;
    };
#else
    template <typename T, typename U, typename = void>
    struct max_impl : max_impl<T, U, when<true>> { };

    struct max_t {
        template <typename X, typename Y>
        constexpr decltype(auto) operator()(X&& x, Y&& y) const;
    };

    constexpr max_t max{};
#endif
}} // end namespace boost::hana

#endif // !BOOST_HANA_FWD_MAX_HPP
