/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
union Slot { int w; struct { u16 lo, hi; }; };
struct Data { u16 *second; u16 *count; u16 *zero; };
struct E { int head; int enabled; char pad[20]; Slot *first; Data data; };
struct Obj { E elems[1]; };
extern "C" int func_004C14A0(Obj *obj, int i, int mode) {
    int n = 0;
    u16 mark;
    if (obj->elems[i].enabled) {
        u16 k = *obj->elems[i].data.count;
        if (obj->elems[i].first[k + 5].hi != 0) {
            u16 savedSecond = obj->elems[i].data.second[k];
            int saved = obj->elems[i].first[k].w;
            u16 to;
            u16 from;
            mark = obj->elems[i].first[k + 2].hi;
            to = obj->elems[i].first[k + 3].hi;
            from = obj->elems[i].first[k + 4].hi;
            if (mode == 0) {
                n = 1;
            } else {
                u16 j;
                if (to < from) {
                    for (j = from; to < j; j--) {
                        obj->elems[i].first[j].w = obj->elems[i].first[j - 1].w;
                        obj->elems[i].data.second[j] = obj->elems[i].data.second[j - 1];
                        n++;
                    }
                } else {
                    for (j = from; j < to; j++) {
                        obj->elems[i].first[j].w = obj->elems[i].first[j + 1].w;
                        obj->elems[i].data.second[j] = obj->elems[i].data.second[j + 1];
                        n++;
                    }
                }
                n++;
                obj->elems[i].first[j].w = saved;
                obj->elems[i].data.second[j] = savedSecond;
            }
            if (mode == 1) {
                *obj->elems[i].data.zero = mark;
                obj->elems[i].first[*obj->elems[i].data.count + 5].w = 0;
            }
        } else {
            mark = obj->elems[i].first[k + 1].hi;
            *obj->elems[i].data.zero = mark;
        }
    }
    return n;
}
