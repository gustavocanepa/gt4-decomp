/* compiler: ee-gcc2.96-no-strict-aliasing */
/* mStringConst(const String &s): RefCounter base, vptr, then the string member copy-constructed
   (basic_string's inline grab(): clone when selfish, else ++ref). The base constructor returns
   `this` (gcc 2.x constructors do): declared void it changes the register homes here. */
typedef int s32;

extern "C" char *func_005C2560(void *rep);

struct Rep {
    s32 len;
    s32 res;
    s32 ref;
    s32 selfish;

    char *data() { return (char *)(this + 1); }
    char *clone() { return func_005C2560(this); }
    char *grab()
    {
        if (selfish)
            return clone();
        ++ref;
        return data();
    }
};

struct String {
    char *dat;
    Rep *rep() const { return ((Rep *)dat) - 1; }
};

static inline String *String_copy(String *self, const String &str)
{
    self->dat = str.rep()->grab();
    return self;
}

extern "C" void *hObject__structor_0(void *self);
extern "C" char hException__vtable[];

struct mStringConst {
    s32 count;
    void *vtbl;
    char pad8[8];
    String str;
};

extern "C" void hException__structor_0(mStringConst *self, const String *s)
{
    hObject__structor_0(self);
    self->vtbl = hException__vtable;
    String_copy(&self->str, *s);
}
