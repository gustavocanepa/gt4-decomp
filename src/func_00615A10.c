/* libio (GNU iostream library, gcc 2000-10-03 snapshot): an out-of-line (linkonce) copy of an inline function or member of libio's classes, from the block of such copies libio's objects brought (0x614068-0x616370, grouped by class around each class's type_info function).
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
struct File {
    int flags;
    char *read_base;
    char *read_end;
    char *read_ptr;
    int f10;
    char *buf_base;
    char pad18[0x24 - 0x18];
    char *save_ptr;
    int f28;
    char *save_end;
};

char *func_00615A10(struct File *f) {
    char *ptr = (f->flags & 0x100) ? f->save_ptr : f->read_ptr;
    char *end = (f->flags & 0x100) ? f->save_end : f->read_end;
    if (ptr != end) {
        if (f->flags & 0x100) {
            return f->save_ptr;
        }
        return f->read_base;
    }
    return f->buf_base;
}
