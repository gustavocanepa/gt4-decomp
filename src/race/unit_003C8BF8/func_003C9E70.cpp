struct List { short pad; unsigned short count; int *items; };
bool func_003C9DB0(int, int);

bool func_003C9E70(List *l, int arg) {
    bool r = false;
    for (int i = 0; i < l->count; i++) r ^= func_003C9DB0(l->items[i], arg);
    return r;
}
