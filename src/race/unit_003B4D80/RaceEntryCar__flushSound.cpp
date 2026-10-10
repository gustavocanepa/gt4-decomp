typedef int s32;
typedef unsigned char u8;

struct Obj003B4EE8 {
    u8 pad[0x28FC];
    s32 unk28FC;
};

extern "C" void RaceCarSound__playStop(char *arg0, s32 arg1);

extern "C" void RaceEntryCar__flushSound(struct Obj003B4EE8 *arg0) {
    RaceCarSound__playStop((char *)arg0 + 0x2900, 0);
    arg0->unk28FC = 0;
}
