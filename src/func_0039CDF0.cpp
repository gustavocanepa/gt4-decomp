typedef int s32;
typedef signed char s8;
typedef unsigned int u32;

struct Obj {
    char pad[0x2E];
    s8 state;
    char pad2f;
    u32 flags;
};

extern "C" void func_0039CDF0(Obj *self, s32 state) {
    if (self->state != state) {
        self->state = state;
        self->flags = (((self->flags & 0xFFFF00FF) | 0x100) & 0xFF00FFFF) | 0x10000;
    }
}
