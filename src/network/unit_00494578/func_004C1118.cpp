/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct E {
    char pad[0x1C];
    u32 *a;
    u16 *b;
    u16 *cnt;
    u16 *mark;
};
struct T {
    E e[4];
    u8 n;
};
struct Obj {
    char pad[0xC];
    u32 *lim;
    char pad10[0x14];
    T *t;
};
extern "C" int func_004C1118(Obj *obj, u32 i, u16 at, u16 from, u32 a, u16 b) {
    u16 j;
    obj->t->e[i].a[*obj->t->e[i].cnt] = a;
    obj->t->e[i].b[*obj->t->e[i].cnt] = b;
    obj->t->e[i].a[*obj->t->e[i].cnt + 2] = *obj->t->e[i].mark << 16;
    obj->t->e[i].a[*obj->t->e[i].cnt + 3] = at << 16;
    obj->t->e[i].a[*obj->t->e[i].cnt + 4] = from << 16;
    obj->t->e[i].a[*obj->t->e[i].cnt + 5] = 0x10000;
    if (at < from) {
        for (j = from; at < j; j--) {
            obj->t->e[i].a[*obj->t->e[i].cnt + 4] = j << 16;
            obj->t->e[i].a[j] = obj->t->e[i].a[j - 1];
            obj->t->e[i].b[j] = obj->t->e[i].b[j - 1];
        }
    } else {
        for (j = from; j < at; j++) {
            obj->t->e[i].a[*obj->t->e[i].cnt + 4] = j << 16;
            obj->t->e[i].a[j] = obj->t->e[i].a[j + 1];
            obj->t->e[i].b[j] = obj->t->e[i].b[j + 1];
        }
    }
    obj->t->e[i].a[*obj->t->e[i].cnt + 4] = j << 16;
    obj->t->e[i].a[at] = a;
    obj->t->e[i].b[at] = b;
    obj->t->e[i].a[*obj->t->e[i].cnt + 1] = *obj->t->e[i].mark << 16;
    obj->t->e[i].a[*obj->t->e[i].cnt + 5] = 0;
    return 0;
}
