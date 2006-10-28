///////////////////////////////////////////////////////////////////////////////
/// \file proto_fwd.hpp
/// Forward declarations of all of proto2's public types and functions.
//
//  Copyright 2004 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROTO2_FWD_HPP_EAN_04_01_2005
#define BOOST_PROTO2_FWD_HPP_EAN_04_01_2005

#include <boost/version.hpp>
#include <boost/mpl/size.hpp>
#include <boost/type_traits/remove_cv.hpp>
#include <boost/type_traits/remove_reference.hpp>
#include <boost/mpl/vector/vector10.hpp>

#ifndef BOOST_PROTO2_MAX_ARITY
# define BOOST_PROTO2_MAX_ARITY 10
#endif

namespace boost { namespace proto2
{
    ///////////////////////////////////////////////////////////////////////////////
    // Operator tags
    struct unary_tag;
    struct binary_tag;
    struct nary_tag;

    struct terminal_tag;
    struct unary_plus_tag;
    struct unary_minus_tag;
    struct unary_star_tag;
    struct complement_tag;
    struct address_of_tag;
    struct logical_not_tag;
    struct pre_inc_tag;
    struct pre_dec_tag;
    struct post_inc_tag;
    struct post_dec_tag;

    struct left_shift_tag;
    struct right_shift_tag;
    struct multiply_tag;
    struct divide_tag;
    struct modulus_tag;
    struct add_tag;
    struct subtract_tag;
    struct less_tag;
    struct greater_tag;
    struct less_equal_tag;
    struct greater_equal_tag;
    struct equal_tag;
    struct not_equal_tag;
    struct logical_or_tag;
    struct logical_and_tag;
    struct bitand_tag;
    struct bitor_tag;
    struct bitxor_tag;
    struct comma_tag;
    struct mem_ptr_tag;

    struct assign_tag;
    struct left_shift_assign_tag;
    struct right_shift_assign_tag;
    struct multiply_assign_tag;
    struct divide_assign_tag;
    struct modulus_assign_tag;
    struct add_assign_tag;
    struct subtract_assign_tag;
    struct bitand_assign_tag;
    struct bitor_assign_tag;
    struct bitxor_assign_tag;
    struct subscript_tag;

    struct function_tag;

    template<typename Tag, typename Args, long Arity = mpl::size<Args>::value>
    struct basic_expr;

    template<typename Expr>
    struct ref;

    template<typename Tag, typename Arg>
    struct unary_expr;

    template<typename Tag, typename Left, typename Right>
    struct binary_expr;

    template<typename T>
    struct is_op;

    template<typename Expr>
    struct literal;

    template<typename Expr>
    struct arg_type;

    template<typename Expr>
    struct left_type;

    template<typename Expr>
    struct right_type;

    template<typename Expr>
    struct tag_type;

    template<typename OpTag, typename DomainTag, typename EnableIf = void>
    struct compiler;

    template<typename DomainTag>
    struct fold_compiler;

    template<typename DomainTag>
    struct reverse_fold_compiler;

    template<typename Lambda, typename DomainTag, typename Compiler = void>
    struct transform_compiler;

    template<typename Lambda, typename DomainTag>
    struct branch_compiler;

    template<typename Predicate, typename IfCompiler, typename ElseCompiler>
    struct conditional_compiler;

    template<typename Lambda, typename Map>
    struct switch_compiler;

    template<typename DomainTag>
    struct pass_through_compiler;

    struct error_compiler;

    struct identity_transform;

    struct arg_transform;

    struct left_transform;

    struct right_transform;

    template<typename Always>
    struct always_transform;

    template<typename First, typename Second>
    struct compose_transforms;

    template<typename Predicate, typename IfTransform, typename ElseTransform = identity_transform>
    struct conditional_transform;

    namespace meta
    {
        template<typename T>
        struct value_type
        {
            typedef typename remove_cv<typename remove_reference<T>::type>::type type;
        };

        template<typename T, bool IsOp = is_op<T>::value>
        struct as_expr;

        template<typename Expr, typename State, typename Visitor, typename DomainTag>
        struct compile;
    }

    namespace op
    {
        struct compile;

        struct as_expr;
    }

    extern op::compile const compile;
    extern op::as_expr const as_expr;

}} // namespace boost::proto2

#endif
