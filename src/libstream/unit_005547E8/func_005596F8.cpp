/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Under the pool lock (D_00655340), finishes every playback pool entry in state 2 with
   func_00558FD8. The byte offset and the countdown are the original's own variables (both set
   before the lock call); the state is read through the global array, the entry through a local. */
typedef int s32;
struct VoiceSlot { void *voice; char unknown04[0x14]; };
struct PlaybackPoolEntry { VoiceSlot voices[2]; char unknown30[0x24]; s32 state; };
extern char D_00655340[];
extern PlaybackPoolEntry D_0064FBF8[24];
extern "C" void func_00576100(void *section);
extern "C" void func_00576140(void *section);
extern "C" void func_00558FD8(PlaybackPoolEntry *e);
extern "C" void func_005596F8(void) {
    PlaybackPoolEntry *pool = D_0064FBF8;
    s32 off = 0;
    s32 i = 23;
    func_00576100(D_00655340);
    for (s32 j = 0; i >= 0; i--, j++) {
        if (D_0064FBF8[j].state == 2) func_00558FD8((PlaybackPoolEntry *)((char *)pool + off));
        off += 0x58;
    }
    func_00576140(D_00655340);
}
