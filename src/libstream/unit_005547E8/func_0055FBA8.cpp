extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *);
};

struct Client {
    char pad0[0xD0];
    VEntry *vt;
};

struct Node {
    Client *client;
    int pad4;
    Node *next;
};

struct Server {
    char mutex[0x30];
    Node *head;
};

extern "C" void func_0055FBA8(Server *self)
{
    func_00576788(self);
    for (Node *n = self->head; n != 0; n = n->next) {
        Client *c = n->client;
        VEntry *e = &c->vt[3];
        e->fn((char *)c + e->delta);
    }
    func_005767C0(self);
}
