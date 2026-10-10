typedef void (*func_005256A8_Fn)(int *obj, int a, int b);

extern "C" {
void func_00529650(int key, int a);
void func_00525AF8(int *obj, int a, int b);
void func_00525C58(int *obj, int a, int b);
void func_00525D20(int *obj, int a, int b);
void func_00525E60(int *obj, int a, int b);
void func_00525E80(int *obj, int a, int b);
void func_00525EA0(int *obj, int a, int b);
}

extern "C" void func_005256A8(int key, int a, unsigned int sel, int b, int *obj) {
    func_005256A8_Fn fn = 0;
    if (*obj != key) {
        func_00529650(key, a);
        if (*obj != key)
            return;
    }
    switch (sel) {
    case 0:
        fn = func_00525AF8;
        break;
    case 1:
        fn = func_00525C58;
        break;
    case 2:
        fn = func_00525D20;
        break;
    case 4:
        fn = func_00525E60;
        break;
    case 3:
        fn = func_00525E80;
        break;
    case 5:
        fn = func_00525EA0;
        break;
    }
    if (fn)
        fn(obj, a, b);
}
