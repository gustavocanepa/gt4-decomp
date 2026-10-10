/* compiler: ee-gcc2.9-991111 */
struct Node { char pad[0x38]; struct Node *next; };
struct Queue { int a, b; struct Node *head; };
int func_005B72A8(void);
void func_005B72F8(void);

struct Node *func_005B1D58(struct Node *n, struct Queue *q)
{
    struct Node *p;
    func_005B72A8();
    p = q->head;
    if (p == n) {
        q->head = p->next;
    } else {
        while (p != 0) {
            if (p->next == n) {
                p->next = n->next;
                break;
            }
            p = p->next;
        }
    }
    func_005B72F8();
    return p;
}
