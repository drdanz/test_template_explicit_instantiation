#include "foo.h"
#include "foo-inl.h"

// Template specializations
template<> Foo<double>::Foo([[maybe_unused]] double n) {}
template<> double Foo<double>::foo1() { return {}; }
template<> int Foo<int>::foo1() { return {}; }
template<> char Foo<char>::foo1() { return {}; }

// Explicit instantiation
template class Foo<double>;
template class Foo<int>;
template class Foo<char>;
