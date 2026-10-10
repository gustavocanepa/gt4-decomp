/* libio (GNU iostream library, gcc 2000-10-03 snapshot): ostream::seekp.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
struct Buf {
    int fd;
    char pad4[0x1A - 4];
    unsigned char state;
};

struct Stream {
    struct Buf *buf;
};

extern int func_00596890(int fd, int off, int whence);

struct Stream *func_00592F28(struct Stream *s, int off) {
    if (func_00596890(s->buf->fd, off, 2) == -1) {
        s->buf->state |= 4;
    }
    return s;
}
