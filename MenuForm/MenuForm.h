#ifndef _MAINFORM_H_
#define _MAINFORM_H_

#include "../Control/Control.h"
#include "../List/List.h"


class MenuForm:public Form // �˵�����
{
public:
	MenuForm(int height,int width,int starty,int startx,int contype,char *role);
	void show();
	void KeyListen(int &key);	
	int menu_sid;// �����˵����
	static MenuForm *pForm;// �˵�����thisָ��
};

class MenuBar:public Control // �˵�����һ���˵���
{
public:
	MenuBar(WINDOW *pFather,int height,int width,int starty,int startx,char *colvalu,char *data,int contype);
	~MenuBar();
	void show();
	void GetFocus();
	void AddAction(char *menu_fid);
	pList psecond;// �����˵�����ͷ
	ActionListen *pAction;//�������˵��Ķ����˵��¼�

};



class MenuItem:public Control// �˵�������˵���
{
public:
	MenuItem(WINDOW *pFather,int height,int width,int starty,int startx,char *data,int contype);
	~MenuItem();
	void show();
	void GetFocus();
	int menu_sid;
    
};


#endif

