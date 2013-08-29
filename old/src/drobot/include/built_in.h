#ifndef _BUILT_IN_H
#define _BUILT_IN_H

#include <assert.h>

#ifndef array_size
# define array_size(x)		(sizeof(x) / sizeof((x)[0]))
#endif

#ifndef bug_on
# define bug_on(x)		(assert(!(x)))
#endif

#ifndef build_bug_on
# define build_bug_on(e)	((void)sizeof(char[1 - 2*!!(e)]))
#endif

#endif /* _BUILT_IN_H */
