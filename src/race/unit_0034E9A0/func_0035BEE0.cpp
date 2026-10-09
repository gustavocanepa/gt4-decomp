typedef unsigned short u16;

struct Obj {
    char pad[0x5BE];
    u16 unk5BE;
};

extern "C" void func_00362E58(Obj *arg0);

extern "C" void func_0035BEE0(Obj *arg0) {
    if (arg0->unk5BE != 0) {
        func_00362E58(arg0);
    }
}
