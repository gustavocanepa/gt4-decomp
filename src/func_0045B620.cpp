typedef int s32;

struct Id {
    s32 a;
    s32 b;
    s32 c;
};

extern "C" void func_0045B5C8(Id *id);

extern "C" Id func_0045B620(void) {
    Id t;
    t.b = -1;
    t.c = 0;
    t.a = 0;
    func_0045B5C8(&t);
    return t;
}
