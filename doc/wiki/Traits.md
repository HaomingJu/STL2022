
<!-- vim-markdown-toc GFM -->

* [1. 综述](#1-综述)
* [2. 萃取 迭代器/指针特性](#2-萃取-迭代器指针特性)
* [3. 萃取 型别特性](#3-萃取-型别特性)
* [4. 其他](#4-其他)

<!-- vim-markdown-toc -->

# 1. 综述

`iterator_traits`负责萃取(迭代器/裸指针)特性, `__type_traits`负责萃取类型(内置类型/自定义类型)特性.

# 2. 萃取 迭代器/指针特性

萃取器可以萃取 五种迭代器/非const裸指针/const裸指针 的特性

特性包括`iterator_category` `value_type` `difference_type` `pointer_type` `reference_type`


# 3. 萃取 型别特性

特性包括`has_trivial_default_constructor` `has_trivial_copy_constructor` `has_trivial_assignment_operator` `has_trivial_destructor` `is_POD_type`

对于内置类型, 则进行偏特化进行赋值, 其特性均为`__true_type`

包含两个萃取函数`__type_traits`和`__is_integer`


# 4. 其他
在`stl_algobase.h`文件中, `copy`和`copy_backward`‵函数中先对型别进行萃取`has_trivial_assignment_operator`, 然后对迭代器萃取出类型.
