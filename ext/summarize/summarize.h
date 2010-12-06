#ifndef RSTRING_PTR
#define RSTRING_PTR(s) (RSTRING(s)->ptr)
#endif

#ifndef RSTRING_LEN
#define RSTRING_LEN(s) (RSTRING(s)->len)
#endif

#ifndef __summarize_h__
#define __summarize_h__
static VALUE summarize(VALUE, VALUE, VALUE, VALUE, VALUE);
#endif
