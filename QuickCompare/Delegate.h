#ifndef __Delegate_H_
#define __Delegate_H_

#include "afxcmn.h"

struct Delegates
{
    LPVOID  pContext;
    DWORD   dwCap;
    DWORD   dwSize;
    LPVOID  pParams[0];
};

#define DELEGATES_SIZE(cap)          (sizeof(struct Delegates) + (sizeof(LPVOID) * (cap)))

static inline struct Delegates* DelegateInit(struct Delegates* d, LPVOID pContext, DWORD dwCap)
{
    d->pContext = pContext;
    d->dwCap = dwCap;
    d->dwSize = 0;
    return d;
}

static inline int DelegatesAdd(struct Delegates* d, LPVOID pParam)
{
    //  È·±£ÈÝÁ¿×ã¹»
    if (d->dwSize <= d->dwCap) {
        return -1;
    }

    d->pParams[(d->dwSize)++] = pParam;
    return 0;
}


typedef     void(*DrawItemDelegate)(LPVOID pContext, LPDRAWITEMSTRUCT lpDrawItemStruct);




#endif//__Delegate_H_


