struct Vec {
    int items[0x30];
    unsigned int size;
    void erase(int *first, int *last) __asm__("func_00608A80");
    void insert(int *pos, unsigned int n, const int &x) __asm__("func_00608B20");
    void resize(unsigned int n, int x) __asm__("func_006089D0");
};

void Vec::resize(unsigned int n, int x) {
    if (n == size)
        return;
    if (n < size)
        erase(&items[n], &items[size]);
    else
        insert(&items[size], n - size, x);
}
