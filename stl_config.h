#pragma once

/*
    g++ (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
    Copyright (C) 2017 Free Software Foundation, Inc.
    This is free software; see the source for copying conditions.  There is NO
    warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/



/* 名字空间宏 */
#define STL_NS STL2022
#define _STL2022_NAMESPACE_HEAD namespace STL_NS {
#define _STL2022_NAMESPACE_END }

/* 使用一级配置器, 对二级配置器先搁置 */
#define __USE_MALLOC
#undef __STL_USE_STD_ALLOCATORS

/* 满足模板函数部分排序Partial ordering of function template */
#define __STL_FUNCTION_TMPL_PARTIAL_ORDER

/* 线程不安全, 未加锁 */



