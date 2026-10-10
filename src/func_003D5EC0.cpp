typedef int s32;

struct Obj {
    char pad0[0x123CC];
    char unk123CC[4];
};

extern "C" void *func_00389628(Obj *self, s32 id);

extern "C" void *func_003D5EC0(Obj *self, s32 id) {
    if (id == 0x100) {
        return self->unk123CC;
    }
    return func_00389628(self, id);
}
