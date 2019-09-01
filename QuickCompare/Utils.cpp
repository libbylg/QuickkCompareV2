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
    pItem->dwLevel = pParent->dwLevel + 1;

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
    BOOL bFound = fd.FindFile(this->GetFullPath() + "/*");
    while (bFound) {
        bFound = fd.FindNextFile();
        if (fd.IsDots()) {
            continue;
        }

        TFILEITEM* pItem = this->AppendChild(new TFILEITEM(fd.GetFileName(), fd.IsDirectory()));
        if (dwMaxDeep > 1) {
            pItem->ScanChilds(dwMaxDeep - 1);
        }
    }
}
