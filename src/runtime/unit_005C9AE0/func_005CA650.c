typedef int s32; typedef unsigned int u32; typedef float f32;

struct Color {
    f32 r;
    f32 g;
    f32 b;
    f32 a;
};

struct Owner {
    s32 pad0;
    char *slots;
};

struct Color *func_002030A0(struct Color *);
void func_002030E8(void *, struct Color *);
void func_00203118(struct Color *, s32);

void func_005CA650(struct Owner *self, u32 i, f32 r, f32 g, f32 b, f32 a) {
    if (i < 4) {
        struct Color c;
        func_002030A0(&c);
        c.r = r;
        c.g = g;
        c.b = b;
        c.a = a;
        func_002030E8(self->slots + i * 0x54 + 0x38, &c);
        func_00203118(&c, 2);
    }
}
