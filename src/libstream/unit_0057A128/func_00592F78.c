/* libio (GNU iostream library, gcc 2000-10-03 snapshot): ostream::seekp.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
typedef unsigned char u8;

struct File { void *fd; char pad[0x16]; u8 flags; };
int _IO_seekoff(void *, int, int, int);

struct File **func_00592F78(struct File **h, int a, int b) {
    if (_IO_seekoff((*h)->fd, a, b, 2) == -1)
        (*h)->flags |= 4;
    return h;
}
