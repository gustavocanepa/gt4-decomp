extern "C" void ModelSet2__render(void *a, void *b);
extern "C" void func_00455598(void *a, int id, void *b);

extern "C" void func_00428790(void *a, void *b, const unsigned short *list) {
    if (list) {
        int n = *list++;
        for (int i = 0; i < n; i++)
            func_00455598(a, *list++, b);
    } else {
        ModelSet2__render(a, b);
    }
}
