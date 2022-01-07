#include <cassert>
#include <cstdio>

#include "../stl_algobase.h"

void init(int* data, int sz) {
    for(int i = 0; i < sz; ++i) {
        data[i] = i;
    }
}

void show(int* data, int sz) {
    for(int i = 0; i < sz; ++i) {
        printf("%d\t", data[i]);
    }
    printf("\n");

}

int main(int argc, const char* argv[]) {
    int data[10];

    // 测试裸指针
    init(data, 10);
    STL_NS::copy(&(data[0]), &(data[3]), &(data[5]));
    assert(data[0] == 0);
    assert(data[1] == 1);
    assert(data[2] == 2);
    assert(data[3] == 3);
    assert(data[4] == 4);
    assert(data[5] == 0);
    assert(data[6] == 1);
    assert(data[7] == 2);
    assert(data[8] == 8);
    assert(data[9] == 9);

    /* 该测试用例通过必须要有 template <typename T> inline T* __copy_aux2(T* first_, T* last_, T* result_, __true_type) */
    init(data, 10);
    STL_NS::copy(&(data[0]), &(data[6]), &(data[3]));
    assert(data[0] == 0);
    assert(data[1] == 1);
    assert(data[2] == 2);
    assert(data[3] == 0);
    assert(data[4] == 1);
    assert(data[5] == 2);
    assert(data[6] == 3);
    assert(data[7] == 4);
    assert(data[8] == 5);
    assert(data[9] == 9);


    //TODO: 测试迭代器
    return 0;
}
