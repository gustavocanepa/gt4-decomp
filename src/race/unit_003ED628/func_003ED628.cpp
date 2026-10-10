extern char D_00621F28[];
extern char D_00621F30[];
extern char D_00621F40[];
extern char D_00621F48[];

extern "C" void func_00387B30(void *a, void *b);

static inline void loadA(int id) {
    if (id == 1)
        func_00387B30(D_00621F28, D_00621F30);
}

static inline void loadB(int id) {
    if (id == 1)
        func_00387B30(D_00621F40, D_00621F48);
}

extern "C" void func_003ED628(int id, int key) {
    if (key == 0xFFFF) {
        loadA(id);
        loadB(id);
    }
}
