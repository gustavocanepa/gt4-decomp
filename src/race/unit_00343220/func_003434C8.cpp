extern "C" int PDISTD__UNIT_MANAGER;
extern "C" unsigned int func_003434C8(const unsigned int *ticks) {
    unsigned int v = ticks[0] / (PDISTD__UNIT_MANAGER != 1 ? 100u : 160u);
    return v < 1000000000 ? v : 999999999;
}
