/*
 * Copyright (c) 2012 Glen Joseph Fernandes 
 * glenfe at live dot com
 *
 * Distributed under the Boost Software License, 
 * Version 1.0. (See accompanying file LICENSE_1_0.txt 
 * or copy at http://boost.org/LICENSE_1_0.txt)
 */
#ifndef BOOST_SMART_PTR_ALLOCATE_SHARED_ARRAY_HPP
#define BOOST_SMART_PTR_ALLOCATE_SHARED_ARRAY_HPP

#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/smart_ptr/detail/allocate_array_helper.hpp>
#include <boost/smart_ptr/detail/array_deleter.hpp>
#include <boost/smart_ptr/detail/array_traits.hpp>
#include <boost/smart_ptr/detail/sp_if_array.hpp>

namespace boost {
    template<typename T, typename A>
    inline typename detail::sp_if_array<T>::type 
    allocate_shared(const A& allocator, size_t size) {
        typedef typename shared_ptr<T>::element_type  T1;
        typedef typename detail::array_type<T1>::type T2;
        T1* p1 = 0;
        T2* p2 = 0;
        size_t n1 = size * detail::array_size<T1>::size;
        detail::allocate_array_helper<A, T2> a1(allocator, n1, &p2);
        detail::array_deleter<T2> d1;
        shared_ptr<T> s1(p1, d1, a1);
        detail::array_deleter<T2>* d2;
        p1 = reinterpret_cast<T1*>(p2);
        d2 = get_deleter<detail::array_deleter<T2> >(s1);
        d2->construct(p2, n1);
        return shared_ptr<T>(s1, p1);
    }
#if defined(BOOST_HAS_VARIADIC_TMPL) && defined(BOOST_HAS_RVALUE_REFS)
    template<typename T, typename A, typename... Args>
    inline typename detail::sp_if_array<T>::type
    allocate_shared(const A& allocator, size_t size, Args&&... args) {
        typedef typename shared_ptr<T>::element_type  T1;
        typedef typename detail::array_type<T1>::type T2;
        T1* p1 = 0;
        T2* p2 = 0;
        size_t n1 = size * detail::array_size<T1>::size;
        detail::allocate_array_helper<A, T2> a1(allocator, n1, &p2);
        detail::array_deleter<T2> d1;
        shared_ptr<T> s1(p1, d1, a1);
        detail::array_deleter<T2>* d2;
        p1 = reinterpret_cast<T1*>(p2);
        d2 = get_deleter<detail::array_deleter<T2> >(s1);
        d2->construct(p2, n1, std::forward<Args>(args)...);
        return shared_ptr<T>(s1, p1);
    }
#endif
}

#endif
