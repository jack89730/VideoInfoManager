#ifndef _USERFORM_H_
#define _USERFORM_H_

#include "../UserForm/UserAction.h"


class UserForm:public Form//�û��������
{
public:
	UserForm(int height,int width,int starty,int startx,int contype);
	static Table *pTable;
};



class UserUpdata:public Form// �û��޸�
{
public:
	UserUpdata(int height,int width,int starty,int startx,int contype);
	~UserUpdata();
	TableItem *pData;
	char *passwd;
};




class UserAdd:public Form// �û�����
{
public:
	UserAdd(int height,int width,int starty,int startx,int contype);
	~UserAdd();
	TableItem *pData;
	char *passwd;
};



class UserRemove:public Form// �û�ɾ��
{
public:
	UserRemove(int height,int width,int starty,int startx,int contype);
};




class UserPower:public Form //�û�Ȩ��
{
public:
	UserPower(int height,int width,int starty,int startx,int contype);
	void show();	//�ض���show
	char *role_id;	// ������ѡ�еĵĽ�ɫID
	static UserPower *pPower;
	static WINDOW *pWindow;	// �û�Ȩ�޸��Ľ���Ĵ���ָ��
protected:
	pList pMenu;			// ��ǰ�û�ӵ�е����˵�����
};



class Power:public Control// Ȩ����Ŀ������
{
public:
	Power(WINDOW *pFather,int height,int width,int starty,int startx,char *data,char *fid,int contype);
	~Power();
	void show();
	void ShowList();
protected:
	pList pNode;// һ�����˵�ӵ�е��Ӳ˵�����
};




#endif