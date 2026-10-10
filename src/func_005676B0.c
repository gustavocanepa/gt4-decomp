/* compiler: ee-gcc2.96-nsa-nosib */
typedef struct Node {
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node **tail;
    Node *pendingHead;
    Node **pendingTail;
} Queue;

void func_005B72A8(void);
void func_005B72F8(void);

void func_005676B0(Queue *q)
{
    Node *n;

    func_005B72A8();
    while ((n = q->pendingHead) != 0) {
        n->next = 0;
        *q->tail = n;
        q->tail = &n->next;
        if ((q->pendingHead = n->next) == 0)
            q->pendingTail = &q->pendingHead;
    }
    func_005B72F8();
}
