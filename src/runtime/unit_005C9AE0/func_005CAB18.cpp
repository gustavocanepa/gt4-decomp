typedef int s32;

struct D_Node {
    char pad[8];
    D_Node *next;
    D_Node *child;
};

extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, s32 arg3);
extern "C" s32 *func_005CB0E0(void);

extern "C" void func_005CAB18(s32 arg0, D_Node *node) {
    if (node) {
        do {
            func_005CAB18(arg0, node->child);
            D_Node *next = node->next;
            s32 *p = func_005CB0E0();
            func_00326798(node, 0x14, 4, *p);
            node = next;
        } while (node);
    }
}
