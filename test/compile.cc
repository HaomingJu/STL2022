#include <cassert>
#include <cstdio>

#include "../stl_algobase.h"
#include "../stl_alloc.h"
#include "../stl_config.h"
#include "../stl_construct.h"
#include "../stl_iterator_base.h"
#include "../stl_uninitialized.h"
#include "../type_traits.h"

int main(int argc, char* argv[]) {
#ifdef __GNUC__
    printf("Define __GNUC__\n");  // 判断为gcc编译器
#endif

#ifndef __USLC__
    printf("Not define __USLC__\n");  // 判断为USL_C编译器
#endif

    return 0;
}
