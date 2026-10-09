typedef int s32;

extern "C" void func_00460168();
extern "C" void func_00460730();
extern "C" void func_00461AB8();

extern "C" void func_00460A28(s32 arg0) {
    switch (arg0) {
        case 1:
            func_00461AB8();
            return;
        case 2:
            func_00460168();
            return;
        case 3:
            func_00460730();
            return;
    }
}
