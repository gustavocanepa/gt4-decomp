typedef int s32;

struct Reader {
    char pad[0x4C];
    void *vtbl;
};

extern char D_006614F8[];
extern "C" void func_001CDA10(Reader *);
extern "C" s32 func_001CDF58(Reader *, void *);
extern "C" void func_001CC060(Reader *, s32);

/* A local object built, used and destroyed: the inlined destructor restores the class's vtable
   pointer and calls the base destructor (in_chrg 0). */
extern "C" s32 func_001CBB80(void *src) {
    Reader r;
    func_001CDA10(&r);
    s32 ok = func_001CDF58(&r, src);
    r.vtbl = D_006614F8;
    func_001CC060(&r, 0);
    return ok;
}
