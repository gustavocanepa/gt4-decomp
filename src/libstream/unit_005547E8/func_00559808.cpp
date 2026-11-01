/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Under the pool lock, takes the first free playback pool entry (state 0): marks it 1, sets it up
   with func_005593F8 and returns it (0 when all 24 are busy). As in func_005596F8 the state is read
   through the global array and the entry through a local; func_005593F8 is declared throw(). */
typedef int s32;
struct VoiceSlot { void *voice; char unknown04[0x14]; };
struct PlaybackPoolEntry { VoiceSlot voices[2]; char unknown30[0x24]; s32 state; };
extern char D_00655340[];
extern PlaybackPoolEntry D_0064FBF8[24];
extern "C" void func_00576100(void *section);
extern "C" void func_00576140(void *section);
extern "C" void func_005593F8(PlaybackPoolEntry *e, s32 flags) throw();
extern "C" PlaybackPoolEntry *func_00559808(void) {
    PlaybackPoolEntry *pool = D_0064FBF8;
    PlaybackPoolEntry *e = 0;
    func_00576100(D_00655340);
    for (s32 i = 0; i < 24; i++) {
        if (D_0064FBF8[i].state == 0) {
            e = &pool[i];
            D_0064FBF8[i].state = 1;
            func_005593F8(e, 0);
            break;
        }
    }
    func_00576140(D_00655340);
    return e;
}
