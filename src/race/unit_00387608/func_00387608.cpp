extern char D_006212C8[];
extern char D_006212D0[];
extern char D_006212E0[];
extern char D_006212E8[];

extern "C" void func_00387B30(void *a, void *b);

static inline void loadA(int id) {
    if (id == 1)
        func_00387B30(D_006212C8, D_006212D0);
}

static inline void loadB(int id) {
    if (id == 1)
        func_00387B30(D_006212E0, D_006212E8);
}

extern "C" void func_00387608(int id, int key) {
    if (key == 0xFFFF) {
        loadA(id);
        loadB(id);
    }
}
