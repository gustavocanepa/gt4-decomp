typedef long long s64;
typedef unsigned long long u64;
typedef unsigned int u32;

struct Database {
    char pad0[0x88];
    void *tables[1];
};

extern "C" int func_00449A20(void *table, int key);

extern "C" s64 func_00443E00(Database *db, int key, int type) {
    void *t = db->tables[type];
    if (!t)
        return -1;
    int id = func_00449A20(t, key);
    if (id == -1)
        return -1;
    return ((s64)type << 32) | (u32)id;
}
