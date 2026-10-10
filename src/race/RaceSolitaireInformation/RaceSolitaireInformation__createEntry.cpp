typedef int s32;

extern "C" void RaceSolitaireEntry__structor_0(void *arg0);
extern "C" void *exception__structor_0(s32 arg0);

extern "C" void *RaceSolitaireInformation__createEntry(void) {
    void *s0 = exception__structor_0(0x5C);
    RaceSolitaireEntry__structor_0(s0);
    return s0;
}
