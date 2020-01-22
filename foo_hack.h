#ifndef FOO_HACK_H
#define FOO_HACK_H

#include "foo_hack_export.h"

#define foo_EXPORTS
#include <foo.h>
#undef foo_EXPORTS

#endif // FOO_HACK_H
