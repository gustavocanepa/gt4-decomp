struct Node {
    char pad[0x10];
    unsigned long long offset : 24;
    unsigned long long rest : 40;
};
extern "C" unsigned int func_0042F4C8(Node *n);

extern "C" void func_00435148(Node *n, unsigned int addr)
{
    n->offset = addr - func_0042F4C8(n);
}
