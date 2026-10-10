struct Step {
    float limit;
    int id;
};

extern Step D_00621270[];
extern Step D_00621290[];

extern "C" int func_0037D5B0(int mode, float *rate, float x) {
    Step *s = D_00621270;
    if (mode)
        s = D_00621290;
    *rate = 0.0f;
    if (x < *rate)
        return s->id;
    for (;; s++) {
        if (s->limit < *rate)
            return s->id;
        if (x < s->limit) {
            *rate = 1.0f / 60.0f;
            return s->id;
        }
    }
}
