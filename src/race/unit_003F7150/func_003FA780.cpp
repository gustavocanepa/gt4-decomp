typedef unsigned char u8;
typedef int s32;

struct Obj003FA780 {
    char pad0[0x89];
    u8 unk89;
};

extern "C" s32 func_003FA780(struct Obj003FA780 *arg0) {
    switch (arg0->unk89) {
        case 0: return 1;
        case 1: return 1;
        case 2: return 1;
        case 3: return 1;
        case 4: return 1;
        case 5: return 1;
        case 6: return 1;
        case 7: return 1;
        case 8: return 1;
        case 9: return 1;
        case 10: return 1;
        case 11: return 1;
        case 12: return 1;
        default:
            return 0;
    }
}
