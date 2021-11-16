#include "stl_algobase.h"       // for func: copy
#include "stl_config.h"         // for cfg
#include "stl_construct.h"      // for func: construct, destroy
#include "stl_iterator_base.h"  // for func:__VALUE_TYPE
#include "type_traits.h"        // for type: __true_type　__false_type

_STL2022_NAMESPACE_HEAD

/* ## 非初始化拷贝 uninitialized_copy */
template <typename _InputIter, typename _ForwardIter>
_ForwardIter __uninitialized_copy_aux(_InputIter first_, _InputIter last_, _ForwardIter result_, __false_type) {
    _ForwardIter indexIter = result_;
    for(; first_ != last_; ++first_, ++indexIter) {
        construct(&*indexIter, *first_);
    }
}

template <typename _InputIter, typename _ForwardIter>
_ForwardIter __uninitialized_copy_aux(_InputIter first_, _InputIter last_, _ForwardIter result, __true_type) {
    // TODO: Use copy from stl_algobase
}

template <typename _InputIter, typename _ForwardIter, typename EleType>
_ForwardIter __uninitialized_copy(_InputIter first_, _InputIter last_, _ForwardIter result_, EleType) {
    typedef typename __type_traits<EleType>::is_POD_type isPOD;
    uninitialized_copy_aux(first_, last_, result_, isPOD());
}

template <typename _InputIter, typename _ForwardIter>
_ForwardIter uninitialized_copy(_InputIter first_, _InputIter last_, _ForwardIter result_) {
    __uninitialized_copy(first_, last_, result_, __VALUE_TYPE(result_));
}

/* ## 非初始化填充 uninitialized_fill */
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

_STL2022_NAMESPACE_END

/*
 * Export func: 
 * uninitialized_copy(_InputIter first_, _InputIter last_, _ForwardIter result_);
 * uninitialized_fill(_ForwardIter first_, _ForwardIter last_, T value_);
 */
