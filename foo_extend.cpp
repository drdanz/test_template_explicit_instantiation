#include "foo_extend.h"

#include "foo-inl.h"

#include <iostream>

// Template specializations
template<> long int Foo<long int>::foo2() { std::cout << "Hello from extension library!\n"; return {}; }

// Explicit instantiation
template class Foo<long int>;
