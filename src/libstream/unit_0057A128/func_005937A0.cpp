/* libio 2.8.0 (gcc 2000-10-03 snapshot): istream::get() (func_005937A0) from isgetline.cc, placed at 0x005937a0 by
 * tools/libmatch.py. Third-party code, see THIRD_PARTY.md for its license and origin.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
/* This is part of libio/iostream, providing -*- C++ -*- input/output.
Copyright (C) 1993 Free Software Foundation

This file is part of the GNU IO Library.  This library is free
software; you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the
Free Software Foundation; either version 2, or (at your option)
any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this library; see the file COPYING.  If not, write to the Free
Software Foundation, 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

As a special exception, if you link this library with files
compiled with a GNU compiler to produce an executable, this does not cause
the resulting executable to be covered by the GNU General Public License.
This exception does not however invalidate any other reasons why
the executable file might be covered by the GNU General Public License. */

/* Copyright (C) 1993, 1997, 2000 Free Software Foundation, Inc.
   This file is part of the GNU IO Library.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2, or (at
   your option) any later version.

   This library is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this library; see the file COPYING.  If not, write to
   the Free Software Foundation, 59 Temple Place - Suite 330, Boston,
   MA 02111-1307, USA.

   As a special exception, if you link this library with files
   compiled with a GNU compiler to produce an executable, this does
   not cause the resulting executable to be covered by the GNU General
   Public License.  This exception does not however invalidate any
   other reasons why the executable file might be covered by the GNU
   General Public License.  */

#ifndef _POSIX_SOURCE
# define _POSIX_SOURCE
#endif

/* errno is not a global variable, because that would make using it
   non-reentrant.  Instead, its address is returned by the function
   func_005A3130.  */

#ifndef _SYS_ERRNO_H_
#ifdef __cplusplus
extern "C" {
#endif
#define _SYS_ERRNO_H_

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

#if defined(_POSIX_TIMERS)

#ifndef _SIGNAL_H_
#ifdef __cplusplus
extern "C" {
#endif
#define _SIGNAL_H_

/* sys/signal.h */

#ifndef _SYS_SIGNAL_H
#define _SYS_SIGNAL_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_POSIX_THREADS)

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

#ifndef _REENT_ONLY
#define errno (*func_005A3130())
extern int *func_005A3130 _PARAMS ((void));
#endif

extern __IMPORT _CONST char * _CONST _sys_errlist[];
extern __IMPORT int _sys_nerr;

#define __errno_r(ptr) ((ptr)->_errno)

#define	EPERM 1		
#define	ENOENT 2	
#define	ESRCH 3		
#define	EINTR 4		
#define	EIO 5		
#define	ENXIO 6		
#define	E2BIG 7		
#define	ENOEXEC 8	
#define	EBADF 9		
#define	ECHILD 10	
#define	EAGAIN 11	
#define	ENOMEM 12	
#define	EACCES 13	
#define	EFAULT 14	
#define	ENOTBLK 15	
#define	EBUSY 16	
#define	EEXIST 17	
#define	EXDEV 18	
#define	ENODEV 19	
#define	ENOTDIR 20	
#define	EISDIR 21	
#define	EINVAL 22	
#define	ENFILE 23	
#define	EMFILE 24	
#define	ENOTTY 25	
#define	ETXTBSY 26	
#define	EFBIG 27	
#define	ENOSPC 28	
#define	ESPIPE 29	
#define	EROFS 30	
#define	EMLINK 31	
#define	EPIPE 32	
#define	EDOM 33		
#define	ERANGE 34	
#define	ENOMSG 35	
#define	EIDRM 36	
#define	ECHRNG 37	
#define	EL2NSYNC 38	
#define	EL3HLT 39	
#define	EL3RST 40	
#define	ELNRNG 41	
#define	EUNATCH 42	
#define	ENOCSI 43	
#define	EL2HLT 44	
#define	EDEADLK 45	
#define	ENOLCK 46	
#define EBADE 50	
#define EBADR 51	
#define EXFULL 52	
#define ENOANO 53	
#define EBADRQC 54	
#define EBADSLT 55	
#define EDEADLOCK 56	
#define EBFONT 57	
#define ENOSTR 60	
#define ENODATA 61	
#define ETIME 62	
#define ENOSR 63	
#define ENONET 64	
#define ENOPKG 65	
#define EREMOTE 66	
#define ENOLINK 67	
#define EADV 68		
#define ESRMNT 69	
#define	ECOMM 70	
#define EPROTO 71	
#define	EMULTIHOP 74	
#define	ELBIN 75	
#define	EDOTDOT 76	
#define EBADMSG 77	
#define ENOTUNIQ 80	
#define EBADFD 81	
#define EREMCHG 82	
#define ELIBACC 83	
#define ELIBBAD 84	
#define ELIBSCN 85	
#define ELIBMAX 86	
#define ELIBEXEC 87	
#define ENOSYS 88	
#define ENMFILE 89      
#define ENOTEMPTY 90	
#define ENAMETOOLONG 91	
#define ELOOP 92	
#define EOPNOTSUPP 95	
#define EPFNOSUPPORT 96 
#define ECONNRESET 104  
#define ENOBUFS 105	
#define EAFNOSUPPORT 106 
#define EPROTOTYPE 107	
#define ENOTSOCK 108	
#define ENOPROTOOPT 109	
#define ESHUTDOWN 110	
#define ECONNREFUSED 111	
#define EADDRINUSE 112		
#define ECONNABORTED 113	
#define ENETUNREACH 114		
#define ENETDOWN 115		
#define ETIMEDOUT 116		
#define EHOSTDOWN 117		
#define EHOSTUNREACH 118	
#define EINPROGRESS 119		
#define EALREADY 120		
#define EDESTADDRREQ 121	
#define EMSGSIZE 122		
#define EPROTONOSUPPORT 123	
#define ESOCKTNOSUPPORT 124	
#define EADDRNOTAVAIL 125	
#define ENETRESET 126
#define EISCONN 127		
#define ENOTCONN 128		
#define ETOOMANYREFS 129
#define EPROCLIM 130
#define EUSERS 131
#define EDQUOT 132
#define ESTALE 133
#define ENOTSUP 134		
#define ENOMEDIUM 135   
#define ENOSHARE 136    

#define EWOULDBLOCK EAGAIN	

#define __ELASTERROR 2000	

#ifdef __cplusplus
}
#endif
#endif 

#ifndef __set_errno
# define __set_errno(Val) errno = (Val)
#endif

#ifdef _IO_MTSAFE_IO
# if defined __GLIBC__ && __GLIBC__ >= 2
#  if __GLIBC_MINOR__ > 0
#   include <bits/libc-lock.h>
#  else
#   include <libc-lock.h>
#  endif
# else

# endif
#endif

/* Copyright (C) 1991, 92, 93, 94, 95, 97, 98 Free Software Foundation, Inc.
   This file is part of the GNU IO Library.
   Written by Per Bothner <bothner@cygnus.com>.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2, or (at
   your option) any later version.

   This library is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this library; see the file COPYING.  If not, write to
   the Free Software Foundation, 59 Temple Place - Suite 330, Boston,
   MA 02111-1307, USA.

   As a special exception, if you link this library with files
   compiled with a GNU compiler to produce an executable, this does
   not cause the resulting executable to be covered by the GNU General
   Public License.  This exception does not however invalidate any
   other reasons why the executable file might be covered by the GNU
   General Public License.  */

#ifndef _IO_STDIO_H
#define _IO_STDIO_H

/* _G_config.h for the PS2 toolchain (mips64r5900el-scei-elf, newlib 1.9.0): what libio's gen-params
   would produce from newlib's headers with ee-gcc 2.96. Written for the GT4 decompilation
   (config/libs/libio.toml); `long` is 64-bit on the EE, so off_t, fpos_t and ssize_t are too
   (the game's _IO_FILE has its 8-byte _offset at 0x40 and the C++ vtable pointer at 0x50). */
#ifndef _G_config_h
#define _G_config_h
#define _G_LIB_VERSION "2.8.0"
#define _G_NAMES_HAVE_UNDERSCORE 0
#define _G_VTABLE_LABEL_HAS_LENGTH 1
#define _G_VTABLE_LABEL_PREFIX "__vt_"
#define _G_VTABLE_LABEL_PREFIX_ID __vt_
#define _G_HAVE_ST_BLKSIZE 1
typedef unsigned int _G_clock_t;
typedef short _G_dev_t;
typedef long _G_fpos_t;
typedef unsigned short _G_gid_t;
typedef unsigned short _G_ino_t;
typedef unsigned int _G_mode_t;
typedef unsigned short _G_nlink_t;
typedef long _G_off_t;
typedef int _G_pid_t;
typedef int _G_ptrdiff_t;
typedef unsigned int _G_sigset_t;
typedef unsigned int _G_size_t;
typedef long _G_time_t;
typedef unsigned short _G_uid_t;
typedef int _G_wchar_t;
typedef long _G_ssize_t;
typedef unsigned int _G_wint_t;
typedef char * _G_va_list;
#define _G_signal_return_type void
#define _G_sprintf_return_type int
typedef int _G_int8_t __attribute__((__mode__(__QI__)));
typedef unsigned int _G_uint8_t __attribute__((__mode__(__QI__)));
typedef int _G_int16_t __attribute__((__mode__(__HI__)));
typedef unsigned int _G_uint16_t __attribute__((__mode__(__HI__)));
typedef int _G_int32_t __attribute__((__mode__(__SI__)));
typedef unsigned int _G_uint32_t __attribute__((__mode__(__SI__)));
typedef int _G_int64_t __attribute__((__mode__(__DI__)));
typedef unsigned int _G_uint64_t __attribute__((__mode__(__DI__)));
#define _G_HAVE_INT64 1
#define _G_HAVE_BOOL 1
#define _G_BUFSIZ 1024
#define _G_FOPEN_MAX 20
#define _G_FILENAME_MAX 1024
#define _G_NULL 0
#define _G_USE_PROTOS
#define _G_ARGS(ARGLIST) ARGLIST
#define _G_HAVE_ATEXIT 1
#define _G_HAVE_SYS_RESOURCE 0
#define _G_HAVE_SYS_TIMES 1
#define _G_HAVE_SYS_SOCKET 0
#define _G_HAVE_SYS_CDEFS 0
#define _G_HAVE_SYS_WAIT 1
#define _G_HAVE_UNISTD 1
#define _G_HAVE_DIRENT 1
#define _G_HAVE_CURSES 0
#define _G_MATH_H_INLINES 0
#define _G_HAVE_BOOL 1
#define _G_HAVE_PRINTF_FP 0
#define _G_HAVE_LONG_DOUBLE_IO 0
#define _G_HAVE_IO_FILE_OPEN 1
#define _G_HAVE_IO_GETLINE_INFO 1
#define _G_HAVE_MMAP 0
#define _G_NEED_STDARG_H
#define _G_CLOG_CONFLICT 0
#endif

#define _IO_pos_t _G_fpos_t 
#define _IO_fpos_t _G_fpos_t
#define _IO_size_t _G_size_t
#define _IO_ssize_t _G_ssize_t
#define _IO_off_t _G_off_t
#define _IO_pid_t _G_pid_t
#define _IO_uid_t _G_uid_t
#define _IO_HAVE_SYS_WAIT _G_HAVE_SYS_WAIT
#define _IO_HAVE_ST_BLKSIZE _G_HAVE_ST_BLKSIZE
#define _IO_BUFSIZ _G_BUFSIZ
#define _IO_va_list _G_va_list
#if defined(_G_IO_IO_FILE_VERSION) && _G_IO_IO_FILE_VERSION == 0x20001
#define _IO_fpos64_t _G_fpos64_t
#define _IO_off64_t _G_off64_t
#endif

#ifdef _G_NEED_STDARG_H

# define __need___va_list
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

# ifdef __GNUC_VA_LIST
#  undef _IO_va_list
#  define _IO_va_list __gnuc_va_list
# endif 
#endif

#ifndef __P
# if _G_HAVE_SYS_CDEFS
#  include <sys/cdefs.h>
# else
#  ifdef __STDC__
#   define __P(p) p
#  else
#   define __P(p) ()
#  endif
# endif
#endif 

#ifndef __PMT
# ifdef __STDC__
#  define __PMT(p) p
# else
#  define __PMT(p) ()
# endif
#endif 

#ifndef _PARAMS
# define _PARAMS(protos) __P(protos)
#endif 

#ifndef __STDC__
# define const
#endif
#define _IO_UNIFIED_JUMPTABLES 1
#if !_G_HAVE_PRINTF_FP
# define _IO_USE_DTOA 1
#endif

#ifndef EOF
# define EOF (-1)
#endif
#ifndef NULL
# if defined __GNUG__ && \
    (__GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 8))
#  define NULL (__null)
# else
#  if !defined(__cplusplus)
#   define NULL ((void*)0)
#  else
#   define NULL (0)
#  endif
# endif
#endif

#define _IOS_INPUT	1
#define _IOS_OUTPUT	2
#define _IOS_ATEND	4
#define _IOS_APPEND	8
#define _IOS_TRUNC	16
#define _IOS_NOCREATE	32
#define _IOS_NOREPLACE	64
#define _IOS_BIN	128

#define _IO_MAGIC 0xFBAD0000 
#define _OLD_STDIO_MAGIC 0xFABC0000 
#define _IO_MAGIC_MASK 0xFFFF0000
#define _IO_USER_BUF 1 
#define _IO_UNBUFFERED 2
#define _IO_NO_READS 4 
#define _IO_NO_WRITES 8 
#define _IO_EOF_SEEN 0x10
#define _IO_ERR_SEEN 0x20
#define _IO_DELETE_DONT_CLOSE 0x40 
#define _IO_LINKED 0x80 
#define _IO_IN_BACKUP 0x100
#define _IO_LINE_BUF 0x200
#define _IO_TIED_PUT_GET 0x400 
#define _IO_CURRENTLY_PUTTING 0x800
#define _IO_IS_APPENDING 0x1000
#define _IO_IS_FILEBUF 0x2000
#define _IO_BAD_SEEN 0x4000
#define _IO_USER_LOCK 0x8000

#define _IO_SKIPWS 01
#define _IO_LEFT 02
#define _IO_RIGHT 04
#define _IO_INTERNAL 010
#define _IO_DEC 020
#define _IO_OCT 040
#define _IO_HEX 0100
#define _IO_SHOWBASE 0200
#define _IO_SHOWPOINT 0400
#define _IO_UPPERCASE 01000
#define _IO_SHOWPOS 02000
#define _IO_SCIENTIFIC 04000
#define _IO_FIXED 010000
#define _IO_UNITBUF 020000
#define _IO_STDIO 040000
#define _IO_DONT_CLOSE 0100000
#define _IO_BOOLALPHA 0200000

struct _IO_jump_t;  struct _IO_FILE;

#ifdef _IO_MTSAFE_IO
# if defined __GLIBC__ && __GLIBC__ >= 2
#  if __GLIBC_MINOR__ > 0
#   include <bits/stdio-lock.h>
#  else
#   include <stdio-lock.h>
#  endif
#  define _IO_LOCK_T _IO_lock_t *
# else

# endif
#else
# if defined(__GLIBC__) && __GLIBC__ >= 2
   typedef void _IO_lock_t;
#  define _IO_LOCK_T void *
# else
#  ifdef __linux__
    struct _IO_lock_t { void *ptr; short int field1; short int field2; };
#   define _IO_LOCK_T struct _IO_lock_t
#  else
    typedef void _IO_lock_t;
#  endif
# endif
#endif

struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;
  

  
  int _pos;
#if 0
    void set_streampos(streampos sp) { _spos = sp; }
    void set_offset(int offset) { _pos = offset; _spos = (streampos)(-2); }
  public:
    streammarker(streambuf *sb);
    ~streammarker();
    int saving() { return  _spos == -2; }
    int delta(streammarker&);
    int delta();
#endif
};

struct _IO_FILE {
  int _flags;		
#define _IO_file_flags _flags

  
  
  char* _IO_read_ptr;	
  char* _IO_read_end;	
  char* _IO_read_base;	
  char* _IO_write_base;	
  char* _IO_write_ptr;	
  char* _IO_write_end;	
  char* _IO_buf_base;	
  char* _IO_buf_end;	
  
  char *_IO_save_base; 
  char *_IO_backup_base;  
  char *_IO_save_end; 

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;
  int _blksize;
#ifdef _G_IO_IO_FILE_VERSION
  _IO_off_t _old_offset;
#else
  _IO_off_t _offset;
#endif

#define __HAVE_COLUMN 
  
  unsigned short _cur_column;
  char _unused;
  char _shortbuf[1];

  

#ifdef _IO_LOCK_T
  _IO_LOCK_T _lock;
#endif
#if defined(_G_IO_IO_FILE_VERSION) && _G_IO_IO_FILE_VERSION == 0x20001
  _IO_off64_t _offset;
  int _unused2[16];	
#endif
};

#ifndef __cplusplus
typedef struct _IO_FILE _IO_FILE;
#endif

#if defined(_G_IO_IO_FILE_VERSION) && _G_IO_IO_FILE_VERSION == 0x20001
#define _IO_stdin_ _IO_2_1_stdin_
#define _IO_stdout_ _IO_2_1_stdout_
#define _IO_stderr_ _IO_2_1_stderr_
#endif

struct _IO_FILE_plus;
extern struct _IO_FILE_plus _IO_stdin_, _IO_stdout_, _IO_stderr_;
#define _IO_stdin ((_IO_FILE*)(&_IO_stdin_))
#define _IO_stdout ((_IO_FILE*)(&_IO_stdout_))
#define _IO_stderr ((_IO_FILE*)(&_IO_stderr_))

typedef struct
{
  _IO_ssize_t (*read) __PMT ((struct _IO_FILE *, void *, _IO_ssize_t));
  _IO_ssize_t (*write) __PMT ((struct _IO_FILE *, const void *, _IO_ssize_t));
  _IO_off_t (*seek) __PMT ((struct _IO_FILE *, _IO_off_t, int));
  int (*close) __PMT ((struct _IO_FILE *));
} _IO_cookie_io_functions_t;

struct _IO_cookie_file
{
  struct _IO_FILE file;
  const void *vtable;
  void *cookie;
  _IO_cookie_io_functions_t io_functions;
};

#ifdef __cplusplus
extern "C" {
#endif

extern int func_005948D8 __P ((_IO_FILE *));
extern int func_005949A8 __P ((_IO_FILE *));
extern int func_00594700 __P ((_IO_FILE *, int));

#define _IO_getc_unlocked(_fp) \
       ((_fp)->_IO_read_ptr >= (_fp)->_IO_read_end ? func_005949A8 (_fp) \
	: *(unsigned char *) (_fp)->_IO_read_ptr++)
#define _IO_peekc_unlocked(_fp) \
       ((_fp)->_IO_read_ptr >= (_fp)->_IO_read_end \
	  && func_005948D8 (_fp) == EOF ? EOF \
	: *(unsigned char *) (_fp)->_IO_read_ptr)

#define _IO_putc_unlocked(_ch, _fp) \
   (((_fp)->_IO_write_ptr >= (_fp)->_IO_write_end) \
    ? func_00594700 (_fp, (unsigned char) (_ch)) \
    : (unsigned char) (*(_fp)->_IO_write_ptr++ = (_ch)))

#define _IO_feof_unlocked(__fp) (((__fp)->_flags & _IO_EOF_SEEN) != 0)
#define _IO_ferror_unlocked(__fp) (((__fp)->_flags & _IO_ERR_SEEN) != 0)

extern int _IO_getc __P ((_IO_FILE *__fp));
extern int _IO_putc __P ((int __c, _IO_FILE *__fp));
extern int _IO_feof __P ((_IO_FILE *__fp));
extern int _IO_ferror __P ((_IO_FILE *__fp));

extern int _IO_peekc_locked __P ((_IO_FILE *__fp));

#define _IO_PENDING_OUTPUT_COUNT(_fp)	\
	((_fp)->_IO_write_ptr - (_fp)->_IO_write_base)

extern void _IO_flockfile __P ((_IO_FILE *));
extern void _IO_funlockfile __P ((_IO_FILE *));
extern int _IO_ftrylockfile __P ((_IO_FILE *));

#ifdef _IO_MTSAFE_IO
# define _IO_peekc(_fp) _IO_peekc_locked (_fp)
#else
# define _IO_peekc(_fp) _IO_peekc_unlocked (_fp)
# define _IO_flockfile(_fp) 
# define _IO_funlockfile(_fp) 
# define _IO_ftrylockfile(_fp) 
# define _IO_cleanup_region_start(_fct, _fp) 
# define _IO_cleanup_region_end(_Doit) 
#endif 

extern int _IO_vfscanf __P ((_IO_FILE *, const char *, _IO_va_list, int *));
extern int _IO_vfprintf __P ((_IO_FILE *, const char *, _IO_va_list));
extern _IO_ssize_t _IO_padn __P ((_IO_FILE *, int, _IO_ssize_t));
extern _IO_size_t _IO_sgetn __P ((_IO_FILE *, void *, _IO_size_t));

#if defined(_G_IO_IO_FILE_VERSION) && _G_IO_IO_FILE_VERSION == 0x20001
extern _IO_off64_t _IO_seekoff __P ((_IO_FILE *, _IO_off64_t, int, int));
extern _IO_off64_t _IO_seekpos __P ((_IO_FILE *, _IO_off64_t, int));
#else
extern _IO_off_t _IO_seekoff __P ((_IO_FILE *, _IO_off_t, int, int));
extern _IO_off_t _IO_seekpos __P ((_IO_FILE *, _IO_off_t, int));
#endif

extern void _IO_free_backup_area __P ((_IO_FILE *));

#ifdef __cplusplus
}
#endif

#endif 

/* These emulate stdio functionality, but with a different name
   (_IO_ungetc instead of ungetc), and using _IO_FILE instead of FILE. */

#ifdef __cplusplus
extern "C" {
#endif

extern int _IO_fclose __P((_IO_FILE*));
extern _IO_FILE *_IO_fdopen __P((int, const char*));
extern int _IO_fflush __P((_IO_FILE*));
extern int _IO_fgetpos __P((_IO_FILE*, _IO_fpos_t*));
extern char* _IO_fgets __P((char*, int, _IO_FILE*));
extern _IO_FILE *_IO_fopen __P((const char*, const char*));
extern int _IO_fprintf __P((_IO_FILE*, const char*, ...));
extern int _IO_fputs __P((const char*, _IO_FILE*));
extern int _IO_fsetpos __P((_IO_FILE*, const _IO_fpos_t *));
extern long int _IO_ftell __P((_IO_FILE*));
extern _IO_size_t _IO_fread __P((void*, _IO_size_t, _IO_size_t, _IO_FILE*));
extern _IO_size_t _IO_fwrite __P((const void*,
				      _IO_size_t, _IO_size_t, _IO_FILE*));
extern char* _IO_gets __P((char*));
extern void _IO_perror __P((const char*));
extern int _IO_printf __P((const char*, ...));
extern int _IO_puts __P((const char*));
extern int _IO_scanf __P((const char*, ...));
extern void _IO_setbuffer __P((_IO_FILE *, char*, _IO_size_t));
extern int _IO_setvbuf __P((_IO_FILE*, char*, int, _IO_size_t));
extern int _IO_sscanf __P((const char*, const char*, ...));
extern int _IO_sprintf __P((char *, const char*, ...));
extern int _IO_ungetc __P((int, _IO_FILE*));
extern int _IO_vsscanf __P((const char *, const char *, _IO_va_list));
extern int _IO_vsprintf __P((char*, const char*, _IO_va_list));

struct obstack;
extern int _IO_obstack_vprintf __P ((struct obstack *, const char *,
                                    _IO_va_list));
extern int _IO_obstack_printf __P ((struct obstack *, const char *, ...));
#ifndef _IO_pos_BAD
# if defined(_G_IO_IO_FILE_VERSION) && _G_IO_IO_FILE_VERSION == 0x20001
#  define _IO_pos_BAD ((_IO_off64_t) -1)
# else
#  define _IO_pos_BAD ((_IO_off_t) -1)
# endif
#endif
#define _IO_clearerr(FP) ((FP)->_flags &= ~(_IO_ERR_SEEN|_IO_EOF_SEEN))
#define _IO_fseek(__fp, __offset, __whence) \
  (_IO_seekoff(__fp, __offset, __whence, _IOS_INPUT|_IOS_OUTPUT) == _IO_pos_BAD ? EOF : 0)
#define _IO_rewind(FILE) (void)_IO_seekoff(FILE, 0, 0, _IOS_INPUT|_IOS_OUTPUT)
#define _IO_vprintf(FORMAT, ARGS) _IO_vfprintf(_IO_stdout, FORMAT, ARGS)
#if _G_IO_IO_FILE_VERSION == 0x20001
#define _IO_freopen(FILENAME, MODE, FP) \
  (_IO_file_close_it(FP), _IO_file_fopen(FP, FILENAME, MODE, 0))
#else
#define _IO_freopen(FILENAME, MODE, FP) \
  (_IO_file_close_it(FP), _IO_file_fopen(FP, FILENAME, MODE))
#endif
#define _IO_fileno(FP) ((FP)->_fileno)
extern _IO_FILE* _IO_popen __P((const char*, const char*));
#define _IO_pclose _IO_fclose
#define _IO_setbuf(_FP, _BUF) _IO_setbuffer(_FP, _BUF, _IO_BUFSIZ)
#define _IO_setlinebuf(_FP) _IO_setvbuf(_FP, NULL, 1, 0)

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define _IO_seek_set 0
#define _IO_seek_cur 1
#define _IO_seek_end 2

#define _IO_JUMPS(THIS) ((struct _IO_FILE_plus *) (THIS))->vtable
#ifdef _G_USING_THUNKS
# define JUMP_FIELD(TYPE, NAME) TYPE NAME
# define JUMP0(FUNC, THIS) _IO_JUMPS(THIS)->FUNC (THIS)
# define JUMP1(FUNC, THIS, X1) _IO_JUMPS(THIS)->FUNC (THIS, X1)
# define JUMP2(FUNC, THIS, X1, X2) _IO_JUMPS(THIS)->FUNC (THIS, X1, X2)
# define JUMP3(FUNC, THIS, X1,X2,X3) _IO_JUMPS(THIS)->FUNC (THIS, X1,X2, X3)
# define JUMP_INIT(NAME, VALUE) VALUE
# define JUMP_INIT_DUMMY JUMP_INIT(dummy, 0), JUMP_INIT (dummy2, 0)
#else

# define JUMP_FIELD(TYPE, NAME) struct { short delta1, delta2; TYPE pfn; } NAME
# define JUMP0(FUNC, THIS) _IO_JUMPS(THIS)->FUNC.pfn (THIS)
# define JUMP1(FUNC, THIS, X1) _IO_JUMPS(THIS)->FUNC.pfn (THIS, X1)
# define JUMP2(FUNC, THIS, X1, X2) _IO_JUMPS(THIS)->FUNC.pfn (THIS, X1, X2)
# define JUMP3(FUNC, THIS, X1,X2,X3) _IO_JUMPS(THIS)->FUNC.pfn (THIS, X1,X2,X3)
# define JUMP_INIT(NAME, VALUE) {0, 0, VALUE}
# define JUMP_INIT_DUMMY JUMP_INIT(dummy, 0)
#endif

typedef void (*_IO_finish_t) __PMT ((_IO_FILE *, int)); 
#define _IO_FINISH(FP) JUMP1 (__finish, FP, 0)

typedef int (*_IO_overflow_t) __PMT ((_IO_FILE *, int));
#define _IO_OVERFLOW(FP, CH) JUMP1 (func_00594700, FP, CH)

typedef int (*_IO_underflow_t) __PMT ((_IO_FILE *));
#define _IO_UNDERFLOW(FP) JUMP0 (func_005948D8, FP)

#define _IO_UFLOW(FP) JUMP0 (func_005949A8, FP)

typedef int (*_IO_pbackfail_t) __PMT ((_IO_FILE *, int));
#define _IO_PBACKFAIL(FP, CH) JUMP1 (__pbackfail, FP, CH)

typedef _IO_size_t (*_IO_xsputn_t) __PMT ((_IO_FILE *FP, const void *DATA,
					 _IO_size_t N));
#define _IO_XSPUTN(FP, DATA, N) JUMP2 (__xsputn, FP, DATA, N)

typedef _IO_size_t (*_IO_xsgetn_t) __PMT ((_IO_FILE *FP, void *DATA,
					 _IO_size_t N));
#define _IO_XSGETN(FP, DATA, N) JUMP2 (__xsgetn, FP, DATA, N)

#if defined(_G_IO_IO_FILE_VERSION) && _G_IO_IO_FILE_VERSION == 0x20001
typedef _IO_off64_t (*_IO_seekoff_t) __PMT ((_IO_FILE *FP, _IO_off64_t OFF,
					  int DIR, int MODE));
#else
typedef _IO_off_t (*_IO_seekoff_t) __PMT ((_IO_FILE *FP, _IO_off_t OFF,
					  int DIR, int MODE));
#endif
#define _IO_SEEKOFF(FP, OFF, DIR, MODE) JUMP3 (__seekoff, FP, OFF, DIR, MODE)

#if defined(_G_IO_IO_FILE_VERSION) && _G_IO_IO_FILE_VERSION == 0x20001
typedef _IO_off64_t (*_IO_seekpos_t) __PMT ((_IO_FILE *, _IO_off64_t, int));
#else
typedef _IO_off_t (*_IO_seekpos_t) __PMT ((_IO_FILE *, _IO_off_t, int));
#endif
#define _IO_SEEKPOS(FP, POS, FLAGS) JUMP2 (__seekpos, FP, POS, FLAGS)

typedef _IO_FILE* (*_IO_setbuf_t) __PMT ((_IO_FILE *, char *, _IO_ssize_t));
#define _IO_SETBUF(FP, BUFFER, LENGTH) JUMP2 (__setbuf, FP, BUFFER, LENGTH)

typedef int (*_IO_sync_t) __PMT ((_IO_FILE *));
#define _IO_SYNC(FP) JUMP0 (__sync, FP)

typedef int (*_IO_doallocate_t) __PMT ((_IO_FILE *));
#define _IO_DOALLOCATE(FP) JUMP0 (__doallocate, FP)

typedef _IO_ssize_t (*_IO_read_t) __PMT ((_IO_FILE *, void *, _IO_ssize_t));
#define _IO_SYSREAD(FP, DATA, LEN) JUMP2 (__read, FP, DATA, LEN)

typedef _IO_ssize_t (*_IO_write_t) __PMT ((_IO_FILE *,const void *,_IO_ssize_t));
#define _IO_SYSWRITE(FP, DATA, LEN) JUMP2 (__write, FP, DATA, LEN)

#if defined(_G_IO_IO_FILE_VERSION) && _G_IO_IO_FILE_VERSION == 0x20001
typedef _IO_off64_t (*_IO_seek_t) __PMT ((_IO_FILE *, _IO_off64_t, int));
#else
typedef _IO_off_t (*_IO_seek_t) __PMT ((_IO_FILE *, _IO_off_t, int));
#endif
#define _IO_SYSSEEK(FP, OFFSET, MODE) JUMP2 (__seek, FP, OFFSET, MODE)

typedef int (*_IO_close_t) __PMT ((_IO_FILE *)); 
#define _IO_SYSCLOSE(FP) JUMP0 (__close, FP)

typedef int (*_IO_stat_t) __PMT ((_IO_FILE *, void *));
#define _IO_SYSSTAT(FP, BUF) JUMP1 (__stat, FP, BUF)

#if _G_IO_IO_FILE_VERSION == 0x20001

typedef int (*_IO_showmanyc_t) __PMT ((_IO_FILE *));
#define _IO_SHOWMANYC(FP) JUMP0 (__showmanyc, FP)

typedef void (*_IO_imbue_t) __PMT ((_IO_FILE *, void *));
#define _IO_IMBUE(FP, LOCALE) JUMP1 (__imbue, FP, LOCALE)
#endif

#define _IO_CHAR_TYPE char 
#define _IO_INT_TYPE int

struct _IO_jump_t
{
    JUMP_FIELD(_G_size_t, __dummy);
#ifdef _G_USING_THUNKS
    JUMP_FIELD(_G_size_t, __dummy2);
#endif
    JUMP_FIELD(_IO_finish_t, __finish);
    JUMP_FIELD(_IO_overflow_t, func_00594700);
    JUMP_FIELD(_IO_underflow_t, func_005948D8);
    JUMP_FIELD(_IO_underflow_t, func_005949A8);
    JUMP_FIELD(_IO_pbackfail_t, __pbackfail);
    
    JUMP_FIELD(_IO_xsputn_t, __xsputn);
    JUMP_FIELD(_IO_xsgetn_t, __xsgetn);
    JUMP_FIELD(_IO_seekoff_t, __seekoff);
    JUMP_FIELD(_IO_seekpos_t, __seekpos);
    JUMP_FIELD(_IO_setbuf_t, __setbuf);
    JUMP_FIELD(_IO_sync_t, __sync);
    JUMP_FIELD(_IO_doallocate_t, __doallocate);
    JUMP_FIELD(_IO_read_t, __read);
    JUMP_FIELD(_IO_write_t, __write);
    JUMP_FIELD(_IO_seek_t, __seek);
    JUMP_FIELD(_IO_close_t, __close);
    JUMP_FIELD(_IO_stat_t, __stat);
#if _G_IO_IO_FILE_VERSION == 0x20001
    JUMP_FIELD(_IO_showmanyc_t, __showmanyc);
    JUMP_FIELD(_IO_imbue_t, __imbue);
#endif
#if 0
    get_column;
    set_column;
#endif
};

struct _IO_FILE_plus
{
  _IO_FILE file;
  const struct _IO_jump_t *vtable;
};

#if defined(_G_IO_IO_FILE_VERSION) && _G_IO_IO_FILE_VERSION == 0x20001
extern _IO_off64_t _IO_seekoff __P ((_IO_FILE *, _IO_off64_t, int, int));
extern _IO_off64_t _IO_seekpos __P ((_IO_FILE *, _IO_off64_t, int));
#else
extern _IO_off_t _IO_seekoff __P ((_IO_FILE *, _IO_off_t, int, int));
extern _IO_off_t _IO_seekpos __P ((_IO_FILE *, _IO_off_t, int));
#endif

extern void _IO_switch_to_main_get_area __P ((_IO_FILE *));
extern void _IO_switch_to_backup_area __P ((_IO_FILE *));
extern int _IO_switch_to_get_mode __P ((_IO_FILE *));
extern void _IO_init __P ((_IO_FILE *, int));
extern int _IO_sputbackc __P ((_IO_FILE *, int));
extern int _IO_sungetc __P ((_IO_FILE *));
extern void _IO_un_link __P ((_IO_FILE *));
extern void _IO_link_in __P ((_IO_FILE *));
extern void _IO_doallocbuf __P ((_IO_FILE *));
extern void _IO_unsave_markers __P ((_IO_FILE *));
extern void _IO_setb __P ((_IO_FILE *, char *, char *, int));
extern unsigned _IO_adjust_column __P ((unsigned, const char *, int));
#define _IO_sputn(__fp, __s, __n) _IO_XSPUTN (__fp, __s, __n)

extern void _IO_init_marker __P ((struct _IO_marker *, _IO_FILE *));
extern void _IO_remove_marker __P ((struct _IO_marker *));
extern int _IO_marker_difference __P ((struct _IO_marker *,
				       struct _IO_marker *));
extern int _IO_marker_delta __P ((struct _IO_marker *));
extern int _IO_seekmark __P ((_IO_FILE *, struct _IO_marker *, int));

extern int _IO_default_underflow __P ((_IO_FILE *));
extern int _IO_default_uflow __P ((_IO_FILE *));
extern int _IO_default_doallocate __P ((_IO_FILE *));
extern void _IO_default_finish __P ((_IO_FILE *, int));
extern int _IO_default_pbackfail __P ((_IO_FILE *, int));
extern _IO_FILE* _IO_default_setbuf __P ((_IO_FILE *, char *, _IO_ssize_t));
extern _IO_size_t _IO_default_xsputn __P ((_IO_FILE *, const void *,
					   _IO_size_t));
extern _IO_size_t _IO_default_xsgetn __P ((_IO_FILE *, void *, _IO_size_t));
#if defined(_G_IO_IO_FILE_VERSION) && _G_IO_IO_FILE_VERSION == 0x20001
extern _IO_off64_t _IO_default_seekoff __P ((_IO_FILE *,
					      _IO_off64_t, int, int));
extern _IO_off64_t _IO_default_seekpos __P ((_IO_FILE *,
					      _IO_off64_t, int));
#else
extern _IO_off_t _IO_default_seekoff __P ((_IO_FILE *, _IO_off_t, int, int));
extern _IO_off_t _IO_default_seekpos __P ((_IO_FILE *, _IO_off_t, int));
#endif
extern _IO_ssize_t _IO_default_write __P ((_IO_FILE *, const void *,
					   _IO_ssize_t));
extern _IO_ssize_t _IO_default_read __P ((_IO_FILE *, void *, _IO_ssize_t));
extern int _IO_default_stat __P ((_IO_FILE *, void *));
#if defined(_G_IO_IO_FILE_VERSION) && _G_IO_IO_FILE_VERSION == 0x20001
extern _IO_off64_t _IO_default_seek __P ((_IO_FILE *, _IO_off64_t, int));
#else
extern _IO_off_t _IO_default_seek __P ((_IO_FILE *, _IO_off_t, int));
#endif
extern int _IO_default_sync __P ((_IO_FILE *));
#define _IO_default_close ((_IO_close_t) _IO_default_sync)

extern struct _IO_jump_t _IO_file_jumps;
extern struct _IO_jump_t _IO_streambuf_jumps;
extern struct _IO_jump_t _IO_proc_jumps;
extern struct _IO_jump_t _IO_str_jumps;
extern int _IO_do_write __P ((_IO_FILE *, const char *, _IO_size_t));
extern int _IO_flush_all __P ((void));
extern void _IO_cleanup __P ((void));
extern void _IO_flush_all_linebuffered __P ((void));

#define _IO_do_flush(_f) \
  _IO_do_write(_f, (_f)->_IO_write_base, \
	       (_f)->_IO_write_ptr-(_f)->_IO_write_base)
#define _IO_in_put_mode(_fp) ((_fp)->_flags & _IO_CURRENTLY_PUTTING)
#define _IO_mask_flags(fp, f, mask) \
       ((fp)->_flags = ((fp)->_flags & ~(mask)) | ((f) & (mask)))
#define _IO_setg(fp, eb, g, eg)  ((fp)->_IO_read_base = (eb),\
	(fp)->_IO_read_ptr = (g), (fp)->_IO_read_end = (eg))
#define _IO_setp(__fp, __p, __ep) \
       ((__fp)->_IO_write_base = (__fp)->_IO_write_ptr = __p, (__fp)->_IO_write_end = (__ep))
#define _IO_have_backup(fp) ((fp)->_IO_save_base != NULL)
#define _IO_in_backup(fp) ((fp)->_flags & _IO_IN_BACKUP)
#define _IO_have_markers(fp) ((fp)->_markers != NULL)
#define _IO_blen(fp) ((fp)->_IO_buf_end - (fp)->_IO_buf_base)

extern int _IO_file_doallocate __P ((_IO_FILE *));
extern _IO_FILE* _IO_file_setbuf __P ((_IO_FILE *, char *, _IO_ssize_t));
#if defined(_G_IO_IO_FILE_VERSION) && _G_IO_IO_FILE_VERSION == 0x20001
extern _IO_off64_t _IO_file_seekoff __P ((_IO_FILE *, _IO_off64_t, int, int));
extern _IO_off64_t _IO_file_seek __P ((_IO_FILE *, _IO_off64_t, int));
#else
extern _IO_off_t _IO_file_seekoff __P ((_IO_FILE *, _IO_off_t, int, int));
extern _IO_off_t _IO_file_seek __P ((_IO_FILE *, _IO_off_t, int));
#endif
extern _IO_size_t _IO_file_xsputn __P ((_IO_FILE *, const void *, _IO_size_t));
extern int _IO_file_stat __P ((_IO_FILE *, void *));
extern int _IO_file_close __P ((_IO_FILE *));
extern int _IO_file_underflow __P ((_IO_FILE *));
extern int _IO_file_overflow __P ((_IO_FILE *, int));
#define _IO_file_is_open(__fp) ((__fp)->_fileno >= 0)
extern void _IO_file_init __P ((_IO_FILE *));
extern _IO_FILE* _IO_file_attach __P ((_IO_FILE *, int));
extern _IO_FILE* _IO_file_open __P ((_IO_FILE *, const char *, int, int,
				     int, int));
#if _G_IO_IO_FILE_VERSION == 0x20001
extern _IO_FILE* _IO_file_fopen __P ((_IO_FILE *, const char *, const char *,
				      int));
#else
extern _IO_FILE* _IO_file_fopen __P ((_IO_FILE *, const char *, const char *));
#endif
extern _IO_ssize_t _IO_file_write __P ((_IO_FILE *, const void *,
					_IO_ssize_t));
extern _IO_ssize_t _IO_file_read __P ((_IO_FILE *, void *, _IO_ssize_t));
extern int _IO_file_sync __P ((_IO_FILE *));
extern int _IO_file_close_it __P ((_IO_FILE *));
extern void _IO_file_finish __P ((_IO_FILE *, int));

extern _IO_FILE* _IO_proc_open __P ((_IO_FILE *, const char *, const char *));
extern int _IO_proc_close __P ((_IO_FILE *));

extern int _IO_str_underflow __P ((_IO_FILE *));
extern int _IO_str_overflow __P ((_IO_FILE *, int));
extern int _IO_str_pbackfail __P ((_IO_FILE *, int));
#if defined(_G_IO_IO_FILE_VERSION) && _G_IO_IO_FILE_VERSION == 0x20001
extern _IO_off64_t _IO_str_seekoff __P ((_IO_FILE *, _IO_off64_t, int, int));
#else
extern _IO_off_t _IO_str_seekoff __P ((_IO_FILE *, _IO_off_t, int, int));
#endif
extern void _IO_str_finish __P ((_IO_FILE *, int));

extern void _IO_str_init_static __P ((_IO_FILE *, char *, int, char *));
extern void _IO_str_init_readonly __P ((_IO_FILE *, const char *, int));
extern _IO_ssize_t _IO_str_count __P ((_IO_FILE *));

extern int _IO_vasprintf __P ((char **result_ptr, __const char *format,
			       _IO_va_list args));
extern int _IO_vdprintf __P ((int d, __const char *format, _IO_va_list arg));
extern int _IO_vsnprintf __P ((char *string, _IO_size_t maxlen,
			       __const char *format, _IO_va_list args));

extern _IO_size_t _IO_getline __P ((_IO_FILE *,char *, _IO_size_t, int, int));
extern _IO_size_t _IO_getline_info __P ((_IO_FILE *,char *, _IO_size_t,
					 int, int, int *));
extern _IO_ssize_t _IO_getdelim __P ((char **, _IO_size_t *, int, _IO_FILE *));
extern double _IO_strtod __P ((const char *, char **));
extern char *_IO_dtoa __P ((double __d, int __mode, int __ndigits,
			    int *__decpt, int *__sign, char **__rve));
extern int _IO_outfloat __P ((double __value, _IO_FILE *__sb, int __type,
			      int __width, int __precision, int __flags,
			      int __sign_mode, int __fill));

extern _IO_FILE *_IO_list_all;
extern void (*_IO_cleanup_registration_needed) __PMT ((void));

#ifndef EOF
# define EOF (-1)
#endif
#ifndef NULL
# if defined __GNUG__ && \
    (__GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 8))
#  define NULL (__null)
# else
#  if !defined(__cplusplus)
#   define NULL ((void*)0)
#  else
#   define NULL (0)
#  endif
# endif
#endif

#if _G_HAVE_MMAP

#ifndef _UNISTD_H_
#define _UNISTD_H_

#endif /* _UNISTD_H_ */

#ifndef	_FCNTL_
#ifdef __cplusplus
extern "C" {
#endif
#define	_FCNTL_

#define	_FOPEN		(-1)	/* from sys/file.h, kernel use only */
#define	_FREAD		0x0001	
#define	_FWRITE		0x0002	
#define	_FAPPEND	0x0008	
#define	_FMARK		0x0010	
#define	_FDEFER		0x0020	
#define	_FASYNC		0x0040	
#define	_FSHLOCK	0x0080	
#define	_FEXLOCK	0x0100	
#define	_FCREAT		0x0200	
#define	_FTRUNC		0x0400	
#define	_FEXCL		0x0800	
#define	_FNBIO		0x1000	
#define	_FSYNC		0x2000	
#define	_FNONBLOCK	0x4000	
#define	_FNDELAY	_FNONBLOCK	
#define	_FNOCTTY	0x8000	

#define	O_ACCMODE	(O_RDONLY|O_WRONLY|O_RDWR)

#define	O_RDONLY	0		
#define	O_WRONLY	1		
#define	O_RDWR		2		
#define	O_APPEND	_FAPPEND
#define	O_CREAT		_FCREAT
#define	O_TRUNC		_FTRUNC
#define	O_EXCL		_FEXCL

#define	O_NONBLOCK	_FNONBLOCK
#define	O_NOCTTY	_FNOCTTY

#if defined (_WIN32) || defined (__CYGWIN__)
#define _FBINARY        0x10000
#define _FTEXT          0x20000
#define _FNOINHERIT	0x40000

#define O_BINARY	_FBINARY
#define O_TEXT		_FTEXT
#define O_NOINHERIT	_FNOINHERIT

#define _O_RDONLY	O_RDONLY
#define _O_WRONLY	O_WRONLY
#define _O_RDWR		O_RDWR
#define _O_APPEND	O_APPEND
#define _O_CREAT	O_CREAT
#define _O_TRUNC	O_TRUNC
#define _O_EXCL		O_EXCL
#define _O_TEXT		O_TEXT
#define _O_BINARY	O_BINARY
#define _O_RAW		O_BINARY
#define _O_NOINHERIT	O_NOINHERIT
#endif

#ifndef	_POSIX_SOURCE

#define	O_SYNC		_FSYNC

#define	FAPPEND		_FAPPEND
#define	FSYNC		_FSYNC
#define	FASYNC		_FASYNC
#define	FNBIO		_FNBIO
#define	FNONBIO		_FNONBLOCK	
#define	FNDELAY		_FNDELAY

#define	FREAD		_FREAD
#define	FWRITE		_FWRITE
#define	FMARK		_FMARK
#define	FDEFER		_FDEFER
#define	FSHLOCK		_FSHLOCK
#define	FEXLOCK		_FEXLOCK

#define	FOPEN		_FOPEN
#define	FCREAT		_FCREAT
#define	FTRUNC		_FTRUNC
#define	FEXCL		_FEXCL
#define	FNOCTTY		_FNOCTTY

#endif	

#define	FD_CLOEXEC	1	

#define	F_DUPFD		0	
#define	F_GETFD		1	
#define	F_SETFD		2	
#define	F_GETFL		3	
#define	F_SETFL		4	
#ifndef	_POSIX_SOURCE
#define	F_GETOWN 	5	
#define	F_SETOWN 	6	
#endif	
#define	F_GETLK  	7	
#define	F_SETLK  	8	
#define	F_SETLKW 	9	
#ifndef	_POSIX_SOURCE
#define	F_RGETLK 	10	
#define	F_RSETLK 	11	
#define	F_CNVT 		12	
#define	F_RSETLKW 	13	
#endif	

#define	F_RDLCK		1	
#define	F_WRLCK		2	
#define	F_UNLCK		3	
#ifndef	_POSIX_SOURCE
#define	F_UNLKSYS	4	
#endif	

struct flock {
	short	l_type;		
	short	l_whence;	
	long	l_start;	
	long	l_len;		
	short	l_pid;		
	short	l_xxx;		
};

#ifndef	_POSIX_SOURCE

struct eflock {
	short	l_type;		
	short	l_whence;	
	long	l_start;	
	long	l_len;		
	short	l_pid;		
	short	l_xxx;		
	long	l_rpid;		
	long	l_rsys;		
};
#endif	

#ifndef	_SYS_STAT_H
#define	_SYS_STAT_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __i386__
#ifdef __MSDOS__
#include "stat-dj.h"
#endif
#endif

/* dj's stat defines _STAT_H_ */
#ifndef _STAT_H_

struct	stat 
{
  dev_t		st_dev;
  ino_t		st_ino;
  mode_t	st_mode;
  nlink_t	st_nlink;
  uid_t		st_uid;
  gid_t		st_gid;
  dev_t		st_rdev;
  off_t		st_size;
  
#if defined(__svr4__) && !defined(__PPC__) && !defined(__sun__)
  time_t	st_atime;
  time_t	st_mtime;
  time_t	st_ctime;
#else
  time_t	st_atime;
  long		st_spare1;
  time_t	st_mtime;
  long		st_spare2;
  time_t	st_ctime;
  long		st_spare3;
  long		st_blksize;
  long		st_blocks;
  long	st_spare4[2];
#endif
};

#define	_IFMT		0170000	
#define		_IFDIR	0040000	
#define		_IFCHR	0020000	
#define		_IFBLK	0060000	
#define		_IFREG	0100000	
#define		_IFLNK	0120000	
#define		_IFSOCK	0140000	
#define		_IFIFO	0010000	

#define 	S_BLKSIZE  1024 

#define	S_ISUID		0004000	
#define	S_ISGID		0002000	
#ifndef	_POSIX_SOURCE
#define	S_ISVTX		0001000	
#define	S_IREAD		0000400	
#define	S_IWRITE 	0000200	
#define	S_IEXEC		0000100	

#define	S_ENFMT 	0002000	

#define	S_IFMT		_IFMT
#define	S_IFDIR		_IFDIR
#define	S_IFCHR		_IFCHR
#define	S_IFBLK		_IFBLK
#define	S_IFREG		_IFREG
#define	S_IFLNK		_IFLNK
#define	S_IFSOCK	_IFSOCK
#define	S_IFIFO		_IFIFO
#endif	

#ifdef _WIN32

#define _S_IFMT		_IFMT
#define _S_IFDIR	_IFDIR
#define _S_IFCHR	_IFCHR
#define _S_IFIFO	_IFIFO
#define _S_IFREG	_IFREG
#define _S_IREAD	0000400
#define _S_IWRITE	0000200
#define _S_IEXEC	0000100
#endif

#define	S_IRWXU 	0000700	
#define		S_IRUSR	0000400	
#define		S_IWUSR	0000200	
#define		S_IXUSR	0000100	
#define	S_IRWXG		0000070	
#define		S_IRGRP	0000040	
#define		S_IWGRP	0000020	
#define		S_IXGRP	0000010	
#define	S_IRWXO		0000007	
#define		S_IROTH	0000004	
#define		S_IWOTH	0000002	
#define		S_IXOTH	0000001	

#define	S_ISBLK(m)	(((m)&_IFMT) == _IFBLK)
#define	S_ISCHR(m)	(((m)&_IFMT) == _IFCHR)
#define	S_ISDIR(m)	(((m)&_IFMT) == _IFDIR)
#define	S_ISFIFO(m)	(((m)&_IFMT) == _IFIFO)
#define	S_ISREG(m)	(((m)&_IFMT) == _IFREG)
#define	S_ISLNK(m)	(((m)&_IFMT) == _IFLNK)
#define	S_ISSOCK(m)	(((m)&_IFMT) == _IFSOCK)

int	_EXFUN(chmod,( const char *__path, mode_t __mode ));
int     _EXFUN(fchmod,(int __fd, mode_t __mode));
int	_EXFUN(fstat,( int __fd, struct stat *__sbuf ));
int	_EXFUN(mkdir,( const char *_path, mode_t __mode ));
int	_EXFUN(mkfifo,( const char *__path, mode_t __mode ));
int	_EXFUN(stat,( const char *__path, struct stat *__sbuf ));
mode_t	_EXFUN(umask,( mode_t __mask ));

#if defined(__rtems__)
int	_EXFUN(mknod,( const char *_path, mode_t _mode, dev_t dev ));
int	_EXFUN(lstat,( const char *__path, struct stat *__buf ));
#endif

int	_EXFUN(_fstat,( int __fd, struct stat *__sbuf ));
int	_EXFUN(_stat,( const char *__path, struct stat *__sbuf ));

#ifdef __CYGWIN__
int	_EXFUN(lstat,( const char *__path, struct stat *__buf ));
#endif

#if defined(__rtems__)
int	_EXFUN(mknod,( const char *_path, mode_t _mode, dev_t dev ));
int	_EXFUN(lstat,( const char *_path, struct stat *_sbuf ));
#endif

#endif 
#ifdef __cplusplus
}
#endif
#endif 

extern int open _PARAMS ((const char *, int, ...));
extern int creat _PARAMS ((const char *, mode_t));
extern int fcntl _PARAMS ((int, int, ...));

extern int _open _PARAMS ((const char *, int, ...));
extern int _fcntl _PARAMS ((int, int, ...));

#ifdef __cplusplus
}
#endif
#endif	

# include <sys/mman.h>
/* This is a dummy <sys/param.h> file, not customized for any
   particular system.  If there is a param.h in libc/sys/SYSDIR/sys,
   it will override this one.  */

#ifndef _SYS_PARAM_H
# define _SYS_PARAM_H

# define HZ (60)
# define NOFILE	(60)
# define PATHSIZE (1024)

#ifdef __i386__
#define BIG_ENDIAN 4321
#define LITTLE_ENDIAN 1234
#define BYTE_ORDER LITTLE_ENDIAN
#endif

#endif

# if !defined(MAP_ANONYMOUS) && defined(MAP_ANON)
#  define MAP_ANONYMOUS MAP_ANON
# endif

# if !defined(MAP_ANONYMOUS) || !defined(EXEC_PAGESIZE)
#  undef _G_HAVE_MMAP
#  define _G_HAVE_MMAP 0
# endif

#endif 

#if _G_HAVE_MMAP

# ifdef _LIBC

#  define mmap __mmap
#  define munmap __munmap
# endif

# define ROUND_TO_PAGE(_S) \
       (((_S) + EXEC_PAGESIZE - 1) & ~(EXEC_PAGESIZE - 1))

# define FREE_BUF(_B, _S) \
       munmap ((_B), ROUND_TO_PAGE (_S))
# define ALLOC_BUF(_B, _S, _R) \
       do {								      \
	  (_B) = (char *) mmap (0, ROUND_TO_PAGE (_S),			      \
				PROT_READ | PROT_WRITE,			      \
				MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);	      \
	  if ((_B) == (char *) -1)					      \
	    return (_R);						      \
       } while (0)

#else 

# define FREE_BUF(_B, _S) \
       free(_B)
# define ALLOC_BUF(_B, _S, _R) \
       do {								      \
	  (_B) = (char*)malloc(_S);					      \
	  if ((_B) == NULL)						      \
	    return (_R);						      \
       } while (0)

#endif 

#ifndef OS_FSTAT
# define OS_FSTAT fstat
#endif
struct stat;
extern _IO_ssize_t _IO_read __P ((int, void *, _IO_size_t));
extern _IO_ssize_t _IO_write __P ((int, const void *, _IO_size_t));
extern _IO_off_t _IO_lseek __P ((int, _IO_off_t, int));
extern int _IO_close __P ((int));
extern int _IO_fstat __P ((int, struct stat *));
extern int _IO_vscanf __P ((const char *, _IO_va_list));

#ifndef _IO_pos_BAD
# if defined(_G_IO_IO_FILE_VERSION) && _G_IO_IO_FILE_VERSION == 0x20001
#  define _IO_pos_BAD ((_IO_off64_t) -1)
# else
#  define _IO_pos_BAD ((_IO_off_t) -1)
# endif
#endif

#ifndef _IO_pos_as_off
# if defined(_G_IO_IO_FILE_VERSION) && _G_IO_IO_FILE_VERSION == 0x20001
#  define _IO_pos_as_off(__pos) ((_IO_off64_t) (__pos))
# else
#  define _IO_pos_as_off(__pos) ((_IO_off_t) (__pos))
# endif
#endif

#ifndef _IO_pos_adjust
# define _IO_pos_adjust(__pos, __delta) ((__pos) += (__delta))
#endif

#ifndef _IO_pos_0
# if defined(_G_IO_IO_FILE_VERSION) && _G_IO_IO_FILE_VERSION == 0x20001
#  define _IO_pos_0 ((_IO_fpos64_t) 0)
# else
#  define _IO_pos_0 ((_IO_fpos_t) 0)
# endif
#endif

#ifdef __cplusplus
}
#endif

#ifdef _IO_MTSAFE_IO

# define FILEBUF_LITERAL(CHAIN, FLAGS, FD) \
       { _IO_MAGIC+_IO_LINKED+_IO_IS_FILEBUF+FLAGS, \
         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, CHAIN, FD, \
	   0, 0, 0, 0, { 0 }, &_IO_stdfile_##FD##_lock }
#else

# define FILEBUF_LITERAL(CHAIN, FLAGS, FD) \
       { _IO_MAGIC+_IO_LINKED+_IO_IS_FILEBUF+FLAGS, \
	   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, CHAIN, FD }
#endif

#ifdef __GNUC__
# if (!defined(__GXX_ABI_VERSION) || __GXX_ABI_VERSION < 100)
#  if _G_VTABLE_LABEL_HAS_LENGTH
#   define VTABLE_LABEL(NAME, CLASS, CNLENGTH) \
  extern char NAME[] asm (_G_VTABLE_LABEL_PREFIX #CNLENGTH #CLASS);
#  else
#   define VTABLE_LABEL(NAME, CLASS, CNLENGTH) \
  extern char NAME[] asm (_G_VTABLE_LABEL_PREFIX #CLASS);
#  endif
# else
#  define VTABLE_LABEL(NAME, CLASS, CNLENGTH) \
  extern char NAME[] asm ("_ZTV" #CNLENGTH #CLASS);
# endif 
#endif 

#if !defined(builtinbuf_vtable) && defined(__cplusplus)
# ifdef __GNUC__
VTABLE_LABEL(builtinbuf_vtable, builtinbuf, 10)
# else
#  if _G_VTABLE_LABEL_HAS_LENGTH
#   define builtinbuf_vtable _G_VTABLE_LABEL_PREFIX_ID##10builtinbuf
#  else
#   define builtinbuf_vtable _G_VTABLE_LABEL_PREFIX_ID##builtinbuf
#  endif
# endif
#endif 

#if defined(__STDC__) || defined(__cplusplus)
# define _IO_va_start(args, last) va_start(args, last)
#else
# define _IO_va_start(args, last) va_start(args)
#endif

extern struct _IO_fake_stdiobuf _IO_stdin_buf, _IO_stdout_buf, _IO_stderr_buf;

#if 1
# define COERCE_FILE(FILE) 
#else

# define COERCE_FILE(FILE) \
  (((FILE)->_IO_file_flags & _IO_MAGIC_MASK) == _OLD_MAGIC_MASK \
    && (FILE) = *(FILE**)&((int*)fp)[1])
#endif

#ifdef EINVAL
# define MAYBE_SET_EINVAL __set_errno (EINVAL)
#else
# define MAYBE_SET_EINVAL 
#endif

#ifdef IO_DEBUG
# define CHECK_FILE(FILE, RET) \
	if ((FILE) == NULL) { MAYBE_SET_EINVAL; return RET; } \
	else { COERCE_FILE(FILE); \
	       if (((FILE)->_IO_file_flags & _IO_MAGIC_MASK) != _IO_MAGIC) \
	  { MAYBE_SET_EINVAL; return RET; }}
#else
# define CHECK_FILE(FILE, RET) COERCE_FILE (FILE)
#endif

/*  This is part of libio/iostream, providing -*- C++ -*- input/output.
Copyright (C) 1993 Free Software Foundation

This file is part of the GNU IO Library.  This library is free
software; you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the
Free Software Foundation; either version 2, or (at your option)
any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this library; see the file COPYING.  If not, write to the Free
Software Foundation, 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

As a special exception, if you link this library with files
compiled with a GNU compiler to produce an executable, this does not cause
the resulting executable to be covered by the GNU General Public License.
This exception does not however invalidate any other reasons why
the executable file might be covered by the GNU General Public License. */

#ifndef _IOSTREAM_H
#ifdef __GNUG__
#pragma interface
#endif
#define _IOSTREAM_H

/* This is part of libio/iostream, providing -*- C++ -*- input/output.
Copyright (C) 1993 Free Software Foundation

This file is part of the GNU IO Library.  This library is free
software; you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the
Free Software Foundation; either version 2, or (at your option)
any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this library; see the file COPYING.  If not, write to the Free
Software Foundation, 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

As a special exception, if you link this library with files
compiled with a GNU compiler to produce an executable, this does not cause
the resulting executable to be covered by the GNU General Public License.
This exception does not however invalidate any other reasons why
the executable file might be covered by the GNU General Public License. */

#ifndef _STREAMBUF_H
#define _STREAMBUF_H
#ifdef __GNUG__
#pragma interface
#endif

 

#define _IO_NEW_STREAMS 

extern "C" {

}

#ifdef _G_NEED_STDARG_H

#endif
#ifndef _IO_va_list
#define _IO_va_list char *
#endif

#ifndef EOF
#define EOF (-1)
#endif
#ifndef NULL
#ifdef __GNUG__
#define NULL (__null)
#else
#define NULL (0)
#endif
#endif

#ifndef _IO_wchar_t
#if _G_IO_IO_FILE_VERSION == 0x20001
#define _IO_wchar_t _G_wchar_t
#else
#define _IO_wchar_t short
#endif
#endif

extern "C++" {
class istream; 
class ostream; class streambuf;

#undef open
#undef close

#if defined(_G_IO_IO_FILE_VERSION) && _G_IO_IO_FILE_VERSION == 0x20001
typedef _IO_off64_t streamoff;
typedef _IO_off64_t streampos;
#else
typedef _IO_off_t streamoff;
typedef _IO_off_t streampos;
#endif
typedef _IO_ssize_t streamsize;

typedef unsigned long __fmtflags;
typedef unsigned char __iostate;

struct _ios_fields
{ 
    streambuf *_strbuf;
    ostream* _tie;
    int _width;
    __fmtflags _flags;
    _IO_wchar_t _fill;
    __iostate _state;
    __iostate _exceptions;
    int _precision;

    void *_arrays; 
};

#define _IOS_GOOD	0
#define _IOS_EOF	1
#define _IOS_FAIL	2
#define _IOS_BAD	4

#define _IO_INPUT	1
#define _IO_OUTPUT	2
#define _IO_ATEND	4
#define _IO_APPEND	8
#define _IO_TRUNC	16
#define _IO_NOCREATE	32
#define _IO_NOREPLACE	64
#define _IO_BIN		128

#ifdef _STREAM_COMPAT
enum state_value {
    _good = _IOS_GOOD,
    _eof = _IOS_EOF,
    _fail = _IOS_FAIL,
    _bad = _IOS_BAD };
enum open_mode {
    input = _IO_INPUT,
    output = _IO_OUTPUT,
    atend = _IO_ATEND,
    append = _IO_APPEND };
#endif

class ios : public _ios_fields {
  ios& operator=(ios&);  
  ios (const ios&); 
  public:
    typedef __fmtflags fmtflags;
    typedef int iostate;
    typedef int openmode;
    typedef _IO_ssize_t streamsize;
    enum io_state {
	goodbit = _IOS_GOOD,
	eofbit = _IOS_EOF,
	failbit = _IOS_FAIL,
	badbit = _IOS_BAD };
    enum open_mode {
	in = _IO_INPUT,
	out = _IO_OUTPUT,
	ate = _IO_ATEND,
	app = _IO_APPEND,
	trunc = _IO_TRUNC,
	nocreate = _IO_NOCREATE,
	noreplace = _IO_NOREPLACE,
	bin = _IOS_BIN, 
	binary = _IOS_BIN };
    enum seek_dir { beg, cur, end};
    typedef enum seek_dir seekdir;
    
    enum { skipws=_IO_SKIPWS,
	   left=_IO_LEFT, right=_IO_RIGHT, internal=_IO_INTERNAL,
	   dec=_IO_DEC, oct=_IO_OCT, hex=_IO_HEX,
	   showbase=_IO_SHOWBASE, showpoint=_IO_SHOWPOINT,
	   uppercase=_IO_UPPERCASE, showpos=_IO_SHOWPOS,
	   scientific=_IO_SCIENTIFIC, fixed=_IO_FIXED,
	   unitbuf=_IO_UNITBUF, stdio=_IO_STDIO
#ifndef _IO_NEW_STREAMS
	   , dont_close=_IO_DONT_CLOSE 
#endif
	   };
    enum { 
	basefield=dec+oct+hex,
	floatfield = scientific+fixed,
	adjustfield = left+right+internal
    };

#ifdef _IO_THROW
    class failure : public xmsg {
	ios* _stream;
      public:
	failure(ios* stream) { _stream = stream; }
	failure(string cause, ios* stream) { _stream = stream; }
	ios* rdios() const { return _stream; }
    };
#endif

    ostream* tie() const { return _tie; }
    ostream* tie(ostream* val) { ostream* save=_tie; _tie=val; return save; }

    
    _IO_wchar_t fill() const { return _fill; }
    _IO_wchar_t fill(_IO_wchar_t newf)
	{_IO_wchar_t oldf = _fill; _fill = newf; return oldf;}
    fmtflags flags() const { return _flags; }
    fmtflags flags(fmtflags new_val) {
	fmtflags old_val = _flags; _flags = new_val; return old_val; }
    int precision() const { return _precision; }
    int precision(int newp) {
	unsigned short oldp = _precision; _precision = (unsigned short)newp;
	return oldp; }
    fmtflags setf(fmtflags val) {
	fmtflags oldbits = _flags;
	_flags |= val; return oldbits; }
    fmtflags setf(fmtflags val, fmtflags mask) {
	fmtflags oldbits = _flags;
	_flags = (_flags & ~mask) | (val & mask); return oldbits; }
    fmtflags unsetf(fmtflags mask) {
	fmtflags oldbits = _flags;
	_flags &= ~mask; return oldbits; }
    int width() const { return _width; }
    int width(int val) { int save = _width; _width = val; return save; }

#ifdef _IO_THROW
    void _throw_failure() const { throw new ios::failure(this); }
#else
    void _throw_failure() const { }
#endif
    void clear(iostate state = 0) {
	_state = _strbuf ? state : state|badbit;
	if (_state & _exceptions) _throw_failure(); }
    void set(iostate flag) { _state |= flag;
	if (_state & _exceptions) _throw_failure(); }
    void setstate(iostate flag) { _state |= flag; 
	if (_state & _exceptions) _throw_failure(); }
    int good() const { return _state == 0; }
    int eof() const { return _state & ios::eofbit; }
    int fail() const { return _state & (ios::badbit|ios::failbit); }
    int bad() const { return _state & ios::badbit; }
    iostate rdstate() const { return _state; }
    operator void*() const { return fail() ? (void*)0 : (void*)(-1); }
    int operator!() const { return fail(); }
    iostate exceptions() const { return _exceptions; }
    void exceptions(iostate enable) {
	_exceptions = enable;
	if (_state & _exceptions) _throw_failure(); }

    streambuf* rdbuf() const { return _strbuf; }
    streambuf* rdbuf(streambuf *_s) {
      streambuf *_old = _strbuf; _strbuf = _s; clear (); return _old; }

    static int sync_with_stdio(int on);
    static void sync_with_stdio() { sync_with_stdio(1); }
    static fmtflags bitalloc();
    static int xalloc();
    void*& pword(int);
    void* pword(int) const;
    long& iword(int);
    long iword(int) const;

#ifdef _STREAM_COMPAT
    void unset(state_value flag) { _state &= ~flag; }
    void close();
    int is_open();
    int readable();
    int writable();
#endif

    
    class Init {
    public:
      Init () { }
    };

  protected:
    inline ios(streambuf* sb = 0, ostream* tie_to = 0);
    inline virtual ~ios();
    inline void init(streambuf* sb, ostream* tie = 0);
};

#if __GNUG__==1
typedef int _seek_dir;
#else
typedef ios::seek_dir _seek_dir;
#endif

class streammarker : private _IO_marker {
    friend class streambuf;
    void set_offset(int offset) { _pos = offset; }
  public:
    streammarker(streambuf *sb);
    ~streammarker();
    int saving() { return  1; }
    int delta(streammarker&);
    int delta();
};

struct streambuf : public _IO_FILE { 
    friend class ios;
    friend class istream;
    friend class ostream;
    friend class streammarker;
    const void *&_vtable() { return *(const void**)((_IO_FILE*)this + 1); }
  protected:
    static streambuf* _list_all; 
    _IO_FILE*& xchain() { return _chain; }
    void _un_link();
    void _link_in();
    char* gptr() const
      { return _IO_file_flags & _IO_IN_BACKUP ? _IO_save_base : _IO_read_ptr; }
    char* pptr() const { return _IO_write_ptr; }
    char* egptr() const
      { return _IO_file_flags & _IO_IN_BACKUP ? _IO_save_end : _IO_read_end; }
    char* epptr() const { return _IO_write_end; }
    char* pbase() const { return _IO_write_base; }
    char* eback() const
      { return _IO_file_flags & _IO_IN_BACKUP ? _IO_save_base : _IO_read_base;}
    char* base() const { return _IO_buf_base; }
    char* ebuf() const { return _IO_buf_end; }
    int blen() const { return _IO_buf_end - _IO_buf_base; }
    void xput_char(char c) { *_IO_write_ptr++ = c; }
    int xflags() { return _IO_file_flags; }
    int xflags(int f) {int fl = _IO_file_flags; _IO_file_flags = f; return fl;}
    void xsetflags(int f) { _IO_file_flags |= f; }
    void xsetflags(int f, int mask)
      { _IO_file_flags = (_IO_file_flags & ~mask) | (f & mask); }
    void gbump(int n)
      { _IO_file_flags & _IO_IN_BACKUP ? (_IO_save_base+=n):(_IO_read_ptr+=n);}
    void pbump(int n) { _IO_write_ptr += n; }
    void setb(char* b, char* eb, int a=0);
    void setp(char* p, char* ep)
      { _IO_write_base=_IO_write_ptr=p; _IO_write_end=ep; }
    void setg(char* eb, char* g, char *eg) {
      if (_IO_file_flags & _IO_IN_BACKUP) _IO_free_backup_area(this); 
      _IO_read_base = eb; _IO_read_ptr = g; _IO_read_end = eg; }
    char *shortbuf() { return _shortbuf; }

    int in_backup() { return _flags & _IO_IN_BACKUP; }
    
    char *Gbase() { return in_backup() ? _IO_save_base : _IO_read_base; }
    
    char *eGptr() { return in_backup() ? _IO_save_end : _IO_read_end; }
    
    char *Bbase() { return in_backup() ? _IO_read_base : _IO_save_base; }
    char *Bptr() { return _IO_backup_base; }
    
    char *eBptr() { return in_backup() ? _IO_read_end : _IO_save_end; }
    char *Nbase() { return _IO_save_base; }
    char *eNptr() { return _IO_save_end; }
    int have_backup() { return _IO_save_base != NULL; }
    int have_markers() { return _markers != NULL; }
    void free_backup_area();
    void unsave_markers(); 
    int put_mode() { return _flags & _IO_CURRENTLY_PUTTING; }
    int switch_to_get_mode();
    
    streambuf(int flags=0);
  public:
    static int flush_all();
    static void flush_all_linebuffered(); 
    virtual ~streambuf();
    virtual int overflow(int c = EOF); 
    virtual int underflow(); 
    virtual int uflow(); 
    virtual int pbackfail(int c);

    virtual streamsize xsputn(const char* s, streamsize n);
    virtual streamsize xsgetn(char* s, streamsize n);
    virtual streampos seekoff(streamoff, _seek_dir, int mode=ios::in|ios::out);
    virtual streampos seekpos(streampos pos, int mode = ios::in|ios::out);

    streampos pubseekoff(streamoff o, _seek_dir d, int mode=ios::in|ios::out)
      { return _IO_seekoff (this, o, d, mode); }
    streampos pubseekpos(streampos pos, int mode = ios::in|ios::out)
      { return _IO_seekpos (this, pos, mode); }
    streampos sseekoff(streamoff, _seek_dir, int mode=ios::in|ios::out);
    streampos sseekpos(streampos pos, int mode = ios::in|ios::out);
    virtual streambuf* setbuf(char* p, int len);
    virtual int sync();
    virtual int doallocate();

    int seekmark(streammarker& mark, int delta = 0);
    int sputbackc(char c);
    int sungetc();
    int unbuffered() { return _flags & _IO_UNBUFFERED ? 1 : 0; }
    int linebuffered() { return _flags & _IO_LINE_BUF ? 1 : 0; }
    void unbuffered(int i)
	{ if (i) _flags |= _IO_UNBUFFERED; else _flags &= ~_IO_UNBUFFERED; }
    void linebuffered(int i)
	{ if (i) _flags |= _IO_LINE_BUF; else _flags &= ~_IO_LINE_BUF; }
    int allocate() { 
	if (base() || unbuffered()) return 0;
	else return doallocate(); }
    
    void allocbuf() { if (base() == NULL) doallocbuf(); }
    void doallocbuf();
    int in_avail() { return _IO_read_end - _IO_read_ptr; }
    int out_waiting() { return _IO_write_ptr - _IO_write_base; }
    streamsize sputn(const char* s, streamsize n) { return xsputn(s, n); }
    streamsize padn(char pad, streamsize n) { return _IO_padn(this, pad, n); }
    streamsize sgetn(char* s, streamsize n) { return _IO_sgetn(this, s, n); }
    int ignore(int);
    int get_column();
    int set_column(int);
    long sgetline(char* buf, _IO_size_t n, char delim, int putback_delim);
    int sputc(int c) { return _IO_putc(c, this); }
    int sbumpc() { return _IO_getc(this); }
    int sgetc() { return _IO_peekc(this); }
    int snextc() {
	if (_IO_read_ptr >= _IO_read_end && func_005948D8(this) == EOF)
	  return EOF;
	else return _IO_read_ptr++, sgetc(); }
    void stossc() { if (_IO_read_ptr < _IO_read_end) _IO_read_ptr++; }
    int vscan(char const *fmt0, _IO_va_list ap, ios* stream = NULL);
    int scan(char const *fmt0 ...);
    int vform(char const *fmt0, _IO_va_list ap);
    int form(char const *fmt0 ...);
#if 0 
    int column();  
    void column(int c);  
#endif
    virtual streamsize sys_read(char* buf, streamsize size);
    virtual streamsize sys_write(const char*, streamsize);
    virtual streampos sys_seek(streamoff, _seek_dir);
    virtual int sys_close();
    virtual int sys_stat(void*); 
#if _G_IO_IO_FILE_VERSION == 0x20001
    virtual int showmanyc();
    virtual void imbue(void *);
#endif
};

class filebuf : public streambuf {
  protected:
    void init();
  public:
    static const int openprot; 
    filebuf();
    filebuf(int fd);
    filebuf(int fd, char* p, int len);
#if !_IO_UNIFIED_JUMPTABLES
    static filebuf *__new();
#endif
    ~filebuf();
    filebuf* attach(int fd);
    filebuf* open(const char *filename, const char *mode);
    filebuf* open(const char *filename, ios::openmode mode, int prot = 0664);
    virtual int underflow();
    virtual int overflow(int c = EOF);
    int is_open() const { return _fileno >= 0; }
    int fd() const { return is_open() ? _fileno : EOF; }
    filebuf* close();
    virtual int doallocate();
    virtual streampos seekoff(streamoff, _seek_dir, int mode=ios::in|ios::out);
    virtual streambuf* setbuf(char* p, int len);
    streamsize xsputn(const char* s, streamsize n);
    streamsize xsgetn(char* s, streamsize n);
    virtual int sync();
  protected: 

    int is_reading() { return eback() != egptr(); }
    char* cur_ptr() { return is_reading() ?  gptr() : pptr(); }
    
    char* file_ptr() { return eGptr(); }
    
    virtual streamsize sys_read(char* buf, streamsize size);
    virtual streampos sys_seek(streamoff, _seek_dir);
    virtual streamsize sys_write(const char*, streamsize);
    virtual int sys_stat(void*); 
    virtual int sys_close();
#if 0
    virtual uflow;
    virtual showmany;
#endif
};

inline void ios::init(streambuf* sb, ostream* tie_to) {
		_state = sb ? ios::goodbit : ios::badbit; _exceptions=0;
		_strbuf=sb; _tie = tie_to; _width=0; _fill=' ';
#ifdef _IO_NEW_STREAMS
		_flags=ios::skipws|ios::dec;
#else
		_flags=ios::skipws|ios::dec|ios::dont_close;
#endif
		_precision=6; _arrays = 0; }

inline ios::ios(streambuf* sb, ostream* tie_to) { init(sb, tie_to); }

inline ios::~ios() {
#ifndef _IO_NEW_STREAMS
    if (!(_flags & (unsigned int)ios::dont_close)) delete rdbuf();
#endif
    
    
    operator delete[] (_arrays);
}
} 
#endif 

extern "C++" {
class istream; class ostream;
typedef ios& (*__manip)(ios&);
typedef istream& (*__imanip)(istream&);
typedef ostream& (*__omanip)(ostream&);

extern istream& ws(istream& ins);
extern ostream& flush(ostream& outs);
extern ostream& endl(ostream& outs);
extern ostream& ends(ostream& outs);

class ostream : virtual public ios
{
    
    void do_osfx();
  public:
    ostream() { }
    ostream(streambuf* sb, ostream* tied=NULL);
    int opfx() {
	if (!good()) return 0;
	else { if (_tie) _tie->flush(); _IO_flockfile(_strbuf); return 1;} }
    void osfx() { _IO_funlockfile(_strbuf);
		  if (flags() & (ios::unitbuf|ios::stdio))
		      do_osfx(); }
    ostream& flush();
    ostream& put(char c) { _strbuf->sputc(c); return *this; }
#ifdef _STREAM_COMPAT
    
    ostream& put(unsigned char c) { return put((char)c); }
    ostream& put(signed char c) { return put((char)c); }
#endif
    ostream& write(const char *s, streamsize n);
    ostream& write(const unsigned char *s, streamsize n)
      { return write((const char*)s, n);}
    ostream& write(const signed char *s, streamsize n)
      { return write((const char*)s, n);}
    ostream& write(const void *s, streamsize n)
      { return write((const char*)s, n);}
    ostream& seekp(streampos);
    ostream& seekp(streamoff, _seek_dir);
    streampos tellp();
    ostream& form(const char *format ...);
    ostream& vform(const char *format, _IO_va_list args);

    ostream& operator<<(char c);
    ostream& operator<<(unsigned char c) { return (*this) << (char)c; }
    ostream& operator<<(signed char c) { return (*this) << (char)c; }
    ostream& operator<<(const char *s);
    ostream& operator<<(const unsigned char *s)
	{ return (*this) << (const char*)s; }
    ostream& operator<<(const signed char *s)
	{ return (*this) << (const char*)s; }
    ostream& operator<<(const void *p);
    ostream& operator<<(int n);
    ostream& operator<<(unsigned int n);
    ostream& operator<<(long n);
    ostream& operator<<(unsigned long n);
#if defined(__GNUC__)
    __extension__ ostream& operator<<(long long n);
    __extension__ ostream& operator<<(unsigned long long n);
#endif
    ostream& operator<<(short n) {return operator<<((int)n);}
    ostream& operator<<(unsigned short n) {return operator<<((unsigned int)n);}
#if _G_HAVE_BOOL
    ostream& operator<<(bool b) { return operator<<((int)b); }
#endif
    ostream& operator<<(double n);
    ostream& operator<<(float n) { return operator<<((double)n); }
#if _G_HAVE_LONG_DOUBLE_IO
    ostream& operator<<(long double n);
#else
    ostream& operator<<(long double n) { return operator<<((double)n); }
#endif
    ostream& operator<<(__omanip func) { return (*func)(*this); }
    ostream& operator<<(__manip func) {(*func)(*this); return *this;}
    ostream& operator<<(streambuf*);
#ifdef _STREAM_COMPAT
    streambuf* ostreambuf() const { return _strbuf; }
#endif
};

class istream : virtual public ios
{
    
protected:
    _IO_size_t _gcount;

    int _skip_ws();
  public:
    istream(): _gcount (0) { }
    istream(streambuf* sb, ostream*tied=NULL);
    istream& get(char* ptr, int len, char delim = '\n');
    istream& get(unsigned char* ptr, int len, char delim = '\n')
	{ return get((char*)ptr, len, delim); }
    istream& get(char& c);
    istream& get(unsigned char& c) { return get((char&)c); }
    istream& getline(char* ptr, int len, char delim = '\n');
    istream& getline(unsigned char* ptr, int len, char delim = '\n')
	{ return getline((char*)ptr, len, delim); }
    istream& get(signed char& c)  { return get((char&)c); }
    istream& get(signed char* ptr, int len, char delim = '\n')
	{ return get((char*)ptr, len, delim); }
    istream& getline(signed char* ptr, int len, char delim = '\n')
	{ return getline((char*)ptr, len, delim); }
    istream& read(char *ptr, streamsize n);
    istream& read(unsigned char *ptr, streamsize n)
      { return read((char*)ptr, n); }
    istream& read(signed char *ptr, streamsize n)
      { return read((char*)ptr, n); }
    istream& read(void *ptr, streamsize n)
      { return read((char*)ptr, n); }
    istream& get(streambuf& sb, char delim = '\n');
    istream& gets(char **s, char delim = '\n');
    int ipfx(int need = 0) {
	if (!good()) { set(ios::failbit); return 0; }
	else {
	  _IO_flockfile(_strbuf);
	  if (_tie && (need == 0 || rdbuf()->in_avail() < need)) _tie->flush();
	  if (!need && (flags() & ios::skipws)) return _skip_ws();
	  else return 1;
	}
    }
    int ipfx0() { 
	if (!good()) { set(ios::failbit); return 0; }
	else {
	  _IO_flockfile(_strbuf);
	  if (_tie) _tie->flush();
	  if (flags() & ios::skipws) return _skip_ws();
	  else return 1;
	}
    }
    int ipfx1() { 
	if (!good()) { set(ios::failbit); return 0; }
	else {
	  _IO_flockfile(_strbuf);
	  if (_tie && rdbuf()->in_avail() == 0) _tie->flush();
	  return 1;
	}
    }
    void isfx() { _IO_funlockfile(_strbuf); }
    int get() { if (!ipfx1()) return EOF;
		else { int ch = _strbuf->sbumpc();
		       if (ch == EOF) set(ios::eofbit);
		       isfx();
		       return ch;
		     } }
    int peek();
    _IO_size_t gcount() { return _gcount; }
    istream& ignore(int n=1, int delim = EOF);
    int sync ();
    istream& seekg(streampos);
    istream& seekg(streamoff, _seek_dir);
    streampos tellg();
    istream& putback(char ch) {
	if (good() && _strbuf->sputbackc(ch) == EOF) clear(ios::badbit);
	return *this;}
    istream& unget() {
	if (good() && _strbuf->sungetc() == EOF) clear(ios::badbit);
	return *this;}
    istream& scan(const char *format ...);
    istream& vscan(const char *format, _IO_va_list args);
#ifdef _STREAM_COMPAT
    istream& unget(char ch) { return putback(ch); }
    int skip(int i);
    streambuf* istreambuf() const { return _strbuf; }
#endif

    istream& operator>>(char*);
    istream& operator>>(unsigned char* p) { return operator>>((char*)p); }
    istream& operator>>(signed char*p) { return operator>>((char*)p); }
    istream& operator>>(char& c);
    istream& operator>>(unsigned char& c) {return operator>>((char&)c);}
    istream& operator>>(signed char& c) {return operator>>((char&)c);}
    istream& operator>>(int&);
    istream& operator>>(long&);
#if defined(__GNUC__)
    __extension__ istream& operator>>(long long&);
    __extension__ istream& operator>>(unsigned long long&);
#endif
    istream& operator>>(short&);
    istream& operator>>(unsigned int&);
    istream& operator>>(unsigned long&);
    istream& operator>>(unsigned short&);
#if _G_HAVE_BOOL
    istream& operator>>(bool&);
#endif
    istream& operator>>(float&);
    istream& operator>>(double&);
    istream& operator>>(long double&);
    istream& operator>>( __manip func) {(*func)(*this); return *this;}
    istream& operator>>(__imanip func) { return (*func)(*this); }
    istream& operator>>(streambuf*);
};

class iostream : public istream, public ostream
{
  public:
    iostream() { }
    iostream(streambuf* sb, ostream*tied=NULL);
};

class _IO_istream_withassign : public istream {
public:
  _IO_istream_withassign& operator=(istream&);
  _IO_istream_withassign& operator=(_IO_istream_withassign& rhs)
    { return operator= (static_cast<istream&> (rhs)); }
};

class _IO_ostream_withassign : public ostream {
public:
  _IO_ostream_withassign& operator=(ostream&);
  _IO_ostream_withassign& operator=(_IO_ostream_withassign& rhs)
    { return operator= (static_cast<ostream&> (rhs)); }
};

extern _IO_istream_withassign cin;

extern _IO_ostream_withassign cout, cerr;

extern _IO_ostream_withassign clog
;

extern istream& lock(istream& ins);
extern istream& unlock(istream& ins);
extern ostream& lock(ostream& outs);
extern ostream& unlock(ostream& outs);

struct Iostream_init { } ;  

inline ios& dec(ios& i)
{ i.setf(ios::dec, ios::dec|ios::hex|ios::oct); return i; }
inline ios& hex(ios& i)
{ i.setf(ios::hex, ios::dec|ios::hex|ios::oct); return i; }
inline ios& oct(ios& i)
{ i.setf(ios::oct, ios::dec|ios::hex|ios::oct); return i; }
} 

#endif 

/*
 * string.h
 *
 * Definitions for memory and string functions.
 */

#ifndef _STRING_H_
#define	_STRING_H_

#ifdef __cplusplus
extern "C" {
#endif

#define __need_size_t

#ifndef NULL
#define NULL 0
#endif

_PTR 	 _EXFUN(memchr,(const _PTR, int, size_t));
int 	 _EXFUN(memcmp,(const _PTR, const _PTR, size_t));
_PTR 	 _EXFUN(memcpy,(_PTR, const _PTR, size_t));
_PTR	 _EXFUN(memmove,(_PTR, const _PTR, size_t));
_PTR	 _EXFUN(func_005A48D8,(_PTR, int, size_t));
char 	*_EXFUN(strcat,(char *, const char *));
char 	*_EXFUN(strchr,(const char *, int));
int	 _EXFUN(strcmp,(const char *, const char *));
int	 _EXFUN(strcoll,(const char *, const char *));
char 	*_EXFUN(strcpy,(char *, const char *));
size_t	 _EXFUN(strcspn,(const char *, const char *));
char 	*_EXFUN(strerror,(int));
size_t	 _EXFUN(strlen,(const char *));
char 	*_EXFUN(strncat,(char *, const char *, size_t));
int	 _EXFUN(strncmp,(const char *, const char *, size_t));
char 	*_EXFUN(strncpy,(char *, const char *, size_t));
char 	*_EXFUN(strpbrk,(const char *, const char *));
char 	*_EXFUN(strrchr,(const char *, int));
size_t	 _EXFUN(strspn,(const char *, const char *));
char 	*_EXFUN(strstr,(const char *, const char *));

#ifndef _REENT_ONLY
char 	*_EXFUN(strtok,(char *, const char *));
#endif

size_t	 _EXFUN(strxfrm,(char *, const char *, size_t));

#ifndef __STRICT_ANSI__
char 	*_EXFUN(strtok_r,(char *, const char *, char **));

int	 _EXFUN(bcmp,(const char *, const char *, size_t));
void	 _EXFUN(bcopy,(const char *, char *, size_t));
void	 _EXFUN(bzero,(char *, size_t));
int	 _EXFUN(ffs,(int));
char 	*_EXFUN(index,(const char *, int));
_PTR	 _EXFUN(memccpy,(_PTR, const _PTR, int, size_t));
char 	*_EXFUN(rindex,(const char *, int));
int	 _EXFUN(strcasecmp,(const char *, const char *));
char 	*_EXFUN(strdup,(const char *));
char 	*_EXFUN(_strdup_r,(struct _reent *, const char *));
int	 _EXFUN(strncasecmp,(const char *, const char *, size_t));
char 	*_EXFUN(strsep,(char **, const char *));
char	*_EXFUN(strlwr,(char *));
char	*_EXFUN(strupr,(char *));
#ifdef __CYGWIN__
#ifndef DEFS_H	
const char  *_EXFUN(strsignal, (int __signo));
#endif
int     _EXFUN(strtosigno, (const char *__name));
#endif

#ifndef strcmpi
#define strcmpi strcasecmp
#endif
#ifndef stricmp
#define stricmp strcasecmp
#endif
#ifndef strncmpi
#define strncmpi strncasecmp
#endif
#ifndef strnicmp
#define strnicmp strncasecmp
#endif

#endif 

#ifdef __cplusplus
}
#endif
#endif 

istream& istream::get(char* buf, int len, char delim)

{
  _gcount = 0;
  if (len <= 0)
    {
      set(ios::failbit);
      return *this;
    }
  if (ipfx1())
    {
      _IO_cleanup_region_start ((void (*) __P ((void *))) _IO_funlockfile,
				_strbuf);
      streambuf *sbuf = rdbuf();
      int ch;
      _gcount = _IO_getline_info(sbuf, buf, len - 1, delim, -1, &ch);
      if (_gcount == 0 && ch == EOF)
	set(ios::failbit|ios::eofbit);
      isfx();
      _IO_cleanup_region_end (0);
    }
  buf[_gcount] = '\0';
  return *this;
}

#define CHUNK_SIZE 512

char *_sb_readline (streambuf *sb, long& total, char terminator);


