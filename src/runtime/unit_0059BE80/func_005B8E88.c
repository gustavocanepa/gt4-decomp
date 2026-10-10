/* compiler: ee-gcc2.9-991111 */
typedef struct Node {
    struct Node *next;
    int data[3];
} Node;

extern Node D_0088BF40[64];
extern Node *D_0088C340;

int func_005B8E88(void) {
    int i;
    D_0088C340 = D_0088BF40;
    for (i = 63; i >= 0; i--)
        D_0088BF40[i].next = &D_0088BF40[i + 1];
    D_0088BF40[63].next = 0;
    return 0;
}
