#include "stl_alloc.h"
#include "stl_config.h"
#include "stl_construct.h"
#include "stl_iterator_base.h"
#include "type_traits.h"
#include "stl_uninitialized.h"

int main(int argc, char* argv[]) {

    int intArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    STL2022::_Destroy(&(intArray[0]), &(intArray[9]));

    return 0;
}
