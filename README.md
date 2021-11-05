
- [ ] 对`output_iterator_tag`的理解
- [x] 完成`stl_iterator_base.h`
- [ ] `__malloc_alloc_template`中对out-of-memory-handling的处理
- [ ] 研究__STL_USE_STD_ALLOCATORS被定义时的类继承关系


两个比较重要的萃取: 迭代器萃取(iterator_traits) | 类型萃取(__type_traits)

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

### stl_alloc.h

两种配置器: simple_alloc和malloc_alloc

```
typedef simple_alloc simple_alloc;

typedef malloc_alloc_template<0> malloc_alloc;
typedef malloc_alloc alloc;
typedef malloc_alloc single_client_alloc;
```

### type_traits.h

包含两个萃取函数`__type_traits`和`__is_integer`

对于内置类型, 则进行偏特化进行赋值. 其中表征真假的类型为`struct __true_type`和`struct __false_type`


### stl_construct.h

```
template <typename _T1, typename _T2> construct(_T1*, _T2);
template <typename _T1> construct(_T1*);
template <typename _T1> destroy(_T1*);
template <typename _ForwardIterator> destroy(_ForwardIterator first_, _ForwardIterator last_);
```

