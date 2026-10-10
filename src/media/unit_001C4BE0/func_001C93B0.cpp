typedef int s32;
typedef unsigned int u32;

struct Entry { s32 id; s32 a, b, c; };
extern Entry D_00694B50[];

extern "C" Entry *func_001C93B0(s32 id) {
    u32 i;
    for (i = 0; i < 6; i++) {
        if (id == D_00694B50[i].id) return &D_00694B50[i];
    }
    return D_00694B50;
}
