struct Obj {
    char pad[0x18];
    char m18[1];
};

extern char D_00870000[];

extern "C" int func_005ADB90(Obj *o);
extern "C" void func_005B1BF0(Obj *o, int v);
extern "C" void func_00553D80(void);
extern "C" void func_005B1C88(void *p, int tag, void (*fn)(void), void *buf, int a, int b, Obj *o);
extern "C" void func_005B20A0(Obj *o);

extern "C" void func_00553BA0(Obj *o) {
    func_005B1BF0(o, func_005ADB90(o));
    func_005B1C88(o->m18, 0x42535550, func_00553D80, D_00870000, 0, 0, o);
    func_005B20A0(o);
}
