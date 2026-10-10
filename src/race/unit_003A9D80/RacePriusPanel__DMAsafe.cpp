struct Obj;

extern "C" void RacePriusHybridDisplay__DMAsafe(Obj *arg0);

extern "C" void RacePriusPanel__DMAsafe(char *arg0) {
    RacePriusHybridDisplay__DMAsafe((Obj *)(arg0 + 0x150));
}
