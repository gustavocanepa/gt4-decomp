struct Base0 {
    int m0;
};
/* hObject: its constructor is hObject__structor_0 */
struct hObject__structor_0 : Base0 {
    hObject__structor_0();
    virtual ~hObject__structor_0();
};
struct Data {
    long w[0xA8 / 8];
};
struct mStorageEntry : hObject__structor_0 {
    int m8;
    int mC;
    Data data;
    mStorageEntry(const Data &d);
    virtual ~mStorageEntry();
};

mStorageEntry::mStorageEntry(const Data &d) : data(d) {}
