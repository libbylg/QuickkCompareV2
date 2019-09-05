#ifndef __MEMDC_H__  
#define __MEMDC_H__  
 
class CMemoryDC : public CDC  
{  
	CSize m_size;  
public:  
	//�����������ͷż��ص�λͼ��Դ
    ~CMemoryDC();
 
    CMemoryDC();
	
	//�ڹ�������ͬʱ��������ԴID����λͼ
    CMemoryDC(UINT nBitmapID, CDC* pDC = NULL);
 
	//�ڹ�������ͬʱ���ӽ����⣬����λͼ�ļ�����·��������λͼ
    CMemoryDC(LPCTSTR szBitmapFile, CDC* pDC = NULL);
 
	//�ڹ�������ͬʱ������һ��հ׻���
    CMemoryDC(int cx, int cy, CDC* pDC = NULL);
 
	//������ԴID����λͼ 
    BOOL LoadBitmap(UINT nBitmapID, CDC* pDC = NULL);
 
	//�ӽ����⣬����λͼ�ļ�����·��������λͼ
    BOOL LoadBitmap(LPCTSTR szBitmapFile, CDC* pDC = NULL);
 
	//����͸��λͼ
    void BitTrans(
        int nXDest,     // Ŀ�����X  
        int nYDest,     // Ŀ�����Y  
        int nWidthDest, // Ŀ����  
        int nHeightDest,// Ŀ��߶�  
        CDC* pDC,       // Ŀ��DC  
        int nXSrc,      // ��Դ���X  
        int nYSrc,      // ��Դ���Y  
        COLORREF crTrans// ͸��ɫ  
        );
 
	//���ƾ��п������͸��λͼ
    void StretchTrans(
        int nXDest,         // Ŀ�����X  
        int nYDest,         // Ŀ�����Y  
        int nWidthDest,     // Ŀ����  
        int nHeightDest,    // Ŀ��߶�  
        CDC* pDC,           // Ŀ��DC  
        int nXSrc,          // ��Դ���X  
        int nYSrc,          // ��Դ���Y  
        int nWidthSrc,      // ��Դ���  
        int nHeightSrc,     // ��Դ�߶�  
        COLORREF crTrans    // ͸��ɫ  
        );
	   
	//����һ�ſհ��ڴ滭��  
    BOOL Create(int cx, int cy, CDC* pDC = NULL);
 
	//�ݻ�  
    BOOL DeleteDC();
 
	//���ݵ�ǰDC�е�λͼ��͸��ɫ��ȥ��͸��ɫ������һ����͸��ɫ�ⲻ���������
    void GenerateRgn(CRgn &DesRgn, COLORREF clTrans);
	inline int Width(){return m_size.cx;}  
	inline int Height(){return m_size.cy;}  
};  
 
#endif //__MEMDC_H__

