struct Obj3D36C0 {
    char pad[0x8];
    void *unk8;
};

extern "C" void func_003D36C0(char *arg0) {
    ((Obj3D36C0 *)arg0)->unk8 = arg0 + 0x1C;
}
