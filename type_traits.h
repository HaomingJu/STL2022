#pragma once

/* 
 * C++11 基本内置类型有:
 * int, short, long, unsigned int, unsigned short, unsigned long, long long, unsigned long long
 * float, double, long double
 * bool, char, unsigned char, signed char
 */

#include "stl_config.h"

_STL2022_NAMESPACE_HEAD

struct __false_type {};
struct __true_type {};

template <typename _Tp>
struct __type_traits {
    typedef __false_type has_trivial_default_constructor;
    typedef __false_type has_trivial_copy_constructor;
    typedef __false_type has_trivial_assignment_operator;
    typedef __false_type has_trivial_destructor;
    typedef __false_type is_POD_type;
};

template <typename _Tp>
struct __is_integer {
    typedef __false_type _Integral;
};

// 为了节约空间, 避免重复代码
#define INSIDE_BASE_TYPE_TRAITS                          \
    typedef __true_type has_trivial_default_constructor; \
    typedef __true_type has_trivial_destructor;          \
    typedef __true_type has_trivial_copy_constructor;    \
    typedef __true_type has_trivial_assignment_operator;

#define INSIDE_BASE_IS_INTEGER typedef __true_type _Integral;

template <>
struct __type_traits<int> {
    INSIDE_BASE_TYPE_TRAITS
};

template <>
struct __type_traits<short> {
    INSIDE_BASE_TYPE_TRAITS
};

template <>
struct __type_traits<long> {
    INSIDE_BASE_TYPE_TRAITS
};

template <>
struct __type_traits<unsigned int> {
    INSIDE_BASE_TYPE_TRAITS
};

template <>
struct __type_traits<unsigned short> {
    INSIDE_BASE_TYPE_TRAITS
};

template <>
struct __type_traits<unsigned long> {
    INSIDE_BASE_TYPE_TRAITS
};

template <>
struct __type_traits<long long> {
    INSIDE_BASE_TYPE_TRAITS
};

template <>
struct __type_traits<unsigned long long> {
    INSIDE_BASE_TYPE_TRAITS
};

template <>
struct __type_traits<float> {
    INSIDE_BASE_TYPE_TRAITS
};

template <>
struct __type_traits<double> {
    INSIDE_BASE_TYPE_TRAITS
};

template <>
struct __type_traits<long double> {
    INSIDE_BASE_TYPE_TRAITS
};

template <>
struct __type_traits<bool> {
    INSIDE_BASE_TYPE_TRAITS
};

template <>
struct __type_traits<char> {
    INSIDE_BASE_TYPE_TRAITS
};

template <>
struct __type_traits<unsigned char> {
    INSIDE_BASE_TYPE_TRAITS
};

template <>
struct __type_traits<signed char> {
    INSIDE_BASE_TYPE_TRAITS
};

// 判断是否是整数

template <>
struct __is_integer<int> {
    INSIDE_BASE_IS_INTEGER
};

template <>
struct __is_integer<short> {
    INSIDE_BASE_IS_INTEGER
};

template <>
struct __is_integer<long> {
    INSIDE_BASE_IS_INTEGER
};

template <>
struct __is_integer<unsigned int> {
    INSIDE_BASE_IS_INTEGER
};

template <>
struct __is_integer<unsigned short> {
    INSIDE_BASE_IS_INTEGER
};

template <>
struct __is_integer<unsigned long> {
    INSIDE_BASE_IS_INTEGER
};

template <>
struct __is_integer<long long> {
    INSIDE_BASE_IS_INTEGER
};

template <>
struct __is_integer<unsigned long long> {
    INSIDE_BASE_IS_INTEGER
};

template <>
struct __is_integer<bool> {
    INSIDE_BASE_TYPE_TRAITS
};

template <>
struct __is_integer<char> {
    INSIDE_BASE_TYPE_TRAITS
};

template <>
struct __is_integer<unsigned char> {
    INSIDE_BASE_TYPE_TRAITS
};

template <>
struct __is_integer<signed char> {
    INSIDE_BASE_TYPE_TRAITS
};

_STL2022_NAMESPACE_END

