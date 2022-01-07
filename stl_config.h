#pragma once

/* g++ 7.5.0 on Ubuntu18.04 LTS */



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



