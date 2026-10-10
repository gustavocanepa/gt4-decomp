struct S00387E10 {
    char pad[0xD34];
    float unkD34;
};

extern "C" void RaceBase__enableInputIdle(S00387E10 *arg0) {
    arg0->unkD34 = 0.016666666f;
}
