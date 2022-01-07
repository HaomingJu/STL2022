#include <cassert>

#include "../stl_algobase.h"

int main(int argc, const char* argv[]) {
    int i = 1;
    int j = 2;

    STL_NS::iter_swap(&i, &j);

    assert(i == 2);
    assert(j == 1);

    // TODO: 需要完成迭代器类
    return 0;
}
