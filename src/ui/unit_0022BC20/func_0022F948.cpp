typedef int s32;

struct Obj {
    char pad0[0x44];
    s32 flag;
    char lock[4];
};

extern "C" void func_00576788(void *lock);
extern "C" void func_005767C0(void *lock);

extern "C" void func_0022F948(Obj *self) {
    func_00576788(self->lock);
    self->flag = 1;
    func_005767C0(self->lock);
}
