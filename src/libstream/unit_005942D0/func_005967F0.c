/* libio (GNU iostream library, gcc 2000-10-03 snapshot): func_005967F0.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
typedef int s32;

struct IOFile {
    s32 flags;
    s32 read_ptr;
    s32 read_end;
    s32 pad[6];
    s32 save_base;
    s32 pad2[10];
    void **jumps;
};

void func_005946B0();

void func_005967F0(struct IOFile *fp, long offset, s32 dir, s32 mode) {
    if (fp->save_base != 0) {
        if (dir == 1 && (fp->flags & 0x100)) {
            offset -= fp->read_end - fp->read_ptr;
        }
        func_005946B0();
    }
    ((void (*)(struct IOFile *, long, s32, s32))fp->jumps[0x11])(fp, offset, dir, mode);
}
