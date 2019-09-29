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
    TFILEITEM*  pParent;        //  ���ڵ�
    TFILEITEM*  pChilds;        //  �ӽڵ�
    DWORD       dwChildsCount;  //  �ӽڵ�ĸ���
    DWORD       dwFlag;         //  ѡ��
    DWORD       dwLevel;        //  �㼶
    //CString     strName;        //  ����
    TFILEITEM*  pAlign;         //  ����һ�����
    CString     strNames[2];    //  ���ж����ͼʱ������ڶ������

    TFILEITEM();
    TFILEITEM(const CString& strName, BOOL bDir);
    CString     GetFullPath(int iSide);
    TFILEITEM*  AppendChild(TFILEITEM* pItem);
    void        ScanChilds(DWORD dwMaxDeep, int iSide);
    TFILEITEM*  GetItem(DWORD index);
    DWORD       GetTotal();
};

struct CPathUtils
{
    static CString DirName(const CString& path);
    static CString BaseName(const CString& path);
};



#endif//__Utils_H_

