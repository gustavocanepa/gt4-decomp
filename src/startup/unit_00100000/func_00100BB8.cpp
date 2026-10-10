typedef int s32;

struct Mgr {
    char lock[0x6C];
    char list[0x30];
    s32 value;
    s32 dirty;
};

extern Mgr D_006D6708;
extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);
extern "C" void func_00574E78(void *);

extern "C" void func_00100BB8(s32 value) {
    Mgr *m = &D_006D6708;
    func_00576788(m);
    func_00574E78(m->list);
    m->value = value;
    m->dirty = 1;
    func_005767C0(m);
}
