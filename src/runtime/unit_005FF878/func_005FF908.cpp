struct Cfg {
    char pad[0x120];
    int mode;
};

extern "C" int func_005FF908(int *flag, Cfg *cfg) {
    if ((cfg->mode == 1 && *flag == 0) || (cfg->mode == 2 && *flag != 0)) {
        return 1;
    }
    return 0;
}
