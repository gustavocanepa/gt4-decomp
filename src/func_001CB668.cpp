typedef int s32;

extern "C" s32 func_004CD298(s32 arg0);

struct Obj_001CB668 {
    char pad[8];
    s32 unk8;
};

extern "C" const char *func_001CB668(Obj_001CB668 *arg0) {
    if (func_004CD298(arg0->unk8) < 0) {
        return "failed";
    }
    return 0;
}
