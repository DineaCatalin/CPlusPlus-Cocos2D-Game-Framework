class MemoryPool
{
    unsigned char** m_ppRawMemoryArray;  // an array of memory blocks, each split up into chunks and connected
    unsigned char* m_pHead;  // the front of the memory chunk linked list
    unsigned int m_chunkSize, m_numChunks;  // the size of each chunk and number of chunks per array, respectively
    unsigned int m_memArraySize;  // the number elements in the memory array
    bool m_toAllowResize;  // true if we resize the memory pool when it fills up
    
    // tracking variables we only care about for debug
#ifdef _DEBUG
    std::string m_debugName;
    unsigned long m_allocPeak, m_numAllocs;
#endif
    
public:
    // construction
    MemoryPool(void);
    ~MemoryPool(void);
    bool Init(unsigned int chunkSize, unsigned int numChunks);
    void Destroy(void);
    
    // allocation functions
    void* Alloc(void);
    void Free(void* pMem);
    unsigned int GetChunkSize(void) const { return m_chunkSize; }
    
    // settings
    void SetAllowResize(bool toAllowResize) { m_toAllowResize = toAllowResize; }
    
    // debug functions
#ifdef _DEBUG
    void SetDebugName(const char* debugName) { m_debugName = debugName; }
    std::string GetDebugName(void) const { return m_debugName; }
#else
    void SetDebugName(const char* debugName) { }
    //std::string GetDebugName(void) const { return (std::string("<No Name>")); }
    const char* GetDebugName(void) const { return "<No Name>"; }
#endif
    
private:
    // resets internal vars
    void Reset(void);
    
    // internal memory allocation helpers
    bool GrowMemoryArray(void);
    unsigned char* AllocateNewMemoryBlock(void);
    
    // internal linked list management
    unsigned char* GetNext(unsigned char* pBlock);
    void SetNext(unsigned char* pBlockToChange, unsigned char* pNewNext);
    
    // don't allow copy constructor
    MemoryPool(const MemoryPool& memPool) {}
};
