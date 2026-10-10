struct Obj;

extern "C" void RaceCarSound__playStart(Obj *arg0);

extern "C" void func_005FAE30(char *arg0) {
    RaceCarSound__playStart((Obj *)(arg0 + 0x2900));
}
