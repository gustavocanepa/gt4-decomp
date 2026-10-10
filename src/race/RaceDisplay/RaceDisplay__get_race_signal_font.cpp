typedef unsigned int u32;

struct Obj {
    char pad[0x1C];
    int unk1C;
};

extern "C" const char *RaceDisplay__get_race_signal_font(struct Obj *arg0) {
    if ((u32)(arg0->unk1C - 8) < 2) {
        return "FC_48*75,75";
    }
    return "FC_48";
}
