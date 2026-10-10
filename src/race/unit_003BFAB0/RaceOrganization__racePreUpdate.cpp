/* compiler: ee-gcc2.96-no-strict-aliasing */
struct func_003C0208_C {
    char pad[0x80];
    struct { int pad; void *p; } *x80;
};

struct func_003C0208_B {
    char pad[0x6C];
    func_003C0208_C *x6c;
};

struct func_003C0208_Obj {
    char pad0[0x84];
    func_003C0208_B *x84;
    char pad1[0xB0 - 0x88];
    int pending;
    int request;
    int count;
    int timer;
    char pad2[0xF4 - 0xC0];
    char fx[4];
};

extern "C" {
void func_003B76F0(void *fx, int a, int b, int c);
void func_003973D0(void *p, float v);
}

extern "C" void RaceOrganization__racePreUpdate(func_003C0208_Obj *self) {
    if (self->pending) {
        self->pending = 0;
        switch (self->request) {
        case 1:
            self->count = 8;
            func_003B76F0(self->fx, 0x18, 0x13, 0);
            break;
        case 2:
            self->count = 10;
            func_003B76F0(self->fx, 0x18, 10, 0);
            break;
        case -1:
            func_003B76F0(self->fx, 0x18, 12, 0);
        case 3:
            self->count = 0;
            break;
        case 0:
            break;
        }
        self->timer = self->count * 60;
        func_003973D0(self->x84->x6c->x80->p, (float)self->count);
    }
    if (self->timer != 0) {
        if (--self->timer == 0)
            func_003B76F0(self->fx, 4, -1, 0);
    }
}
