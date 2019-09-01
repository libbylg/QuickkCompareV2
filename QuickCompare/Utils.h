#ifndef __Utils_H_
#define __Utils_H_


enum EITEMFLAG
{
    ITEMFLAG_VISIBLE    = 0x00000001,
    ITEMFLAG_DIR        = 0x00000002,

    ITEMFLAG_DEFAULT    = 0x00000000,
};

struct TFILEITEM
{
    TFILEITEM*  pPrev;
    TFILEITEM*  pNext;
    TFILEITEM*  pParent;        //  父节点
    TFILEITEM*  pChilds;        //  子节点
    DWORD       dwChildsCount;  //  子节点的个数
    DWORD       dwFlag;         //  选项
    DWORD       dwLevel;        //  层级
    CString     strName;        //  名字
    TFILEITEM*  pAlign;         //  与那一项对齐

    TFILEITEM();
    TFILEITEM(const CString& strName, BOOL bDir);
    CString     GetFullPath();
    TFILEITEM*  AppendChild(TFILEITEM* pItem);
    void        ScanChilds(DWORD dwMaxDeep);
};



#endif//__Utils_H_

