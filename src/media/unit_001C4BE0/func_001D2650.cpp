typedef int s32;

struct Obj {
    char pad0[0x694];
    s32 unk694;
    char pad698[0x6E0 - 0x698];
    s32 thread;
};

struct ThreadDesc {
    void (*entry)(void);
    Obj *arg;
    s32 pad[2];
};

extern "C" void func_001D25F0(void);
extern "C" s32 func_00575098(ThreadDesc *desc, s32 arg1);
extern "C" void func_001D2610(Obj *self, s32 value);
extern "C" void func_005788B8(s32 thread);

extern "C" void func_001D2650(Obj *self) {
    ThreadDesc desc;
    desc.entry = func_001D25F0;
    desc.arg = self;
    self->thread = func_00575098(&desc, 0);
    self->unk694 = 0;
    func_001D2610(self, 5);
    func_005788B8(self->thread);
}
