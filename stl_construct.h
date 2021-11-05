#pragma once

#include <new>  //for placement new
#include "stl_config.h"
#include "stl_iterator_base.h"
#include "type_traits.h"  // for type_traits and __true_type　__false_type

_STL2022_NAMESPACE_HEAD

/* private */

/* _Construct 代码段*/

template <typename _T1, typename _T2>
void _Construct(_T1* ptr_, const _T2& value_) {
    new((void*) ptr_) _T1(value_);  //placement new
}  // Impl

template <typename _T1>
void _Construct(_T1* ptr_) {
    new((void*) ptr_) _T1();  //placement new
}  // Impl

/* # _Destroy 代码段 */

/* ## 单个类型指针, 直接调用析构函数(内置和非内置均有) */
template <typename _T1>
void _Destroy(_T1* ptr_) {
    ptr_->~_T1();
}  // Impl

template <typename _ForwardIterator>
void _destroy_aux(_ForwardIterator first_, _ForwardIterator last_, __false_type) {
    for(; first_ != last_; ++first_) {
        _Destroy(&*first_);  // 先从迭代器中获取对象, 然后取出裸地址
    }
}

template <typename _ForwardIterator>
void _destroy_aux(_ForwardIterator first_, _ForwardIterator last_, __true_type) {
    // Do nothing.
}

/* ## 两个迭代器表征的一个范围内的对象进行销毁 */
template <typename _ForwardIterator>
void _Destroy(_ForwardIterator first_, _ForwardIterator last_) {
    // 从迭代器中萃取出值类型
    typedef typename iterator_traits<_ForwardIterator>::value_type VALUE_TYPE;
    // 从值类型中萃取出是否有平凡析构
    typedef typename __type_traits<VALUE_TYPE>::has_trivial_destructor HAS_TRIVIAL_DESTRUCTOR;
    _destroy_aux(first_, last_, HAS_TRIVIAL_DESTRUCTOR());
}

template <>
void _Destroy(unsigned*, unsigned*) {}
template <>
void _Destroy(int*, int*) {}
template <>
void _Destroy(unsigned short*, unsigned short*) {}
template <>
void _Destroy(short*, short*) {}
template <>
void _Destroy(unsigned long*, unsigned long*) {}
template <>
void _Destroy(long*, long*) {}
template <>
void _Destroy(float*, float*) {}
template <>
void _Destroy(double*, double*) {}
template <>
void _Destroy(long long*, long long*) {}
template <>
void _Destroy(long double*, long double*) {}

/* public */
template <typename _T1, typename _T2>
void construct(_T1* ptr_, const _T2& value_) {
    _Construct(ptr_, value_);
}

template <typename _T1>
void construct(_T1* ptr_) {
    _Construct(ptr_);
}

template <typename _T1>
void destroy(_T1* ptr_) {
    _Destroy(ptr_);
};

template <typename _ForwardIterator>
void destroy(_ForwardIterator first_, _ForwardIterator last_) {
    _Destroy(first_, last_);
};

_STL2022_NAMESPACE_END

/*
 * 知识点: placement new link: https://www.geeksforgeeks.org/placement-new-operator-cpp/
 */
