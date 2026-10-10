struct Node { Node *next; const char *name; };
extern "C" Node *D_00623818;
extern "C" int func_0057F238(const char *a, const char *b);

extern "C" Node *func_0044CEB8(const char *name)
{
    Node *n; for (n = D_00623818; n; n = n->next) if (!func_0057F238(n->name, name)) break; return n;
}
