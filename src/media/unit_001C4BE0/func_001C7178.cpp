typedef int s32;

struct Elem_001C7178 {
    char pad0[0x10];
    s32 unk10;
};

struct Obj_001C7178 {
    char pad0[0xBC8];
    s32 unkBC8;
};

extern "C" void func_001C7178(struct Obj_001C7178 *arg0) {
    struct Obj_001C7178 *self = arg0;
    s32 temp_a2 = self->unkBC8;

    if (temp_a2 >= 0) {
        self->unkBC8 = -1;

        s32 off = temp_a2 * 0x2B8;
        off = off + 0x8F0;
        struct Elem_001C7178 *temp_v1 = (struct Elem_001C7178 *)((char *)self + off);
        temp_v1->unk10 = temp_v1->unk10 & ~0xFF;
    }
}
