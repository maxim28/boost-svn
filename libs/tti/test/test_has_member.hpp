
//  (C) Copyright Edward Diener 2011
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#if !defined(TEST_HAS_MEMBER_HPP)
#define TEST_HAS_MEMBER_HPP

#include "test_structs.hpp"
#include <boost/tti/has_member_function_with_sig.hpp>

BOOST_TTI_HAS_MEMBER_FUNCTION_WITH_SIG(VoidFunction)
BOOST_TTI_TRAIT_HAS_MEMBER_FUNCTION_WITH_SIG(FunctionReturningInt,IntFunction)
BOOST_TTI_HAS_MEMBER_FUNCTION_WITH_SIG(aFunction)
BOOST_TTI_TRAIT_HAS_MEMBER_FUNCTION_WITH_SIG(AnotherIntFunction,anotherFunction)
BOOST_TTI_HAS_MEMBER_FUNCTION_WITH_SIG(sFunction)
BOOST_TTI_HAS_MEMBER_FUNCTION_WITH_SIG(someFunctionMember)

#endif // TEST_HAS_MEMBER_HPP
