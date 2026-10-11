/* libio (GNU iostream library, gcc 2000-10-03 snapshot): _IO_file_close.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
typedef int s32;

struct Obj {
    char pad0[0x38];
    s32 unk38;
};

extern "C" s32 close(s32 arg0);

extern "C" s32 _IO_file_close(Obj *arg0) {
    return close(arg0->unk38);
}
