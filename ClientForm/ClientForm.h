#ifndef _CLIENTFORM_H_
#define _CLIENTFORM_H_

#include "../Control/Control.h"

/**********************************************�ͻ����û�����**********************************************/


class ClientForm:public Form//�ͻ����û��������
{
public:
	ClientForm(int height,int width,int starty,int startx,int contype);
	static Table *pTable1;
};



class ClientUserAdd:public Form// �ͻ����û�����
{
public:
	ClientUserAdd(int height,int width,int starty,int startx,int contype);
	~ClientUserAdd();
	TableItem *pData;
	char *passwd;
};



class ClientUserUpdata:public Form// �ͻ����û��޸�
{
public:
	ClientUserUpdata(int height,int width,int starty,int startx,int contype);
	~ClientUserUpdata();
	TableItem *pData;
	char *passwd;
};



class ClientUserRemove:public Form// �ͻ����û���ɾ��
{
public:
	ClientUserRemove(int height,int width,int starty,int startx,int contype);

};


#endif

