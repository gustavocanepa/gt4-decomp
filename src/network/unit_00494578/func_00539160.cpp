typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

struct Obj00539160 {
    u8 unk0;
    u8 unk1;
};

extern "C" s32 func_00539160(struct Obj00539160 *arg0, u32 arg1) {
    s32 var_v0;
    u16 temp_a1;

    temp_a1 = (u16)arg1;
    var_v0 = 2;
    if (arg0 != 0) {
        arg0->unk0 = (u8)(temp_a1 >> 8);
        var_v0 = 0;
        arg0->unk1 = (u8)temp_a1;
    }
    return var_v0;
}
