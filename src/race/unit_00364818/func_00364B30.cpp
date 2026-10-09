typedef int s32;
typedef float f32;

struct Table {
    unsigned char pad0;
    unsigned char count;
    unsigned char pad2[0x12];
    unsigned char ids[1];
};

struct Entry {
    char pad[4];
    f32 a;
    f32 b;
    char pad2[4];
    f32 base;
    char pad3[0x58 - 0x14];
};

struct Data {
    char pad[0x908];
    Entry entries[1];
};

extern "C" Table *func_00359510(s32);

extern "C" f32 func_00364B30(Data **self, s32 i) {
    Table *t;
    unsigned char k;
    Entry *e;

    t = func_00359510((s32)*self + 0x600);
    k = 0;
    if (i < t->count) {
        k = t->ids[i];
    }
    e = &(*self)->entries[k];
    return e->b - e->base;
}
