/* libio (GNU iostream library, gcc 2000-10-03 snapshot): an out-of-line (linkonce) copy of an inline function or member of libio's classes, from the block of such copies libio's objects brought (0x614068-0x616370, grouped by class around each class's type_info function).
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
typedef signed char s8;

struct Obj {
    char pad[0x14];
    s8 *unk14;
};

extern "C" void func_00615480(struct Obj *arg0, s8 arg1) {
    s8 **pp = &arg0->unk14;
    *(*pp)++ = arg1;
}
