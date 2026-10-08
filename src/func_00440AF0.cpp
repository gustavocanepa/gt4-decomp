typedef int s32;
typedef long long s64;

struct __attribute__((aligned(8))) Elem00440AF0 {
    char pad[0x108];
    s64 unk108;
};

struct Obj00440AF0 {
    char pad[0x490];
    s32 unk490;
};

extern "C" s64 func_00440AF0(Obj00440AF0 *arg0) {
    return ((Elem00440AF0 *)((char *)arg0 + arg0->unk490 * 0x178))->unk108;
}
