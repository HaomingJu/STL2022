#pragma once
#include <cstddef>       // for type: size_t
#include <cstdlib>       //for func: malloc & free
#include "stl_config.h"  // for namespace macro

/*
 * 不纠结为了优化空间占用和申请效率加入的次配置器(__default_alloc_template)中复杂的逻辑
 * 先理解接口. 定义宏__USE_MALLOC, 没有次配置器
 */


_STL2022_NAMESPACE_HEAD

/* # 配置器 __malloc_alloc_template */
template <int __inst>
class __malloc_alloc_template {
  public:
    static void* allocate(size_t sz_) {
        return malloc(sz_);
    }
    static void deallocate(void* ptr_, size_t sz_ = 0) {
        free(ptr_);
    }
    // TODO: out-of-memory handling
};

/* # 配置器 simple_alloc*/
template <class _Tp, class _Alloc>
class simple_alloc {
  public:
    static _Tp* allocate(size_t sz_) {
        return sz_ <= 0 ? nullptr : (_Tp*) _Alloc::allocate(sizeof(_Tp) * sz_);
    }
    static _Tp* allocate(void) {
        return (_Tp*) _Alloc::allocate(sizeof(_Tp));
    }
    static void deallocate(_Tp* ptr_, size_t sz_) {
        _Alloc::deallocate(ptr_, sz_ * sizeof(_Tp));
    }
    static void deallocate(_Tp* ptr_) {
        _Alloc::deallocate(ptr_, sizeof(_Tp));
    }
};

typedef __malloc_alloc_template<0> malloc_alloc;
typedef malloc_alloc               alloc;
typedef malloc_alloc               single_client_alloc;

_STL2022_NAMESPACE_END

