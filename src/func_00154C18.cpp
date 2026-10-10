typedef int s32;

struct Obj {
    s32 lock;
    s32 unk4;
    s32 active;
    s32 dirty;
};

extern "C" void func_00154C68(Obj *);
extern "C" void func_005767E0(s32);
extern "C" void func_00154C88(Obj *);

extern "C" void func_00154C18(Obj *self) {
    if (self->active != 0) {
        func_00154C68(self);
        self->dirty = 1;
        func_005767E0(self->lock);
        func_00154C88(self);
    }
}
