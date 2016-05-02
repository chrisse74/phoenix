/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef BOOST_PHOENIX_CORE_LIMITS_HPP
#define BOOST_PHOENIX_CORE_LIMITS_HPP

#include <boost/config.hpp>
#include <boost/preprocessor/arithmetic/add.hpp>
#include <boost/preprocessor/inc.hpp>
#include <boost/preprocessor/dec.hpp>
#include <boost/preprocessor/stringize.hpp>
#include <boost/phoenix/version.hpp>
#include <boost/phoenix/support/preprocessor/round.hpp>


#if defined(BOOST_PHOENIX_LIMIT)
# if !defined( BOOST_PROTO_MAX_ARITY )
#  define BOOST_PROTO_MAX_ARITY BOOST_PHOENIX_LIMIT
# elif (BOOST_PROTO_MAX_ARITY < BOOST_PHOENIX_LIMIT)
#  error "BOOST_PROTO_MAX_ARITY is set too low"
# endif
#include <boost/proto/proto_fwd.hpp>
#else
#include <boost/proto/proto_fwd.hpp>
#define BOOST_PHOENIX_LIMIT BOOST_PROTO_MAX_ARITY
#endif

#if !defined(PHOENIX_LIMIT)
#define PHOENIX_LIMIT BOOST_PHOENIX_LIMIT
#endif

#define BOOST_PHOENIX_LIMIT_STR BOOST_PP_STRINGIZE(BOOST_PHOENIX_PP_ROUND_UP(BOOST_PHOENIX_LIMIT))

#ifdef BOOST_NO_CXX11_VARIADIC_TEMPLATES
# define BOOST_PHOENIX_NO_VARIADIC_ACTOR
# define BOOST_PHOENIX_NO_VARIADIC_CALL
# define BOOST_PHOENIX_NO_VARIADIC_FUNCTION_EQUAL
# define BOOST_PHOENIX_NO_VARIADIC_FUNCTION_EVAL
# define BOOST_PHOENIX_NO_VARIADIC_PHX2_RESULT
# define BOOST_PHOENIX_NO_VARIADIC_EXPRESSION
#endif
#ifdef BOOST_NO_CXX11_RVALUE_REFERENCES
# define BOOST_PHOENIX_NO_VARIADIC_ACTOR
# define BOOST_PHOENIX_NO_VARIADIC_FUNCTION_EVAL
#endif

# define BOOST_PHOENIX_NO_VARIADIC_BIND
# define BOOST_PHOENIX_NO_VARIADIC_OBJECT
# define BOOST_PHOENIX_NO_VARIADIC_OPERATOR

#if !defined(BOOST_PHOENIX_ARG_LIMIT)
# define BOOST_PHOENIX_ARG_LIMIT BOOST_PHOENIX_PP_ROUND_UP(BOOST_PHOENIX_LIMIT)
#elif (BOOST_PHOENIX_ARG_LIMIT < 5)
# error "BOOST_PHOENIX_ARG_LIMIT is set too low"
#elif BOOST_PHOENIX_ARG_LIMIT != BOOST_PHOENIX_PP_ROUND_UP(BOOST_PHOENIX_LIMIT) && !defined(BOOST_PHOENIX_DONT_USE_PREPROCESSED_FILES)
# define BOOST_PHOENIX_DONT_USE_PREPROCESSED_FILES
#endif

#if !defined(BOOST_PHOENIX_ACTOR_LIMIT)
# define BOOST_PHOENIX_ACTOR_LIMIT BOOST_PHOENIX_PP_ROUND_UP(BOOST_PHOENIX_LIMIT)
#elif (BOOST_PHOENIX_ACTOR_LIMIT > BOOST_PHOENIX_ARG_LIMIT)
# error "BOOST_PHOENIX_ACTOR_LIMIT > BOOST_PHOENIX_ARG_LIMIT"
#elif (BOOST_PHOENIX_ACTOR_LIMIT < 3)
# error "BOOST_PHOENIX_ACTOR_LIMIT is set too low"
#elif BOOST_PHOENIX_ACTOR_LIMIT != BOOST_PHOENIX_PP_ROUND_UP(BOOST_PHOENIX_LIMIT) && !defined(BOOST_PHOENIX_DONT_USE_PREPROCESSED_FILES)
# define BOOST_PHOENIX_DONT_USE_PREPROCESSED_FILES
#endif

#if !defined(BOOST_PHOENIX_PERFECT_FORWARD_LIMIT)
# define BOOST_PHOENIX_PERFECT_FORWARD_LIMIT 3
#elif (BOOST_PHOENIX_PERFECT_FORWARD_LIMIT > BOOST_PHOENIX_ACTOR_LIMIT)
# error "BOOST_PHOENIX_PERFECT_FORWARD_LIMIT > BOOST_PHOENIX_ACTOR_LIMIT"
#elif (BOOST_PHOENIX_PERFECT_FORWARD_LIMIT < 3)
# error "BOOST_PHOENIX_PERFECT_FORWARD_LIMIT is set too low"
#elif BOOST_PHOENIX_PERFECT_FORWARD_LIMIT != 3 && !defined(BOOST_PHOENIX_DONT_USE_PREPROCESSED_FILES)
# define BOOST_PHOENIX_DONT_USE_PREPROCESSED_FILES
#endif

#if !defined(BOOST_PHOENIX_COMPOSITE_LIMIT)
# define BOOST_PHOENIX_COMPOSITE_LIMIT BOOST_PHOENIX_PP_ROUND_UP(BOOST_PHOENIX_LIMIT)
#elif (BOOST_PHOENIX_COMPOSITE_LIMIT < 5)
# error "BOOST_PHOENIX_COMPOSITE_LIMIT is set too low"
#elif BOOST_PHOENIX_COMPOSITE_LIMIT != BOOST_PHOENIX_PP_ROUND_UP(BOOST_PHOENIX_LIMIT) && !defined(BOOST_PHOENIX_DONT_USE_PREPROCESSED_FILES)
# define BOOST_PHOENIX_DONT_USE_PREPROCESSED_FILES
#endif

#if !defined(BOOST_PHOENIX_MEMBER_LIMIT)
# define BOOST_PHOENIX_MEMBER_LIMIT BOOST_PP_DEC(BOOST_PHOENIX_COMPOSITE_LIMIT)
#elif (BOOST_PHOENIX_MEMBER_LIMIT > BOOST_PHOENIX_COMPOSITE_LIMIT)
# error "BOOST_PHOENIX_MEMBER_LIMIT > BOOST_PHOENIX_COMPOSITE_LIMIT"
#elif (BOOST_PHOENIX_MEMBER_LIMIT < 3)
# error "BOOST_PHOENIX_MEMBER_LIMIT is set too low"
#elif BOOST_PHOENIX_MEMBER_LIMIT != BOOST_PHOENIX_PP_ROUND_UP(BOOST_PHOENIX_LIMIT) && !defined(BOOST_PHOENIX_DONT_USE_PREPROCESSED_FILES)
# define BOOST_PHOENIX_DONT_USE_PREPROCESSED_FILES
#endif

#if !defined(BOOST_PHOENIX_CATCH_LIMIT)
# define BOOST_PHOENIX_CATCH_LIMIT BOOST_PHOENIX_COMPOSITE_LIMIT
#elif (BOOST_PHOENIX_CATCH_LIMIT < 1)
# error "BOOST_PHOENIX_CATCH_LIMIT is set too low"
#elif BOOST_PHOENIX_CATCH_LIMIT != BOOST_PHOENIX_PP_ROUND_UP(BOOST_PHOENIX_LIMIT) && !defined(BOOST_PHOENIX_DONT_USE_PREPROCESSED_FILES)
# define BOOST_PHOENIX_DONT_USE_PREPROCESSED_FILES
#endif

#if !defined(BOOST_PHOENIX_DYNAMIC_LIMIT)
# define BOOST_PHOENIX_DYNAMIC_LIMIT BOOST_PHOENIX_PP_ROUND_UP(BOOST_PHOENIX_LIMIT)
#elif (BOOST_PHOENIX_DYNAMIC_LIMIT < 1)
# error "BOOST_PHOENIX_DYNAMIC_LIMIT is set too low"
#elif BOOST_PHOENIX_DYNAMIC_LIMIT != BOOST_PHOENIX_PP_ROUND_UP(BOOST_PHOENIX_LIMIT) && !defined(BOOST_PHOENIX_DONT_USE_PREPROCESSED_FILES)
# define BOOST_PHOENIX_DONT_USE_PREPROCESSED_FILES
#endif

#if !defined(BOOST_PHOENIX_LOCAL_LIMIT)
# define BOOST_PHOENIX_LOCAL_LIMIT BOOST_PHOENIX_PP_ROUND_UP(BOOST_PHOENIX_LIMIT)
#elif (BOOST_PHOENIX_LOCAL_LIMIT < 3)
# error "BOOST_PHOENIX_LOCAL_LIMIT is set too low"
#elif BOOST_PHOENIX_LOCAL_LIMIT != BOOST_PHOENIX_PP_ROUND_UP(BOOST_PHOENIX_LIMIT) && !defined(BOOST_PHOENIX_DONT_USE_PREPROCESSED_FILES)
# define BOOST_PHOENIX_DONT_USE_PREPROCESSED_FILES
#endif

#endif
