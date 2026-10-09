typedef int s32;

struct Inner {
    char pad[0x1310];
    s32 unk1310;
};

struct Obj {
    char pad[0x50];
    Inner *unk50;
};

extern "C" s32 func_004ED570(Obj *arg0) {
    s32 temp = arg0->unk50->unk1310;
    return (temp == -1) ? 1 : temp;
}
