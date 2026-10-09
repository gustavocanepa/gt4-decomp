typedef unsigned int u32;

extern "C" void func_00602780();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D60B0;

extern int D_0088FC90;

extern "C" void *func_00601238(void) {
    if (D_0088FC90 == 0) {
        func_00602780();
        func_005BFB68(&D_0088FC90, ((char *)"Q212GranTurismo416CourseRecordBase"), &D_006D60B0);
    }
    return &D_0088FC90;
}
