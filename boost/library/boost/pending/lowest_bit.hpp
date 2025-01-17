// -------------------------------------
// lowest_bit.hpp
//
//           Position of the lowest bit 'on'
//
//       (C) Copyright Gennaro Prota 2003 - 2004.
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// ------------------------------------------------------
//
// $Id: lowest_bit.hpp,v 1.3 2008/04/19 09:38:42 teis Exp $

#ifndef BOOST_LOWEST_BIT_HPP_GP_20030301
#define BOOST_LOWEST_BIT_HPP_GP_20030301

#include <assert.h>
#include "boost/pending/integer_log2.hpp"


namespace boost {

    template <typename T>
    int lowest_bit(T x) {

        assert(x >= 1); // PRE

        // clear all bits on except the rightmost one,
        // then calculate the logarithm base 2
        //
        return boost::integer_log2<T>( x - ( x & (x-1) ) );

    }


}


#endif // include guard
