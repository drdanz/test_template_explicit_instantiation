#include <foo.h>

#ifdef HAVE_FOO_EXTEND
#include <foo_extend.h>
#endif

int main()
{
    Foo<double> fd(0.1);
    fd.foo1();
    fd.foo2();
    fd.foo3();

#ifdef HAVE_FOO_EXTEND
    Foo<long int> fli(1);
    fli.foo1();
    fli.foo2();
    fli.foo3();
#endif

    Foo<int> fi(1);
    fi.foo1();
    fi.foo2();
    fi.foo3();

    return 0;
}
