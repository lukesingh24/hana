/*!
@file
Defines `boost::hana::Functor`.

@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_CONCEPT_FUNCTOR_HPP
#define BOOST_HANA_CONCEPT_FUNCTOR_HPP

#include <boost/hana/fwd/concept/functor.hpp>

#include <boost/hana/bool.hpp>
#include <boost/hana/concept/comparable.hpp>
#include <boost/hana/core/datatype.hpp>
#include <boost/hana/core/default.hpp>
#include <boost/hana/core/models.hpp>
#include <boost/hana/core/when.hpp>
#include <boost/hana/functional/always.hpp>
#include <boost/hana/functional/partial.hpp>
#include <boost/hana/concept/logical.hpp>

#include <boost/hana/transform.hpp>
#include <boost/hana/fill.hpp>
#include <boost/hana/adjust_if.hpp>
#include <boost/hana/adjust.hpp>
#include <boost/hana/replace.hpp>
#include <boost/hana/replace_if.hpp>


namespace boost { namespace hana {
    template <typename F>
    struct models_impl<Functor, F>
        : _integral_constant<bool,
            !is_default<transform_impl<F>>{}() ||
            !is_default<adjust_if_impl<F>>{}()
        >
    { };
}} // end namespace boost::hana

#endif // !BOOST_HANA_CONCEPT_FUNCTOR_HPP
