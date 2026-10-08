typedef signed char s8;

struct Obj {
    char pad[0x14];
    s8 *unk14;
};

extern "C" void func_00615480(struct Obj *arg0, s8 arg1) {
    s8 **pp = &arg0->unk14;
    *(*pp)++ = arg1;
}
