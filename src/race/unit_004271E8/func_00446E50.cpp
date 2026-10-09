typedef long long s64;
typedef int s32;

struct Obj { char pad[0x100]; s64 unk100; } __attribute__((aligned(8)));

extern "C" s32 func_00446E50(Obj *arg0) {
    return ~arg0->unk100 == 0;
}
