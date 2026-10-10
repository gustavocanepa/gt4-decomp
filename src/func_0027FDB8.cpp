typedef unsigned short u16;
typedef int s32;
typedef float f32;

struct Event {
    char pad0[0x20];
    u16 button;
    u16 pad22;
    s32 state;
    f32 x;
    f32 y;
};

extern "C" void mWindowEvent__virtual_50(Event *self);
extern char D_0069A990[]; /* "button %d state %04x port %d x %d y %d " */
extern "C" void func_005D4AD8(const char *fmt, ...);

extern "C" s32 func_0027FDB8(Event *self) {
    mWindowEvent__virtual_50(self);
    func_005D4AD8(D_0069A990, self->button, self->state,
                  self->state & 0xF, (s32)self->x, (s32)self->y);
    return 0;
}
