
typedef struct Obj {
    char pad[0x14];
    void *vtable;
    short name[6];
    char pad2[4];
    int m28;
    unsigned int m2C;
} Obj;

extern char D_0067FA08[];
extern Obj *func_003AEBA8(Obj *o);
extern void func_003A3F80(Obj *o);
extern char *strcpy(char *dst, const char *src);

void func_003A3F10(Obj *o)
{
    func_003AEBA8(o);
    o->vtable = D_0067FA08;
    o->m2C = 0x80E3B896;
    o->m28 = 0;
    strcpy((char *)o->name, "GT4meter#1");
    func_003A3F80(o);
}
