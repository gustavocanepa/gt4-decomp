/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Node {
    s32 unk0;
    s32 unk4;
    Node *next;
};

struct List {
    Node *head;
};

extern "C" Node *func_0057CCC8(List *list, s32 index) {
    Node *n;
    s32 i = 0;

    for (n = list->head; n != 0; n = n->next) {
        if (i == index) {
            return n;
        }
        i++;
    }
    return 0;
}
