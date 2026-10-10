typedef int s32;

struct Obj {
    char pad[0xE418];
    s32 active;
};

extern "C" void func_0038B428(Obj *);
extern "C" void func_003BA8B8(Obj *, s32);

extern "C" void func_003BA218(Obj *self) {
    func_0038B428(self);
    if (self->active != 0)
        func_003BA8B8(self, 1);
}
