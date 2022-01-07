#pragma once
#include <cstddef>
#include <cstring>

#include "stl_config.h"
#include "stl_iterator_base.h"
#include "type_traits.h"

_STL2022_NAMESPACE_HEAD

/* # swap */
/* ## 针对迭代器 */
template <typename _ForwardIter>
inline void iter_swap(_ForwardIter iter1_, _ForwardIter iter2_) {
    //typename iterator_traits<_ForwardIter>::value_type tmp = *iter1_;
    ITERATOR_TRAITS_VALUE_TYPE(_ForwardIter) tmp = *iter1_;
    *iter1_ = *iter2_;
    *iter2_ = tmp;
}

/* ## 针对裸指针 */
template <typename _Tp>
inline void iter_swap(_Tp* iter1_, _Tp* iter2_) {
    _Tp tmp = *iter1_;
    *iter1_ = *iter2_;
    *iter2_ = tmp;
}

template <typename _T>
inline void swap(_T& a_, _T& b_) {
    _T tmp = a_;
    a_ = b_;
    b_ = tmp;
}

/* # min & max */
template <typename _Tp>
inline const _Tp& min(const _Tp& a_, const _Tp& b_) {
    return a_ < b_ ? a_ : b_;
}

template <typename _Tp>
inline const _Tp& max(const _Tp& a_, const _Tp& b_) {
    return a_ < b_ ? b_ : a_;
}

template <typename _Tp, typename _Compare>
inline const _Tp& min(const _Tp& a_, const _Tp& b_, _Compare compare_) {
    return compare_(a_, b_) ? a_ : b_;
}

template <typename _Tp, typename _Compare>
inline const _Tp& max(const _Tp& a_, const _Tp& b_, _Compare compare_) {
    return compare_(a_, b_) ? b_ : a_;
}

/* equal 判断两个迭代器所指数据组是否相同 */
template <typename _InputIter1, typename _InputIter2>
inline bool equal(_InputIter1 first1_, _InputIter1 last1_, _InputIter2 first2_) {
    for(; first1_ != last1_; ++first1_, ++first2_) {
        if(*first1_ != *first2_)
            return false;
    }
    return true;
}

template <typename _InputIter1, typename _InputIter2, typename _Compare>
inline bool equal(_InputIter1 first1_, _InputIter1 last1_, _InputIter2 first2_, _Compare compare_) {
    for(; first1_ != last1_; ++first1_, ++first2_) {
        if(!(compare_(*first1_, *first2_)))
            return false;
    }
    return true;
}

/* copy */
template <typename _InputIter, typename _OutputIter>
inline _OutputIter __copy(_InputIter first_, _InputIter last_, _OutputIter result_, input_iterator_tag) {
    for(; first_ != last_; ++first_, ++result_) {
        *result_ = *first_;
    }
    return result_;
}

template <typename _InputIter, typename _OutputIter>
inline _OutputIter __copy(_InputIter first_, _InputIter last_, _OutputIter result_, random_iterator_tag) {
    typedef ITERATOR_TRAITS_DIFFERENCE_TYPE(_InputIter) _Distance;
    for(_Distance n = last_ - first_; n > 0; --n) {
        *(result_++) = *(first_++);
    }
    return result_;
}

template <typename T>
inline T* __copy_trivial(const T* first_, const T* last_, T* result_) {
    memmove(result_, first_, sizeof(T) * (last_ - first_));
    return result_ + (last_ - first_);
}

template <typename _InputIter, typename _OutputIter>
inline _OutputIter __copy_aux2(_InputIter first_, _InputIter last_, _OutputIter result_, __false_type) {
    return __copy(first_, last_, result_, __ITERATOR_CATEGORY(first_));
}

template <typename _InputIter, typename _OutputIter>
inline _OutputIter __copy_aux2(_InputIter first_, _InputIter last_, _OutputIter result_, __true_type) {
    return __copy(first_, last_, result_, __ITERATOR_CATEGORY(first_));
}

template <typename T>
inline T* __copy_aux2(const T* first_, const T* last_, T* result_, __true_type) {
    return __copy_trivial(first_, last_, result_);
}

template <typename T>
inline T* __copy_aux2(T* first_, T* last_, T* result_, __true_type) {
    return __copy_trivial(first_, last_, result_);
}

/* 该函数仅仅为了使用类型推断出迭代器或指针所指的类型 */
template <typename _InputIter, typename _OutputIter, typename _T>
inline _OutputIter __copy_aux(_InputIter first_, _InputIter last_, _OutputIter result_, _T) {
    typedef typename __type_traits<_T>::has_trivial_assignment_operator isTrivial;
    __copy_aux2(first_, last_, result_, isTrivial());
}

/* 最后的被其他文件调用的函数 */
template <typename _InputIter, typename _OutputIter>
inline _OutputIter copy(_InputIter first_, _InputIter last_, _OutputIter result_) {
    __copy_aux(first_, last_, result_, __VALUE_TYPE(first_));
}

/* copy_backward */
template <typename _BI1, typename _BI2>
inline _BI2 __copy_backward(_BI1 first_, _BI1 last_, _BI2 result_, bidirectional_iterator_tag) {
    while(first_ != last_) {
        *--result_ = *--last_;
    }
    return result_;
}

/** for通过对n的判断比while中对两个迭代器是否相等的判断 快**/
template <typename _RI1, typename _RI2>
inline _RI2 __copy_backward(_RI1 first_, _RI1 last_, _RI2 result_, random_iterator_tag) {
    typedef ITERATOR_TRAITS_DIFFERENCE_TYPE(_RI1) _Distance;
    for(_Distance n = last_ - last_; n > 0; --n) {
        *--result_ = *--last_;
    }
    return result_;
}

template <typename _BI1, typename _BI2>
inline _BI2 __copy_backward_aux2(_BI1 first_, _BI1 last_, _BI2 result_, __true_type) {
    typedef ITERATOR_TRAITS_CATEGORY(_BI1) _Category;
    __copy_backward(first_, last_, result_, _Category());
}

template <typename _BI1, typename _BI2>
inline _BI2 __copy_backward_aux2(_BI1 first_, _BI1 last_, _BI2 result_, __false_type) {
    typedef ITERATOR_TRAITS_CATEGORY(_BI1) _Category;
    __copy_backward(first_, last_, result_, _Category());
}

template <typename _T>
inline _T* __copy_backward_aux2(const _T* first_, const _T* last_, _T* result_, __true_type) {
    result_ = result_ - (last_ - first_);
    __copy_trivial(first_, last_, result_);  // To call memmove
}

template <typename _BI1, typename _BI2, typename _T>
inline _BI2 __copy_backward_aux(_BI1 first_, _BI1 last_, _BI2 result_, _T) {
    typedef typename __type_traits<_T>::has_trivial_assignment_operator _Trivial;
    __copy_backward_aux(first_, last_, result_, _Trivial());
}

template <typename _BI1, typename _BI2>
inline _BI2 copy_backward(_BI1 first_, _BI1 last_, _BI2 result_) {
    typedef ITERATOR_TRAITS_VALUE_TYPE(_BI1) _ValueType;
    __copy_backward_aux(first_, last_, result_, _ValueType());
}

/* copy_n */

/* fill */

/* fill_n */

_STL2022_NAMESPACE_END
