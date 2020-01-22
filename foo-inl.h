#ifndef FOO_INL_H
#define FOO_INL_H

#include "foo.h"

template <typename T> Foo<T>::Foo([[maybe_unused]] T n) { }
template <typename T> T Foo<T>::foo2() { return {}; }

#endif // FOO_INL_H
