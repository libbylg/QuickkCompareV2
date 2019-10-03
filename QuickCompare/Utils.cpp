#include "stdafx.h"


#include "Utils.h"



CompareNode::CompareNode()
{
    this->pPrev = this;
    this->pNext = this;
    this->pParent = NULL;
    this->pChilds = NULL;
    this->dwChildsCount = 0;
    this->dwFlag = ITEMFLAG_DEFAULT;
    this->dwLevel = 0;
    //this->tItems;
    this->pAlign = NULL;
}

//CompareNode::CompareNode(BOOL bDir, const CString& strLeft, const CString& strRight)
//{
//    this->pPrev = this;
//    this->pNext = this;
//    this->pParent = NULL;
//    this->pChilds = NULL;
//    this->dwChildsCount = 0;
//    this->dwFlag = (bDir?ITEMFLAG_DIR:ITEMFLAG_DEFAULT);
//    this->dwLevel = 0;
//    this->strNames[0] = strLeft;
//    this->strNames[1] = strRight;
//    this->pAlign = NULL;
//}

CString CompareNode::GetFullPath(int iSide)
{
    CString strPath = this->tDescs[iSide].strName;
    CompareNode* pParent = this->pParent;
    while (pParent) {
        strPath = pParent->tDescs[iSide].strName + _T("\\") + strPath;
        pParent = pParent->pParent;
    }

    return strPath;
}

CompareNode* CompareNode::AppendChild(CompareNode* pItem)
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



void CompareNode::ScanChilds(DWORD dwMaxDeep, int iSide)
{
    //  �޷�����������
    if (dwMaxDeep == 0) {
        return;
    }

    //  ��������Լ������룬����Ҫ�Ա������ɨ��
    CFileFind fd;
    CString strPattern = this->GetFullPath(iSide) + "\\*";
    BOOL bFound = fd.FindFile(strPattern);
    while (bFound) {
        bFound = fd.FindNextFile();
        if (fd.IsDots()) {
            continue;
        }


        CompareNode* pNode = new CompareNode();

        FileDesc tDesc;
        tDesc.strName = fd.GetFileName();
        fd.GetLastWriteTime(&(tDesc.tLastModifyTime));
        tDesc.llSize = fd.GetLength();
        
        pNode->tDescs[0] = tDesc;
        
        CompareNode* pItem = this->AppendChild(pNode);
        ASSERT(NULL != pItem);
        if (fd.IsDirectory()) {
            if (dwMaxDeep > 1) {
                pItem->ScanChilds(dwMaxDeep - 1, iSide);
            }
        }
    }
}


CompareNode* CompareNode::GetItem(DWORD index)
{
    if (0 == index) {
        return this;
    }

    CompareNode* pItem = this;
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

DWORD       CompareNode::GetTotal()
{
    DWORD dwTotal = 1;  //  �Լ�Ҳ��������
    CompareNode* pItem = this;
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

