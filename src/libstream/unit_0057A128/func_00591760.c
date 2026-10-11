/* libio (GNU iostream library, gcc 2000-10-03 snapshot): istream::seekg.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
typedef unsigned char u8;

struct File { void *fd; char pad[0x16]; u8 flags; };
int _IO_seekpos(void *, int, int);

struct File **func_00591760(struct File **h, int mode) {
    if (_IO_seekpos((*h)->fd, mode, 1) == -1)
        (*h)->flags |= 4;
    return h;
}
