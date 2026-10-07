typedef int s32;

struct Obj {
    char pad[0x74];
    s32 unk74;
};

struct Container {
    char pad[0x84];
    Obj *unk84;
};

extern char D_00621340[];

extern "C" s32 func_003C0C00(Container *arg0) {
    Obj *temp_v0 = arg0->unk84;
    if (temp_v0 == 0) {
        return (s32)D_00621340;
    }
    return temp_v0->unk74;
}
