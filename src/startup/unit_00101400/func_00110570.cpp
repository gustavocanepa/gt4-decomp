typedef int s32;

struct Node00110570 {
    char pad[0x10];
    struct Node00110570 *unk10;
    s32 unk14;
};

struct List00110570 {
    s32 unk0;
    char pad[0x10];
    struct Node00110570 *unk14;
};

struct Obj00110570 {
    char pad[0x60];
    struct List00110570 *unk60;
};

extern "C" s32 func_00110570(struct Obj00110570 *arg0, s32 arg1) {
    struct List00110570 *list = arg0->unk60;
    s32 count = list->unk0;
    s32 i;
    struct Node00110570 *node;

    node = list->unk14;
    for (i = 0; i < count; i++) {
        if (node->unk14 == arg1) {
            break;
        }
        node = node->unk10;
    }
    return i;
}
