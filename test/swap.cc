#include <cassert>

#include "../stl_algobase.h"

int main(int argc, const char* argv[]) {
    int i = 1;
    int j = 2;

    STL_NS::swap(i, j);

    assert(i == 2);
    assert(j == 1);

    return 0;
}
