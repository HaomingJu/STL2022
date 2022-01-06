#include <cassert>

#include "stl_algobase.h"
#include "stl_alloc.h"
#include "stl_config.h"
#include "stl_construct.h"
#include "stl_iterator_base.h"
#include "stl_uninitialized.h"
#include "type_traits.h"

int main(int argc, char* argv[]) {
    int intArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    STL2022::_Destroy(&(intArray[0]), &(intArray[9]));

    int intArray2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    STL2022::iter_swap(&(intArray2[0]), &(intArray2[1]));
    assert(intArray2[0] == 2);
    assert(intArray2[1] == 1);

    assert(STL2022::min(1, 2) == 1);
    assert(STL2022::max(1, 2) == 2);


    // TODO: gtest + mock

    return 0;
}
