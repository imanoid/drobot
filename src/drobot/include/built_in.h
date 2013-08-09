#ifndef _BUILT_IN_H
#define _BUILT_IN_H

#ifndef array_size
# define array_size(x)	(sizeof(x) / sizeof((x)[0]))
#endif

#ifndef bug_on
# define bug_on(x)	(assert(!(x)))
#endif

#endif /* _BUILT_IN_H */
