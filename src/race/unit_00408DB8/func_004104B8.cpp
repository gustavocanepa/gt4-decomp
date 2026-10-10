extern "C" int DRIVERSUPPORT_NAME__GetMotoristDynamicParameter(void);
extern "C" float func_0044FAE0(int param);

extern "C" float func_004104B8(int side, int kind, float x, float y, float level, float rate) {
    float v = x;
    int again;
    if (kind >= 14) v = y;
    do {
        again = 0;
        if (0.0f < v) {
            switch (kind) {
            case 3: case 4: case 16: case 17: case 29: case 30:
                if (0.25f < level) level -= func_0044FAE0(DRIVERSUPPORT_NAME__GetMotoristDynamicParameter()) * rate;
                break;
            case 8: case 9: case 21: case 22: case 34: case 35:
                if (v < 0.95f) {
                    if (0.0f < level) level -= func_0044FAE0(DRIVERSUPPORT_NAME__GetMotoristDynamicParameter()) * rate;
                } else {
                    v = 0.0f;
                    again = 1;
                }
                break;
            case 0: case 1: case 2: case 14: case 15: case 27: case 28:
                v = 0.0f;
                again = 1;
                break;
            case 5: case 6: case 7: case 18: case 19: case 20: case 31: case 32: case 33:
                if (level < 1.0f) level += func_0044FAE0(DRIVERSUPPORT_NAME__GetMotoristDynamicParameter()) * rate;
                break;
            }
        } else {
            switch (side) {
            case 0:
                if (level < 1.0f) level += func_0044FAE0(DRIVERSUPPORT_NAME__GetMotoristDynamicParameter()) * rate;
                break;
            case 1 ... 8:
                if (0.0f < level) level -= func_0044FAE0(DRIVERSUPPORT_NAME__GetMotoristDynamicParameter()) * rate;
                break;
            }
        }
    } while (again);
    if (level < 0.0f) level = 0.0f;
    else if (1.0f < level) level = 1.0f;
    return level;
}
