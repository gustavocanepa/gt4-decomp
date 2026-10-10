struct VEntry { short delta; short index; void *pfn; };
struct Obj { char pad[0x64]; VEntry *vptr; };
struct Target {
    char pad[0x64];
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
};

extern "C" char func_005C1F98[]; /* type_info function of the target class */
extern "C" char func_005C24C8[]; /* type_info function of the static class */
/* __dynamic_cast (old ABI): from, to, require_public, address, sub, subptr */
extern "C" void *func_005C0FC8(void *from, void *to, int require_public, void *address, void *sub, void *subptr);
extern "C" void func_005C1B98(void) __attribute__((noreturn)); /* __throw_bad_cast */

/* dynamic_cast<Derived &>(*obj) followed by a virtual call through slot 12. */
extern "C" void func_00100EE0(Obj *obj)
{
    Target *d = (Target *)func_005C0FC8(obj->vptr[0].pfn, func_005C1F98, 0, (char *)obj + obj->vptr[0].delta,
                                  func_005C24C8, obj);
    if (!d)
        func_005C1B98();
    d->v11();
}
