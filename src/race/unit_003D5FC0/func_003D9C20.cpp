struct Obj {
    char pad0[0x28];
    int cur;
    int next;
    char pad30[0x9C - 0x30];
    int state;
};

extern "C" void func_003D9C70(Obj *o, int id);

extern "C" void func_003D9C20(Obj *o, int id) {
    if (id != o->cur && id != o->next) {
        func_003D9C70(o, id);
        o->state = 6;
    }
}
