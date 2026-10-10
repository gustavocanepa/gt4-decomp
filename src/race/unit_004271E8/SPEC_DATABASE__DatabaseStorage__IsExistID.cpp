extern "C" int SPEC_DATABASE__DatabaseStorage__IsExistID_2(int a, int b, int c);

extern "C" int SPEC_DATABASE__DatabaseStorage__IsExistID(int a, long b) {
    return SPEC_DATABASE__DatabaseStorage__IsExistID_2(a, (int)(b & 0xFFFFFFFF), (int)(b >> 32));
}
