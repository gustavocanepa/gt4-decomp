struct Units {
    int metric;
};

extern "C" int func_00472CC8(const Units *u, int value, int unit) {
    if (u->metric == 0) {
        if (unit == 0)
            return value;
        return (int)((float)value * 0x1.9be76cp+0f + 0.5f);
    }
    if (unit == 1)
        return value;
    return (int)((float)value * 0x1.3e26d4p-1f + 0.5f);
}
