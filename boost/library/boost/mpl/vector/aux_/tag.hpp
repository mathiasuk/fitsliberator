
#ifndef BOOST_MPL_VECTOR_AUX_TAG_HPP_INCLUDED
#define BOOST_MPL_VECTOR_AUX_TAG_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Source: /project24/CVS/liberator/boost/library/boost/mpl/vector/aux_/tag.hpp,v $
// $Date: 2008/04/19 09:38:41 $
// $Revision: 1.4 $

#include <boost/mpl/aux_/config/typeof.hpp>
#include <boost/mpl/aux_/nttp_decl.hpp>

namespace boost { namespace mpl { namespace aux {

struct v_iter_tag;

#if defined(BOOST_MPL_CFG_TYPEOF_BASED_SEQUENCES)
struct vector_tag;
#else
template< BOOST_MPL_AUX_NTTP_DECL(long, N) > struct vector_tag;
#endif

}}}

#endif // BOOST_MPL_VECTOR_AUX_TAG_HPP_INCLUDED
