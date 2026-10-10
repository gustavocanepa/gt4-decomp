/* compiler: ee-gcc2.96-as2004 */
struct Item {
    char pad[0xC];
    int priority;
};

struct Node {
    Item *item;
    Node *prev;
    Node *next;
};

struct List {
    Node *head;
};

extern "C" char D_00631880[];
extern "C" List D_006318B0;
extern "C" void func_00576788(void *lock);
extern "C" void func_005767C0(void *lock);
extern "C" void func_0057CB28(List *list, Node *pos, Item *item);

extern "C" void func_004ACD88(Item *item) {
    func_00576788(D_00631880);
    int p = item->priority;
    Node *n = D_006318B0.head;
    while (n != 0 && p >= n->item->priority)
        n = n->next;
    func_0057CB28(&D_006318B0, n, item);
    func_005767C0(D_00631880);
}
