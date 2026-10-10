typedef int s32;

struct Info {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

extern s32 D_0062378C;

extern "C" s32 SPEC_DATABASE__GetCarNameInfo(s32 id, Info *info);
extern "C" const char *func_00449CD8(s32 a, s32 b);
extern "C" char *func_005A609C(char *dst, const char *src);

extern "C" void func_004481B8(s32 id, char *out) {
    Info info;
    if (SPEC_DATABASE__GetCarNameInfo(id, &info)) {
        func_005A609C(out, func_00449CD8(D_0062378C, info.unk8));
    }
}
