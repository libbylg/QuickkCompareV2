#ifndef __MEMDC_H__  
#define __MEMDC_H__  
 
class CMemoryDC : public CDC  
{  
	CSize m_size;  
public:  
	//析构函数，释放加载的位图资源
    ~CMemoryDC();
 
    CMemoryDC();
	
	//在构造对象的同时，根据资源ID加载位图
    CMemoryDC(UINT nBitmapID, CDC* pDC = NULL);
 
	//在构造对象的同时，从进程外，根据位图文件绝对路径名加载位图
    CMemoryDC(LPCTSTR szBitmapFile, CDC* pDC = NULL);
 
	//在构造对象的同时，创建一块空白画布
    CMemoryDC(int cx, int cy, CDC* pDC = NULL);
 
	//根据资源ID加载位图 
    BOOL LoadBitmap(UINT nBitmapID, CDC* pDC = NULL);
 
	//从进程外，根据位图文件绝对路径名加载位图
    BOOL LoadBitmap(LPCTSTR szBitmapFile, CDC* pDC = NULL);
 
	//绘制透明位图
    void BitTrans(
        int nXDest,     // 目标起点X  
        int nYDest,     // 目标起点Y  
        int nWidthDest, // 目标宽度  
        int nHeightDest,// 目标高度  
        CDC* pDC,       // 目标DC  
        int nXSrc,      // 来源起点X  
        int nYSrc,      // 来源起点Y  
        COLORREF crTrans// 透明色  
        );
 
	//绘制具有可拉伸的透明位图
    void StretchTrans(
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
        );
	   
	//创建一张空白内存画布  
    BOOL Create(int cx, int cy, CDC* pDC = NULL);
 
	//摧毁  
    BOOL DeleteDC();
 
	//根据当前DC中的位图和透明色，去掉透明色，生成一个除透明色外不规则的区域
    void GenerateRgn(CRgn &DesRgn, COLORREF clTrans);
	inline int Width(){return m_size.cx;}  
	inline int Height(){return m_size.cy;}  
};  
 
#endif //__MEMDC_H__

