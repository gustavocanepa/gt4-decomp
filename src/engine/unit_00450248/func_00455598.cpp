extern "C" void ModelSet2__render(void *a, int c);
extern "C" void ModelSet2__begin(void *a, int c);
extern "C" void ModelSet2___render(void *a, int b, int c);
extern "C" void ModelSet2__end(void *a);

extern "C" void func_00455598(void *a, int b, int c) {
    if (b < 0)
        return ModelSet2__render(a, c);
    ModelSet2__begin(a, c);
    ModelSet2___render(a, b, c);
    ModelSet2__end(a);
}
