typedef unsigned short u16;

struct Obj {
    char pad[0x60E];
    u16 unk60E;
};

extern "C" u16 func_0035FC68(Obj *arg0) {
    u16 temp_v1 = arg0->unk60E;
    u16 nz = 0 < temp_v1;
    arg0->unk60E = (u16)(temp_v1 - nz);
    return temp_v1;
}
