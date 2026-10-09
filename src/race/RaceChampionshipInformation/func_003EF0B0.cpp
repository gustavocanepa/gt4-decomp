typedef int s32;

struct Node_003EF0B0 {
    char pad0[0x10];
    Node_003EF0B0 *next;
    s32 f14;
};

struct Head_003EF0B0 {
    s32 count;
    char pad4[0x10];
    Node_003EF0B0 *firstNode;
};

struct Arg1_003EF0B0 {
    char pad0[0x60];
    Head_003EF0B0 *head;
};

extern "C" s32 func_003EF0B0(void *arg0, struct Arg1_003EF0B0 *arg1) {
    Head_003EF0B0 *head = arg1->head;
    s32 total = head->count;
    Node_003EF0B0 *node = head->firstNode;
    s32 i;

    for (i = 0; i < total; i++, node = node->next) {
        if (node->f14 == 0) {
            break;
        }
    }

    return i;
}
