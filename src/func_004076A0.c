typedef int s32;

typedef struct Sub { s32 m0; s32 pad[0x10]; s32 m44; } Sub;
typedef struct Self {
    s32 m0; s32 pad[0x10]; s32 m44; s32 m48;
    Sub sub;
    s32 m94; s32 pad3[4]; s32 mA8; s32 pad4[1]; char mB0[4];
} Self;
s32 func_00449D58(void *);

void func_004076A0(Self *self) {
    Sub *s;
    self->m0 = 0;
    self->m44 = 0;
    self->m48 = 0;
    s = &self->sub;
    s->m0 = 0;
    s->m44 = 0;
    self->m94 = 0;
    self->mA8 = 0;
    func_00449D58(self->mB0);
}
