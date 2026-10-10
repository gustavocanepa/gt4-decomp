typedef int s32;
typedef unsigned char u8;

struct Obj {
    char pad0[0x18];
    u8 value;
};

extern "C" s32 func_00445808(Obj *self);

extern "C" s32 func_00445880(Obj *self, s32 v) {
    if (v >= func_00445808(self)) {
        return 0;
    }
    self->value = v;
    return 1;
}
