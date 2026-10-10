struct Node {
    Node *next;
    void *item;
};

extern "C" Node *D_00654A44;
extern "C" char D_006C8C60[];
extern "C" int func_0055F3E8(void *item, const char *name);

extern "C" int func_0055F420(const char *name)
{
    if (!name)
        name = D_006C8C60;
    for (Node *n = D_00654A44; n; n = n->next) {
        int r = func_0055F3E8(n->item, name);
        if (r)
            return r;
    }
    return 0;
}
