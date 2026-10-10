typedef int s32;
typedef unsigned int u32;
typedef unsigned long u64;
typedef float f32;

struct Elem {
    s32 a;
    f32 b;
    f32 c;
    f32 d;
    f32 e[3];
    f32 pad[3];
    f32 f[3];
    f32 g[3];
    f32 h[3];
    f32 i[3];
    f32 j[3];
    f32 k[2];
};

struct Self {
    struct Elem arr[2];
    s32 xD8;
    f32 vDC[3];
    s32 xE8;
    s32 xEC;
    char padF0[0x10];
    f32 m[4][4];
    s32 x140;
    s32 x144;
    s32 x148;
    f32 x14C;
    s32 x150;
    s32 x154;
    s32 x158;
    f32 x15C;
    s32 x160;
    char buf[6];
    char pad16A[6];
};

extern "C" void *func_005A48D8(void *arg0, s32 arg1, s32 arg2);

struct func_00378CB8_self {
    char pad0[0x168];
    u64 unk168;
};

extern "C" void func_00378CB8(struct Self *self) {
    s32 i;
    s32 j;
    s32 k;
    s32 off;
    char *m;

    for (i = 0, m = (char *)self->m, off = 0; i < 4; i++, off += 4) {
        for (j = 0; j < 4; j++) {
            f32 *p = (f32 *)(m + j * 16 + off);
            *p = 0.0f;
            if (i == j) {
                *p = 1.0f;
            }
        }
    }
    self->x148 = 0;
    for (k = 0; k < 2; k++) {
        struct Elem *e = &self->arr[k];
        self->arr[k].b = 1.0f;
        self->arr[k].c = 100.0f;
        self->arr[k].d = 70.0f;
        func_005A48D8(e->e, 0, 0xC);
        func_005A48D8(e->f, 0, 0xC);
        func_005A48D8(e->g, 0, 0xC);
        func_005A48D8(e->h, 0, 0xC);
        func_005A48D8(e->i, 0, 0xC);
        func_005A48D8(e->j, 0, 0xC);
        func_005A48D8(e->k, 0, 0xC);
    }
    ((struct func_00378CB8_self *)self)->unk168 &= 0xFFFFFFFF00FFFFFFul;
    func_005A48D8(self->vDC, 0, 0xC);
    self->xE8 = 1;
    self->x14C = 1.0f;
    ((struct func_00378CB8_self *)self)->unk168 &= 0xFFFF00FFFFFFFFFFul;
    self->xEC = 0;
    self->x140 = 0;
    self->x144 = 0;
    self->x150 = 10000;
    self->x154 = -60;
    self->x158 = 0;
    self->x15C = 5500.0f;
    self->x160 = 0;
    for (k = 0; k < 6; k++) {
        self->buf[k] = 0;
    }
    ((struct func_00378CB8_self *)self)->unk168 &= 0xFFFFFFFFFF00FFFFul;
}
