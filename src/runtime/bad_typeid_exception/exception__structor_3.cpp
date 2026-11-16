/* compiler: ee-gcc2.96-exceptions */
/* gcc-exception gcc snapshot 2000-10-03 (old C++ ABI): __throw_bad_typeid() (exception__structor_3) and std::uncaught_exception() from exception.cc, in the context of
 * exception.cc as staged by tools/libmatch.py. Third-party code, see THIRD_PARTY.md for its license and origin.
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
#define L_op_new
#define L_op_vnew
// Functions for Exception Support for -*- C++ -*-
// Copyright (C) 1994, 1995, 1996, 1997, 1998, 1999, 2000 Free Software Foundation

// This file is part of GNU CC.

// GNU CC is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2, or (at your option)
// any later version.

// GNU CC is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with GNU CC; see the file COPYING.  If not, write to
// the Free Software Foundation, 59 Temple Place - Suite 330,
// Boston, MA 02111-1307, USA.

// As a special exception, you may use this file as part of a free software
// library without restriction.  Specifically, if other files instantiate
// templates or use macros or inline functions from this file, or you compile
// this file and link it with other files to produce an executable, this
// file does not by itself cause the resulting executable to be covered by
// the GNU General Public License.  This exception does not however
// invalidate any other reasons why the executable file might be covered by
// the GNU General Public License.

// RTTI support for -*- C++ -*-
// Copyright (C) 1994, 1995, 1996, 1997, 1998, 2000 Free Software Foundation

// This file is part of GNU CC.
//
// GNU CC is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2, or (at your option)
// any later version.
//
// GNU CC is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with GNU CC; see the file COPYING.  If not, write to
// the Free Software Foundation, 59 Temple Place - Suite 330,
// Boston, MA 02111-1307, USA.

// As a special exception, you may use this file as part of a free software
// library without restriction.  Specifically, if other files instantiate
// templates or use macros or inline functions from this file, or you compile
// this file and link it with other files to produce an executable, this
// file does not by itself cause the resulting executable to be covered by
// the GNU General Public License.  This exception does not however
// invalidate any other reasons why the executable file might be covered by
// the GNU General Public License.

// __GXX_ABI_VERSION distinguishes the ABI that is being used. Values <100
// indicate the `old' abi, which grew as C++ was defined. Values >=100
// indicate the `new' abi, which is a cross vendor C++ abi, documented at
// `http://reality.sgi.com/dehnert_engr/cxx/'.

#ifndef __TYPEINFO__
#define __TYPEINFO__

#pragma interface "typeinfo"

// Exception Handling support header for -*- C++ -*-
// Copyright (C) 1995, 1996, 1997, 1998, 2000 Free Software Foundation

// This file is part of GNU CC.
//
// GNU CC is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2, or (at your option)
// any later version.
//
// GNU CC is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with GNU CC; see the file COPYING.  If not, write to
// the Free Software Foundation, 59 Temple Place - Suite 330,
// Boston, MA 02111-1307, USA.

// As a special exception, you may use this file as part of a free software
// library without restriction.  Specifically, if other files instantiate
// templates or use macros or inline functions from this file, or you compile
// this file and link it with other files to produce an executable, this
// file does not by itself cause the resulting executable to be covered by
// the GNU General Public License.  This exception does not however
// invalidate any other reasons why the executable file might be covered by
// the GNU General Public License.

#ifndef __EXCEPTION__
#define __EXCEPTION__

#pragma interface "exception"

extern "C++" {

namespace std {

class exception {
public:
  exception () { }
  virtual ~exception () { }
  virtual const char* what () const;
};

class bad_exception : public exception {
public:
  bad_exception () { }
  virtual ~bad_exception () { }
};

typedef void (*terminate_handler) ();
typedef void (*unexpected_handler) ();

terminate_handler set_terminate (terminate_handler);
void terminate () __attribute__ ((__noreturn__));
unexpected_handler set_unexpected (unexpected_handler);
void unexpected () __attribute__ ((__noreturn__));
bool uncaught_exception ();

}

}

#endif

extern "C++" {

#if defined(__GXX_ABI_VERSION) && __GXX_ABI_VERSION >= 100
namespace __cxxabiv1
{
  class __class_type_info;
}
#endif

namespace std {

class type_info {
public:

  virtual ~type_info ();

private:

  type_info& operator= (const type_info&);
  type_info (const type_info&);

protected:
  const char *__name;

protected:
  explicit type_info (const char *__n): __name (__n) { }

public:

#if !defined(__GXX_ABI_VERSION) || __GXX_ABI_VERSION < 100

  bool before (const type_info& arg) const;
  const char* name () const
    { return __name; }
  bool operator== (const type_info& __arg) const;
  bool operator!= (const type_info& __arg) const
    { return !operator== (__arg); }

#else

  bool before (const type_info& __arg) const
    { return __name < __arg.__name; }
  const char* name () const
    { return __name; }
  bool operator== (const type_info& __arg) const
    { return __name == __arg.__name; }
  bool operator!= (const type_info& __arg) const
    { return !operator== (__arg); }
#endif

#if defined(__GXX_ABI_VERSION) && __GXX_ABI_VERSION >= 100
public:

  virtual bool __is_pointer_p () const;

  virtual bool __is_function_p () const;

  virtual bool __do_catch (const type_info *__thr_type, void **__thr_obj,
                         unsigned __outer) const;

  virtual bool __do_upcast (const __cxxabiv1::__class_type_info *__target,
			    void **__obj_ptr) const;
#endif
};

class bad_cast : public exception {
public:
  bad_cast() { }
  virtual ~bad_cast() { }
};

class bad_typeid : public exception {
 public:
  bad_typeid () { }
  virtual ~bad_typeid () { }
};

}

}
#endif

#ifndef GT4_RUNTIME_STDDEF
#define GT4_RUNTIME_STDDEF
typedef unsigned int size_t;
typedef int ptrdiff_t;
#define NULL 0
#endif

/* ANSI and traditional C compatibility macros.
   Copyright (C) 1996, 1997, 1998, 1999 Free Software Foundation, Inc.

This file is part of GNU CC.

GNU CC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GNU CC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU CC; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

#ifndef	__GANSIDECL_H__
#define	__GANSIDECL_H__

/* ANSI and traditional C compatability macros
   Copyright 1991, 1992, 1996, 1999 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */

#ifndef	_ANSIDECL_H

#define	_ANSIDECL_H	1

#if defined (__STDC__) || defined (_AIX) || (defined (__mips) && defined (_SYSTYPE_SVR4)) || defined(_WIN32)

#define	PTR		void *
#define	PTRCONST	void *CONST
#define	LONG_DOUBLE	long double

#ifndef IN_GCC
#define	AND		,
#define	NOARGS		void
#define	VOLATILE	volatile
#define	SIGNED		signed
#endif

#define PARAMS(paramlist)		paramlist
#define ANSI_PROTOTYPES			1

#define VPARAMS(ARGS)			ARGS
#define VA_START(va_list,var)		va_start(va_list,var)

#ifndef IN_GCC
#define CONST				const
#define DOTS				, ...
#define PROTO(type, name, arglist)	type name arglist
#define EXFUN(name, proto)		name proto
#define DEFUN(name, arglist, args)	name(args)
#define DEFUN_VOID(name)		name(void)
#endif

#else

#define	PTR		char *
#define	PTRCONST	PTR
#define	LONG_DOUBLE	double

#ifndef IN_GCC
#define	AND		;
#define	NOARGS
#define	VOLATILE
#define	SIGNED
#endif

#ifndef const
#define	const
#endif

#define PARAMS(paramlist)		()

#define VPARAMS(ARGS)			(va_alist) va_dcl
#define VA_START(va_list,var)		va_start(va_list)

#ifndef IN_GCC
#define CONST
#define DOTS
#define PROTO(type, name, arglist)	type name ()
#define EXFUN(name, proto)		name()
#define DEFUN(name, arglist, args)	name arglist args;
#define DEFUN_VOID(name)		name()
#endif

#endif

#ifndef GCC_VERSION
#define GCC_VERSION (__GNUC__ * 1000 + __GNUC_MINOR__)
#endif

#if (GCC_VERSION < 2007)
# define __attribute__(x)
#endif

#ifndef ATTRIBUTE_MALLOC
# if (GCC_VERSION >= 2096)
#  define ATTRIBUTE_MALLOC __attribute__ ((__malloc__))
# else
#  define ATTRIBUTE_MALLOC
# endif
#endif

#ifndef ATTRIBUTE_UNUSED_LABEL
# if (GCC_VERSION >= 2093)
#  define ATTRIBUTE_UNUSED_LABEL ATTRIBUTE_UNUSED
# else
#  define ATTRIBUTE_UNUSED_LABEL
# endif
#endif

#ifndef ATTRIBUTE_UNUSED
#define ATTRIBUTE_UNUSED __attribute__ ((__unused__))
#endif

#ifndef ATTRIBUTE_NORETURN
#define ATTRIBUTE_NORETURN __attribute__ ((__noreturn__))
#endif

#ifndef ATTRIBUTE_PRINTF
#define ATTRIBUTE_PRINTF(m, n) __attribute__ ((__format__ (__printf__, m, n)))
#define ATTRIBUTE_PRINTF_1 ATTRIBUTE_PRINTF(1, 2)
#define ATTRIBUTE_PRINTF_2 ATTRIBUTE_PRINTF(2, 3)
#define ATTRIBUTE_PRINTF_3 ATTRIBUTE_PRINTF(3, 4)
#define ATTRIBUTE_PRINTF_4 ATTRIBUTE_PRINTF(4, 5)
#define ATTRIBUTE_PRINTF_5 ATTRIBUTE_PRINTF(5, 6)
#endif

#if GCC_VERSION < 2008
#define __extension__
#endif

#endif

#if (GCC_VERSION >= 2007)
# undef const
# undef inline
# define inline __inline__
# ifndef HAVE_LONG_DOUBLE
#  define HAVE_LONG_DOUBLE 1
# endif

# if !defined (HAVE_STRINGIZE) && __STDC__
#  define HAVE_STRINGIZE 1
# endif
#endif

#ifndef NULL_PTR
#define NULL_PTR ((PTR) 0)
#endif

#endif

/* EH stuff
   Copyright (C) 1997, 1998, 1999, 2000 Free Software Foundation, Inc.

This file is part of GNU CC.

This program is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation; either version 2, or (at your option) any
later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */

#ifndef EH_ALLOC_SIZE

#define EH_ALLOC_SIZE 192
#endif
#ifndef EH_ALLOC_ALIGN

#define EH_ALLOC_ALIGN 16
#endif

struct eh_context
{
  void *handler_label;
  void **dynamic_handler_chain;

  void *info;

  void *table_index;

  char alloc_buffer[EH_ALLOC_SIZE]
      __attribute__((__aligned__(EH_ALLOC_ALIGN)));
  unsigned alloc_mask;
};

#ifndef EH_TABLE_LOOKUP

typedef struct old_exception_table
{
  void *start_region;
  void *end_region;
  void *exception_handler;
} old_exception_table;

typedef struct exception_table
{
  void *start_region;
  void *end_region;
  void *exception_handler;
  void *match_info;
} exception_table;

typedef struct exception_lang_info
{
  short language;
  short version;
} exception_lang_info;

#define NEW_EH_RUNTIME  ((void *) -2)

typedef struct exception_descriptor
{
  void *runtime_id_field;
  exception_lang_info lang;
  exception_table table[1];
} exception_descriptor;

struct __eh_info;

typedef void * (*__eh_matcher)	PARAMS ((struct __eh_info *, void *,
					 struct exception_descriptor *));

#define CATCH_ALL_TYPE   ((void *) -1)

typedef struct __eh_info
{
  __eh_matcher match_function;
  short language;
  short version;
} __eh_info;

enum exception_source_language
  {
    EH_LANG_C89 = 0x0001,
    EH_LANG_C = 0x0002,
    EH_LANG_Ada83 = 0x0003,
    EH_LANG_C_plus_plus = 0x0004,
    EH_LANG_Cobol74 = 0x0005,
    EH_LANG_Cobol85 = 0x0006,
    EH_LANG_Fortran77 = 0x0007,
    EH_LANG_Fortran90 = 0x0008,
    EH_LANG_Pascal83 = 0x0009,
    EH_LANG_Modula2 = 0x000a,
    EH_LANG_Java = 0x000b,
    EH_LANG_Mips_Assembler = 0x8001
  };

#endif

extern std::terminate_handler __terminate_func __attribute__((__noreturn__));
using std::terminate;

void
__default_unexpected ();

extern std::unexpected_handler __unexpected_func __attribute__((__noreturn__));

#if !defined (__GXX_ABI_VERSION) || __GXX_ABI_VERSION < 100
typedef void (*cleanup_fn)(void *, int);

#define CALL_CLEANUP(FN, THIS) FN (THIS, 2)
#else
typedef void (*cleanup_fn)(void *);
#define CALL_CLEANUP(FN, THIS) FN (THIS)
#endif

struct cp_eh_info
{
  __eh_info eh_info;
  void *value;
  void *type;
  cleanup_fn cleanup;
  bool caught;
  cp_eh_info *next;
  long handlers;
  void *original_value;
};

extern "C" cp_eh_info **__get_eh_info ();

extern "C" void *__eh_alloc(size_t);
extern "C" void __eh_free(void *);

extern bool __is_pointer (void *);

extern "C" void *
__cp_exception_info (void);

#define CP_EH_INFO ((cp_eh_info *) *__get_eh_info ())

extern "C" cp_eh_info *
__cp_eh_info (void);

extern "C" cp_eh_info *
__start_cp_handler (void);

extern "C" int __throw_type_match_rtti_2 (const void *, const void *,
					 void *, void **);

extern "C" void *
__cplus_type_matcher (__eh_info *info_, void *match_info,
		      exception_descriptor *exception_table);

extern "C" void
__cp_push_exception (void *value, void *type, cleanup_fn cleanup);

extern "C" void
__cp_pop_exception (cp_eh_info *p);

extern "C" void
__uncatch_exception (void);

extern "C" void
__check_eh_spec (int n, const void **spec);

extern "C" void
__check_null_eh_spec (void);

extern "C" void *
exception__structor_3 ()

{
  throw std::bad_typeid ();
  return 0;
}

/* Has an exception been thrown and not caught?  */

bool
std::uncaught_exception ()
{
  cp_eh_info *p = CP_EH_INFO;
  return p && ! p->caught;
}
