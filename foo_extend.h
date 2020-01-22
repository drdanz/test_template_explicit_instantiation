#ifndef FOO_EXTEND_H
#define FOO_EXTEND_H

#include "foo_extend_export.h"

#include <foo.h>

#ifndef foo_extend_EXPORTS
extern template class FOO_EXTEND_EXPORT Foo<long int>;
#endif

#endif // FOO_EXTEND_H
