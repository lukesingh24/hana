/*
 * Copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/foldable.hpp>

#include <boost/hana/detail/static_assert.hpp>
#include <boost/hana/functional.hpp>
#include <boost/hana/integral.hpp>
#include <boost/hana/list.hpp>

#include "minimal_foldable.hpp"
using namespace boost::hana;


int main() {
    BOOST_HANA_STATIC_ASSERT(unpack(list, foldable()) == list());
    BOOST_HANA_STATIC_ASSERT(unpack(list, foldable(int_<0>)) == list_c<int, 0>);
    BOOST_HANA_STATIC_ASSERT(unpack(list, foldable(int_<0>, int_<1>)) == list_c<int, 0, 1>);
    BOOST_HANA_STATIC_ASSERT(unpack(list, foldable(int_<0>, int_<1>, int_<2>)) == list_c<int, 0, 1, 2>);

    BOOST_HANA_STATIC_ASSERT(unpack(list, foldable(0)) == list(0));
    BOOST_HANA_STATIC_ASSERT(unpack(list, foldable(0, '1')) == list(0, '1'));
    BOOST_HANA_STATIC_ASSERT(unpack(list, foldable(0, '1', "2")) == list(0, '1', "2"));
}
