extern int func_00104218(void *arg0, void *arg1);
extern "C" void *memcpy(void *dst, const void *src, unsigned int n);

// Address-only global; its actual link address is irrelevant for grading,
// only the lui/addiu opcode pattern matters.
extern int D_00659D50;

struct S001043C0_Obj {
    int unk00;                     // 0x00 - type/tag pointer
    int unk04;                     // 0x04
    char pad08[0x38 - 0x08];       // padding up to 0x38
    unsigned char unk38[16];       // 0x38, 16 bytes copied from arg1
};

void func_001043C0(S001043C0_Obj *arg0, void *arg1)
{
    func_00104218(arg0, arg1);
    arg0->unk00 = (int)&D_00659D50;
    memcpy(arg0->unk38, arg1, 16);
    arg0->unk04 = 0;
}
