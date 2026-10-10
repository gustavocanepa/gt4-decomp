struct Vec4;

extern "C" Vec4 *func_002030E8(Vec4 *arg0, Vec4 *arg1);

extern "C" void mTextBoxFace__setColor(char *arg0, Vec4 *arg1) {
    func_002030E8((Vec4 *)(arg0 + 0xC0), arg1);
}
