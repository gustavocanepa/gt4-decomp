# Third-party code in this repository

Gran Turismo 4 links libraries whose source is public. Where the license allows redistribution,
their functions are matched from that source with `tools/libmatch.py` (see TOOLS.md) and committed
as the usual one-function-per-file sources under `src/`, each carrying the library's license header
and a first comment naming the library, the function and this file. Nothing else of those libraries
is copied: the library's own source tree stays outside the repository (`config/libs/NAME.toml` says
where it is expected) and the files under `src/` are derived from it mechanically.

| library | version | license | where in the executable | source |
|---|---|---|---|---|
| Expat (James Clark's XML parser) | 1.95.7 (2003-10-20) | MIT (see below) | 0x4ce828-0x4e6bd8, 323 functions, 98.5 KB | https://github.com/libexpat/libexpat/tree/R_1_95_7/expat |
| newlib (Cygnus/Red Hat embedded C library) | 1.9.0 (2001-03; the PS2 toolchain's libc) | BSD-style per file, COPYING.NEWLIB (see below) | libc and libm in the library region (string, stdio, stdlib, ctype, reent around 0x5a2000-0x5b7000) | https://sourceware.org/pub/newlib/newlib-1.9.0.tar.gz |
| SGI STL headers (libstdc++ v2 of gcc 2.96, snapshot 2000-10-03) | stl_*.h, type_traits.h | HP/SGI permissive notice (see below) | template instantiations in the library region (0x5d5000-0x60f000: rb-tree members of `map<basic_string, T>`) | gcc-20001003/libstdc++/stl/ |
| GNU libio (iostream/streambuf of libstdc++ v2) | 2.8.0, gcc snapshot 2000-10-03 | GPLv2 with the libio special exception (see below); marked `licence: libio` | 0x591248-0x59bee8 (its objects), 0x614068-0x616370 (out-of-line copies of its inline members and its classes' type_info functions) | gcc-20001003/libio/ |
| GCC runtime (libgcc.a of gcc 2.96: libgcc2.c, fp-bit.c, frame.c, the C++ runtime cp/tinfo*.cc, exception.cc, new*.cc) | gcc snapshot 2000-10-03 | GPL with the GCC runtime/linking exceptions (see below); marked `licence: gcc-runtime` | 0x5ba060-0x5c1ce0, 0x616370-0x616f24 | gcc-20001003/gcc/ |

## Expat 1.95.7

Copyright (c) 1998, 1999, 2000 Thai Open Source Software Center Ltd and Clark Cooper
Copyright (c) 2001, 2002, 2003 Expat maintainers.

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or
substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

The game's build of expat: `xmlparse.c`, `xmlrole.c`, `xmltok.c` (with `xmltok_impl.c` three times
and `xmltok_ns.c` twice) compiled as C with `-O2 -G0 -fno-strict-aliasing`, `XML_NS`, `XML_DTD`,
`XML_CONTEXT_BYTES=1024`, `BYTEORDER=1234`, `HAVE_MEMMOVE`, 32-bit `size_t`; the version string
`expat_1.95.7` is in the executable. 321 of its 323 functions compile to the original bytes from the
unmodified source (`python tools/libmatch.py scan expat`).

## newlib 1.9.0

The game's C library is newlib, built with `-O2 -G0 -fno-strict-aliasing` (ee-gcc 2.96, 64-bit
`long`): `config/libs/newlib.toml` describes the staged source tree and `python tools/libmatch.py
scan newlib` finds its functions. 32 compile to the original bytes so far (string, stdio, stdlib:
fclose/fflush/fread/fwrite/fseek/__sfvwrite, strcasecmp/strstr/strtok_r/strtoul, bsearch, atoi...);
the small `_r` wrappers look alike and scan to the same addresses, so ambiguous names were dropped
from build/libmatch/newlib.json by hand before `emit`. Each file of newlib carries its own notice; the emitted sources keep
the first comment of their file, and a file without a notice of its own is covered by section (9) of
newlib's COPYING.NEWLIB:

Copyright (c) 1994, 1997 Cygnus Solutions. All rights reserved.

Redistribution and use in source and binary forms are permitted provided that the above copyright
notice and this paragraph are duplicated in all such forms and that any documentation, advertising
materials, and other materials related to such distribution and use acknowledge that the software
was developed at Cygnus Solutions. Cygnus Solutions may not be used to endorse or promote products
derived from this software without specific prior written permission. THIS SOFTWARE IS PROVIDED
``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.

The other notices that occur in the matched files are the University of California's (BSD, the
stdio and stdlib files from 4.4BSD: "Copyright (c) 1990 The Regents of the University of
California. All rights reserved." with the redistribution paragraph above, naming the University of
California, Berkeley), David M. Gay's for dtoa/mprec/strtod ("Copyright (c) 1991 by AT&T", permission
to use, copy, modify and distribute provided the entire notice is included) and Sun's for libm
("Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved. Developed at SunPro, a Sun
Microsystems, Inc. business. Permission to use, copy, modify, and distribute this software is freely
granted, provided that this notice is preserved."). Files touched by DJ Delorie (`mktemp.c`,
`getenv*.c`, `putenv*.c`, `setenv*.c`), whose terms are in a separate `copying.dj`, are left out.

## Code that a build can leave out: `licence:` markers

The owner's decision for the GPL-derived libraries below: their sources stay in `src/` and count
toward the total, but each carries a `licence: NAME` line in its first 8 lines, and
`python tools/build.py --without NAME` (repeatable) leaves those sources out. The image still
matches: the functions they stood for then come from splat's assembly like any unmatched function,
and every name the other sources call them by resolves to the same address
(`config/libs/libio_symbols.txt`, read by tools/symbols.py, gives libio's mangled C++ and C names
their addresses).

## GNU libio 2.8.0 (gcc snapshot 2000-10-03)

The game's iostream library is libio as libstdc++ v2 shipped it in the gcc snapshot the compiler
was built from (`Libgcc_2_96_ee_001003_1`): libstdc++'s `iostream.list` (libio's IO_OBJECTS,
IOSTREAM_OBJECTS and OSPRIM_OBJECTS). `config/libs/libio.toml` describes the staged tree (libio's
top-level sources, newlib 1.9.0's headers as the PS2 toolchain configured it, and a hand-written
`_G_config.h` for the EE: 64-bit `long`, so `off_t`, `fpos_t` and `ssize_t` are 64-bit; the
game's `_IO_FILE` has its 8-byte `_offset` at 0x40 and the C++ vtable pointer at 0x50). Built like
Sony's other libraries, C as C and the `.cc` files as C++.

Where it is: its objects at 0x591248-0x59bee8 (iostream.cc, isgetline.cc, isscan.cc, sbscan.cc,
stdstreams.cc, streambuf.cc, genops.c, iovfscanf.c, iopadn.c, iogetline.c, ioseekoff.c,
ioseekpos.c, outfloat.c, ioungetc.c, iogetc.c, ioputc.c, filebuf.cc, ioassign.cc, filedoalloc.c,
floatconv.c, fileops.c, stdiostream.cc), and the out-of-line copies of its inline members with its
classes' type_info functions at 0x614068-0x616370 (grouped class by class: ostream, istream,
iostream, the `_withassign` streams, ios, streambuf, filebuf, `_ios_fields`, `_IO_FILE`, stdiobuf,
istdiostream, ostdiostream). `python tools/libmatch.py scan libio` finds 209 of its functions
byte for byte (23.3 KB); 83 sources in `src/` were written from the unmodified source by
`libmatch.py emit libio` (each starts with a comment naming libio, the function and its file, the
`licence: libio` line, then the file's own notice; floatconv.c's sources also keep David M. Gay's
notice, which that file carries for its dtoa code), 6 more need the nothrow stubs and wait in
`build/libmatch/pending/`. The other libio functions in `src/` (262 sources, written by agents from
the assembly) carry the same marker after a first comment naming the libio function; all 345 are
judged MATCH. `iovfscanf.c`'s and `outfloat.c`'s code descends from 4.4BSD (their own notice is the
FSF one above), and `ioputc.c` carries the GNU C Library's LGPL notice.

The libio notice (each file carries it, with its own years):

Copyright (C) 1993, 1995, 1997, 1998 Free Software Foundation, Inc. This file is part of the GNU IO
Library. This library is free software; you can redistribute it and/or modify it under the terms
of the GNU General Public License as published by the Free Software Foundation; either version 2,
or (at your option) any later version. [...]

As a special exception, if you link this library with files compiled with a GNU compiler to produce
an executable, this does not cause the resulting executable to be covered by the GNU General Public
License. This exception does not however invalidate any other reasons why the executable file might
be covered by the GNU General Public License.

Building without it: `python tools/build.py --without libio` leaves out every source whose first 8
lines hold `licence: libio`.

## GCC runtime (libgcc.a of the gcc snapshot 2000-10-03)

libgcc.a as the game's compiler built it, at 0x5ba060-0x5c1ce0: libgcc2.c (`__muldi3`,
`__udivdi3`, `__umoddi3`, `__negdi2`, `__cmpdi2`, `__ucmpdi2`, `__gcc_bcmp`, the exception-handling
support), config/fp-bit.c (soft float: `__addsf3`...), frame.c (`search_fdes`...) and the C++ runtime
that gcc 2.96 puts in libgcc.a (cp/tinfo.cc, tinfo2.cc, exception.cc, new*.cc: the type_info
classes, `__user_type_info::do_upcast`, `__is_pointer`, `__cplus_type_matcher`, terminate...), plus
the out-of-line copies of the runtime classes' members and their type_info functions at
0x616370-0x616f24 (type_info, the `__*_type_info` classes, exception, bad_alloc, bad_cast,
bad_typeid, bad_exception). The 123 sources of it in `src/` (written from the assembly) carry
`licence: gcc-runtime` after a first comment naming the function where it is known; all judged
MATCH. libgcc2.c, fp-bit.c and frame.c say:

In addition to the permissions in the GNU General Public License, the Free Software Foundation
gives you unlimited permission to link the compiled version of this file into combinations with
other programs, and to distribute those combinations without any restriction coming from the use of
this file. (The General Public License restrictions do apply in other respects; for example, they
cover modification of the file, and distribution when not linked into a combine executable.)

and the C++ runtime files (cp/tinfo.cc, tinfo2.cc, exception.cc, new*.cc):

As a special exception, you may use this file as part of a free software library without
restriction. Specifically, if other files instantiate templates or use macros or inline functions
from this file, or you compile this file and link it with other files to produce an executable,
this file does not by itself cause the resulting executable to be covered by the GNU General Public
License. This exception does not however invalidate any other reasons why the executable file
might be covered by the GNU General Public License.

Building without it: `python tools/build.py --without gcc-runtime` (both:
`--without libio --without gcc-runtime`).

## Identified but not redistributable (no code added)

Everything else that was identified in the "network stack" cluster (0x494578-0x54db98) and the
library region above it is proprietary; only the identification is recorded here, for whoever
holds a license to compare against:

- **SCE-RT / Medius (Sony Online)**, build `rtime-040920` (2004-09-20), 0x4f10d0-0x5455xx:
  Medius Client Library 2.8.3 (`MediusAccountLogin`, billing, `mbill_*`), MGCL 2.8.1 (Medius Game
  Communication Library), `dme` 2.8.140, `rt_msg_client` 2.8.2, `rt_comm` 2.8.2, `rt_udp` 2.8.22
  (`rt_p2p.c`), `rt_util` (`rt_list_buf.c`, `rt_ip.c`, `rt_parse.c` with a base64 alphabet,
  `rt_string.c`), `rt_upnp` 1.01.0008 (`rt_upnp.c`, `rt_upnp_xmlparse.c`: the UPnP/SOAP strings),
  `rt_crypt` 2.8.0 (`rt_crypt.c`, `LargeInt.c`, `SHA1.c`, `md5.c` with `ps2/*_platform.c`),
  `libnetb` 1.10.0007. The `$Header: /projects/rtime/CVS/...` strings at 0x6c22a8-0x6c74b8 name
  every file and revision. The MD5 and SHA-1 files are probably derived from the RSA reference
  (RFC 1321) and a public-domain SHA-1, but they sit inside SCE-RT's tree.
- **Polyphony's own libraries** (not third-party): `pdistd-http library` (0x4e6bd8-0x4ec078,
  HTTP/1.1 client with cookies and chunked transfer), `PDI_NETCNF`/`pdinetcnf.irx`
  (0x4ed0c0-0x4ee7c8), the kana/romaji tables at 0x4b8b10, `PDISTD::Inflator` and `Jpeg2Sys`
  (unit_0046A050: their own inflate and JPEG decoder, not zlib/libjpeg), `stdio_vprintf.cxx`
  (`PDISTD::PrintFormatTargetBase`).
- **Logitech `liblgdev` 1.11.036** (built 2005-01-27; steering wheels), proprietary.
- **Sony SDK** (`libcdvd`, `sceMc`, `libdbc`, `sceSif*`, `libkernl`'s `SceStdio*` layer) at
  0x5bf000 and up; most of it has the 16-byte register-save prologue of ee-gcc 2.9
  (knowledge/ee-gcc-2.96.md, "A second compiler"). The C library itself is newlib (above).

## SGI STL headers (include/stl/)

The 32 headers under `include/stl/` are copied verbatim from `libstdc++/stl/` of the gcc snapshot of
2000-10-03 (the compiler the game was built with ships them as its C++ library). They are not
matched functions themselves: `tools/stl.py` instantiates them (`/* compiler: ee-gcc2.96-stl */`
puts them on the include path) for the game's element types, and the instantiations go under
`src/` as usual. `include/shim/` holds the project's own stand-ins for the C headers they include.
Every header carries its notice:

Copyright (c) 1994 Hewlett-Packard Company; Copyright (c) 1996-1999 Silicon Graphics Computer
Systems, Inc.

Permission to use, copy, modify, distribute and sell this software and its documentation for any
purpose is hereby granted without fee, provided that the above copyright notice appear in all
copies and that both that copyright notice and this permission notice appear in supporting
documentation. Hewlett-Packard Company and Silicon Graphics make no representations about the
suitability of this software for any purpose. It is provided "as is" without express or implied
warranty.
