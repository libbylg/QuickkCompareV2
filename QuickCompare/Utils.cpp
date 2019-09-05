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
    //  无法继续深入了
    if (dwMaxDeep == 0) {
        return;
    }

    //  如果还可以继续深入，才需要对本层进行扫描
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

        //  如果有子节点，那么深入查找子节点
        if (pItem->dwChildsCount > 0) {
            pItem = pItem->pChilds;
            dwPos++;
            continue;
        }

        //  如果pItem已经 最后一个元素了，那么回退到父亲节点
        while ((pItem != this) && (pItem->pNext == pItem->pParent->pChilds)) {
            pItem = pItem->pParent;
        }

        //  如果回退到顶点后，说明扫描结束了
        if (pItem == this) {
            return NULL;
        }

        //  如果连续回退之后，节点有效，而且不是父节点的最后一个节点，那么游标指向该下一个节点
        pItem = pItem->pNext;
        dwPos++;
    }

    return pItem;
}

DWORD       TFILEITEM::GetTotal()
{
    DWORD dwTotal = 1;  //  自己也计算在内
    TFILEITEM* pItem = this;
    DWORD dwPos = 0;
    while (NULL != pItem) {

        //  如果有子节点，那么深入查找子节点
        if (pItem->dwChildsCount > 0) {
            dwTotal += pItem->dwChildsCount;
            pItem = pItem->pChilds;
            continue;
        }
        
        //  如果pItem已经 最后一个元素了，那么回退到父亲节点
        while ((pItem != this) && (pItem->pNext == pItem->pParent->pChilds)) {
            pItem = pItem->pParent;
        }

        if (pItem == this) {
            return dwTotal;
        }

        //  如果连续回退之后，节点有效，而且不是父节点的最后一个节点，那么游标指向该下一个节点
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

