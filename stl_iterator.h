#pragma once

#include "stl_config.h"         // for namespace macro
#include "stl_iterator_base.h"  // for class output_iterator;

_STL2022_NAMESPACE_HEAD

/* back_insert_iterator和front_insert_iterator均继承自iterator<output_iterator_tag, void, void, void, void> */

/* ## back_insert_iterator */
template <typename _Container>
class back_insert_iterator : public output_iterator {
  protected:
    _Container* container;

  public:
    typedef _Container container_type;

  public:
    explicit back_insert_iterator(_Container& container_) : container(&container_) {}

    back_insert_iterator<_Container>& operator=(const typename _Container::value_type& value) {
        container->push_back(value);
        return *this;
    }

    back_insert_iterator<_Container>& operator*() {
        return *this;
    }

    back_insert_iterator<_Container>& operator++() {
        return *this;
    }

    back_insert_iterator<_Container> operator++(int) {
        return *this;
    }
};

/* ## front_insert_iterator */
template <typename _Container>
class front_insert_iterator : public output_iterator {
  protected:
    _Container* container;

  public:
    typedef _Container container_type;

  public:
    explicit front_insert_iterator(_Container& container_) : container(&container_) {}

    front_insert_iterator<_Container>& operator=(const typename _Container::value_type& value) {
        container->push_front(value);
        return *this;
    }
    front_insert_iterator<_Container>& operator*() {
        return *this;
    }

    front_insert_iterator<_Container>& operator++() {
        return *this;
    }

    front_insert_iterator<_Container>& operator++(int) {
        return *this;
    }
};

_STL2022_NAMESPACE_END

