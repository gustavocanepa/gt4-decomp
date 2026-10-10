struct Array {
    int data[32];
    unsigned int count;
};

extern "C" void func_005FD4A0(Array *a, int *first, int *last);
extern "C" void func_005FD540(Array *a, int *pos, unsigned int n, const int &value);

extern "C" void func_005FD3F0(Array *a, unsigned int n, int value)
{
    unsigned int size = a->count;
    if (n == size)
        return;
    if (n < size)
        func_005FD4A0(a, a->data + n, a->data + size);
    else
        func_005FD540(a, a->data + size, n - size, value);
}
