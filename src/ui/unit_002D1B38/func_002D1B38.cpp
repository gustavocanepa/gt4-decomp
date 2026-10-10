typedef int s32;

struct Self { s32 m0; s32 m4; s32 m8; s32 a[9]; s32 m30; };

extern "C" void func_002D1B38(Self *self, s32 b, s32 c) {
    self->m0 = c;
    self->m4 = b;
    self->m8 = 1;
    self->a[0] = 0;
    self->a[1] = 0;
    self->a[2] = 0;
    self->a[3] = 0;
    self->a[4] = 0;
    self->a[5] = 0;
    self->a[6] = 0;
    self->a[7] = 0;
    self->a[8] = 0;
    self->m30 = 0;
}
