typedef int s32;
struct Entry { char label[64]; float score; };
extern "C" s32 func_00130618(Entry *entries, s32 low, s32 high, float score) {
    s32 middle = (low + high) / 2;
    if (middle == low) return middle;
    if (entries[middle].score < score) return func_00130618(entries, low, middle, score);
    return func_00130618(entries, middle, high, score);
}
