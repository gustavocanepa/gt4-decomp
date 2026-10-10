typedef int s32;

struct Obj {
    char pad[0x1AA0];
    s32 unk1AA0;
};

extern "C" void AutomobileControlRecord__Manager__save(s32 arg0, struct Obj *arg1, s32 arg2);

extern "C" void RaceLanBattle__virtual_57(s32 arg0, struct Obj *arg1) {
    arg1->unk1AA0 = 1;
    AutomobileControlRecord__Manager__save(arg0 + 0xF258, arg1, 1);
}
