typedef int s32;

struct Obj { void *f0; char pad4[0x3C]; char *f40; char pad44[0x3C]; char buf[1]; };
extern "C" void func_00578500(void *);
extern "C" void func_00578168(struct Obj *, s32, s32, s32, s32);

extern "C" void func_00610130(struct Obj *o) {
    func_00578500(o->f0);
    o->f40 = o->buf;
    func_00578168(o, 0, 0, 0, 0);
}
