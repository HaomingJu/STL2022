#pragma once
#include "stl_config.h"  // for namespace macro
#include <cstddef> // for ptrdiff_t

_STL2022_NAMESPACE_HEAD

/* # 迭代器类型分类 */
struct input_iterator_tag {};                                        // 输入(读取)迭代器
struct forward_iterator_tag : public input_iterator_tag {};          // 前向(读取)迭代器
struct bidirectional_iterator_tag : public forward_iterator_tag {};  // 双向(读取)迭代器
struct random_iterator_tag : public bidirectional_iterator_tag {};   // 随机(读取)迭代器, 支持- +
struct output_iterator_tag {};                                       // 输出迭代器

/* # 基础模板迭代器 */
template <typename _Category, typename _Tp, typename _Distance = ptrdiff_t, typename _Pointer = _Tp*, typename _Reference = _Tp&>
struct iterator {
    typedef _Category  iterator_category;
    typedef _Tp        value_type;
    typedef _Distance  difference_type;
    typedef _Pointer   pointer_type;
    typedef _Reference reference_type;
};

/* # 对基础模板迭代器的特化 [Usage]: input_itertor<_Tp, _Distance>; */
template <typename _Tp>
using input_itertor = iterator<input_iterator_tag, _Tp>;

template <typename _Tp>
using forward_iterator = iterator<forward_iterator_tag, _Tp>;

template <typename _Tp>
using bidirectional_iterator = iterator<bidirectional_iterator_tag, _Tp>;

template <typename _Tp>
using random_iterator = iterator<random_iterator_tag, _Tp>;

/* ## output_iterator_tag类型的迭代器很特殊 TODO: 为啥全部为void */
using output_iterator = iterator<output_iterator_tag, void, void, void, void>;

/* # 迭代器属性萃取器 */
template <typename _Iter>
struct iterator_traits {
    typedef typename _Iter::iterator_category iterator_category;
    typedef typename _Iter::value_type        value_type;
    typedef typename _Iter::difference_type   difference_type;
    typedef typename _Iter::pointer_type      pointer_type;
    typedef typename _Iter::reference_type    reference_type;
};

/* ## 对裸指针的萃取 */
template <typename _T>
struct iterator_traits<_T*> {
    typedef random_iterator_tag     iterator_category;
    typedef _T                      value_type;
    typedef ptrdiff_t               difference_type;
    typedef _T*                     pointer_type;
    typedef _T&                     reference_type;
};

template <typename _T>
struct iterator_traits<const _T*> {
    typedef random_iterator_tag     iterator_category;
    typedef _T                      value_type;
    typedef ptrdiff_t               difference_type;
    typedef const _T*               pointer_type;
    typedef const _T&               reference_type;
};

/* # 增加一些萃取函数*/
#define ITERATOR_TRAITS_CATEGORY(_Iter) typename iterator_traits<_Iter>::iterator_category
#define ITERATOR_TRAITS_VALUE_TYPE(_Iter) typename iterator_traits<_Iter>::value_type
#define ITERATOR_TRAITS_DIFFERENCE_TYPE(_Iter) typename iterator_traits<_Iter>::difference_type

template <typename _Iter>
ITERATOR_TRAITS_CATEGORY(_Iter) __iterator_category(const _Iter&) {
    return ITERATOR_TRAITS_CATEGORY(_Iter)();
};

template <typename _Iter>
ITERATOR_TRAITS_VALUE_TYPE(_Iter) __value_type(const _Iter&) {
    return ITERATOR_TRAITS_VALUE_TYPE(_Iter)();
};

template <typename _Iter>
ITERATOR_TRAITS_DIFFERENCE_TYPE(_Iter) __distance_type(const _Iter&) {
    return ITERATOR_TRAITS_DIFFERENCE_TYPE(_Iter)();
}

/* ## 可以将_i的类型属性萃取出来, 并创建一个实例 */
#define __ITERATOR_CATEGORY(_i) __iterator_category(_i)
#define __VALUE_TYPE(_i) __value_type(_i)
#define __DISTANCE_TYPE(_i) __distance_type(_i)

/* # 针对迭代器的两个函数 distance 和 advance */
/* ## distance */

/* ### 针对仅支持operator++的迭代器 */
template <typename _Iter>
ITERATOR_TRAITS_DIFFERENCE_TYPE(_Iter) __distance(_Iter first_, _Iter last_, input_iterator_tag) {
    ITERATOR_TRAITS_DIFFERENCE_TYPE(_Iter) n = 0;
    while(first_ != last_) {
        ++first_;
        ++n;
    }
    return n;
};
/* ### random_iterator_tag 支持随机加减 operator+ operator- */
template <typename _Iter>
ITERATOR_TRAITS_DIFFERENCE_TYPE(_Iter) __distance(_Iter first_, _Iter last_, random_iterator_tag) {
    return last_ - first_;
};

template <typename _Iter>
ITERATOR_TRAITS_DIFFERENCE_TYPE(_Iter) distance(_Iter first_, _Iter last_) {
    return __distance(first_, last_, __ITERATOR_CATEGORY(first_));
};

/* ## __advance*/

template <typename _Iter, typename _Distance>
void __advance(_Iter& iter_, _Distance n_, input_iterator_tag) {
    /* 迭代器仅支持operator++, n_ 只能>=０*/
    while(n_--)
        ++iter_;
};

template <typename _Iter, typename _Distance>
void __advance(_Iter& iter_, _Distance n_, bidirectional_iterator_tag) {
    /* 双向迭代器支持 operator++ operator-- */
    if(n_ >= 0)
        while(n_--)
            ++iter_;
    else
        while(n_++)
            --iter_;
};

template <typename _Iter, typename _Distance>
void __advance(_Iter& iter_, _Distance n_, random_iterator_tag) {
    /* 随机迭代器支持operator+, operator- */
    iter_ += n_;
};

template <typename _Iter, typename _Distance>
void advance(_Iter& iter_, _Distance n_) {
    __advance(iter_, n_, __ITERATOR_CATEGORY(iter_));
};

_STL2022_NAMESPACE_END

/* 参考链接:
 * https://www.cplusplus.com/reference/iterator/
 */
