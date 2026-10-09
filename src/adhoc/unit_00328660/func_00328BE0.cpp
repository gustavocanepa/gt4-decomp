typedef int s32;

struct Node {
    char pad0[4];
    Node *unk4;
    Node *unk8;
};

struct List {
    char pad0[0x30];
    Node *unk30;
    Node *unk34;
};

extern "C" void func_00328BE0(List *arg0, Node *arg1) {
    Node *head = arg0->unk30;
    if (head == 0) {
        arg0->unk34 = arg1;
        arg0->unk30 = arg1;
        return;
    }
    head->unk4 = arg1;
    arg1->unk8 = arg0->unk30;
    arg0->unk30 = arg1;
}
