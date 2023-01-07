#include <cstddef>
#include <cstdio>
#include <cstring>
#include <string>
#include <limits>
#include <iterator>
#include <climits>
#include <type_traits>
/**
 * @brief 
 * Allows us to check version and operating system code is runnning on.
 * 
 * - Allows us to handle deprecation for C++11 and over
 * - Handling the following:
 * - Exceptions
 * - Constexpr
 * - [[nodiscard]]
 * - [[fallthrough]]
 * 
 */

/*********************************/
/*************CLANG***************/
/*********************************/
#if defined(__clang__) && !defined(__libmxl__)
// #   define FORMAT_CLANG_VERSION(__clang_major__ * 100 + __clang_minor__)
#else
#   define FORMAT_CLANG_VERSION 0
#endif

/***********************************/
/************** GCC ****************/
/***********************************/
#if defined(__GNUC__) && !defined(__clang__) && !defined(__INTEL_COMPILER) && !defined(__NVCOMPILER)
#   define FORMAT_GCC_VERSION(__GNUC__ * 100 + __GNUC_MINOR__)
#else
#   define FORMAT_GCC_VERSION 0
#endif

/*********************************/
/********** GCC PRGAMA ***********/
/*********************************/

#ifndef FORMAT_GCC_PRAGMA
#   if FORMAT_GCC_VERSION >= 504
#       define FORMAT_GCC_PRAGMA(args) __Pragma(arg)
#   else
#       define FORMAT_GCC_PRAGMA(arg)
#   endif
#endif

/***********************************/
/************** ICL ****************/
/***********************************/
#ifdef __ICL
#   define FORMAT_ICC_VERSION __ICL
#elif defined(__INTEL_COMPILER)
#   define FORMAT_ICC_VERS __INTEL_COMPILER
#else
#   define FORMAT_ICC_VERS 0
#endif

/*********************************/
/*************MSC VERS************/
/*********************************/
#ifdef _MSC_VER
#   define FORMAT_MSC_VERS _MSC_VER
#   define FORMAT_MSC_WARNING(...) __pragma(warning(__VA_ARGS__))
#else
#   define FORMAT_MSC_VERS 0
#   define FORMAT_MSC_WARNING(...)
#endif

/*********************************/
/*************MSC LANG************/
/*********************************/
#ifdef _MSVC_LANG
#   define FORMAT_CPLUSPLUS _MSVC_LANG
#else
#   define FORMAT_CPLUSPLUS __cplusplus
#endif

/*********************************/
/***********HAS_FEATURE***********/
/*********************************/
#ifdef __has_feature
#   define FORMAT_HAS_FEATURE(x) __has_feature(x)
#else
#   define FORMAT_HAS_FEATURE(x) 0
#endif

/*********************************/
/***********HAS_INCLUDE***********/
/*********************************/
#if defined(__has_include) || FORMAT_ICC_VERS >= 1600 || FORMAT_MSC_VERS > 1900
#   define FORMAT_HAS_INCLUDE(x) __has_include(x)
#else
#   define FORMAT_HAS_INCLUDE(x) 0
#endif

/*********************************/
/*************HAS_CPP*************/
/*********************************/
#ifdef __has_cpp_attribute
#   define FORMAT_HAS_CPP_ATTRIBUTE(x) __has_cpp_attribute(x)
#else
#   define FORMAT_HAS_CPP_ATTRIBUTE(x) 0
#endif

/*********************************/
/*************CPP_14**************/
/*********************************/
#define FORMAT_HAS_CPP14_ATTR(attribute) (FORMAT_CPLUSPLUS  >= 201402L && FORMAT_HAS_CPP_ATTRIBUTE(attribute))

/*********************************/
/*************CPP_17**************/
/*********************************/
#define FORMAT_HAS_CPP17_ATTR(attribute) (FORMAT_CPLUSPLUS >= 201703L && FORMAT_HAS_CPP_ATTRIBUTE(attribute))