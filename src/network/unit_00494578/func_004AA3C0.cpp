struct Node {
    unsigned char used;
    unsigned char b1;
    signed char prev;
    signed char next;
    signed char c4;
    signed char c5;
    short id;
    int data;
    int pad[2];
};

struct Head {
    unsigned char used;
    unsigned char b1;
    signed char prev;
    signed char next;
    signed char c4;
    signed char c5;
    signed char c6;
    unsigned char c7;
    short id;
    short pad;
    int data;
    int pad10;
};

struct Pool {
    char pad[0xC38];
    Node nodes[32];
    Head head;
    int mask;
};

extern "C" void func_004AA3C0(Pool *p) {
    int i;
    for (i = 1; i < 31; i++)
        p->nodes[i].next = i + 1;
    p->nodes[i].next = -1;
    p->head.c7 = 1;
    p->nodes[0].used = 1;
    p->nodes[0].prev = -1;
    p->nodes[0].next = -1;
    p->nodes[0].c4 = -1;
    p->nodes[0].c5 = -1;
    p->nodes[0].id = 0x1FF;
    p->nodes[0].data = 0;
    p->head.used = 0;
    p->head.b1 = 0;
    p->head.prev = -1;
    p->head.next = -1;
    p->head.c4 = -1;
    p->head.c5 = -1;
    p->head.data = 0;
    p->head.c6 = -1;
    p->head.id = 0x1FF;
    p->mask = 0xFF800;
}
