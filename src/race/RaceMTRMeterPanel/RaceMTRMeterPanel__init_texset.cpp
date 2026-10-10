typedef int s32;

struct Obj {
    char pad[0x1C];
    void *p;
};

extern char D_006A1768[];
extern "C" void *func_003A1E10(void *);

extern "C" void RaceMTRMeterPanel__init_texset(Obj *self) {
    if (self->p == 0)
        self->p = func_003A1E10(D_006A1768);
}
