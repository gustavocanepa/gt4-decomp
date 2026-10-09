struct Obj398B48 {
    char pad[0x6C];
    int unk6C;
    char pad2[0x90 - 0x6C - 4];
    int unk90;
};

extern "C" void func_00398B48(Obj398B48 *arg0) {
    arg0->unk90 = 0;
    arg0->unk6C = 0;
}
