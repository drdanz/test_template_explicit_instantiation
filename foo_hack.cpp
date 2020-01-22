#include "foo_hack.h"

#define foo_EXPORTS
#include <foo-inl.h>
#undef foo_EXPORTS

#include <iostream>

// Template specializations
template<> FOO_HACK_EXPORT long int Foo<long int>::foo1() { std::cout << "HACKED\n"; return {}; }

// Explicit instantiation
template class Foo<int>;
