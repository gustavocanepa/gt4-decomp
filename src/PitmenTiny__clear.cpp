/* compiler: ee-gcc2.96-as2004 */
struct PitmenTiny {
    struct Team { char pad[0x320]; void clear(); };
    Team mTeam[6];
    int mSel[2];
    int mA;
    int mB;
    void clear();
};

void PitmenTiny::clear() {
    int i;
    for (i = 0; i < 2; i++) mSel[i] = -1;
    for (i = 0; i < 6; i++) mTeam[i].clear();
    mA = 0;
    mB = 0;
}
