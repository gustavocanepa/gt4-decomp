template <class T> inline const T &tmin(const T &a, const T &b) { return b < a ? b : a; }
template <class T> inline const T &tmax(const T &a, const T &b) { return a < b ? b : a; }

extern "C" int func_00578B50(unsigned int mode, int c) {
    /* Three function-scope slots (sp+0, 4, 8) shared by every case; their roles differ per case. */
    int x, y, z;
    switch (mode) {
    case 0:
        return 1;
    case 5:
        c++;
    case 3:
        x = c + 13; y = 2; z = 23;
        return tmin(tmax(x, y), z);
    case 4:
        z = c + 24; y = 24; x = 31;
        return tmin(tmax(z, y), x);
    default:
    case 1:
        z = c + 64; y = 32; x = 95;
        return tmin(tmax(z, y), x);
    case 2:
        z = c + 112; y = 96; x = 126;
        return tmin(tmax(z, y), x);
    }
}
