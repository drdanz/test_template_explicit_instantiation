#ifndef FOO_H
#define FOO_H

#include "foo_export.h"

template <typename T>
class FOO_EXPORT Foo
{
public:
    Foo() = delete;
    Foo(T n);

    T foo1();
    T foo2();
    T foo3() { return {}; }

private:
    T n;
};

#ifndef foo_EXPORTS
extern template class FOO_EXPORT Foo<double>;
extern template class FOO_EXPORT Foo<int>;
extern template class FOO_EXPORT Foo<char>;
#endif

#endif // FOO_H
