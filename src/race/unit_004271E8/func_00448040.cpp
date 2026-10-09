typedef unsigned char u8;
typedef int s32;

struct Local {
    char pad[0x10];
    u8 unk10;
    char pad2[0x20 - 0x10 - 1];
};

extern "C" void func_00447F48(s32 arg0, Local *arg1);

extern "C" u8 func_00448040(s32 arg0) {
    Local loc;
    func_00447F48(arg0, &loc);
    return loc.unk10;
}
