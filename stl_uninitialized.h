#include <cstddef>
#include "stl_algobase.h"       // for func: copy
#include "stl_config.h"         // for cfg
#include "stl_construct.h"      // for func: construct, destroy
#include "stl_iterator_base.h"  // for func:__VALUE_TYPE
#include "type_traits.h"        // for type: __true_type　__false_type

_STL2022_NAMESPACE_HEAD

/* ## uninitialized_copy */
/* 有个地方需要说明一下, result_为首的内存块要调用者来提供, 该函数内不对内存进行申请操作 */
template <typename _InputIter, typename _ForwardIter>
_ForwardIter __uninitialized_copy_aux(_InputIter first_, _InputIter last_, _ForwardIter result_, __false_type) {
    _ForwardIter indexIter = result_;
    for(; first_ != last_; ++first_, ++indexIter) {
        construct(&*indexIter, *first_);  // 仅放置对象, 不做内存申请
    }
    return indexIter;
}

template <typename _InputIter, typename _ForwardIter>
_ForwardIter __uninitialized_copy_aux(_InputIter first_, _InputIter last_, _ForwardIter result_, __true_type) {
    _ForwardIter indexIter = result_;
    // TODO: Use copy from stl_algobase
    return indexIter;
}

template <typename _InputIter, typename _ForwardIter, typename EleType>
_ForwardIter __uninitialized_copy(_InputIter first_, _InputIter last_, _ForwardIter result_, EleType) {
    typedef typename __type_traits<EleType>::is_POD_type isPOD;
    return uninitialized_copy_aux(first_, last_, result_, isPOD());
}

template <typename _InputIter, typename _ForwardIter>
_ForwardIter uninitialized_copy(_InputIter first_, _InputIter last_, _ForwardIter result_) {
    return __uninitialized_copy(first_, last_, result_, __VALUE_TYPE(result_));
}

/* ## uninitialized_fill */
/* 同样的, fill系列函数内部不做内存申请, 只做fill填充*/
template <typename _ForwardIter, typename _T>
void __uninitialized_fill_aux(_ForwardIter first_, _ForwardIter last_, const _T& value_, __false_type) {
    for(; first_ != last_; ++first_) {
        construct(&*first_, value_);
    }
}

template <typename _ForwardIter, typename _T>
void __uninitialized_fill_aux(_ForwardIter first_, _ForwardIter last_, const _T& value_, __true_type) {
    // TODO: Use fill from stl_algobase
}

template <typename _ForwardIter, typename _T, typename EleType>
void __uninitialized_fill(_ForwardIter first_, _ForwardIter last_, const _T& value_, EleType) {
    typedef typename __type_traits<EleType>::is_POD_type isPOD;
    __uninitialized_fill_aux(first_, last_, value_, isPOD());
}

template <typename _ForwardIter, typename _T>
void uninitialized_fill(_ForwardIter first_, _ForwardIter last_, const _T& value_) {
    __uninitialized_fill(first_, last_, value_, __VALUE_TYPE(first_));
}

/* ## uninitialized_copy_n */
/* 其实就是uninitialized_copy的重载 */
template <typename _InputIter, typename _ForwardIter>
void __uninitialized_copy_n(_InputIter first_, std::size_t count_, _ForwardIter last_, input_iterator_tag) {
    _ForwardIter indexIter = last_;
    try {
        for(; count_ > 0; --count_, ++first_, ++indexIter) {
            construct(&*indexIter, *first_);
        }
    } catch(...) {
        destroy(last_, indexIter);
    }
}

template <typename _RandomIter, typename _ForwardIter>
void __uninitialized_copy_n(_RandomIter first_, std::size_t count_, _ForwardIter result_, random_iterator_tag) {
    _RandomIter last_ = first_ + count_;
    uninitialized_copy(first_, last_, result_);
}

template <typename _InputIter, typename _ForwardIter>
void uninitialized_copy_n(_InputIter first_, std::size_t count_, _ForwardIter result_) {
    //typedef typename iterator_traits<_InputIter>::iterator_category iterCategory;
    __uninitialized_copy_n(first_, count_, result_, __ITERATOR_CATEGORY(first_));
}

/* ## uninitialized_fill_n */
/* 其实就是uninitialized_fill的重载 */

template <typename _InputIter, typename _ForwardIter, typename _T>
void __uninitialized_fill_n(_InputIter first_, std::size_t count_, const _T& value_, input_iterator_tag) {
    _InputIter indexIter = first_;
    try {
        for(; count_ > 0; --count_, ++indexIter) {
            construct(&*indexIter, value_);
        }

    } catch(...) {
        destroy(first_, indexIter);
    }
}

template <typename _RandomIter, typename _ForwardIter, typename _T>
void __uninitialized_fill_n(_RandomIter first_, std::size_t count_, const _T& value_, random_iterator_tag) {
    _RandomIter last_ = first_ + count_;
    uninitialized_fill(first_, last_, value_);
}

template <typename _InputIter, typename _T>
void uninitialized_fill_n(_InputIter first_, std::size_t count_, const _T& value_) {
    //typedef typename iterator_traits<_InputIter>::iterator_category iterCategory;
    __uninitialized_fill_n(first_, count_, value_, __ITERATOR_CATEGORY(first_));
}

_STL2022_NAMESPACE_END

/*
 * Export func: 
 * uninitialized_copy(_InputIter first_, _InputIter last_, _ForwardIter result_);
 * uninitialized_fill(_ForwardIter first_, _ForwardIter last_, T value_);
 */
