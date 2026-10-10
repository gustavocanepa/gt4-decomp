typedef int s32;

struct Obj { char pad[0x98]; s32 unk98; };

extern "C" s32 mWidget__canDefault(Obj *arg0) {
    return (arg0->unk98 >> 17) & 1;
}
