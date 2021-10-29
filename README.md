
- [ ] 对output_iterator_tag的理解
- [ ] 完成stl_iterator_base.h



### stl_iterator_base.h

```
# 五种迭代器类别类
struct input_iterator_tag;
struct forward_iterator_tag : public input_iterator_tag;
struct bidirectional_iterator_tag : public forward_iterator_tag;
struct random_iterator_tag : public bidirectional_iterator_tag
struct output_iterator_tag;


# 基础迭代器模板衍生出: 5中偏特化迭代器模板
template <...> class iterator;
template <...> class input_iterator;
template <...> class forward_iterator;
template <...> class bidirectional_iterator;
template <...> class random_iterator;
template <...> class output_iterator;

# 迭代器萃取器, 萃取出几种特性
template <...> class iterator_traits;

template <typename _Iter> iterator_traits::iterator_category;
template <typename _Iter> iterator_traits::value_type;
template <typename _Iter> iterator_traits::difference_type;
template <typename _Iter> iterator_traits::pointer_type;
template <typename _Iter> iterator_traits::reference_type;

# 函数advance(自增)和distance(距离)
template <typename _Iter> typename iterator_traits<_Iter>::difference_type \
    distance(_Iter first_, _Iter last_);

template <typename _Iter> void advance(_Iter iter_);

```
