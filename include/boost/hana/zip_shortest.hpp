/*!
@file
Defines `boost::hana::zip_shortest`.

@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_ZIP_SHORTEST_HPP
#define BOOST_HANA_ZIP_SHORTEST_HPP

#include <boost/hana/fwd/zip_shortest.hpp>

#include <boost/hana/core/datatype.hpp>
#include <boost/hana/core/default.hpp>
#include <boost/hana/core/models.hpp>
#include <boost/hana/core/when.hpp>
#include <boost/hana/detail/dispatch_if.hpp>

#include <boost/hana/all.hpp>
#include <boost/hana/tuple.hpp>
#include <boost/hana/zip_shortest_with.hpp>


namespace boost { namespace hana {
    //! @cond
    template <typename Xs, typename ...Ys>
    constexpr auto zip_shortest_t::operator()(Xs&& xs, Ys&& ...ys) const {
    #ifndef BOOST_HANA_CONFIG_DISABLE_CONCEPT_CHECKS
        constexpr bool models_of_Sequence[] = {
            _models<Sequence, Xs>{}, _models<Sequence, Ys>{}...
        };
        static_assert(hana::all(models_of_Sequence),
        "hana::zip_shortest(xs, ys...) requires 'xs' and 'ys...' to be Sequences");
    #endif

        return zip_shortest_impl<typename datatype<Xs>::type>::apply(
            static_cast<Xs&&>(xs),
            static_cast<Ys&&>(ys)...
        );
    }
    //! @endcond

    template <typename S, bool condition>
    struct zip_shortest_impl<S, when<condition>> : default_ {
        template <typename ...Xs>
        static constexpr decltype(auto) apply(Xs&& ...xs) {
            return hana::zip_shortest_with(hana::make_tuple,
                                           static_cast<Xs&&>(xs)...);
        }
    };
}} // end namespace boost::hana

#endif // !BOOST_HANA_ZIP_SHORTEST_HPP
