typedef int s32;

extern s32 D_006186FC;

extern "C" void func_00575DA0(s32 arg0);

extern "C" void func_003B1C28(void) {
    s32 temp_v1 = D_006186FC;
    if (temp_v1 != 0) {
        func_00575DA0(temp_v1);
        D_006186FC = 0;
    }
}
