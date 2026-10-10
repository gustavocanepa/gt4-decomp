unsigned DynamicsConductor__CurrentLapTime_Normal(char *a, char *b) {
    unsigned y = *(unsigned *)(b + 0x718);
    return *(unsigned *)(a + 0xF898) / 3 - y;
}
