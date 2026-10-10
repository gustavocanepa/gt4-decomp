/* compiler: ee-gcc2.96-nsa-nosib-as2004 */
typedef struct Node {
    int id;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *head;
    Node *tail;
} Queue;

typedef struct Pool {
    int handle;
} Pool;

int func_005B72A8(void);
int func_005B72F8(void);
int func_005ADBD0(int id);
void func_00567790(int handle, Node *node);

void func_00554910(Pool *pool, Queue *q) {
    Node *node;
    func_005B72A8();
    while ((node = q->head) != 0) {
        func_005B72F8();
        func_005ADBD0(node->id);
        func_005B72A8();
        if ((q->head = node->next) == 0)
            q->tail = (Node *)q;
        func_00567790(pool->handle, node);
    }
    func_005B72F8();
}
