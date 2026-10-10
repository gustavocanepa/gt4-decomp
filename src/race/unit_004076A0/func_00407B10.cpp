typedef int s32;
typedef unsigned int u32;

struct Flags_00407B10 {
    char pad0[0x40];
    u32 bits[1];
    bool test(s32 i) const { return (bits[i >> 5] & (1 << (i & 0x1F))) != 0; }
};

struct Obj_00407B10 {
    char pad0[0x54];
    Flags_00407B10 flags;
};

extern "C" s32 func_00407B10(Obj_00407B10 *o, s32 n) {
    s32 count = 0;
    s32 i;
    for (i = 0; i < 13; i++) {
        if (o->flags.test(i)) {
            count++;
        }
        if (n < count) {
            return i;
        }
    }
    return -1;
}
