typedef unsigned char u8;
typedef int s32;

extern char D_0069DEB8[];

struct Obj {
    u8 pad[0x8];
    char *unk10;
};

extern "C" char *func_0030C460(Obj *arg0) {
    char **fieldPtr = &arg0->unk10;
    char *p = *fieldPtr;
    s32 len = *(s32 *)(p - 0x10);
    if (len == 0) {
        return D_0069DEB8;
    }
    p[len] = 0;
    return *fieldPtr;
}
