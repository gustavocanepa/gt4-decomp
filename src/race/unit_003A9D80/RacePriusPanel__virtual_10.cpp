struct Obj;

extern "C" void RacePriusHybridDisplay__virtual_10(Obj *arg0);

extern "C" void RacePriusPanel__virtual_10(char *arg0) {
    RacePriusHybridDisplay__virtual_10((Obj *)(arg0 + 0x150));
}
