struct Obj3D36C0 {
    char pad[0x8];
    void *unk8;
};

extern "C" void PitmenTiny__Entity__clear(char *arg0) {
    ((Obj3D36C0 *)arg0)->unk8 = arg0 + 0x1C;
}
