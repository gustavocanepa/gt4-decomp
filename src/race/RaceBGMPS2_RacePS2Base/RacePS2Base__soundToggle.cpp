typedef int s32;

struct S { char pad[0x34]; s32 unk34; };

extern "C" void RacePS2Base__soundToggle(char *arg0) {
    S *temp_a0 = (S *)(arg0 + 0xCF88);
    temp_a0->unk34 = temp_a0->unk34 ^ 1;
}
