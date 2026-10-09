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
- **Sony SDK** (`libcdvd`, `sceMc`, `libdbc`, `sceSif*`) and the C library at 0x5bf000 and up, whose
  `vfprintf` carries the BSD/newlib string "bug in vfprintf: bad base"; most of it has the 16-byte
  register-save prologue of ee-gcc 2.9 (knowledge/ee-gcc-2.96.md, "A second compiler"). If the
  libc is newlib (BSD-licensed), it is the next candidate for libmatch.py once a source can choose
  the 2.9 compiler.
