struct Ref {
    int id;
};

extern "C" Ref *func_004580F0(void *p);
extern "C" void func_003971F0(void *self, void *obj, int id);

extern "C" void func_00397188(void *self, void *obj, void *p) {
    if (obj == 0)
        return;
    if (p != 0)
        func_003971F0(self, obj, func_004580F0(p)->id);
    else
        func_003971F0(self, obj, 0);
}
