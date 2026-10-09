typedef unsigned int u32;

struct Obj {
    char pad[8];
    u32 unk8;
};

extern "C" u32 func_003A3680(struct Obj *arg0) {
    u32 temp_v0;

    temp_v0 = arg0->unk8;
    return (temp_v0 > 0x03FFFFFEU) ? 0x157529FFU : temp_v0;
}
