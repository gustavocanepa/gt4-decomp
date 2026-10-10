extern void *PDISTD__global_font_manager;
extern void *D_00624984;
extern "C" void *func_0048FED0(void *mgr, void *obj);
extern "C" void func_00490040(void *mgr, void *item);

extern "C" void func_0048F930(void *obj) {
    if (PDISTD__global_font_manager && obj) {
        void *item = func_0048FED0(PDISTD__global_font_manager, obj);
        if (D_00624984 && item)
            func_00490040(D_00624984, item);
    }
}
