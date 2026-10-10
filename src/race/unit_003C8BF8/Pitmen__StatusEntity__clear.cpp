typedef int s32;

struct Self { s32 m0; char pad[0x10]; s32 m14; s32 m18; char m1C[0x14C]; s32 m168, m16C, m170, m174; };
extern "C" void ConcourseLighting__clear(void *);

extern "C" void Pitmen__StatusEntity__clear(Self *self) {
    self->m0 = 0;
    ConcourseLighting__clear(self->m1C);
    self->m168 = 0;
    self->m16C = 0;
    self->m170 = 0;
    self->m174 = 0;
    self->m14 = 0;
    self->m18 = 0;
}
