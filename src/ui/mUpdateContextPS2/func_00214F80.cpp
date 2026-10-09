typedef int s32;
typedef unsigned char u8;

struct Obj {
    u8 pad[0x420];
    s32 unk420;
};

struct D_Obj {
    u8 pad[0x78];
    s32 unk78;
};

extern D_Obj D_0061850C;

extern "C" void *func_00214F80(Obj *arg0) {
    void *result = (char *)arg0 + 0x3E4;
    if (arg0->unk420 == 0) {
        result = (char *)&D_0061850C + D_0061850C.unk78 * 0x3C;
    }
    return result;
}
