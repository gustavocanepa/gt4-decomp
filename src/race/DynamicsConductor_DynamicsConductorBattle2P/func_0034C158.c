extern unsigned DynamicsConductor__getLimitTime(void);
int func_0034C158(int x, unsigned i) {
    unsigned n = DynamicsConductor__getLimitTime();
    return n != 0 && i >= n;
}
