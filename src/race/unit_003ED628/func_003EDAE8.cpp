struct Arena {
    char pad[0x18];
    void *vtable;
    int pad1C;
    char member[0x10];
};

extern "C" Arena D_00621F58;
extern "C" char D_00621F78[];
extern "C" char D_0067E228[];
extern "C" void _UnitArenaBase__structor_1(Arena *a);
extern "C" void _UnitArenaBase__structor_0(Arena *a, int flags);
extern "C" void func_003ED710(void *m);

extern "C" void func_003EDAE8(int init, int prio) {
    if (prio == 0xFFFF && init == 1) {
        _UnitArenaBase__structor_1(&D_00621F58);
        D_00621F58.vtable = D_0067E228;
    }
    if (prio == 0xFFFF && init == 1)
        func_003ED710(D_00621F78);
    if (prio == 0xFFFF && init == 0)
        _UnitArenaBase__structor_0(&D_00621F58, 0);
}
