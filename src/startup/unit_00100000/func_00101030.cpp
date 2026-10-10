typedef int s32;

extern char D_00617CB8[];
extern char D_00617CF8[];
extern char D_00659AC0[];
struct Self { char pad[0x64]; char *vtbl; s32 m68; };
extern "C" void *func_00109658(Self *, char *, char *);

extern "C" void *func_00101030(Self *self) {
    void *r = func_00109658(self, D_00617CB8, D_00617CF8);
    self->m68 = 0;
    self->vtbl = D_00659AC0;
    return r;
}
