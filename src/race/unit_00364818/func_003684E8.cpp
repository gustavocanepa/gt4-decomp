typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

struct Obj003684E8 {
    u8 pad0[4];
    s32 unk4;
};

extern u8 D_0000F85D[];

extern "C" s32 func_00354E08(void *arg0);
extern "C" s32 Automobile_GetAverageGasMileage10(struct Obj003684E8 *arg0);

extern "C" s32 func_003684E8(struct Obj003684E8 *arg0) {
    if (D_0000F85D[arg0->unk4] != 0) {
        return Automobile_GetAverageGasMileage10(arg0);
    }
    return func_00354E08(arg0);
}
