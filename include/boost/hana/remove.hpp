/*!
@file
Defines `boost::hana::remove`.

@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_REMOVE_HPP
#define BOOST_HANA_REMOVE_HPP

#include <boost/hana/fwd/remove.hpp>

#include <boost/hana/core/datatype.hpp>
#include <boost/hana/core/default.hpp>
#include <boost/hana/core/models.hpp>
#include <boost/hana/core/when.hpp>
#include <boost/hana/detail/dispatch_if.hpp>

#include <boost/hana/equal.hpp>
#include <boost/hana/filter.hpp>
#include <boost/hana/functional/compose.hpp>
#include <boost/hana/not.hpp>


namespace boost { namespace hana {
    //! @cond
    template <typename Xs, typename Value>
    constexpr auto remove_t::operator()(Xs&& xs, Value&& value) const {
        using M = typename datatype<Xs>::type;
        using Remove = BOOST_HANA_DISPATCH_IF(remove_impl<M>,
            _models<MonadPlus, M>::value
        );

        #ifndef BOOST_HANA_CONFIG_DISABLE_CONCEPT_CHECKS
            static_assert(_models<MonadPlus, M>::value,
            "hana::remove(xs, value) requires 'xs' to be a MonadPlus");
        #endif

        return Remove::apply(static_cast<Xs&&>(xs),
                             static_cast<Value&&>(value));
    }
    //! @endcond

    template <typename M, bool condition>
    struct remove_impl<M, when<condition>> : default_ {
        template <typename Xs, typename Value>
        static constexpr auto apply(Xs&& xs, Value&& value) {
            return hana::filter(static_cast<Xs&&>(xs),
                    hana::compose(hana::not_,
                                  hana::equal.to(static_cast<Value&&>(value))));
        }
    };
}} // end namespace boost::hana

#endif // !BOOST_HANA_REMOVE_HPP
