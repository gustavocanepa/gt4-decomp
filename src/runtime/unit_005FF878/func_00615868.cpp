/* libio (GNU iostream library, gcc 2000-10-03 snapshot): streambuf::sgetc() out of line, the code of _IO_peekc_unlocked (byte-identical to peekc.c's func_00615868).
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
struct Buf { int flags; char *read_ptr; char *read_end; };
extern "C" int func_005948D8(Buf *b); /* underflow */

/* streambuf::sgetc: the next character without consuming it, or EOF. */
extern "C" int func_00615868(Buf *b)
{
    return b->read_ptr >= b->read_end && func_005948D8(b) == -1
        ? -1 : *(unsigned char *)b->read_ptr;
}
