#ifndef _Control_H
#define _Control_H

#include <ncurses.h>
#include <sqlite3.h>
#include <iostream> //usleepͷ�ļ�
#include "../List/List.h"

class ActionListen;//�¼������������
class Control//�������
{
public:
	Control(WINDOW *pFather,int height,int width,int starty,int startx,int contype);
	virtual ~Control();
	virtual void show() = 0;//���麯������̬��ʾ��ͬ�Ŀؼ�
	virtual void KeyListen(int &key);//�ؼ����̼����Ķ�̬
	virtual void GetFocus();//�ؼ�����ͣ���Ķ�̬
	WINDOW* GetHandle();//��ÿؼ�ָ��
	int GetType();
	char *Getdata();
protected:
	WINDOW *pCon;//�ؼ�ָ��
	int height;//�ؼ��ĸ߶�
	int width;//�ؼ��Ŀ��
    int starty;//��ʼ������
	int startx;//��ʼ������
	char *data;//�ؼ�������
	int contype;// �ؼ�������  1-��ǩ��2-�༭��3-��ť��4-���5-��ʾ��6-������
    WINDOW *pFather;//������ָ��

};



class Label:public Control//��ǩ������
{
public:
	Label(WINDOW *pFather,int height,int width,int starty,int startx,char *data,int contype);
	~Label();
    void show();

};

class Notic:public Control//��ʾ��
{
public:
	Notic(WINDOW *pFather,int height,int width,int starty,int startx,char *data,int contype);
	~Notic();
	void show();
};


class Edit:public Control//�༭��������
{
public:
	Edit(WINDOW *pFather,int height,int width,int starty,int startx,int len,int type,int contype,bool pwd = false);
	~Edit();
	void show();
	void KeyListen(int &key);
	void GetFocus();
private:
	int len;// �����ַ�����
	int type;// �����ַ�����
	bool pwd;// ���ı�־

};

class ComboxItem:public Control
{
public:
	ComboxItem(WINDOW *pFather,int height,int width,int starty,int startx,int contype,char *ID,char *Name);
	void show();
	void GetFocus();
	char ID[10];
	char Name[20];
};


class Combobox:public Control//������
{
public:
	Combobox(WINDOW *pFather,int height,int width,int starty,int startx,int contype,char *sql);
	~Combobox();
	void show();
	void showmin();
	void GetFocus();
	void MenuClear();
	void KeyListen(int &key);
	static Combobox *pBox;
	static int Add_CallBack(void *pData,int cols,char **colvalu,char **colname);  
	char ID[10];// ���������ݵ�ID
protected:	
	pList pNode;// ������������˵��б�

};

class Button:public Control//��ť������
{
public:
	Button(WINDOW *pFather,int height,int width,int starty,int startx,char *data,int contype);
	~Button();
	void show();
	void KeyListen(int &key);
	void GetFocus();
    void AddAction(ActionListen *pAct);
private:
	WINDOW *pShadow;
	ActionListen *pAct;

};

class Form:public Control//������
{
public:
    Form(int height,int width,int starty,int startx,int contype);
    ~Form();
    void show();
    void KeyListen(int &key);
	bool flag;   //�˳�keylisten�ı�־ 
protected:
    pList pfirst;// �ؼ����������Ϊ�˵������һ���˵�����
	WINDOW *pShadow;
	
};


class ActionListen//�¼�����
{
public:
    ActionListen(Form *pWin);
    virtual void DoAction(int &key) = 0;
protected:
    Form *pWin;//���ڻ���ָ��
};



class TableItem:public Control
{
public:
	TableItem(WINDOW *pFather,int height,int width,int starty,int startx,int contype,char *user_id,char *user_name,char *user_account,char *user_remark,char *role,char *logintime);
	~TableItem();
	void show();//ϵͳ�û������ʾ����
	void ClientShow();//�ͻ����û������ʾ����
	void TableShow();//����ͳ�Ƶı����ʾ����
	void GetFocus();
	void SelectFocus();
	char *user_id;
	char *user_name;
	char *user_pwd;
	char *user_account;
	char *user_remark;
	char *role_id;
	char *logintime;
};



class Table:public Control
{
public:
	Table(WINDOW *pFather,int height,int width,int starty,int startx,int contype);
	~Table();
	void show();
	void KeyListen(int &key);
	void UpdataTable();
	void RunSql(int flag);
	int flag;			// sql����־
	Control *pLable;	// ҳ����ʾ����
	char *user_name;	//�����������û���
	char *user_account;//�����������˺�
	int sum;			// ���ϲ�ѯ�����ļ�¼����
	TableItem *pNode;	// ����ĳһ����¼
	int n;				//�ӵڼ��������ʼ��ʾ�ڱ���
	int count;			//ָ���¼����ĵڼ������
	int tabtype;		//������� 1-ϵͳ�û���2-�ͻ����û���3-����ͳ�Ʊ�
protected:
	pList precord;		// ��¼���еļ�¼����
};



#endif
