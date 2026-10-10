extern void *D_00624980;
extern void *D_00624984;
extern "C" void *func_0048FED0(void *mgr, void *obj);
extern "C" void func_00490040(void *mgr, void *item);

extern "C" void func_0048F930(void *obj) {
    if (D_00624980 && obj) {
        void *item = func_0048FED0(D_00624980, obj);
        if (D_00624984 && item)
            func_00490040(D_00624984, item);
    }
}
