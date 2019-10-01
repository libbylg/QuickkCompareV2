#ifndef __Utils_H_
#define __Utils_H_


enum EITEMFLAG
{
    ITEMFLAG_VISIBLE    = 0x00000001,
    ITEMFLAG_DIR        = 0x00000002,

    ITEMFLAG_DEFAULT    = 0x00000000,
};


struct FileDesc
{
    CString     strName;
    LONGLONG    llSize;
    FILETIME    tLastModifyTime;
    FileDesc()
    {
        this->llSize = 0;
        this->tLastModifyTime.dwHighDateTime = 0;
        this->tLastModifyTime.dwLowDateTime = 0;
    }
    FileDesc(const CString& strName, LONGLONG llSize, FILETIME tLastModifyTime)
    {
        this->strName = strName;
        this->llSize = llSize;
        this->tLastModifyTime = tLastModifyTime;
    }
};

struct CompareNode
{
    CompareNode*    pPrev;
    CompareNode*    pNext;
    CompareNode*    pParent;        //  父节点
    CompareNode*    pChilds;        //  子节点
    DWORD           dwChildsCount;  //  子节点的个数
    DWORD           dwFlag;         //  选项
    DWORD           dwLevel;        //  层级
    CompareNode*    pAlign;         //  与那一项对齐
    FileDesc        tDescs[2];    //  当有多个视图时，会存在多个名称

    CompareNode();
    CString         GetFullPath(int iSide);
    CompareNode*    AppendChild(CompareNode* pItem);
    void            ScanChilds(DWORD dwMaxDeep, int iSide);
    CompareNode*    GetItem(DWORD index);
    DWORD           GetTotal();
};

struct CPathUtils
{
    static CString DirName(const CString& path);
    static CString BaseName(const CString& path);
};



#endif//__Utils_H_

