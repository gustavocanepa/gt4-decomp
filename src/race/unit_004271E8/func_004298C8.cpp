typedef unsigned short u16;
typedef int s32;

struct Entry {
    char pad[2];
    u16 unk2;
    char pad2[0xC];
};

struct Obj {
    char pad[0x10];
    Entry *unk10;
};

extern "C" u16 func_004298C8(Obj *arg0, s32 arg1) {
    Entry *ptr = arg0->unk10 + arg1;
    return ptr->unk2;
}
