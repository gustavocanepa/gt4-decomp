/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef long s64;

/* A file object followed by the header it reads: two sizes and a name. */
struct Frame {
    char obj[0xD0];
    s32 d0;
    s32 d4;
    s32 d8;
    char name[0x150 - 0xDC];
};
struct Stream {
    s32 handle;
    char pad[0x3C];
    s32 arg0;
    s32 arg1;
    s32 user;
    s32 flags;
    char name[0xB0];
};
struct Status {
    s64 position;
    char pad[0xC];
    s32 busy;
};
extern Stream D_0086CA40;
extern Status D_0086CB40;

extern "C" void func_004AFE28(void *self);
extern "C" s32 func_004AFA20(void *self, void *arg);
extern "C" void func_004AFE60(void *self, s32 mode);
extern "C" s32 func_004AFED8(void *self, void *name, s32 mode);
extern "C" s32 func_004AFF60(void *self);
extern "C" void func_005A609C(char *dst, char *src);
extern "C" s32 func_00578500(s32 handle);
extern "C" s32 func_00578168(void *obj, s32 a1, s32 a2, void *buf, s32 size);

extern "C" void func_00547E10(void *name, s32 user) {
    Frame f;

    func_004AFE28(&f);
    if (func_004AFED8(&f, name, 3) >= 0) {
        f.d0 = 0;
        if (func_004AFA20(&f, &f.d0) != 0) {
            Stream *s;
            do { s = &D_0086CA40; } while (0);
            s32 d4 = f.d4;
            s32 d8 = f.d8;
            s32 flags = 0x40000;
            func_00578500(s->handle);
            D_0086CB40.position = -1;
            D_0086CB40.busy = 0;
            s->arg0 = d4;
            s->arg1 = d8;
            s->user = user;
            s->flags = flags;
            s->name[0] = 0;
            func_005A609C(s->name, f.name);
            func_00578168(s, 1, 0, 0, 0);
        }
        func_004AFF60(&f);
    }
    func_004AFE60(&f, 2);
}
