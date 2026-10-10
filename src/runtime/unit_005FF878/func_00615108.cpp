/* libio (GNU iostream library, gcc 2000-10-03 snapshot): an out-of-line (linkonce) copy of an inline function or member of libio's classes, from the block of such copies libio's objects brought (0x614068-0x616370, grouped by class around each class's type_info function).
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
typedef long long s64;

struct __attribute__((aligned(8))) S00615108 {
    char pad[0x10];
    s64 unk10;
};

extern "C" void *func_00615108(struct S00615108 *arg0) {
    arg0->unk10 = (arg0->unk10 & ~0x70LL) | 0x40;
    return arg0;
}
