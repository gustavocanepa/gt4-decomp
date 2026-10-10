typedef float f32;

struct Self { char pad[0x38]; f32 m38, m3C; };
extern f32 D_0062150C;
extern "C" void func_00397E98(void);

extern "C" void func_00397DF8(Self *self) {
    D_0062150C = 0x1.000000p+0f / (self->m3C * self->m38);
    func_00397E98();
}
