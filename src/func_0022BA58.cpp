typedef int s32;

struct Target {
    char pad[0x10];
    s32 id;
};

struct Handle {
    Target *p;
    s32 pad[3];
};

extern "C" Handle *func_0022AD20(Handle *);
extern "C" void func_0022ACC8(Handle *, s32);
extern "C" s32 func_002A95A8(void);
extern "C" void func_00250B98(s32, s32);

extern "C" void func_0022BA58(void) {
    Handle h;
    func_0022AD20(&h);
    s32 id = h.p->id;
    func_00250B98(id, func_002A95A8());
    func_0022ACC8(&h, 2);
}
