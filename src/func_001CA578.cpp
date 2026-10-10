typedef int s32;

struct Req {
    s32 unk0;
    s32 size;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 pad[2];
};

struct Obj {
    char pad[0x5C];
    s32 handle;
};

extern char D_00693F50[];
extern "C" s32 func_005C1CF0(s32, Req *);

extern "C" char *func_001CA578(Obj *self) {
    Req r;
    r.unk0 = 0;
    r.size = 0x14;
    r.unk8 = 0;
    r.unkC = 0;
    r.unk10 = 0;
    r.unk14 = 0;
    r.unk18 = 0;
    r.unk24 = 0;
    if (func_005C1CF0(self->handle, &r))
        return D_00693F50;
    return 0;
}
