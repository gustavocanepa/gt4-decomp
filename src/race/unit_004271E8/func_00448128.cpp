typedef int s32;

extern s32 D_0062378C;
extern "C" s32 SPEC_DATABASE__GetCarNameInfo(void *, s32 *);
extern "C" s32 func_00449CD8(s32, s32);
extern "C" void func_005A609C(void *, s32);

extern "C" void func_00448128(void *self, void *out) {
    s32 t[4];
    if (SPEC_DATABASE__GetCarNameInfo(self, t)) {
        func_005A609C(out, func_00449CD8(D_0062378C, t[0]));
    }
}
