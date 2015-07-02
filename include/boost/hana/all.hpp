/*!
@file
Defines `boost::hana::all`.

@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_ALL_HPP
#define BOOST_HANA_ALL_HPP

#include <boost/hana/fwd/all.hpp>

#include <boost/hana/core/datatype.hpp>
#include <boost/hana/core/default.hpp>
#include <boost/hana/core/models.hpp>
#include <boost/hana/core/when.hpp>
#include <boost/hana/detail/dispatch_if.hpp>

#include <boost/hana/all_of.hpp>
#include <boost/hana/functional/id.hpp>


namespace boost { namespace hana {
    //! @cond
    template <typename Xs>
    constexpr auto all_t::operator()(Xs&& xs) const {
        using S = typename datatype<Xs>::type;
        using All = BOOST_HANA_DISPATCH_IF(all_impl<S>,
            _models<Searchable, S>::value
        );

    #ifndef BOOST_HANA_CONFIG_DISABLE_CONCEPT_CHECKS
        static_assert(_models<Searchable, S>::value,
        "hana::all(xs) requires 'xs' to be a Searchable");
    #endif

        return All::apply(static_cast<Xs&&>(xs));
    }
    //! @endcond

    template <typename S, bool condition>
    struct all_impl<S, when<condition>> : default_ {
        template <typename Xs>
        static constexpr auto apply(Xs&& xs)
        { return hana::all_of(static_cast<Xs&&>(xs), hana::id); }
    };
}} // end namespace boost::hana

#endif // !BOOST_HANA_ALL_HPP
