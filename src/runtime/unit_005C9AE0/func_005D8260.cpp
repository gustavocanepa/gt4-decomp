typedef unsigned int u32;

extern "C" void _Rb_tree_node_base__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006975E8[];
extern int D_006D5E60;

extern int D_0088E080;

extern "C" void *func_005D8260(void) {
    if (D_0088E080 == 0) {
        _Rb_tree_node_base__tf();
        func_005BFB68(&D_0088E080, D_006975E8, &D_006D5E60);
    }
    return &D_0088E080;
}
