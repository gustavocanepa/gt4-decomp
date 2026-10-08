typedef void (*FnPtr)(void *);

struct Obj {
    char pad[0xD8];
    FnPtr unkD8;
};

extern "C" void func_00251EC8(Obj *arg0) {
    FnPtr temp_v0 = arg0->unkD8;
    if (temp_v0 != 0) {
        temp_v0(arg0);
    }
}
