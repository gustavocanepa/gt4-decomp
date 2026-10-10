/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Elem {
    int m0;
    float m4, m8, mC;
    char pad[0x94 - 0x10];
    float m94;
    char pad2[0xA0 - 0x98];
};
struct Table {
    char pad[0x20];
    Elem e[1];
};
struct Owner {
    char pad[0x10];
    int count;
};
extern Table *D_006D6054;
extern Elem D_00621A48;

extern "C" void func_003E4EB8(Owner *o)
{
    Elem *src = &D_00621A48;
    for (int i = 0; i < o->count + 1; i++) {
        Elem *e = &D_006D6054->e[i];
        e->m4 = src->m4;
        e->m8 = src->m8;
        e->mC = src->mC;
        e->m94 = src->m94;
    }
}
