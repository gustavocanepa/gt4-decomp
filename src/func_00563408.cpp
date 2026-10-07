typedef int s32;

struct Elem {
    s32 unk0;
    s32 unk4;
};

extern Elem D_00874344[];

extern "C" s32 func_00563408(s32 arg0) {
    return D_00874344[arg0].unk0;
}
