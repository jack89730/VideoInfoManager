#ifndef _SINGLES_H_
#define _SINGLES_H_

#include <stdio.h>
#include <sqlite3.h>

class DbSingles
{
public:
	static DbSingles *GetSingle();// ��ȡ������ָ��
    int GetData(char *sql,sqlite3_callback pFun,void *pData);// ִ��sql���	
private:
	DbSingles();
	~DbSingles();
	static DbSingles *pS;
    sqlite3 *db;
	friend void ReleaseDb();   
	
};

void ReleaseDb();// �ͷŵ������ر����ݿ�

int Get_CallBack(void *pData,int cols,char **colvalu,char **colname);

#endif