/*!
@file
Forward declares `boost::hana::ordering`.

@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_FWD_ORDERING_HPP
#define BOOST_HANA_FWD_ORDERING_HPP

namespace boost { namespace hana {
    //! Returns a function performing `less` after applying a transformation
    //! to both arguments.
    //! @relates Orderable
    //!
    //! `ordering` creates a total order based on the result of applying a
    //! function to some objects, which is especially useful in conjunction
    //! with algorithms that accept a custom predicate that must represent
    //! a total order.
    //!
    //! Specifically, `ordering` is such that
    //! @code
    //!     ordering(f) == less ^on^ f
    //! @endcode
    //! or, equivalently,
    //! @code
    //!     ordering(f)(x, y) == less(f(x), f(y))
    //! @endcode
    //!
    //! @note
    //! This is not a tag-dispatched method (hence it can't be customized),
    //! but just a convenience function provided with the `Orderable` concept.
    //!
    //!
    //! Signature
    //! ---------
    //! Given a Logical `Bool` and an Orderable `B`, the signature is
    //! @f$ \mathrm{ordering} : (A \to B) \to (A \times A \to Bool) @f$.
    //!
    //!
    //! Example
    //! -------
    //! @snippet example/orderable.cpp ordering
#ifdef BOOST_HANA_DOXYGEN_INVOKED
    constexpr auto ordering = [](auto&& f) {
        return [perfect-capture](auto&& x, auto&& y) -> decltype(auto) {
            return less(f(forwarded(x)), f(forwarded(y)));
        };
    };
#else
    struct ordering_t {
        template <typename F>
        constexpr auto operator()(F&& f) const;
    };

    constexpr ordering_t ordering{};
#endif
}} // end namespace boost::hana

#endif // !BOOST_HANA_FWD_ORDERING_HPP
