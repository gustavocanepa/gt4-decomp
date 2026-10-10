typedef int s32;

struct S00323CD8 {
    char pad0[0x8];
    s32 unk8;
};

extern "C" s32 HSymID__GetName(s32 arg0);

extern "C" void func_005F0E48(struct S00323CD8 *arg0) {
    HSymID__GetName(arg0->unk8);
}
