extern "C" int D_006244D8;
extern "C" unsigned int func_003434C8(const unsigned int *ticks) {
    unsigned int v = ticks[0] / (D_006244D8 != 1 ? 100u : 160u);
    return v < 1000000000 ? v : 999999999;
}
