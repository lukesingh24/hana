/*
@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/concept/struct.hpp>
using namespace boost::hana;


struct Person {
    BOOST_HANA_DEFINE_STRUCT(Person,
        (int, Person)
    );
};

struct Employee {
    int Employee;
};

BOOST_HANA_ADAPT_STRUCT(Employee, Employee);

int main() { }
