// Boost.Geometry (aka GGL, Generic Geometry Library)
//
// Copyright Barend Gehrels 2011, Geodan, Amsterdam, the Netherlands
// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// Quickbook Example

//[assign_point_to_index
//` Shows how to assign the lower-left or upper-right point from a box

#include <iostream>

#include <boost/geometry/geometry.hpp>
#include <boost/geometry/geometries/geometries.hpp>

using namespace boost::geometry;

int main()
{
    typedef model::d2::point_xy<int> point;
    typedef model::box<point> box;

    point lower_left(0, 0), upper_right(2, 2);

    box b;
    assign_point_to_index<0>(lower_left, b);
    assign_point_to_index<1>(upper_right, b);
    std::cout << "box: " << dsv(b) << std::endl;

    return 0;
}

//]


//[assign_point_to_index_output
/*`
Output:
[pre
box: ((0, 0), (2, 2))
]
*/
//]