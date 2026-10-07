typedef int s32;

extern "C" void func_00460188();
extern "C" void func_00460780();
extern "C" void func_00461AF8();

extern "C" void func_00460A90(s32 arg0) {
    switch (arg0) {
        case 1:
            func_00461AF8();
            return;
        case 2:
            func_00460188();
            return;
        case 3:
            func_00460780();
            return;
    }
}
