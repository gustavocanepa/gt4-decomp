typedef int s32;

struct S { char pad[0xB0]; s32 unkB0; };

extern "C" void RaceCourse__setSectionNumber(S *arg0, s32 arg1) {
    arg0->unkB0 = arg1;
}
