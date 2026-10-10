typedef unsigned int u32;
typedef unsigned char u8;

struct Obj {
    char pad[0x168];
    u8 ids[2];
};

extern u8 D_00620300[];

extern "C" void func_0034AB80(Obj *self) {
    u32 i;
    for (i = 0; i < 2; i++)
        self->ids[i] = self->ids[i] < 8 ? D_00620300[self->ids[i]] : self->ids[i];
}
