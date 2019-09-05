#include "stdafx.h"


#include "Utils.h"



TFILEITEM::TFILEITEM()
{
    this->pPrev = this;
    this->pNext = this;
    this->pParent = NULL;
    this->pChilds = NULL;
    this->dwChildsCount = 0;
    this->dwFlag = ITEMFLAG_DEFAULT;
    this->dwLevel = 0;
    //this->strName;
    this->pAlign = NULL;
}

TFILEITEM::TFILEITEM(const CString& strName, BOOL bDir)
{
    this->pPrev = this;
    this->pNext = this;
    this->pParent = NULL;
    this->pChilds = NULL;
    this->dwChildsCount = 0;
    this->dwFlag = (bDir?ITEMFLAG_DIR:ITEMFLAG_DEFAULT);
    this->dwLevel = 0;
    this->strName = strName;
    this->pAlign = NULL;
}

CString TFILEITEM::GetFullPath()
{
    CString strPath = this->strName;
    TFILEITEM* pParent = this->pParent;
    while (pParent) {
        strPath = pParent->strName + _T("\\") + strPath;
    }

    return strPath;
}

TFILEITEM* TFILEITEM::AppendChild(TFILEITEM* pItem)
{
    ASSERT((NULL != pItem));
    pItem->dwLevel = this->dwLevel + 1;

    if (NULL == this->pChilds) {
        this->pChilds = pItem;
    } else {
        pItem->pPrev = this->pChilds->pPrev;
        pItem->pNext = this->pChilds;
        this->pChilds->pPrev->pNext = pItem;
        this->pChilds->pPrev = pItem;
        this->dwChildsCount++;
    }

    pItem->pParent = this;
    return pItem;
}



void TFILEITEM::ScanChilds(DWORD dwMaxDeep)
{
    //  �޷�����������
    if (dwMaxDeep == 0) {
        return;
    }

    //  ��������Լ������룬����Ҫ�Ա������ɨ��
    CFileFind fd;
    CString strPattern = this->GetFullPath() + "\\*";
    BOOL bFound = fd.FindFile(strPattern);
    while (bFound) {
        bFound = fd.FindNextFile();
        if (fd.IsDots()) {
            continue;
        }

        TFILEITEM* pItem = this->AppendChild(new TFILEITEM(fd.GetFileName(), fd.IsDirectory()));
        ASSERT(NULL != pItem);
        if (fd.IsDirectory()) {
            if (dwMaxDeep > 1) {
                pItem->ScanChilds(dwMaxDeep - 1);
            }
        }
    }
}

TFILEITEM* TFILEITEM::GetItem(DWORD index)
{
    if (0 == index) {
        return this;
    }

    TFILEITEM* pItem = this;
    DWORD dwPos = 0;
    while (dwPos < index) {

        //  ������ӽڵ㣬��ô��������ӽڵ�
        if (pItem->dwChildsCount > 0) {
            pItem = pItem->pChilds;
            dwPos++;
            continue;
        }

        //  ���pItem�Ѿ� ���һ��Ԫ���ˣ���ô���˵����׽ڵ�
        while ((pItem != this) && (pItem->pNext == pItem->pParent->pChilds)) {
            pItem = pItem->pParent;
        }

        //  ������˵������˵��ɨ�������
        if (pItem == this) {
            return NULL;
        }

        //  �����������֮�󣬽ڵ���Ч�����Ҳ��Ǹ��ڵ�����һ���ڵ㣬��ô�α�ָ�����һ���ڵ�
        pItem = pItem->pNext;
        dwPos++;
    }

    return pItem;
}

DWORD       TFILEITEM::GetTotal()
{
    DWORD dwTotal = 1;  //  �Լ�Ҳ��������
    TFILEITEM* pItem = this;
    DWORD dwPos = 0;
    while (NULL != pItem) {

        //  ������ӽڵ㣬��ô��������ӽڵ�
        if (pItem->dwChildsCount > 0) {
            dwTotal += pItem->dwChildsCount;
            pItem = pItem->pChilds;
            continue;
        }
        
        //  ���pItem�Ѿ� ���һ��Ԫ���ˣ���ô���˵����׽ڵ�
        while ((pItem != this) && (pItem->pNext == pItem->pParent->pChilds)) {
            pItem = pItem->pParent;
        }

        if (pItem == this) {
            return dwTotal;
        }

        //  �����������֮�󣬽ڵ���Ч�����Ҳ��Ǹ��ڵ�����һ���ڵ㣬��ô�α�ָ�����һ���ڵ�
        pItem = pItem->pNext;
    }

    return dwTotal;
}



CString CPathUtils::DirName(const CString& path)
{
    int pos = path.ReverseFind(_T('\\'));
    if (pos < 0) {
        pos = path.ReverseFind(_T('/'));
        if (pos < 0) {
            return path;
        }
    }

    return path.Left(pos);
}
 
CString CPathUtils::BaseName(const CString& path)
{
    int pos = path.ReverseFind(_T('\\'));
    if (pos < 0) {
        pos = path.ReverseFind(_T('/'));
        if (pos < 0) {
            return path;
        }
    }

    return path.Mid(pos + 1);
}

