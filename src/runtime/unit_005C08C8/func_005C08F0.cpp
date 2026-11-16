/* gcc-rtti gcc snapshot 2000-10-03 (old C++ ABI): func_005C08F0() (func_005C08F0) from tinfo2.cc, placed at 0x005c08f0 by
 * tools/libmatch.py. Third-party code, see THIRD_PARTY.md for its license and origin.
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
// Methods for type_info for -*- C++ -*- Run Time Type Identification.
// Copyright (C) 1994, 1996, 1997, 1998, 1999, 2000 Free Software Foundation

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

#ifndef GT4_RUNTIME_STDDEF
#define GT4_RUNTIME_STDDEF
typedef unsigned int size_t;
typedef int ptrdiff_t;
#define NULL 0
#endif

// RTTI support internals for -*- C++ -*-
// Copyright (C) 1994, 1995, 1996, 1998, 1999, 2000 Free Software Foundation

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

#if !defined(__GXX_ABI_VERSION) || __GXX_ABI_VERSION < 100

struct __user_type_info : public std::type_info {
  __user_type_info (const char *n) : type_info (n) {}

  int upcast (const type_info &target, void *obj, void **res) const;

  void *dyncast (int boff,
                 const type_info &target, void *obj,
                 const type_info &subtype, void *subobj) const;

  static const type_info *const nonvirtual_base_type
      = static_cast <const type_info *> (0) + 1;

  enum sub_kind
  {
    unknown = 0,
    not_contained,

    contained_ambig,
    contained_mask = 4,
    contained_virtual_mask = 1,
    contained_public_mask = 2,
    contained_private = contained_mask,
    contained_public = contained_mask | contained_public_mask
  };

  static inline bool contained_p (sub_kind access_path)
  {
    return access_path >= contained_mask;
  }
  static inline bool contained_public_p (sub_kind access_path)
  {
    return access_path >= contained_public;
  }
  static inline bool contained_nonpublic_p (sub_kind access_path)
  {
    return (access_path & contained_public) == contained_mask;
  }
  static inline bool contained_nonvirtual_p (sub_kind access_path)
  {
    return (access_path & (contained_mask | contained_virtual_mask))
           == contained_mask;
  }
  static inline bool contained_virtual_p (sub_kind access_path)
  {
    return (access_path & (contained_mask | contained_virtual_mask))
           == (contained_mask | contained_virtual_mask);
  }

  struct upcast_result
  {
    void *target_obj;
    sub_kind whole2target;
    const type_info *base_type;

    public:
    upcast_result ()
      :target_obj (NULL), whole2target (unknown), base_type (NULL)
      {}
  };
  struct dyncast_result
  {
    void *target_obj;
    sub_kind whole2target;
    sub_kind whole2sub;
    sub_kind target2sub;

    public:
    dyncast_result ()
      :target_obj (NULL), whole2target (unknown),
       whole2sub (unknown), target2sub (unknown)
      {}
  };

  public:

  virtual bool do_upcast (sub_kind access_path,
                          const type_info &target, void *obj,
                          upcast_result &__restrict result) const;

  virtual bool do_dyncast (int boff, sub_kind access_path,
                           const type_info &target, void *obj,
                           const type_info &subtype, void *subptr,
                           dyncast_result &__restrict result) const;
  public:

  sub_kind find_public_subobj (int boff, const type_info &subtype,
                               void *objptr, void *subptr) const
  {
    if (boff >= 0)
      return ((char *)subptr - (char *)objptr) == boff
              ? contained_public : not_contained;
    if (boff == -2)
      return not_contained;
    return do_find_public_subobj (boff, subtype, objptr, subptr);
  }

  public:

  virtual sub_kind do_find_public_subobj (int boff, const type_info &subtype,
                                          void *objptr, void *subptr) const;
};

class __si_type_info : public __user_type_info {
  const __user_type_info &base;

public:
  __si_type_info (const char *n, const __user_type_info &b)
    : __user_type_info (n), base (b) { }

  private:
  virtual bool do_upcast (sub_kind access_path,
                          const type_info &target, void *obj,
                          upcast_result &__restrict result) const;
  virtual bool do_dyncast (int boff, sub_kind access_path,
                           const type_info &target, void *obj,
                           const type_info &subtype, void *subptr,
                           dyncast_result &__restrict result) const;
  virtual sub_kind do_find_public_subobj (int boff, const type_info &subtype,
                                          void *objptr, void *subptr) const;
};

#define BITS_PER_UNIT 8

#if BITS_PER_UNIT == 8
typedef int myint32 __attribute__ ((mode (SI)));
#elif BITS_PER_UNIT == 16
typedef int myint32 __attribute__ ((mode (HI)));
#elif BITS_PER_UNIT == 32
typedef int myint32 __attribute__ ((mode (QI)));
#endif

struct __class_type_info : public __user_type_info {
  enum access { PUBLIC = 1, PROTECTED = 2, PRIVATE = 3 };

  struct base_info {
    const __user_type_info *base;
    myint32 offset: 29;
    bool is_virtual: 1;
    enum access access: 2;
  };

  const base_info *base_list;
  size_t n_bases;

  __class_type_info (const char *name, const base_info *bl, size_t bn)
    : __user_type_info (name), base_list (bl), n_bases (bn) {}

  public:
  virtual bool do_upcast (sub_kind access_path,
                          const type_info &target, void *obj,
                          upcast_result &__restrict result) const;
  virtual bool do_dyncast (int boff, sub_kind access_path,
                           const type_info &target, void *obj,
                           const type_info &subtype, void *subptr,
                           dyncast_result &__restrict result) const;
  virtual sub_kind do_find_public_subobj (int boff, const type_info &subtype,
                                          void *objptr, void *subptr) const;
};
#else

/* new abi support -*- C++ -*-
   Copyright (C) 2000
   Free Software Foundation, Inc.
   Written by Nathan Sidwell, Codesourcery LLC, <nathan@codesourcery.com>  */

#ifndef __CXXABI_H
#define __CXXABI_H 1

#if defined(__cplusplus) && (!defined(__GXX_ABI_VERSION) || __GXX_ABI_VERSION < 100)

#error "Not targetting the new abi, supply -fnew-abi"
#endif

#ifdef __cplusplus

namespace __cxxabiv1
{

class __fundamental_type_info
  : public std::type_info
{
public:
  virtual ~__fundamental_type_info ();
public:
  explicit __fundamental_type_info (const char *__n)
    : std::type_info (__n)
    { }
};

class __array_type_info
  : public std::type_info
{

protected:
  virtual ~__array_type_info ();
public:
  explicit __array_type_info (const char *__n)
    : std::type_info (__n)
    { }
};

class __function_type_info
  : public std::type_info
{

public:
  virtual ~__function_type_info ();
public:
  explicit __function_type_info (const char *__n)
    : std::type_info (__n)
    { }

protected:
  virtual bool __is_function_p () const;
};

class __enum_type_info
  : public std::type_info
{

public:
  virtual ~__enum_type_info ();
public:
  explicit __enum_type_info (const char *__n)
    : std::type_info (__n)
    { }
};

class __pbase_type_info
  : public std::type_info
{

public:
  unsigned int __qualifier_flags;
  const std::type_info *__pointee;

public:
  virtual ~__pbase_type_info ();
public:
  explicit __pbase_type_info (const char *__n,
                                int __quals,
                                const std::type_info *__type)
    : std::type_info (__n), __qualifier_flags (__quals), __pointee (__type)
    { }

public:
  enum __qualifier_masks {
    __const_mask = 0x1,
    __volatile_mask = 0x2,
    __restrict_mask = 0x4,
    __incomplete_mask = 0x8,
    __incomplete_class_mask = 0x10
  };

protected:
  virtual bool __do_catch (const std::type_info *__thr_type,
                           void **__thr_obj,
                           unsigned __outer) const;
protected:
  inline virtual bool __pointer_catch (const __pbase_type_info *__thr_type,
                                       void **__thr_obj,
                                       unsigned __outer) const;
};

class __pointer_type_info
  : public __pbase_type_info
{

public:
  virtual ~__pointer_type_info ();
public:
  explicit __pointer_type_info (const char *__n,
                                int __quals,
                                const std::type_info *__type)
    : __pbase_type_info (__n, __quals, __type)
    { }

protected:
  virtual bool __is_pointer_p () const;

protected:
  virtual bool __pointer_catch (const __pbase_type_info *__thr_type,
                                void **__thr_obj,
                                unsigned __outer) const;
};

class __pointer_to_member_type_info
  : public __pbase_type_info
{

public:
  __class_type_info *__context_class;

public:
  virtual ~__pointer_to_member_type_info ();
public:
  explicit __pointer_to_member_type_info (const char *__n,
                                          int __quals,
                                          const std::type_info *__type,
                                          __class_type_info *__klass)
    : __pbase_type_info (__n, __quals, __type), __context_class (__klass)
    { }

protected:
  virtual bool __pointer_catch (const __pbase_type_info *__thr_type,
                                void **__thr_obj,
                                unsigned __outer) const;
};

class __class_type_info;

class __base_class_info
{

public:
  const __class_type_info *__base;
  long __offset_flags;

public:
  enum __offset_flags_masks {
    __virtual_mask = 0x1,
    __public_mask = 0x2,
    hwm_bit = 2,
    offset_shift = 8
  };

public:
  bool __is_virtual_p () const
    { return __offset_flags & __virtual_mask; }
  bool __is_public_p () const
    { return __offset_flags & __public_mask; }
  __PTRDIFF_TYPE__ __offset () const
    {

      return static_cast<__PTRDIFF_TYPE__> (__offset_flags) >> offset_shift;
    }
};

class __class_type_info
  : public std::type_info
{

public:
  virtual ~__class_type_info ();
public:
  explicit __class_type_info (const char *__n)
    : type_info (__n)
    { }

public:

  enum __sub_kind
  {
    __unknown = 0,
    __not_contained,

    __contained_ambig,

    __contained_virtual_mask = __base_class_info::__virtual_mask,
    __contained_public_mask = __base_class_info::__public_mask,
    __contained_mask = 1 << __base_class_info::hwm_bit,

    __contained_private = __contained_mask,
    __contained_public = __contained_mask | __contained_public_mask
  };

public:
  struct __upcast_result;
  struct __dyncast_result;

protected:
  virtual bool __do_upcast (const __class_type_info *__dst_type, void **__obj_ptr) const;

protected:
  virtual bool __do_catch (const type_info *__thr_type, void **__thr_obj,
                           unsigned __outer) const;

public:

  virtual bool __do_upcast (const __class_type_info *__dst,
                            const void *__obj,
                            __upcast_result &__restrict __result) const;

public:

  inline __sub_kind __find_public_src (__PTRDIFF_TYPE__ __src2dst,
                                       const void *__obj_ptr,
                                       const __class_type_info *__src_type,
                                       const void *__src_ptr) const;

public:

  virtual bool __do_dyncast (__PTRDIFF_TYPE__ __src2dst,
                             __sub_kind __access_path,
                             const __class_type_info *__dst_type,
                             const void *__obj_ptr,
                             const __class_type_info *__src_type,
                             const void *__src_ptr,
                             __dyncast_result &__result) const;
public:

  virtual __sub_kind __do_find_public_src (__PTRDIFF_TYPE__ __src2dst,
                                           const void *__obj_ptr,
                                           const __class_type_info *__src_type,
                                           const void *__src_ptr) const;
};

class __si_class_type_info
  : public __class_type_info
{

public:
  const __class_type_info *__base_type;

public:
  virtual ~__si_class_type_info ();
public:
  explicit __si_class_type_info (const char *__n,
                                 const __class_type_info *__base)
    : __class_type_info (__n), __base_type (__base)
    { }

protected:
  virtual bool __do_dyncast (__PTRDIFF_TYPE__ __src2dst,
                             __sub_kind __access_path,
                             const __class_type_info *__dst_type,
                             const void *__obj_ptr,
                             const __class_type_info *__src_type,
                             const void *__src_ptr,
                             __dyncast_result &__result) const;
  virtual __sub_kind __do_find_public_src (__PTRDIFF_TYPE__ __src2dst,
                                           const void *__obj_ptr,
                                           const __class_type_info *__src_type,
                                           const void *__sub_ptr) const;
  virtual bool __do_upcast (const __class_type_info *__dst,
                            const void *__obj,
                            __upcast_result &__restrict __result) const;
};

class __vmi_class_type_info : public __class_type_info {

public:
  unsigned int __flags;
  unsigned int __base_count;
  __base_class_info const __base_info[1];

public:
  virtual ~__vmi_class_type_info ();
public:
  explicit __vmi_class_type_info (const char *__n,
                                  int ___flags)
    : __class_type_info (__n), __flags (___flags), __base_count (0)
    { }

public:
  enum __flags_masks {
    __non_diamond_repeat_mask = 0x1,
    __diamond_shaped_mask = 0x2,
    non_public_base_mask = 0x4,
    public_base_mask = 0x8,

    __flags_unknown_mask = 0x10
  };

protected:
  virtual bool __do_dyncast (__PTRDIFF_TYPE__ __src2dst,
                             __sub_kind __access_path,
                             const __class_type_info *__dst_type,
                             const void *__obj_ptr,
                             const __class_type_info *__src_type,
                             const void *__src_ptr,
                             __dyncast_result &__result) const;
  virtual __sub_kind __do_find_public_src (__PTRDIFF_TYPE__ __src2dst,
                                           const void *__obj_ptr,
                                           const __class_type_info *__src_type,
                                           const void *__src_ptr) const;
  virtual bool __do_upcast (const __class_type_info *__dst,
                            const void *__obj,
                            __upcast_result &__restrict __result) const;
};

extern "C"
void *func_005C0F40 (const void *__src_ptr,
                      const __class_type_info *__src_type,
                      const __class_type_info *__dst_type,
                      __PTRDIFF_TYPE__ __src2dst);

extern "C"
void *__cxa_vec_new (__SIZE_TYPE__ __element_count,
                     __SIZE_TYPE__ __element_size,
                     __SIZE_TYPE__ __padding_size,
                     void (*__constructor) (void *),
                     void (*__destructor) (void *));

extern "C"
void *__cxa_vec_new2 (__SIZE_TYPE__ __element_count,
                      __SIZE_TYPE__ __element_size,
                      __SIZE_TYPE__ __padding_size,
                      void (*__constructor) (void *),
                      void (*__destructor) (void *),
                      void *(*__alloc) (__SIZE_TYPE__),
                      void (*__dealloc) (void *));

extern "C"
void *__cxa_vec_new3 (__SIZE_TYPE__ __element_count,
                      __SIZE_TYPE__ __element_size,
                      __SIZE_TYPE__ __padding_size,
                      void (*__constructor) (void *),
                      void (*__destructor) (void *),
                      void *(*__alloc) (__SIZE_TYPE__),
                      void (*__dealloc) (void *, __SIZE_TYPE__));

extern "C"
void __cxa_vec_ctor (void *__array_address,
                     __SIZE_TYPE__ __element_count,
                     __SIZE_TYPE__ __element_size,
                     void (*__constructor) (void *),
                     void (*__destructor) (void *));

extern "C"
void __cxa_vec_cctor (void *dest_array,
		      void *src_array,
		      __SIZE_TYPE__ element_count,
		      __SIZE_TYPE__ element_size,
		      void (*constructor) (void *, void *),
		      void (*destructor) (void *));

extern "C"
void __cxa_vec_dtor (void *__array_address,
                     __SIZE_TYPE__ __element_count,
                     __SIZE_TYPE__ __element_size,
                     void (*__destructor) (void *));

extern "C"
void __cxa_vec_delete (void *__array_address,
                       __SIZE_TYPE__ __element_size,
                       __SIZE_TYPE__ __padding_size,
                       void (*__destructor) (void *));

extern "C"
void __cxa_vec_delete2 (void *__array_address,
                        __SIZE_TYPE__ __element_size,
                        __SIZE_TYPE__ __padding_size,
                        void (*__destructor) (void *),
                        void (*__dealloc) (void *));

extern "C"
void __cxa_vec_delete3 (void *__array_address,
                        __SIZE_TYPE__ __element_size,
                        __SIZE_TYPE__ __padding_size,
                        void (*__destructor) (void *),
                        void (*__dealloc) (void *, __SIZE_TYPE__));

extern "C"
char *__cxa_demangle (const char *__mangled_name,
		      char *__output_buffer,
		      __SIZE_TYPE__ *__length,
		      int *__status);

}

namespace abi = __cxxabiv1;

#else
#endif

#endif

#endif

// The -*- C++ -*- dynamic memory management header.
// Copyright (C) 1994, 1996, 1997, 1998, 2000 Free Software Foundation

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

#ifndef __NEW__
#define __NEW__

#pragma interface "new"

extern "C++" {

namespace std {

  class bad_alloc : public exception {
  public:
    virtual const char* what() const throw() { return "bad_alloc"; }
  };

  struct nothrow_t {};
  extern const nothrow_t nothrow;
  typedef void (*new_handler)();
  new_handler set_new_handler (new_handler);

}

void *operator new (size_t) throw (std::bad_alloc);
void *operator new[] (size_t) throw (std::bad_alloc);
void operator delete (void *) throw();
void operator delete[] (void *) throw();
void *operator new (size_t, const std::nothrow_t&) throw();
void *operator new[] (size_t, const std::nothrow_t&) throw();
void operator delete (void *, const std::nothrow_t&) throw();
void operator delete[] (void *, const std::nothrow_t&) throw();

inline void *operator new(size_t, void *place) throw() { return place; }
inline void *operator new[](size_t, void *place) throw() { return place; }
}

#endif


using std::type_info;

#if !defined(__GXX_ABI_VERSION) || __GXX_ABI_VERSION < 100

struct __pointer_type_info : public type_info {
  const type_info& type;

  __pointer_type_info (const char *n, const type_info& ti)
    : type_info (n), type (ti) {}
};

struct __attr_type_info : public type_info {
  enum cv { NONE = 0, CONST = 1, VOLATILE = 2, CONSTVOL = 1 | 2 };

  const type_info& type;
  cv attr;

  __attr_type_info (const char *n, cv a, const type_info& t)
    : type_info (n), type (t), attr (a) {}
};

struct __builtin_type_info : public type_info {
  __builtin_type_info (const char *n): type_info (n) {}
};

struct __func_type_info : public type_info {
  __func_type_info (const char *n) : type_info (n) {}
};

struct __ptmf_type_info : public type_info {
  __ptmf_type_info (const char *n) : type_info (n) {}
};

struct __ptmd_type_info : public type_info {
  __ptmd_type_info (const char *n): type_info (n) {}
};

struct __array_type_info : public type_info {
  __array_type_info (const char *n): type_info (n) {}
};

#else

/* new abi support -*- C++ -*-
   Copyright (C) 2000
   Free Software Foundation, Inc.
   Written by Nathan Sidwell, Codesourcery LLC, <nathan@codesourcery.com>  */

#ifndef __CXXABI_H
#define __CXXABI_H 1

#if defined(__cplusplus) && (!defined(__GXX_ABI_VERSION) || __GXX_ABI_VERSION < 100)

#error "Not targetting the new abi, supply -fnew-abi"
#endif

#ifdef __cplusplus

namespace __cxxabiv1
{

class __fundamental_type_info
  : public std::type_info
{
public:
  virtual ~__fundamental_type_info ();
public:
  explicit __fundamental_type_info (const char *__n)
    : std::type_info (__n)
    { }
};

class __array_type_info
  : public std::type_info
{

protected:
  virtual ~__array_type_info ();
public:
  explicit __array_type_info (const char *__n)
    : std::type_info (__n)
    { }
};

class __function_type_info
  : public std::type_info
{

public:
  virtual ~__function_type_info ();
public:
  explicit __function_type_info (const char *__n)
    : std::type_info (__n)
    { }

protected:
  virtual bool __is_function_p () const;
};

class __enum_type_info
  : public std::type_info
{

public:
  virtual ~__enum_type_info ();
public:
  explicit __enum_type_info (const char *__n)
    : std::type_info (__n)
    { }
};

class __pbase_type_info
  : public std::type_info
{

public:
  unsigned int __qualifier_flags;
  const std::type_info *__pointee;

public:
  virtual ~__pbase_type_info ();
public:
  explicit __pbase_type_info (const char *__n,
                                int __quals,
                                const std::type_info *__type)
    : std::type_info (__n), __qualifier_flags (__quals), __pointee (__type)
    { }

public:
  enum __qualifier_masks {
    __const_mask = 0x1,
    __volatile_mask = 0x2,
    __restrict_mask = 0x4,
    __incomplete_mask = 0x8,
    __incomplete_class_mask = 0x10
  };

protected:
  virtual bool __do_catch (const std::type_info *__thr_type,
                           void **__thr_obj,
                           unsigned __outer) const;
protected:
  inline virtual bool __pointer_catch (const __pbase_type_info *__thr_type,
                                       void **__thr_obj,
                                       unsigned __outer) const;
};

class __pointer_type_info
  : public __pbase_type_info
{

public:
  virtual ~__pointer_type_info ();
public:
  explicit __pointer_type_info (const char *__n,
                                int __quals,
                                const std::type_info *__type)
    : __pbase_type_info (__n, __quals, __type)
    { }

protected:
  virtual bool __is_pointer_p () const;

protected:
  virtual bool __pointer_catch (const __pbase_type_info *__thr_type,
                                void **__thr_obj,
                                unsigned __outer) const;
};

class __pointer_to_member_type_info
  : public __pbase_type_info
{

public:
  __class_type_info *__context_class;

public:
  virtual ~__pointer_to_member_type_info ();
public:
  explicit __pointer_to_member_type_info (const char *__n,
                                          int __quals,
                                          const std::type_info *__type,
                                          __class_type_info *__klass)
    : __pbase_type_info (__n, __quals, __type), __context_class (__klass)
    { }

protected:
  virtual bool __pointer_catch (const __pbase_type_info *__thr_type,
                                void **__thr_obj,
                                unsigned __outer) const;
};

class __class_type_info;

class __base_class_info
{

public:
  const __class_type_info *__base;
  long __offset_flags;

public:
  enum __offset_flags_masks {
    __virtual_mask = 0x1,
    __public_mask = 0x2,
    hwm_bit = 2,
    offset_shift = 8
  };

public:
  bool __is_virtual_p () const
    { return __offset_flags & __virtual_mask; }
  bool __is_public_p () const
    { return __offset_flags & __public_mask; }
  __PTRDIFF_TYPE__ __offset () const
    {

      return static_cast<__PTRDIFF_TYPE__> (__offset_flags) >> offset_shift;
    }
};

class __class_type_info
  : public std::type_info
{

public:
  virtual ~__class_type_info ();
public:
  explicit __class_type_info (const char *__n)
    : type_info (__n)
    { }

public:

  enum __sub_kind
  {
    __unknown = 0,
    __not_contained,

    __contained_ambig,

    __contained_virtual_mask = __base_class_info::__virtual_mask,
    __contained_public_mask = __base_class_info::__public_mask,
    __contained_mask = 1 << __base_class_info::hwm_bit,

    __contained_private = __contained_mask,
    __contained_public = __contained_mask | __contained_public_mask
  };

public:
  struct __upcast_result;
  struct __dyncast_result;

protected:
  virtual bool __do_upcast (const __class_type_info *__dst_type, void **__obj_ptr) const;

protected:
  virtual bool __do_catch (const type_info *__thr_type, void **__thr_obj,
                           unsigned __outer) const;

public:

  virtual bool __do_upcast (const __class_type_info *__dst,
                            const void *__obj,
                            __upcast_result &__restrict __result) const;

public:

  inline __sub_kind __find_public_src (__PTRDIFF_TYPE__ __src2dst,
                                       const void *__obj_ptr,
                                       const __class_type_info *__src_type,
                                       const void *__src_ptr) const;

public:

  virtual bool __do_dyncast (__PTRDIFF_TYPE__ __src2dst,
                             __sub_kind __access_path,
                             const __class_type_info *__dst_type,
                             const void *__obj_ptr,
                             const __class_type_info *__src_type,
                             const void *__src_ptr,
                             __dyncast_result &__result) const;
public:

  virtual __sub_kind __do_find_public_src (__PTRDIFF_TYPE__ __src2dst,
                                           const void *__obj_ptr,
                                           const __class_type_info *__src_type,
                                           const void *__src_ptr) const;
};

class __si_class_type_info
  : public __class_type_info
{

public:
  const __class_type_info *__base_type;

public:
  virtual ~__si_class_type_info ();
public:
  explicit __si_class_type_info (const char *__n,
                                 const __class_type_info *__base)
    : __class_type_info (__n), __base_type (__base)
    { }

protected:
  virtual bool __do_dyncast (__PTRDIFF_TYPE__ __src2dst,
                             __sub_kind __access_path,
                             const __class_type_info *__dst_type,
                             const void *__obj_ptr,
                             const __class_type_info *__src_type,
                             const void *__src_ptr,
                             __dyncast_result &__result) const;
  virtual __sub_kind __do_find_public_src (__PTRDIFF_TYPE__ __src2dst,
                                           const void *__obj_ptr,
                                           const __class_type_info *__src_type,
                                           const void *__sub_ptr) const;
  virtual bool __do_upcast (const __class_type_info *__dst,
                            const void *__obj,
                            __upcast_result &__restrict __result) const;
};

class __vmi_class_type_info : public __class_type_info {

public:
  unsigned int __flags;
  unsigned int __base_count;
  __base_class_info const __base_info[1];

public:
  virtual ~__vmi_class_type_info ();
public:
  explicit __vmi_class_type_info (const char *__n,
                                  int ___flags)
    : __class_type_info (__n), __flags (___flags), __base_count (0)
    { }

public:
  enum __flags_masks {
    __non_diamond_repeat_mask = 0x1,
    __diamond_shaped_mask = 0x2,
    non_public_base_mask = 0x4,
    public_base_mask = 0x8,

    __flags_unknown_mask = 0x10
  };

protected:
  virtual bool __do_dyncast (__PTRDIFF_TYPE__ __src2dst,
                             __sub_kind __access_path,
                             const __class_type_info *__dst_type,
                             const void *__obj_ptr,
                             const __class_type_info *__src_type,
                             const void *__src_ptr,
                             __dyncast_result &__result) const;
  virtual __sub_kind __do_find_public_src (__PTRDIFF_TYPE__ __src2dst,
                                           const void *__obj_ptr,
                                           const __class_type_info *__src_type,
                                           const void *__src_ptr) const;
  virtual bool __do_upcast (const __class_type_info *__dst,
                            const void *__obj,
                            __upcast_result &__restrict __result) const;
};

extern "C"
void *func_005C0F40 (const void *__src_ptr,
                      const __class_type_info *__src_type,
                      const __class_type_info *__dst_type,
                      __PTRDIFF_TYPE__ __src2dst);

extern "C"
void *__cxa_vec_new (__SIZE_TYPE__ __element_count,
                     __SIZE_TYPE__ __element_size,
                     __SIZE_TYPE__ __padding_size,
                     void (*__constructor) (void *),
                     void (*__destructor) (void *));

extern "C"
void *__cxa_vec_new2 (__SIZE_TYPE__ __element_count,
                      __SIZE_TYPE__ __element_size,
                      __SIZE_TYPE__ __padding_size,
                      void (*__constructor) (void *),
                      void (*__destructor) (void *),
                      void *(*__alloc) (__SIZE_TYPE__),
                      void (*__dealloc) (void *));

extern "C"
void *__cxa_vec_new3 (__SIZE_TYPE__ __element_count,
                      __SIZE_TYPE__ __element_size,
                      __SIZE_TYPE__ __padding_size,
                      void (*__constructor) (void *),
                      void (*__destructor) (void *),
                      void *(*__alloc) (__SIZE_TYPE__),
                      void (*__dealloc) (void *, __SIZE_TYPE__));

extern "C"
void __cxa_vec_ctor (void *__array_address,
                     __SIZE_TYPE__ __element_count,
                     __SIZE_TYPE__ __element_size,
                     void (*__constructor) (void *),
                     void (*__destructor) (void *));

extern "C"
void __cxa_vec_cctor (void *dest_array,
		      void *src_array,
		      __SIZE_TYPE__ element_count,
		      __SIZE_TYPE__ element_size,
		      void (*constructor) (void *, void *),
		      void (*destructor) (void *));

extern "C"
void __cxa_vec_dtor (void *__array_address,
                     __SIZE_TYPE__ __element_count,
                     __SIZE_TYPE__ __element_size,
                     void (*__destructor) (void *));

extern "C"
void __cxa_vec_delete (void *__array_address,
                       __SIZE_TYPE__ __element_size,
                       __SIZE_TYPE__ __padding_size,
                       void (*__destructor) (void *));

extern "C"
void __cxa_vec_delete2 (void *__array_address,
                        __SIZE_TYPE__ __element_size,
                        __SIZE_TYPE__ __padding_size,
                        void (*__destructor) (void *),
                        void (*__dealloc) (void *));

extern "C"
void __cxa_vec_delete3 (void *__array_address,
                        __SIZE_TYPE__ __element_size,
                        __SIZE_TYPE__ __padding_size,
                        void (*__destructor) (void *),
                        void (*__dealloc) (void *, __SIZE_TYPE__));

extern "C"
char *__cxa_demangle (const char *__mangled_name,
		      char *__output_buffer,
		      __SIZE_TYPE__ *__length,
		      int *__status);

}

namespace abi = __cxxabiv1;

#else
#endif

#endif

#endif

#if defined(__GXX_ABI_VERSION) && __GXX_ABI_VERSION >= 100
namespace __cxxabiv1 {

using namespace std;

inline bool __pbase_type_info::
__pointer_catch (const __pbase_type_info *thrown_type,
                 void **thr_obj,
                 unsigned outer) const
{
  return __pointee->__do_catch (thrown_type->__pointee, thr_obj, outer + 2);
}

}
#endif

extern "C" int
func_005C08F0 (const void *catch_type_r, const void *throw_type_r,
			 void *objptr, void **valp)

{
  const type_info &catch_type = *(const type_info *)catch_type_r;
  const type_info &throw_type = *(const type_info *)throw_type_r;

  *valp = objptr;

#if !defined(__GXX_ABI_VERSION) || __GXX_ABI_VERSION < 100

  if (catch_type == throw_type)
    return 1;

  if (const __user_type_info *p
      = dynamic_cast <const __user_type_info *> (&throw_type))
    {
      return p->upcast (catch_type, objptr, valp);
    }
  else if (const __pointer_type_info *fr =
	   dynamic_cast <const __pointer_type_info *> (&throw_type))
    {
      const __pointer_type_info *to =
	   dynamic_cast <const __pointer_type_info *> (&catch_type);

      if (! to)
	return 0;

      const type_info *subfr = &fr->type, *subto = &to->type;
      __attr_type_info::cv cvfrom, cvto;

      if (const __attr_type_info *at
	  = dynamic_cast <const __attr_type_info *> (subfr))
	{
	  cvfrom = at->attr;
	  subfr = &at->type;
	}
      else
	cvfrom = __attr_type_info::NONE;

      if (const __attr_type_info *at
	  = dynamic_cast <const __attr_type_info *> (subto))
	{
	  cvto = at->attr;
	  subto = &at->type;
	}
      else
	cvto = __attr_type_info::NONE;

      if (((cvfrom & __attr_type_info::CONST)
	   > (cvto & __attr_type_info::CONST))
	  || ((cvfrom & __attr_type_info::VOLATILE)
	      > (cvto & __attr_type_info::VOLATILE)))
	return 0;

      if (*subto == *subfr)
	return 1;
      else if (*subto == typeid (void)
	       && dynamic_cast <const __func_type_info *> (subfr) == 0)
	return 1;
      else if (const __user_type_info *p
	       = dynamic_cast <const __user_type_info *> (subfr))
	return p->upcast (*subto, objptr, valp);
      else if (const __pointer_type_info *pfr
	       = dynamic_cast <const __pointer_type_info *> (subfr))
	{

	  const __pointer_type_info *pto
	    = dynamic_cast <const __pointer_type_info *> (subto);

	  if (! pto)
	    return 0;

	  bool constp = (cvto & __attr_type_info::CONST);
	  for (subto = &pto->type, subfr = &pfr->type; ;
	       subto = &pto->type, subfr = &pfr->type)
	    {
	      if (const __attr_type_info *at
		  = dynamic_cast <const __attr_type_info *> (subfr))
		{
		  cvfrom = at->attr;
		  subfr = &at->type;
		}
	      else
		cvfrom = __attr_type_info::NONE;

	      if (const __attr_type_info *at
		  = dynamic_cast <const __attr_type_info *> (subto))
		{
		  cvto = at->attr;
		  subto = &at->type;
		}
	      else
		cvto = __attr_type_info::NONE;

	      if (((cvfrom & __attr_type_info::CONST)
		   > (cvto & __attr_type_info::CONST))
		  || ((cvfrom & __attr_type_info::VOLATILE)
		      > (cvto & __attr_type_info::VOLATILE)))
		return 0;

	      if (! constp
		  && (((cvfrom & __attr_type_info::CONST)
		       < (cvto & __attr_type_info::CONST))
		      || ((cvfrom & __attr_type_info::VOLATILE)
			  < (cvto & __attr_type_info::VOLATILE))))
		return 0;

	      if (*subto == *subfr)
		return 1;

	      pto = dynamic_cast <const __pointer_type_info *> (subto);
	      pfr = dynamic_cast <const __pointer_type_info *> (subfr);
	      if (! pto || ! pfr)
		return 0;

	      if (! (cvto & __attr_type_info::CONST))
		constp = false;
	    }
	}
    }
#else

  return catch_type.__do_catch (&throw_type, valp, 1);
#endif
  return 0;
}

#if !defined(__GXX_ABI_VERSION) || __GXX_ABI_VERSION < 100

extern "C" void*
func_005C0E00 (const void *catch_type_r, const void *throw_type_r,
			 void *objptr);
#endif

bool
__is_pointer (void *p);

#if !defined(__GXX_ABI_VERSION) || __GXX_ABI_VERSION < 100

extern "C" void
func_005C0E78 (void *addr, const char *n, const type_info *ti);

extern "C" void
func_005C0E98 (void *addr, const char *n, int attrval, const type_info *ti);

extern "C" void
func_005C0EC0 (void *addr, const char *name);

extern "C" void
func_005C0EE0 (void *addr, const char *name);

extern "C" void
func_005C0F00 (void *addr, const char *name);

extern "C" void
func_005C0F20 (void *addr, const char *name);

extern "C" void *
func_005C0F40 (const type_info& (*from)(void), const type_info& (*to)(void),
		int require_public, void *address, const type_info & (*sub)(void), void *subptr);

extern "C" void *
__dynamic_cast_2 (const type_info& (*from)(void), const type_info& (*to)(void),
                  int boff,
		  void *address, const type_info & (*sub)(void), void *subptr);

#define BUILTIN(mangled)					\
unsigned char __ti##mangled [sizeof (__builtin_type_info)]	\
  __attribute__ ((aligned (__alignof__ (void *))));		\
extern "C" const type_info &__tf##mangled (void) {		\
  if ((*(void **) __ti##mangled) == 0)				\
    new (__ti##mangled) __builtin_type_info (#mangled);		\
  return *(type_info *)__ti##mangled;				\
}

extern unsigned char D_00659988 [sizeof (__builtin_type_info)]
  __attribute__ ((aligned (__alignof__ (void *))));

extern unsigned char D_00659990 [sizeof (__builtin_type_info)]
  __attribute__ ((aligned (__alignof__ (void *))));

extern unsigned char D_00659998 [sizeof (__builtin_type_info)]
  __attribute__ ((aligned (__alignof__ (void *))));

extern unsigned char D_006599A0 [sizeof (__builtin_type_info)]
  __attribute__ ((aligned (__alignof__ (void *))));

extern unsigned char D_006599A8 [sizeof (__builtin_type_info)]
  __attribute__ ((aligned (__alignof__ (void *))));

extern unsigned char D_006599B0 [sizeof (__builtin_type_info)]
  __attribute__ ((aligned (__alignof__ (void *))));

extern unsigned char D_006599B8 [sizeof (__builtin_type_info)]
  __attribute__ ((aligned (__alignof__ (void *))));

extern unsigned char D_006599C0 [sizeof (__builtin_type_info)]
  __attribute__ ((aligned (__alignof__ (void *))));

extern unsigned char D_006599C8 [sizeof (__builtin_type_info)]
  __attribute__ ((aligned (__alignof__ (void *))));

extern unsigned char D_006599D0 [sizeof (__builtin_type_info)]
  __attribute__ ((aligned (__alignof__ (void *))));

extern unsigned char D_006599D8 [sizeof (__builtin_type_info)]
  __attribute__ ((aligned (__alignof__ (void *))));

extern unsigned char D_006599E0 [sizeof (__builtin_type_info)]
  __attribute__ ((aligned (__alignof__ (void *))));

extern unsigned char D_006599E8 [sizeof (__builtin_type_info)]
  __attribute__ ((aligned (__alignof__ (void *))));

extern unsigned char D_006599F0 [sizeof (__builtin_type_info)]
  __attribute__ ((aligned (__alignof__ (void *))));

extern unsigned char D_006599F8 [sizeof (__builtin_type_info)]
  __attribute__ ((aligned (__alignof__ (void *))));

extern unsigned char D_00659A00 [sizeof (__builtin_type_info)]
  __attribute__ ((aligned (__alignof__ (void *))));

extern unsigned char D_00659A08 [sizeof (__builtin_type_info)]
  __attribute__ ((aligned (__alignof__ (void *))));

#endif
