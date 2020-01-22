#ifndef BAR_H
#define BAR_H

#include "bar_export.h"

template <typename T>
BAR_EXPORT T bar1();

template <typename T>
BAR_EXPORT T bar2();

template <typename T>
BAR_EXPORT T bar3() { return {}; }

#ifndef bar_EXPORTS
extern template BAR_EXPORT double bar1<double>();
extern template BAR_EXPORT int bar1<int>();
extern template BAR_EXPORT char bar1<char>();
extern template BAR_EXPORT double bar2<double>();
extern template BAR_EXPORT int bar2<int>();
extern template BAR_EXPORT char bar2<char>();
extern template BAR_EXPORT double bar3<double>();
extern template BAR_EXPORT int bar3<int>();
extern template BAR_EXPORT char bar3<char>();
#endif

#endif // BAR_H
