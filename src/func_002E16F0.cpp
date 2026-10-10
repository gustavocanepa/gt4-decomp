struct Base0 {
    int m0;
};
/* hObject: its constructor is func_0030A678 */
struct func_0030A678 : Base0 {
    func_0030A678();
    virtual ~func_0030A678();
};
struct Data {
    long w[0xA8 / 8];
};
struct mStorageEntry : func_0030A678 {
    int m8;
    int mC;
    Data data;
    mStorageEntry(const Data &d);
    virtual ~mStorageEntry();
};

mStorageEntry::mStorageEntry(const Data &d) : data(d) {}
