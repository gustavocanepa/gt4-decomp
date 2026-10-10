/* newlib 1.9.0: vsnprintf_r from vsnprintf.c, placed at 0x005aaac8 by
 * tools/libmatch.py. Third-party code, see THIRD_PARTY.md for its license and origin. */
#define _Balloc func_005AC4D8
#define _Bfree func_005AC580
#define __assert func_005A2E98
#define __errno func_0056FFC0
#define __mcmp func_005ACDC8
#define __mdiff func_005ACE30
#define __mprec_bigtens D_006D22E8
#define __mprec_tens D_006D2220
#define __mprec_tinytens D_006D2310
#define __muldi3 D_005BA060
#define __sccl func_005AA958
#define __sclose func_005A5CD0
#define __sflags func_005AC2A0
#define __sfmoreglue func_005A34B8
#define __sfp func_005A3530
#define __sfvwrite func_005A3FC8
#define __sinit func_005A3668
#define __smakebuf func_005A44F0
#define __sprint func_005A74D0
#define __sread func_005A5B80
#define __srefill func_005A56A0
#define __srget func_005A5820
#define __sseek func_005A5C68
#define __submore func_005AD5D8
#define __swbuf func_005AAB30
#define __swrite func_005A5BE8
#define __swsetup func_005AACA0
#define __udivdi3 D_005BAE00
#define __umoddi3 D_005BB380
#define _b2d func_005AD090
#define _close_r func_005AADB0
#define _ctype_ D_006D0E78
#define _d2b func_005AD228
#define _exit D_00100220
#define _fwalk func_005A43A8
#define _getpid D_005A5EF4
#define _getpid_r func_005A44C8
#define _hi0bits func_005AC7E8
#define _i2b func_005AC928
#define _impure_ptr D_00658288
#define _lo0bits func_005AC868
#define _lseek_r func_005AC440
#define _lshift func_005ACC70
#define _malloc_r D_00575FB0
#define _mbtowc_r func_005AC4A0
#define _mprec_log10 func_005AD480
#define _multadd func_005AC5B0
#define _multiply func_005AC960
#define _pow5mult func_005ACB70
#define _puts_r func_005A4B50
#define _read_r func_005AD4F0
#define _realloc_r D_00575FC8
#define _s2b func_005AC6B8
#define _setlocale_r func_005AC358
#define _snprintf_r func_005A5998
#define _strtoul_r func_005A71A0
#define _times D_00575DA0
#define _user_strerror func_00559AD8
#define abort func_005A2E68
#define abs func_005A2E80
#define asctime func_00578660
#define atoi func_005A2F88
#define atol func_005A2FB0
#define bcopy func_005A2FE8
#define bsearch func_005A3008
#define bzero func_005A30D8
#define copysign func_005A26C8
#define ctime func_00578B30
#define dpmul D_0057F8B8
#define dptofp D_00577AF0
#define eofread func_005A5AD0
#define errno D_006D62F8
#define exit func_005A3140
#define fabsf func_005A2E20
#define fclose func_005A31F0
#define fflush func_005A32F0
#define fileno func_005A3408
#define finite func_005A2E48
#define fputs func_005A3948
#define fread func_005A3998
#define fseek func_005A3AB8
#define fwrite func_005A4440
#define isinf func_005AD550
#define isnan func_005AD598
#define labs func_005A44E0
#define lconv D_006D21C8
#define lflush func_005A5668
#define localtime func_005ADB90
#define memchr func_005A4644
#define memcpy func_005A4724
#define memmove func_005A47D4
#define memset func_005A48D8
#define puts func_005A4BD8
#define qsort func_005A4BF8
#define raise func_00575C68
#define setlocale func_005AC3F8
#define snprintf func_005A5A30
#define srand func_005A55E8
#define sscanf func_005A5AD8
#define std func_005A3458
#define strcasecmp func_005A5CF0
#define strcspn func_005A61B0
#define strerror func_005A62C0
#define strlen func_0057F260
#define strlwr func_005A67D8
#define strncasecmp func_005A6828
#define strpbrk func_005A6C70
#define strspn func_005A6D48
#define strstr func_005A6DC8
#define strtok func_005A6E50
#define strtok_r func_005A6E70
#define strtoul func_005A73D0
#define strupr func_005A7400
#define strxfrm func_005A7450
#define ungetc func_005AD6C0
#define vfprintf func_005A8340
#define vsnprintf func_005AAA58
#define vsnprintf_r func_005AAAC8
/* doc in vfprintf.c */

#if defined(LIBC_SCCS) && !defined(lint)
static char sccsid[] = "%W% (Berkeley) %G%";
#endif 

/* Provide support for both ANSI and non-ANSI environments.  */

#ifndef	_ANSIDECL_H_
#define	_ANSIDECL_H_

#ifndef __SYS_CONFIG_H__
#define __SYS_CONFIG_H__

/* exceptions first */

#if defined(__H8300__) || defined(__H8500__) || defined (__H8300H__) ||  defined(__W65__) || defined (__H8300S__)
#define _FLOAT_ARG float
#define __SMALL_BITFIELDS
#define _DOUBLE_IS_32BITS
#define __IEEE_BIG_ENDIAN

#define H8300 1
#endif

#ifdef __W65__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_BIG_ENDIAN
#undef INT_MAX
#undef UINT_MAX
#define INT_MAX 32767
#define UINT_MAX 65535

#endif

#if defined(__Z8001__) || defined(__Z8002__) || defined(__H8300__) || defined(__H8500__) || defined(__W65__) || defined (__H8300H__) || defined (__H8300S__) || defined (__mn10200__) || defined (__AVR__)

#undef INT_MAX
#undef UINT_MAX
#define INT_MAX 32767
#define UINT_MAX 65535
#endif

#if defined(__D10V__)
#undef INT_MAX
#undef UINT_MAX
#define INT_MAX __INT_MAX__
#define UINT_MAX (__INT_MAX__ * 2U + 1)
#define _DOUBLE_IS_32BITS
#define _POINTER_INT short
#define __IEEE_BIG_ENDIAN
#endif

#ifdef ___AM29K__
#define _FLOAT_RET double
#endif

#ifdef __i386__
#ifndef __unix__

#define _FLOAT_RET double
#endif
#endif

#ifdef __M32R__
#define __IEEE_BIG_ENDIAN
#endif

#ifdef __m68k__

#define __IEEE_BIG_ENDIAN
#endif

#ifdef __mn10300__
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __mn10200__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __AVR__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_LITTLE_ENDIAN
#define _POINTER_INT short
#endif

#ifdef __TIC80__
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __v850
#define __IEEE_LITTLE_ENDIAN
#define __ATTRIBUTE_IMPURE_PTR__ __attribute__((__sda__))
#endif

#ifdef __D30V__
#define __IEEE_BIG_ENDIAN
#endif

#if defined(__PPC__) && defined(_CALL_SYSV)
#define __ATTRIBUTE_IMPURE_PTR__ __attribute__((__section__(".sdata")))
#endif

#ifdef __sparc__
#ifdef __LITTLE_ENDIAN_DATA__
#define __IEEE_LITTLE_ENDIAN
#else
#define __IEEE_BIG_ENDIAN
#endif
#endif

#if INT_MAX == 32767
typedef long int __int32_t;
typedef unsigned long int __uint32_t;
#else
typedef int __int32_t;
typedef unsigned int __uint32_t;
#endif

#ifndef _POINTER_INT
#define _POINTER_INT long
#endif

#undef __RAND_MAX
#if INT_MAX == 32767
#define __RAND_MAX 32767
#else
#define __RAND_MAX 0x7fffffff
#endif

#if defined(__CYGWIN32__) || defined(__CYGWIN__)
#if defined(__INSIDE_CYGWIN__) || defined(_COMPILING_NEWLIB)
#define __IMPORT
#else
#define __IMPORT __declspec(dllimport)
#endif
#endif

#ifndef __IMPORT
#define __IMPORT
#endif

#endif 

#ifdef __STDC__
#define _HAVE_STDC
#endif

#ifdef _HAVE_STDC
#define	_PTR		void *
#define	_AND		,
#define	_NOARGS		void
#define	_CONST		const
#define	_VOLATILE	volatile
#define	_SIGNED		signed
#define	_DOTS		, ...
#define _VOID void
#ifdef __CYGWIN__
#define	_EXFUN(name, proto)		__cdecl name proto
#define	_EXPARM(name, proto)		(* __cdecl name) proto
#else
#define	_EXFUN(name, proto)		name proto
#define _EXPARM(name, proto)		(* name) proto
#endif
#define	_DEFUN(name, arglist, args)	name(args)
#define	_DEFUN_VOID(name)		name(_NOARGS)
#define _CAST_VOID (void)
#ifndef _LONG_DOUBLE
#define _LONG_DOUBLE long double
#endif
#ifndef _PARAMS
#define _PARAMS(paramlist)		paramlist
#endif
#else	
#define	_PTR		char *
#define	_AND		;
#define	_NOARGS
#define	_CONST
#define	_VOLATILE
#define	_SIGNED
#define	_DOTS
#define _VOID void
#define	_EXFUN(name, proto)		name()
#define	_DEFUN(name, arglist, args)	name arglist args;
#define	_DEFUN_VOID(name)		name()
#define _CAST_VOID
#define _LONG_DOUBLE double
#ifndef _PARAMS
#define _PARAMS(paramlist)		()
#endif
#endif

#ifdef __GNUC__
#define _ATTRIBUTE(attrs) __attribute__ (attrs)
#else
#define _ATTRIBUTE(attrs)
#endif

#endif 

/* This header file provides the reentrancy.  */

#ifndef _REENT_H_
#ifdef __cplusplus
extern "C" {
#endif
#define _REENT_H_

/* This header file provides the reentrancy.  */

#ifndef _SYS_REENT_H_
#ifdef __cplusplus
extern "C" {
#endif
#define _SYS_REENT_H_

/* Provide support for both ANSI and non-ANSI environments.  */

#ifndef	_ANSIDECL_H_
#define	_ANSIDECL_H_

#ifndef __SYS_CONFIG_H__
#define __SYS_CONFIG_H__

/* exceptions first */

#if defined(__H8300__) || defined(__H8500__) || defined (__H8300H__) ||  defined(__W65__) || defined (__H8300S__)
#define _FLOAT_ARG float
#define __SMALL_BITFIELDS
#define _DOUBLE_IS_32BITS
#define __IEEE_BIG_ENDIAN

#define H8300 1
#endif

#ifdef __W65__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_BIG_ENDIAN
#undef INT_MAX
#undef UINT_MAX
#define INT_MAX 32767
#define UINT_MAX 65535

#endif

#if defined(__Z8001__) || defined(__Z8002__) || defined(__H8300__) || defined(__H8500__) || defined(__W65__) || defined (__H8300H__) || defined (__H8300S__) || defined (__mn10200__) || defined (__AVR__)

#undef INT_MAX
#undef UINT_MAX
#define INT_MAX 32767
#define UINT_MAX 65535
#endif

#if defined(__D10V__)
#undef INT_MAX
#undef UINT_MAX
#define INT_MAX __INT_MAX__
#define UINT_MAX (__INT_MAX__ * 2U + 1)
#define _DOUBLE_IS_32BITS
#define _POINTER_INT short
#define __IEEE_BIG_ENDIAN
#endif

#ifdef ___AM29K__
#define _FLOAT_RET double
#endif

#ifdef __i386__
#ifndef __unix__

#define _FLOAT_RET double
#endif
#endif

#ifdef __M32R__
#define __IEEE_BIG_ENDIAN
#endif

#ifdef __m68k__

#define __IEEE_BIG_ENDIAN
#endif

#ifdef __mn10300__
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __mn10200__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __AVR__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_LITTLE_ENDIAN
#define _POINTER_INT short
#endif

#ifdef __TIC80__
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __v850
#define __IEEE_LITTLE_ENDIAN
#define __ATTRIBUTE_IMPURE_PTR__ __attribute__((__sda__))
#endif

#ifdef __D30V__
#define __IEEE_BIG_ENDIAN
#endif

#if defined(__PPC__) && defined(_CALL_SYSV)
#define __ATTRIBUTE_IMPURE_PTR__ __attribute__((__section__(".sdata")))
#endif

#ifdef __sparc__
#ifdef __LITTLE_ENDIAN_DATA__
#define __IEEE_LITTLE_ENDIAN
#else
#define __IEEE_BIG_ENDIAN
#endif
#endif

#if INT_MAX == 32767
typedef long int __int32_t;
typedef unsigned long int __uint32_t;
#else
typedef int __int32_t;
typedef unsigned int __uint32_t;
#endif

#ifndef _POINTER_INT
#define _POINTER_INT long
#endif

#undef __RAND_MAX
#if INT_MAX == 32767
#define __RAND_MAX 32767
#else
#define __RAND_MAX 0x7fffffff
#endif

#if defined(__CYGWIN32__) || defined(__CYGWIN__)
#if defined(__INSIDE_CYGWIN__) || defined(_COMPILING_NEWLIB)
#define __IMPORT
#else
#define __IMPORT __declspec(dllimport)
#endif
#endif

#ifndef __IMPORT
#define __IMPORT
#endif

#endif 

#ifdef __STDC__
#define _HAVE_STDC
#endif

#ifdef _HAVE_STDC
#define	_PTR		void *
#define	_AND		,
#define	_NOARGS		void
#define	_CONST		const
#define	_VOLATILE	volatile
#define	_SIGNED		signed
#define	_DOTS		, ...
#define _VOID void
#ifdef __CYGWIN__
#define	_EXFUN(name, proto)		__cdecl name proto
#define	_EXPARM(name, proto)		(* __cdecl name) proto
#else
#define	_EXFUN(name, proto)		name proto
#define _EXPARM(name, proto)		(* name) proto
#endif
#define	_DEFUN(name, arglist, args)	name(args)
#define	_DEFUN_VOID(name)		name(_NOARGS)
#define _CAST_VOID (void)
#ifndef _LONG_DOUBLE
#define _LONG_DOUBLE long double
#endif
#ifndef _PARAMS
#define _PARAMS(paramlist)		paramlist
#endif
#else	
#define	_PTR		char *
#define	_AND		;
#define	_NOARGS
#define	_CONST
#define	_VOLATILE
#define	_SIGNED
#define	_DOTS
#define _VOID void
#define	_EXFUN(name, proto)		name()
#define	_DEFUN(name, arglist, args)	name arglist args;
#define	_DEFUN_VOID(name)		name()
#define _CAST_VOID
#define _LONG_DOUBLE double
#ifndef _PARAMS
#define _PARAMS(paramlist)		()
#endif
#endif

#ifdef __GNUC__
#define _ATTRIBUTE(attrs) __attribute__ (attrs)
#else
#define _ATTRIBUTE(attrs)
#endif

#endif 

/*
 * time.h
 * 
 * Struct and function declarations for dealing with time.
 */

#ifndef _TIME_H_
#define _TIME_H_

/* Provide support for both ANSI and non-ANSI environments.  */

#ifndef	_ANSIDECL_H_
#define	_ANSIDECL_H_

#ifndef __SYS_CONFIG_H__
#define __SYS_CONFIG_H__

/* exceptions first */

#if defined(__H8300__) || defined(__H8500__) || defined (__H8300H__) ||  defined(__W65__) || defined (__H8300S__)
#define _FLOAT_ARG float
#define __SMALL_BITFIELDS
#define _DOUBLE_IS_32BITS
#define __IEEE_BIG_ENDIAN

#define H8300 1
#endif

#ifdef __W65__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_BIG_ENDIAN
#undef INT_MAX
#undef UINT_MAX
#define INT_MAX 32767
#define UINT_MAX 65535

#endif

#if defined(__Z8001__) || defined(__Z8002__) || defined(__H8300__) || defined(__H8500__) || defined(__W65__) || defined (__H8300H__) || defined (__H8300S__) || defined (__mn10200__) || defined (__AVR__)

#undef INT_MAX
#undef UINT_MAX
#define INT_MAX 32767
#define UINT_MAX 65535
#endif

#if defined(__D10V__)
#undef INT_MAX
#undef UINT_MAX
#define INT_MAX __INT_MAX__
#define UINT_MAX (__INT_MAX__ * 2U + 1)
#define _DOUBLE_IS_32BITS
#define _POINTER_INT short
#define __IEEE_BIG_ENDIAN
#endif

#ifdef ___AM29K__
#define _FLOAT_RET double
#endif

#ifdef __i386__
#ifndef __unix__

#define _FLOAT_RET double
#endif
#endif

#ifdef __M32R__
#define __IEEE_BIG_ENDIAN
#endif

#ifdef __m68k__

#define __IEEE_BIG_ENDIAN
#endif

#ifdef __mn10300__
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __mn10200__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __AVR__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_LITTLE_ENDIAN
#define _POINTER_INT short
#endif

#ifdef __TIC80__
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __v850
#define __IEEE_LITTLE_ENDIAN
#define __ATTRIBUTE_IMPURE_PTR__ __attribute__((__sda__))
#endif

#ifdef __D30V__
#define __IEEE_BIG_ENDIAN
#endif

#if defined(__PPC__) && defined(_CALL_SYSV)
#define __ATTRIBUTE_IMPURE_PTR__ __attribute__((__section__(".sdata")))
#endif

#ifdef __sparc__
#ifdef __LITTLE_ENDIAN_DATA__
#define __IEEE_LITTLE_ENDIAN
#else
#define __IEEE_BIG_ENDIAN
#endif
#endif

#if INT_MAX == 32767
typedef long int __int32_t;
typedef unsigned long int __uint32_t;
#else
typedef int __int32_t;
typedef unsigned int __uint32_t;
#endif

#ifndef _POINTER_INT
#define _POINTER_INT long
#endif

#undef __RAND_MAX
#if INT_MAX == 32767
#define __RAND_MAX 32767
#else
#define __RAND_MAX 0x7fffffff
#endif

#if defined(__CYGWIN32__) || defined(__CYGWIN__)
#if defined(__INSIDE_CYGWIN__) || defined(_COMPILING_NEWLIB)
#define __IMPORT
#else
#define __IMPORT __declspec(dllimport)
#endif
#endif

#ifndef __IMPORT
#define __IMPORT
#endif

#endif 

#ifdef __STDC__
#define _HAVE_STDC
#endif

#ifdef _HAVE_STDC
#define	_PTR		void *
#define	_AND		,
#define	_NOARGS		void
#define	_CONST		const
#define	_VOLATILE	volatile
#define	_SIGNED		signed
#define	_DOTS		, ...
#define _VOID void
#ifdef __CYGWIN__
#define	_EXFUN(name, proto)		__cdecl name proto
#define	_EXPARM(name, proto)		(* __cdecl name) proto
#else
#define	_EXFUN(name, proto)		name proto
#define _EXPARM(name, proto)		(* name) proto
#endif
#define	_DEFUN(name, arglist, args)	name(args)
#define	_DEFUN_VOID(name)		name(_NOARGS)
#define _CAST_VOID (void)
#ifndef _LONG_DOUBLE
#define _LONG_DOUBLE long double
#endif
#ifndef _PARAMS
#define _PARAMS(paramlist)		paramlist
#endif
#else	
#define	_PTR		char *
#define	_AND		;
#define	_NOARGS
#define	_CONST
#define	_VOLATILE
#define	_SIGNED
#define	_DOTS
#define _VOID void
#define	_EXFUN(name, proto)		name()
#define	_DEFUN(name, arglist, args)	name arglist args;
#define	_DEFUN_VOID(name)		name()
#define _CAST_VOID
#define _LONG_DOUBLE double
#ifndef _PARAMS
#define _PARAMS(paramlist)		()
#endif
#endif

#ifdef __GNUC__
#define _ATTRIBUTE(attrs) __attribute__ (attrs)
#else
#define _ATTRIBUTE(attrs)
#endif

#endif 

#ifdef __cplusplus
extern "C" {
#endif

#ifndef NULL
#define	NULL	0
#endif

#ifndef	_MACHTIME_H_
#define	_MACHTIME_H_

#if defined(__rtems__)
#define _CLOCKS_PER_SEC_  sysconf(_SC_CLK_TCK)
#else  /* !__rtems__ */
#if defined(__arm__) || defined(__thumb__)
#define _CLOCKS_PER_SEC_ 100
#endif
#endif 

#endif	

#ifndef _CLOCKS_PER_SEC_
#define _CLOCKS_PER_SEC_ 1000
#endif

#define CLOCKS_PER_SEC _CLOCKS_PER_SEC_
#define CLK_TCK CLOCKS_PER_SEC
#define __need_size_t
/* gt4: stand-in for gcc's <stddef.h> (the compiler ships without headers). */
#ifndef _STDDEF_H
#define _STDDEF_H
typedef __SIZE_TYPE__ size_t;
typedef __PTRDIFF_TYPE__ ptrdiff_t;
#ifndef __cplusplus
typedef __WCHAR_TYPE__ wchar_t;
#endif
typedef unsigned int wint_t;
#ifndef NULL
#define NULL ((void *)0)
#endif
#define offsetof(t, m) ((size_t)&((t *)0)->m)
#endif

/* unified sys/types.h: 
   start with sef's sysvi386 version.
   merge go32 version -- a few ifdefs.
   h8300hms, h8300xray, and sysvnecv70 disagree on the following types:

   typedef int gid_t;
   typedef int uid_t;
   typedef int dev_t;
   typedef int ino_t;
   typedef int mode_t;
   typedef int caddr_t;

   however, these aren't "reasonable" values, the sysvi386 ones make far 
   more sense, and should work sufficiently well (in particular, h8300 
   doesn't have a stat, and the necv70 doesn't matter.) -- eichin
 */

#ifndef _SYS_TYPES_H
#define _SYS_TYPES_H

#if defined (_WIN32) || defined (__CYGWIN__)
#define __MS_types__
#endif

#ifdef __i386__
#if defined (GO32) || defined (__MSDOS__)
#define __MS_types__
#endif
#endif

/* gt4: stand-in for gcc's <stddef.h> (the compiler ships without headers). */
#ifndef _STDDEF_H
#define _STDDEF_H
typedef __SIZE_TYPE__ size_t;
typedef __PTRDIFF_TYPE__ ptrdiff_t;
#ifndef __cplusplus
typedef __WCHAR_TYPE__ wchar_t;
#endif
typedef unsigned int wint_t;
#ifndef NULL
#define NULL ((void *)0)
#endif
#define offsetof(t, m) ((size_t)&((t *)0)->m)
#endif

#ifndef	_MACHTYPES_H_
#define	_MACHTYPES_H_

#define	_CLOCK_T_	unsigned long		/* clock() */
#define	_TIME_T_	long			
#define _CLOCKID_T_ 	unsigned long
#define _TIMER_T_   	unsigned long

#endif	

#ifdef __GNUC__
#define _ST_INT32 __attribute__ ((__mode__ (__SI__)))
#else
#define _ST_INT32
#endif

# ifndef	_POSIX_SOURCE

#  define	physadr		physadr_t
#  define	quad		quad_t

#ifndef _WINSOCK_H
typedef	unsigned char	u_char;
typedef	unsigned short	u_short;
typedef	unsigned int	u_int;
typedef	unsigned long	u_long;
#endif

typedef	unsigned short	ushort;		
typedef	unsigned int	uint;		
# endif	

#ifndef __clock_t_defined
typedef _CLOCK_T_ clock_t;
#define __clock_t_defined
#endif

#ifndef __time_t_defined
typedef _TIME_T_ time_t;
#define __time_t_defined

struct timespec {
  time_t  tv_sec;   
  long    tv_nsec;  
};

struct itimerspec {
  struct timespec  it_interval;  
  struct timespec  it_value;     
};
#endif

typedef	long	daddr_t;
typedef	char *	caddr_t;

#ifdef __MS_types__
typedef	unsigned long	ino_t;
#else
#ifdef __sparc__
typedef	unsigned long	ino_t;
#else
typedef	unsigned short	ino_t;
#endif
#endif

#ifdef __MS_types__
typedef unsigned long vm_offset_t;
typedef unsigned long vm_size_t;

#define __BIT_TYPES_DEFINED__

typedef char int8_t;
typedef unsigned char u_int8_t;
typedef short int16_t;
typedef unsigned short u_int16_t;
typedef int int32_t;
typedef unsigned int u_int32_t;
typedef long long int64_t;
typedef unsigned long long u_int64_t;
typedef int32_t register_t;
#endif 

#if defined(__rtems__)

typedef unsigned long long dev_t;
#else
typedef	short	dev_t;
#endif

typedef	long	off_t;

typedef	unsigned short	uid_t;
typedef	unsigned short	gid_t;
typedef int pid_t;
typedef	long key_t;
typedef long ssize_t;

#ifdef __MS_types__
typedef	char *	addr_t;
typedef int mode_t;
#else
#if defined (__sparc__) && !defined (__sparc_v9__)
#ifdef __svr4__
typedef unsigned long mode_t;
#else
typedef unsigned short mode_t;
#endif
#else
typedef unsigned int mode_t _ST_INT32;
#endif
#endif 

typedef unsigned short nlink_t;

# if ! defined (_POSIX_SOURCE) && ! defined (_WINSOCK_H)

#  define	NBBY	8		

#  ifndef	FD_SETSIZE
#	define	FD_SETSIZE	64
#  endif

typedef	long	fd_mask;
#  define	NFDBITS	(sizeof (fd_mask) * NBBY)	
#  ifndef	howmany
#	define	howmany(x,y)	(((x)+((y)-1))/(y))
#  endif

typedef	struct _types_fd_set {
	fd_mask	fds_bits[howmany(FD_SETSIZE, NFDBITS)];
} _types_fd_set;

#define fd_set _types_fd_set

#  define	FD_SET(n, p)	((p)->fds_bits[(n)/NFDBITS] |= (1L << ((n) % NFDBITS)))
#  define	FD_CLR(n, p)	((p)->fds_bits[(n)/NFDBITS] &= ~(1L << ((n) % NFDBITS)))
#  define	FD_ISSET(n, p)	((p)->fds_bits[(n)/NFDBITS] & (1L << ((n) % NFDBITS)))
#  define	FD_ZERO(p)	(__extension__ (void)({ \
     size_t __i; \
     char *__tmp = (char *)p; \
     for (__i = 0; __i < sizeof (*(p)); ++__i) \
       *__tmp++ = 0; \
}))

# endif	

#undef __MS_types__
#undef _ST_INT32

#if defined(__rtems__)

#ifndef __clockid_t_defined
typedef _CLOCKID_T_ clockid_t;
#define __clockid_t_defined
#endif

#ifndef __timer_t_defined
typedef _TIMER_T_ timer_t;
#define __timer_t_defined
#endif

/*
 *  Written by Joel Sherrill <joel@OARcorp.com>.
 *
 *  COPYRIGHT (c) 1989-2000.
 *
 *  On-Line Applications Research Corporation (OAR).
 *
 *  Permission to use, copy, modify, and distribute this software for any
 *  purpose without fee is hereby granted, provided that this entire notice
 *  is included in all copies of any software which is or includes a copy
 *  or modification of this software.
 *
 *  THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 *  WARRANTY.  IN PARTICULAR,  THE AUTHOR MAKES NO REPRESENTATION
 *  OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY OF THIS
 *  SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 *  $Id: features.h,v 1.1 2000/12/12 01:24:08 jjohnstn Exp $
 */

#ifndef _SYS_FEATURES_H
#define _SYS_FEATURES_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __rtems__
#define _POSIX_JOB_CONTROL     		1
#define _POSIX_SAVED_IDS       		1
#define _POSIX_VERSION			199309L
#define _POSIX_ASYNCHRONOUS_IO		1
#define _POSIX_FSYNC			1
#define _POSIX_MAPPED_FILES		1
#define _POSIX_MEMLOCK			1
#define _POSIX_MEMLOCK_RANGE		1
#define _POSIX_MEMORY_PROTECTION	1
#define _POSIX_MESSAGE_PASSING		1
#define _POSIX_PRIORITIZED_IO		1
#define _POSIX_PRIORITY_SCHEDULING	1
#define _POSIX_REALTIME_SIGNALS		1
#define _POSIX_SEMAPHORES		1
#define _POSIX_SHARED_MEMORY_OBJECTS	1
#define _POSIX_SYNCHRONIZED_IO		1
#define _POSIX_TIMERS			1

#define _POSIX_THREADS				1
#define _POSIX_THREAD_ATTR_STACKADDR		1
#define _POSIX_THREAD_ATTR_STACKSIZE		1
#define _POSIX_THREAD_PRIORITY_SCHEDULING	1
#define _POSIX_THREAD_PRIO_INHERIT		1
#define _POSIX_THREAD_PRIO_PROTECT		1
#define _POSIX_THREAD_PROCESS_SHARED		1
#define _POSIX_THREAD_SAFE_FUNCTIONS		1

#define _POSIX_SPAWN				1
#define _POSIX_TIMEOUTS				1
#define _POSIX_CPUTIME				1
#define _POSIX_THREAD_CPUTIME			1
#define _POSIX_SPORADIC_SERVER			1
#define _POSIX_THREAD_SPORADIC_SERVER		1
#define _POSIX_DEVICE_CONTROL			1
#define _POSIX_DEVCTL_DIRECTION			1
#define _POSIX_INTERRUPT_CONTROL		1
#define _POSIX_ADVISORY_INFO			1

#endif

#ifdef __svr4__
# define _POSIX_JOB_CONTROL     1
# define _POSIX_SAVED_IDS       1
# define _POSIX_VERSION 199009L
#endif

#ifdef __CYGWIN32__
# define _POSIX_JOB_CONTROL	1
# define _POSIX_SAVED_IDS	0
# define _POSIX_VERSION		199009L
#endif

#ifdef __cplusplus
}
#endif
#endif 

#if defined(_POSIX_THREADS)

/*
 *  Written by Joel Sherrill <joel@OARcorp.com>.
 *
 *  COPYRIGHT (c) 1989-2000.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  Permission to use, copy, modify, and distribute this software for any
 *  purpose without fee is hereby granted, provided that this entire notice
 *  is included in all copies of any software which is or includes a copy
 *  or modification of this software.
 *
 *  THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 *  WARRANTY.  IN PARTICULAR,  THE AUTHOR MAKES NO REPRESENTATION
 *  OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY OF THIS
 *  SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 *  $Id: sched.h,v 1.1 2000/12/12 01:24:08 jjohnstn Exp $
 */

#ifndef __POSIX_SYS_SCHEDULING_h
#define __POSIX_SYS_SCHEDULING_h

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _SYS_UNISTD_H
#define _SYS_UNISTD_H

#ifdef __cplusplus
extern "C" {
#endif

/* Provide support for both ANSI and non-ANSI environments.  */

#ifndef	_ANSIDECL_H_
#define	_ANSIDECL_H_

#ifndef __SYS_CONFIG_H__
#define __SYS_CONFIG_H__

/* exceptions first */

#if defined(__H8300__) || defined(__H8500__) || defined (__H8300H__) ||  defined(__W65__) || defined (__H8300S__)
#define _FLOAT_ARG float
#define __SMALL_BITFIELDS
#define _DOUBLE_IS_32BITS
#define __IEEE_BIG_ENDIAN

#define H8300 1
#endif

#ifdef __W65__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_BIG_ENDIAN
#undef INT_MAX
#undef UINT_MAX
#define INT_MAX 32767
#define UINT_MAX 65535

#endif

#if defined(__Z8001__) || defined(__Z8002__) || defined(__H8300__) || defined(__H8500__) || defined(__W65__) || defined (__H8300H__) || defined (__H8300S__) || defined (__mn10200__) || defined (__AVR__)

#undef INT_MAX
#undef UINT_MAX
#define INT_MAX 32767
#define UINT_MAX 65535
#endif

#if defined(__D10V__)
#undef INT_MAX
#undef UINT_MAX
#define INT_MAX __INT_MAX__
#define UINT_MAX (__INT_MAX__ * 2U + 1)
#define _DOUBLE_IS_32BITS
#define _POINTER_INT short
#define __IEEE_BIG_ENDIAN
#endif

#ifdef ___AM29K__
#define _FLOAT_RET double
#endif

#ifdef __i386__
#ifndef __unix__

#define _FLOAT_RET double
#endif
#endif

#ifdef __M32R__
#define __IEEE_BIG_ENDIAN
#endif

#ifdef __m68k__

#define __IEEE_BIG_ENDIAN
#endif

#ifdef __mn10300__
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __mn10200__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __AVR__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_LITTLE_ENDIAN
#define _POINTER_INT short
#endif

#ifdef __TIC80__
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __v850
#define __IEEE_LITTLE_ENDIAN
#define __ATTRIBUTE_IMPURE_PTR__ __attribute__((__sda__))
#endif

#ifdef __D30V__
#define __IEEE_BIG_ENDIAN
#endif

#if defined(__PPC__) && defined(_CALL_SYSV)
#define __ATTRIBUTE_IMPURE_PTR__ __attribute__((__section__(".sdata")))
#endif

#ifdef __sparc__
#ifdef __LITTLE_ENDIAN_DATA__
#define __IEEE_LITTLE_ENDIAN
#else
#define __IEEE_BIG_ENDIAN
#endif
#endif

#if INT_MAX == 32767
typedef long int __int32_t;
typedef unsigned long int __uint32_t;
#else
typedef int __int32_t;
typedef unsigned int __uint32_t;
#endif

#ifndef _POINTER_INT
#define _POINTER_INT long
#endif

#undef __RAND_MAX
#if INT_MAX == 32767
#define __RAND_MAX 32767
#else
#define __RAND_MAX 0x7fffffff
#endif

#if defined(__CYGWIN32__) || defined(__CYGWIN__)
#if defined(__INSIDE_CYGWIN__) || defined(_COMPILING_NEWLIB)
#define __IMPORT
#else
#define __IMPORT __declspec(dllimport)
#endif
#endif

#ifndef __IMPORT
#define __IMPORT
#endif

#endif 

#ifdef __STDC__
#define _HAVE_STDC
#endif

#ifdef _HAVE_STDC
#define	_PTR		void *
#define	_AND		,
#define	_NOARGS		void
#define	_CONST		const
#define	_VOLATILE	volatile
#define	_SIGNED		signed
#define	_DOTS		, ...
#define _VOID void
#ifdef __CYGWIN__
#define	_EXFUN(name, proto)		__cdecl name proto
#define	_EXPARM(name, proto)		(* __cdecl name) proto
#else
#define	_EXFUN(name, proto)		name proto
#define _EXPARM(name, proto)		(* name) proto
#endif
#define	_DEFUN(name, arglist, args)	name(args)
#define	_DEFUN_VOID(name)		name(_NOARGS)
#define _CAST_VOID (void)
#ifndef _LONG_DOUBLE
#define _LONG_DOUBLE long double
#endif
#ifndef _PARAMS
#define _PARAMS(paramlist)		paramlist
#endif
#else	
#define	_PTR		char *
#define	_AND		;
#define	_NOARGS
#define	_CONST
#define	_VOLATILE
#define	_SIGNED
#define	_DOTS
#define _VOID void
#define	_EXFUN(name, proto)		name()
#define	_DEFUN(name, arglist, args)	name arglist args;
#define	_DEFUN_VOID(name)		name()
#define _CAST_VOID
#define _LONG_DOUBLE double
#ifndef _PARAMS
#define _PARAMS(paramlist)		()
#endif
#endif

#ifdef __GNUC__
#define _ATTRIBUTE(attrs) __attribute__ (attrs)
#else
#define _ATTRIBUTE(attrs)
#endif

#endif 

/* unified sys/types.h: 
   start with sef's sysvi386 version.
   merge go32 version -- a few ifdefs.
   h8300hms, h8300xray, and sysvnecv70 disagree on the following types:

   typedef int gid_t;
   typedef int uid_t;
   typedef int dev_t;
   typedef int ino_t;
   typedef int mode_t;
   typedef int caddr_t;

   however, these aren't "reasonable" values, the sysvi386 ones make far 
   more sense, and should work sufficiently well (in particular, h8300 
   doesn't have a stat, and the necv70 doesn't matter.) -- eichin
 */

#ifndef _SYS_TYPES_H
#define _SYS_TYPES_H

#if defined (_WIN32) || defined (__CYGWIN__)
#define __MS_types__
#endif

#ifdef __i386__
#if defined (GO32) || defined (__MSDOS__)
#define __MS_types__
#endif
#endif

/* gt4: stand-in for gcc's <stddef.h> (the compiler ships without headers). */
#ifndef _STDDEF_H
#define _STDDEF_H
typedef __SIZE_TYPE__ size_t;
typedef __PTRDIFF_TYPE__ ptrdiff_t;
#ifndef __cplusplus
typedef __WCHAR_TYPE__ wchar_t;
#endif
typedef unsigned int wint_t;
#ifndef NULL
#define NULL ((void *)0)
#endif
#define offsetof(t, m) ((size_t)&((t *)0)->m)
#endif

#ifndef	_MACHTYPES_H_
#define	_MACHTYPES_H_

#define	_CLOCK_T_	unsigned long		/* clock() */
#define	_TIME_T_	long			
#define _CLOCKID_T_ 	unsigned long
#define _TIMER_T_   	unsigned long

#endif	

#ifdef __GNUC__
#define _ST_INT32 __attribute__ ((__mode__ (__SI__)))
#else
#define _ST_INT32
#endif

# ifndef	_POSIX_SOURCE

#  define	physadr		physadr_t
#  define	quad		quad_t

#ifndef _WINSOCK_H
typedef	unsigned char	u_char;
typedef	unsigned short	u_short;
typedef	unsigned int	u_int;
typedef	unsigned long	u_long;
#endif

typedef	unsigned short	ushort;		
typedef	unsigned int	uint;		
# endif	

#ifndef __clock_t_defined
typedef _CLOCK_T_ clock_t;
#define __clock_t_defined
#endif

#ifndef __time_t_defined
typedef _TIME_T_ time_t;
#define __time_t_defined

struct timespec {
  time_t  tv_sec;   
  long    tv_nsec;  
};

struct itimerspec {
  struct timespec  it_interval;  
  struct timespec  it_value;     
};
#endif

typedef	long	daddr_t;
typedef	char *	caddr_t;

#ifdef __MS_types__
typedef	unsigned long	ino_t;
#else
#ifdef __sparc__
typedef	unsigned long	ino_t;
#else
typedef	unsigned short	ino_t;
#endif
#endif

#ifdef __MS_types__
typedef unsigned long vm_offset_t;
typedef unsigned long vm_size_t;

#define __BIT_TYPES_DEFINED__

typedef char int8_t;
typedef unsigned char u_int8_t;
typedef short int16_t;
typedef unsigned short u_int16_t;
typedef int int32_t;
typedef unsigned int u_int32_t;
typedef long long int64_t;
typedef unsigned long long u_int64_t;
typedef int32_t register_t;
#endif 

#if defined(__rtems__)

typedef unsigned long long dev_t;
#else
typedef	short	dev_t;
#endif

typedef	long	off_t;

typedef	unsigned short	uid_t;
typedef	unsigned short	gid_t;
typedef int pid_t;
typedef	long key_t;
typedef long ssize_t;

#ifdef __MS_types__
typedef	char *	addr_t;
typedef int mode_t;
#else
#if defined (__sparc__) && !defined (__sparc_v9__)
#ifdef __svr4__
typedef unsigned long mode_t;
#else
typedef unsigned short mode_t;
#endif
#else
typedef unsigned int mode_t _ST_INT32;
#endif
#endif 

typedef unsigned short nlink_t;

# if ! defined (_POSIX_SOURCE) && ! defined (_WINSOCK_H)

#  define	NBBY	8		

#  ifndef	FD_SETSIZE
#	define	FD_SETSIZE	64
#  endif

typedef	long	fd_mask;
#  define	NFDBITS	(sizeof (fd_mask) * NBBY)	
#  ifndef	howmany
#	define	howmany(x,y)	(((x)+((y)-1))/(y))
#  endif

typedef	struct _types_fd_set {
	fd_mask	fds_bits[howmany(FD_SETSIZE, NFDBITS)];
} _types_fd_set;

#define fd_set _types_fd_set

#  define	FD_SET(n, p)	((p)->fds_bits[(n)/NFDBITS] |= (1L << ((n) % NFDBITS)))
#  define	FD_CLR(n, p)	((p)->fds_bits[(n)/NFDBITS] &= ~(1L << ((n) % NFDBITS)))
#  define	FD_ISSET(n, p)	((p)->fds_bits[(n)/NFDBITS] & (1L << ((n) % NFDBITS)))
#  define	FD_ZERO(p)	(__extension__ (void)({ \
     size_t __i; \
     char *__tmp = (char *)p; \
     for (__i = 0; __i < sizeof (*(p)); ++__i) \
       *__tmp++ = 0; \
}))

# endif	

#undef __MS_types__
#undef _ST_INT32

#if defined(__rtems__)

#ifndef __clockid_t_defined
typedef _CLOCKID_T_ clockid_t;
#define __clockid_t_defined
#endif

#ifndef __timer_t_defined
typedef _TIMER_T_ timer_t;
#define __timer_t_defined
#endif

/*
 *  Written by Joel Sherrill <joel@OARcorp.com>.
 *
 *  COPYRIGHT (c) 1989-2000.
 *
 *  On-Line Applications Research Corporation (OAR).
 *
 *  Permission to use, copy, modify, and distribute this software for any
 *  purpose without fee is hereby granted, provided that this entire notice
 *  is included in all copies of any software which is or includes a copy
 *  or modification of this software.
 *
 *  THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 *  WARRANTY.  IN PARTICULAR,  THE AUTHOR MAKES NO REPRESENTATION
 *  OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY OF THIS
 *  SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 *  $Id: features.h,v 1.1 2000/12/12 01:24:08 jjohnstn Exp $
 */

#ifndef _SYS_FEATURES_H
#define _SYS_FEATURES_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __rtems__
#define _POSIX_JOB_CONTROL     		1
#define _POSIX_SAVED_IDS       		1
#define _POSIX_VERSION			199309L
#define _POSIX_ASYNCHRONOUS_IO		1
#define _POSIX_FSYNC			1
#define _POSIX_MAPPED_FILES		1
#define _POSIX_MEMLOCK			1
#define _POSIX_MEMLOCK_RANGE		1
#define _POSIX_MEMORY_PROTECTION	1
#define _POSIX_MESSAGE_PASSING		1
#define _POSIX_PRIORITIZED_IO		1
#define _POSIX_PRIORITY_SCHEDULING	1
#define _POSIX_REALTIME_SIGNALS		1
#define _POSIX_SEMAPHORES		1
#define _POSIX_SHARED_MEMORY_OBJECTS	1
#define _POSIX_SYNCHRONIZED_IO		1
#define _POSIX_TIMERS			1

#define _POSIX_THREADS				1
#define _POSIX_THREAD_ATTR_STACKADDR		1
#define _POSIX_THREAD_ATTR_STACKSIZE		1
#define _POSIX_THREAD_PRIORITY_SCHEDULING	1
#define _POSIX_THREAD_PRIO_INHERIT		1
#define _POSIX_THREAD_PRIO_PROTECT		1
#define _POSIX_THREAD_PROCESS_SHARED		1
#define _POSIX_THREAD_SAFE_FUNCTIONS		1

#define _POSIX_SPAWN				1
#define _POSIX_TIMEOUTS				1
#define _POSIX_CPUTIME				1
#define _POSIX_THREAD_CPUTIME			1
#define _POSIX_SPORADIC_SERVER			1
#define _POSIX_THREAD_SPORADIC_SERVER		1
#define _POSIX_DEVICE_CONTROL			1
#define _POSIX_DEVCTL_DIRECTION			1
#define _POSIX_INTERRUPT_CONTROL		1
#define _POSIX_ADVISORY_INFO			1

#endif

#ifdef __svr4__
# define _POSIX_JOB_CONTROL     1
# define _POSIX_SAVED_IDS       1
# define _POSIX_VERSION 199009L
#endif

#ifdef __CYGWIN32__
# define _POSIX_JOB_CONTROL	1
# define _POSIX_SAVED_IDS	0
# define _POSIX_VERSION		199009L
#endif

#ifdef __cplusplus
}
#endif
#endif 

#if defined(_POSIX_THREADS)

/*
 *  Written by Joel Sherrill <joel@OARcorp.com>.
 *
 *  COPYRIGHT (c) 1989-2000.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  Permission to use, copy, modify, and distribute this software for any
 *  purpose without fee is hereby granted, provided that this entire notice
 *  is included in all copies of any software which is or includes a copy
 *  or modification of this software.
 *
 *  THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 *  WARRANTY.  IN PARTICULAR,  THE AUTHOR MAKES NO REPRESENTATION
 *  OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY OF THIS
 *  SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 *  $Id: sched.h,v 1.1 2000/12/12 01:24:08 jjohnstn Exp $
 */

#ifndef __POSIX_SYS_SCHEDULING_h
#define __POSIX_SYS_SCHEDULING_h

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/unistd.h>

#include <sys/types.h>
#include <sys/time.h>

#define SCHED_OTHER    0
#define SCHED_FIFO     1
#define SCHED_RR       2

#if defined(_POSIX_SPORADIC_SERVER)
#define SCHED_SPORADIC 3 
#endif

struct sched_param {
  int sched_priority;           

#if defined(_POSIX_SPORADIC_SERVER)
  int ss_low_priority;          
                                
  struct timespec ss_replenish_period; 
                                
  struct timespec ss_initial_budget;   
#endif
};

#ifdef __cplusplus
}
#endif 

#endif

typedef __uint32_t pthread_t;            

#define PTHREAD_SCOPE_PROCESS 0
#define PTHREAD_SCOPE_SYSTEM  1

#define PTHREAD_INHERIT_SCHED  1      
                                      
                                      
#define PTHREAD_EXPLICIT_SCHED 2      

#define PTHREAD_CREATE_DETACHED 0
#define PTHREAD_CREATE_JOINABLE  1

typedef struct {
  int is_initialized;
  void *stackaddr;
  int stacksize;
  int contentionscope;
  int inheritsched;
  int schedpolicy;
  struct sched_param schedparam;

  
#if defined(_POSIX_THREAD_CPUTIME)
  int  cputime_clock_allowed;  
#endif
  int  detachstate;

} pthread_attr_t;

#if defined(_POSIX_THREAD_PROCESS_SHARED)

#define PTHREAD_PROCESS_PRIVATE 0 
#define PTHREAD_PROCESS_SHARED  1 
                                  
                                  
#endif

#if defined(_POSIX_THREAD_PRIO_PROTECT)

#define PTHREAD_PRIO_NONE    0
#define PTHREAD_PRIO_INHERIT 1
#define PTHREAD_PRIO_PROTECT 2
#endif

typedef __uint32_t pthread_mutex_t;      

typedef struct {
  int   is_initialized;
#if defined(_POSIX_THREAD_PROCESS_SHARED)
  int   process_shared;  
#endif
#if defined(_POSIX_THREAD_PRIO_PROTECT)
  int   prio_ceiling;
  int   protocol;
#endif
  int   recursive;
} pthread_mutexattr_t;

typedef __uint32_t pthread_cond_t;       

typedef struct {
  int   is_initialized;
#if defined(_POSIX_THREAD_PROCESS_SHARED)
  int   process_shared;       
#endif
} pthread_condattr_t;         

typedef __uint32_t pthread_key_t;        

typedef struct {
  int   is_initialized;  
  int   init_executed;   
} pthread_once_t;       

#endif 

#endif  

#endif	

#define __need_size_t
#define __need_ptrdiff_t
/* gt4: stand-in for gcc's <stddef.h> (the compiler ships without headers). */
#ifndef _STDDEF_H
#define _STDDEF_H
typedef __SIZE_TYPE__ size_t;
typedef __PTRDIFF_TYPE__ ptrdiff_t;
#ifndef __cplusplus
typedef __WCHAR_TYPE__ wchar_t;
#endif
typedef unsigned int wint_t;
#ifndef NULL
#define NULL ((void *)0)
#endif
#define offsetof(t, m) ((size_t)&((t *)0)->m)
#endif

extern char **environ;

void	_EXFUN(_exit, (int __status ) _ATTRIBUTE ((noreturn)));

int	_EXFUN(access,(const char *__path, int __amode ));
unsigned  _EXFUN(alarm, (unsigned __secs ));
int     _EXFUN(chdir, (const char *__path ));
int     _EXFUN(chmod, (const char *__path, mode_t __mode ));
int     _EXFUN(chown, (const char *__path, uid_t __owner, gid_t __group ));
#ifdef __CYGWIN__
int     _EXFUN(chroot, (const char *__path ));
#endif
int     _EXFUN(close, (int __fildes ));
char    _EXFUN(*ctermid, (char *__s ));
char    _EXFUN(*cuserid, (char *__s ));
int     _EXFUN(dup, (int __fildes ));
int     _EXFUN(dup2, (int __fildes, int __fildes2 ));
int     _EXFUN(execl, (const char *__path, const char *, ... ));
int     _EXFUN(execle, (const char *__path, const char *, ... ));
int     _EXFUN(execlp, (const char *__file, const char *, ... ));
int     _EXFUN(execv, (const char *__path, char * const __argv[] ));
int     _EXFUN(execve, (const char *__path, char * const __argv[], char * const __envp[] ));
int     _EXFUN(execvp, (const char *__file, char * const __argv[] ));
int     _EXFUN(fchmod, (int __fildes, mode_t __mode ));
int     _EXFUN(fchown, (int __fildes, uid_t __owner, gid_t __group ));
pid_t   _EXFUN(fork, (void ));
long    _EXFUN(fpathconf, (int __fd, int __name ));
int     _EXFUN(fsync, (int __fd));
char    _EXFUN(*getcwd, (char *__buf, size_t __size ));
gid_t   _EXFUN(getegid, (void ));
uid_t   _EXFUN(geteuid, (void ));
gid_t   _EXFUN(getgid, (void ));
int     _EXFUN(getgroups, (int __gidsetsize, gid_t __grouplist[] ));
char    _EXFUN(*getlogin, (void ));
#if defined(_POSIX_THREAD_SAFE_FUNCTIONS)
int _EXFUN(getlogin_r, (char *name, size_t namesize) );
#endif
char 	_EXFUN(*getpass, (__const char *__prompt));
size_t  _EXFUN(getpagesize, (void));
pid_t   _EXFUN(getpgrp, (void ));
pid_t   _EXFUN(getpid, (void ));
pid_t   _EXFUN(getppid, (void ));
uid_t   _EXFUN(getuid, (void ));
#ifdef __CYGWIN__
char    _EXFUN(*getwd, (char *__buf ));
#endif
int     _EXFUN(isatty, (int __fildes ));
int     _EXFUN(lchown, (const char *__path, uid_t __owner, gid_t __group ));
int     _EXFUN(link, (const char *__path1, const char *__path2 ));
int	_EXFUN(nice, (int __nice_value ));
off_t   _EXFUN(lseek, (int __fildes, off_t __offset, int __whence ));
long    _EXFUN(pathconf, (const char *__path, int __name ));
int     _EXFUN(pause, (void ));
int     _EXFUN(pipe, (int __fildes[2] ));
/* POSIX 1003.1b-1993 says read() returns ssize_t */
#if defined(__rtems__)
ssize_t	_EXFUN(read, (int __fildes, void *__buf, size_t __nbyte ));
#else
int	_EXFUN(read, (int __fildes, void *__buf, size_t __nbyte ));
#endif
int     _EXFUN(rmdir, (const char *__path ));
#if defined(__rtems__)
void *  _EXFUN(sbrk,  (ptrdiff_t __incr));
#else
void *  _EXFUN(sbrk,  (size_t __incr));
#endif
#if defined(__CYGWIN__)
int     _EXFUN(setegid, (gid_t __gid ));
int     _EXFUN(seteuid, (uid_t __uid ));
#endif
int     _EXFUN(setgid, (gid_t __gid ));
int     _EXFUN(setpgid, (pid_t __pid, pid_t __pgid ));
pid_t   _EXFUN(setsid, (void ));
int     _EXFUN(setuid, (uid_t __uid ));
unsigned _EXFUN(sleep, (unsigned int __seconds ));
void    _EXFUN(swab, (const void *, void *, ssize_t));
long    _EXFUN(sysconf, (int __name ));
pid_t   _EXFUN(tcgetpgrp, (int __fildes ));
int     _EXFUN(tcsetpgrp, (int __fildes, pid_t __pgrp_id ));
char    _EXFUN(*ttyname, (int __fildes ));
int     _EXFUN(unlink, (const char *__path ));

#if defined(__rtems__)
ssize_t     _EXFUN(write, (int __fildes, const void *__buf, size_t __nbyte ));
#else
int     _EXFUN(write, (int __fildes, const void *__buf, size_t __nbyte ));
#endif

#ifndef        _POSIX_SOURCE
pid_t   _EXFUN(vfork, (void ));
#endif 

int     _EXFUN(_close, (int __fildes ));
pid_t   _EXFUN(_fork, (void ));
pid_t   _EXFUN(_getpid, (void ));
int     _EXFUN(_link, (const char *__path1, const char *__path2 ));
off_t   _EXFUN(_lseek, (int __fildes, off_t __offset, int __whence ));
int     _EXFUN(_read, (int __fildes, void *__buf, size_t __nbyte ));
void *  _EXFUN(_sbrk,  (size_t __incr));
int     _EXFUN(_unlink, (const char *__path ));
int     _EXFUN(_write, (int __fildes, const void *__buf, size_t __nbyte ));
int     _EXFUN(_execve, (const char *__path, char * const __argv[], char * const __envp[] ));

#if defined(__CYGWIN__) || defined(__rtems__)
int	_EXFUN(getdtablesize, (void));
void	_EXFUN(setdtablesize, (int));
unsigned _EXFUN(usleep, (unsigned int __useconds));
int     _EXFUN(ftruncate, (int __fd, off_t __length));
int     _EXFUN(truncate, (const char *, off_t __length));
int	_EXFUN(gethostname, (char *__name, size_t __len));
char *	_EXFUN(mktemp, (char *));
int     _EXFUN(sync, (void));
int     _EXFUN(readlink, (const char *__path, char *__buf, int __buflen));
int     _EXFUN(symlink, (const char *__name1, const char *__name2));
#endif

# define	F_OK	0
# define	R_OK	4
# define	W_OK	2
# define	X_OK	1

# define	SEEK_SET	0
# define	SEEK_CUR	1
# define	SEEK_END	2

/*
 *  Written by Joel Sherrill <joel@OARcorp.com>.
 *
 *  COPYRIGHT (c) 1989-2000.
 *
 *  On-Line Applications Research Corporation (OAR).
 *
 *  Permission to use, copy, modify, and distribute this software for any
 *  purpose without fee is hereby granted, provided that this entire notice
 *  is included in all copies of any software which is or includes a copy
 *  or modification of this software.
 *
 *  THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 *  WARRANTY.  IN PARTICULAR,  THE AUTHOR MAKES NO REPRESENTATION
 *  OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY OF THIS
 *  SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 *  $Id: features.h,v 1.1 2000/12/12 01:24:08 jjohnstn Exp $
 */

#ifndef _SYS_FEATURES_H
#define _SYS_FEATURES_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __rtems__
#define _POSIX_JOB_CONTROL     		1
#define _POSIX_SAVED_IDS       		1
#define _POSIX_VERSION			199309L
#define _POSIX_ASYNCHRONOUS_IO		1
#define _POSIX_FSYNC			1
#define _POSIX_MAPPED_FILES		1
#define _POSIX_MEMLOCK			1
#define _POSIX_MEMLOCK_RANGE		1
#define _POSIX_MEMORY_PROTECTION	1
#define _POSIX_MESSAGE_PASSING		1
#define _POSIX_PRIORITIZED_IO		1
#define _POSIX_PRIORITY_SCHEDULING	1
#define _POSIX_REALTIME_SIGNALS		1
#define _POSIX_SEMAPHORES		1
#define _POSIX_SHARED_MEMORY_OBJECTS	1
#define _POSIX_SYNCHRONIZED_IO		1
#define _POSIX_TIMERS			1

#define _POSIX_THREADS				1
#define _POSIX_THREAD_ATTR_STACKADDR		1
#define _POSIX_THREAD_ATTR_STACKSIZE		1
#define _POSIX_THREAD_PRIORITY_SCHEDULING	1
#define _POSIX_THREAD_PRIO_INHERIT		1
#define _POSIX_THREAD_PRIO_PROTECT		1
#define _POSIX_THREAD_PROCESS_SHARED		1
#define _POSIX_THREAD_SAFE_FUNCTIONS		1

#define _POSIX_SPAWN				1
#define _POSIX_TIMEOUTS				1
#define _POSIX_CPUTIME				1
#define _POSIX_THREAD_CPUTIME			1
#define _POSIX_SPORADIC_SERVER			1
#define _POSIX_THREAD_SPORADIC_SERVER		1
#define _POSIX_DEVICE_CONTROL			1
#define _POSIX_DEVCTL_DIRECTION			1
#define _POSIX_INTERRUPT_CONTROL		1
#define _POSIX_ADVISORY_INFO			1

#endif

#ifdef __svr4__
# define _POSIX_JOB_CONTROL     1
# define _POSIX_SAVED_IDS       1
# define _POSIX_VERSION 199009L
#endif

#ifdef __CYGWIN32__
# define _POSIX_JOB_CONTROL	1
# define _POSIX_SAVED_IDS	0
# define _POSIX_VERSION		199009L
#endif

#ifdef __cplusplus
}
#endif
#endif 

#define STDIN_FILENO    0       
#define STDOUT_FILENO   1       
#define STDERR_FILENO   2       

long _EXFUN(sysconf, (int __name));

#define _SC_ARG_MAX                 0
#define _SC_CHILD_MAX               1
#define _SC_CLK_TCK                 2
#define _SC_NGROUPS_MAX             3
#define _SC_OPEN_MAX                4
  
#define _SC_JOB_CONTROL             5
#define _SC_SAVED_IDS               6
#define _SC_VERSION                 7
#define _SC_PAGESIZE                8

#define _SC_NPROCESSORS_CONF        9
#define _SC_NPROCESSORS_ONLN       10
#define _SC_PHYS_PAGES             11
#define _SC_AVPHYS_PAGES           12

#define _SC_MQ_OPEN_MAX            13
#define _SC_MQ_PRIO_MAX            14
#define _SC_RTSIG_MAX              15
#define _SC_SEM_NSEMS_MAX          16
#define _SC_SEM_VALUE_MAX          17
#define _SC_SIGQUEUE_MAX           18
#define _SC_TIMER_MAX              19
#define _SC_TZNAME_MAX             20

#define _SC_ASYNCHRONOUS_IO        21
#define _SC_FSYNC                  22
#define _SC_MAPPED_FILES           23
#define _SC_MEMLOCK                24
#define _SC_MEMLOCK_RANGE          25
#define _SC_MEMORY_PROTECTION      26
#define _SC_MESSAGE_PASSING        27
#define _SC_PRIORITIZED_IO         28
#define _SC_REALTIME_SIGNALS       29
#define _SC_SEMAPHORES             30
#define _SC_SHARED_MEMORY_OBJECTS  31
#define _SC_SYNCHRONIZED_IO        32
#define _SC_TIMERS                 33
#define _SC_AIO_LISTIO_MAX         34
#define _SC_AIO_MAX                35
#define _SC_AIO_PRIO_DELTA_MAX     36
#define _SC_DELAYTIMER_MAX         37

#define _SC_THREAD_KEYS_MAX              38
#define _SC_THREAD_STACK_MIN             39
#define _SC_THREAD_THREADS_MAX           40
#define _SC_TTY_NAME_MAX                 41

#define _SC_THREADS                      42
#define _SC_THREAD_ATTR_STACKADDR        43
#define _SC_THREAD_ATTR_STACKSIZE        44
#define _SC_THREAD_PRIORITY_SCHEDULING   45
#define _SC_THREAD_PRIO_INHERIT          46

#define _SC_THREAD_PRIO_PROTECT          47
#define _SC_THREAD_PRIO_CEILING          _SC_THREAD_PRIO_PROTECT
#define _SC_THREAD_PROCESS_SHARED        48
#define _SC_THREAD_SAFE_FUNCTIONS        49
#define _SC_GETGR_R_SIZE_MAX             50
#define _SC_GETPW_R_SIZE_MAX             51
#define _SC_LOGIN_NAME_MAX               52
#define _SC_THREAD_DESTRUCTOR_ITERATIONS 53
  
# define	_PC_LINK_MAX	        0
# define	_PC_MAX_CANON	        1
# define	_PC_MAX_INPUT	        2
# define	_PC_NAME_MAX	        3
# define	_PC_PATH_MAX	        4
# define	_PC_PIPE_BUF	        5
# define	_PC_CHOWN_RESTRICTED   	6
# define	_PC_NO_TRUNC	        7
# define	_PC_VDISABLE	        8
# define	_PC_ASYNC_IO            9
# define	_PC_PRIO_IO            10
# define	_PC_SYNC_IO            11

#ifdef __CYGWIN__
#define MAXPATHLEN (260 - 1 )
#else
# define	MAXPATHLEN	1024
#endif

#ifdef __cplusplus
}
#endif
#endif 

/* unified sys/types.h: 
   start with sef's sysvi386 version.
   merge go32 version -- a few ifdefs.
   h8300hms, h8300xray, and sysvnecv70 disagree on the following types:

   typedef int gid_t;
   typedef int uid_t;
   typedef int dev_t;
   typedef int ino_t;
   typedef int mode_t;
   typedef int caddr_t;

   however, these aren't "reasonable" values, the sysvi386 ones make far 
   more sense, and should work sufficiently well (in particular, h8300 
   doesn't have a stat, and the necv70 doesn't matter.) -- eichin
 */

#ifndef _SYS_TYPES_H
#define _SYS_TYPES_H

#if defined (_WIN32) || defined (__CYGWIN__)
#define __MS_types__
#endif

#ifdef __i386__
#if defined (GO32) || defined (__MSDOS__)
#define __MS_types__
#endif
#endif

/* gt4: stand-in for gcc's <stddef.h> (the compiler ships without headers). */
#ifndef _STDDEF_H
#define _STDDEF_H
typedef __SIZE_TYPE__ size_t;
typedef __PTRDIFF_TYPE__ ptrdiff_t;
#ifndef __cplusplus
typedef __WCHAR_TYPE__ wchar_t;
#endif
typedef unsigned int wint_t;
#ifndef NULL
#define NULL ((void *)0)
#endif
#define offsetof(t, m) ((size_t)&((t *)0)->m)
#endif

#ifndef	_MACHTYPES_H_
#define	_MACHTYPES_H_

#define	_CLOCK_T_	unsigned long		/* clock() */
#define	_TIME_T_	long			
#define _CLOCKID_T_ 	unsigned long
#define _TIMER_T_   	unsigned long

#endif	

#ifdef __GNUC__
#define _ST_INT32 __attribute__ ((__mode__ (__SI__)))
#else
#define _ST_INT32
#endif

# ifndef	_POSIX_SOURCE

#  define	physadr		physadr_t
#  define	quad		quad_t

#ifndef _WINSOCK_H
typedef	unsigned char	u_char;
typedef	unsigned short	u_short;
typedef	unsigned int	u_int;
typedef	unsigned long	u_long;
#endif

typedef	unsigned short	ushort;		
typedef	unsigned int	uint;		
# endif	

#ifndef __clock_t_defined
typedef _CLOCK_T_ clock_t;
#define __clock_t_defined
#endif

#ifndef __time_t_defined
typedef _TIME_T_ time_t;
#define __time_t_defined

struct timespec {
  time_t  tv_sec;   
  long    tv_nsec;  
};

struct itimerspec {
  struct timespec  it_interval;  
  struct timespec  it_value;     
};
#endif

typedef	long	daddr_t;
typedef	char *	caddr_t;

#ifdef __MS_types__
typedef	unsigned long	ino_t;
#else
#ifdef __sparc__
typedef	unsigned long	ino_t;
#else
typedef	unsigned short	ino_t;
#endif
#endif

#ifdef __MS_types__
typedef unsigned long vm_offset_t;
typedef unsigned long vm_size_t;

#define __BIT_TYPES_DEFINED__

typedef char int8_t;
typedef unsigned char u_int8_t;
typedef short int16_t;
typedef unsigned short u_int16_t;
typedef int int32_t;
typedef unsigned int u_int32_t;
typedef long long int64_t;
typedef unsigned long long u_int64_t;
typedef int32_t register_t;
#endif 

#if defined(__rtems__)

typedef unsigned long long dev_t;
#else
typedef	short	dev_t;
#endif

typedef	long	off_t;

typedef	unsigned short	uid_t;
typedef	unsigned short	gid_t;
typedef int pid_t;
typedef	long key_t;
typedef long ssize_t;

#ifdef __MS_types__
typedef	char *	addr_t;
typedef int mode_t;
#else
#if defined (__sparc__) && !defined (__sparc_v9__)
#ifdef __svr4__
typedef unsigned long mode_t;
#else
typedef unsigned short mode_t;
#endif
#else
typedef unsigned int mode_t _ST_INT32;
#endif
#endif 

typedef unsigned short nlink_t;

# if ! defined (_POSIX_SOURCE) && ! defined (_WINSOCK_H)

#  define	NBBY	8		

#  ifndef	FD_SETSIZE
#	define	FD_SETSIZE	64
#  endif

typedef	long	fd_mask;
#  define	NFDBITS	(sizeof (fd_mask) * NBBY)	
#  ifndef	howmany
#	define	howmany(x,y)	(((x)+((y)-1))/(y))
#  endif

typedef	struct _types_fd_set {
	fd_mask	fds_bits[howmany(FD_SETSIZE, NFDBITS)];
} _types_fd_set;

#define fd_set _types_fd_set

#  define	FD_SET(n, p)	((p)->fds_bits[(n)/NFDBITS] |= (1L << ((n) % NFDBITS)))
#  define	FD_CLR(n, p)	((p)->fds_bits[(n)/NFDBITS] &= ~(1L << ((n) % NFDBITS)))
#  define	FD_ISSET(n, p)	((p)->fds_bits[(n)/NFDBITS] & (1L << ((n) % NFDBITS)))
#  define	FD_ZERO(p)	(__extension__ (void)({ \
     size_t __i; \
     char *__tmp = (char *)p; \
     for (__i = 0; __i < sizeof (*(p)); ++__i) \
       *__tmp++ = 0; \
}))

# endif	

#undef __MS_types__
#undef _ST_INT32

#if defined(__rtems__)

#ifndef __clockid_t_defined
typedef _CLOCKID_T_ clockid_t;
#define __clockid_t_defined
#endif

#ifndef __timer_t_defined
typedef _TIMER_T_ timer_t;
#define __timer_t_defined
#endif

/*
 *  Written by Joel Sherrill <joel@OARcorp.com>.
 *
 *  COPYRIGHT (c) 1989-2000.
 *
 *  On-Line Applications Research Corporation (OAR).
 *
 *  Permission to use, copy, modify, and distribute this software for any
 *  purpose without fee is hereby granted, provided that this entire notice
 *  is included in all copies of any software which is or includes a copy
 *  or modification of this software.
 *
 *  THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 *  WARRANTY.  IN PARTICULAR,  THE AUTHOR MAKES NO REPRESENTATION
 *  OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY OF THIS
 *  SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 *  $Id: features.h,v 1.1 2000/12/12 01:24:08 jjohnstn Exp $
 */

#ifndef _SYS_FEATURES_H
#define _SYS_FEATURES_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __rtems__
#define _POSIX_JOB_CONTROL     		1
#define _POSIX_SAVED_IDS       		1
#define _POSIX_VERSION			199309L
#define _POSIX_ASYNCHRONOUS_IO		1
#define _POSIX_FSYNC			1
#define _POSIX_MAPPED_FILES		1
#define _POSIX_MEMLOCK			1
#define _POSIX_MEMLOCK_RANGE		1
#define _POSIX_MEMORY_PROTECTION	1
#define _POSIX_MESSAGE_PASSING		1
#define _POSIX_PRIORITIZED_IO		1
#define _POSIX_PRIORITY_SCHEDULING	1
#define _POSIX_REALTIME_SIGNALS		1
#define _POSIX_SEMAPHORES		1
#define _POSIX_SHARED_MEMORY_OBJECTS	1
#define _POSIX_SYNCHRONIZED_IO		1
#define _POSIX_TIMERS			1

#define _POSIX_THREADS				1
#define _POSIX_THREAD_ATTR_STACKADDR		1
#define _POSIX_THREAD_ATTR_STACKSIZE		1
#define _POSIX_THREAD_PRIORITY_SCHEDULING	1
#define _POSIX_THREAD_PRIO_INHERIT		1
#define _POSIX_THREAD_PRIO_PROTECT		1
#define _POSIX_THREAD_PROCESS_SHARED		1
#define _POSIX_THREAD_SAFE_FUNCTIONS		1

#define _POSIX_SPAWN				1
#define _POSIX_TIMEOUTS				1
#define _POSIX_CPUTIME				1
#define _POSIX_THREAD_CPUTIME			1
#define _POSIX_SPORADIC_SERVER			1
#define _POSIX_THREAD_SPORADIC_SERVER		1
#define _POSIX_DEVICE_CONTROL			1
#define _POSIX_DEVCTL_DIRECTION			1
#define _POSIX_INTERRUPT_CONTROL		1
#define _POSIX_ADVISORY_INFO			1

#endif

#ifdef __svr4__
# define _POSIX_JOB_CONTROL     1
# define _POSIX_SAVED_IDS       1
# define _POSIX_VERSION 199009L
#endif

#ifdef __CYGWIN32__
# define _POSIX_JOB_CONTROL	1
# define _POSIX_SAVED_IDS	0
# define _POSIX_VERSION		199009L
#endif

#ifdef __cplusplus
}
#endif
#endif 

#if defined(_POSIX_THREADS)

/*
 *  Written by Joel Sherrill <joel@OARcorp.com>.
 *
 *  COPYRIGHT (c) 1989-2000.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  Permission to use, copy, modify, and distribute this software for any
 *  purpose without fee is hereby granted, provided that this entire notice
 *  is included in all copies of any software which is or includes a copy
 *  or modification of this software.
 *
 *  THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 *  WARRANTY.  IN PARTICULAR,  THE AUTHOR MAKES NO REPRESENTATION
 *  OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY OF THIS
 *  SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 *  $Id: sched.h,v 1.1 2000/12/12 01:24:08 jjohnstn Exp $
 */

#ifndef __POSIX_SYS_SCHEDULING_h
#define __POSIX_SYS_SCHEDULING_h

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _SYS_UNISTD_H
#define _SYS_UNISTD_H

#ifdef __cplusplus
extern "C" {
#endif

#include <_ansi.h>
#include <sys/types.h>
#define __need_size_t
#define __need_ptrdiff_t
#include <stddef.h>

extern char **environ;

void	_EXFUN(_exit, (int __status ) _ATTRIBUTE ((noreturn)));

int	_EXFUN(access,(const char *__path, int __amode ));
unsigned  _EXFUN(alarm, (unsigned __secs ));
int     _EXFUN(chdir, (const char *__path ));
int     _EXFUN(chmod, (const char *__path, mode_t __mode ));
int     _EXFUN(chown, (const char *__path, uid_t __owner, gid_t __group ));
#ifdef __CYGWIN__
int     _EXFUN(chroot, (const char *__path ));
#endif
int     _EXFUN(close, (int __fildes ));
char    _EXFUN(*ctermid, (char *__s ));
char    _EXFUN(*cuserid, (char *__s ));
int     _EXFUN(dup, (int __fildes ));
int     _EXFUN(dup2, (int __fildes, int __fildes2 ));
int     _EXFUN(execl, (const char *__path, const char *, ... ));
int     _EXFUN(execle, (const char *__path, const char *, ... ));
int     _EXFUN(execlp, (const char *__file, const char *, ... ));
int     _EXFUN(execv, (const char *__path, char * const __argv[] ));
int     _EXFUN(execve, (const char *__path, char * const __argv[], char * const __envp[] ));
int     _EXFUN(execvp, (const char *__file, char * const __argv[] ));
int     _EXFUN(fchmod, (int __fildes, mode_t __mode ));
int     _EXFUN(fchown, (int __fildes, uid_t __owner, gid_t __group ));
pid_t   _EXFUN(fork, (void ));
long    _EXFUN(fpathconf, (int __fd, int __name ));
int     _EXFUN(fsync, (int __fd));
char    _EXFUN(*getcwd, (char *__buf, size_t __size ));
gid_t   _EXFUN(getegid, (void ));
uid_t   _EXFUN(geteuid, (void ));
gid_t   _EXFUN(getgid, (void ));
int     _EXFUN(getgroups, (int __gidsetsize, gid_t __grouplist[] ));
char    _EXFUN(*getlogin, (void ));
#if defined(_POSIX_THREAD_SAFE_FUNCTIONS)
int _EXFUN(getlogin_r, (char *name, size_t namesize) );
#endif
char 	_EXFUN(*getpass, (__const char *__prompt));
size_t  _EXFUN(getpagesize, (void));
pid_t   _EXFUN(getpgrp, (void ));
pid_t   _EXFUN(getpid, (void ));
pid_t   _EXFUN(getppid, (void ));
uid_t   _EXFUN(getuid, (void ));
#ifdef __CYGWIN__
char    _EXFUN(*getwd, (char *__buf ));
#endif
int     _EXFUN(isatty, (int __fildes ));
int     _EXFUN(lchown, (const char *__path, uid_t __owner, gid_t __group ));
int     _EXFUN(link, (const char *__path1, const char *__path2 ));
int	_EXFUN(nice, (int __nice_value ));
off_t   _EXFUN(lseek, (int __fildes, off_t __offset, int __whence ));
long    _EXFUN(pathconf, (const char *__path, int __name ));
int     _EXFUN(pause, (void ));
int     _EXFUN(pipe, (int __fildes[2] ));
/* POSIX 1003.1b-1993 says read() returns ssize_t */
#if defined(__rtems__)
ssize_t	_EXFUN(read, (int __fildes, void *__buf, size_t __nbyte ));
#else
int	_EXFUN(read, (int __fildes, void *__buf, size_t __nbyte ));
#endif
int     _EXFUN(rmdir, (const char *__path ));
#if defined(__rtems__)
void *  _EXFUN(sbrk,  (ptrdiff_t __incr));
#else
void *  _EXFUN(sbrk,  (size_t __incr));
#endif
#if defined(__CYGWIN__)
int     _EXFUN(setegid, (gid_t __gid ));
int     _EXFUN(seteuid, (uid_t __uid ));
#endif
int     _EXFUN(setgid, (gid_t __gid ));
int     _EXFUN(setpgid, (pid_t __pid, pid_t __pgid ));
pid_t   _EXFUN(setsid, (void ));
int     _EXFUN(setuid, (uid_t __uid ));
unsigned _EXFUN(sleep, (unsigned int __seconds ));
void    _EXFUN(swab, (const void *, void *, ssize_t));
long    _EXFUN(sysconf, (int __name ));
pid_t   _EXFUN(tcgetpgrp, (int __fildes ));
int     _EXFUN(tcsetpgrp, (int __fildes, pid_t __pgrp_id ));
char    _EXFUN(*ttyname, (int __fildes ));
int     _EXFUN(unlink, (const char *__path ));

#if defined(__rtems__)
ssize_t     _EXFUN(write, (int __fildes, const void *__buf, size_t __nbyte ));
#else
int     _EXFUN(write, (int __fildes, const void *__buf, size_t __nbyte ));
#endif

#ifndef        _POSIX_SOURCE
pid_t   _EXFUN(vfork, (void ));
#endif 

int     _EXFUN(_close, (int __fildes ));
pid_t   _EXFUN(_fork, (void ));
pid_t   _EXFUN(_getpid, (void ));
int     _EXFUN(_link, (const char *__path1, const char *__path2 ));
off_t   _EXFUN(_lseek, (int __fildes, off_t __offset, int __whence ));
int     _EXFUN(_read, (int __fildes, void *__buf, size_t __nbyte ));
void *  _EXFUN(_sbrk,  (size_t __incr));
int     _EXFUN(_unlink, (const char *__path ));
int     _EXFUN(_write, (int __fildes, const void *__buf, size_t __nbyte ));
int     _EXFUN(_execve, (const char *__path, char * const __argv[], char * const __envp[] ));

#if defined(__CYGWIN__) || defined(__rtems__)
int	_EXFUN(getdtablesize, (void));
void	_EXFUN(setdtablesize, (int));
unsigned _EXFUN(usleep, (unsigned int __useconds));
int     _EXFUN(ftruncate, (int __fd, off_t __length));
int     _EXFUN(truncate, (const char *, off_t __length));
int	_EXFUN(gethostname, (char *__name, size_t __len));
char *	_EXFUN(mktemp, (char *));
int     _EXFUN(sync, (void));
int     _EXFUN(readlink, (const char *__path, char *__buf, int __buflen));
int     _EXFUN(symlink, (const char *__name1, const char *__name2));
#endif

# define	F_OK	0
# define	R_OK	4
# define	W_OK	2
# define	X_OK	1

# define	SEEK_SET	0
# define	SEEK_CUR	1
# define	SEEK_END	2

#include <sys/features.h>

#define STDIN_FILENO    0       
#define STDOUT_FILENO   1       
#define STDERR_FILENO   2       

long _EXFUN(sysconf, (int __name));

#define _SC_ARG_MAX                 0
#define _SC_CHILD_MAX               1
#define _SC_CLK_TCK                 2
#define _SC_NGROUPS_MAX             3
#define _SC_OPEN_MAX                4
  
#define _SC_JOB_CONTROL             5
#define _SC_SAVED_IDS               6
#define _SC_VERSION                 7
#define _SC_PAGESIZE                8

#define _SC_NPROCESSORS_CONF        9
#define _SC_NPROCESSORS_ONLN       10
#define _SC_PHYS_PAGES             11
#define _SC_AVPHYS_PAGES           12

#define _SC_MQ_OPEN_MAX            13
#define _SC_MQ_PRIO_MAX            14
#define _SC_RTSIG_MAX              15
#define _SC_SEM_NSEMS_MAX          16
#define _SC_SEM_VALUE_MAX          17
#define _SC_SIGQUEUE_MAX           18
#define _SC_TIMER_MAX              19
#define _SC_TZNAME_MAX             20

#define _SC_ASYNCHRONOUS_IO        21
#define _SC_FSYNC                  22
#define _SC_MAPPED_FILES           23
#define _SC_MEMLOCK                24
#define _SC_MEMLOCK_RANGE          25
#define _SC_MEMORY_PROTECTION      26
#define _SC_MESSAGE_PASSING        27
#define _SC_PRIORITIZED_IO         28
#define _SC_REALTIME_SIGNALS       29
#define _SC_SEMAPHORES             30
#define _SC_SHARED_MEMORY_OBJECTS  31
#define _SC_SYNCHRONIZED_IO        32
#define _SC_TIMERS                 33
#define _SC_AIO_LISTIO_MAX         34
#define _SC_AIO_MAX                35
#define _SC_AIO_PRIO_DELTA_MAX     36
#define _SC_DELAYTIMER_MAX         37

#define _SC_THREAD_KEYS_MAX              38
#define _SC_THREAD_STACK_MIN             39
#define _SC_THREAD_THREADS_MAX           40
#define _SC_TTY_NAME_MAX                 41

#define _SC_THREADS                      42
#define _SC_THREAD_ATTR_STACKADDR        43
#define _SC_THREAD_ATTR_STACKSIZE        44
#define _SC_THREAD_PRIORITY_SCHEDULING   45
#define _SC_THREAD_PRIO_INHERIT          46

#define _SC_THREAD_PRIO_PROTECT          47
#define _SC_THREAD_PRIO_CEILING          _SC_THREAD_PRIO_PROTECT
#define _SC_THREAD_PROCESS_SHARED        48
#define _SC_THREAD_SAFE_FUNCTIONS        49
#define _SC_GETGR_R_SIZE_MAX             50
#define _SC_GETPW_R_SIZE_MAX             51
#define _SC_LOGIN_NAME_MAX               52
#define _SC_THREAD_DESTRUCTOR_ITERATIONS 53
  
# define	_PC_LINK_MAX	        0
# define	_PC_MAX_CANON	        1
# define	_PC_MAX_INPUT	        2
# define	_PC_NAME_MAX	        3
# define	_PC_PATH_MAX	        4
# define	_PC_PIPE_BUF	        5
# define	_PC_CHOWN_RESTRICTED   	6
# define	_PC_NO_TRUNC	        7
# define	_PC_VDISABLE	        8
# define	_PC_ASYNC_IO            9
# define	_PC_PRIO_IO            10
# define	_PC_SYNC_IO            11

#ifdef __CYGWIN__
#define MAXPATHLEN (260 - 1 )
#else
# define	MAXPATHLEN	1024
#endif

#ifdef __cplusplus
}
#endif
#endif 

/* unified sys/types.h: 
   start with sef's sysvi386 version.
   merge go32 version -- a few ifdefs.
   h8300hms, h8300xray, and sysvnecv70 disagree on the following types:

   typedef int gid_t;
   typedef int uid_t;
   typedef int dev_t;
   typedef int ino_t;
   typedef int mode_t;
   typedef int caddr_t;

   however, these aren't "reasonable" values, the sysvi386 ones make far 
   more sense, and should work sufficiently well (in particular, h8300 
   doesn't have a stat, and the necv70 doesn't matter.) -- eichin
 */

#ifndef _SYS_TYPES_H
#define _SYS_TYPES_H

#if defined (_WIN32) || defined (__CYGWIN__)
#define __MS_types__
#endif

#ifdef __i386__
#if defined (GO32) || defined (__MSDOS__)
#define __MS_types__
#endif
#endif

# include <stddef.h>
# include <machine/types.h>

#ifdef __GNUC__
#define _ST_INT32 __attribute__ ((__mode__ (__SI__)))
#else
#define _ST_INT32
#endif

# ifndef	_POSIX_SOURCE

#  define	physadr		physadr_t
#  define	quad		quad_t

#ifndef _WINSOCK_H
typedef	unsigned char	u_char;
typedef	unsigned short	u_short;
typedef	unsigned int	u_int;
typedef	unsigned long	u_long;
#endif

typedef	unsigned short	ushort;		
typedef	unsigned int	uint;		
# endif	

#ifndef __clock_t_defined
typedef _CLOCK_T_ clock_t;
#define __clock_t_defined
#endif

#ifndef __time_t_defined
typedef _TIME_T_ time_t;
#define __time_t_defined

struct timespec {
  time_t  tv_sec;   
  long    tv_nsec;  
};

struct itimerspec {
  struct timespec  it_interval;  
  struct timespec  it_value;     
};
#endif

typedef	long	daddr_t;
typedef	char *	caddr_t;

#ifdef __MS_types__
typedef	unsigned long	ino_t;
#else
#ifdef __sparc__
typedef	unsigned long	ino_t;
#else
typedef	unsigned short	ino_t;
#endif
#endif

#ifdef __MS_types__
typedef unsigned long vm_offset_t;
typedef unsigned long vm_size_t;

#define __BIT_TYPES_DEFINED__

typedef char int8_t;
typedef unsigned char u_int8_t;
typedef short int16_t;
typedef unsigned short u_int16_t;
typedef int int32_t;
typedef unsigned int u_int32_t;
typedef long long int64_t;
typedef unsigned long long u_int64_t;
typedef int32_t register_t;
#endif 

#if defined(__rtems__)

typedef unsigned long long dev_t;
#else
typedef	short	dev_t;
#endif

typedef	long	off_t;

typedef	unsigned short	uid_t;
typedef	unsigned short	gid_t;
typedef int pid_t;
typedef	long key_t;
typedef long ssize_t;

#ifdef __MS_types__
typedef	char *	addr_t;
typedef int mode_t;
#else
#if defined (__sparc__) && !defined (__sparc_v9__)
#ifdef __svr4__
typedef unsigned long mode_t;
#else
typedef unsigned short mode_t;
#endif
#else
typedef unsigned int mode_t _ST_INT32;
#endif
#endif 

typedef unsigned short nlink_t;

# if ! defined (_POSIX_SOURCE) && ! defined (_WINSOCK_H)

#  define	NBBY	8		

#  ifndef	FD_SETSIZE
#	define	FD_SETSIZE	64
#  endif

typedef	long	fd_mask;
#  define	NFDBITS	(sizeof (fd_mask) * NBBY)	
#  ifndef	howmany
#	define	howmany(x,y)	(((x)+((y)-1))/(y))
#  endif

typedef	struct _types_fd_set {
	fd_mask	fds_bits[howmany(FD_SETSIZE, NFDBITS)];
} _types_fd_set;

#define fd_set _types_fd_set

#  define	FD_SET(n, p)	((p)->fds_bits[(n)/NFDBITS] |= (1L << ((n) % NFDBITS)))
#  define	FD_CLR(n, p)	((p)->fds_bits[(n)/NFDBITS] &= ~(1L << ((n) % NFDBITS)))
#  define	FD_ISSET(n, p)	((p)->fds_bits[(n)/NFDBITS] & (1L << ((n) % NFDBITS)))
#  define	FD_ZERO(p)	(__extension__ (void)({ \
     size_t __i; \
     char *__tmp = (char *)p; \
     for (__i = 0; __i < sizeof (*(p)); ++__i) \
       *__tmp++ = 0; \
}))

# endif	

#undef __MS_types__
#undef _ST_INT32

#if defined(__rtems__)

#ifndef __clockid_t_defined
typedef _CLOCKID_T_ clockid_t;
#define __clockid_t_defined
#endif

#ifndef __timer_t_defined
typedef _TIMER_T_ timer_t;
#define __timer_t_defined
#endif

#include <sys/features.h>

#if defined(_POSIX_THREADS)

#include <sys/sched.h>

typedef __uint32_t pthread_t;            

#define PTHREAD_SCOPE_PROCESS 0
#define PTHREAD_SCOPE_SYSTEM  1

#define PTHREAD_INHERIT_SCHED  1      
                                      
                                      
#define PTHREAD_EXPLICIT_SCHED 2      

#define PTHREAD_CREATE_DETACHED 0
#define PTHREAD_CREATE_JOINABLE  1

typedef struct {
  int is_initialized;
  void *stackaddr;
  int stacksize;
  int contentionscope;
  int inheritsched;
  int schedpolicy;
  struct sched_param schedparam;

  
#if defined(_POSIX_THREAD_CPUTIME)
  int  cputime_clock_allowed;  
#endif
  int  detachstate;

} pthread_attr_t;

#if defined(_POSIX_THREAD_PROCESS_SHARED)

#define PTHREAD_PROCESS_PRIVATE 0 
#define PTHREAD_PROCESS_SHARED  1 
                                  
                                  
#endif

#if defined(_POSIX_THREAD_PRIO_PROTECT)

#define PTHREAD_PRIO_NONE    0
#define PTHREAD_PRIO_INHERIT 1
#define PTHREAD_PRIO_PROTECT 2
#endif

typedef __uint32_t pthread_mutex_t;      

typedef struct {
  int   is_initialized;
#if defined(_POSIX_THREAD_PROCESS_SHARED)
  int   process_shared;  
#endif
#if defined(_POSIX_THREAD_PRIO_PROTECT)
  int   prio_ceiling;
  int   protocol;
#endif
  int   recursive;
} pthread_mutexattr_t;

typedef __uint32_t pthread_cond_t;       

typedef struct {
  int   is_initialized;
#if defined(_POSIX_THREAD_PROCESS_SHARED)
  int   process_shared;       
#endif
} pthread_condattr_t;         

typedef __uint32_t pthread_key_t;        

typedef struct {
  int   is_initialized;  
  int   init_executed;   
} pthread_once_t;       

#endif 

#endif  

#endif	

/* time.h -- An implementation of the standard Unix <sys/time.h> file.
   Written by Geoffrey Noer <noer@cygnus.com>
   Public domain; no rights reserved. */

#ifndef _SYS_TIME_H_
#define _SYS_TIME_H_

#include <_ansi.h>
#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _WINSOCK_H
struct timeval {
  long tv_sec;
  long tv_usec;
};

struct timezone {
  int tz_minuteswest;
  int tz_dsttime;
};

#ifdef __CYGWIN__
#include <sys/select.h>
#endif 

#endif 

#define ITIMER_REAL     0
#define ITIMER_VIRTUAL  1
#define ITIMER_PROF     2

struct  itimerval {
  struct  timeval it_interval;
  struct  timeval it_value;
};

#if defined(__rtems__)

#define	timerisset(tvp)		((tvp)->tv_sec || (tvp)->tv_usec)
#define	timerclear(tvp)		((tvp)->tv_sec = (tvp)->tv_usec = 0)
#define	timercmp(a, b, CMP) 						      \
  (((a)->tv_sec == (b)->tv_sec) ? 					      \
   ((a)->tv_usec CMP (b)->tv_usec) : 					      \
   ((a)->tv_sec CMP (b)->tv_sec))
#define	timeradd(a, b, result)						      \
  do {									      \
    (result)->tv_sec = (a)->tv_sec + (b)->tv_sec;			      \
    (result)->tv_usec = (a)->tv_usec + (b)->tv_usec;			      \
    if ((result)->tv_usec >= 1000000)					      \
      {									      \
	++(result)->tv_sec;						      \
	(result)->tv_usec -= 1000000;					      \
      }									      \
  } while (0)
#define	timersub(a, b, result)						      \
  do {									      \
    (result)->tv_sec = (a)->tv_sec - (b)->tv_sec;			      \
    (result)->tv_usec = (a)->tv_usec - (b)->tv_usec;			      \
    if ((result)->tv_usec < 0) {					      \
      --(result)->tv_sec;						      \
      (result)->tv_usec += 1000000;					      \
    }									      \
  } while (0)
#endif

int _EXFUN(gettimeofday, (struct timeval *__p, struct timezone *__z));
int _EXFUN(settimeofday, (const struct timeval *, const struct timezone *));
int _EXFUN(utimes, (const char *__path, struct timeval *__tvp));
int _EXFUN(getitimer, (int __which, struct itimerval *__value));
int _EXFUN(setitimer, (int __which, const struct itimerval *__value,
					struct itimerval *__ovalue));

#ifdef __cplusplus
}
#endif
#endif 

#define SCHED_OTHER    0
#define SCHED_FIFO     1
#define SCHED_RR       2

#if defined(_POSIX_SPORADIC_SERVER)
#define SCHED_SPORADIC 3 
#endif

struct sched_param {
  int sched_priority;           

#if defined(_POSIX_SPORADIC_SERVER)
  int ss_low_priority;          
                                
  struct timespec ss_replenish_period; 
                                
  struct timespec ss_initial_budget;   
#endif
};

#ifdef __cplusplus
}
#endif 

#endif

typedef __uint32_t pthread_t;            

#define PTHREAD_SCOPE_PROCESS 0
#define PTHREAD_SCOPE_SYSTEM  1

#define PTHREAD_INHERIT_SCHED  1      
                                      
                                      
#define PTHREAD_EXPLICIT_SCHED 2      

#define PTHREAD_CREATE_DETACHED 0
#define PTHREAD_CREATE_JOINABLE  1

typedef struct {
  int is_initialized;
  void *stackaddr;
  int stacksize;
  int contentionscope;
  int inheritsched;
  int schedpolicy;
  struct sched_param schedparam;

  
#if defined(_POSIX_THREAD_CPUTIME)
  int  cputime_clock_allowed;  
#endif
  int  detachstate;

} pthread_attr_t;

#if defined(_POSIX_THREAD_PROCESS_SHARED)

#define PTHREAD_PROCESS_PRIVATE 0 
#define PTHREAD_PROCESS_SHARED  1 
                                  
                                  
#endif

#if defined(_POSIX_THREAD_PRIO_PROTECT)

#define PTHREAD_PRIO_NONE    0
#define PTHREAD_PRIO_INHERIT 1
#define PTHREAD_PRIO_PROTECT 2
#endif

typedef __uint32_t pthread_mutex_t;      

typedef struct {
  int   is_initialized;
#if defined(_POSIX_THREAD_PROCESS_SHARED)
  int   process_shared;  
#endif
#if defined(_POSIX_THREAD_PRIO_PROTECT)
  int   prio_ceiling;
  int   protocol;
#endif
  int   recursive;
} pthread_mutexattr_t;

typedef __uint32_t pthread_cond_t;       

typedef struct {
  int   is_initialized;
#if defined(_POSIX_THREAD_PROCESS_SHARED)
  int   process_shared;       
#endif
} pthread_condattr_t;         

typedef __uint32_t pthread_key_t;        

typedef struct {
  int   is_initialized;  
  int   init_executed;   
} pthread_once_t;       

#endif 

#endif  

#endif	

/* time.h -- An implementation of the standard Unix <sys/time.h> file.
   Written by Geoffrey Noer <noer@cygnus.com>
   Public domain; no rights reserved. */

#ifndef _SYS_TIME_H_
#define _SYS_TIME_H_

/* Provide support for both ANSI and non-ANSI environments.  */

#ifndef	_ANSIDECL_H_
#define	_ANSIDECL_H_

#ifndef __SYS_CONFIG_H__
#define __SYS_CONFIG_H__

/* exceptions first */

#if defined(__H8300__) || defined(__H8500__) || defined (__H8300H__) ||  defined(__W65__) || defined (__H8300S__)
#define _FLOAT_ARG float
#define __SMALL_BITFIELDS
#define _DOUBLE_IS_32BITS
#define __IEEE_BIG_ENDIAN

#define H8300 1
#endif

#ifdef __W65__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_BIG_ENDIAN
#undef INT_MAX
#undef UINT_MAX
#define INT_MAX 32767
#define UINT_MAX 65535

#endif

#if defined(__Z8001__) || defined(__Z8002__) || defined(__H8300__) || defined(__H8500__) || defined(__W65__) || defined (__H8300H__) || defined (__H8300S__) || defined (__mn10200__) || defined (__AVR__)

#undef INT_MAX
#undef UINT_MAX
#define INT_MAX 32767
#define UINT_MAX 65535
#endif

#if defined(__D10V__)
#undef INT_MAX
#undef UINT_MAX
#define INT_MAX __INT_MAX__
#define UINT_MAX (__INT_MAX__ * 2U + 1)
#define _DOUBLE_IS_32BITS
#define _POINTER_INT short
#define __IEEE_BIG_ENDIAN
#endif

#ifdef ___AM29K__
#define _FLOAT_RET double
#endif

#ifdef __i386__
#ifndef __unix__

#define _FLOAT_RET double
#endif
#endif

#ifdef __M32R__
#define __IEEE_BIG_ENDIAN
#endif

#ifdef __m68k__

#define __IEEE_BIG_ENDIAN
#endif

#ifdef __mn10300__
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __mn10200__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __AVR__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_LITTLE_ENDIAN
#define _POINTER_INT short
#endif

#ifdef __TIC80__
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __v850
#define __IEEE_LITTLE_ENDIAN
#define __ATTRIBUTE_IMPURE_PTR__ __attribute__((__sda__))
#endif

#ifdef __D30V__
#define __IEEE_BIG_ENDIAN
#endif

#if defined(__PPC__) && defined(_CALL_SYSV)
#define __ATTRIBUTE_IMPURE_PTR__ __attribute__((__section__(".sdata")))
#endif

#ifdef __sparc__
#ifdef __LITTLE_ENDIAN_DATA__
#define __IEEE_LITTLE_ENDIAN
#else
#define __IEEE_BIG_ENDIAN
#endif
#endif

#if INT_MAX == 32767
typedef long int __int32_t;
typedef unsigned long int __uint32_t;
#else
typedef int __int32_t;
typedef unsigned int __uint32_t;
#endif

#ifndef _POINTER_INT
#define _POINTER_INT long
#endif

#undef __RAND_MAX
#if INT_MAX == 32767
#define __RAND_MAX 32767
#else
#define __RAND_MAX 0x7fffffff
#endif

#if defined(__CYGWIN32__) || defined(__CYGWIN__)
#if defined(__INSIDE_CYGWIN__) || defined(_COMPILING_NEWLIB)
#define __IMPORT
#else
#define __IMPORT __declspec(dllimport)
#endif
#endif

#ifndef __IMPORT
#define __IMPORT
#endif

#endif 

#ifdef __STDC__
#define _HAVE_STDC
#endif

#ifdef _HAVE_STDC
#define	_PTR		void *
#define	_AND		,
#define	_NOARGS		void
#define	_CONST		const
#define	_VOLATILE	volatile
#define	_SIGNED		signed
#define	_DOTS		, ...
#define _VOID void
#ifdef __CYGWIN__
#define	_EXFUN(name, proto)		__cdecl name proto
#define	_EXPARM(name, proto)		(* __cdecl name) proto
#else
#define	_EXFUN(name, proto)		name proto
#define _EXPARM(name, proto)		(* name) proto
#endif
#define	_DEFUN(name, arglist, args)	name(args)
#define	_DEFUN_VOID(name)		name(_NOARGS)
#define _CAST_VOID (void)
#ifndef _LONG_DOUBLE
#define _LONG_DOUBLE long double
#endif
#ifndef _PARAMS
#define _PARAMS(paramlist)		paramlist
#endif
#else	
#define	_PTR		char *
#define	_AND		;
#define	_NOARGS
#define	_CONST
#define	_VOLATILE
#define	_SIGNED
#define	_DOTS
#define _VOID void
#define	_EXFUN(name, proto)		name()
#define	_DEFUN(name, arglist, args)	name arglist args;
#define	_DEFUN_VOID(name)		name()
#define _CAST_VOID
#define _LONG_DOUBLE double
#ifndef _PARAMS
#define _PARAMS(paramlist)		()
#endif
#endif

#ifdef __GNUC__
#define _ATTRIBUTE(attrs) __attribute__ (attrs)
#else
#define _ATTRIBUTE(attrs)
#endif

#endif 

/* unified sys/types.h: 
   start with sef's sysvi386 version.
   merge go32 version -- a few ifdefs.
   h8300hms, h8300xray, and sysvnecv70 disagree on the following types:

   typedef int gid_t;
   typedef int uid_t;
   typedef int dev_t;
   typedef int ino_t;
   typedef int mode_t;
   typedef int caddr_t;

   however, these aren't "reasonable" values, the sysvi386 ones make far 
   more sense, and should work sufficiently well (in particular, h8300 
   doesn't have a stat, and the necv70 doesn't matter.) -- eichin
 */

#ifndef _SYS_TYPES_H
#define _SYS_TYPES_H

#if defined (_WIN32) || defined (__CYGWIN__)
#define __MS_types__
#endif

#ifdef __i386__
#if defined (GO32) || defined (__MSDOS__)
#define __MS_types__
#endif
#endif

/* gt4: stand-in for gcc's <stddef.h> (the compiler ships without headers). */
#ifndef _STDDEF_H
#define _STDDEF_H
typedef __SIZE_TYPE__ size_t;
typedef __PTRDIFF_TYPE__ ptrdiff_t;
#ifndef __cplusplus
typedef __WCHAR_TYPE__ wchar_t;
#endif
typedef unsigned int wint_t;
#ifndef NULL
#define NULL ((void *)0)
#endif
#define offsetof(t, m) ((size_t)&((t *)0)->m)
#endif

#ifndef	_MACHTYPES_H_
#define	_MACHTYPES_H_

#define	_CLOCK_T_	unsigned long		/* clock() */
#define	_TIME_T_	long			
#define _CLOCKID_T_ 	unsigned long
#define _TIMER_T_   	unsigned long

#endif	

#ifdef __GNUC__
#define _ST_INT32 __attribute__ ((__mode__ (__SI__)))
#else
#define _ST_INT32
#endif

# ifndef	_POSIX_SOURCE

#  define	physadr		physadr_t
#  define	quad		quad_t

#ifndef _WINSOCK_H
typedef	unsigned char	u_char;
typedef	unsigned short	u_short;
typedef	unsigned int	u_int;
typedef	unsigned long	u_long;
#endif

typedef	unsigned short	ushort;		
typedef	unsigned int	uint;		
# endif	

#ifndef __clock_t_defined
typedef _CLOCK_T_ clock_t;
#define __clock_t_defined
#endif

#ifndef __time_t_defined
typedef _TIME_T_ time_t;
#define __time_t_defined

struct timespec {
  time_t  tv_sec;   
  long    tv_nsec;  
};

struct itimerspec {
  struct timespec  it_interval;  
  struct timespec  it_value;     
};
#endif

typedef	long	daddr_t;
typedef	char *	caddr_t;

#ifdef __MS_types__
typedef	unsigned long	ino_t;
#else
#ifdef __sparc__
typedef	unsigned long	ino_t;
#else
typedef	unsigned short	ino_t;
#endif
#endif

#ifdef __MS_types__
typedef unsigned long vm_offset_t;
typedef unsigned long vm_size_t;

#define __BIT_TYPES_DEFINED__

typedef char int8_t;
typedef unsigned char u_int8_t;
typedef short int16_t;
typedef unsigned short u_int16_t;
typedef int int32_t;
typedef unsigned int u_int32_t;
typedef long long int64_t;
typedef unsigned long long u_int64_t;
typedef int32_t register_t;
#endif 

#if defined(__rtems__)

typedef unsigned long long dev_t;
#else
typedef	short	dev_t;
#endif

typedef	long	off_t;

typedef	unsigned short	uid_t;
typedef	unsigned short	gid_t;
typedef int pid_t;
typedef	long key_t;
typedef long ssize_t;

#ifdef __MS_types__
typedef	char *	addr_t;
typedef int mode_t;
#else
#if defined (__sparc__) && !defined (__sparc_v9__)
#ifdef __svr4__
typedef unsigned long mode_t;
#else
typedef unsigned short mode_t;
#endif
#else
typedef unsigned int mode_t _ST_INT32;
#endif
#endif 

typedef unsigned short nlink_t;

# if ! defined (_POSIX_SOURCE) && ! defined (_WINSOCK_H)

#  define	NBBY	8		

#  ifndef	FD_SETSIZE
#	define	FD_SETSIZE	64
#  endif

typedef	long	fd_mask;
#  define	NFDBITS	(sizeof (fd_mask) * NBBY)	
#  ifndef	howmany
#	define	howmany(x,y)	(((x)+((y)-1))/(y))
#  endif

typedef	struct _types_fd_set {
	fd_mask	fds_bits[howmany(FD_SETSIZE, NFDBITS)];
} _types_fd_set;

#define fd_set _types_fd_set

#  define	FD_SET(n, p)	((p)->fds_bits[(n)/NFDBITS] |= (1L << ((n) % NFDBITS)))
#  define	FD_CLR(n, p)	((p)->fds_bits[(n)/NFDBITS] &= ~(1L << ((n) % NFDBITS)))
#  define	FD_ISSET(n, p)	((p)->fds_bits[(n)/NFDBITS] & (1L << ((n) % NFDBITS)))
#  define	FD_ZERO(p)	(__extension__ (void)({ \
     size_t __i; \
     char *__tmp = (char *)p; \
     for (__i = 0; __i < sizeof (*(p)); ++__i) \
       *__tmp++ = 0; \
}))

# endif	

#undef __MS_types__
#undef _ST_INT32

#if defined(__rtems__)

#ifndef __clockid_t_defined
typedef _CLOCKID_T_ clockid_t;
#define __clockid_t_defined
#endif

#ifndef __timer_t_defined
typedef _TIMER_T_ timer_t;
#define __timer_t_defined
#endif

/*
 *  Written by Joel Sherrill <joel@OARcorp.com>.
 *
 *  COPYRIGHT (c) 1989-2000.
 *
 *  On-Line Applications Research Corporation (OAR).
 *
 *  Permission to use, copy, modify, and distribute this software for any
 *  purpose without fee is hereby granted, provided that this entire notice
 *  is included in all copies of any software which is or includes a copy
 *  or modification of this software.
 *
 *  THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 *  WARRANTY.  IN PARTICULAR,  THE AUTHOR MAKES NO REPRESENTATION
 *  OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY OF THIS
 *  SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 *  $Id: features.h,v 1.1 2000/12/12 01:24:08 jjohnstn Exp $
 */

#ifndef _SYS_FEATURES_H
#define _SYS_FEATURES_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __rtems__
#define _POSIX_JOB_CONTROL     		1
#define _POSIX_SAVED_IDS       		1
#define _POSIX_VERSION			199309L
#define _POSIX_ASYNCHRONOUS_IO		1
#define _POSIX_FSYNC			1
#define _POSIX_MAPPED_FILES		1
#define _POSIX_MEMLOCK			1
#define _POSIX_MEMLOCK_RANGE		1
#define _POSIX_MEMORY_PROTECTION	1
#define _POSIX_MESSAGE_PASSING		1
#define _POSIX_PRIORITIZED_IO		1
#define _POSIX_PRIORITY_SCHEDULING	1
#define _POSIX_REALTIME_SIGNALS		1
#define _POSIX_SEMAPHORES		1
#define _POSIX_SHARED_MEMORY_OBJECTS	1
#define _POSIX_SYNCHRONIZED_IO		1
#define _POSIX_TIMERS			1

#define _POSIX_THREADS				1
#define _POSIX_THREAD_ATTR_STACKADDR		1
#define _POSIX_THREAD_ATTR_STACKSIZE		1
#define _POSIX_THREAD_PRIORITY_SCHEDULING	1
#define _POSIX_THREAD_PRIO_INHERIT		1
#define _POSIX_THREAD_PRIO_PROTECT		1
#define _POSIX_THREAD_PROCESS_SHARED		1
#define _POSIX_THREAD_SAFE_FUNCTIONS		1

#define _POSIX_SPAWN				1
#define _POSIX_TIMEOUTS				1
#define _POSIX_CPUTIME				1
#define _POSIX_THREAD_CPUTIME			1
#define _POSIX_SPORADIC_SERVER			1
#define _POSIX_THREAD_SPORADIC_SERVER		1
#define _POSIX_DEVICE_CONTROL			1
#define _POSIX_DEVCTL_DIRECTION			1
#define _POSIX_INTERRUPT_CONTROL		1
#define _POSIX_ADVISORY_INFO			1

#endif

#ifdef __svr4__
# define _POSIX_JOB_CONTROL     1
# define _POSIX_SAVED_IDS       1
# define _POSIX_VERSION 199009L
#endif

#ifdef __CYGWIN32__
# define _POSIX_JOB_CONTROL	1
# define _POSIX_SAVED_IDS	0
# define _POSIX_VERSION		199009L
#endif

#ifdef __cplusplus
}
#endif
#endif 

#if defined(_POSIX_THREADS)

/*
 *  Written by Joel Sherrill <joel@OARcorp.com>.
 *
 *  COPYRIGHT (c) 1989-2000.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  Permission to use, copy, modify, and distribute this software for any
 *  purpose without fee is hereby granted, provided that this entire notice
 *  is included in all copies of any software which is or includes a copy
 *  or modification of this software.
 *
 *  THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 *  WARRANTY.  IN PARTICULAR,  THE AUTHOR MAKES NO REPRESENTATION
 *  OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY OF THIS
 *  SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 *  $Id: sched.h,v 1.1 2000/12/12 01:24:08 jjohnstn Exp $
 */

#ifndef __POSIX_SYS_SCHEDULING_h
#define __POSIX_SYS_SCHEDULING_h

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/unistd.h>

#include <sys/types.h>
#include <sys/time.h>

#define SCHED_OTHER    0
#define SCHED_FIFO     1
#define SCHED_RR       2

#if defined(_POSIX_SPORADIC_SERVER)
#define SCHED_SPORADIC 3 
#endif

struct sched_param {
  int sched_priority;           

#if defined(_POSIX_SPORADIC_SERVER)
  int ss_low_priority;          
                                
  struct timespec ss_replenish_period; 
                                
  struct timespec ss_initial_budget;   
#endif
};

#ifdef __cplusplus
}
#endif 

#endif

typedef __uint32_t pthread_t;            

#define PTHREAD_SCOPE_PROCESS 0
#define PTHREAD_SCOPE_SYSTEM  1

#define PTHREAD_INHERIT_SCHED  1      
                                      
                                      
#define PTHREAD_EXPLICIT_SCHED 2      

#define PTHREAD_CREATE_DETACHED 0
#define PTHREAD_CREATE_JOINABLE  1

typedef struct {
  int is_initialized;
  void *stackaddr;
  int stacksize;
  int contentionscope;
  int inheritsched;
  int schedpolicy;
  struct sched_param schedparam;

  
#if defined(_POSIX_THREAD_CPUTIME)
  int  cputime_clock_allowed;  
#endif
  int  detachstate;

} pthread_attr_t;

#if defined(_POSIX_THREAD_PROCESS_SHARED)

#define PTHREAD_PROCESS_PRIVATE 0 
#define PTHREAD_PROCESS_SHARED  1 
                                  
                                  
#endif

#if defined(_POSIX_THREAD_PRIO_PROTECT)

#define PTHREAD_PRIO_NONE    0
#define PTHREAD_PRIO_INHERIT 1
#define PTHREAD_PRIO_PROTECT 2
#endif

typedef __uint32_t pthread_mutex_t;      

typedef struct {
  int   is_initialized;
#if defined(_POSIX_THREAD_PROCESS_SHARED)
  int   process_shared;  
#endif
#if defined(_POSIX_THREAD_PRIO_PROTECT)
  int   prio_ceiling;
  int   protocol;
#endif
  int   recursive;
} pthread_mutexattr_t;

typedef __uint32_t pthread_cond_t;       

typedef struct {
  int   is_initialized;
#if defined(_POSIX_THREAD_PROCESS_SHARED)
  int   process_shared;       
#endif
} pthread_condattr_t;         

typedef __uint32_t pthread_key_t;        

typedef struct {
  int   is_initialized;  
  int   init_executed;   
} pthread_once_t;       

#endif 

#endif  

#endif	

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _WINSOCK_H
struct timeval {
  long tv_sec;
  long tv_usec;
};

struct timezone {
  int tz_minuteswest;
  int tz_dsttime;
};

#ifdef __CYGWIN__
#include <sys/select.h>
#endif 

#endif 

#define ITIMER_REAL     0
#define ITIMER_VIRTUAL  1
#define ITIMER_PROF     2

struct  itimerval {
  struct  timeval it_interval;
  struct  timeval it_value;
};

#if defined(__rtems__)

#define	timerisset(tvp)		((tvp)->tv_sec || (tvp)->tv_usec)
#define	timerclear(tvp)		((tvp)->tv_sec = (tvp)->tv_usec = 0)
#define	timercmp(a, b, CMP) 						      \
  (((a)->tv_sec == (b)->tv_sec) ? 					      \
   ((a)->tv_usec CMP (b)->tv_usec) : 					      \
   ((a)->tv_sec CMP (b)->tv_sec))
#define	timeradd(a, b, result)						      \
  do {									      \
    (result)->tv_sec = (a)->tv_sec + (b)->tv_sec;			      \
    (result)->tv_usec = (a)->tv_usec + (b)->tv_usec;			      \
    if ((result)->tv_usec >= 1000000)					      \
      {									      \
	++(result)->tv_sec;						      \
	(result)->tv_usec -= 1000000;					      \
      }									      \
  } while (0)
#define	timersub(a, b, result)						      \
  do {									      \
    (result)->tv_sec = (a)->tv_sec - (b)->tv_sec;			      \
    (result)->tv_usec = (a)->tv_usec - (b)->tv_usec;			      \
    if ((result)->tv_usec < 0) {					      \
      --(result)->tv_sec;						      \
      (result)->tv_usec += 1000000;					      \
    }									      \
  } while (0)
#endif

int _EXFUN(gettimeofday, (struct timeval *__p, struct timezone *__z));
int _EXFUN(settimeofday, (const struct timeval *, const struct timezone *));
int _EXFUN(utimes, (const char *__path, struct timeval *__tvp));
int _EXFUN(getitimer, (int __which, struct itimerval *__value));
int _EXFUN(setitimer, (int __which, const struct itimerval *__value,
					struct itimerval *__ovalue));

#ifdef __cplusplus
}
#endif
#endif 

#define SCHED_OTHER    0
#define SCHED_FIFO     1
#define SCHED_RR       2

#if defined(_POSIX_SPORADIC_SERVER)
#define SCHED_SPORADIC 3 
#endif

struct sched_param {
  int sched_priority;           

#if defined(_POSIX_SPORADIC_SERVER)
  int ss_low_priority;          
                                
  struct timespec ss_replenish_period; 
                                
  struct timespec ss_initial_budget;   
#endif
};

#ifdef __cplusplus
}
#endif 

#endif

typedef __uint32_t pthread_t;            

#define PTHREAD_SCOPE_PROCESS 0
#define PTHREAD_SCOPE_SYSTEM  1

#define PTHREAD_INHERIT_SCHED  1      
                                      
                                      
#define PTHREAD_EXPLICIT_SCHED 2      

#define PTHREAD_CREATE_DETACHED 0
#define PTHREAD_CREATE_JOINABLE  1

typedef struct {
  int is_initialized;
  void *stackaddr;
  int stacksize;
  int contentionscope;
  int inheritsched;
  int schedpolicy;
  struct sched_param schedparam;

  
#if defined(_POSIX_THREAD_CPUTIME)
  int  cputime_clock_allowed;  
#endif
  int  detachstate;

} pthread_attr_t;

#if defined(_POSIX_THREAD_PROCESS_SHARED)

#define PTHREAD_PROCESS_PRIVATE 0 
#define PTHREAD_PROCESS_SHARED  1 
                                  
                                  
#endif

#if defined(_POSIX_THREAD_PRIO_PROTECT)

#define PTHREAD_PRIO_NONE    0
#define PTHREAD_PRIO_INHERIT 1
#define PTHREAD_PRIO_PROTECT 2
#endif

typedef __uint32_t pthread_mutex_t;      

typedef struct {
  int   is_initialized;
#if defined(_POSIX_THREAD_PROCESS_SHARED)
  int   process_shared;  
#endif
#if defined(_POSIX_THREAD_PRIO_PROTECT)
  int   prio_ceiling;
  int   protocol;
#endif
  int   recursive;
} pthread_mutexattr_t;

typedef __uint32_t pthread_cond_t;       

typedef struct {
  int   is_initialized;
#if defined(_POSIX_THREAD_PROCESS_SHARED)
  int   process_shared;       
#endif
} pthread_condattr_t;         

typedef __uint32_t pthread_key_t;        

typedef struct {
  int   is_initialized;  
  int   init_executed;   
} pthread_once_t;       

#endif 

#endif  

#endif	

struct tm
{
  int	tm_sec;
  int	tm_min;
  int	tm_hour;
  int	tm_mday;
  int	tm_mon;
  int	tm_year;
  int	tm_wday;
  int	tm_yday;
  int	tm_isdst;
};

clock_t	   _EXFUN(clock,    (void));
double	   _EXFUN(difftime, (time_t _time2, time_t _time1));
time_t	   _EXFUN(mktime,   (struct tm *_timeptr));
time_t	   _EXFUN(time,     (time_t *_timer));
#ifndef _REENT_ONLY
char	  *_EXFUN(asctime,  (const struct tm *_tblock));
char	  *_EXFUN(ctime,    (const time_t *_time));
struct tm *_EXFUN(gmtime,   (const time_t *_timer));
struct tm *_EXFUN(localtime,(const time_t *_timer));
#endif
size_t	   _EXFUN(strftime, (char *_s, size_t _maxsize, const char *_fmt, const struct tm *_t));

char	  *_EXFUN(asctime_r,	(const struct tm *, char *));
char	  *_EXFUN(ctime_r,	(const time_t *, char *));
struct tm *_EXFUN(gmtime_r,	(const time_t *, struct tm *));
struct tm *_EXFUN(localtime_r,	(const time_t *, struct tm *));

#ifdef __CYGWIN__
#ifndef __STRICT_ANSI__
extern __IMPORT time_t _timezone;
extern __IMPORT int _daylight;
extern __IMPORT char *_tzname[2];

char *_EXFUN(timezone, (void));
void _EXFUN(tzset, (void));
#endif
#endif 

/*
 *  Written by Joel Sherrill <joel@OARcorp.com>.
 *
 *  COPYRIGHT (c) 1989-2000.
 *
 *  On-Line Applications Research Corporation (OAR).
 *
 *  Permission to use, copy, modify, and distribute this software for any
 *  purpose without fee is hereby granted, provided that this entire notice
 *  is included in all copies of any software which is or includes a copy
 *  or modification of this software.
 *
 *  THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 *  WARRANTY.  IN PARTICULAR,  THE AUTHOR MAKES NO REPRESENTATION
 *  OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY OF THIS
 *  SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 *  $Id: features.h,v 1.1 2000/12/12 01:24:08 jjohnstn Exp $
 */

#ifndef _SYS_FEATURES_H
#define _SYS_FEATURES_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __rtems__
#define _POSIX_JOB_CONTROL     		1
#define _POSIX_SAVED_IDS       		1
#define _POSIX_VERSION			199309L
#define _POSIX_ASYNCHRONOUS_IO		1
#define _POSIX_FSYNC			1
#define _POSIX_MAPPED_FILES		1
#define _POSIX_MEMLOCK			1
#define _POSIX_MEMLOCK_RANGE		1
#define _POSIX_MEMORY_PROTECTION	1
#define _POSIX_MESSAGE_PASSING		1
#define _POSIX_PRIORITIZED_IO		1
#define _POSIX_PRIORITY_SCHEDULING	1
#define _POSIX_REALTIME_SIGNALS		1
#define _POSIX_SEMAPHORES		1
#define _POSIX_SHARED_MEMORY_OBJECTS	1
#define _POSIX_SYNCHRONIZED_IO		1
#define _POSIX_TIMERS			1

#define _POSIX_THREADS				1
#define _POSIX_THREAD_ATTR_STACKADDR		1
#define _POSIX_THREAD_ATTR_STACKSIZE		1
#define _POSIX_THREAD_PRIORITY_SCHEDULING	1
#define _POSIX_THREAD_PRIO_INHERIT		1
#define _POSIX_THREAD_PRIO_PROTECT		1
#define _POSIX_THREAD_PROCESS_SHARED		1
#define _POSIX_THREAD_SAFE_FUNCTIONS		1

#define _POSIX_SPAWN				1
#define _POSIX_TIMEOUTS				1
#define _POSIX_CPUTIME				1
#define _POSIX_THREAD_CPUTIME			1
#define _POSIX_SPORADIC_SERVER			1
#define _POSIX_THREAD_SPORADIC_SERVER		1
#define _POSIX_DEVICE_CONTROL			1
#define _POSIX_DEVCTL_DIRECTION			1
#define _POSIX_INTERRUPT_CONTROL		1
#define _POSIX_ADVISORY_INFO			1

#endif

#ifdef __svr4__
# define _POSIX_JOB_CONTROL     1
# define _POSIX_SAVED_IDS       1
# define _POSIX_VERSION 199009L
#endif

#ifdef __CYGWIN32__
# define _POSIX_JOB_CONTROL	1
# define _POSIX_SAVED_IDS	0
# define _POSIX_VERSION		199009L
#endif

#ifdef __cplusplus
}
#endif
#endif 

#if defined(_POSIX_TIMERS)

#ifndef _SIGNAL_H_
#ifdef __cplusplus
extern "C" {
#endif
#define _SIGNAL_H_

/* Provide support for both ANSI and non-ANSI environments.  */

#ifndef	_ANSIDECL_H_
#define	_ANSIDECL_H_

#ifndef __SYS_CONFIG_H__
#define __SYS_CONFIG_H__

/* exceptions first */

#if defined(__H8300__) || defined(__H8500__) || defined (__H8300H__) ||  defined(__W65__) || defined (__H8300S__)
#define _FLOAT_ARG float
#define __SMALL_BITFIELDS
#define _DOUBLE_IS_32BITS
#define __IEEE_BIG_ENDIAN

#define H8300 1
#endif

#ifdef __W65__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_BIG_ENDIAN
#undef INT_MAX
#undef UINT_MAX
#define INT_MAX 32767
#define UINT_MAX 65535

#endif

#if defined(__Z8001__) || defined(__Z8002__) || defined(__H8300__) || defined(__H8500__) || defined(__W65__) || defined (__H8300H__) || defined (__H8300S__) || defined (__mn10200__) || defined (__AVR__)

#undef INT_MAX
#undef UINT_MAX
#define INT_MAX 32767
#define UINT_MAX 65535
#endif

#if defined(__D10V__)
#undef INT_MAX
#undef UINT_MAX
#define INT_MAX __INT_MAX__
#define UINT_MAX (__INT_MAX__ * 2U + 1)
#define _DOUBLE_IS_32BITS
#define _POINTER_INT short
#define __IEEE_BIG_ENDIAN
#endif

#ifdef ___AM29K__
#define _FLOAT_RET double
#endif

#ifdef __i386__
#ifndef __unix__

#define _FLOAT_RET double
#endif
#endif

#ifdef __M32R__
#define __IEEE_BIG_ENDIAN
#endif

#ifdef __m68k__

#define __IEEE_BIG_ENDIAN
#endif

#ifdef __mn10300__
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __mn10200__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __AVR__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_LITTLE_ENDIAN
#define _POINTER_INT short
#endif

#ifdef __TIC80__
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __v850
#define __IEEE_LITTLE_ENDIAN
#define __ATTRIBUTE_IMPURE_PTR__ __attribute__((__sda__))
#endif

#ifdef __D30V__
#define __IEEE_BIG_ENDIAN
#endif

#if defined(__PPC__) && defined(_CALL_SYSV)
#define __ATTRIBUTE_IMPURE_PTR__ __attribute__((__section__(".sdata")))
#endif

#ifdef __sparc__
#ifdef __LITTLE_ENDIAN_DATA__
#define __IEEE_LITTLE_ENDIAN
#else
#define __IEEE_BIG_ENDIAN
#endif
#endif

#if INT_MAX == 32767
typedef long int __int32_t;
typedef unsigned long int __uint32_t;
#else
typedef int __int32_t;
typedef unsigned int __uint32_t;
#endif

#ifndef _POINTER_INT
#define _POINTER_INT long
#endif

#undef __RAND_MAX
#if INT_MAX == 32767
#define __RAND_MAX 32767
#else
#define __RAND_MAX 0x7fffffff
#endif

#if defined(__CYGWIN32__) || defined(__CYGWIN__)
#if defined(__INSIDE_CYGWIN__) || defined(_COMPILING_NEWLIB)
#define __IMPORT
#else
#define __IMPORT __declspec(dllimport)
#endif
#endif

#ifndef __IMPORT
#define __IMPORT
#endif

#endif 

#ifdef __STDC__
#define _HAVE_STDC
#endif

#ifdef _HAVE_STDC
#define	_PTR		void *
#define	_AND		,
#define	_NOARGS		void
#define	_CONST		const
#define	_VOLATILE	volatile
#define	_SIGNED		signed
#define	_DOTS		, ...
#define _VOID void
#ifdef __CYGWIN__
#define	_EXFUN(name, proto)		__cdecl name proto
#define	_EXPARM(name, proto)		(* __cdecl name) proto
#else
#define	_EXFUN(name, proto)		name proto
#define _EXPARM(name, proto)		(* name) proto
#endif
#define	_DEFUN(name, arglist, args)	name(args)
#define	_DEFUN_VOID(name)		name(_NOARGS)
#define _CAST_VOID (void)
#ifndef _LONG_DOUBLE
#define _LONG_DOUBLE long double
#endif
#ifndef _PARAMS
#define _PARAMS(paramlist)		paramlist
#endif
#else	
#define	_PTR		char *
#define	_AND		;
#define	_NOARGS
#define	_CONST
#define	_VOLATILE
#define	_SIGNED
#define	_DOTS
#define _VOID void
#define	_EXFUN(name, proto)		name()
#define	_DEFUN(name, arglist, args)	name arglist args;
#define	_DEFUN_VOID(name)		name()
#define _CAST_VOID
#define _LONG_DOUBLE double
#ifndef _PARAMS
#define _PARAMS(paramlist)		()
#endif
#endif

#ifdef __GNUC__
#define _ATTRIBUTE(attrs) __attribute__ (attrs)
#else
#define _ATTRIBUTE(attrs)
#endif

#endif 

/* sys/signal.h */

#ifndef _SYS_SIGNAL_H
#define _SYS_SIGNAL_H

#ifdef __cplusplus
extern "C" {
#endif

/* Provide support for both ANSI and non-ANSI environments.  */

#ifndef	_ANSIDECL_H_
#define	_ANSIDECL_H_

#ifndef __SYS_CONFIG_H__
#define __SYS_CONFIG_H__

/* exceptions first */

#if defined(__H8300__) || defined(__H8500__) || defined (__H8300H__) ||  defined(__W65__) || defined (__H8300S__)
#define _FLOAT_ARG float
#define __SMALL_BITFIELDS
#define _DOUBLE_IS_32BITS
#define __IEEE_BIG_ENDIAN

#define H8300 1
#endif

#ifdef __W65__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_BIG_ENDIAN
#undef INT_MAX
#undef UINT_MAX
#define INT_MAX 32767
#define UINT_MAX 65535

#endif

#if defined(__Z8001__) || defined(__Z8002__) || defined(__H8300__) || defined(__H8500__) || defined(__W65__) || defined (__H8300H__) || defined (__H8300S__) || defined (__mn10200__) || defined (__AVR__)

#undef INT_MAX
#undef UINT_MAX
#define INT_MAX 32767
#define UINT_MAX 65535
#endif

#if defined(__D10V__)
#undef INT_MAX
#undef UINT_MAX
#define INT_MAX __INT_MAX__
#define UINT_MAX (__INT_MAX__ * 2U + 1)
#define _DOUBLE_IS_32BITS
#define _POINTER_INT short
#define __IEEE_BIG_ENDIAN
#endif

#ifdef ___AM29K__
#define _FLOAT_RET double
#endif

#ifdef __i386__
#ifndef __unix__

#define _FLOAT_RET double
#endif
#endif

#ifdef __M32R__
#define __IEEE_BIG_ENDIAN
#endif

#ifdef __m68k__

#define __IEEE_BIG_ENDIAN
#endif

#ifdef __mn10300__
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __mn10200__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __AVR__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_LITTLE_ENDIAN
#define _POINTER_INT short
#endif

#ifdef __TIC80__
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __v850
#define __IEEE_LITTLE_ENDIAN
#define __ATTRIBUTE_IMPURE_PTR__ __attribute__((__sda__))
#endif

#ifdef __D30V__
#define __IEEE_BIG_ENDIAN
#endif

#if defined(__PPC__) && defined(_CALL_SYSV)
#define __ATTRIBUTE_IMPURE_PTR__ __attribute__((__section__(".sdata")))
#endif

#ifdef __sparc__
#ifdef __LITTLE_ENDIAN_DATA__
#define __IEEE_LITTLE_ENDIAN
#else
#define __IEEE_BIG_ENDIAN
#endif
#endif

#if INT_MAX == 32767
typedef long int __int32_t;
typedef unsigned long int __uint32_t;
#else
typedef int __int32_t;
typedef unsigned int __uint32_t;
#endif

#ifndef _POINTER_INT
#define _POINTER_INT long
#endif

#undef __RAND_MAX
#if INT_MAX == 32767
#define __RAND_MAX 32767
#else
#define __RAND_MAX 0x7fffffff
#endif

#if defined(__CYGWIN32__) || defined(__CYGWIN__)
#if defined(__INSIDE_CYGWIN__) || defined(_COMPILING_NEWLIB)
#define __IMPORT
#else
#define __IMPORT __declspec(dllimport)
#endif
#endif

#ifndef __IMPORT
#define __IMPORT
#endif

#endif 

#ifdef __STDC__
#define _HAVE_STDC
#endif

#ifdef _HAVE_STDC
#define	_PTR		void *
#define	_AND		,
#define	_NOARGS		void
#define	_CONST		const
#define	_VOLATILE	volatile
#define	_SIGNED		signed
#define	_DOTS		, ...
#define _VOID void
#ifdef __CYGWIN__
#define	_EXFUN(name, proto)		__cdecl name proto
#define	_EXPARM(name, proto)		(* __cdecl name) proto
#else
#define	_EXFUN(name, proto)		name proto
#define _EXPARM(name, proto)		(* name) proto
#endif
#define	_DEFUN(name, arglist, args)	name(args)
#define	_DEFUN_VOID(name)		name(_NOARGS)
#define _CAST_VOID (void)
#ifndef _LONG_DOUBLE
#define _LONG_DOUBLE long double
#endif
#ifndef _PARAMS
#define _PARAMS(paramlist)		paramlist
#endif
#else	
#define	_PTR		char *
#define	_AND		;
#define	_NOARGS
#define	_CONST
#define	_VOLATILE
#define	_SIGNED
#define	_DOTS
#define _VOID void
#define	_EXFUN(name, proto)		name()
#define	_DEFUN(name, arglist, args)	name arglist args;
#define	_DEFUN_VOID(name)		name()
#define _CAST_VOID
#define _LONG_DOUBLE double
#ifndef _PARAMS
#define _PARAMS(paramlist)		()
#endif
#endif

#ifdef __GNUC__
#define _ATTRIBUTE(attrs) __attribute__ (attrs)
#else
#define _ATTRIBUTE(attrs)
#endif

#endif 

/*
 *  Written by Joel Sherrill <joel@OARcorp.com>.
 *
 *  COPYRIGHT (c) 1989-2000.
 *
 *  On-Line Applications Research Corporation (OAR).
 *
 *  Permission to use, copy, modify, and distribute this software for any
 *  purpose without fee is hereby granted, provided that this entire notice
 *  is included in all copies of any software which is or includes a copy
 *  or modification of this software.
 *
 *  THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 *  WARRANTY.  IN PARTICULAR,  THE AUTHOR MAKES NO REPRESENTATION
 *  OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY OF THIS
 *  SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 *  $Id: features.h,v 1.1 2000/12/12 01:24:08 jjohnstn Exp $
 */

#ifndef _SYS_FEATURES_H
#define _SYS_FEATURES_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __rtems__
#define _POSIX_JOB_CONTROL     		1
#define _POSIX_SAVED_IDS       		1
#define _POSIX_VERSION			199309L
#define _POSIX_ASYNCHRONOUS_IO		1
#define _POSIX_FSYNC			1
#define _POSIX_MAPPED_FILES		1
#define _POSIX_MEMLOCK			1
#define _POSIX_MEMLOCK_RANGE		1
#define _POSIX_MEMORY_PROTECTION	1
#define _POSIX_MESSAGE_PASSING		1
#define _POSIX_PRIORITIZED_IO		1
#define _POSIX_PRIORITY_SCHEDULING	1
#define _POSIX_REALTIME_SIGNALS		1
#define _POSIX_SEMAPHORES		1
#define _POSIX_SHARED_MEMORY_OBJECTS	1
#define _POSIX_SYNCHRONIZED_IO		1
#define _POSIX_TIMERS			1

#define _POSIX_THREADS				1
#define _POSIX_THREAD_ATTR_STACKADDR		1
#define _POSIX_THREAD_ATTR_STACKSIZE		1
#define _POSIX_THREAD_PRIORITY_SCHEDULING	1
#define _POSIX_THREAD_PRIO_INHERIT		1
#define _POSIX_THREAD_PRIO_PROTECT		1
#define _POSIX_THREAD_PROCESS_SHARED		1
#define _POSIX_THREAD_SAFE_FUNCTIONS		1

#define _POSIX_SPAWN				1
#define _POSIX_TIMEOUTS				1
#define _POSIX_CPUTIME				1
#define _POSIX_THREAD_CPUTIME			1
#define _POSIX_SPORADIC_SERVER			1
#define _POSIX_THREAD_SPORADIC_SERVER		1
#define _POSIX_DEVICE_CONTROL			1
#define _POSIX_DEVCTL_DIRECTION			1
#define _POSIX_INTERRUPT_CONTROL		1
#define _POSIX_ADVISORY_INFO			1

#endif

#ifdef __svr4__
# define _POSIX_JOB_CONTROL     1
# define _POSIX_SAVED_IDS       1
# define _POSIX_VERSION 199009L
#endif

#ifdef __CYGWIN32__
# define _POSIX_JOB_CONTROL	1
# define _POSIX_SAVED_IDS	0
# define _POSIX_VERSION		199009L
#endif

#ifdef __cplusplus
}
#endif
#endif 

#if defined(_POSIX_THREADS)
/* unified sys/types.h: 
   start with sef's sysvi386 version.
   merge go32 version -- a few ifdefs.
   h8300hms, h8300xray, and sysvnecv70 disagree on the following types:

   typedef int gid_t;
   typedef int uid_t;
   typedef int dev_t;
   typedef int ino_t;
   typedef int mode_t;
   typedef int caddr_t;

   however, these aren't "reasonable" values, the sysvi386 ones make far 
   more sense, and should work sufficiently well (in particular, h8300 
   doesn't have a stat, and the necv70 doesn't matter.) -- eichin
 */

#ifndef _SYS_TYPES_H
#define _SYS_TYPES_H

#if defined (_WIN32) || defined (__CYGWIN__)
#define __MS_types__
#endif

#ifdef __i386__
#if defined (GO32) || defined (__MSDOS__)
#define __MS_types__
#endif
#endif

/* gt4: stand-in for gcc's <stddef.h> (the compiler ships without headers). */
#ifndef _STDDEF_H
#define _STDDEF_H
typedef __SIZE_TYPE__ size_t;
typedef __PTRDIFF_TYPE__ ptrdiff_t;
#ifndef __cplusplus
typedef __WCHAR_TYPE__ wchar_t;
#endif
typedef unsigned int wint_t;
#ifndef NULL
#define NULL ((void *)0)
#endif
#define offsetof(t, m) ((size_t)&((t *)0)->m)
#endif

#ifndef	_MACHTYPES_H_
#define	_MACHTYPES_H_

#define	_CLOCK_T_	unsigned long		/* clock() */
#define	_TIME_T_	long			
#define _CLOCKID_T_ 	unsigned long
#define _TIMER_T_   	unsigned long

#endif	

#ifdef __GNUC__
#define _ST_INT32 __attribute__ ((__mode__ (__SI__)))
#else
#define _ST_INT32
#endif

# ifndef	_POSIX_SOURCE

#  define	physadr		physadr_t
#  define	quad		quad_t

#ifndef _WINSOCK_H
typedef	unsigned char	u_char;
typedef	unsigned short	u_short;
typedef	unsigned int	u_int;
typedef	unsigned long	u_long;
#endif

typedef	unsigned short	ushort;		
typedef	unsigned int	uint;		
# endif	

#ifndef __clock_t_defined
typedef _CLOCK_T_ clock_t;
#define __clock_t_defined
#endif

#ifndef __time_t_defined
typedef _TIME_T_ time_t;
#define __time_t_defined

struct timespec {
  time_t  tv_sec;   
  long    tv_nsec;  
};

struct itimerspec {
  struct timespec  it_interval;  
  struct timespec  it_value;     
};
#endif

typedef	long	daddr_t;
typedef	char *	caddr_t;

#ifdef __MS_types__
typedef	unsigned long	ino_t;
#else
#ifdef __sparc__
typedef	unsigned long	ino_t;
#else
typedef	unsigned short	ino_t;
#endif
#endif

#ifdef __MS_types__
typedef unsigned long vm_offset_t;
typedef unsigned long vm_size_t;

#define __BIT_TYPES_DEFINED__

typedef char int8_t;
typedef unsigned char u_int8_t;
typedef short int16_t;
typedef unsigned short u_int16_t;
typedef int int32_t;
typedef unsigned int u_int32_t;
typedef long long int64_t;
typedef unsigned long long u_int64_t;
typedef int32_t register_t;
#endif 

#if defined(__rtems__)

typedef unsigned long long dev_t;
#else
typedef	short	dev_t;
#endif

typedef	long	off_t;

typedef	unsigned short	uid_t;
typedef	unsigned short	gid_t;
typedef int pid_t;
typedef	long key_t;
typedef long ssize_t;

#ifdef __MS_types__
typedef	char *	addr_t;
typedef int mode_t;
#else
#if defined (__sparc__) && !defined (__sparc_v9__)
#ifdef __svr4__
typedef unsigned long mode_t;
#else
typedef unsigned short mode_t;
#endif
#else
typedef unsigned int mode_t _ST_INT32;
#endif
#endif 

typedef unsigned short nlink_t;

# if ! defined (_POSIX_SOURCE) && ! defined (_WINSOCK_H)

#  define	NBBY	8		

#  ifndef	FD_SETSIZE
#	define	FD_SETSIZE	64
#  endif

typedef	long	fd_mask;
#  define	NFDBITS	(sizeof (fd_mask) * NBBY)	
#  ifndef	howmany
#	define	howmany(x,y)	(((x)+((y)-1))/(y))
#  endif

typedef	struct _types_fd_set {
	fd_mask	fds_bits[howmany(FD_SETSIZE, NFDBITS)];
} _types_fd_set;

#define fd_set _types_fd_set

#  define	FD_SET(n, p)	((p)->fds_bits[(n)/NFDBITS] |= (1L << ((n) % NFDBITS)))
#  define	FD_CLR(n, p)	((p)->fds_bits[(n)/NFDBITS] &= ~(1L << ((n) % NFDBITS)))
#  define	FD_ISSET(n, p)	((p)->fds_bits[(n)/NFDBITS] & (1L << ((n) % NFDBITS)))
#  define	FD_ZERO(p)	(__extension__ (void)({ \
     size_t __i; \
     char *__tmp = (char *)p; \
     for (__i = 0; __i < sizeof (*(p)); ++__i) \
       *__tmp++ = 0; \
}))

# endif	

#undef __MS_types__
#undef _ST_INT32

#if defined(__rtems__)

#ifndef __clockid_t_defined
typedef _CLOCKID_T_ clockid_t;
#define __clockid_t_defined
#endif

#ifndef __timer_t_defined
typedef _TIMER_T_ timer_t;
#define __timer_t_defined
#endif

/*
 *  Written by Joel Sherrill <joel@OARcorp.com>.
 *
 *  COPYRIGHT (c) 1989-2000.
 *
 *  On-Line Applications Research Corporation (OAR).
 *
 *  Permission to use, copy, modify, and distribute this software for any
 *  purpose without fee is hereby granted, provided that this entire notice
 *  is included in all copies of any software which is or includes a copy
 *  or modification of this software.
 *
 *  THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 *  WARRANTY.  IN PARTICULAR,  THE AUTHOR MAKES NO REPRESENTATION
 *  OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY OF THIS
 *  SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 *  $Id: features.h,v 1.1 2000/12/12 01:24:08 jjohnstn Exp $
 */

#ifndef _SYS_FEATURES_H
#define _SYS_FEATURES_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __rtems__
#define _POSIX_JOB_CONTROL     		1
#define _POSIX_SAVED_IDS       		1
#define _POSIX_VERSION			199309L
#define _POSIX_ASYNCHRONOUS_IO		1
#define _POSIX_FSYNC			1
#define _POSIX_MAPPED_FILES		1
#define _POSIX_MEMLOCK			1
#define _POSIX_MEMLOCK_RANGE		1
#define _POSIX_MEMORY_PROTECTION	1
#define _POSIX_MESSAGE_PASSING		1
#define _POSIX_PRIORITIZED_IO		1
#define _POSIX_PRIORITY_SCHEDULING	1
#define _POSIX_REALTIME_SIGNALS		1
#define _POSIX_SEMAPHORES		1
#define _POSIX_SHARED_MEMORY_OBJECTS	1
#define _POSIX_SYNCHRONIZED_IO		1
#define _POSIX_TIMERS			1

#define _POSIX_THREADS				1
#define _POSIX_THREAD_ATTR_STACKADDR		1
#define _POSIX_THREAD_ATTR_STACKSIZE		1
#define _POSIX_THREAD_PRIORITY_SCHEDULING	1
#define _POSIX_THREAD_PRIO_INHERIT		1
#define _POSIX_THREAD_PRIO_PROTECT		1
#define _POSIX_THREAD_PROCESS_SHARED		1
#define _POSIX_THREAD_SAFE_FUNCTIONS		1

#define _POSIX_SPAWN				1
#define _POSIX_TIMEOUTS				1
#define _POSIX_CPUTIME				1
#define _POSIX_THREAD_CPUTIME			1
#define _POSIX_SPORADIC_SERVER			1
#define _POSIX_THREAD_SPORADIC_SERVER		1
#define _POSIX_DEVICE_CONTROL			1
#define _POSIX_DEVCTL_DIRECTION			1
#define _POSIX_INTERRUPT_CONTROL		1
#define _POSIX_ADVISORY_INFO			1

#endif

#ifdef __svr4__
# define _POSIX_JOB_CONTROL     1
# define _POSIX_SAVED_IDS       1
# define _POSIX_VERSION 199009L
#endif

#ifdef __CYGWIN32__
# define _POSIX_JOB_CONTROL	1
# define _POSIX_SAVED_IDS	0
# define _POSIX_VERSION		199009L
#endif

#ifdef __cplusplus
}
#endif
#endif 

#if defined(_POSIX_THREADS)

/*
 *  Written by Joel Sherrill <joel@OARcorp.com>.
 *
 *  COPYRIGHT (c) 1989-2000.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  Permission to use, copy, modify, and distribute this software for any
 *  purpose without fee is hereby granted, provided that this entire notice
 *  is included in all copies of any software which is or includes a copy
 *  or modification of this software.
 *
 *  THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 *  WARRANTY.  IN PARTICULAR,  THE AUTHOR MAKES NO REPRESENTATION
 *  OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY OF THIS
 *  SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 *  $Id: sched.h,v 1.1 2000/12/12 01:24:08 jjohnstn Exp $
 */

#ifndef __POSIX_SYS_SCHEDULING_h
#define __POSIX_SYS_SCHEDULING_h

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _SYS_UNISTD_H
#define _SYS_UNISTD_H

#ifdef __cplusplus
extern "C" {
#endif

#include <_ansi.h>
#include <sys/types.h>
#define __need_size_t
#define __need_ptrdiff_t
#include <stddef.h>

extern char **environ;

void	_EXFUN(_exit, (int __status ) _ATTRIBUTE ((noreturn)));

int	_EXFUN(access,(const char *__path, int __amode ));
unsigned  _EXFUN(alarm, (unsigned __secs ));
int     _EXFUN(chdir, (const char *__path ));
int     _EXFUN(chmod, (const char *__path, mode_t __mode ));
int     _EXFUN(chown, (const char *__path, uid_t __owner, gid_t __group ));
#ifdef __CYGWIN__
int     _EXFUN(chroot, (const char *__path ));
#endif
int     _EXFUN(close, (int __fildes ));
char    _EXFUN(*ctermid, (char *__s ));
char    _EXFUN(*cuserid, (char *__s ));
int     _EXFUN(dup, (int __fildes ));
int     _EXFUN(dup2, (int __fildes, int __fildes2 ));
int     _EXFUN(execl, (const char *__path, const char *, ... ));
int     _EXFUN(execle, (const char *__path, const char *, ... ));
int     _EXFUN(execlp, (const char *__file, const char *, ... ));
int     _EXFUN(execv, (const char *__path, char * const __argv[] ));
int     _EXFUN(execve, (const char *__path, char * const __argv[], char * const __envp[] ));
int     _EXFUN(execvp, (const char *__file, char * const __argv[] ));
int     _EXFUN(fchmod, (int __fildes, mode_t __mode ));
int     _EXFUN(fchown, (int __fildes, uid_t __owner, gid_t __group ));
pid_t   _EXFUN(fork, (void ));
long    _EXFUN(fpathconf, (int __fd, int __name ));
int     _EXFUN(fsync, (int __fd));
char    _EXFUN(*getcwd, (char *__buf, size_t __size ));
gid_t   _EXFUN(getegid, (void ));
uid_t   _EXFUN(geteuid, (void ));
gid_t   _EXFUN(getgid, (void ));
int     _EXFUN(getgroups, (int __gidsetsize, gid_t __grouplist[] ));
char    _EXFUN(*getlogin, (void ));
#if defined(_POSIX_THREAD_SAFE_FUNCTIONS)
int _EXFUN(getlogin_r, (char *name, size_t namesize) );
#endif
char 	_EXFUN(*getpass, (__const char *__prompt));
size_t  _EXFUN(getpagesize, (void));
pid_t   _EXFUN(getpgrp, (void ));
pid_t   _EXFUN(getpid, (void ));
pid_t   _EXFUN(getppid, (void ));
uid_t   _EXFUN(getuid, (void ));
#ifdef __CYGWIN__
char    _EXFUN(*getwd, (char *__buf ));
#endif
int     _EXFUN(isatty, (int __fildes ));
int     _EXFUN(lchown, (const char *__path, uid_t __owner, gid_t __group ));
int     _EXFUN(link, (const char *__path1, const char *__path2 ));
int	_EXFUN(nice, (int __nice_value ));
off_t   _EXFUN(lseek, (int __fildes, off_t __offset, int __whence ));
long    _EXFUN(pathconf, (const char *__path, int __name ));
int     _EXFUN(pause, (void ));
int     _EXFUN(pipe, (int __fildes[2] ));
/* POSIX 1003.1b-1993 says read() returns ssize_t */
#if defined(__rtems__)
ssize_t	_EXFUN(read, (int __fildes, void *__buf, size_t __nbyte ));
#else
int	_EXFUN(read, (int __fildes, void *__buf, size_t __nbyte ));
#endif
int     _EXFUN(rmdir, (const char *__path ));
#if defined(__rtems__)
void *  _EXFUN(sbrk,  (ptrdiff_t __incr));
#else
void *  _EXFUN(sbrk,  (size_t __incr));
#endif
#if defined(__CYGWIN__)
int     _EXFUN(setegid, (gid_t __gid ));
int     _EXFUN(seteuid, (uid_t __uid ));
#endif
int     _EXFUN(setgid, (gid_t __gid ));
int     _EXFUN(setpgid, (pid_t __pid, pid_t __pgid ));
pid_t   _EXFUN(setsid, (void ));
int     _EXFUN(setuid, (uid_t __uid ));
unsigned _EXFUN(sleep, (unsigned int __seconds ));
void    _EXFUN(swab, (const void *, void *, ssize_t));
long    _EXFUN(sysconf, (int __name ));
pid_t   _EXFUN(tcgetpgrp, (int __fildes ));
int     _EXFUN(tcsetpgrp, (int __fildes, pid_t __pgrp_id ));
char    _EXFUN(*ttyname, (int __fildes ));
int     _EXFUN(unlink, (const char *__path ));

#if defined(__rtems__)
ssize_t     _EXFUN(write, (int __fildes, const void *__buf, size_t __nbyte ));
#else
int     _EXFUN(write, (int __fildes, const void *__buf, size_t __nbyte ));
#endif

#ifndef        _POSIX_SOURCE
pid_t   _EXFUN(vfork, (void ));
#endif 

int     _EXFUN(_close, (int __fildes ));
pid_t   _EXFUN(_fork, (void ));
pid_t   _EXFUN(_getpid, (void ));
int     _EXFUN(_link, (const char *__path1, const char *__path2 ));
off_t   _EXFUN(_lseek, (int __fildes, off_t __offset, int __whence ));
int     _EXFUN(_read, (int __fildes, void *__buf, size_t __nbyte ));
void *  _EXFUN(_sbrk,  (size_t __incr));
int     _EXFUN(_unlink, (const char *__path ));
int     _EXFUN(_write, (int __fildes, const void *__buf, size_t __nbyte ));
int     _EXFUN(_execve, (const char *__path, char * const __argv[], char * const __envp[] ));

#if defined(__CYGWIN__) || defined(__rtems__)
int	_EXFUN(getdtablesize, (void));
void	_EXFUN(setdtablesize, (int));
unsigned _EXFUN(usleep, (unsigned int __useconds));
int     _EXFUN(ftruncate, (int __fd, off_t __length));
int     _EXFUN(truncate, (const char *, off_t __length));
int	_EXFUN(gethostname, (char *__name, size_t __len));
char *	_EXFUN(mktemp, (char *));
int     _EXFUN(sync, (void));
int     _EXFUN(readlink, (const char *__path, char *__buf, int __buflen));
int     _EXFUN(symlink, (const char *__name1, const char *__name2));
#endif

# define	F_OK	0
# define	R_OK	4
# define	W_OK	2
# define	X_OK	1

# define	SEEK_SET	0
# define	SEEK_CUR	1
# define	SEEK_END	2

#include <sys/features.h>

#define STDIN_FILENO    0       
#define STDOUT_FILENO   1       
#define STDERR_FILENO   2       

long _EXFUN(sysconf, (int __name));

#define _SC_ARG_MAX                 0
#define _SC_CHILD_MAX               1
#define _SC_CLK_TCK                 2
#define _SC_NGROUPS_MAX             3
#define _SC_OPEN_MAX                4
  
#define _SC_JOB_CONTROL             5
#define _SC_SAVED_IDS               6
#define _SC_VERSION                 7
#define _SC_PAGESIZE                8

#define _SC_NPROCESSORS_CONF        9
#define _SC_NPROCESSORS_ONLN       10
#define _SC_PHYS_PAGES             11
#define _SC_AVPHYS_PAGES           12

#define _SC_MQ_OPEN_MAX            13
#define _SC_MQ_PRIO_MAX            14
#define _SC_RTSIG_MAX              15
#define _SC_SEM_NSEMS_MAX          16
#define _SC_SEM_VALUE_MAX          17
#define _SC_SIGQUEUE_MAX           18
#define _SC_TIMER_MAX              19
#define _SC_TZNAME_MAX             20

#define _SC_ASYNCHRONOUS_IO        21
#define _SC_FSYNC                  22
#define _SC_MAPPED_FILES           23
#define _SC_MEMLOCK                24
#define _SC_MEMLOCK_RANGE          25
#define _SC_MEMORY_PROTECTION      26
#define _SC_MESSAGE_PASSING        27
#define _SC_PRIORITIZED_IO         28
#define _SC_REALTIME_SIGNALS       29
#define _SC_SEMAPHORES             30
#define _SC_SHARED_MEMORY_OBJECTS  31
#define _SC_SYNCHRONIZED_IO        32
#define _SC_TIMERS                 33
#define _SC_AIO_LISTIO_MAX         34
#define _SC_AIO_MAX                35
#define _SC_AIO_PRIO_DELTA_MAX     36
#define _SC_DELAYTIMER_MAX         37

#define _SC_THREAD_KEYS_MAX              38
#define _SC_THREAD_STACK_MIN             39
#define _SC_THREAD_THREADS_MAX           40
#define _SC_TTY_NAME_MAX                 41

#define _SC_THREADS                      42
#define _SC_THREAD_ATTR_STACKADDR        43
#define _SC_THREAD_ATTR_STACKSIZE        44
#define _SC_THREAD_PRIORITY_SCHEDULING   45
#define _SC_THREAD_PRIO_INHERIT          46

#define _SC_THREAD_PRIO_PROTECT          47
#define _SC_THREAD_PRIO_CEILING          _SC_THREAD_PRIO_PROTECT
#define _SC_THREAD_PROCESS_SHARED        48
#define _SC_THREAD_SAFE_FUNCTIONS        49
#define _SC_GETGR_R_SIZE_MAX             50
#define _SC_GETPW_R_SIZE_MAX             51
#define _SC_LOGIN_NAME_MAX               52
#define _SC_THREAD_DESTRUCTOR_ITERATIONS 53
  
# define	_PC_LINK_MAX	        0
# define	_PC_MAX_CANON	        1
# define	_PC_MAX_INPUT	        2
# define	_PC_NAME_MAX	        3
# define	_PC_PATH_MAX	        4
# define	_PC_PIPE_BUF	        5
# define	_PC_CHOWN_RESTRICTED   	6
# define	_PC_NO_TRUNC	        7
# define	_PC_VDISABLE	        8
# define	_PC_ASYNC_IO            9
# define	_PC_PRIO_IO            10
# define	_PC_SYNC_IO            11

#ifdef __CYGWIN__
#define MAXPATHLEN (260 - 1 )
#else
# define	MAXPATHLEN	1024
#endif

#ifdef __cplusplus
}
#endif
#endif 

/* unified sys/types.h: 
   start with sef's sysvi386 version.
   merge go32 version -- a few ifdefs.
   h8300hms, h8300xray, and sysvnecv70 disagree on the following types:

   typedef int gid_t;
   typedef int uid_t;
   typedef int dev_t;
   typedef int ino_t;
   typedef int mode_t;
   typedef int caddr_t;

   however, these aren't "reasonable" values, the sysvi386 ones make far 
   more sense, and should work sufficiently well (in particular, h8300 
   doesn't have a stat, and the necv70 doesn't matter.) -- eichin
 */

#ifndef _SYS_TYPES_H
#define _SYS_TYPES_H

#if defined (_WIN32) || defined (__CYGWIN__)
#define __MS_types__
#endif

#ifdef __i386__
#if defined (GO32) || defined (__MSDOS__)
#define __MS_types__
#endif
#endif

# include <stddef.h>
# include <machine/types.h>

#ifdef __GNUC__
#define _ST_INT32 __attribute__ ((__mode__ (__SI__)))
#else
#define _ST_INT32
#endif

# ifndef	_POSIX_SOURCE

#  define	physadr		physadr_t
#  define	quad		quad_t

#ifndef _WINSOCK_H
typedef	unsigned char	u_char;
typedef	unsigned short	u_short;
typedef	unsigned int	u_int;
typedef	unsigned long	u_long;
#endif

typedef	unsigned short	ushort;		
typedef	unsigned int	uint;		
# endif	

#ifndef __clock_t_defined
typedef _CLOCK_T_ clock_t;
#define __clock_t_defined
#endif

#ifndef __time_t_defined
typedef _TIME_T_ time_t;
#define __time_t_defined

struct timespec {
  time_t  tv_sec;   
  long    tv_nsec;  
};

struct itimerspec {
  struct timespec  it_interval;  
  struct timespec  it_value;     
};
#endif

typedef	long	daddr_t;
typedef	char *	caddr_t;

#ifdef __MS_types__
typedef	unsigned long	ino_t;
#else
#ifdef __sparc__
typedef	unsigned long	ino_t;
#else
typedef	unsigned short	ino_t;
#endif
#endif

#ifdef __MS_types__
typedef unsigned long vm_offset_t;
typedef unsigned long vm_size_t;

#define __BIT_TYPES_DEFINED__

typedef char int8_t;
typedef unsigned char u_int8_t;
typedef short int16_t;
typedef unsigned short u_int16_t;
typedef int int32_t;
typedef unsigned int u_int32_t;
typedef long long int64_t;
typedef unsigned long long u_int64_t;
typedef int32_t register_t;
#endif 

#if defined(__rtems__)

typedef unsigned long long dev_t;
#else
typedef	short	dev_t;
#endif

typedef	long	off_t;

typedef	unsigned short	uid_t;
typedef	unsigned short	gid_t;
typedef int pid_t;
typedef	long key_t;
typedef long ssize_t;

#ifdef __MS_types__
typedef	char *	addr_t;
typedef int mode_t;
#else
#if defined (__sparc__) && !defined (__sparc_v9__)
#ifdef __svr4__
typedef unsigned long mode_t;
#else
typedef unsigned short mode_t;
#endif
#else
typedef unsigned int mode_t _ST_INT32;
#endif
#endif 

typedef unsigned short nlink_t;

# if ! defined (_POSIX_SOURCE) && ! defined (_WINSOCK_H)

#  define	NBBY	8		

#  ifndef	FD_SETSIZE
#	define	FD_SETSIZE	64
#  endif

typedef	long	fd_mask;
#  define	NFDBITS	(sizeof (fd_mask) * NBBY)	
#  ifndef	howmany
#	define	howmany(x,y)	(((x)+((y)-1))/(y))
#  endif

typedef	struct _types_fd_set {
	fd_mask	fds_bits[howmany(FD_SETSIZE, NFDBITS)];
} _types_fd_set;

#define fd_set _types_fd_set

#  define	FD_SET(n, p)	((p)->fds_bits[(n)/NFDBITS] |= (1L << ((n) % NFDBITS)))
#  define	FD_CLR(n, p)	((p)->fds_bits[(n)/NFDBITS] &= ~(1L << ((n) % NFDBITS)))
#  define	FD_ISSET(n, p)	((p)->fds_bits[(n)/NFDBITS] & (1L << ((n) % NFDBITS)))
#  define	FD_ZERO(p)	(__extension__ (void)({ \
     size_t __i; \
     char *__tmp = (char *)p; \
     for (__i = 0; __i < sizeof (*(p)); ++__i) \
       *__tmp++ = 0; \
}))

# endif	

#undef __MS_types__
#undef _ST_INT32

#if defined(__rtems__)

#ifndef __clockid_t_defined
typedef _CLOCKID_T_ clockid_t;
#define __clockid_t_defined
#endif

#ifndef __timer_t_defined
typedef _TIMER_T_ timer_t;
#define __timer_t_defined
#endif

#include <sys/features.h>

#if defined(_POSIX_THREADS)

#include <sys/sched.h>

typedef __uint32_t pthread_t;            

#define PTHREAD_SCOPE_PROCESS 0
#define PTHREAD_SCOPE_SYSTEM  1

#define PTHREAD_INHERIT_SCHED  1      
                                      
                                      
#define PTHREAD_EXPLICIT_SCHED 2      

#define PTHREAD_CREATE_DETACHED 0
#define PTHREAD_CREATE_JOINABLE  1

typedef struct {
  int is_initialized;
  void *stackaddr;
  int stacksize;
  int contentionscope;
  int inheritsched;
  int schedpolicy;
  struct sched_param schedparam;

  
#if defined(_POSIX_THREAD_CPUTIME)
  int  cputime_clock_allowed;  
#endif
  int  detachstate;

} pthread_attr_t;

#if defined(_POSIX_THREAD_PROCESS_SHARED)

#define PTHREAD_PROCESS_PRIVATE 0 
#define PTHREAD_PROCESS_SHARED  1 
                                  
                                  
#endif

#if defined(_POSIX_THREAD_PRIO_PROTECT)

#define PTHREAD_PRIO_NONE    0
#define PTHREAD_PRIO_INHERIT 1
#define PTHREAD_PRIO_PROTECT 2
#endif

typedef __uint32_t pthread_mutex_t;      

typedef struct {
  int   is_initialized;
#if defined(_POSIX_THREAD_PROCESS_SHARED)
  int   process_shared;  
#endif
#if defined(_POSIX_THREAD_PRIO_PROTECT)
  int   prio_ceiling;
  int   protocol;
#endif
  int   recursive;
} pthread_mutexattr_t;

typedef __uint32_t pthread_cond_t;       

typedef struct {
  int   is_initialized;
#if defined(_POSIX_THREAD_PROCESS_SHARED)
  int   process_shared;       
#endif
} pthread_condattr_t;         

typedef __uint32_t pthread_key_t;        

typedef struct {
  int   is_initialized;  
  int   init_executed;   
} pthread_once_t;       

#endif 

#endif  

#endif	

/* time.h -- An implementation of the standard Unix <sys/time.h> file.
   Written by Geoffrey Noer <noer@cygnus.com>
   Public domain; no rights reserved. */

#ifndef _SYS_TIME_H_
#define _SYS_TIME_H_

#include <_ansi.h>
#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _WINSOCK_H
struct timeval {
  long tv_sec;
  long tv_usec;
};

struct timezone {
  int tz_minuteswest;
  int tz_dsttime;
};

#ifdef __CYGWIN__
#include <sys/select.h>
#endif 

#endif 

#define ITIMER_REAL     0
#define ITIMER_VIRTUAL  1
#define ITIMER_PROF     2

struct  itimerval {
  struct  timeval it_interval;
  struct  timeval it_value;
};

#if defined(__rtems__)

#define	timerisset(tvp)		((tvp)->tv_sec || (tvp)->tv_usec)
#define	timerclear(tvp)		((tvp)->tv_sec = (tvp)->tv_usec = 0)
#define	timercmp(a, b, CMP) 						      \
  (((a)->tv_sec == (b)->tv_sec) ? 					      \
   ((a)->tv_usec CMP (b)->tv_usec) : 					      \
   ((a)->tv_sec CMP (b)->tv_sec))
#define	timeradd(a, b, result)						      \
  do {									      \
    (result)->tv_sec = (a)->tv_sec + (b)->tv_sec;			      \
    (result)->tv_usec = (a)->tv_usec + (b)->tv_usec;			      \
    if ((result)->tv_usec >= 1000000)					      \
      {									      \
	++(result)->tv_sec;						      \
	(result)->tv_usec -= 1000000;					      \
      }									      \
  } while (0)
#define	timersub(a, b, result)						      \
  do {									      \
    (result)->tv_sec = (a)->tv_sec - (b)->tv_sec;			      \
    (result)->tv_usec = (a)->tv_usec - (b)->tv_usec;			      \
    if ((result)->tv_usec < 0) {					      \
      --(result)->tv_sec;						      \
      (result)->tv_usec += 1000000;					      \
    }									      \
  } while (0)
#endif

int _EXFUN(gettimeofday, (struct timeval *__p, struct timezone *__z));
int _EXFUN(settimeofday, (const struct timeval *, const struct timezone *));
int _EXFUN(utimes, (const char *__path, struct timeval *__tvp));
int _EXFUN(getitimer, (int __which, struct itimerval *__value));
int _EXFUN(setitimer, (int __which, const struct itimerval *__value,
					struct itimerval *__ovalue));

#ifdef __cplusplus
}
#endif
#endif 

#define SCHED_OTHER    0
#define SCHED_FIFO     1
#define SCHED_RR       2

#if defined(_POSIX_SPORADIC_SERVER)
#define SCHED_SPORADIC 3 
#endif

struct sched_param {
  int sched_priority;           

#if defined(_POSIX_SPORADIC_SERVER)
  int ss_low_priority;          
                                
  struct timespec ss_replenish_period; 
                                
  struct timespec ss_initial_budget;   
#endif
};

#ifdef __cplusplus
}
#endif 

#endif

typedef __uint32_t pthread_t;            

#define PTHREAD_SCOPE_PROCESS 0
#define PTHREAD_SCOPE_SYSTEM  1

#define PTHREAD_INHERIT_SCHED  1      
                                      
                                      
#define PTHREAD_EXPLICIT_SCHED 2      

#define PTHREAD_CREATE_DETACHED 0
#define PTHREAD_CREATE_JOINABLE  1

typedef struct {
  int is_initialized;
  void *stackaddr;
  int stacksize;
  int contentionscope;
  int inheritsched;
  int schedpolicy;
  struct sched_param schedparam;

  
#if defined(_POSIX_THREAD_CPUTIME)
  int  cputime_clock_allowed;  
#endif
  int  detachstate;

} pthread_attr_t;

#if defined(_POSIX_THREAD_PROCESS_SHARED)

#define PTHREAD_PROCESS_PRIVATE 0 
#define PTHREAD_PROCESS_SHARED  1 
                                  
                                  
#endif

#if defined(_POSIX_THREAD_PRIO_PROTECT)

#define PTHREAD_PRIO_NONE    0
#define PTHREAD_PRIO_INHERIT 1
#define PTHREAD_PRIO_PROTECT 2
#endif

typedef __uint32_t pthread_mutex_t;      

typedef struct {
  int   is_initialized;
#if defined(_POSIX_THREAD_PROCESS_SHARED)
  int   process_shared;  
#endif
#if defined(_POSIX_THREAD_PRIO_PROTECT)
  int   prio_ceiling;
  int   protocol;
#endif
  int   recursive;
} pthread_mutexattr_t;

typedef __uint32_t pthread_cond_t;       

typedef struct {
  int   is_initialized;
#if defined(_POSIX_THREAD_PROCESS_SHARED)
  int   process_shared;       
#endif
} pthread_condattr_t;         

typedef __uint32_t pthread_key_t;        

typedef struct {
  int   is_initialized;  
  int   init_executed;   
} pthread_once_t;       

#endif 

#endif  

#endif	

#endif

typedef unsigned long sigset_t;

#if defined(__rtems__)

#if defined(_POSIX_REALTIME_SIGNALS)

#define SIGEV_NONE   1  
                        
#define SIGEV_SIGNAL 2  
                        
                        
#define SIGEV_THREAD 3  
                        

union sigval {
  int    sival_int;    
  void  *sival_ptr;    
};

struct sigevent {
  int              sigev_notify;               
  int              sigev_signo;                
  union sigval     sigev_value;                

#if defined(_POSIX_THREADS)
  void           (*sigev_notify_function)( union sigval );
                                               
  pthread_attr_t  *sigev_notify_attributes;    
#endif
};

#define SI_USER    1    
#define SI_QUEUE   2    
#define SI_TIMER   3    
#define SI_ASYNCIO 4    
#define SI_MESGQ   5    

typedef struct {
  int          si_signo;    
  int          si_code;     
  union sigval si_value;    
} siginfo_t;
#endif

#define SA_NOCLDSTOP 1   
#define SA_SIGINFO   2   
                         

struct sigaction {
  int         sa_flags;       
  sigset_t    sa_mask;        
                              
                              
  union {
    void      (*_handler)();  
#if defined(_POSIX_REALTIME_SIGNALS)
    void      (*_sigaction)( int, siginfo_t *, void * );
#endif
  } _signal_handlers;
};

#define sa_handler    _signal_handlers._handler
#if defined(_POSIX_REALTIME_SIGNALS)
#define sa_sigaction  _signal_handlers._sigaction
#endif

#else

struct sigaction 
{
	void (*sa_handler)(int);
	sigset_t sa_mask;
	int sa_flags;
};

#define SA_NOCLDSTOP 1  

#endif 

#define SIG_SETMASK 0	
#define SIG_BLOCK 1	
#define SIG_UNBLOCK 2	

#define sigaddset(what,sig) (*(what) |= (1<<(sig)))
#define sigemptyset(what)   (*(what) = 0)

int _EXFUN(sigprocmask, (int how, const sigset_t *set, sigset_t *oset));

#if defined(_POSIX_THREADS)
int _EXFUN(pthread_sigmask, (int how, const sigset_t *set, sigset_t *oset));
#endif

#if defined(__CYGWIN__) || defined(__rtems__)
#undef sigaddset
#undef sigemptyset

int _EXFUN(kill, (int, int));
int _EXFUN(sigaction, (int, const struct sigaction *, struct sigaction *));
int _EXFUN(sigaddset, (sigset_t *, const int));
int _EXFUN(sigdelset, (sigset_t *, const int));
int _EXFUN(sigismember, (const sigset_t *, int));
int _EXFUN(sigfillset, (sigset_t *));
int _EXFUN(sigemptyset, (sigset_t *));
int _EXFUN(sigpending, (sigset_t *));
int _EXFUN(sigsuspend, (const sigset_t *));
int _EXFUN(sigpause, (int));

#if defined(_POSIX_THREADS)
int _EXFUN(pthread_kill, (pthread_t thread, int sig));
#endif

#if defined(_POSIX_REALTIME_SIGNALS)

int _EXFUN(sigwaitinfo, (const sigset_t *set, siginfo_t *info));
int _EXFUN(sigtimedwait,
  (const sigset_t *set, siginfo_t *info, const struct timespec  *timeout)
);
int _EXFUN(sigwait, (const sigset_t *set, int *sig));

int _EXFUN(sigqueue, (pid_t pid, int signo, const union sigval value));

#endif 

#endif 

#if defined(___AM29K__)

#define SIGABRT 1
#define SIGFPE 1
#define SIGILL 1
#define SIGINT 1
#define SIGSEGV 1
#define SIGTERM 1

#define SIGHUP 1
#define SIGQUIT 1
#define NSIG 2
#elif defined(__GO32__)
#define SIGINT  1
#define SIGKILL 2
#define SIGPIPE 3
#define SIGFPE  4
#define SIGHUP  5
#define SIGTERM 6
#define SIGSEGV 7
#define SIGTSTP 8
#define SIGQUIT 9
#define SIGTRAP 10
#define SIGILL  11
#define SIGEMT  12
#define SIGALRM 13
#define SIGBUS  14
#define SIGLOST 15
#define SIGSTOP 16
#define SIGABRT 17
#define SIGUSR1	18
#define SIGUSR2	19
#define NSIG    20
#elif defined(__CYGWIN__)	
#define	SIGHUP	1	
#define	SIGINT	2	
#define	SIGQUIT	3	
#define	SIGILL	4	
#define	SIGTRAP	5	
#define	SIGABRT 6	
#define	SIGEMT	7	
#define	SIGFPE	8	
#define	SIGKILL	9	
#define	SIGBUS	10	
#define	SIGSEGV	11	
#define	SIGSYS	12	
#define	SIGPIPE	13	
#define	SIGALRM	14	
#define	SIGTERM	15	
#define	SIGURG	16	
#define	SIGSTOP	17	
#define	SIGTSTP	18	
#define	SIGCONT	19	
#define	SIGCHLD	20	
#define	SIGCLD	20	
#define	SIGTTIN	21	
#define	SIGTTOU	22	
#define	SIGIO	23	
#define	SIGPOLL	SIGIO	
#define	SIGXCPU	24	
#define	SIGXFSZ	25	
#define	SIGVTALRM 26	
#define	SIGPROF	27	
#define	SIGWINCH 28	
#define	SIGLOST 29	
#define	SIGUSR1 30	
#define	SIGUSR2 31	
#define NSIG	32      
#else
#define	SIGHUP	1	
#define	SIGINT	2	
#define	SIGQUIT	3	
#define	SIGILL	4	
#define	SIGTRAP	5	
#define	SIGIOT	6	
#define	SIGABRT 6	
#define	SIGEMT	7	
#define	SIGFPE	8	
#define	SIGKILL	9	
#define	SIGBUS	10	
#define	SIGSEGV	11	
#define	SIGSYS	12	
#define	SIGPIPE	13	
#define	SIGALRM	14	
#define	SIGTERM	15	

#if defined(__rtems__)
#define SIGUSR1 16  
#define SIGUSR2 17  

#define __SIGFIRSTNOTRT SIGHUP
#define __SIGLASTNOTRT  SIGUSR2

#define SIGRTMIN 18
#define SIGRTMAX 32

#elif defined(__svr4__)

#define	SIGUSR1	16
#define SIGUSR2	17
#define SIGCLD	18
#define	SIGPWR	19
#define SIGWINCH 20
#define	SIGPOLL	22	
#define	SIGSTOP	23	
#define	SIGTSTP	24	
#define	SIGCONT	25	
#define	SIGTTIN	26	
#define	SIGTTOU	27	
#define NSIG	28	
#else
#define	SIGURG	16	
#define	SIGSTOP	17	
#define	SIGTSTP	18	
#define	SIGCONT	19	
#define	SIGCHLD	20	
#define	SIGCLD	20	
#define	SIGTTIN	21	
#define	SIGTTOU	22	
#define	SIGIO	23	
#define	SIGPOLL	SIGIO	
#define	SIGXCPU	24	
#define	SIGXFSZ	25	
#define	SIGVTALRM 26	
#define	SIGPROF	27	
#define	SIGWINCH 28	
#define	SIGLOST 29	
#define	SIGUSR1 30	
#define	SIGUSR2 31	
#define NSIG	32      
#endif
#endif

#ifdef __cplusplus
}
#endif
#endif 

typedef int	sig_atomic_t;		/* Atomic entity type (ANSI) */

#if defined(__STDC__) || defined(__cplusplus)
#define SIG_DFL ((void (*)(int))0)	
#define SIG_IGN ((void (*)(int))1)	
#define SIG_ERR ((void (*)(int))-1)	
#else
#define SIG_DFL ((void (*)())0)		
#define SIG_IGN ((void (*)())1)		
#define SIG_ERR ((void (*)())-1)	
#endif

typedef void (*_sig_func_ptr) (int);

struct _reent;

_sig_func_ptr _EXFUN(_signal_r, (struct _reent *, int, _sig_func_ptr));
int	_EXFUN(_raise_r, (struct _reent *, int));

#ifndef _REENT_ONLY
_sig_func_ptr _EXFUN(signal, (int, _sig_func_ptr));
int	_EXFUN(raise, (int));
#endif

#ifdef __cplusplus
}
#endif
#endif 

int _EXFUN(clock_settime, (clockid_t clock_id, const struct timespec *tp));
int _EXFUN(clock_gettime, (clockid_t clock_id, struct timespec *tp));
int _EXFUN(clock_getres,  (clockid_t clock_id, struct timespec *res));

int _EXFUN(timer_create,
  (clockid_t clock_id, struct sigevent *evp, timer_t *timerid));

int _EXFUN(timer_delete, (timer_t timerid));

int _EXFUN(timer_settime,
  (timer_t timerid, int flags, const struct itimerspec *value,
   struct itimerspec *ovalue));
int _EXFUN(timer_gettime, (timer_t timerid, struct itimerspec *value));
int _EXFUN(timer_getoverrun, (timer_t timerid));

int _EXFUN(nanosleep, (const struct timespec  *rqtp, struct timespec *rmtp));

#endif 

#define CLOCK_ENABLED  1  
#define CLOCK_DISABLED 0  

#define CLOCK_ALLOWED    1 
                           
                           
#define CLOCK_DISALLOWED 0 
                           
                           

#define CLOCK_REALTIME (clockid_t)1

#define TIMER_ABSTIME  4

#if defined(_POSIX_CPUTIME)

#define CLOCK_PROCESS_CPUTIME (clockid_t)2

#endif

#if defined(_POSIX_THREAD_CPUTIME)

#define CLOCK_THREAD_CPUTIME (clockid_t)3

#endif

#if defined(_POSIX_CPUTIME)

int _EXFUN(clock_getcpuclockid, (pid_t pid, clockid_t *clock_id));

#endif 

#if defined(_POSIX_CPUTIME) || defined(_POSIX_THREAD_CPUTIME)

int _EXFUN(clock_setenable_attr, (clockid_t clock_id, int attr));
int _EXFUN(clock_getenable_attr, (clockid_t clock_id, int *attr));

#endif 

#ifdef __cplusplus
}
#endif
#endif 

#ifndef __Long
#if __LONG_MAX__ == 2147483647L
#define __Long long
typedef unsigned __Long __ULong;
#elif __INT_MAX__ == 2147483647
#define __Long int
typedef unsigned __Long __ULong;
#endif
#endif

#ifndef __Long
#define __Long __int32_t
typedef __uint32_t __ULong;
#endif

struct _glue 
{
  struct _glue *_next;
  int _niobs;
  struct __sFILE *_iobs;
};

struct _Bigint 
{
  struct _Bigint *_next;
  int _k, _maxwds, _sign, _wds;
  __ULong _x[1];
};

#define	_ATEXIT_SIZE 32	

struct _atexit {
	struct	_atexit *_next;			
	int	_ind;				
	void	(*_fns[_ATEXIT_SIZE])(void);	
};

struct __sbuf {
	unsigned char *_base;
	int	_size;
};

typedef long _fpos_t;		
				

struct __sFILE {
  unsigned char *_p;	
  int	_r;		
  int	_w;		
  short	_flags;		
  short	_file;		
  struct __sbuf _bf;	
  int	_lbfsize;	

  
  _PTR	_cookie;	

  int	_EXFUN((*_read),(_PTR _cookie, char *_buf, int _n));
  int	_EXFUN((*_write),(_PTR _cookie, const char *_buf, int _n));
  _fpos_t _EXFUN((*_seek),(_PTR _cookie, _fpos_t _offset, int _whence));
  int	_EXFUN((*_close),(_PTR _cookie));

  
  struct __sbuf _ub;	
  unsigned char *_up;	
  int	_ur;		

  
  unsigned char _ubuf[3];	
  unsigned char _nbuf[1];	

  
  struct __sbuf _lb;	

  
  int	_blksize;	
  int	_offset;	

  struct _reent *_data;
};

struct _reent
{
  
  int _errno;

  

  struct __sFILE *_stdin, *_stdout, *_stderr;

  int  _inc;			
  char _emergency[25];
 
  int _current_category;	
  _CONST char *_current_locale;

  int __sdidinit;		

  void _EXFUN((*__cleanup),(struct _reent *));

  
  struct _Bigint *_result;
  int _result_k;
  struct _Bigint *_p5s;
  struct _Bigint **_freelist;

  
  int _cvtlen;			
  char *_cvtbuf;

  union
    {
      struct
        {
          unsigned int _unused_rand;
          char * _strtok_last;
          char _asctime_buf[26];
          struct tm _localtime_buf;
          int _gamma_signgam;
          __extension__ unsigned long long _rand_next;

        } _reent;
  

 
      struct
        {
#define _N_LISTS 30
          unsigned char * _nextf[_N_LISTS];
          unsigned int _nmalloc[_N_LISTS];
        } _unused;
    } _new;

  
  struct _atexit *_atexit;	
  struct _atexit _atexit0;	

  
  void (**(_sig_func))(int);

  

  struct _glue __sglue;			
  struct __sFILE __sf[3];		
};

#define _REENT_INIT(var) \
  { 0, &var.__sf[0], &var.__sf[1], &var.__sf[2], 0, "", 0, "C", \
    0, NULL, NULL, 0, NULL, NULL, 0, NULL, { {0, NULL, "", \
    { 0,0,0,0,0,0,0,0}, 0, 1} } }

#ifndef __ATTRIBUTE_IMPURE_PTR__
#define __ATTRIBUTE_IMPURE_PTR__
#endif

extern struct _reent *_impure_ptr __ATTRIBUTE_IMPURE_PTR__;

void _reclaim_reent _PARAMS ((struct _reent *));

#ifndef _REENT_ONLY
#define _REENT _impure_ptr
#endif

#ifdef __cplusplus
}
#endif
#endif 

/* ANSI C namespace clean utility typedefs */

#ifndef	_SYS__TYPES_H
#define _SYS__TYPES_H

typedef long _off_t;
typedef long _ssize_t;

#endif	

#ifndef	_MACHTYPES_H_
#define	_MACHTYPES_H_

#define	_CLOCK_T_	unsigned long		/* clock() */
#define	_TIME_T_	long			
#define _CLOCKID_T_ 	unsigned long
#define _TIMER_T_   	unsigned long

#endif	

#define __need_size_t
/* gt4: stand-in for gcc's <stddef.h> (the compiler ships without headers). */
#ifndef _STDDEF_H
#define _STDDEF_H
typedef __SIZE_TYPE__ size_t;
typedef __PTRDIFF_TYPE__ ptrdiff_t;
#ifndef __cplusplus
typedef __WCHAR_TYPE__ wchar_t;
#endif
typedef unsigned int wint_t;
#ifndef NULL
#define NULL ((void *)0)
#endif
#define offsetof(t, m) ((size_t)&((t *)0)->m)
#endif

struct stat;
struct tms;
struct timeval;
struct timezone;

extern int _close_r _PARAMS ((struct _reent *, int));
extern int _execve_r _PARAMS ((struct _reent *, char *, char **, char **));
extern int _fcntl_r _PARAMS ((struct _reent *, int, int, int));
extern int _fork_r _PARAMS ((struct _reent *));
extern int _fstat_r _PARAMS ((struct _reent *, int, struct stat *));
extern int _getpid_r _PARAMS ((struct _reent *));
extern int _kill_r _PARAMS ((struct _reent *, int, int));
extern int _link_r _PARAMS ((struct _reent *, const char *, const char *));
extern _off_t _lseek_r _PARAMS ((struct _reent *, int, _off_t, int));
extern int _open_r _PARAMS ((struct _reent *, const char *, int, int));
extern _ssize_t _read_r _PARAMS ((struct _reent *, int, void *, size_t));
extern void *_sbrk_r _PARAMS ((struct _reent *, size_t));
extern int _stat_r _PARAMS ((struct _reent *, const char *, struct stat *));
extern _CLOCK_T_ _times_r _PARAMS ((struct _reent *, struct tms *));
extern int _unlink_r _PARAMS ((struct _reent *, const char *));
extern int _wait_r _PARAMS ((struct _reent *, int *));
extern _ssize_t _write_r _PARAMS ((struct _reent *, int, const void *, size_t));

extern int _gettimeofday_r _PARAMS ((struct _reent *, struct timeval *tp, struct timezone *tzp));

#ifdef __cplusplus
}
#endif
#endif 

/*
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *	@(#)stdio.h	5.3 (Berkeley) 3/15/86
 */

#ifndef _STDIO_H_
#ifdef __cplusplus
extern "C" {
#endif
#define	_STDIO_H_

/* Provide support for both ANSI and non-ANSI environments.  */

#ifndef	_ANSIDECL_H_
#define	_ANSIDECL_H_

#ifndef __SYS_CONFIG_H__
#define __SYS_CONFIG_H__

/* exceptions first */

#if defined(__H8300__) || defined(__H8500__) || defined (__H8300H__) ||  defined(__W65__) || defined (__H8300S__)
#define _FLOAT_ARG float
#define __SMALL_BITFIELDS
#define _DOUBLE_IS_32BITS
#define __IEEE_BIG_ENDIAN

#define H8300 1
#endif

#ifdef __W65__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_BIG_ENDIAN
#undef INT_MAX
#undef UINT_MAX
#define INT_MAX 32767
#define UINT_MAX 65535

#endif

#if defined(__Z8001__) || defined(__Z8002__) || defined(__H8300__) || defined(__H8500__) || defined(__W65__) || defined (__H8300H__) || defined (__H8300S__) || defined (__mn10200__) || defined (__AVR__)

#undef INT_MAX
#undef UINT_MAX
#define INT_MAX 32767
#define UINT_MAX 65535
#endif

#if defined(__D10V__)
#undef INT_MAX
#undef UINT_MAX
#define INT_MAX __INT_MAX__
#define UINT_MAX (__INT_MAX__ * 2U + 1)
#define _DOUBLE_IS_32BITS
#define _POINTER_INT short
#define __IEEE_BIG_ENDIAN
#endif

#ifdef ___AM29K__
#define _FLOAT_RET double
#endif

#ifdef __i386__
#ifndef __unix__

#define _FLOAT_RET double
#endif
#endif

#ifdef __M32R__
#define __IEEE_BIG_ENDIAN
#endif

#ifdef __m68k__

#define __IEEE_BIG_ENDIAN
#endif

#ifdef __mn10300__
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __mn10200__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __AVR__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_LITTLE_ENDIAN
#define _POINTER_INT short
#endif

#ifdef __TIC80__
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __v850
#define __IEEE_LITTLE_ENDIAN
#define __ATTRIBUTE_IMPURE_PTR__ __attribute__((__sda__))
#endif

#ifdef __D30V__
#define __IEEE_BIG_ENDIAN
#endif

#if defined(__PPC__) && defined(_CALL_SYSV)
#define __ATTRIBUTE_IMPURE_PTR__ __attribute__((__section__(".sdata")))
#endif

#ifdef __sparc__
#ifdef __LITTLE_ENDIAN_DATA__
#define __IEEE_LITTLE_ENDIAN
#else
#define __IEEE_BIG_ENDIAN
#endif
#endif

#if INT_MAX == 32767
typedef long int __int32_t;
typedef unsigned long int __uint32_t;
#else
typedef int __int32_t;
typedef unsigned int __uint32_t;
#endif

#ifndef _POINTER_INT
#define _POINTER_INT long
#endif

#undef __RAND_MAX
#if INT_MAX == 32767
#define __RAND_MAX 32767
#else
#define __RAND_MAX 0x7fffffff
#endif

#if defined(__CYGWIN32__) || defined(__CYGWIN__)
#if defined(__INSIDE_CYGWIN__) || defined(_COMPILING_NEWLIB)
#define __IMPORT
#else
#define __IMPORT __declspec(dllimport)
#endif
#endif

#ifndef __IMPORT
#define __IMPORT
#endif

#endif 

#ifdef __STDC__
#define _HAVE_STDC
#endif

#ifdef _HAVE_STDC
#define	_PTR		void *
#define	_AND		,
#define	_NOARGS		void
#define	_CONST		const
#define	_VOLATILE	volatile
#define	_SIGNED		signed
#define	_DOTS		, ...
#define _VOID void
#ifdef __CYGWIN__
#define	_EXFUN(name, proto)		__cdecl name proto
#define	_EXPARM(name, proto)		(* __cdecl name) proto
#else
#define	_EXFUN(name, proto)		name proto
#define _EXPARM(name, proto)		(* name) proto
#endif
#define	_DEFUN(name, arglist, args)	name(args)
#define	_DEFUN_VOID(name)		name(_NOARGS)
#define _CAST_VOID (void)
#ifndef _LONG_DOUBLE
#define _LONG_DOUBLE long double
#endif
#ifndef _PARAMS
#define _PARAMS(paramlist)		paramlist
#endif
#else	
#define	_PTR		char *
#define	_AND		;
#define	_NOARGS
#define	_CONST
#define	_VOLATILE
#define	_SIGNED
#define	_DOTS
#define _VOID void
#define	_EXFUN(name, proto)		name()
#define	_DEFUN(name, arglist, args)	name arglist args;
#define	_DEFUN_VOID(name)		name()
#define _CAST_VOID
#define _LONG_DOUBLE double
#ifndef _PARAMS
#define _PARAMS(paramlist)		()
#endif
#endif

#ifdef __GNUC__
#define _ATTRIBUTE(attrs) __attribute__ (attrs)
#else
#define _ATTRIBUTE(attrs)
#endif

#endif 

#define	_FSTDIO			

#define __need_size_t
/* gt4: stand-in for gcc's <stddef.h> (the compiler ships without headers). */
#ifndef _STDDEF_H
#define _STDDEF_H
typedef __SIZE_TYPE__ size_t;
typedef __PTRDIFF_TYPE__ ptrdiff_t;
#ifndef __cplusplus
typedef __WCHAR_TYPE__ wchar_t;
#endif
typedef unsigned int wint_t;
#ifndef NULL
#define NULL ((void *)0)
#endif
#define offsetof(t, m) ((size_t)&((t *)0)->m)
#endif

#define __need___va_list
/* gt4: stand-in for gcc's <stdarg.h> (the compiler ships without headers). */
#ifndef _STDARG_H
#define _STDARG_H
#ifndef __GNUC_VA_LIST
#define __GNUC_VA_LIST
typedef __builtin_va_list __gnuc_va_list;
#endif
typedef __gnuc_va_list va_list;
#define va_start(v, l) __builtin_stdarg_start((v), l)
#define va_arg(v, t) __builtin_va_arg((v), t)
#define va_end(v) __builtin_va_end(v)
#endif

/* This header file provides the reentrancy.  */

#ifndef _SYS_REENT_H_
#ifdef __cplusplus
extern "C" {
#endif
#define _SYS_REENT_H_

/* Provide support for both ANSI and non-ANSI environments.  */

#ifndef	_ANSIDECL_H_
#define	_ANSIDECL_H_

#ifndef __SYS_CONFIG_H__
#define __SYS_CONFIG_H__

/* exceptions first */

#if defined(__H8300__) || defined(__H8500__) || defined (__H8300H__) ||  defined(__W65__) || defined (__H8300S__)
#define _FLOAT_ARG float
#define __SMALL_BITFIELDS
#define _DOUBLE_IS_32BITS
#define __IEEE_BIG_ENDIAN

#define H8300 1
#endif

#ifdef __W65__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_BIG_ENDIAN
#undef INT_MAX
#undef UINT_MAX
#define INT_MAX 32767
#define UINT_MAX 65535

#endif

#if defined(__Z8001__) || defined(__Z8002__) || defined(__H8300__) || defined(__H8500__) || defined(__W65__) || defined (__H8300H__) || defined (__H8300S__) || defined (__mn10200__) || defined (__AVR__)

#undef INT_MAX
#undef UINT_MAX
#define INT_MAX 32767
#define UINT_MAX 65535
#endif

#if defined(__D10V__)
#undef INT_MAX
#undef UINT_MAX
#define INT_MAX __INT_MAX__
#define UINT_MAX (__INT_MAX__ * 2U + 1)
#define _DOUBLE_IS_32BITS
#define _POINTER_INT short
#define __IEEE_BIG_ENDIAN
#endif

#ifdef ___AM29K__
#define _FLOAT_RET double
#endif

#ifdef __i386__
#ifndef __unix__

#define _FLOAT_RET double
#endif
#endif

#ifdef __M32R__
#define __IEEE_BIG_ENDIAN
#endif

#ifdef __m68k__

#define __IEEE_BIG_ENDIAN
#endif

#ifdef __mn10300__
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __mn10200__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __AVR__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_LITTLE_ENDIAN
#define _POINTER_INT short
#endif

#ifdef __TIC80__
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __v850
#define __IEEE_LITTLE_ENDIAN
#define __ATTRIBUTE_IMPURE_PTR__ __attribute__((__sda__))
#endif

#ifdef __D30V__
#define __IEEE_BIG_ENDIAN
#endif

#if defined(__PPC__) && defined(_CALL_SYSV)
#define __ATTRIBUTE_IMPURE_PTR__ __attribute__((__section__(".sdata")))
#endif

#ifdef __sparc__
#ifdef __LITTLE_ENDIAN_DATA__
#define __IEEE_LITTLE_ENDIAN
#else
#define __IEEE_BIG_ENDIAN
#endif
#endif

#if INT_MAX == 32767
typedef long int __int32_t;
typedef unsigned long int __uint32_t;
#else
typedef int __int32_t;
typedef unsigned int __uint32_t;
#endif

#ifndef _POINTER_INT
#define _POINTER_INT long
#endif

#undef __RAND_MAX
#if INT_MAX == 32767
#define __RAND_MAX 32767
#else
#define __RAND_MAX 0x7fffffff
#endif

#if defined(__CYGWIN32__) || defined(__CYGWIN__)
#if defined(__INSIDE_CYGWIN__) || defined(_COMPILING_NEWLIB)
#define __IMPORT
#else
#define __IMPORT __declspec(dllimport)
#endif
#endif

#ifndef __IMPORT
#define __IMPORT
#endif

#endif 

#ifdef __STDC__
#define _HAVE_STDC
#endif

#ifdef _HAVE_STDC
#define	_PTR		void *
#define	_AND		,
#define	_NOARGS		void
#define	_CONST		const
#define	_VOLATILE	volatile
#define	_SIGNED		signed
#define	_DOTS		, ...
#define _VOID void
#ifdef __CYGWIN__
#define	_EXFUN(name, proto)		__cdecl name proto
#define	_EXPARM(name, proto)		(* __cdecl name) proto
#else
#define	_EXFUN(name, proto)		name proto
#define _EXPARM(name, proto)		(* name) proto
#endif
#define	_DEFUN(name, arglist, args)	name(args)
#define	_DEFUN_VOID(name)		name(_NOARGS)
#define _CAST_VOID (void)
#ifndef _LONG_DOUBLE
#define _LONG_DOUBLE long double
#endif
#ifndef _PARAMS
#define _PARAMS(paramlist)		paramlist
#endif
#else	
#define	_PTR		char *
#define	_AND		;
#define	_NOARGS
#define	_CONST
#define	_VOLATILE
#define	_SIGNED
#define	_DOTS
#define _VOID void
#define	_EXFUN(name, proto)		name()
#define	_DEFUN(name, arglist, args)	name arglist args;
#define	_DEFUN_VOID(name)		name()
#define _CAST_VOID
#define _LONG_DOUBLE double
#ifndef _PARAMS
#define _PARAMS(paramlist)		()
#endif
#endif

#ifdef __GNUC__
#define _ATTRIBUTE(attrs) __attribute__ (attrs)
#else
#define _ATTRIBUTE(attrs)
#endif

#endif 

/*
 * time.h
 * 
 * Struct and function declarations for dealing with time.
 */

#ifndef _TIME_H_
#define _TIME_H_

/* Provide support for both ANSI and non-ANSI environments.  */

#ifndef	_ANSIDECL_H_
#define	_ANSIDECL_H_

#ifndef __SYS_CONFIG_H__
#define __SYS_CONFIG_H__

/* exceptions first */

#if defined(__H8300__) || defined(__H8500__) || defined (__H8300H__) ||  defined(__W65__) || defined (__H8300S__)
#define _FLOAT_ARG float
#define __SMALL_BITFIELDS
#define _DOUBLE_IS_32BITS
#define __IEEE_BIG_ENDIAN

#define H8300 1
#endif

#ifdef __W65__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_BIG_ENDIAN
#undef INT_MAX
#undef UINT_MAX
#define INT_MAX 32767
#define UINT_MAX 65535

#endif

#if defined(__Z8001__) || defined(__Z8002__) || defined(__H8300__) || defined(__H8500__) || defined(__W65__) || defined (__H8300H__) || defined (__H8300S__) || defined (__mn10200__) || defined (__AVR__)

#undef INT_MAX
#undef UINT_MAX
#define INT_MAX 32767
#define UINT_MAX 65535
#endif

#if defined(__D10V__)
#undef INT_MAX
#undef UINT_MAX
#define INT_MAX __INT_MAX__
#define UINT_MAX (__INT_MAX__ * 2U + 1)
#define _DOUBLE_IS_32BITS
#define _POINTER_INT short
#define __IEEE_BIG_ENDIAN
#endif

#ifdef ___AM29K__
#define _FLOAT_RET double
#endif

#ifdef __i386__
#ifndef __unix__

#define _FLOAT_RET double
#endif
#endif

#ifdef __M32R__
#define __IEEE_BIG_ENDIAN
#endif

#ifdef __m68k__

#define __IEEE_BIG_ENDIAN
#endif

#ifdef __mn10300__
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __mn10200__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __AVR__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_LITTLE_ENDIAN
#define _POINTER_INT short
#endif

#ifdef __TIC80__
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __v850
#define __IEEE_LITTLE_ENDIAN
#define __ATTRIBUTE_IMPURE_PTR__ __attribute__((__sda__))
#endif

#ifdef __D30V__
#define __IEEE_BIG_ENDIAN
#endif

#if defined(__PPC__) && defined(_CALL_SYSV)
#define __ATTRIBUTE_IMPURE_PTR__ __attribute__((__section__(".sdata")))
#endif

#ifdef __sparc__
#ifdef __LITTLE_ENDIAN_DATA__
#define __IEEE_LITTLE_ENDIAN
#else
#define __IEEE_BIG_ENDIAN
#endif
#endif

#if INT_MAX == 32767
typedef long int __int32_t;
typedef unsigned long int __uint32_t;
#else
typedef int __int32_t;
typedef unsigned int __uint32_t;
#endif

#ifndef _POINTER_INT
#define _POINTER_INT long
#endif

#undef __RAND_MAX
#if INT_MAX == 32767
#define __RAND_MAX 32767
#else
#define __RAND_MAX 0x7fffffff
#endif

#if defined(__CYGWIN32__) || defined(__CYGWIN__)
#if defined(__INSIDE_CYGWIN__) || defined(_COMPILING_NEWLIB)
#define __IMPORT
#else
#define __IMPORT __declspec(dllimport)
#endif
#endif

#ifndef __IMPORT
#define __IMPORT
#endif

#endif 

#ifdef __STDC__
#define _HAVE_STDC
#endif

#ifdef _HAVE_STDC
#define	_PTR		void *
#define	_AND		,
#define	_NOARGS		void
#define	_CONST		const
#define	_VOLATILE	volatile
#define	_SIGNED		signed
#define	_DOTS		, ...
#define _VOID void
#ifdef __CYGWIN__
#define	_EXFUN(name, proto)		__cdecl name proto
#define	_EXPARM(name, proto)		(* __cdecl name) proto
#else
#define	_EXFUN(name, proto)		name proto
#define _EXPARM(name, proto)		(* name) proto
#endif
#define	_DEFUN(name, arglist, args)	name(args)
#define	_DEFUN_VOID(name)		name(_NOARGS)
#define _CAST_VOID (void)
#ifndef _LONG_DOUBLE
#define _LONG_DOUBLE long double
#endif
#ifndef _PARAMS
#define _PARAMS(paramlist)		paramlist
#endif
#else	
#define	_PTR		char *
#define	_AND		;
#define	_NOARGS
#define	_CONST
#define	_VOLATILE
#define	_SIGNED
#define	_DOTS
#define _VOID void
#define	_EXFUN(name, proto)		name()
#define	_DEFUN(name, arglist, args)	name arglist args;
#define	_DEFUN_VOID(name)		name()
#define _CAST_VOID
#define _LONG_DOUBLE double
#ifndef _PARAMS
#define _PARAMS(paramlist)		()
#endif
#endif

#ifdef __GNUC__
#define _ATTRIBUTE(attrs) __attribute__ (attrs)
#else
#define _ATTRIBUTE(attrs)
#endif

#endif 

#ifdef __cplusplus
extern "C" {
#endif

#ifndef NULL
#define	NULL	0
#endif

#ifndef	_MACHTIME_H_
#define	_MACHTIME_H_

#if defined(__rtems__)
#define _CLOCKS_PER_SEC_  sysconf(_SC_CLK_TCK)
#else  /* !__rtems__ */
#if defined(__arm__) || defined(__thumb__)
#define _CLOCKS_PER_SEC_ 100
#endif
#endif 

#endif	

#ifndef _CLOCKS_PER_SEC_
#define _CLOCKS_PER_SEC_ 1000
#endif

#define CLOCKS_PER_SEC _CLOCKS_PER_SEC_
#define CLK_TCK CLOCKS_PER_SEC
#define __need_size_t
/* gt4: stand-in for gcc's <stddef.h> (the compiler ships without headers). */
#ifndef _STDDEF_H
#define _STDDEF_H
typedef __SIZE_TYPE__ size_t;
typedef __PTRDIFF_TYPE__ ptrdiff_t;
#ifndef __cplusplus
typedef __WCHAR_TYPE__ wchar_t;
#endif
typedef unsigned int wint_t;
#ifndef NULL
#define NULL ((void *)0)
#endif
#define offsetof(t, m) ((size_t)&((t *)0)->m)
#endif

/* unified sys/types.h: 
   start with sef's sysvi386 version.
   merge go32 version -- a few ifdefs.
   h8300hms, h8300xray, and sysvnecv70 disagree on the following types:

   typedef int gid_t;
   typedef int uid_t;
   typedef int dev_t;
   typedef int ino_t;
   typedef int mode_t;
   typedef int caddr_t;

   however, these aren't "reasonable" values, the sysvi386 ones make far 
   more sense, and should work sufficiently well (in particular, h8300 
   doesn't have a stat, and the necv70 doesn't matter.) -- eichin
 */

#ifndef _SYS_TYPES_H
#define _SYS_TYPES_H

#if defined (_WIN32) || defined (__CYGWIN__)
#define __MS_types__
#endif

#ifdef __i386__
#if defined (GO32) || defined (__MSDOS__)
#define __MS_types__
#endif
#endif

/* gt4: stand-in for gcc's <stddef.h> (the compiler ships without headers). */
#ifndef _STDDEF_H
#define _STDDEF_H
typedef __SIZE_TYPE__ size_t;
typedef __PTRDIFF_TYPE__ ptrdiff_t;
#ifndef __cplusplus
typedef __WCHAR_TYPE__ wchar_t;
#endif
typedef unsigned int wint_t;
#ifndef NULL
#define NULL ((void *)0)
#endif
#define offsetof(t, m) ((size_t)&((t *)0)->m)
#endif

#ifndef	_MACHTYPES_H_
#define	_MACHTYPES_H_

#define	_CLOCK_T_	unsigned long		/* clock() */
#define	_TIME_T_	long			
#define _CLOCKID_T_ 	unsigned long
#define _TIMER_T_   	unsigned long

#endif	

#ifdef __GNUC__
#define _ST_INT32 __attribute__ ((__mode__ (__SI__)))
#else
#define _ST_INT32
#endif

# ifndef	_POSIX_SOURCE

#  define	physadr		physadr_t
#  define	quad		quad_t

#ifndef _WINSOCK_H
typedef	unsigned char	u_char;
typedef	unsigned short	u_short;
typedef	unsigned int	u_int;
typedef	unsigned long	u_long;
#endif

typedef	unsigned short	ushort;		
typedef	unsigned int	uint;		
# endif	

#ifndef __clock_t_defined
typedef _CLOCK_T_ clock_t;
#define __clock_t_defined
#endif

#ifndef __time_t_defined
typedef _TIME_T_ time_t;
#define __time_t_defined

struct timespec {
  time_t  tv_sec;   
  long    tv_nsec;  
};

struct itimerspec {
  struct timespec  it_interval;  
  struct timespec  it_value;     
};
#endif

typedef	long	daddr_t;
typedef	char *	caddr_t;

#ifdef __MS_types__
typedef	unsigned long	ino_t;
#else
#ifdef __sparc__
typedef	unsigned long	ino_t;
#else
typedef	unsigned short	ino_t;
#endif
#endif

#ifdef __MS_types__
typedef unsigned long vm_offset_t;
typedef unsigned long vm_size_t;

#define __BIT_TYPES_DEFINED__

typedef char int8_t;
typedef unsigned char u_int8_t;
typedef short int16_t;
typedef unsigned short u_int16_t;
typedef int int32_t;
typedef unsigned int u_int32_t;
typedef long long int64_t;
typedef unsigned long long u_int64_t;
typedef int32_t register_t;
#endif 

#if defined(__rtems__)

typedef unsigned long long dev_t;
#else
typedef	short	dev_t;
#endif

typedef	long	off_t;

typedef	unsigned short	uid_t;
typedef	unsigned short	gid_t;
typedef int pid_t;
typedef	long key_t;
typedef long ssize_t;

#ifdef __MS_types__
typedef	char *	addr_t;
typedef int mode_t;
#else
#if defined (__sparc__) && !defined (__sparc_v9__)
#ifdef __svr4__
typedef unsigned long mode_t;
#else
typedef unsigned short mode_t;
#endif
#else
typedef unsigned int mode_t _ST_INT32;
#endif
#endif 

typedef unsigned short nlink_t;

# if ! defined (_POSIX_SOURCE) && ! defined (_WINSOCK_H)

#  define	NBBY	8		

#  ifndef	FD_SETSIZE
#	define	FD_SETSIZE	64
#  endif

typedef	long	fd_mask;
#  define	NFDBITS	(sizeof (fd_mask) * NBBY)	
#  ifndef	howmany
#	define	howmany(x,y)	(((x)+((y)-1))/(y))
#  endif

typedef	struct _types_fd_set {
	fd_mask	fds_bits[howmany(FD_SETSIZE, NFDBITS)];
} _types_fd_set;

#define fd_set _types_fd_set

#  define	FD_SET(n, p)	((p)->fds_bits[(n)/NFDBITS] |= (1L << ((n) % NFDBITS)))
#  define	FD_CLR(n, p)	((p)->fds_bits[(n)/NFDBITS] &= ~(1L << ((n) % NFDBITS)))
#  define	FD_ISSET(n, p)	((p)->fds_bits[(n)/NFDBITS] & (1L << ((n) % NFDBITS)))
#  define	FD_ZERO(p)	(__extension__ (void)({ \
     size_t __i; \
     char *__tmp = (char *)p; \
     for (__i = 0; __i < sizeof (*(p)); ++__i) \
       *__tmp++ = 0; \
}))

# endif	

#undef __MS_types__
#undef _ST_INT32

#if defined(__rtems__)

#ifndef __clockid_t_defined
typedef _CLOCKID_T_ clockid_t;
#define __clockid_t_defined
#endif

#ifndef __timer_t_defined
typedef _TIMER_T_ timer_t;
#define __timer_t_defined
#endif

/*
 *  Written by Joel Sherrill <joel@OARcorp.com>.
 *
 *  COPYRIGHT (c) 1989-2000.
 *
 *  On-Line Applications Research Corporation (OAR).
 *
 *  Permission to use, copy, modify, and distribute this software for any
 *  purpose without fee is hereby granted, provided that this entire notice
 *  is included in all copies of any software which is or includes a copy
 *  or modification of this software.
 *
 *  THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 *  WARRANTY.  IN PARTICULAR,  THE AUTHOR MAKES NO REPRESENTATION
 *  OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY OF THIS
 *  SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 *  $Id: features.h,v 1.1 2000/12/12 01:24:08 jjohnstn Exp $
 */

#ifndef _SYS_FEATURES_H
#define _SYS_FEATURES_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __rtems__
#define _POSIX_JOB_CONTROL     		1
#define _POSIX_SAVED_IDS       		1
#define _POSIX_VERSION			199309L
#define _POSIX_ASYNCHRONOUS_IO		1
#define _POSIX_FSYNC			1
#define _POSIX_MAPPED_FILES		1
#define _POSIX_MEMLOCK			1
#define _POSIX_MEMLOCK_RANGE		1
#define _POSIX_MEMORY_PROTECTION	1
#define _POSIX_MESSAGE_PASSING		1
#define _POSIX_PRIORITIZED_IO		1
#define _POSIX_PRIORITY_SCHEDULING	1
#define _POSIX_REALTIME_SIGNALS		1
#define _POSIX_SEMAPHORES		1
#define _POSIX_SHARED_MEMORY_OBJECTS	1
#define _POSIX_SYNCHRONIZED_IO		1
#define _POSIX_TIMERS			1

#define _POSIX_THREADS				1
#define _POSIX_THREAD_ATTR_STACKADDR		1
#define _POSIX_THREAD_ATTR_STACKSIZE		1
#define _POSIX_THREAD_PRIORITY_SCHEDULING	1
#define _POSIX_THREAD_PRIO_INHERIT		1
#define _POSIX_THREAD_PRIO_PROTECT		1
#define _POSIX_THREAD_PROCESS_SHARED		1
#define _POSIX_THREAD_SAFE_FUNCTIONS		1

#define _POSIX_SPAWN				1
#define _POSIX_TIMEOUTS				1
#define _POSIX_CPUTIME				1
#define _POSIX_THREAD_CPUTIME			1
#define _POSIX_SPORADIC_SERVER			1
#define _POSIX_THREAD_SPORADIC_SERVER		1
#define _POSIX_DEVICE_CONTROL			1
#define _POSIX_DEVCTL_DIRECTION			1
#define _POSIX_INTERRUPT_CONTROL		1
#define _POSIX_ADVISORY_INFO			1

#endif

#ifdef __svr4__
# define _POSIX_JOB_CONTROL     1
# define _POSIX_SAVED_IDS       1
# define _POSIX_VERSION 199009L
#endif

#ifdef __CYGWIN32__
# define _POSIX_JOB_CONTROL	1
# define _POSIX_SAVED_IDS	0
# define _POSIX_VERSION		199009L
#endif

#ifdef __cplusplus
}
#endif
#endif 

#if defined(_POSIX_THREADS)

/*
 *  Written by Joel Sherrill <joel@OARcorp.com>.
 *
 *  COPYRIGHT (c) 1989-2000.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  Permission to use, copy, modify, and distribute this software for any
 *  purpose without fee is hereby granted, provided that this entire notice
 *  is included in all copies of any software which is or includes a copy
 *  or modification of this software.
 *
 *  THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 *  WARRANTY.  IN PARTICULAR,  THE AUTHOR MAKES NO REPRESENTATION
 *  OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY OF THIS
 *  SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 *  $Id: sched.h,v 1.1 2000/12/12 01:24:08 jjohnstn Exp $
 */

#ifndef __POSIX_SYS_SCHEDULING_h
#define __POSIX_SYS_SCHEDULING_h

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _SYS_UNISTD_H
#define _SYS_UNISTD_H

#ifdef __cplusplus
extern "C" {
#endif

/* Provide support for both ANSI and non-ANSI environments.  */

#ifndef	_ANSIDECL_H_
#define	_ANSIDECL_H_

#ifndef __SYS_CONFIG_H__
#define __SYS_CONFIG_H__

/* exceptions first */

#if defined(__H8300__) || defined(__H8500__) || defined (__H8300H__) ||  defined(__W65__) || defined (__H8300S__)
#define _FLOAT_ARG float
#define __SMALL_BITFIELDS
#define _DOUBLE_IS_32BITS
#define __IEEE_BIG_ENDIAN

#define H8300 1
#endif

#ifdef __W65__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_BIG_ENDIAN
#undef INT_MAX
#undef UINT_MAX
#define INT_MAX 32767
#define UINT_MAX 65535

#endif

#if defined(__Z8001__) || defined(__Z8002__) || defined(__H8300__) || defined(__H8500__) || defined(__W65__) || defined (__H8300H__) || defined (__H8300S__) || defined (__mn10200__) || defined (__AVR__)

#undef INT_MAX
#undef UINT_MAX
#define INT_MAX 32767
#define UINT_MAX 65535
#endif

#if defined(__D10V__)
#undef INT_MAX
#undef UINT_MAX
#define INT_MAX __INT_MAX__
#define UINT_MAX (__INT_MAX__ * 2U + 1)
#define _DOUBLE_IS_32BITS
#define _POINTER_INT short
#define __IEEE_BIG_ENDIAN
#endif

#ifdef ___AM29K__
#define _FLOAT_RET double
#endif

#ifdef __i386__
#ifndef __unix__

#define _FLOAT_RET double
#endif
#endif

#ifdef __M32R__
#define __IEEE_BIG_ENDIAN
#endif

#ifdef __m68k__

#define __IEEE_BIG_ENDIAN
#endif

#ifdef __mn10300__
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __mn10200__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __AVR__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_LITTLE_ENDIAN
#define _POINTER_INT short
#endif

#ifdef __TIC80__
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __v850
#define __IEEE_LITTLE_ENDIAN
#define __ATTRIBUTE_IMPURE_PTR__ __attribute__((__sda__))
#endif

#ifdef __D30V__
#define __IEEE_BIG_ENDIAN
#endif

#if defined(__PPC__) && defined(_CALL_SYSV)
#define __ATTRIBUTE_IMPURE_PTR__ __attribute__((__section__(".sdata")))
#endif

#ifdef __sparc__
#ifdef __LITTLE_ENDIAN_DATA__
#define __IEEE_LITTLE_ENDIAN
#else
#define __IEEE_BIG_ENDIAN
#endif
#endif

#if INT_MAX == 32767
typedef long int __int32_t;
typedef unsigned long int __uint32_t;
#else
typedef int __int32_t;
typedef unsigned int __uint32_t;
#endif

#ifndef _POINTER_INT
#define _POINTER_INT long
#endif

#undef __RAND_MAX
#if INT_MAX == 32767
#define __RAND_MAX 32767
#else
#define __RAND_MAX 0x7fffffff
#endif

#if defined(__CYGWIN32__) || defined(__CYGWIN__)
#if defined(__INSIDE_CYGWIN__) || defined(_COMPILING_NEWLIB)
#define __IMPORT
#else
#define __IMPORT __declspec(dllimport)
#endif
#endif

#ifndef __IMPORT
#define __IMPORT
#endif

#endif 

#ifdef __STDC__
#define _HAVE_STDC
#endif

#ifdef _HAVE_STDC
#define	_PTR		void *
#define	_AND		,
#define	_NOARGS		void
#define	_CONST		const
#define	_VOLATILE	volatile
#define	_SIGNED		signed
#define	_DOTS		, ...
#define _VOID void
#ifdef __CYGWIN__
#define	_EXFUN(name, proto)		__cdecl name proto
#define	_EXPARM(name, proto)		(* __cdecl name) proto
#else
#define	_EXFUN(name, proto)		name proto
#define _EXPARM(name, proto)		(* name) proto
#endif
#define	_DEFUN(name, arglist, args)	name(args)
#define	_DEFUN_VOID(name)		name(_NOARGS)
#define _CAST_VOID (void)
#ifndef _LONG_DOUBLE
#define _LONG_DOUBLE long double
#endif
#ifndef _PARAMS
#define _PARAMS(paramlist)		paramlist
#endif
#else	
#define	_PTR		char *
#define	_AND		;
#define	_NOARGS
#define	_CONST
#define	_VOLATILE
#define	_SIGNED
#define	_DOTS
#define _VOID void
#define	_EXFUN(name, proto)		name()
#define	_DEFUN(name, arglist, args)	name arglist args;
#define	_DEFUN_VOID(name)		name()
#define _CAST_VOID
#define _LONG_DOUBLE double
#ifndef _PARAMS
#define _PARAMS(paramlist)		()
#endif
#endif

#ifdef __GNUC__
#define _ATTRIBUTE(attrs) __attribute__ (attrs)
#else
#define _ATTRIBUTE(attrs)
#endif

#endif 

/* unified sys/types.h: 
   start with sef's sysvi386 version.
   merge go32 version -- a few ifdefs.
   h8300hms, h8300xray, and sysvnecv70 disagree on the following types:

   typedef int gid_t;
   typedef int uid_t;
   typedef int dev_t;
   typedef int ino_t;
   typedef int mode_t;
   typedef int caddr_t;

   however, these aren't "reasonable" values, the sysvi386 ones make far 
   more sense, and should work sufficiently well (in particular, h8300 
   doesn't have a stat, and the necv70 doesn't matter.) -- eichin
 */

#ifndef _SYS_TYPES_H
#define _SYS_TYPES_H

#if defined (_WIN32) || defined (__CYGWIN__)
#define __MS_types__
#endif

#ifdef __i386__
#if defined (GO32) || defined (__MSDOS__)
#define __MS_types__
#endif
#endif

/* gt4: stand-in for gcc's <stddef.h> (the compiler ships without headers). */
#ifndef _STDDEF_H
#define _STDDEF_H
typedef __SIZE_TYPE__ size_t;
typedef __PTRDIFF_TYPE__ ptrdiff_t;
#ifndef __cplusplus
typedef __WCHAR_TYPE__ wchar_t;
#endif
typedef unsigned int wint_t;
#ifndef NULL
#define NULL ((void *)0)
#endif
#define offsetof(t, m) ((size_t)&((t *)0)->m)
#endif

#ifndef	_MACHTYPES_H_
#define	_MACHTYPES_H_

#define	_CLOCK_T_	unsigned long		/* clock() */
#define	_TIME_T_	long			
#define _CLOCKID_T_ 	unsigned long
#define _TIMER_T_   	unsigned long

#endif	

#ifdef __GNUC__
#define _ST_INT32 __attribute__ ((__mode__ (__SI__)))
#else
#define _ST_INT32
#endif

# ifndef	_POSIX_SOURCE

#  define	physadr		physadr_t
#  define	quad		quad_t

#ifndef _WINSOCK_H
typedef	unsigned char	u_char;
typedef	unsigned short	u_short;
typedef	unsigned int	u_int;
typedef	unsigned long	u_long;
#endif

typedef	unsigned short	ushort;		
typedef	unsigned int	uint;		
# endif	

#ifndef __clock_t_defined
typedef _CLOCK_T_ clock_t;
#define __clock_t_defined
#endif

#ifndef __time_t_defined
typedef _TIME_T_ time_t;
#define __time_t_defined

struct timespec {
  time_t  tv_sec;   
  long    tv_nsec;  
};

struct itimerspec {
  struct timespec  it_interval;  
  struct timespec  it_value;     
};
#endif

typedef	long	daddr_t;
typedef	char *	caddr_t;

#ifdef __MS_types__
typedef	unsigned long	ino_t;
#else
#ifdef __sparc__
typedef	unsigned long	ino_t;
#else
typedef	unsigned short	ino_t;
#endif
#endif

#ifdef __MS_types__
typedef unsigned long vm_offset_t;
typedef unsigned long vm_size_t;

#define __BIT_TYPES_DEFINED__

typedef char int8_t;
typedef unsigned char u_int8_t;
typedef short int16_t;
typedef unsigned short u_int16_t;
typedef int int32_t;
typedef unsigned int u_int32_t;
typedef long long int64_t;
typedef unsigned long long u_int64_t;
typedef int32_t register_t;
#endif 

#if defined(__rtems__)

typedef unsigned long long dev_t;
#else
typedef	short	dev_t;
#endif

typedef	long	off_t;

typedef	unsigned short	uid_t;
typedef	unsigned short	gid_t;
typedef int pid_t;
typedef	long key_t;
typedef long ssize_t;

#ifdef __MS_types__
typedef	char *	addr_t;
typedef int mode_t;
#else
#if defined (__sparc__) && !defined (__sparc_v9__)
#ifdef __svr4__
typedef unsigned long mode_t;
#else
typedef unsigned short mode_t;
#endif
#else
typedef unsigned int mode_t _ST_INT32;
#endif
#endif 

typedef unsigned short nlink_t;

# if ! defined (_POSIX_SOURCE) && ! defined (_WINSOCK_H)

#  define	NBBY	8		

#  ifndef	FD_SETSIZE
#	define	FD_SETSIZE	64
#  endif

typedef	long	fd_mask;
#  define	NFDBITS	(sizeof (fd_mask) * NBBY)	
#  ifndef	howmany
#	define	howmany(x,y)	(((x)+((y)-1))/(y))
#  endif

typedef	struct _types_fd_set {
	fd_mask	fds_bits[howmany(FD_SETSIZE, NFDBITS)];
} _types_fd_set;

#define fd_set _types_fd_set

#  define	FD_SET(n, p)	((p)->fds_bits[(n)/NFDBITS] |= (1L << ((n) % NFDBITS)))
#  define	FD_CLR(n, p)	((p)->fds_bits[(n)/NFDBITS] &= ~(1L << ((n) % NFDBITS)))
#  define	FD_ISSET(n, p)	((p)->fds_bits[(n)/NFDBITS] & (1L << ((n) % NFDBITS)))
#  define	FD_ZERO(p)	(__extension__ (void)({ \
     size_t __i; \
     char *__tmp = (char *)p; \
     for (__i = 0; __i < sizeof (*(p)); ++__i) \
       *__tmp++ = 0; \
}))

# endif	

#undef __MS_types__
#undef _ST_INT32

#if defined(__rtems__)

#ifndef __clockid_t_defined
typedef _CLOCKID_T_ clockid_t;
#define __clockid_t_defined
#endif

#ifndef __timer_t_defined
typedef _TIMER_T_ timer_t;
#define __timer_t_defined
#endif

/*
 *  Written by Joel Sherrill <joel@OARcorp.com>.
 *
 *  COPYRIGHT (c) 1989-2000.
 *
 *  On-Line Applications Research Corporation (OAR).
 *
 *  Permission to use, copy, modify, and distribute this software for any
 *  purpose without fee is hereby granted, provided that this entire notice
 *  is included in all copies of any software which is or includes a copy
 *  or modification of this software.
 *
 *  THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 *  WARRANTY.  IN PARTICULAR,  THE AUTHOR MAKES NO REPRESENTATION
 *  OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY OF THIS
 *  SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 *  $Id: features.h,v 1.1 2000/12/12 01:24:08 jjohnstn Exp $
 */

#ifndef _SYS_FEATURES_H
#define _SYS_FEATURES_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __rtems__
#define _POSIX_JOB_CONTROL     		1
#define _POSIX_SAVED_IDS       		1
#define _POSIX_VERSION			199309L
#define _POSIX_ASYNCHRONOUS_IO		1
#define _POSIX_FSYNC			1
#define _POSIX_MAPPED_FILES		1
#define _POSIX_MEMLOCK			1
#define _POSIX_MEMLOCK_RANGE		1
#define _POSIX_MEMORY_PROTECTION	1
#define _POSIX_MESSAGE_PASSING		1
#define _POSIX_PRIORITIZED_IO		1
#define _POSIX_PRIORITY_SCHEDULING	1
#define _POSIX_REALTIME_SIGNALS		1
#define _POSIX_SEMAPHORES		1
#define _POSIX_SHARED_MEMORY_OBJECTS	1
#define _POSIX_SYNCHRONIZED_IO		1
#define _POSIX_TIMERS			1

#define _POSIX_THREADS				1
#define _POSIX_THREAD_ATTR_STACKADDR		1
#define _POSIX_THREAD_ATTR_STACKSIZE		1
#define _POSIX_THREAD_PRIORITY_SCHEDULING	1
#define _POSIX_THREAD_PRIO_INHERIT		1
#define _POSIX_THREAD_PRIO_PROTECT		1
#define _POSIX_THREAD_PROCESS_SHARED		1
#define _POSIX_THREAD_SAFE_FUNCTIONS		1

#define _POSIX_SPAWN				1
#define _POSIX_TIMEOUTS				1
#define _POSIX_CPUTIME				1
#define _POSIX_THREAD_CPUTIME			1
#define _POSIX_SPORADIC_SERVER			1
#define _POSIX_THREAD_SPORADIC_SERVER		1
#define _POSIX_DEVICE_CONTROL			1
#define _POSIX_DEVCTL_DIRECTION			1
#define _POSIX_INTERRUPT_CONTROL		1
#define _POSIX_ADVISORY_INFO			1

#endif

#ifdef __svr4__
# define _POSIX_JOB_CONTROL     1
# define _POSIX_SAVED_IDS       1
# define _POSIX_VERSION 199009L
#endif

#ifdef __CYGWIN32__
# define _POSIX_JOB_CONTROL	1
# define _POSIX_SAVED_IDS	0
# define _POSIX_VERSION		199009L
#endif

#ifdef __cplusplus
}
#endif
#endif 

#if defined(_POSIX_THREADS)

/*
 *  Written by Joel Sherrill <joel@OARcorp.com>.
 *
 *  COPYRIGHT (c) 1989-2000.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  Permission to use, copy, modify, and distribute this software for any
 *  purpose without fee is hereby granted, provided that this entire notice
 *  is included in all copies of any software which is or includes a copy
 *  or modification of this software.
 *
 *  THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 *  WARRANTY.  IN PARTICULAR,  THE AUTHOR MAKES NO REPRESENTATION
 *  OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY OF THIS
 *  SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 *  $Id: sched.h,v 1.1 2000/12/12 01:24:08 jjohnstn Exp $
 */

#ifndef __POSIX_SYS_SCHEDULING_h
#define __POSIX_SYS_SCHEDULING_h

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/unistd.h>

#include <sys/types.h>
#include <sys/time.h>

#define SCHED_OTHER    0
#define SCHED_FIFO     1
#define SCHED_RR       2

#if defined(_POSIX_SPORADIC_SERVER)
#define SCHED_SPORADIC 3 
#endif

struct sched_param {
  int sched_priority;           

#if defined(_POSIX_SPORADIC_SERVER)
  int ss_low_priority;          
                                
  struct timespec ss_replenish_period; 
                                
  struct timespec ss_initial_budget;   
#endif
};

#ifdef __cplusplus
}
#endif 

#endif

typedef __uint32_t pthread_t;            

#define PTHREAD_SCOPE_PROCESS 0
#define PTHREAD_SCOPE_SYSTEM  1

#define PTHREAD_INHERIT_SCHED  1      
                                      
                                      
#define PTHREAD_EXPLICIT_SCHED 2      

#define PTHREAD_CREATE_DETACHED 0
#define PTHREAD_CREATE_JOINABLE  1

typedef struct {
  int is_initialized;
  void *stackaddr;
  int stacksize;
  int contentionscope;
  int inheritsched;
  int schedpolicy;
  struct sched_param schedparam;

  
#if defined(_POSIX_THREAD_CPUTIME)
  int  cputime_clock_allowed;  
#endif
  int  detachstate;

} pthread_attr_t;

#if defined(_POSIX_THREAD_PROCESS_SHARED)

#define PTHREAD_PROCESS_PRIVATE 0 
#define PTHREAD_PROCESS_SHARED  1 
                                  
                                  
#endif

#if defined(_POSIX_THREAD_PRIO_PROTECT)

#define PTHREAD_PRIO_NONE    0
#define PTHREAD_PRIO_INHERIT 1
#define PTHREAD_PRIO_PROTECT 2
#endif

typedef __uint32_t pthread_mutex_t;      

typedef struct {
  int   is_initialized;
#if defined(_POSIX_THREAD_PROCESS_SHARED)
  int   process_shared;  
#endif
#if defined(_POSIX_THREAD_PRIO_PROTECT)
  int   prio_ceiling;
  int   protocol;
#endif
  int   recursive;
} pthread_mutexattr_t;

typedef __uint32_t pthread_cond_t;       

typedef struct {
  int   is_initialized;
#if defined(_POSIX_THREAD_PROCESS_SHARED)
  int   process_shared;       
#endif
} pthread_condattr_t;         

typedef __uint32_t pthread_key_t;        

typedef struct {
  int   is_initialized;  
  int   init_executed;   
} pthread_once_t;       

#endif 

#endif  

#endif	

#define __need_size_t
#define __need_ptrdiff_t
/* gt4: stand-in for gcc's <stddef.h> (the compiler ships without headers). */
#ifndef _STDDEF_H
#define _STDDEF_H
typedef __SIZE_TYPE__ size_t;
typedef __PTRDIFF_TYPE__ ptrdiff_t;
#ifndef __cplusplus
typedef __WCHAR_TYPE__ wchar_t;
#endif
typedef unsigned int wint_t;
#ifndef NULL
#define NULL ((void *)0)
#endif
#define offsetof(t, m) ((size_t)&((t *)0)->m)
#endif

extern char **environ;

void	_EXFUN(_exit, (int __status ) _ATTRIBUTE ((noreturn)));

int	_EXFUN(access,(const char *__path, int __amode ));
unsigned  _EXFUN(alarm, (unsigned __secs ));
int     _EXFUN(chdir, (const char *__path ));
int     _EXFUN(chmod, (const char *__path, mode_t __mode ));
int     _EXFUN(chown, (const char *__path, uid_t __owner, gid_t __group ));
#ifdef __CYGWIN__
int     _EXFUN(chroot, (const char *__path ));
#endif
int     _EXFUN(close, (int __fildes ));
char    _EXFUN(*ctermid, (char *__s ));
char    _EXFUN(*cuserid, (char *__s ));
int     _EXFUN(dup, (int __fildes ));
int     _EXFUN(dup2, (int __fildes, int __fildes2 ));
int     _EXFUN(execl, (const char *__path, const char *, ... ));
int     _EXFUN(execle, (const char *__path, const char *, ... ));
int     _EXFUN(execlp, (const char *__file, const char *, ... ));
int     _EXFUN(execv, (const char *__path, char * const __argv[] ));
int     _EXFUN(execve, (const char *__path, char * const __argv[], char * const __envp[] ));
int     _EXFUN(execvp, (const char *__file, char * const __argv[] ));
int     _EXFUN(fchmod, (int __fildes, mode_t __mode ));
int     _EXFUN(fchown, (int __fildes, uid_t __owner, gid_t __group ));
pid_t   _EXFUN(fork, (void ));
long    _EXFUN(fpathconf, (int __fd, int __name ));
int     _EXFUN(fsync, (int __fd));
char    _EXFUN(*getcwd, (char *__buf, size_t __size ));
gid_t   _EXFUN(getegid, (void ));
uid_t   _EXFUN(geteuid, (void ));
gid_t   _EXFUN(getgid, (void ));
int     _EXFUN(getgroups, (int __gidsetsize, gid_t __grouplist[] ));
char    _EXFUN(*getlogin, (void ));
#if defined(_POSIX_THREAD_SAFE_FUNCTIONS)
int _EXFUN(getlogin_r, (char *name, size_t namesize) );
#endif
char 	_EXFUN(*getpass, (__const char *__prompt));
size_t  _EXFUN(getpagesize, (void));
pid_t   _EXFUN(getpgrp, (void ));
pid_t   _EXFUN(getpid, (void ));
pid_t   _EXFUN(getppid, (void ));
uid_t   _EXFUN(getuid, (void ));
#ifdef __CYGWIN__
char    _EXFUN(*getwd, (char *__buf ));
#endif
int     _EXFUN(isatty, (int __fildes ));
int     _EXFUN(lchown, (const char *__path, uid_t __owner, gid_t __group ));
int     _EXFUN(link, (const char *__path1, const char *__path2 ));
int	_EXFUN(nice, (int __nice_value ));
off_t   _EXFUN(lseek, (int __fildes, off_t __offset, int __whence ));
long    _EXFUN(pathconf, (const char *__path, int __name ));
int     _EXFUN(pause, (void ));
int     _EXFUN(pipe, (int __fildes[2] ));
/* POSIX 1003.1b-1993 says read() returns ssize_t */
#if defined(__rtems__)
ssize_t	_EXFUN(read, (int __fildes, void *__buf, size_t __nbyte ));
#else
int	_EXFUN(read, (int __fildes, void *__buf, size_t __nbyte ));
#endif
int     _EXFUN(rmdir, (const char *__path ));
#if defined(__rtems__)
void *  _EXFUN(sbrk,  (ptrdiff_t __incr));
#else
void *  _EXFUN(sbrk,  (size_t __incr));
#endif
#if defined(__CYGWIN__)
int     _EXFUN(setegid, (gid_t __gid ));
int     _EXFUN(seteuid, (uid_t __uid ));
#endif
int     _EXFUN(setgid, (gid_t __gid ));
int     _EXFUN(setpgid, (pid_t __pid, pid_t __pgid ));
pid_t   _EXFUN(setsid, (void ));
int     _EXFUN(setuid, (uid_t __uid ));
unsigned _EXFUN(sleep, (unsigned int __seconds ));
void    _EXFUN(swab, (const void *, void *, ssize_t));
long    _EXFUN(sysconf, (int __name ));
pid_t   _EXFUN(tcgetpgrp, (int __fildes ));
int     _EXFUN(tcsetpgrp, (int __fildes, pid_t __pgrp_id ));
char    _EXFUN(*ttyname, (int __fildes ));
int     _EXFUN(unlink, (const char *__path ));

#if defined(__rtems__)
ssize_t     _EXFUN(write, (int __fildes, const void *__buf, size_t __nbyte ));
#else
int     _EXFUN(write, (int __fildes, const void *__buf, size_t __nbyte ));
#endif

#ifndef        _POSIX_SOURCE
pid_t   _EXFUN(vfork, (void ));
#endif 

int     _EXFUN(_close, (int __fildes ));
pid_t   _EXFUN(_fork, (void ));
pid_t   _EXFUN(_getpid, (void ));
int     _EXFUN(_link, (const char *__path1, const char *__path2 ));
off_t   _EXFUN(_lseek, (int __fildes, off_t __offset, int __whence ));
int     _EXFUN(_read, (int __fildes, void *__buf, size_t __nbyte ));
void *  _EXFUN(_sbrk,  (size_t __incr));
int     _EXFUN(_unlink, (const char *__path ));
int     _EXFUN(_write, (int __fildes, const void *__buf, size_t __nbyte ));
int     _EXFUN(_execve, (const char *__path, char * const __argv[], char * const __envp[] ));

#if defined(__CYGWIN__) || defined(__rtems__)
int	_EXFUN(getdtablesize, (void));
void	_EXFUN(setdtablesize, (int));
unsigned _EXFUN(usleep, (unsigned int __useconds));
int     _EXFUN(ftruncate, (int __fd, off_t __length));
int     _EXFUN(truncate, (const char *, off_t __length));
int	_EXFUN(gethostname, (char *__name, size_t __len));
char *	_EXFUN(mktemp, (char *));
int     _EXFUN(sync, (void));
int     _EXFUN(readlink, (const char *__path, char *__buf, int __buflen));
int     _EXFUN(symlink, (const char *__name1, const char *__name2));
#endif

# define	F_OK	0
# define	R_OK	4
# define	W_OK	2
# define	X_OK	1

# define	SEEK_SET	0
# define	SEEK_CUR	1
# define	SEEK_END	2

/*
 *  Written by Joel Sherrill <joel@OARcorp.com>.
 *
 *  COPYRIGHT (c) 1989-2000.
 *
 *  On-Line Applications Research Corporation (OAR).
 *
 *  Permission to use, copy, modify, and distribute this software for any
 *  purpose without fee is hereby granted, provided that this entire notice
 *  is included in all copies of any software which is or includes a copy
 *  or modification of this software.
 *
 *  THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 *  WARRANTY.  IN PARTICULAR,  THE AUTHOR MAKES NO REPRESENTATION
 *  OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY OF THIS
 *  SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 *  $Id: features.h,v 1.1 2000/12/12 01:24:08 jjohnstn Exp $
 */

#ifndef _SYS_FEATURES_H
#define _SYS_FEATURES_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __rtems__
#define _POSIX_JOB_CONTROL     		1
#define _POSIX_SAVED_IDS       		1
#define _POSIX_VERSION			199309L
#define _POSIX_ASYNCHRONOUS_IO		1
#define _POSIX_FSYNC			1
#define _POSIX_MAPPED_FILES		1
#define _POSIX_MEMLOCK			1
#define _POSIX_MEMLOCK_RANGE		1
#define _POSIX_MEMORY_PROTECTION	1
#define _POSIX_MESSAGE_PASSING		1
#define _POSIX_PRIORITIZED_IO		1
#define _POSIX_PRIORITY_SCHEDULING	1
#define _POSIX_REALTIME_SIGNALS		1
#define _POSIX_SEMAPHORES		1
#define _POSIX_SHARED_MEMORY_OBJECTS	1
#define _POSIX_SYNCHRONIZED_IO		1
#define _POSIX_TIMERS			1

#define _POSIX_THREADS				1
#define _POSIX_THREAD_ATTR_STACKADDR		1
#define _POSIX_THREAD_ATTR_STACKSIZE		1
#define _POSIX_THREAD_PRIORITY_SCHEDULING	1
#define _POSIX_THREAD_PRIO_INHERIT		1
#define _POSIX_THREAD_PRIO_PROTECT		1
#define _POSIX_THREAD_PROCESS_SHARED		1
#define _POSIX_THREAD_SAFE_FUNCTIONS		1

#define _POSIX_SPAWN				1
#define _POSIX_TIMEOUTS				1
#define _POSIX_CPUTIME				1
#define _POSIX_THREAD_CPUTIME			1
#define _POSIX_SPORADIC_SERVER			1
#define _POSIX_THREAD_SPORADIC_SERVER		1
#define _POSIX_DEVICE_CONTROL			1
#define _POSIX_DEVCTL_DIRECTION			1
#define _POSIX_INTERRUPT_CONTROL		1
#define _POSIX_ADVISORY_INFO			1

#endif

#ifdef __svr4__
# define _POSIX_JOB_CONTROL     1
# define _POSIX_SAVED_IDS       1
# define _POSIX_VERSION 199009L
#endif

#ifdef __CYGWIN32__
# define _POSIX_JOB_CONTROL	1
# define _POSIX_SAVED_IDS	0
# define _POSIX_VERSION		199009L
#endif

#ifdef __cplusplus
}
#endif
#endif 

#define STDIN_FILENO    0       
#define STDOUT_FILENO   1       
#define STDERR_FILENO   2       

long _EXFUN(sysconf, (int __name));

#define _SC_ARG_MAX                 0
#define _SC_CHILD_MAX               1
#define _SC_CLK_TCK                 2
#define _SC_NGROUPS_MAX             3
#define _SC_OPEN_MAX                4
  
#define _SC_JOB_CONTROL             5
#define _SC_SAVED_IDS               6
#define _SC_VERSION                 7
#define _SC_PAGESIZE                8

#define _SC_NPROCESSORS_CONF        9
#define _SC_NPROCESSORS_ONLN       10
#define _SC_PHYS_PAGES             11
#define _SC_AVPHYS_PAGES           12

#define _SC_MQ_OPEN_MAX            13
#define _SC_MQ_PRIO_MAX            14
#define _SC_RTSIG_MAX              15
#define _SC_SEM_NSEMS_MAX          16
#define _SC_SEM_VALUE_MAX          17
#define _SC_SIGQUEUE_MAX           18
#define _SC_TIMER_MAX              19
#define _SC_TZNAME_MAX             20

#define _SC_ASYNCHRONOUS_IO        21
#define _SC_FSYNC                  22
#define _SC_MAPPED_FILES           23
#define _SC_MEMLOCK                24
#define _SC_MEMLOCK_RANGE          25
#define _SC_MEMORY_PROTECTION      26
#define _SC_MESSAGE_PASSING        27
#define _SC_PRIORITIZED_IO         28
#define _SC_REALTIME_SIGNALS       29
#define _SC_SEMAPHORES             30
#define _SC_SHARED_MEMORY_OBJECTS  31
#define _SC_SYNCHRONIZED_IO        32
#define _SC_TIMERS                 33
#define _SC_AIO_LISTIO_MAX         34
#define _SC_AIO_MAX                35
#define _SC_AIO_PRIO_DELTA_MAX     36
#define _SC_DELAYTIMER_MAX         37

#define _SC_THREAD_KEYS_MAX              38
#define _SC_THREAD_STACK_MIN             39
#define _SC_THREAD_THREADS_MAX           40
#define _SC_TTY_NAME_MAX                 41

#define _SC_THREADS                      42
#define _SC_THREAD_ATTR_STACKADDR        43
#define _SC_THREAD_ATTR_STACKSIZE        44
#define _SC_THREAD_PRIORITY_SCHEDULING   45
#define _SC_THREAD_PRIO_INHERIT          46

#define _SC_THREAD_PRIO_PROTECT          47
#define _SC_THREAD_PRIO_CEILING          _SC_THREAD_PRIO_PROTECT
#define _SC_THREAD_PROCESS_SHARED        48
#define _SC_THREAD_SAFE_FUNCTIONS        49
#define _SC_GETGR_R_SIZE_MAX             50
#define _SC_GETPW_R_SIZE_MAX             51
#define _SC_LOGIN_NAME_MAX               52
#define _SC_THREAD_DESTRUCTOR_ITERATIONS 53
  
# define	_PC_LINK_MAX	        0
# define	_PC_MAX_CANON	        1
# define	_PC_MAX_INPUT	        2
# define	_PC_NAME_MAX	        3
# define	_PC_PATH_MAX	        4
# define	_PC_PIPE_BUF	        5
# define	_PC_CHOWN_RESTRICTED   	6
# define	_PC_NO_TRUNC	        7
# define	_PC_VDISABLE	        8
# define	_PC_ASYNC_IO            9
# define	_PC_PRIO_IO            10
# define	_PC_SYNC_IO            11

#ifdef __CYGWIN__
#define MAXPATHLEN (260 - 1 )
#else
# define	MAXPATHLEN	1024
#endif

#ifdef __cplusplus
}
#endif
#endif 

/* unified sys/types.h: 
   start with sef's sysvi386 version.
   merge go32 version -- a few ifdefs.
   h8300hms, h8300xray, and sysvnecv70 disagree on the following types:

   typedef int gid_t;
   typedef int uid_t;
   typedef int dev_t;
   typedef int ino_t;
   typedef int mode_t;
   typedef int caddr_t;

   however, these aren't "reasonable" values, the sysvi386 ones make far 
   more sense, and should work sufficiently well (in particular, h8300 
   doesn't have a stat, and the necv70 doesn't matter.) -- eichin
 */

#ifndef _SYS_TYPES_H
#define _SYS_TYPES_H

#if defined (_WIN32) || defined (__CYGWIN__)
#define __MS_types__
#endif

#ifdef __i386__
#if defined (GO32) || defined (__MSDOS__)
#define __MS_types__
#endif
#endif

/* gt4: stand-in for gcc's <stddef.h> (the compiler ships without headers). */
#ifndef _STDDEF_H
#define _STDDEF_H
typedef __SIZE_TYPE__ size_t;
typedef __PTRDIFF_TYPE__ ptrdiff_t;
#ifndef __cplusplus
typedef __WCHAR_TYPE__ wchar_t;
#endif
typedef unsigned int wint_t;
#ifndef NULL
#define NULL ((void *)0)
#endif
#define offsetof(t, m) ((size_t)&((t *)0)->m)
#endif

#ifndef	_MACHTYPES_H_
#define	_MACHTYPES_H_

#define	_CLOCK_T_	unsigned long		/* clock() */
#define	_TIME_T_	long			
#define _CLOCKID_T_ 	unsigned long
#define _TIMER_T_   	unsigned long

#endif	

#ifdef __GNUC__
#define _ST_INT32 __attribute__ ((__mode__ (__SI__)))
#else
#define _ST_INT32
#endif

# ifndef	_POSIX_SOURCE

#  define	physadr		physadr_t
#  define	quad		quad_t

#ifndef _WINSOCK_H
typedef	unsigned char	u_char;
typedef	unsigned short	u_short;
typedef	unsigned int	u_int;
typedef	unsigned long	u_long;
#endif

typedef	unsigned short	ushort;		
typedef	unsigned int	uint;		
# endif	

#ifndef __clock_t_defined
typedef _CLOCK_T_ clock_t;
#define __clock_t_defined
#endif

#ifndef __time_t_defined
typedef _TIME_T_ time_t;
#define __time_t_defined

struct timespec {
  time_t  tv_sec;   
  long    tv_nsec;  
};

struct itimerspec {
  struct timespec  it_interval;  
  struct timespec  it_value;     
};
#endif

typedef	long	daddr_t;
typedef	char *	caddr_t;

#ifdef __MS_types__
typedef	unsigned long	ino_t;
#else
#ifdef __sparc__
typedef	unsigned long	ino_t;
#else
typedef	unsigned short	ino_t;
#endif
#endif

#ifdef __MS_types__
typedef unsigned long vm_offset_t;
typedef unsigned long vm_size_t;

#define __BIT_TYPES_DEFINED__

typedef char int8_t;
typedef unsigned char u_int8_t;
typedef short int16_t;
typedef unsigned short u_int16_t;
typedef int int32_t;
typedef unsigned int u_int32_t;
typedef long long int64_t;
typedef unsigned long long u_int64_t;
typedef int32_t register_t;
#endif 

#if defined(__rtems__)

typedef unsigned long long dev_t;
#else
typedef	short	dev_t;
#endif

typedef	long	off_t;

typedef	unsigned short	uid_t;
typedef	unsigned short	gid_t;
typedef int pid_t;
typedef	long key_t;
typedef long ssize_t;

#ifdef __MS_types__
typedef	char *	addr_t;
typedef int mode_t;
#else
#if defined (__sparc__) && !defined (__sparc_v9__)
#ifdef __svr4__
typedef unsigned long mode_t;
#else
typedef unsigned short mode_t;
#endif
#else
typedef unsigned int mode_t _ST_INT32;
#endif
#endif 

typedef unsigned short nlink_t;

# if ! defined (_POSIX_SOURCE) && ! defined (_WINSOCK_H)

#  define	NBBY	8		

#  ifndef	FD_SETSIZE
#	define	FD_SETSIZE	64
#  endif

typedef	long	fd_mask;
#  define	NFDBITS	(sizeof (fd_mask) * NBBY)	
#  ifndef	howmany
#	define	howmany(x,y)	(((x)+((y)-1))/(y))
#  endif

typedef	struct _types_fd_set {
	fd_mask	fds_bits[howmany(FD_SETSIZE, NFDBITS)];
} _types_fd_set;

#define fd_set _types_fd_set

#  define	FD_SET(n, p)	((p)->fds_bits[(n)/NFDBITS] |= (1L << ((n) % NFDBITS)))
#  define	FD_CLR(n, p)	((p)->fds_bits[(n)/NFDBITS] &= ~(1L << ((n) % NFDBITS)))
#  define	FD_ISSET(n, p)	((p)->fds_bits[(n)/NFDBITS] & (1L << ((n) % NFDBITS)))
#  define	FD_ZERO(p)	(__extension__ (void)({ \
     size_t __i; \
     char *__tmp = (char *)p; \
     for (__i = 0; __i < sizeof (*(p)); ++__i) \
       *__tmp++ = 0; \
}))

# endif	

#undef __MS_types__
#undef _ST_INT32

#if defined(__rtems__)

#ifndef __clockid_t_defined
typedef _CLOCKID_T_ clockid_t;
#define __clockid_t_defined
#endif

#ifndef __timer_t_defined
typedef _TIMER_T_ timer_t;
#define __timer_t_defined
#endif

/*
 *  Written by Joel Sherrill <joel@OARcorp.com>.
 *
 *  COPYRIGHT (c) 1989-2000.
 *
 *  On-Line Applications Research Corporation (OAR).
 *
 *  Permission to use, copy, modify, and distribute this software for any
 *  purpose without fee is hereby granted, provided that this entire notice
 *  is included in all copies of any software which is or includes a copy
 *  or modification of this software.
 *
 *  THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 *  WARRANTY.  IN PARTICULAR,  THE AUTHOR MAKES NO REPRESENTATION
 *  OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY OF THIS
 *  SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 *  $Id: features.h,v 1.1 2000/12/12 01:24:08 jjohnstn Exp $
 */

#ifndef _SYS_FEATURES_H
#define _SYS_FEATURES_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __rtems__
#define _POSIX_JOB_CONTROL     		1
#define _POSIX_SAVED_IDS       		1
#define _POSIX_VERSION			199309L
#define _POSIX_ASYNCHRONOUS_IO		1
#define _POSIX_FSYNC			1
#define _POSIX_MAPPED_FILES		1
#define _POSIX_MEMLOCK			1
#define _POSIX_MEMLOCK_RANGE		1
#define _POSIX_MEMORY_PROTECTION	1
#define _POSIX_MESSAGE_PASSING		1
#define _POSIX_PRIORITIZED_IO		1
#define _POSIX_PRIORITY_SCHEDULING	1
#define _POSIX_REALTIME_SIGNALS		1
#define _POSIX_SEMAPHORES		1
#define _POSIX_SHARED_MEMORY_OBJECTS	1
#define _POSIX_SYNCHRONIZED_IO		1
#define _POSIX_TIMERS			1

#define _POSIX_THREADS				1
#define _POSIX_THREAD_ATTR_STACKADDR		1
#define _POSIX_THREAD_ATTR_STACKSIZE		1
#define _POSIX_THREAD_PRIORITY_SCHEDULING	1
#define _POSIX_THREAD_PRIO_INHERIT		1
#define _POSIX_THREAD_PRIO_PROTECT		1
#define _POSIX_THREAD_PROCESS_SHARED		1
#define _POSIX_THREAD_SAFE_FUNCTIONS		1

#define _POSIX_SPAWN				1
#define _POSIX_TIMEOUTS				1
#define _POSIX_CPUTIME				1
#define _POSIX_THREAD_CPUTIME			1
#define _POSIX_SPORADIC_SERVER			1
#define _POSIX_THREAD_SPORADIC_SERVER		1
#define _POSIX_DEVICE_CONTROL			1
#define _POSIX_DEVCTL_DIRECTION			1
#define _POSIX_INTERRUPT_CONTROL		1
#define _POSIX_ADVISORY_INFO			1

#endif

#ifdef __svr4__
# define _POSIX_JOB_CONTROL     1
# define _POSIX_SAVED_IDS       1
# define _POSIX_VERSION 199009L
#endif

#ifdef __CYGWIN32__
# define _POSIX_JOB_CONTROL	1
# define _POSIX_SAVED_IDS	0
# define _POSIX_VERSION		199009L
#endif

#ifdef __cplusplus
}
#endif
#endif 

#if defined(_POSIX_THREADS)

/*
 *  Written by Joel Sherrill <joel@OARcorp.com>.
 *
 *  COPYRIGHT (c) 1989-2000.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  Permission to use, copy, modify, and distribute this software for any
 *  purpose without fee is hereby granted, provided that this entire notice
 *  is included in all copies of any software which is or includes a copy
 *  or modification of this software.
 *
 *  THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 *  WARRANTY.  IN PARTICULAR,  THE AUTHOR MAKES NO REPRESENTATION
 *  OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY OF THIS
 *  SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 *  $Id: sched.h,v 1.1 2000/12/12 01:24:08 jjohnstn Exp $
 */

#ifndef __POSIX_SYS_SCHEDULING_h
#define __POSIX_SYS_SCHEDULING_h

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _SYS_UNISTD_H
#define _SYS_UNISTD_H

#ifdef __cplusplus
extern "C" {
#endif

#include <_ansi.h>
#include <sys/types.h>
#define __need_size_t
#define __need_ptrdiff_t
#include <stddef.h>

extern char **environ;

void	_EXFUN(_exit, (int __status ) _ATTRIBUTE ((noreturn)));

int	_EXFUN(access,(const char *__path, int __amode ));
unsigned  _EXFUN(alarm, (unsigned __secs ));
int     _EXFUN(chdir, (const char *__path ));
int     _EXFUN(chmod, (const char *__path, mode_t __mode ));
int     _EXFUN(chown, (const char *__path, uid_t __owner, gid_t __group ));
#ifdef __CYGWIN__
int     _EXFUN(chroot, (const char *__path ));
#endif
int     _EXFUN(close, (int __fildes ));
char    _EXFUN(*ctermid, (char *__s ));
char    _EXFUN(*cuserid, (char *__s ));
int     _EXFUN(dup, (int __fildes ));
int     _EXFUN(dup2, (int __fildes, int __fildes2 ));
int     _EXFUN(execl, (const char *__path, const char *, ... ));
int     _EXFUN(execle, (const char *__path, const char *, ... ));
int     _EXFUN(execlp, (const char *__file, const char *, ... ));
int     _EXFUN(execv, (const char *__path, char * const __argv[] ));
int     _EXFUN(execve, (const char *__path, char * const __argv[], char * const __envp[] ));
int     _EXFUN(execvp, (const char *__file, char * const __argv[] ));
int     _EXFUN(fchmod, (int __fildes, mode_t __mode ));
int     _EXFUN(fchown, (int __fildes, uid_t __owner, gid_t __group ));
pid_t   _EXFUN(fork, (void ));
long    _EXFUN(fpathconf, (int __fd, int __name ));
int     _EXFUN(fsync, (int __fd));
char    _EXFUN(*getcwd, (char *__buf, size_t __size ));
gid_t   _EXFUN(getegid, (void ));
uid_t   _EXFUN(geteuid, (void ));
gid_t   _EXFUN(getgid, (void ));
int     _EXFUN(getgroups, (int __gidsetsize, gid_t __grouplist[] ));
char    _EXFUN(*getlogin, (void ));
#if defined(_POSIX_THREAD_SAFE_FUNCTIONS)
int _EXFUN(getlogin_r, (char *name, size_t namesize) );
#endif
char 	_EXFUN(*getpass, (__const char *__prompt));
size_t  _EXFUN(getpagesize, (void));
pid_t   _EXFUN(getpgrp, (void ));
pid_t   _EXFUN(getpid, (void ));
pid_t   _EXFUN(getppid, (void ));
uid_t   _EXFUN(getuid, (void ));
#ifdef __CYGWIN__
char    _EXFUN(*getwd, (char *__buf ));
#endif
int     _EXFUN(isatty, (int __fildes ));
int     _EXFUN(lchown, (const char *__path, uid_t __owner, gid_t __group ));
int     _EXFUN(link, (const char *__path1, const char *__path2 ));
int	_EXFUN(nice, (int __nice_value ));
off_t   _EXFUN(lseek, (int __fildes, off_t __offset, int __whence ));
long    _EXFUN(pathconf, (const char *__path, int __name ));
int     _EXFUN(pause, (void ));
int     _EXFUN(pipe, (int __fildes[2] ));
/* POSIX 1003.1b-1993 says read() returns ssize_t */
#if defined(__rtems__)
ssize_t	_EXFUN(read, (int __fildes, void *__buf, size_t __nbyte ));
#else
int	_EXFUN(read, (int __fildes, void *__buf, size_t __nbyte ));
#endif
int     _EXFUN(rmdir, (const char *__path ));
#if defined(__rtems__)
void *  _EXFUN(sbrk,  (ptrdiff_t __incr));
#else
void *  _EXFUN(sbrk,  (size_t __incr));
#endif
#if defined(__CYGWIN__)
int     _EXFUN(setegid, (gid_t __gid ));
int     _EXFUN(seteuid, (uid_t __uid ));
#endif
int     _EXFUN(setgid, (gid_t __gid ));
int     _EXFUN(setpgid, (pid_t __pid, pid_t __pgid ));
pid_t   _EXFUN(setsid, (void ));
int     _EXFUN(setuid, (uid_t __uid ));
unsigned _EXFUN(sleep, (unsigned int __seconds ));
void    _EXFUN(swab, (const void *, void *, ssize_t));
long    _EXFUN(sysconf, (int __name ));
pid_t   _EXFUN(tcgetpgrp, (int __fildes ));
int     _EXFUN(tcsetpgrp, (int __fildes, pid_t __pgrp_id ));
char    _EXFUN(*ttyname, (int __fildes ));
int     _EXFUN(unlink, (const char *__path ));

#if defined(__rtems__)
ssize_t     _EXFUN(write, (int __fildes, const void *__buf, size_t __nbyte ));
#else
int     _EXFUN(write, (int __fildes, const void *__buf, size_t __nbyte ));
#endif

#ifndef        _POSIX_SOURCE
pid_t   _EXFUN(vfork, (void ));
#endif 

int     _EXFUN(_close, (int __fildes ));
pid_t   _EXFUN(_fork, (void ));
pid_t   _EXFUN(_getpid, (void ));
int     _EXFUN(_link, (const char *__path1, const char *__path2 ));
off_t   _EXFUN(_lseek, (int __fildes, off_t __offset, int __whence ));
int     _EXFUN(_read, (int __fildes, void *__buf, size_t __nbyte ));
void *  _EXFUN(_sbrk,  (size_t __incr));
int     _EXFUN(_unlink, (const char *__path ));
int     _EXFUN(_write, (int __fildes, const void *__buf, size_t __nbyte ));
int     _EXFUN(_execve, (const char *__path, char * const __argv[], char * const __envp[] ));

#if defined(__CYGWIN__) || defined(__rtems__)
int	_EXFUN(getdtablesize, (void));
void	_EXFUN(setdtablesize, (int));
unsigned _EXFUN(usleep, (unsigned int __useconds));
int     _EXFUN(ftruncate, (int __fd, off_t __length));
int     _EXFUN(truncate, (const char *, off_t __length));
int	_EXFUN(gethostname, (char *__name, size_t __len));
char *	_EXFUN(mktemp, (char *));
int     _EXFUN(sync, (void));
int     _EXFUN(readlink, (const char *__path, char *__buf, int __buflen));
int     _EXFUN(symlink, (const char *__name1, const char *__name2));
#endif

# define	F_OK	0
# define	R_OK	4
# define	W_OK	2
# define	X_OK	1

# define	SEEK_SET	0
# define	SEEK_CUR	1
# define	SEEK_END	2

#include <sys/features.h>

#define STDIN_FILENO    0       
#define STDOUT_FILENO   1       
#define STDERR_FILENO   2       

long _EXFUN(sysconf, (int __name));

#define _SC_ARG_MAX                 0
#define _SC_CHILD_MAX               1
#define _SC_CLK_TCK                 2
#define _SC_NGROUPS_MAX             3
#define _SC_OPEN_MAX                4
  
#define _SC_JOB_CONTROL             5
#define _SC_SAVED_IDS               6
#define _SC_VERSION                 7
#define _SC_PAGESIZE                8

#define _SC_NPROCESSORS_CONF        9
#define _SC_NPROCESSORS_ONLN       10
#define _SC_PHYS_PAGES             11
#define _SC_AVPHYS_PAGES           12

#define _SC_MQ_OPEN_MAX            13
#define _SC_MQ_PRIO_MAX            14
#define _SC_RTSIG_MAX              15
#define _SC_SEM_NSEMS_MAX          16
#define _SC_SEM_VALUE_MAX          17
#define _SC_SIGQUEUE_MAX           18
#define _SC_TIMER_MAX              19
#define _SC_TZNAME_MAX             20

#define _SC_ASYNCHRONOUS_IO        21
#define _SC_FSYNC                  22
#define _SC_MAPPED_FILES           23
#define _SC_MEMLOCK                24
#define _SC_MEMLOCK_RANGE          25
#define _SC_MEMORY_PROTECTION      26
#define _SC_MESSAGE_PASSING        27
#define _SC_PRIORITIZED_IO         28
#define _SC_REALTIME_SIGNALS       29
#define _SC_SEMAPHORES             30
#define _SC_SHARED_MEMORY_OBJECTS  31
#define _SC_SYNCHRONIZED_IO        32
#define _SC_TIMERS                 33
#define _SC_AIO_LISTIO_MAX         34
#define _SC_AIO_MAX                35
#define _SC_AIO_PRIO_DELTA_MAX     36
#define _SC_DELAYTIMER_MAX         37

#define _SC_THREAD_KEYS_MAX              38
#define _SC_THREAD_STACK_MIN             39
#define _SC_THREAD_THREADS_MAX           40
#define _SC_TTY_NAME_MAX                 41

#define _SC_THREADS                      42
#define _SC_THREAD_ATTR_STACKADDR        43
#define _SC_THREAD_ATTR_STACKSIZE        44
#define _SC_THREAD_PRIORITY_SCHEDULING   45
#define _SC_THREAD_PRIO_INHERIT          46

#define _SC_THREAD_PRIO_PROTECT          47
#define _SC_THREAD_PRIO_CEILING          _SC_THREAD_PRIO_PROTECT
#define _SC_THREAD_PROCESS_SHARED        48
#define _SC_THREAD_SAFE_FUNCTIONS        49
#define _SC_GETGR_R_SIZE_MAX             50
#define _SC_GETPW_R_SIZE_MAX             51
#define _SC_LOGIN_NAME_MAX               52
#define _SC_THREAD_DESTRUCTOR_ITERATIONS 53
  
# define	_PC_LINK_MAX	        0
# define	_PC_MAX_CANON	        1
# define	_PC_MAX_INPUT	        2
# define	_PC_NAME_MAX	        3
# define	_PC_PATH_MAX	        4
# define	_PC_PIPE_BUF	        5
# define	_PC_CHOWN_RESTRICTED   	6
# define	_PC_NO_TRUNC	        7
# define	_PC_VDISABLE	        8
# define	_PC_ASYNC_IO            9
# define	_PC_PRIO_IO            10
# define	_PC_SYNC_IO            11

#ifdef __CYGWIN__
#define MAXPATHLEN (260 - 1 )
#else
# define	MAXPATHLEN	1024
#endif

#ifdef __cplusplus
}
#endif
#endif 

/* unified sys/types.h: 
   start with sef's sysvi386 version.
   merge go32 version -- a few ifdefs.
   h8300hms, h8300xray, and sysvnecv70 disagree on the following types:

   typedef int gid_t;
   typedef int uid_t;
   typedef int dev_t;
   typedef int ino_t;
   typedef int mode_t;
   typedef int caddr_t;

   however, these aren't "reasonable" values, the sysvi386 ones make far 
   more sense, and should work sufficiently well (in particular, h8300 
   doesn't have a stat, and the necv70 doesn't matter.) -- eichin
 */

#ifndef _SYS_TYPES_H
#define _SYS_TYPES_H

#if defined (_WIN32) || defined (__CYGWIN__)
#define __MS_types__
#endif

#ifdef __i386__
#if defined (GO32) || defined (__MSDOS__)
#define __MS_types__
#endif
#endif

# include <stddef.h>
# include <machine/types.h>

#ifdef __GNUC__
#define _ST_INT32 __attribute__ ((__mode__ (__SI__)))
#else
#define _ST_INT32
#endif

# ifndef	_POSIX_SOURCE

#  define	physadr		physadr_t
#  define	quad		quad_t

#ifndef _WINSOCK_H
typedef	unsigned char	u_char;
typedef	unsigned short	u_short;
typedef	unsigned int	u_int;
typedef	unsigned long	u_long;
#endif

typedef	unsigned short	ushort;		
typedef	unsigned int	uint;		
# endif	

#ifndef __clock_t_defined
typedef _CLOCK_T_ clock_t;
#define __clock_t_defined
#endif

#ifndef __time_t_defined
typedef _TIME_T_ time_t;
#define __time_t_defined

struct timespec {
  time_t  tv_sec;   
  long    tv_nsec;  
};

struct itimerspec {
  struct timespec  it_interval;  
  struct timespec  it_value;     
};
#endif

typedef	long	daddr_t;
typedef	char *	caddr_t;

#ifdef __MS_types__
typedef	unsigned long	ino_t;
#else
#ifdef __sparc__
typedef	unsigned long	ino_t;
#else
typedef	unsigned short	ino_t;
#endif
#endif

#ifdef __MS_types__
typedef unsigned long vm_offset_t;
typedef unsigned long vm_size_t;

#define __BIT_TYPES_DEFINED__

typedef char int8_t;
typedef unsigned char u_int8_t;
typedef short int16_t;
typedef unsigned short u_int16_t;
typedef int int32_t;
typedef unsigned int u_int32_t;
typedef long long int64_t;
typedef unsigned long long u_int64_t;
typedef int32_t register_t;
#endif 

#if defined(__rtems__)

typedef unsigned long long dev_t;
#else
typedef	short	dev_t;
#endif

typedef	long	off_t;

typedef	unsigned short	uid_t;
typedef	unsigned short	gid_t;
typedef int pid_t;
typedef	long key_t;
typedef long ssize_t;

#ifdef __MS_types__
typedef	char *	addr_t;
typedef int mode_t;
#else
#if defined (__sparc__) && !defined (__sparc_v9__)
#ifdef __svr4__
typedef unsigned long mode_t;
#else
typedef unsigned short mode_t;
#endif
#else
typedef unsigned int mode_t _ST_INT32;
#endif
#endif 

typedef unsigned short nlink_t;

# if ! defined (_POSIX_SOURCE) && ! defined (_WINSOCK_H)

#  define	NBBY	8		

#  ifndef	FD_SETSIZE
#	define	FD_SETSIZE	64
#  endif

typedef	long	fd_mask;
#  define	NFDBITS	(sizeof (fd_mask) * NBBY)	
#  ifndef	howmany
#	define	howmany(x,y)	(((x)+((y)-1))/(y))
#  endif

typedef	struct _types_fd_set {
	fd_mask	fds_bits[howmany(FD_SETSIZE, NFDBITS)];
} _types_fd_set;

#define fd_set _types_fd_set

#  define	FD_SET(n, p)	((p)->fds_bits[(n)/NFDBITS] |= (1L << ((n) % NFDBITS)))
#  define	FD_CLR(n, p)	((p)->fds_bits[(n)/NFDBITS] &= ~(1L << ((n) % NFDBITS)))
#  define	FD_ISSET(n, p)	((p)->fds_bits[(n)/NFDBITS] & (1L << ((n) % NFDBITS)))
#  define	FD_ZERO(p)	(__extension__ (void)({ \
     size_t __i; \
     char *__tmp = (char *)p; \
     for (__i = 0; __i < sizeof (*(p)); ++__i) \
       *__tmp++ = 0; \
}))

# endif	

#undef __MS_types__
#undef _ST_INT32

#if defined(__rtems__)

#ifndef __clockid_t_defined
typedef _CLOCKID_T_ clockid_t;
#define __clockid_t_defined
#endif

#ifndef __timer_t_defined
typedef _TIMER_T_ timer_t;
#define __timer_t_defined
#endif

#include <sys/features.h>

#if defined(_POSIX_THREADS)

#include <sys/sched.h>

typedef __uint32_t pthread_t;            

#define PTHREAD_SCOPE_PROCESS 0
#define PTHREAD_SCOPE_SYSTEM  1

#define PTHREAD_INHERIT_SCHED  1      
                                      
                                      
#define PTHREAD_EXPLICIT_SCHED 2      

#define PTHREAD_CREATE_DETACHED 0
#define PTHREAD_CREATE_JOINABLE  1

typedef struct {
  int is_initialized;
  void *stackaddr;
  int stacksize;
  int contentionscope;
  int inheritsched;
  int schedpolicy;
  struct sched_param schedparam;

  
#if defined(_POSIX_THREAD_CPUTIME)
  int  cputime_clock_allowed;  
#endif
  int  detachstate;

} pthread_attr_t;

#if defined(_POSIX_THREAD_PROCESS_SHARED)

#define PTHREAD_PROCESS_PRIVATE 0 
#define PTHREAD_PROCESS_SHARED  1 
                                  
                                  
#endif

#if defined(_POSIX_THREAD_PRIO_PROTECT)

#define PTHREAD_PRIO_NONE    0
#define PTHREAD_PRIO_INHERIT 1
#define PTHREAD_PRIO_PROTECT 2
#endif

typedef __uint32_t pthread_mutex_t;      

typedef struct {
  int   is_initialized;
#if defined(_POSIX_THREAD_PROCESS_SHARED)
  int   process_shared;  
#endif
#if defined(_POSIX_THREAD_PRIO_PROTECT)
  int   prio_ceiling;
  int   protocol;
#endif
  int   recursive;
} pthread_mutexattr_t;

typedef __uint32_t pthread_cond_t;       

typedef struct {
  int   is_initialized;
#if defined(_POSIX_THREAD_PROCESS_SHARED)
  int   process_shared;       
#endif
} pthread_condattr_t;         

typedef __uint32_t pthread_key_t;        

typedef struct {
  int   is_initialized;  
  int   init_executed;   
} pthread_once_t;       

#endif 

#endif  

#endif	

/* time.h -- An implementation of the standard Unix <sys/time.h> file.
   Written by Geoffrey Noer <noer@cygnus.com>
   Public domain; no rights reserved. */

#ifndef _SYS_TIME_H_
#define _SYS_TIME_H_

#include <_ansi.h>
#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _WINSOCK_H
struct timeval {
  long tv_sec;
  long tv_usec;
};

struct timezone {
  int tz_minuteswest;
  int tz_dsttime;
};

#ifdef __CYGWIN__
#include <sys/select.h>
#endif 

#endif 

#define ITIMER_REAL     0
#define ITIMER_VIRTUAL  1
#define ITIMER_PROF     2

struct  itimerval {
  struct  timeval it_interval;
  struct  timeval it_value;
};

#if defined(__rtems__)

#define	timerisset(tvp)		((tvp)->tv_sec || (tvp)->tv_usec)
#define	timerclear(tvp)		((tvp)->tv_sec = (tvp)->tv_usec = 0)
#define	timercmp(a, b, CMP) 						      \
  (((a)->tv_sec == (b)->tv_sec) ? 					      \
   ((a)->tv_usec CMP (b)->tv_usec) : 					      \
   ((a)->tv_sec CMP (b)->tv_sec))
#define	timeradd(a, b, result)						      \
  do {									      \
    (result)->tv_sec = (a)->tv_sec + (b)->tv_sec;			      \
    (result)->tv_usec = (a)->tv_usec + (b)->tv_usec;			      \
    if ((result)->tv_usec >= 1000000)					      \
      {									      \
	++(result)->tv_sec;						      \
	(result)->tv_usec -= 1000000;					      \
      }									      \
  } while (0)
#define	timersub(a, b, result)						      \
  do {									      \
    (result)->tv_sec = (a)->tv_sec - (b)->tv_sec;			      \
    (result)->tv_usec = (a)->tv_usec - (b)->tv_usec;			      \
    if ((result)->tv_usec < 0) {					      \
      --(result)->tv_sec;						      \
      (result)->tv_usec += 1000000;					      \
    }									      \
  } while (0)
#endif

int _EXFUN(gettimeofday, (struct timeval *__p, struct timezone *__z));
int _EXFUN(settimeofday, (const struct timeval *, const struct timezone *));
int _EXFUN(utimes, (const char *__path, struct timeval *__tvp));
int _EXFUN(getitimer, (int __which, struct itimerval *__value));
int _EXFUN(setitimer, (int __which, const struct itimerval *__value,
					struct itimerval *__ovalue));

#ifdef __cplusplus
}
#endif
#endif 

#define SCHED_OTHER    0
#define SCHED_FIFO     1
#define SCHED_RR       2

#if defined(_POSIX_SPORADIC_SERVER)
#define SCHED_SPORADIC 3 
#endif

struct sched_param {
  int sched_priority;           

#if defined(_POSIX_SPORADIC_SERVER)
  int ss_low_priority;          
                                
  struct timespec ss_replenish_period; 
                                
  struct timespec ss_initial_budget;   
#endif
};

#ifdef __cplusplus
}
#endif 

#endif

typedef __uint32_t pthread_t;            

#define PTHREAD_SCOPE_PROCESS 0
#define PTHREAD_SCOPE_SYSTEM  1

#define PTHREAD_INHERIT_SCHED  1      
                                      
                                      
#define PTHREAD_EXPLICIT_SCHED 2      

#define PTHREAD_CREATE_DETACHED 0
#define PTHREAD_CREATE_JOINABLE  1

typedef struct {
  int is_initialized;
  void *stackaddr;
  int stacksize;
  int contentionscope;
  int inheritsched;
  int schedpolicy;
  struct sched_param schedparam;

  
#if defined(_POSIX_THREAD_CPUTIME)
  int  cputime_clock_allowed;  
#endif
  int  detachstate;

} pthread_attr_t;

#if defined(_POSIX_THREAD_PROCESS_SHARED)

#define PTHREAD_PROCESS_PRIVATE 0 
#define PTHREAD_PROCESS_SHARED  1 
                                  
                                  
#endif

#if defined(_POSIX_THREAD_PRIO_PROTECT)

#define PTHREAD_PRIO_NONE    0
#define PTHREAD_PRIO_INHERIT 1
#define PTHREAD_PRIO_PROTECT 2
#endif

typedef __uint32_t pthread_mutex_t;      

typedef struct {
  int   is_initialized;
#if defined(_POSIX_THREAD_PROCESS_SHARED)
  int   process_shared;  
#endif
#if defined(_POSIX_THREAD_PRIO_PROTECT)
  int   prio_ceiling;
  int   protocol;
#endif
  int   recursive;
} pthread_mutexattr_t;

typedef __uint32_t pthread_cond_t;       

typedef struct {
  int   is_initialized;
#if defined(_POSIX_THREAD_PROCESS_SHARED)
  int   process_shared;       
#endif
} pthread_condattr_t;         

typedef __uint32_t pthread_key_t;        

typedef struct {
  int   is_initialized;  
  int   init_executed;   
} pthread_once_t;       

#endif 

#endif  

#endif	

/* time.h -- An implementation of the standard Unix <sys/time.h> file.
   Written by Geoffrey Noer <noer@cygnus.com>
   Public domain; no rights reserved. */

#ifndef _SYS_TIME_H_
#define _SYS_TIME_H_

/* Provide support for both ANSI and non-ANSI environments.  */

#ifndef	_ANSIDECL_H_
#define	_ANSIDECL_H_

#ifndef __SYS_CONFIG_H__
#define __SYS_CONFIG_H__

/* exceptions first */

#if defined(__H8300__) || defined(__H8500__) || defined (__H8300H__) ||  defined(__W65__) || defined (__H8300S__)
#define _FLOAT_ARG float
#define __SMALL_BITFIELDS
#define _DOUBLE_IS_32BITS
#define __IEEE_BIG_ENDIAN

#define H8300 1
#endif

#ifdef __W65__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_BIG_ENDIAN
#undef INT_MAX
#undef UINT_MAX
#define INT_MAX 32767
#define UINT_MAX 65535

#endif

#if defined(__Z8001__) || defined(__Z8002__) || defined(__H8300__) || defined(__H8500__) || defined(__W65__) || defined (__H8300H__) || defined (__H8300S__) || defined (__mn10200__) || defined (__AVR__)

#undef INT_MAX
#undef UINT_MAX
#define INT_MAX 32767
#define UINT_MAX 65535
#endif

#if defined(__D10V__)
#undef INT_MAX
#undef UINT_MAX
#define INT_MAX __INT_MAX__
#define UINT_MAX (__INT_MAX__ * 2U + 1)
#define _DOUBLE_IS_32BITS
#define _POINTER_INT short
#define __IEEE_BIG_ENDIAN
#endif

#ifdef ___AM29K__
#define _FLOAT_RET double
#endif

#ifdef __i386__
#ifndef __unix__

#define _FLOAT_RET double
#endif
#endif

#ifdef __M32R__
#define __IEEE_BIG_ENDIAN
#endif

#ifdef __m68k__

#define __IEEE_BIG_ENDIAN
#endif

#ifdef __mn10300__
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __mn10200__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __AVR__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_LITTLE_ENDIAN
#define _POINTER_INT short
#endif

#ifdef __TIC80__
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __v850
#define __IEEE_LITTLE_ENDIAN
#define __ATTRIBUTE_IMPURE_PTR__ __attribute__((__sda__))
#endif

#ifdef __D30V__
#define __IEEE_BIG_ENDIAN
#endif

#if defined(__PPC__) && defined(_CALL_SYSV)
#define __ATTRIBUTE_IMPURE_PTR__ __attribute__((__section__(".sdata")))
#endif

#ifdef __sparc__
#ifdef __LITTLE_ENDIAN_DATA__
#define __IEEE_LITTLE_ENDIAN
#else
#define __IEEE_BIG_ENDIAN
#endif
#endif

#if INT_MAX == 32767
typedef long int __int32_t;
typedef unsigned long int __uint32_t;
#else
typedef int __int32_t;
typedef unsigned int __uint32_t;
#endif

#ifndef _POINTER_INT
#define _POINTER_INT long
#endif

#undef __RAND_MAX
#if INT_MAX == 32767
#define __RAND_MAX 32767
#else
#define __RAND_MAX 0x7fffffff
#endif

#if defined(__CYGWIN32__) || defined(__CYGWIN__)
#if defined(__INSIDE_CYGWIN__) || defined(_COMPILING_NEWLIB)
#define __IMPORT
#else
#define __IMPORT __declspec(dllimport)
#endif
#endif

#ifndef __IMPORT
#define __IMPORT
#endif

#endif 

#ifdef __STDC__
#define _HAVE_STDC
#endif

#ifdef _HAVE_STDC
#define	_PTR		void *
#define	_AND		,
#define	_NOARGS		void
#define	_CONST		const
#define	_VOLATILE	volatile
#define	_SIGNED		signed
#define	_DOTS		, ...
#define _VOID void
#ifdef __CYGWIN__
#define	_EXFUN(name, proto)		__cdecl name proto
#define	_EXPARM(name, proto)		(* __cdecl name) proto
#else
#define	_EXFUN(name, proto)		name proto
#define _EXPARM(name, proto)		(* name) proto
#endif
#define	_DEFUN(name, arglist, args)	name(args)
#define	_DEFUN_VOID(name)		name(_NOARGS)
#define _CAST_VOID (void)
#ifndef _LONG_DOUBLE
#define _LONG_DOUBLE long double
#endif
#ifndef _PARAMS
#define _PARAMS(paramlist)		paramlist
#endif
#else	
#define	_PTR		char *
#define	_AND		;
#define	_NOARGS
#define	_CONST
#define	_VOLATILE
#define	_SIGNED
#define	_DOTS
#define _VOID void
#define	_EXFUN(name, proto)		name()
#define	_DEFUN(name, arglist, args)	name arglist args;
#define	_DEFUN_VOID(name)		name()
#define _CAST_VOID
#define _LONG_DOUBLE double
#ifndef _PARAMS
#define _PARAMS(paramlist)		()
#endif
#endif

#ifdef __GNUC__
#define _ATTRIBUTE(attrs) __attribute__ (attrs)
#else
#define _ATTRIBUTE(attrs)
#endif

#endif 

/* unified sys/types.h: 
   start with sef's sysvi386 version.
   merge go32 version -- a few ifdefs.
   h8300hms, h8300xray, and sysvnecv70 disagree on the following types:

   typedef int gid_t;
   typedef int uid_t;
   typedef int dev_t;
   typedef int ino_t;
   typedef int mode_t;
   typedef int caddr_t;

   however, these aren't "reasonable" values, the sysvi386 ones make far 
   more sense, and should work sufficiently well (in particular, h8300 
   doesn't have a stat, and the necv70 doesn't matter.) -- eichin
 */

#ifndef _SYS_TYPES_H
#define _SYS_TYPES_H

#if defined (_WIN32) || defined (__CYGWIN__)
#define __MS_types__
#endif

#ifdef __i386__
#if defined (GO32) || defined (__MSDOS__)
#define __MS_types__
#endif
#endif

/* gt4: stand-in for gcc's <stddef.h> (the compiler ships without headers). */
#ifndef _STDDEF_H
#define _STDDEF_H
typedef __SIZE_TYPE__ size_t;
typedef __PTRDIFF_TYPE__ ptrdiff_t;
#ifndef __cplusplus
typedef __WCHAR_TYPE__ wchar_t;
#endif
typedef unsigned int wint_t;
#ifndef NULL
#define NULL ((void *)0)
#endif
#define offsetof(t, m) ((size_t)&((t *)0)->m)
#endif

#ifndef	_MACHTYPES_H_
#define	_MACHTYPES_H_

#define	_CLOCK_T_	unsigned long		/* clock() */
#define	_TIME_T_	long			
#define _CLOCKID_T_ 	unsigned long
#define _TIMER_T_   	unsigned long

#endif	

#ifdef __GNUC__
#define _ST_INT32 __attribute__ ((__mode__ (__SI__)))
#else
#define _ST_INT32
#endif

# ifndef	_POSIX_SOURCE

#  define	physadr		physadr_t
#  define	quad		quad_t

#ifndef _WINSOCK_H
typedef	unsigned char	u_char;
typedef	unsigned short	u_short;
typedef	unsigned int	u_int;
typedef	unsigned long	u_long;
#endif

typedef	unsigned short	ushort;		
typedef	unsigned int	uint;		
# endif	

#ifndef __clock_t_defined
typedef _CLOCK_T_ clock_t;
#define __clock_t_defined
#endif

#ifndef __time_t_defined
typedef _TIME_T_ time_t;
#define __time_t_defined

struct timespec {
  time_t  tv_sec;   
  long    tv_nsec;  
};

struct itimerspec {
  struct timespec  it_interval;  
  struct timespec  it_value;     
};
#endif

typedef	long	daddr_t;
typedef	char *	caddr_t;

#ifdef __MS_types__
typedef	unsigned long	ino_t;
#else
#ifdef __sparc__
typedef	unsigned long	ino_t;
#else
typedef	unsigned short	ino_t;
#endif
#endif

#ifdef __MS_types__
typedef unsigned long vm_offset_t;
typedef unsigned long vm_size_t;

#define __BIT_TYPES_DEFINED__

typedef char int8_t;
typedef unsigned char u_int8_t;
typedef short int16_t;
typedef unsigned short u_int16_t;
typedef int int32_t;
typedef unsigned int u_int32_t;
typedef long long int64_t;
typedef unsigned long long u_int64_t;
typedef int32_t register_t;
#endif 

#if defined(__rtems__)

typedef unsigned long long dev_t;
#else
typedef	short	dev_t;
#endif

typedef	long	off_t;

typedef	unsigned short	uid_t;
typedef	unsigned short	gid_t;
typedef int pid_t;
typedef	long key_t;
typedef long ssize_t;

#ifdef __MS_types__
typedef	char *	addr_t;
typedef int mode_t;
#else
#if defined (__sparc__) && !defined (__sparc_v9__)
#ifdef __svr4__
typedef unsigned long mode_t;
#else
typedef unsigned short mode_t;
#endif
#else
typedef unsigned int mode_t _ST_INT32;
#endif
#endif 

typedef unsigned short nlink_t;

# if ! defined (_POSIX_SOURCE) && ! defined (_WINSOCK_H)

#  define	NBBY	8		

#  ifndef	FD_SETSIZE
#	define	FD_SETSIZE	64
#  endif

typedef	long	fd_mask;
#  define	NFDBITS	(sizeof (fd_mask) * NBBY)	
#  ifndef	howmany
#	define	howmany(x,y)	(((x)+((y)-1))/(y))
#  endif

typedef	struct _types_fd_set {
	fd_mask	fds_bits[howmany(FD_SETSIZE, NFDBITS)];
} _types_fd_set;

#define fd_set _types_fd_set

#  define	FD_SET(n, p)	((p)->fds_bits[(n)/NFDBITS] |= (1L << ((n) % NFDBITS)))
#  define	FD_CLR(n, p)	((p)->fds_bits[(n)/NFDBITS] &= ~(1L << ((n) % NFDBITS)))
#  define	FD_ISSET(n, p)	((p)->fds_bits[(n)/NFDBITS] & (1L << ((n) % NFDBITS)))
#  define	FD_ZERO(p)	(__extension__ (void)({ \
     size_t __i; \
     char *__tmp = (char *)p; \
     for (__i = 0; __i < sizeof (*(p)); ++__i) \
       *__tmp++ = 0; \
}))

# endif	

#undef __MS_types__
#undef _ST_INT32

#if defined(__rtems__)

#ifndef __clockid_t_defined
typedef _CLOCKID_T_ clockid_t;
#define __clockid_t_defined
#endif

#ifndef __timer_t_defined
typedef _TIMER_T_ timer_t;
#define __timer_t_defined
#endif

/*
 *  Written by Joel Sherrill <joel@OARcorp.com>.
 *
 *  COPYRIGHT (c) 1989-2000.
 *
 *  On-Line Applications Research Corporation (OAR).
 *
 *  Permission to use, copy, modify, and distribute this software for any
 *  purpose without fee is hereby granted, provided that this entire notice
 *  is included in all copies of any software which is or includes a copy
 *  or modification of this software.
 *
 *  THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 *  WARRANTY.  IN PARTICULAR,  THE AUTHOR MAKES NO REPRESENTATION
 *  OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY OF THIS
 *  SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 *  $Id: features.h,v 1.1 2000/12/12 01:24:08 jjohnstn Exp $
 */

#ifndef _SYS_FEATURES_H
#define _SYS_FEATURES_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __rtems__
#define _POSIX_JOB_CONTROL     		1
#define _POSIX_SAVED_IDS       		1
#define _POSIX_VERSION			199309L
#define _POSIX_ASYNCHRONOUS_IO		1
#define _POSIX_FSYNC			1
#define _POSIX_MAPPED_FILES		1
#define _POSIX_MEMLOCK			1
#define _POSIX_MEMLOCK_RANGE		1
#define _POSIX_MEMORY_PROTECTION	1
#define _POSIX_MESSAGE_PASSING		1
#define _POSIX_PRIORITIZED_IO		1
#define _POSIX_PRIORITY_SCHEDULING	1
#define _POSIX_REALTIME_SIGNALS		1
#define _POSIX_SEMAPHORES		1
#define _POSIX_SHARED_MEMORY_OBJECTS	1
#define _POSIX_SYNCHRONIZED_IO		1
#define _POSIX_TIMERS			1

#define _POSIX_THREADS				1
#define _POSIX_THREAD_ATTR_STACKADDR		1
#define _POSIX_THREAD_ATTR_STACKSIZE		1
#define _POSIX_THREAD_PRIORITY_SCHEDULING	1
#define _POSIX_THREAD_PRIO_INHERIT		1
#define _POSIX_THREAD_PRIO_PROTECT		1
#define _POSIX_THREAD_PROCESS_SHARED		1
#define _POSIX_THREAD_SAFE_FUNCTIONS		1

#define _POSIX_SPAWN				1
#define _POSIX_TIMEOUTS				1
#define _POSIX_CPUTIME				1
#define _POSIX_THREAD_CPUTIME			1
#define _POSIX_SPORADIC_SERVER			1
#define _POSIX_THREAD_SPORADIC_SERVER		1
#define _POSIX_DEVICE_CONTROL			1
#define _POSIX_DEVCTL_DIRECTION			1
#define _POSIX_INTERRUPT_CONTROL		1
#define _POSIX_ADVISORY_INFO			1

#endif

#ifdef __svr4__
# define _POSIX_JOB_CONTROL     1
# define _POSIX_SAVED_IDS       1
# define _POSIX_VERSION 199009L
#endif

#ifdef __CYGWIN32__
# define _POSIX_JOB_CONTROL	1
# define _POSIX_SAVED_IDS	0
# define _POSIX_VERSION		199009L
#endif

#ifdef __cplusplus
}
#endif
#endif 

#if defined(_POSIX_THREADS)

/*
 *  Written by Joel Sherrill <joel@OARcorp.com>.
 *
 *  COPYRIGHT (c) 1989-2000.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  Permission to use, copy, modify, and distribute this software for any
 *  purpose without fee is hereby granted, provided that this entire notice
 *  is included in all copies of any software which is or includes a copy
 *  or modification of this software.
 *
 *  THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 *  WARRANTY.  IN PARTICULAR,  THE AUTHOR MAKES NO REPRESENTATION
 *  OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY OF THIS
 *  SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 *  $Id: sched.h,v 1.1 2000/12/12 01:24:08 jjohnstn Exp $
 */

#ifndef __POSIX_SYS_SCHEDULING_h
#define __POSIX_SYS_SCHEDULING_h

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/unistd.h>

#include <sys/types.h>
#include <sys/time.h>

#define SCHED_OTHER    0
#define SCHED_FIFO     1
#define SCHED_RR       2

#if defined(_POSIX_SPORADIC_SERVER)
#define SCHED_SPORADIC 3 
#endif

struct sched_param {
  int sched_priority;           

#if defined(_POSIX_SPORADIC_SERVER)
  int ss_low_priority;          
                                
  struct timespec ss_replenish_period; 
                                
  struct timespec ss_initial_budget;   
#endif
};

#ifdef __cplusplus
}
#endif 

#endif

typedef __uint32_t pthread_t;            

#define PTHREAD_SCOPE_PROCESS 0
#define PTHREAD_SCOPE_SYSTEM  1

#define PTHREAD_INHERIT_SCHED  1      
                                      
                                      
#define PTHREAD_EXPLICIT_SCHED 2      

#define PTHREAD_CREATE_DETACHED 0
#define PTHREAD_CREATE_JOINABLE  1

typedef struct {
  int is_initialized;
  void *stackaddr;
  int stacksize;
  int contentionscope;
  int inheritsched;
  int schedpolicy;
  struct sched_param schedparam;

  
#if defined(_POSIX_THREAD_CPUTIME)
  int  cputime_clock_allowed;  
#endif
  int  detachstate;

} pthread_attr_t;

#if defined(_POSIX_THREAD_PROCESS_SHARED)

#define PTHREAD_PROCESS_PRIVATE 0 
#define PTHREAD_PROCESS_SHARED  1 
                                  
                                  
#endif

#if defined(_POSIX_THREAD_PRIO_PROTECT)

#define PTHREAD_PRIO_NONE    0
#define PTHREAD_PRIO_INHERIT 1
#define PTHREAD_PRIO_PROTECT 2
#endif

typedef __uint32_t pthread_mutex_t;      

typedef struct {
  int   is_initialized;
#if defined(_POSIX_THREAD_PROCESS_SHARED)
  int   process_shared;  
#endif
#if defined(_POSIX_THREAD_PRIO_PROTECT)
  int   prio_ceiling;
  int   protocol;
#endif
  int   recursive;
} pthread_mutexattr_t;

typedef __uint32_t pthread_cond_t;       

typedef struct {
  int   is_initialized;
#if defined(_POSIX_THREAD_PROCESS_SHARED)
  int   process_shared;       
#endif
} pthread_condattr_t;         

typedef __uint32_t pthread_key_t;        

typedef struct {
  int   is_initialized;  
  int   init_executed;   
} pthread_once_t;       

#endif 

#endif  

#endif	

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _WINSOCK_H
struct timeval {
  long tv_sec;
  long tv_usec;
};

struct timezone {
  int tz_minuteswest;
  int tz_dsttime;
};

#ifdef __CYGWIN__
#include <sys/select.h>
#endif 

#endif 

#define ITIMER_REAL     0
#define ITIMER_VIRTUAL  1
#define ITIMER_PROF     2

struct  itimerval {
  struct  timeval it_interval;
  struct  timeval it_value;
};

#if defined(__rtems__)

#define	timerisset(tvp)		((tvp)->tv_sec || (tvp)->tv_usec)
#define	timerclear(tvp)		((tvp)->tv_sec = (tvp)->tv_usec = 0)
#define	timercmp(a, b, CMP) 						      \
  (((a)->tv_sec == (b)->tv_sec) ? 					      \
   ((a)->tv_usec CMP (b)->tv_usec) : 					      \
   ((a)->tv_sec CMP (b)->tv_sec))
#define	timeradd(a, b, result)						      \
  do {									      \
    (result)->tv_sec = (a)->tv_sec + (b)->tv_sec;			      \
    (result)->tv_usec = (a)->tv_usec + (b)->tv_usec;			      \
    if ((result)->tv_usec >= 1000000)					      \
      {									      \
	++(result)->tv_sec;						      \
	(result)->tv_usec -= 1000000;					      \
      }									      \
  } while (0)
#define	timersub(a, b, result)						      \
  do {									      \
    (result)->tv_sec = (a)->tv_sec - (b)->tv_sec;			      \
    (result)->tv_usec = (a)->tv_usec - (b)->tv_usec;			      \
    if ((result)->tv_usec < 0) {					      \
      --(result)->tv_sec;						      \
      (result)->tv_usec += 1000000;					      \
    }									      \
  } while (0)
#endif

int _EXFUN(gettimeofday, (struct timeval *__p, struct timezone *__z));
int _EXFUN(settimeofday, (const struct timeval *, const struct timezone *));
int _EXFUN(utimes, (const char *__path, struct timeval *__tvp));
int _EXFUN(getitimer, (int __which, struct itimerval *__value));
int _EXFUN(setitimer, (int __which, const struct itimerval *__value,
					struct itimerval *__ovalue));

#ifdef __cplusplus
}
#endif
#endif 

#define SCHED_OTHER    0
#define SCHED_FIFO     1
#define SCHED_RR       2

#if defined(_POSIX_SPORADIC_SERVER)
#define SCHED_SPORADIC 3 
#endif

struct sched_param {
  int sched_priority;           

#if defined(_POSIX_SPORADIC_SERVER)
  int ss_low_priority;          
                                
  struct timespec ss_replenish_period; 
                                
  struct timespec ss_initial_budget;   
#endif
};

#ifdef __cplusplus
}
#endif 

#endif

typedef __uint32_t pthread_t;            

#define PTHREAD_SCOPE_PROCESS 0
#define PTHREAD_SCOPE_SYSTEM  1

#define PTHREAD_INHERIT_SCHED  1      
                                      
                                      
#define PTHREAD_EXPLICIT_SCHED 2      

#define PTHREAD_CREATE_DETACHED 0
#define PTHREAD_CREATE_JOINABLE  1

typedef struct {
  int is_initialized;
  void *stackaddr;
  int stacksize;
  int contentionscope;
  int inheritsched;
  int schedpolicy;
  struct sched_param schedparam;

  
#if defined(_POSIX_THREAD_CPUTIME)
  int  cputime_clock_allowed;  
#endif
  int  detachstate;

} pthread_attr_t;

#if defined(_POSIX_THREAD_PROCESS_SHARED)

#define PTHREAD_PROCESS_PRIVATE 0 
#define PTHREAD_PROCESS_SHARED  1 
                                  
                                  
#endif

#if defined(_POSIX_THREAD_PRIO_PROTECT)

#define PTHREAD_PRIO_NONE    0
#define PTHREAD_PRIO_INHERIT 1
#define PTHREAD_PRIO_PROTECT 2
#endif

typedef __uint32_t pthread_mutex_t;      

typedef struct {
  int   is_initialized;
#if defined(_POSIX_THREAD_PROCESS_SHARED)
  int   process_shared;  
#endif
#if defined(_POSIX_THREAD_PRIO_PROTECT)
  int   prio_ceiling;
  int   protocol;
#endif
  int   recursive;
} pthread_mutexattr_t;

typedef __uint32_t pthread_cond_t;       

typedef struct {
  int   is_initialized;
#if defined(_POSIX_THREAD_PROCESS_SHARED)
  int   process_shared;       
#endif
} pthread_condattr_t;         

typedef __uint32_t pthread_key_t;        

typedef struct {
  int   is_initialized;  
  int   init_executed;   
} pthread_once_t;       

#endif 

#endif  

#endif	

struct tm
{
  int	tm_sec;
  int	tm_min;
  int	tm_hour;
  int	tm_mday;
  int	tm_mon;
  int	tm_year;
  int	tm_wday;
  int	tm_yday;
  int	tm_isdst;
};

clock_t	   _EXFUN(clock,    (void));
double	   _EXFUN(difftime, (time_t _time2, time_t _time1));
time_t	   _EXFUN(mktime,   (struct tm *_timeptr));
time_t	   _EXFUN(time,     (time_t *_timer));
#ifndef _REENT_ONLY
char	  *_EXFUN(asctime,  (const struct tm *_tblock));
char	  *_EXFUN(ctime,    (const time_t *_time));
struct tm *_EXFUN(gmtime,   (const time_t *_timer));
struct tm *_EXFUN(localtime,(const time_t *_timer));
#endif
size_t	   _EXFUN(strftime, (char *_s, size_t _maxsize, const char *_fmt, const struct tm *_t));

char	  *_EXFUN(asctime_r,	(const struct tm *, char *));
char	  *_EXFUN(ctime_r,	(const time_t *, char *));
struct tm *_EXFUN(gmtime_r,	(const time_t *, struct tm *));
struct tm *_EXFUN(localtime_r,	(const time_t *, struct tm *));

#ifdef __CYGWIN__
#ifndef __STRICT_ANSI__
extern __IMPORT time_t _timezone;
extern __IMPORT int _daylight;
extern __IMPORT char *_tzname[2];

char *_EXFUN(timezone, (void));
void _EXFUN(tzset, (void));
#endif
#endif 

/*
 *  Written by Joel Sherrill <joel@OARcorp.com>.
 *
 *  COPYRIGHT (c) 1989-2000.
 *
 *  On-Line Applications Research Corporation (OAR).
 *
 *  Permission to use, copy, modify, and distribute this software for any
 *  purpose without fee is hereby granted, provided that this entire notice
 *  is included in all copies of any software which is or includes a copy
 *  or modification of this software.
 *
 *  THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 *  WARRANTY.  IN PARTICULAR,  THE AUTHOR MAKES NO REPRESENTATION
 *  OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY OF THIS
 *  SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 *  $Id: features.h,v 1.1 2000/12/12 01:24:08 jjohnstn Exp $
 */

#ifndef _SYS_FEATURES_H
#define _SYS_FEATURES_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __rtems__
#define _POSIX_JOB_CONTROL     		1
#define _POSIX_SAVED_IDS       		1
#define _POSIX_VERSION			199309L
#define _POSIX_ASYNCHRONOUS_IO		1
#define _POSIX_FSYNC			1
#define _POSIX_MAPPED_FILES		1
#define _POSIX_MEMLOCK			1
#define _POSIX_MEMLOCK_RANGE		1
#define _POSIX_MEMORY_PROTECTION	1
#define _POSIX_MESSAGE_PASSING		1
#define _POSIX_PRIORITIZED_IO		1
#define _POSIX_PRIORITY_SCHEDULING	1
#define _POSIX_REALTIME_SIGNALS		1
#define _POSIX_SEMAPHORES		1
#define _POSIX_SHARED_MEMORY_OBJECTS	1
#define _POSIX_SYNCHRONIZED_IO		1
#define _POSIX_TIMERS			1

#define _POSIX_THREADS				1
#define _POSIX_THREAD_ATTR_STACKADDR		1
#define _POSIX_THREAD_ATTR_STACKSIZE		1
#define _POSIX_THREAD_PRIORITY_SCHEDULING	1
#define _POSIX_THREAD_PRIO_INHERIT		1
#define _POSIX_THREAD_PRIO_PROTECT		1
#define _POSIX_THREAD_PROCESS_SHARED		1
#define _POSIX_THREAD_SAFE_FUNCTIONS		1

#define _POSIX_SPAWN				1
#define _POSIX_TIMEOUTS				1
#define _POSIX_CPUTIME				1
#define _POSIX_THREAD_CPUTIME			1
#define _POSIX_SPORADIC_SERVER			1
#define _POSIX_THREAD_SPORADIC_SERVER		1
#define _POSIX_DEVICE_CONTROL			1
#define _POSIX_DEVCTL_DIRECTION			1
#define _POSIX_INTERRUPT_CONTROL		1
#define _POSIX_ADVISORY_INFO			1

#endif

#ifdef __svr4__
# define _POSIX_JOB_CONTROL     1
# define _POSIX_SAVED_IDS       1
# define _POSIX_VERSION 199009L
#endif

#ifdef __CYGWIN32__
# define _POSIX_JOB_CONTROL	1
# define _POSIX_SAVED_IDS	0
# define _POSIX_VERSION		199009L
#endif

#ifdef __cplusplus
}
#endif
#endif 

#if defined(_POSIX_TIMERS)

#ifndef _SIGNAL_H_
#ifdef __cplusplus
extern "C" {
#endif
#define _SIGNAL_H_

/* Provide support for both ANSI and non-ANSI environments.  */

#ifndef	_ANSIDECL_H_
#define	_ANSIDECL_H_

#ifndef __SYS_CONFIG_H__
#define __SYS_CONFIG_H__

/* exceptions first */

#if defined(__H8300__) || defined(__H8500__) || defined (__H8300H__) ||  defined(__W65__) || defined (__H8300S__)
#define _FLOAT_ARG float
#define __SMALL_BITFIELDS
#define _DOUBLE_IS_32BITS
#define __IEEE_BIG_ENDIAN

#define H8300 1
#endif

#ifdef __W65__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_BIG_ENDIAN
#undef INT_MAX
#undef UINT_MAX
#define INT_MAX 32767
#define UINT_MAX 65535

#endif

#if defined(__Z8001__) || defined(__Z8002__) || defined(__H8300__) || defined(__H8500__) || defined(__W65__) || defined (__H8300H__) || defined (__H8300S__) || defined (__mn10200__) || defined (__AVR__)

#undef INT_MAX
#undef UINT_MAX
#define INT_MAX 32767
#define UINT_MAX 65535
#endif

#if defined(__D10V__)
#undef INT_MAX
#undef UINT_MAX
#define INT_MAX __INT_MAX__
#define UINT_MAX (__INT_MAX__ * 2U + 1)
#define _DOUBLE_IS_32BITS
#define _POINTER_INT short
#define __IEEE_BIG_ENDIAN
#endif

#ifdef ___AM29K__
#define _FLOAT_RET double
#endif

#ifdef __i386__
#ifndef __unix__

#define _FLOAT_RET double
#endif
#endif

#ifdef __M32R__
#define __IEEE_BIG_ENDIAN
#endif

#ifdef __m68k__

#define __IEEE_BIG_ENDIAN
#endif

#ifdef __mn10300__
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __mn10200__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __AVR__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_LITTLE_ENDIAN
#define _POINTER_INT short
#endif

#ifdef __TIC80__
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __v850
#define __IEEE_LITTLE_ENDIAN
#define __ATTRIBUTE_IMPURE_PTR__ __attribute__((__sda__))
#endif

#ifdef __D30V__
#define __IEEE_BIG_ENDIAN
#endif

#if defined(__PPC__) && defined(_CALL_SYSV)
#define __ATTRIBUTE_IMPURE_PTR__ __attribute__((__section__(".sdata")))
#endif

#ifdef __sparc__
#ifdef __LITTLE_ENDIAN_DATA__
#define __IEEE_LITTLE_ENDIAN
#else
#define __IEEE_BIG_ENDIAN
#endif
#endif

#if INT_MAX == 32767
typedef long int __int32_t;
typedef unsigned long int __uint32_t;
#else
typedef int __int32_t;
typedef unsigned int __uint32_t;
#endif

#ifndef _POINTER_INT
#define _POINTER_INT long
#endif

#undef __RAND_MAX
#if INT_MAX == 32767
#define __RAND_MAX 32767
#else
#define __RAND_MAX 0x7fffffff
#endif

#if defined(__CYGWIN32__) || defined(__CYGWIN__)
#if defined(__INSIDE_CYGWIN__) || defined(_COMPILING_NEWLIB)
#define __IMPORT
#else
#define __IMPORT __declspec(dllimport)
#endif
#endif

#ifndef __IMPORT
#define __IMPORT
#endif

#endif 

#ifdef __STDC__
#define _HAVE_STDC
#endif

#ifdef _HAVE_STDC
#define	_PTR		void *
#define	_AND		,
#define	_NOARGS		void
#define	_CONST		const
#define	_VOLATILE	volatile
#define	_SIGNED		signed
#define	_DOTS		, ...
#define _VOID void
#ifdef __CYGWIN__
#define	_EXFUN(name, proto)		__cdecl name proto
#define	_EXPARM(name, proto)		(* __cdecl name) proto
#else
#define	_EXFUN(name, proto)		name proto
#define _EXPARM(name, proto)		(* name) proto
#endif
#define	_DEFUN(name, arglist, args)	name(args)
#define	_DEFUN_VOID(name)		name(_NOARGS)
#define _CAST_VOID (void)
#ifndef _LONG_DOUBLE
#define _LONG_DOUBLE long double
#endif
#ifndef _PARAMS
#define _PARAMS(paramlist)		paramlist
#endif
#else	
#define	_PTR		char *
#define	_AND		;
#define	_NOARGS
#define	_CONST
#define	_VOLATILE
#define	_SIGNED
#define	_DOTS
#define _VOID void
#define	_EXFUN(name, proto)		name()
#define	_DEFUN(name, arglist, args)	name arglist args;
#define	_DEFUN_VOID(name)		name()
#define _CAST_VOID
#define _LONG_DOUBLE double
#ifndef _PARAMS
#define _PARAMS(paramlist)		()
#endif
#endif

#ifdef __GNUC__
#define _ATTRIBUTE(attrs) __attribute__ (attrs)
#else
#define _ATTRIBUTE(attrs)
#endif

#endif 

/* sys/signal.h */

#ifndef _SYS_SIGNAL_H
#define _SYS_SIGNAL_H

#ifdef __cplusplus
extern "C" {
#endif

/* Provide support for both ANSI and non-ANSI environments.  */

#ifndef	_ANSIDECL_H_
#define	_ANSIDECL_H_

#ifndef __SYS_CONFIG_H__
#define __SYS_CONFIG_H__

/* exceptions first */

#if defined(__H8300__) || defined(__H8500__) || defined (__H8300H__) ||  defined(__W65__) || defined (__H8300S__)
#define _FLOAT_ARG float
#define __SMALL_BITFIELDS
#define _DOUBLE_IS_32BITS
#define __IEEE_BIG_ENDIAN

#define H8300 1
#endif

#ifdef __W65__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_BIG_ENDIAN
#undef INT_MAX
#undef UINT_MAX
#define INT_MAX 32767
#define UINT_MAX 65535

#endif

#if defined(__Z8001__) || defined(__Z8002__) || defined(__H8300__) || defined(__H8500__) || defined(__W65__) || defined (__H8300H__) || defined (__H8300S__) || defined (__mn10200__) || defined (__AVR__)

#undef INT_MAX
#undef UINT_MAX
#define INT_MAX 32767
#define UINT_MAX 65535
#endif

#if defined(__D10V__)
#undef INT_MAX
#undef UINT_MAX
#define INT_MAX __INT_MAX__
#define UINT_MAX (__INT_MAX__ * 2U + 1)
#define _DOUBLE_IS_32BITS
#define _POINTER_INT short
#define __IEEE_BIG_ENDIAN
#endif

#ifdef ___AM29K__
#define _FLOAT_RET double
#endif

#ifdef __i386__
#ifndef __unix__

#define _FLOAT_RET double
#endif
#endif

#ifdef __M32R__
#define __IEEE_BIG_ENDIAN
#endif

#ifdef __m68k__

#define __IEEE_BIG_ENDIAN
#endif

#ifdef __mn10300__
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __mn10200__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __AVR__
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#define __IEEE_LITTLE_ENDIAN
#define _POINTER_INT short
#endif

#ifdef __TIC80__
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __v850
#define __IEEE_LITTLE_ENDIAN
#define __ATTRIBUTE_IMPURE_PTR__ __attribute__((__sda__))
#endif

#ifdef __D30V__
#define __IEEE_BIG_ENDIAN
#endif

#if defined(__PPC__) && defined(_CALL_SYSV)
#define __ATTRIBUTE_IMPURE_PTR__ __attribute__((__section__(".sdata")))
#endif

#ifdef __sparc__
#ifdef __LITTLE_ENDIAN_DATA__
#define __IEEE_LITTLE_ENDIAN
#else
#define __IEEE_BIG_ENDIAN
#endif
#endif

#if INT_MAX == 32767
typedef long int __int32_t;
typedef unsigned long int __uint32_t;
#else
typedef int __int32_t;
typedef unsigned int __uint32_t;
#endif

#ifndef _POINTER_INT
#define _POINTER_INT long
#endif

#undef __RAND_MAX
#if INT_MAX == 32767
#define __RAND_MAX 32767
#else
#define __RAND_MAX 0x7fffffff
#endif

#if defined(__CYGWIN32__) || defined(__CYGWIN__)
#if defined(__INSIDE_CYGWIN__) || defined(_COMPILING_NEWLIB)
#define __IMPORT
#else
#define __IMPORT __declspec(dllimport)
#endif
#endif

#ifndef __IMPORT
#define __IMPORT
#endif

#endif 

#ifdef __STDC__
#define _HAVE_STDC
#endif

#ifdef _HAVE_STDC
#define	_PTR		void *
#define	_AND		,
#define	_NOARGS		void
#define	_CONST		const
#define	_VOLATILE	volatile
#define	_SIGNED		signed
#define	_DOTS		, ...
#define _VOID void
#ifdef __CYGWIN__
#define	_EXFUN(name, proto)		__cdecl name proto
#define	_EXPARM(name, proto)		(* __cdecl name) proto
#else
#define	_EXFUN(name, proto)		name proto
#define _EXPARM(name, proto)		(* name) proto
#endif
#define	_DEFUN(name, arglist, args)	name(args)
#define	_DEFUN_VOID(name)		name(_NOARGS)
#define _CAST_VOID (void)
#ifndef _LONG_DOUBLE
#define _LONG_DOUBLE long double
#endif
#ifndef _PARAMS
#define _PARAMS(paramlist)		paramlist
#endif
#else	
#define	_PTR		char *
#define	_AND		;
#define	_NOARGS
#define	_CONST
#define	_VOLATILE
#define	_SIGNED
#define	_DOTS
#define _VOID void
#define	_EXFUN(name, proto)		name()
#define	_DEFUN(name, arglist, args)	name arglist args;
#define	_DEFUN_VOID(name)		name()
#define _CAST_VOID
#define _LONG_DOUBLE double
#ifndef _PARAMS
#define _PARAMS(paramlist)		()
#endif
#endif

#ifdef __GNUC__
#define _ATTRIBUTE(attrs) __attribute__ (attrs)
#else
#define _ATTRIBUTE(attrs)
#endif

#endif 

/*
 *  Written by Joel Sherrill <joel@OARcorp.com>.
 *
 *  COPYRIGHT (c) 1989-2000.
 *
 *  On-Line Applications Research Corporation (OAR).
 *
 *  Permission to use, copy, modify, and distribute this software for any
 *  purpose without fee is hereby granted, provided that this entire notice
 *  is included in all copies of any software which is or includes a copy
 *  or modification of this software.
 *
 *  THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 *  WARRANTY.  IN PARTICULAR,  THE AUTHOR MAKES NO REPRESENTATION
 *  OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY OF THIS
 *  SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 *  $Id: features.h,v 1.1 2000/12/12 01:24:08 jjohnstn Exp $
 */

#ifndef _SYS_FEATURES_H
#define _SYS_FEATURES_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __rtems__
#define _POSIX_JOB_CONTROL     		1
#define _POSIX_SAVED_IDS       		1
#define _POSIX_VERSION			199309L
#define _POSIX_ASYNCHRONOUS_IO		1
#define _POSIX_FSYNC			1
#define _POSIX_MAPPED_FILES		1
#define _POSIX_MEMLOCK			1
#define _POSIX_MEMLOCK_RANGE		1
#define _POSIX_MEMORY_PROTECTION	1
#define _POSIX_MESSAGE_PASSING		1
#define _POSIX_PRIORITIZED_IO		1
#define _POSIX_PRIORITY_SCHEDULING	1
#define _POSIX_REALTIME_SIGNALS		1
#define _POSIX_SEMAPHORES		1
#define _POSIX_SHARED_MEMORY_OBJECTS	1
#define _POSIX_SYNCHRONIZED_IO		1
#define _POSIX_TIMERS			1

#define _POSIX_THREADS				1
#define _POSIX_THREAD_ATTR_STACKADDR		1
#define _POSIX_THREAD_ATTR_STACKSIZE		1
#define _POSIX_THREAD_PRIORITY_SCHEDULING	1
#define _POSIX_THREAD_PRIO_INHERIT		1
#define _POSIX_THREAD_PRIO_PROTECT		1
#define _POSIX_THREAD_PROCESS_SHARED		1
#define _POSIX_THREAD_SAFE_FUNCTIONS		1

#define _POSIX_SPAWN				1
#define _POSIX_TIMEOUTS				1
#define _POSIX_CPUTIME				1
#define _POSIX_THREAD_CPUTIME			1
#define _POSIX_SPORADIC_SERVER			1
#define _POSIX_THREAD_SPORADIC_SERVER		1
#define _POSIX_DEVICE_CONTROL			1
#define _POSIX_DEVCTL_DIRECTION			1
#define _POSIX_INTERRUPT_CONTROL		1
#define _POSIX_ADVISORY_INFO			1

#endif

#ifdef __svr4__
# define _POSIX_JOB_CONTROL     1
# define _POSIX_SAVED_IDS       1
# define _POSIX_VERSION 199009L
#endif

#ifdef __CYGWIN32__
# define _POSIX_JOB_CONTROL	1
# define _POSIX_SAVED_IDS	0
# define _POSIX_VERSION		199009L
#endif

#ifdef __cplusplus
}
#endif
#endif 

#if defined(_POSIX_THREADS)
/* unified sys/types.h: 
   start with sef's sysvi386 version.
   merge go32 version -- a few ifdefs.
   h8300hms, h8300xray, and sysvnecv70 disagree on the following types:

   typedef int gid_t;
   typedef int uid_t;
   typedef int dev_t;
   typedef int ino_t;
   typedef int mode_t;
   typedef int caddr_t;

   however, these aren't "reasonable" values, the sysvi386 ones make far 
   more sense, and should work sufficiently well (in particular, h8300 
   doesn't have a stat, and the necv70 doesn't matter.) -- eichin
 */

#ifndef _SYS_TYPES_H
#define _SYS_TYPES_H

#if defined (_WIN32) || defined (__CYGWIN__)
#define __MS_types__
#endif

#ifdef __i386__
#if defined (GO32) || defined (__MSDOS__)
#define __MS_types__
#endif
#endif

/* gt4: stand-in for gcc's <stddef.h> (the compiler ships without headers). */
#ifndef _STDDEF_H
#define _STDDEF_H
typedef __SIZE_TYPE__ size_t;
typedef __PTRDIFF_TYPE__ ptrdiff_t;
#ifndef __cplusplus
typedef __WCHAR_TYPE__ wchar_t;
#endif
typedef unsigned int wint_t;
#ifndef NULL
#define NULL ((void *)0)
#endif
#define offsetof(t, m) ((size_t)&((t *)0)->m)
#endif

#ifndef	_MACHTYPES_H_
#define	_MACHTYPES_H_

#define	_CLOCK_T_	unsigned long		/* clock() */
#define	_TIME_T_	long			
#define _CLOCKID_T_ 	unsigned long
#define _TIMER_T_   	unsigned long

#endif	

#ifdef __GNUC__
#define _ST_INT32 __attribute__ ((__mode__ (__SI__)))
#else
#define _ST_INT32
#endif

# ifndef	_POSIX_SOURCE

#  define	physadr		physadr_t
#  define	quad		quad_t

#ifndef _WINSOCK_H
typedef	unsigned char	u_char;
typedef	unsigned short	u_short;
typedef	unsigned int	u_int;
typedef	unsigned long	u_long;
#endif

typedef	unsigned short	ushort;		
typedef	unsigned int	uint;		
# endif	

#ifndef __clock_t_defined
typedef _CLOCK_T_ clock_t;
#define __clock_t_defined
#endif

#ifndef __time_t_defined
typedef _TIME_T_ time_t;
#define __time_t_defined

struct timespec {
  time_t  tv_sec;   
  long    tv_nsec;  
};

struct itimerspec {
  struct timespec  it_interval;  
  struct timespec  it_value;     
};
#endif

typedef	long	daddr_t;
typedef	char *	caddr_t;

#ifdef __MS_types__
typedef	unsigned long	ino_t;
#else
#ifdef __sparc__
typedef	unsigned long	ino_t;
#else
typedef	unsigned short	ino_t;
#endif
#endif

#ifdef __MS_types__
typedef unsigned long vm_offset_t;
typedef unsigned long vm_size_t;

#define __BIT_TYPES_DEFINED__

typedef char int8_t;
typedef unsigned char u_int8_t;
typedef short int16_t;
typedef unsigned short u_int16_t;
typedef int int32_t;
typedef unsigned int u_int32_t;
typedef long long int64_t;
typedef unsigned long long u_int64_t;
typedef int32_t register_t;
#endif 

#if defined(__rtems__)

typedef unsigned long long dev_t;
#else
typedef	short	dev_t;
#endif

typedef	long	off_t;

typedef	unsigned short	uid_t;
typedef	unsigned short	gid_t;
typedef int pid_t;
typedef	long key_t;
typedef long ssize_t;

#ifdef __MS_types__
typedef	char *	addr_t;
typedef int mode_t;
#else
#if defined (__sparc__) && !defined (__sparc_v9__)
#ifdef __svr4__
typedef unsigned long mode_t;
#else
typedef unsigned short mode_t;
#endif
#else
typedef unsigned int mode_t _ST_INT32;
#endif
#endif 

typedef unsigned short nlink_t;

# if ! defined (_POSIX_SOURCE) && ! defined (_WINSOCK_H)

#  define	NBBY	8		

#  ifndef	FD_SETSIZE
#	define	FD_SETSIZE	64
#  endif

typedef	long	fd_mask;
#  define	NFDBITS	(sizeof (fd_mask) * NBBY)	
#  ifndef	howmany
#	define	howmany(x,y)	(((x)+((y)-1))/(y))
#  endif

typedef	struct _types_fd_set {
	fd_mask	fds_bits[howmany(FD_SETSIZE, NFDBITS)];
} _types_fd_set;

#define fd_set _types_fd_set

#  define	FD_SET(n, p)	((p)->fds_bits[(n)/NFDBITS] |= (1L << ((n) % NFDBITS)))
#  define	FD_CLR(n, p)	((p)->fds_bits[(n)/NFDBITS] &= ~(1L << ((n) % NFDBITS)))
#  define	FD_ISSET(n, p)	((p)->fds_bits[(n)/NFDBITS] & (1L << ((n) % NFDBITS)))
#  define	FD_ZERO(p)	(__extension__ (void)({ \
     size_t __i; \
     char *__tmp = (char *)p; \
     for (__i = 0; __i < sizeof (*(p)); ++__i) \
       *__tmp++ = 0; \
}))

# endif	

#undef __MS_types__
#undef _ST_INT32

#if defined(__rtems__)

#ifndef __clockid_t_defined
typedef _CLOCKID_T_ clockid_t;
#define __clockid_t_defined
#endif

#ifndef __timer_t_defined
typedef _TIMER_T_ timer_t;
#define __timer_t_defined
#endif

/*
 *  Written by Joel Sherrill <joel@OARcorp.com>.
 *
 *  COPYRIGHT (c) 1989-2000.
 *
 *  On-Line Applications Research Corporation (OAR).
 *
 *  Permission to use, copy, modify, and distribute this software for any
 *  purpose without fee is hereby granted, provided that this entire notice
 *  is included in all copies of any software which is or includes a copy
 *  or modification of this software.
 *
 *  THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 *  WARRANTY.  IN PARTICULAR,  THE AUTHOR MAKES NO REPRESENTATION
 *  OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY OF THIS
 *  SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 *  $Id: features.h,v 1.1 2000/12/12 01:24:08 jjohnstn Exp $
 */

#ifndef _SYS_FEATURES_H
#define _SYS_FEATURES_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __rtems__
#define _POSIX_JOB_CONTROL     		1
#define _POSIX_SAVED_IDS       		1
#define _POSIX_VERSION			199309L
#define _POSIX_ASYNCHRONOUS_IO		1
#define _POSIX_FSYNC			1
#define _POSIX_MAPPED_FILES		1
#define _POSIX_MEMLOCK			1
#define _POSIX_MEMLOCK_RANGE		1
#define _POSIX_MEMORY_PROTECTION	1
#define _POSIX_MESSAGE_PASSING		1
#define _POSIX_PRIORITIZED_IO		1
#define _POSIX_PRIORITY_SCHEDULING	1
#define _POSIX_REALTIME_SIGNALS		1
#define _POSIX_SEMAPHORES		1
#define _POSIX_SHARED_MEMORY_OBJECTS	1
#define _POSIX_SYNCHRONIZED_IO		1
#define _POSIX_TIMERS			1

#define _POSIX_THREADS				1
#define _POSIX_THREAD_ATTR_STACKADDR		1
#define _POSIX_THREAD_ATTR_STACKSIZE		1
#define _POSIX_THREAD_PRIORITY_SCHEDULING	1
#define _POSIX_THREAD_PRIO_INHERIT		1
#define _POSIX_THREAD_PRIO_PROTECT		1
#define _POSIX_THREAD_PROCESS_SHARED		1
#define _POSIX_THREAD_SAFE_FUNCTIONS		1

#define _POSIX_SPAWN				1
#define _POSIX_TIMEOUTS				1
#define _POSIX_CPUTIME				1
#define _POSIX_THREAD_CPUTIME			1
#define _POSIX_SPORADIC_SERVER			1
#define _POSIX_THREAD_SPORADIC_SERVER		1
#define _POSIX_DEVICE_CONTROL			1
#define _POSIX_DEVCTL_DIRECTION			1
#define _POSIX_INTERRUPT_CONTROL		1
#define _POSIX_ADVISORY_INFO			1

#endif

#ifdef __svr4__
# define _POSIX_JOB_CONTROL     1
# define _POSIX_SAVED_IDS       1
# define _POSIX_VERSION 199009L
#endif

#ifdef __CYGWIN32__
# define _POSIX_JOB_CONTROL	1
# define _POSIX_SAVED_IDS	0
# define _POSIX_VERSION		199009L
#endif

#ifdef __cplusplus
}
#endif
#endif 

#if defined(_POSIX_THREADS)

/*
 *  Written by Joel Sherrill <joel@OARcorp.com>.
 *
 *  COPYRIGHT (c) 1989-2000.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  Permission to use, copy, modify, and distribute this software for any
 *  purpose without fee is hereby granted, provided that this entire notice
 *  is included in all copies of any software which is or includes a copy
 *  or modification of this software.
 *
 *  THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 *  WARRANTY.  IN PARTICULAR,  THE AUTHOR MAKES NO REPRESENTATION
 *  OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY OF THIS
 *  SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 *  $Id: sched.h,v 1.1 2000/12/12 01:24:08 jjohnstn Exp $
 */

#ifndef __POSIX_SYS_SCHEDULING_h
#define __POSIX_SYS_SCHEDULING_h

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _SYS_UNISTD_H
#define _SYS_UNISTD_H

#ifdef __cplusplus
extern "C" {
#endif

#include <_ansi.h>
#include <sys/types.h>
#define __need_size_t
#define __need_ptrdiff_t
#include <stddef.h>

extern char **environ;

void	_EXFUN(_exit, (int __status ) _ATTRIBUTE ((noreturn)));

int	_EXFUN(access,(const char *__path, int __amode ));
unsigned  _EXFUN(alarm, (unsigned __secs ));
int     _EXFUN(chdir, (const char *__path ));
int     _EXFUN(chmod, (const char *__path, mode_t __mode ));
int     _EXFUN(chown, (const char *__path, uid_t __owner, gid_t __group ));
#ifdef __CYGWIN__
int     _EXFUN(chroot, (const char *__path ));
#endif
int     _EXFUN(close, (int __fildes ));
char    _EXFUN(*ctermid, (char *__s ));
char    _EXFUN(*cuserid, (char *__s ));
int     _EXFUN(dup, (int __fildes ));
int     _EXFUN(dup2, (int __fildes, int __fildes2 ));
int     _EXFUN(execl, (const char *__path, const char *, ... ));
int     _EXFUN(execle, (const char *__path, const char *, ... ));
int     _EXFUN(execlp, (const char *__file, const char *, ... ));
int     _EXFUN(execv, (const char *__path, char * const __argv[] ));
int     _EXFUN(execve, (const char *__path, char * const __argv[], char * const __envp[] ));
int     _EXFUN(execvp, (const char *__file, char * const __argv[] ));
int     _EXFUN(fchmod, (int __fildes, mode_t __mode ));
int     _EXFUN(fchown, (int __fildes, uid_t __owner, gid_t __group ));
pid_t   _EXFUN(fork, (void ));
long    _EXFUN(fpathconf, (int __fd, int __name ));
int     _EXFUN(fsync, (int __fd));
char    _EXFUN(*getcwd, (char *__buf, size_t __size ));
gid_t   _EXFUN(getegid, (void ));
uid_t   _EXFUN(geteuid, (void ));
gid_t   _EXFUN(getgid, (void ));
int     _EXFUN(getgroups, (int __gidsetsize, gid_t __grouplist[] ));
char    _EXFUN(*getlogin, (void ));
#if defined(_POSIX_THREAD_SAFE_FUNCTIONS)
int _EXFUN(getlogin_r, (char *name, size_t namesize) );
#endif
char 	_EXFUN(*getpass, (__const char *__prompt));
size_t  _EXFUN(getpagesize, (void));
pid_t   _EXFUN(getpgrp, (void ));
pid_t   _EXFUN(getpid, (void ));
pid_t   _EXFUN(getppid, (void ));
uid_t   _EXFUN(getuid, (void ));
#ifdef __CYGWIN__
char    _EXFUN(*getwd, (char *__buf ));
#endif
int     _EXFUN(isatty, (int __fildes ));
int     _EXFUN(lchown, (const char *__path, uid_t __owner, gid_t __group ));
int     _EXFUN(link, (const char *__path1, const char *__path2 ));
int	_EXFUN(nice, (int __nice_value ));
off_t   _EXFUN(lseek, (int __fildes, off_t __offset, int __whence ));
long    _EXFUN(pathconf, (const char *__path, int __name ));
int     _EXFUN(pause, (void ));
int     _EXFUN(pipe, (int __fildes[2] ));
/* POSIX 1003.1b-1993 says read() returns ssize_t */
#if defined(__rtems__)
ssize_t	_EXFUN(read, (int __fildes, void *__buf, size_t __nbyte ));
#else
int	_EXFUN(read, (int __fildes, void *__buf, size_t __nbyte ));
#endif
int     _EXFUN(rmdir, (const char *__path ));
#if defined(__rtems__)
void *  _EXFUN(sbrk,  (ptrdiff_t __incr));
#else
void *  _EXFUN(sbrk,  (size_t __incr));
#endif
#if defined(__CYGWIN__)
int     _EXFUN(setegid, (gid_t __gid ));
int     _EXFUN(seteuid, (uid_t __uid ));
#endif
int     _EXFUN(setgid, (gid_t __gid ));
int     _EXFUN(setpgid, (pid_t __pid, pid_t __pgid ));
pid_t   _EXFUN(setsid, (void ));
int     _EXFUN(setuid, (uid_t __uid ));
unsigned _EXFUN(sleep, (unsigned int __seconds ));
void    _EXFUN(swab, (const void *, void *, ssize_t));
long    _EXFUN(sysconf, (int __name ));
pid_t   _EXFUN(tcgetpgrp, (int __fildes ));
int     _EXFUN(tcsetpgrp, (int __fildes, pid_t __pgrp_id ));
char    _EXFUN(*ttyname, (int __fildes ));
int     _EXFUN(unlink, (const char *__path ));

#if defined(__rtems__)
ssize_t     _EXFUN(write, (int __fildes, const void *__buf, size_t __nbyte ));
#else
int     _EXFUN(write, (int __fildes, const void *__buf, size_t __nbyte ));
#endif

#ifndef        _POSIX_SOURCE
pid_t   _EXFUN(vfork, (void ));
#endif 

int     _EXFUN(_close, (int __fildes ));
pid_t   _EXFUN(_fork, (void ));
pid_t   _EXFUN(_getpid, (void ));
int     _EXFUN(_link, (const char *__path1, const char *__path2 ));
off_t   _EXFUN(_lseek, (int __fildes, off_t __offset, int __whence ));
int     _EXFUN(_read, (int __fildes, void *__buf, size_t __nbyte ));
void *  _EXFUN(_sbrk,  (size_t __incr));
int     _EXFUN(_unlink, (const char *__path ));
int     _EXFUN(_write, (int __fildes, const void *__buf, size_t __nbyte ));
int     _EXFUN(_execve, (const char *__path, char * const __argv[], char * const __envp[] ));

#if defined(__CYGWIN__) || defined(__rtems__)
int	_EXFUN(getdtablesize, (void));
void	_EXFUN(setdtablesize, (int));
unsigned _EXFUN(usleep, (unsigned int __useconds));
int     _EXFUN(ftruncate, (int __fd, off_t __length));
int     _EXFUN(truncate, (const char *, off_t __length));
int	_EXFUN(gethostname, (char *__name, size_t __len));
char *	_EXFUN(mktemp, (char *));
int     _EXFUN(sync, (void));
int     _EXFUN(readlink, (const char *__path, char *__buf, int __buflen));
int     _EXFUN(symlink, (const char *__name1, const char *__name2));
#endif

# define	F_OK	0
# define	R_OK	4
# define	W_OK	2
# define	X_OK	1

# define	SEEK_SET	0
# define	SEEK_CUR	1
# define	SEEK_END	2

#include <sys/features.h>

#define STDIN_FILENO    0       
#define STDOUT_FILENO   1       
#define STDERR_FILENO   2       

long _EXFUN(sysconf, (int __name));

#define _SC_ARG_MAX                 0
#define _SC_CHILD_MAX               1
#define _SC_CLK_TCK                 2
#define _SC_NGROUPS_MAX             3
#define _SC_OPEN_MAX                4
  
#define _SC_JOB_CONTROL             5
#define _SC_SAVED_IDS               6
#define _SC_VERSION                 7
#define _SC_PAGESIZE                8

#define _SC_NPROCESSORS_CONF        9
#define _SC_NPROCESSORS_ONLN       10
#define _SC_PHYS_PAGES             11
#define _SC_AVPHYS_PAGES           12

#define _SC_MQ_OPEN_MAX            13
#define _SC_MQ_PRIO_MAX            14
#define _SC_RTSIG_MAX              15
#define _SC_SEM_NSEMS_MAX          16
#define _SC_SEM_VALUE_MAX          17
#define _SC_SIGQUEUE_MAX           18
#define _SC_TIMER_MAX              19
#define _SC_TZNAME_MAX             20

#define _SC_ASYNCHRONOUS_IO        21
#define _SC_FSYNC                  22
#define _SC_MAPPED_FILES           23
#define _SC_MEMLOCK                24
#define _SC_MEMLOCK_RANGE          25
#define _SC_MEMORY_PROTECTION      26
#define _SC_MESSAGE_PASSING        27
#define _SC_PRIORITIZED_IO         28
#define _SC_REALTIME_SIGNALS       29
#define _SC_SEMAPHORES             30
#define _SC_SHARED_MEMORY_OBJECTS  31
#define _SC_SYNCHRONIZED_IO        32
#define _SC_TIMERS                 33
#define _SC_AIO_LISTIO_MAX         34
#define _SC_AIO_MAX                35
#define _SC_AIO_PRIO_DELTA_MAX     36
#define _SC_DELAYTIMER_MAX         37

#define _SC_THREAD_KEYS_MAX              38
#define _SC_THREAD_STACK_MIN             39
#define _SC_THREAD_THREADS_MAX           40
#define _SC_TTY_NAME_MAX                 41

#define _SC_THREADS                      42
#define _SC_THREAD_ATTR_STACKADDR        43
#define _SC_THREAD_ATTR_STACKSIZE        44
#define _SC_THREAD_PRIORITY_SCHEDULING   45
#define _SC_THREAD_PRIO_INHERIT          46

#define _SC_THREAD_PRIO_PROTECT          47
#define _SC_THREAD_PRIO_CEILING          _SC_THREAD_PRIO_PROTECT
#define _SC_THREAD_PROCESS_SHARED        48
#define _SC_THREAD_SAFE_FUNCTIONS        49
#define _SC_GETGR_R_SIZE_MAX             50
#define _SC_GETPW_R_SIZE_MAX             51
#define _SC_LOGIN_NAME_MAX               52
#define _SC_THREAD_DESTRUCTOR_ITERATIONS 53
  
# define	_PC_LINK_MAX	        0
# define	_PC_MAX_CANON	        1
# define	_PC_MAX_INPUT	        2
# define	_PC_NAME_MAX	        3
# define	_PC_PATH_MAX	        4
# define	_PC_PIPE_BUF	        5
# define	_PC_CHOWN_RESTRICTED   	6
# define	_PC_NO_TRUNC	        7
# define	_PC_VDISABLE	        8
# define	_PC_ASYNC_IO            9
# define	_PC_PRIO_IO            10
# define	_PC_SYNC_IO            11

#ifdef __CYGWIN__
#define MAXPATHLEN (260 - 1 )
#else
# define	MAXPATHLEN	1024
#endif

#ifdef __cplusplus
}
#endif
#endif 

/* unified sys/types.h: 
   start with sef's sysvi386 version.
   merge go32 version -- a few ifdefs.
   h8300hms, h8300xray, and sysvnecv70 disagree on the following types:

   typedef int gid_t;
   typedef int uid_t;
   typedef int dev_t;
   typedef int ino_t;
   typedef int mode_t;
   typedef int caddr_t;

   however, these aren't "reasonable" values, the sysvi386 ones make far 
   more sense, and should work sufficiently well (in particular, h8300 
   doesn't have a stat, and the necv70 doesn't matter.) -- eichin
 */

#ifndef _SYS_TYPES_H
#define _SYS_TYPES_H

#if defined (_WIN32) || defined (__CYGWIN__)
#define __MS_types__
#endif

#ifdef __i386__
#if defined (GO32) || defined (__MSDOS__)
#define __MS_types__
#endif
#endif

# include <stddef.h>
# include <machine/types.h>

#ifdef __GNUC__
#define _ST_INT32 __attribute__ ((__mode__ (__SI__)))
#else
#define _ST_INT32
#endif

# ifndef	_POSIX_SOURCE

#  define	physadr		physadr_t
#  define	quad		quad_t

#ifndef _WINSOCK_H
typedef	unsigned char	u_char;
typedef	unsigned short	u_short;
typedef	unsigned int	u_int;
typedef	unsigned long	u_long;
#endif

typedef	unsigned short	ushort;		
typedef	unsigned int	uint;		
# endif	

#ifndef __clock_t_defined
typedef _CLOCK_T_ clock_t;
#define __clock_t_defined
#endif

#ifndef __time_t_defined
typedef _TIME_T_ time_t;
#define __time_t_defined

struct timespec {
  time_t  tv_sec;   
  long    tv_nsec;  
};

struct itimerspec {
  struct timespec  it_interval;  
  struct timespec  it_value;     
};
#endif

typedef	long	daddr_t;
typedef	char *	caddr_t;

#ifdef __MS_types__
typedef	unsigned long	ino_t;
#else
#ifdef __sparc__
typedef	unsigned long	ino_t;
#else
typedef	unsigned short	ino_t;
#endif
#endif

#ifdef __MS_types__
typedef unsigned long vm_offset_t;
typedef unsigned long vm_size_t;

#define __BIT_TYPES_DEFINED__

typedef char int8_t;
typedef unsigned char u_int8_t;
typedef short int16_t;
typedef unsigned short u_int16_t;
typedef int int32_t;
typedef unsigned int u_int32_t;
typedef long long int64_t;
typedef unsigned long long u_int64_t;
typedef int32_t register_t;
#endif 

#if defined(__rtems__)

typedef unsigned long long dev_t;
#else
typedef	short	dev_t;
#endif

typedef	long	off_t;

typedef	unsigned short	uid_t;
typedef	unsigned short	gid_t;
typedef int pid_t;
typedef	long key_t;
typedef long ssize_t;

#ifdef __MS_types__
typedef	char *	addr_t;
typedef int mode_t;
#else
#if defined (__sparc__) && !defined (__sparc_v9__)
#ifdef __svr4__
typedef unsigned long mode_t;
#else
typedef unsigned short mode_t;
#endif
#else
typedef unsigned int mode_t _ST_INT32;
#endif
#endif 

typedef unsigned short nlink_t;

# if ! defined (_POSIX_SOURCE) && ! defined (_WINSOCK_H)

#  define	NBBY	8		

#  ifndef	FD_SETSIZE
#	define	FD_SETSIZE	64
#  endif

typedef	long	fd_mask;
#  define	NFDBITS	(sizeof (fd_mask) * NBBY)	
#  ifndef	howmany
#	define	howmany(x,y)	(((x)+((y)-1))/(y))
#  endif

typedef	struct _types_fd_set {
	fd_mask	fds_bits[howmany(FD_SETSIZE, NFDBITS)];
} _types_fd_set;

#define fd_set _types_fd_set

#  define	FD_SET(n, p)	((p)->fds_bits[(n)/NFDBITS] |= (1L << ((n) % NFDBITS)))
#  define	FD_CLR(n, p)	((p)->fds_bits[(n)/NFDBITS] &= ~(1L << ((n) % NFDBITS)))
#  define	FD_ISSET(n, p)	((p)->fds_bits[(n)/NFDBITS] & (1L << ((n) % NFDBITS)))
#  define	FD_ZERO(p)	(__extension__ (void)({ \
     size_t __i; \
     char *__tmp = (char *)p; \
     for (__i = 0; __i < sizeof (*(p)); ++__i) \
       *__tmp++ = 0; \
}))

# endif	

#undef __MS_types__
#undef _ST_INT32

#if defined(__rtems__)

#ifndef __clockid_t_defined
typedef _CLOCKID_T_ clockid_t;
#define __clockid_t_defined
#endif

#ifndef __timer_t_defined
typedef _TIMER_T_ timer_t;
#define __timer_t_defined
#endif

#include <sys/features.h>

#if defined(_POSIX_THREADS)

#include <sys/sched.h>

typedef __uint32_t pthread_t;            

#define PTHREAD_SCOPE_PROCESS 0
#define PTHREAD_SCOPE_SYSTEM  1

#define PTHREAD_INHERIT_SCHED  1      
                                      
                                      
#define PTHREAD_EXPLICIT_SCHED 2      

#define PTHREAD_CREATE_DETACHED 0
#define PTHREAD_CREATE_JOINABLE  1

typedef struct {
  int is_initialized;
  void *stackaddr;
  int stacksize;
  int contentionscope;
  int inheritsched;
  int schedpolicy;
  struct sched_param schedparam;

  
#if defined(_POSIX_THREAD_CPUTIME)
  int  cputime_clock_allowed;  
#endif
  int  detachstate;

} pthread_attr_t;

#if defined(_POSIX_THREAD_PROCESS_SHARED)

#define PTHREAD_PROCESS_PRIVATE 0 
#define PTHREAD_PROCESS_SHARED  1 
                                  
                                  
#endif

#if defined(_POSIX_THREAD_PRIO_PROTECT)

#define PTHREAD_PRIO_NONE    0
#define PTHREAD_PRIO_INHERIT 1
#define PTHREAD_PRIO_PROTECT 2
#endif

typedef __uint32_t pthread_mutex_t;      

typedef struct {
  int   is_initialized;
#if defined(_POSIX_THREAD_PROCESS_SHARED)
  int   process_shared;  
#endif
#if defined(_POSIX_THREAD_PRIO_PROTECT)
  int   prio_ceiling;
  int   protocol;
#endif
  int   recursive;
} pthread_mutexattr_t;

typedef __uint32_t pthread_cond_t;       

typedef struct {
  int   is_initialized;
#if defined(_POSIX_THREAD_PROCESS_SHARED)
  int   process_shared;       
#endif
} pthread_condattr_t;         

typedef __uint32_t pthread_key_t;        

typedef struct {
  int   is_initialized;  
  int   init_executed;   
} pthread_once_t;       

#endif 

#endif  

#endif	

/* time.h -- An implementation of the standard Unix <sys/time.h> file.
   Written by Geoffrey Noer <noer@cygnus.com>
   Public domain; no rights reserved. */

#ifndef _SYS_TIME_H_
#define _SYS_TIME_H_

#include <_ansi.h>
#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _WINSOCK_H
struct timeval {
  long tv_sec;
  long tv_usec;
};

struct timezone {
  int tz_minuteswest;
  int tz_dsttime;
};

#ifdef __CYGWIN__
#include <sys/select.h>
#endif 

#endif 

#define ITIMER_REAL     0
#define ITIMER_VIRTUAL  1
#define ITIMER_PROF     2

struct  itimerval {
  struct  timeval it_interval;
  struct  timeval it_value;
};

#if defined(__rtems__)

#define	timerisset(tvp)		((tvp)->tv_sec || (tvp)->tv_usec)
#define	timerclear(tvp)		((tvp)->tv_sec = (tvp)->tv_usec = 0)
#define	timercmp(a, b, CMP) 						      \
  (((a)->tv_sec == (b)->tv_sec) ? 					      \
   ((a)->tv_usec CMP (b)->tv_usec) : 					      \
   ((a)->tv_sec CMP (b)->tv_sec))
#define	timeradd(a, b, result)						      \
  do {									      \
    (result)->tv_sec = (a)->tv_sec + (b)->tv_sec;			      \
    (result)->tv_usec = (a)->tv_usec + (b)->tv_usec;			      \
    if ((result)->tv_usec >= 1000000)					      \
      {									      \
	++(result)->tv_sec;						      \
	(result)->tv_usec -= 1000000;					      \
      }									      \
  } while (0)
#define	timersub(a, b, result)						      \
  do {									      \
    (result)->tv_sec = (a)->tv_sec - (b)->tv_sec;			      \
    (result)->tv_usec = (a)->tv_usec - (b)->tv_usec;			      \
    if ((result)->tv_usec < 0) {					      \
      --(result)->tv_sec;						      \
      (result)->tv_usec += 1000000;					      \
    }									      \
  } while (0)
#endif

int _EXFUN(gettimeofday, (struct timeval *__p, struct timezone *__z));
int _EXFUN(settimeofday, (const struct timeval *, const struct timezone *));
int _EXFUN(utimes, (const char *__path, struct timeval *__tvp));
int _EXFUN(getitimer, (int __which, struct itimerval *__value));
int _EXFUN(setitimer, (int __which, const struct itimerval *__value,
					struct itimerval *__ovalue));

#ifdef __cplusplus
}
#endif
#endif 

#define SCHED_OTHER    0
#define SCHED_FIFO     1
#define SCHED_RR       2

#if defined(_POSIX_SPORADIC_SERVER)
#define SCHED_SPORADIC 3 
#endif

struct sched_param {
  int sched_priority;           

#if defined(_POSIX_SPORADIC_SERVER)
  int ss_low_priority;          
                                
  struct timespec ss_replenish_period; 
                                
  struct timespec ss_initial_budget;   
#endif
};

#ifdef __cplusplus
}
#endif 

#endif

typedef __uint32_t pthread_t;            

#define PTHREAD_SCOPE_PROCESS 0
#define PTHREAD_SCOPE_SYSTEM  1

#define PTHREAD_INHERIT_SCHED  1      
                                      
                                      
#define PTHREAD_EXPLICIT_SCHED 2      

#define PTHREAD_CREATE_DETACHED 0
#define PTHREAD_CREATE_JOINABLE  1

typedef struct {
  int is_initialized;
  void *stackaddr;
  int stacksize;
  int contentionscope;
  int inheritsched;
  int schedpolicy;
  struct sched_param schedparam;

  
#if defined(_POSIX_THREAD_CPUTIME)
  int  cputime_clock_allowed;  
#endif
  int  detachstate;

} pthread_attr_t;

#if defined(_POSIX_THREAD_PROCESS_SHARED)

#define PTHREAD_PROCESS_PRIVATE 0 
#define PTHREAD_PROCESS_SHARED  1 
                                  
                                  
#endif

#if defined(_POSIX_THREAD_PRIO_PROTECT)

#define PTHREAD_PRIO_NONE    0
#define PTHREAD_PRIO_INHERIT 1
#define PTHREAD_PRIO_PROTECT 2
#endif

typedef __uint32_t pthread_mutex_t;      

typedef struct {
  int   is_initialized;
#if defined(_POSIX_THREAD_PROCESS_SHARED)
  int   process_shared;  
#endif
#if defined(_POSIX_THREAD_PRIO_PROTECT)
  int   prio_ceiling;
  int   protocol;
#endif
  int   recursive;
} pthread_mutexattr_t;

typedef __uint32_t pthread_cond_t;       

typedef struct {
  int   is_initialized;
#if defined(_POSIX_THREAD_PROCESS_SHARED)
  int   process_shared;       
#endif
} pthread_condattr_t;         

typedef __uint32_t pthread_key_t;        

typedef struct {
  int   is_initialized;  
  int   init_executed;   
} pthread_once_t;       

#endif 

#endif  

#endif	

#endif

typedef unsigned long sigset_t;

#if defined(__rtems__)

#if defined(_POSIX_REALTIME_SIGNALS)

#define SIGEV_NONE   1  
                        
#define SIGEV_SIGNAL 2  
                        
                        
#define SIGEV_THREAD 3  
                        

union sigval {
  int    sival_int;    
  void  *sival_ptr;    
};

struct sigevent {
  int              sigev_notify;               
  int              sigev_signo;                
  union sigval     sigev_value;                

#if defined(_POSIX_THREADS)
  void           (*sigev_notify_function)( union sigval );
                                               
  pthread_attr_t  *sigev_notify_attributes;    
#endif
};

#define SI_USER    1    
#define SI_QUEUE   2    
#define SI_TIMER   3    
#define SI_ASYNCIO 4    
#define SI_MESGQ   5    

typedef struct {
  int          si_signo;    
  int          si_code;     
  union sigval si_value;    
} siginfo_t;
#endif

#define SA_NOCLDSTOP 1   
#define SA_SIGINFO   2   
                         

struct sigaction {
  int         sa_flags;       
  sigset_t    sa_mask;        
                              
                              
  union {
    void      (*_handler)();  
#if defined(_POSIX_REALTIME_SIGNALS)
    void      (*_sigaction)( int, siginfo_t *, void * );
#endif
  } _signal_handlers;
};

#define sa_handler    _signal_handlers._handler
#if defined(_POSIX_REALTIME_SIGNALS)
#define sa_sigaction  _signal_handlers._sigaction
#endif

#else

struct sigaction 
{
	void (*sa_handler)(int);
	sigset_t sa_mask;
	int sa_flags;
};

#define SA_NOCLDSTOP 1  

#endif 

#define SIG_SETMASK 0	
#define SIG_BLOCK 1	
#define SIG_UNBLOCK 2	

#define sigaddset(what,sig) (*(what) |= (1<<(sig)))
#define sigemptyset(what)   (*(what) = 0)

int _EXFUN(sigprocmask, (int how, const sigset_t *set, sigset_t *oset));

#if defined(_POSIX_THREADS)
int _EXFUN(pthread_sigmask, (int how, const sigset_t *set, sigset_t *oset));
#endif

#if defined(__CYGWIN__) || defined(__rtems__)
#undef sigaddset
#undef sigemptyset

int _EXFUN(kill, (int, int));
int _EXFUN(sigaction, (int, const struct sigaction *, struct sigaction *));
int _EXFUN(sigaddset, (sigset_t *, const int));
int _EXFUN(sigdelset, (sigset_t *, const int));
int _EXFUN(sigismember, (const sigset_t *, int));
int _EXFUN(sigfillset, (sigset_t *));
int _EXFUN(sigemptyset, (sigset_t *));
int _EXFUN(sigpending, (sigset_t *));
int _EXFUN(sigsuspend, (const sigset_t *));
int _EXFUN(sigpause, (int));

#if defined(_POSIX_THREADS)
int _EXFUN(pthread_kill, (pthread_t thread, int sig));
#endif

#if defined(_POSIX_REALTIME_SIGNALS)

int _EXFUN(sigwaitinfo, (const sigset_t *set, siginfo_t *info));
int _EXFUN(sigtimedwait,
  (const sigset_t *set, siginfo_t *info, const struct timespec  *timeout)
);
int _EXFUN(sigwait, (const sigset_t *set, int *sig));

int _EXFUN(sigqueue, (pid_t pid, int signo, const union sigval value));

#endif 

#endif 

#if defined(___AM29K__)

#define SIGABRT 1
#define SIGFPE 1
#define SIGILL 1
#define SIGINT 1
#define SIGSEGV 1
#define SIGTERM 1

#define SIGHUP 1
#define SIGQUIT 1
#define NSIG 2
#elif defined(__GO32__)
#define SIGINT  1
#define SIGKILL 2
#define SIGPIPE 3
#define SIGFPE  4
#define SIGHUP  5
#define SIGTERM 6
#define SIGSEGV 7
#define SIGTSTP 8
#define SIGQUIT 9
#define SIGTRAP 10
#define SIGILL  11
#define SIGEMT  12
#define SIGALRM 13
#define SIGBUS  14
#define SIGLOST 15
#define SIGSTOP 16
#define SIGABRT 17
#define SIGUSR1	18
#define SIGUSR2	19
#define NSIG    20
#elif defined(__CYGWIN__)	
#define	SIGHUP	1	
#define	SIGINT	2	
#define	SIGQUIT	3	
#define	SIGILL	4	
#define	SIGTRAP	5	
#define	SIGABRT 6	
#define	SIGEMT	7	
#define	SIGFPE	8	
#define	SIGKILL	9	
#define	SIGBUS	10	
#define	SIGSEGV	11	
#define	SIGSYS	12	
#define	SIGPIPE	13	
#define	SIGALRM	14	
#define	SIGTERM	15	
#define	SIGURG	16	
#define	SIGSTOP	17	
#define	SIGTSTP	18	
#define	SIGCONT	19	
#define	SIGCHLD	20	
#define	SIGCLD	20	
#define	SIGTTIN	21	
#define	SIGTTOU	22	
#define	SIGIO	23	
#define	SIGPOLL	SIGIO	
#define	SIGXCPU	24	
#define	SIGXFSZ	25	
#define	SIGVTALRM 26	
#define	SIGPROF	27	
#define	SIGWINCH 28	
#define	SIGLOST 29	
#define	SIGUSR1 30	
#define	SIGUSR2 31	
#define NSIG	32      
#else
#define	SIGHUP	1	
#define	SIGINT	2	
#define	SIGQUIT	3	
#define	SIGILL	4	
#define	SIGTRAP	5	
#define	SIGIOT	6	
#define	SIGABRT 6	
#define	SIGEMT	7	
#define	SIGFPE	8	
#define	SIGKILL	9	
#define	SIGBUS	10	
#define	SIGSEGV	11	
#define	SIGSYS	12	
#define	SIGPIPE	13	
#define	SIGALRM	14	
#define	SIGTERM	15	

#if defined(__rtems__)
#define SIGUSR1 16  
#define SIGUSR2 17  

#define __SIGFIRSTNOTRT SIGHUP
#define __SIGLASTNOTRT  SIGUSR2

#define SIGRTMIN 18
#define SIGRTMAX 32

#elif defined(__svr4__)

#define	SIGUSR1	16
#define SIGUSR2	17
#define SIGCLD	18
#define	SIGPWR	19
#define SIGWINCH 20
#define	SIGPOLL	22	
#define	SIGSTOP	23	
#define	SIGTSTP	24	
#define	SIGCONT	25	
#define	SIGTTIN	26	
#define	SIGTTOU	27	
#define NSIG	28	
#else
#define	SIGURG	16	
#define	SIGSTOP	17	
#define	SIGTSTP	18	
#define	SIGCONT	19	
#define	SIGCHLD	20	
#define	SIGCLD	20	
#define	SIGTTIN	21	
#define	SIGTTOU	22	
#define	SIGIO	23	
#define	SIGPOLL	SIGIO	
#define	SIGXCPU	24	
#define	SIGXFSZ	25	
#define	SIGVTALRM 26	
#define	SIGPROF	27	
#define	SIGWINCH 28	
#define	SIGLOST 29	
#define	SIGUSR1 30	
#define	SIGUSR2 31	
#define NSIG	32      
#endif
#endif

#ifdef __cplusplus
}
#endif
#endif 

typedef int	sig_atomic_t;		/* Atomic entity type (ANSI) */

#if defined(__STDC__) || defined(__cplusplus)
#define SIG_DFL ((void (*)(int))0)	
#define SIG_IGN ((void (*)(int))1)	
#define SIG_ERR ((void (*)(int))-1)	
#else
#define SIG_DFL ((void (*)())0)		
#define SIG_IGN ((void (*)())1)		
#define SIG_ERR ((void (*)())-1)	
#endif

typedef void (*_sig_func_ptr) (int);

struct _reent;

_sig_func_ptr _EXFUN(_signal_r, (struct _reent *, int, _sig_func_ptr));
int	_EXFUN(_raise_r, (struct _reent *, int));

#ifndef _REENT_ONLY
_sig_func_ptr _EXFUN(signal, (int, _sig_func_ptr));
int	_EXFUN(raise, (int));
#endif

#ifdef __cplusplus
}
#endif
#endif 

int _EXFUN(clock_settime, (clockid_t clock_id, const struct timespec *tp));
int _EXFUN(clock_gettime, (clockid_t clock_id, struct timespec *tp));
int _EXFUN(clock_getres,  (clockid_t clock_id, struct timespec *res));

int _EXFUN(timer_create,
  (clockid_t clock_id, struct sigevent *evp, timer_t *timerid));

int _EXFUN(timer_delete, (timer_t timerid));

int _EXFUN(timer_settime,
  (timer_t timerid, int flags, const struct itimerspec *value,
   struct itimerspec *ovalue));
int _EXFUN(timer_gettime, (timer_t timerid, struct itimerspec *value));
int _EXFUN(timer_getoverrun, (timer_t timerid));

int _EXFUN(nanosleep, (const struct timespec  *rqtp, struct timespec *rmtp));

#endif 

#define CLOCK_ENABLED  1  
#define CLOCK_DISABLED 0  

#define CLOCK_ALLOWED    1 
                           
                           
#define CLOCK_DISALLOWED 0 
                           
                           

#define CLOCK_REALTIME (clockid_t)1

#define TIMER_ABSTIME  4

#if defined(_POSIX_CPUTIME)

#define CLOCK_PROCESS_CPUTIME (clockid_t)2

#endif

#if defined(_POSIX_THREAD_CPUTIME)

#define CLOCK_THREAD_CPUTIME (clockid_t)3

#endif

#if defined(_POSIX_CPUTIME)

int _EXFUN(clock_getcpuclockid, (pid_t pid, clockid_t *clock_id));

#endif 

#if defined(_POSIX_CPUTIME) || defined(_POSIX_THREAD_CPUTIME)

int _EXFUN(clock_setenable_attr, (clockid_t clock_id, int attr));
int _EXFUN(clock_getenable_attr, (clockid_t clock_id, int *attr));

#endif 

#ifdef __cplusplus
}
#endif
#endif 

#ifndef __Long
#if __LONG_MAX__ == 2147483647L
#define __Long long
typedef unsigned __Long __ULong;
#elif __INT_MAX__ == 2147483647
#define __Long int
typedef unsigned __Long __ULong;
#endif
#endif

#ifndef __Long
#define __Long __int32_t
typedef __uint32_t __ULong;
#endif

struct _glue 
{
  struct _glue *_next;
  int _niobs;
  struct __sFILE *_iobs;
};

struct _Bigint 
{
  struct _Bigint *_next;
  int _k, _maxwds, _sign, _wds;
  __ULong _x[1];
};

#define	_ATEXIT_SIZE 32	

struct _atexit {
	struct	_atexit *_next;			
	int	_ind;				
	void	(*_fns[_ATEXIT_SIZE])(void);	
};

struct __sbuf {
	unsigned char *_base;
	int	_size;
};

typedef long _fpos_t;		
				

struct __sFILE {
  unsigned char *_p;	
  int	_r;		
  int	_w;		
  short	_flags;		
  short	_file;		
  struct __sbuf _bf;	
  int	_lbfsize;	

  
  _PTR	_cookie;	

  int	_EXFUN((*_read),(_PTR _cookie, char *_buf, int _n));
  int	_EXFUN((*_write),(_PTR _cookie, const char *_buf, int _n));
  _fpos_t _EXFUN((*_seek),(_PTR _cookie, _fpos_t _offset, int _whence));
  int	_EXFUN((*_close),(_PTR _cookie));

  
  struct __sbuf _ub;	
  unsigned char *_up;	
  int	_ur;		

  
  unsigned char _ubuf[3];	
  unsigned char _nbuf[1];	

  
  struct __sbuf _lb;	

  
  int	_blksize;	
  int	_offset;	

  struct _reent *_data;
};

struct _reent
{
  
  int _errno;

  

  struct __sFILE *_stdin, *_stdout, *_stderr;

  int  _inc;			
  char _emergency[25];
 
  int _current_category;	
  _CONST char *_current_locale;

  int __sdidinit;		

  void _EXFUN((*__cleanup),(struct _reent *));

  
  struct _Bigint *_result;
  int _result_k;
  struct _Bigint *_p5s;
  struct _Bigint **_freelist;

  
  int _cvtlen;			
  char *_cvtbuf;

  union
    {
      struct
        {
          unsigned int _unused_rand;
          char * _strtok_last;
          char _asctime_buf[26];
          struct tm _localtime_buf;
          int _gamma_signgam;
          __extension__ unsigned long long _rand_next;

        } _reent;
  

 
      struct
        {
#define _N_LISTS 30
          unsigned char * _nextf[_N_LISTS];
          unsigned int _nmalloc[_N_LISTS];
        } _unused;
    } _new;

  
  struct _atexit *_atexit;	
  struct _atexit _atexit0;	

  
  void (**(_sig_func))(int);

  

  struct _glue __sglue;			
  struct __sFILE __sf[3];		
};

#define _REENT_INIT(var) \
  { 0, &var.__sf[0], &var.__sf[1], &var.__sf[2], 0, "", 0, "C", \
    0, NULL, NULL, 0, NULL, NULL, 0, NULL, { {0, NULL, "", \
    { 0,0,0,0,0,0,0,0}, 0, 1} } }

#ifndef __ATTRIBUTE_IMPURE_PTR__
#define __ATTRIBUTE_IMPURE_PTR__
#endif

extern struct _reent *_impure_ptr __ATTRIBUTE_IMPURE_PTR__;

void _reclaim_reent _PARAMS ((struct _reent *));

#ifndef _REENT_ONLY
#define _REENT _impure_ptr
#endif

#ifdef __cplusplus
}
#endif
#endif 

typedef _fpos_t fpos_t;

typedef struct __sFILE FILE;

#define	__SLBF	0x0001		
#define	__SNBF	0x0002		
#define	__SRD	0x0004		
#define	__SWR	0x0008		
	
#define	__SRW	0x0010		
#define	__SEOF	0x0020		
#define	__SERR	0x0040		
#define	__SMBF	0x0080		
#define	__SAPP	0x0100		
#define	__SSTR	0x0200		
#define	__SOPT	0x0400		
#define	__SNPT	0x0800		
#define	__SOFF	0x1000		
#define	__SMOD	0x2000		
#if defined(__CYGWIN__) || defined(__CYGWIN__)
#define __SCLE        0x4000          
#endif

#define	_IOFBF	0		
#define	_IOLBF	1		
#define	_IONBF	2		

#ifndef NULL
#define	NULL	0
#endif

#define	BUFSIZ	1024
#define	EOF	(-1)

#define	FOPEN_MAX	20	
#define	FILENAME_MAX	1024	
#define	L_tmpnam	1024	
#ifndef __STRICT_ANSI__
#define P_tmpdir        "/tmp"
#endif

#ifndef SEEK_SET
#define	SEEK_SET	0	
#endif
#ifndef SEEK_CUR
#define	SEEK_CUR	1	
#endif
#ifndef SEEK_END
#define	SEEK_END	2	
#endif

#define	TMP_MAX		26

#define	stdin	(_impure_ptr->_stdin)
#define	stdout	(_impure_ptr->_stdout)
#define	stderr	(_impure_ptr->_stderr)

#define _stdin_r(x)	((x)->_stdin)
#define _stdout_r(x)	((x)->_stdout)
#define _stderr_r(x)	((x)->_stderr)

#ifdef __GNUC__
#define __VALIST __gnuc_va_list
#else
#define __VALIST char*
#endif

#ifndef _REENT_ONLY
int	_EXFUN(remove, (const char *));
int	_EXFUN(rename, (const char *, const char *));
#endif
char *	_EXFUN(tempnam, (const char *, const char *));
FILE *	_EXFUN(tmpfile, (void));
char *	_EXFUN(tmpnam, (char *));
int	_EXFUN(fclose, (FILE *));
int	_EXFUN(fflush, (FILE *));
FILE *	_EXFUN(freopen, (const char *, const char *, FILE *));
void	_EXFUN(setbuf, (FILE *, char *));
int	_EXFUN(setvbuf, (FILE *, char *, int, size_t));
int	_EXFUN(fprintf, (FILE *, const char *, ...));
int	_EXFUN(fscanf, (FILE *, const char *, ...));
int	_EXFUN(printf, (const char *, ...));
int	_EXFUN(scanf, (const char *, ...));
int	_EXFUN(sscanf, (const char *, const char *, ...));
int	_EXFUN(vfprintf, (FILE *, const char *, __VALIST));
int	_EXFUN(vprintf, (const char *, __VALIST));
int	_EXFUN(vsprintf, (char *, const char *, __VALIST));
int	_EXFUN(vsnprintf, (char *, size_t, const char *, __VALIST));
int	_EXFUN(fgetc, (FILE *));
char *  _EXFUN(fgets, (char *, int, FILE *));
int	_EXFUN(fputc, (int, FILE *));
int	_EXFUN(fputs, (const char *, FILE *));
int	_EXFUN(getc, (FILE *));
int	_EXFUN(getchar, (void));
char *  _EXFUN(gets, (char *));
int	_EXFUN(putc, (int, FILE *));
int	_EXFUN(putchar, (int));
int	_EXFUN(puts, (const char *));
int	_EXFUN(ungetc, (int, FILE *));
size_t	_EXFUN(fread, (_PTR, size_t _size, size_t _n, FILE *));
size_t	_EXFUN(fwrite, (const _PTR , size_t _size, size_t _n, FILE *));
int	_EXFUN(fgetpos, (FILE *, fpos_t *));
int	_EXFUN(fseek, (FILE *, long, int));
int	_EXFUN(fsetpos, (FILE *, const fpos_t *));
long	_EXFUN(ftell, ( FILE *));
void	_EXFUN(rewind, (FILE *));
void	_EXFUN(clearerr, (FILE *));
int	_EXFUN(feof, (FILE *));
int	_EXFUN(ferror, (FILE *));
void    _EXFUN(perror, (const char *));
#ifndef _REENT_ONLY
FILE *	_EXFUN(fopen, (const char *_name, const char *_type));
int	_EXFUN(sprintf, (char *, const char *, ...));
int	_EXFUN(snprintf, (char *, size_t, const char *, ...));
#endif
#ifndef __STRICT_ANSI__
int	_EXFUN(vfiprintf, (FILE *, const char *, __VALIST));
int	_EXFUN(iprintf, (const char *, ...));
int	_EXFUN(fiprintf, (FILE *, const char *, ...));
int	_EXFUN(siprintf, (char *, const char *, ...));
#endif

#ifndef __STRICT_ANSI__
#ifndef _REENT_ONLY
FILE *	_EXFUN(fdopen, (int, const char *));
#endif
int	_EXFUN(fileno, (FILE *));
int	_EXFUN(getw, (FILE *));
int	_EXFUN(pclose, (FILE *));
FILE *  _EXFUN(popen, (const char *, const char *));
int	_EXFUN(putw, (int, FILE *));
void    _EXFUN(setbuffer, (FILE *, char *, int));
int	_EXFUN(setlinebuf, (FILE *));
#endif

FILE *	_EXFUN(_fdopen_r, (struct _reent *, int, const char *));
FILE *	_EXFUN(_fopen_r, (struct _reent *, const char *, const char *));
int	_EXFUN(_getchar_r, (struct _reent *));
char *	_EXFUN(_gets_r, (struct _reent *, char *));
int	_EXFUN(_iprintf_r, (struct _reent *, const char *, ...));
int	_EXFUN(_mkstemp_r, (struct _reent *, char *));
char *	_EXFUN(_mktemp_r, (struct _reent *, char *));
void	_EXFUN(_perror_r, (struct _reent *, const char *));
int	_EXFUN(_printf_r, (struct _reent *, const char *, ...));
int	_EXFUN(_putchar_r, (struct _reent *, int));
int	_EXFUN(_puts_r, (struct _reent *, const char *));
int	_EXFUN(_remove_r, (struct _reent *, const char *));
int	_EXFUN(_rename_r, (struct _reent *,
			   const char *_old, const char *_new));
int	_EXFUN(_scanf_r, (struct _reent *, const char *, ...));
int	_EXFUN(_sprintf_r, (struct _reent *, char *, const char *, ...));
int	_EXFUN(_snprintf_r, (struct _reent *, char *, size_t, const char *, ...));
char *	_EXFUN(_tempnam_r, (struct _reent *, const char *, const char *));
FILE *	_EXFUN(_tmpfile_r, (struct _reent *));
char *	_EXFUN(_tmpnam_r, (struct _reent *, char *));
int	_EXFUN(_vfprintf_r, (struct _reent *, FILE *, const char *, __VALIST));
int	_EXFUN(_vprintf_r, (struct _reent *, const char *, __VALIST));
int	_EXFUN(_vsprintf_r, (struct _reent *, char *, const char *, __VALIST));
int	_EXFUN(_vsnprintf_r, (struct _reent *, char *, size_t, const char *, __VALIST));

int	_EXFUN(__srget, (FILE *));
int	_EXFUN(__swbuf, (int, FILE *));

#ifndef __STRICT_ANSI__
FILE	*_EXFUN(funopen,(const _PTR _cookie,
		int (*readfn)(_PTR _cookie, char *_buf, int _n),
		int (*writefn)(_PTR _cookie, const char *_buf, int _n),
		fpos_t (*seekfn)(_PTR _cookie, fpos_t _off, int _whence),
		int (*closefn)(_PTR _cookie)));

#define	fropen(cookie, fn) funopen(cookie, fn, (int (*)())0, (fpos_t (*)())0, (int (*)())0)
#define	fwopen(cookie, fn) funopen(cookie, (int (*)())0, fn, (fpos_t (*)())0, (int (*)())0)
#endif

#define       __sgetc_raw(p) (--(p)->_r < 0 ? __srget(p) : (int)(*(p)->_p++))

#ifdef __SCLE
static __inline__ int __sgetc(FILE *__p);
#else
#define __sgetc(p) __sgetc_raw(p)
#endif

#ifdef _never 

static __inline int __sputc(int _c, FILE *_p);
#else

#define       __sputc_raw(c, p) \
	(--(p)->_w < 0 ? \
		(p)->_w >= (p)->_lbfsize ? \
			(*(p)->_p = (c)), *(p)->_p != '\n' ? \
				(int)*(p)->_p++ : \
				__swbuf('\n', p) : \
			__swbuf((int)(c), p) : \
		(*(p)->_p = (c), (int)*(p)->_p++))
#ifdef __SCLE
#define __sputc(c, p) \
        ((((p)->_flags & __SCLE) && ((c) == '\n')) \
          ? __sputc_raw('\r', (p)) : 0 , \
        __sputc_raw((c), (p)))
#else
#define __sputc(c, p) __sputc_raw(c, p)
#endif
#endif

#define	__sfeof(p)	(((p)->_flags & __SEOF) != 0)
#define	__sferror(p)	(((p)->_flags & __SERR) != 0)
#define	__sclearerr(p)	((void)((p)->_flags &= ~(__SERR|__SEOF)))
#define	__sfileno(p)	((p)->_file)

#define	feof(p)		__sfeof(p)
#define	ferror(p)	__sferror(p)
#define	clearerr(p)	__sclearerr(p)

#if 0 
#define	fileno(p)	__sfileno(p)
#endif

#ifndef __CYGWIN__
#ifndef lint
#define	getc(fp)	__sgetc(fp)
#define putc(x, fp)	__sputc(x, fp)
#endif 
#endif 

#define	getchar()	getc(stdin)
#define	putchar(x)	putc(x, stdout)

#ifndef __STRICT_ANSI__

#define	fast_putc(x,p) (--(p)->_w < 0 ? \
	__swbuf((int)(x), p) == EOF : (*(p)->_p = (x), (p)->_p++, 0))

#define	L_cuserid	9		
#ifdef __CYGWIN__
#define L_ctermid       16
#endif
#endif

#ifdef __cplusplus
}
#endif
#endif 

/* gt4: stand-in for gcc's <limits.h> (ee-gcc: 64-bit long). */
#ifndef _LIMITS_H
#define _LIMITS_H
#define CHAR_BIT 8
#define MB_LEN_MAX 1
#define SCHAR_MAX 127
#define SCHAR_MIN (-128)
#define UCHAR_MAX 255
#define CHAR_MAX SCHAR_MAX
#define CHAR_MIN SCHAR_MIN
#define SHRT_MAX 32767
#define SHRT_MIN (-32768)
#define USHRT_MAX 65535
#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)
#define UINT_MAX 4294967295U
#define LONG_MAX 9223372036854775807L
#define LONG_MIN (-LONG_MAX - 1L)
#define ULONG_MAX 18446744073709551615UL
#define LONG_LONG_MAX 9223372036854775807LL
#define LONG_LONG_MIN (-LONG_LONG_MAX - 1LL)
#define ULONG_LONG_MAX 18446744073709551615ULL
#endif

#ifdef _HAVE_STDC
/* gt4: stand-in for gcc's <stdarg.h> (the compiler ships without headers). */
#ifndef _STDARG_H
#define _STDARG_H
#ifndef __GNUC_VA_LIST
#define __GNUC_VA_LIST
typedef __builtin_va_list __gnuc_va_list;
#endif
typedef __gnuc_va_list va_list;
#define va_start(v, l) __builtin_stdarg_start((v), l)
#define va_arg(v, t) __builtin_va_arg((v), t)
#define va_end(v) __builtin_va_end(v)
#endif

#else
#include <varargs.h>
#endif

int
vsnprintf ();

int
vsnprintf_r (ptr, str, size, fmt, ap)
     struct _reent *ptr;
     char *str;
     size_t size;
     char _CONST *fmt;
     va_list ap;

{
  int ret;
  FILE f;

  f._flags = __SWR | __SSTR;
  f._bf._base = f._p = (unsigned char *) str;
  f._bf._size = f._w = (size > 0 ? size - 1 : 0);
  f._data = ptr;
  ret = vfprintf (&f, fmt, ap);
  if (size > 0)
    *f._p = 0;
  return ret;
}

