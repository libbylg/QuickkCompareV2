#include "stdafx.h"

#include "CMemoryDC.h"

//析构函数，释放加载的位图资源
CMemoryDC::~CMemoryDC()  
{  
	DeleteDC();  
}
 
CMemoryDC::CMemoryDC()  
{  
	m_size.cx = m_size.cy = 0;  
} 
	
//在构造对象的同时，根据资源ID加载位图
CMemoryDC::CMemoryDC(UINT nBitmapID,CDC* pDC)  
{  
	LoadBitmap(nBitmapID,pDC);  
} 
 
//在构造对象的同时，从进程外，根据位图文件绝对路径名加载位图
CMemoryDC::CMemoryDC(LPCTSTR szBitmapFile,CDC* pDC)  
{  
	LoadBitmap(szBitmapFile,pDC);  
}
 
//在构造对象的同时，创建一块空白画布
CMemoryDC::CMemoryDC(int cx,int cy,CDC* pDC)  
{  
	Create(cx,cy,pDC);  
}  
 
//根据资源ID加载位图 
BOOL CMemoryDC::LoadBitmap(UINT nBitmapID,CDC* pDC)  
{  
	CBitmap bitmap;  
	bitmap.LoadBitmap(nBitmapID);  
	BITMAP bm;  
	bitmap.GetBitmap(&bm);  
	m_size.cx = bm.bmWidth;  
	m_size.cy = bm.bmHeight;  
	CreateCompatibleDC(pDC);  
	SelectObject(bitmap);  
	return TRUE;  
}  
 
//从进程外，根据位图文件绝对路径名加载位图
BOOL CMemoryDC::LoadBitmap(LPCTSTR szBitmapFile,CDC* pDC)  
{  
	HBITMAP hBitmap = (HBITMAP)LoadImage(AfxGetInstanceHandle(),  
		szBitmapFile,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);  
	BITMAP bm;  
	GetObject(hBitmap,sizeof(bm),&bm);  
	m_size.cx = bm.bmWidth;  
	m_size.cy = bm.bmHeight;  
	CreateCompatibleDC(pDC);  
	SelectObject(hBitmap);        
	return TRUE;  
} 
 
//绘制透明位图
void CMemoryDC::BitTrans(  
	int nXDest,     // 目标起点X  
	int nYDest,     // 目标起点Y  
	int nWidthDest, // 目标宽度  
	int nHeightDest,// 目标高度  
	CDC* pDC,       // 目标DC  
	int nXSrc,      // 来源起点X  
	int nYSrc,      // 来源起点Y  
	COLORREF crTrans// 透明色  
	)  
{  
	CMemoryDC dcImage(nWidthDest, nHeightDest,pDC);//临时DC  
	CBitmap bmpMask;  
	bmpMask.CreateBitmap(nWidthDest, nHeightDest, 1, 1, NULL);            // 创建单色掩码位图  
	CDC dcMask;//掩码DC   
	dcMask.CreateCompatibleDC(pDC);  
	dcMask.SelectObject(bmpMask);  
	//将载入位图的内存DC中的位图，拷贝到临时DC中  
	dcImage.BitBlt( 0, 0, nWidthDest, nHeightDest, this, nXSrc, nYSrc, SRCCOPY);  
 
	// 设置临时DC的透明色  
	dcImage.SetBkColor(crTrans);  
	//掩码DC的透明区域为白色其它区域为黑色  
	dcMask.BitBlt(0, 0, nWidthDest, nHeightDest, &dcImage, 0, 0, SRCCOPY);  
 
	//临时DC透明区域为黑色，其它区域保持不变  
	dcImage.SetBkColor(RGB(0,0,0));  
	dcImage.SetTextColor(RGB(255,255,255));  
	dcImage.BitBlt( 0, 0, nWidthDest, nHeightDest, &dcMask, 0, 0, SRCAND);  
 
	// 目标DC透明部分保持屏幕不变，其它部分变成黑色  
	pDC ->SetBkColor(RGB(255,255,255));  
	pDC ->SetTextColor(RGB(0,0,0));  
	pDC ->BitBlt(nXDest, nYDest, nWidthDest, nHeightDest, &dcMask, 0, 0, SRCAND);  
	pDC ->BitBlt(nXDest, nYDest, nWidthDest, nHeightDest, &dcImage, 0, 0, SRCPAINT);  
}   
 
//绘制具有可拉伸的透明位图
void CMemoryDC::StretchTrans(  
	int nXDest,         // 目标起点X  
	int nYDest,         // 目标起点Y  
	int nWidthDest,     // 目标宽度  
	int nHeightDest,    // 目标高度  
	CDC* pDC,           // 目标DC  
	int nXSrc,          // 来源起点X  
	int nYSrc,          // 来源起点Y  
	int nWidthSrc,      // 来源宽度  
	int nHeightSrc,     // 来源高度  
	COLORREF crTrans    // 透明色  
	)  
{  
	CMemoryDC dcImage(nWidthDest, nHeightDest,pDC);//临时DC  
	CBitmap bmpMask;  
	// 创建单色掩码位图  
	bmpMask.CreateBitmap(nWidthDest, nHeightDest, 1, 1, NULL);  
	CDC dcMask;  
	dcMask.CreateCompatibleDC(pDC);  
	dcMask.SelectObject(bmpMask);  
 
	// 将载入位图的内存DC中的位图，拷贝到临时DC中  
	if (nWidthDest == nWidthSrc && nHeightDest == nHeightSrc)  
		dcImage.BitBlt(0, 0, nWidthDest, nHeightDest, this, nXSrc, nYSrc, SRCCOPY);  
	else  
		dcImage.StretchBlt(0, 0, nWidthDest, nHeightDest,   
		this, nXSrc, nYSrc, nWidthSrc, nHeightSrc, SRCCOPY);  
 
	// 设置临时DC的透明色  
	dcImage.SetBkColor( crTrans);  
	//掩码DC的透明区域为白色其它区域为黑色  
	dcMask.BitBlt(0,0,nWidthDest, nHeightDest,&dcImage,0,0,SRCCOPY);  
 
	//临时DC透明区域为黑色，其它区域保持不变  
	dcImage.SetBkColor(RGB(0,0,0));  
	dcImage.SetTextColor(RGB(255,255,255));  
	dcImage.BitBlt(0, 0, nWidthDest, nHeightDest, &dcMask, 0, 0, SRCAND);  
 
	// 目标DC透明部分保持屏幕不变，其它部分变成黑色  
	pDC ->SetBkColor(RGB(255,255,255));  
	pDC ->SetTextColor(RGB(0,0,0));  
	pDC ->BitBlt(nXDest, nYDest, nWidthDest, nHeightDest, &dcMask, 0, 0, SRCAND);  
	pDC ->BitBlt(nXDest, nYDest, nWidthDest, nHeightDest, &dcImage, 0, 0, SRCPAINT);  
}     
	   
//创建一张空白内存画布  
BOOL CMemoryDC::Create(int cx,int cy,CDC* pDC)  
{  
	this->CreateCompatibleDC(pDC);  
	CBitmap bitmap;  
	if(pDC)  
		bitmap.CreateCompatibleBitmap(pDC,cx,cy);  
	else  
		bitmap.CreateCompatibleBitmap(&CClientDC(NULL),cx,cy);  
	m_size.cx = cx;  
	m_size.cy = cy;  
	this->SelectObject(bitmap);  
	return TRUE;  
}  
 
//摧毁  
BOOL CMemoryDC::DeleteDC()  
{  
	if(!GetSafeHdc())  
		return TRUE;  
	CBitmap * pBitmap = GetCurrentBitmap();  
	pBitmap ->DeleteObject();  
	return CDC::DeleteDC();  
}  
 
//根据当前DC中的位图和透明色，去掉透明色，生成一个除透明色外不规则的区域
void CMemoryDC::GenerateRgn(CRgn &DesRgn,COLORREF clTrans)
{
	DesRgn.CreateRectRgn(0,0,0,0);
 
	int i(0),j(0);
 
	while (i < m_size.cx)
	{
		j = 0;
 
		while (j < m_size.cy)
		{
			if (GetPixel(i,j) - clTrans)
			{
				CRgn rgTemp;
				rgTemp.CreateRectRgn(i,j,i+1,j+1);
				DesRgn.CombineRgn(&DesRgn,&rgTemp,RGN_OR);
			}
 
			j++;
		}
 
		i++;
	}
}
