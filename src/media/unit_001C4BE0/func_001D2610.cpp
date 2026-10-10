typedef int s32;

struct Obj {
    char pad0[0x698];
    s32 unk698;
};

extern "C" void func_00576788(Obj *self);
extern "C" void func_005767C0(Obj *self);

extern "C" void func_001D2610(Obj *self, s32 value) {
    func_00576788(self);
    self->unk698 = value;
    func_005767C0(self);
}
