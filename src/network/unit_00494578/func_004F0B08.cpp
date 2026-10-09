/* Clears the field at +0x39A0 when name is null or equals the string at +0x3984; returns whether it did. */
typedef int s32;

struct Obj {
    char pad0[0x3984];
    char name[0x1C];
    s32 unk39A0;
};

extern "C" s32 func_0057F238(const char *a, const char *b); /* strcmp */

extern "C" s32 func_004F0B08(Obj *self, const char *name)
{
    if (name == 0 || func_0057F238(name, self->name) == 0) {
        self->unk39A0 = 0;
        return 1;
    }
    return 0;
}
