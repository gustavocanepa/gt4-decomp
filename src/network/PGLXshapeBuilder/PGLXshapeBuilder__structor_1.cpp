typedef int s32;

struct Obj00494520 {
    char pad[0x98C];
    void *unk98C;
};

extern char PGLXshapeBuilder__vtable[];
extern "C" s32 func_00494578(struct Obj00494520 *arg0);

extern "C" s32 PGLXshapeBuilder__structor_1(struct Obj00494520 *arg0) {
    arg0->unk98C = PGLXshapeBuilder__vtable;
    return func_00494578(arg0);
}
