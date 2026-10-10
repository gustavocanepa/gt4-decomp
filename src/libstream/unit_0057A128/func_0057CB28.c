/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef struct Node_0057CB28 {
    int m0;
    struct Node_0057CB28 *prev;
    struct Node_0057CB28 *next;
} Node_0057CB28;

typedef struct {
    Node_0057CB28 *head;
} List_0057CB28;

void func_0057CB00(List_0057CB28 *list, Node_0057CB28 *node);

void func_0057CB28(List_0057CB28 *list, Node_0057CB28 *pos, Node_0057CB28 *node) {
    Node_0057CB28 *prev;
    if (pos == 0) {
        func_0057CB00(list, node);
        return;
    }
    prev = pos->prev;
    node->next = pos;
    node->prev = prev;
    if (prev != 0) {
        prev->next = node;
    } else {
        list->head = node;
    }
    pos->prev = node;
}
