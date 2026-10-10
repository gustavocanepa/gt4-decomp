extern int D_006214CC;
extern char RaceCourse__model_arena_[];

extern "C" void *func_00578CB0(int size);
extern "C" int func_00463858(void *heap, void *mem, int total, int size);

extern "C" void func_00394B10(int size) {
    int *initialized = &D_006214CC;
    if (*initialized == 0) {
        int total = size + 0x100;
        func_00463858(RaceCourse__model_arena_, func_00578CB0(total), total, size);
        *initialized = 1;
    }
}
