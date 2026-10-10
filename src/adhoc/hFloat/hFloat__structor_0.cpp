typedef int s32;

extern char hFloat__vtable[];
extern "C" void *hObject__structor_0(void *);

struct hFloat { s32 m0; char *vtbl; s32 m8, mC; float v; };

extern "C" void *hFloat__structor_0(hFloat *self, float v) {
    void *r = hObject__structor_0(self);
    self->vtbl = hFloat__vtable;
    self->v = v;
    return r;
}
