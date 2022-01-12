
<!-- vim-markdown-toc GFM -->

* [__STL_FUNCTION_TMPL_PARTIAL_ORDER](#stl_function_tmpl_partial_order)
* [__USLC__](#uslc)

<!-- vim-markdown-toc -->

### __STL_FUNCTION_TMPL_PARTIAL_ORDER

Partial ordering of function templates(函数模板部分排序), [参考](https://docs.microsoft.com/en-us/cpp/cpp/partial-ordering-of-function-templates-cpp?redirectedfrom=MSDN&view=msvc-170) **即对模板选择的更加准确化, 也可以理解为模板函数的重载**

```
template <typename T>
void func(T t) {
    printf("void func(T t)\n");
}

template <typename T>
void func(T* t) {
    printf("void func(T* t)\n");
}

template <typename T>
void func(const T* t) {
    printf("void func(const T* t)\n");
}

int i = 1;
const int j = 2;
int* pi = &i;
const int* cpi = &j;

func(i);        // call func(T t);
func(pi);       // call func(T* t);
func(cpi);      // call func(const T* t);

```


### __USLC__

使用编译器USL_C时, 编译器内置该宏 [参考](http://beefchunk.com/documentation/lang/c/pre-defined-c/precomp.html)
