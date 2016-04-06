/*****************************************
 *功能：文件处理类接口
 *
 *
 *
 *
 *author:Jerry.Chau
 *time: 2016-04-02 
 *****************************************/

#ifndef _CFILE_H
#define _CFILE_H
#include <dir.h>
//#include <>

class CFile
{
    public:
        CFile(){ m_pFile = NULL;}
        CFile(const CFile& right);
    public:
        Open();


    private:
        FILE* m_pFile;

};




#endif
