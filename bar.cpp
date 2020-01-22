#include "bar.h"

template<> double bar1() { return {}; }
template<> int bar1() { return {}; }
template<> char bar1() { return {}; }

#include "bar-inl.h"


// Explicit instantiation

// template double bar1<double>();
// template int bar1<int>();
// template char bar1<char>();
template double bar2<double>();
template int bar2<int>();
template char bar2<char>();
template double bar3<double>();
template int bar3<int>();
template char bar3<char>();
