#include <string.h>
#include <malloc.h>
#include "../ClientForm/ClientForm.h"
#include "../ClientForm/ClientAction.h"
#include "../ClientForm/ClientDb.h"



Table *ClientForm::pTable1 = NULL;
ClientForm::ClientForm(int height,int width,int starty,int startx,int contype)
						:Form(height,width,starty,startx,contype)
{
	Control *pCom;
	ActionListen *pAction;
	mvwhline(this->pCon,5,0,0,(4*COLS)/5);
	mvwvline(this->pCon,0,(4*COLS)/5,0,LINES+1);
	mvwhline(this->pCon,7,0,0,(4*COLS)/5);
	mvwhline(this->pCon,LINES-5,0,0,(4*COLS)/5);
	// �����������ߺ�һ������
	pCom = new Table(this->pCon,10,(4*COLS)/5-1,8,1,4);
	((Table *)pCom)->flag = 8;
	ClientForm::pTable1 = (Table *)pCom;
	ClientForm::pTable1->tabtype = 2;
	List_add(pfirst,pCom);
	// Ϊ�û�������潨һ����ؼ���������ʾ��ѯ�õ��ļ�¼
	pCom = new Label(this->pCon,3,8,1,1,(char *)"�û���",1);
    List_add(pfirst,pCom);
	pCom = new Edit(this->pCon,3,14,1,9,10,1,2,true);
	ClientForm::pTable1->user_name = pCom->Getdata();
    List_add(pfirst,pCom);
	pCom = new Label(this->pCon,3,8,1,24,(char *)"�ʺ�",1);
    List_add(pfirst,pCom);
	pCom = new Edit(this->pCon,3,14,1,31,10,1,2,true);
	ClientForm::pTable1->user_account = pCom->Getdata();
    List_add(pfirst,pCom);
	pCom = new Button(this->pCon,3,8,1,50,(char *)" ��ѯ ",3);
 	pAction = new ActionClientSearch(this);
 	((Button *)pCom)->AddAction(pAction);
	List_add(pfirst,pCom);
	pCom = new Button(this->pCon,3,8,3,(4*COLS)/5+3,(char *)" ���� ",3);
	pAction = new ActionClientAdd(this);
 	((Button *)pCom)->AddAction(pAction);
	List_add(pfirst,pCom);
	pCom = new Button(this->pCon,3,8,8,(4*COLS)/5+3,(char *)" �޸� ",3);
 	pAction = new ActionClientUpdata(this);
 	((Button *)pCom)->AddAction(pAction);
	List_add(pfirst,pCom);
	pCom = new Button(this->pCon,3,8,13,(4*COLS)/5+3,(char *)" ɾ�� ",3);
 	pAction = new ActionClientRemove(this);
 	((Button *)pCom)->AddAction(pAction);
	List_add(pfirst,pCom);  
	pCom = new Button(this->pCon,3,8,18,(4*COLS)/5+3,(char *)" ���� ",3);
 	pAction = new ActionReturn(this);
 	((Button *)pCom)->AddAction(pAction);// ��ӷ��ذ�ť�¼�
	List_add(pfirst,pCom);   
	pCom = new Label(this->pCon,3,8,5,0,(char *)"���",1);
	List_add(pfirst,pCom);   
	pCom = new Label(this->pCon,3,8,5,12,(char *)"�û���",1);
	List_add(pfirst,pCom); 
	pCom = new Label(this->pCon,3,8,5,26,(char *)"�ʺ�",1);
	List_add(pfirst,pCom);   
	pCom = new Label(this->pCon,3,12,5,39,(char *)"����¼ʱ��",1);
	List_add(pfirst,pCom);  
	pCom = new Label(this->pCon,3,8,5,54,(char *)"��ע",1);
	List_add(pfirst,pCom);  
	pCom = new Label(this->pCon,1,60,LINES-2,1,(char *)"ѡ��:Up/Down  ��ҳ:PageUp/PageDown  ȷ��:Enter  ��ѡ��¼:Esc",1);
	List_add(pfirst,pCom); 
	mvwvline(this->pCon,6,9,0,1);
	mvwvline(this->pCon,6,23,0,1);
	mvwvline(this->pCon,6,36,0,1);
	mvwvline(this->pCon,6,53,0,1);
	
}

 

ClientUserAdd::ClientUserAdd(int height,int width,int starty,int startx,int contype)
					:Form(height,width,starty,startx,contype)
{
	this->pData = (TableItem *)malloc(sizeof(class TableItem));
	memset(pData,0,sizeof(class TableItem));
	Control *pCom;
	ActionListen *pAction;	
	
	pCom = new Label(this->pCon,1,21,0,20,(char *)"  �û�����  ",1);
    List_add(pfirst,pCom);
	pCom = new Label(this->pCon,3,8,2,2,(char *)"�� �� ��",1);
    List_add(pfirst,pCom);
	pCom = new Edit(this->pCon,3,15,2,11,10,1,2,true);
	pData->user_name = pCom->Getdata();
    List_add(pfirst,pCom);
	pCom = new Label(this->pCon,3,8,5,2,(char *)"��    ��",1);
    List_add(pfirst,pCom);
	pCom = new Edit(this->pCon,3,15,5,11,8,2,2);
	passwd = pCom->Getdata();
    List_add(pfirst,pCom);	
	pCom = new Label(this->pCon,3,8,8,2,(char *)"ȷ������",1);
    List_add(pfirst,pCom);
	pCom = new Edit(this->pCon,3,15,8,11,8,2,2);
	pData->user_pwd = pCom->Getdata();
    List_add(pfirst,pCom);
	pCom = new Label(this->pCon,3,8,2,30,(char *)"��    ��",1);
    List_add(pfirst,pCom);
	pCom = new Edit(this->pCon,3,15,2,39,10,1,2,true);
	pData->user_account = pCom->Getdata();
    List_add(pfirst,pCom);	

	pCom = new Label(this->pCon,3,8,5,30,(char *)"��    ע",1);
	List_add(pfirst,pCom);
	pCom = new Edit(this->pCon,3,15,5,39,10,1,2,true);
	pData->user_remark = pCom->Getdata();
    List_add(pfirst,pCom);
	pCom = new Button(this->pCon,3,8,14,18,(char *)" ���� ",3);
	pAction = new ActionAddEnter(this);
	((Button *)pCom)->AddAction(pAction);
	List_add(pfirst,pCom);
	pCom = new Button(this->pCon,3,8,14,35,(char *)" ȡ�� ",3);
	pAction = new ActionReturn(this);
	((Button *)pCom)->AddAction(pAction);
	List_add(pfirst,pCom);
	pCom = new Label(this->pCon,1,50,11,6,(char *)"Ҫ��:�û�������Ϊ�գ�����������һ�£����벻Ϊ��",1);
	List_add(pfirst,pCom);
	pCom = new Label(this->pCon,1,50,12,5,(char *)"�����8λ�������10λ",1);
	List_add(pfirst,pCom);
	
}

ClientUserAdd::~ClientUserAdd()
{
	free(pData);
}

ClientUserUpdata::ClientUserUpdata(int height,int width,int starty,int startx,int contype)
									:Form(height,width,starty,startx,contype)
{
	this->pData = (TableItem *)malloc(sizeof(class TableItem));
	memset(pData,0,sizeof(class TableItem));
	Control *pCom;
	ActionListen *pAction;
	
	pCom = new Label(this->pCon,1,21,0,20,(char *)"  �û��޸�  ",1);
    List_add(pfirst,pCom);
	pCom = new Label(this->pCon,3,8,2,2,(char *)"�� �� ��",1);
    List_add(pfirst,pCom);
	pCom = new Edit(this->pCon,3,15,2,11,10,1,2,true);
	strcpy(pCom->Getdata(),ClientForm::pTable1->pNode->user_name);
	pData->user_name = pCom->Getdata();
    List_add(pfirst,pCom);
	pCom = new Label(this->pCon,3,8,5,2,(char *)"��    ��",1);
    List_add(pfirst,pCom);
	pCom = new Edit(this->pCon,3,15,5,11,8,2,2);
	passwd = pCom->Getdata();
    List_add(pfirst,pCom);
	pCom = new Label(this->pCon,3,8,8,2,(char *)"ȷ������",1);
    List_add(pfirst,pCom);
	pCom = new Edit(this->pCon,3,15,8,11,8,2,2);
	pData->user_pwd = pCom->Getdata();
    List_add(pfirst,pCom);
	pCom = new Label(this->pCon,3,8,2,30,(char *)"��    ��",1);
    List_add(pfirst,pCom);
	pCom = new Edit(this->pCon,3,15,2,39,10,1,2,true);
	strcpy(pCom->Getdata(),ClientForm::pTable1->pNode->user_account);
	pData->user_account = pCom->Getdata();
    List_add(pfirst,pCom);
	pCom = new Label(this->pCon,3,8,5,30,(char *)"��    ע",1);
	List_add(pfirst,pCom);
	pCom = new Edit(this->pCon,3,15,5,39,10,1,2,true);
	strcpy(pCom->Getdata(),ClientForm::pTable1->pNode->user_remark);
	pData->user_remark = pCom->Getdata();
    List_add(pfirst,pCom);
	pCom = new Button(this->pCon,3,8,14,18,(char *)" �޸� ",3);
 	pAction = new ActionUpdataEnter(this);
 	((Button *)pCom)->AddAction(pAction);
	List_add(pfirst,pCom);
	pCom = new Button(this->pCon,3,8,14,35,(char *)" ȡ�� ",3);
	pAction = new ActionReturn(this);
	((Button *)pCom)->AddAction(pAction);
	List_add(pfirst,pCom);
	pCom = new Label(this->pCon,1,50,11,6,(char *)"Ҫ��:�û�������Ϊ�գ�����������һ�£����벻Ϊ��",1);
	List_add(pfirst,pCom);
	pCom = new Label(this->pCon,1,40,12,5,(char *)"�����8λ�������10λ",1);
	List_add(pfirst,pCom);

}


ClientUserUpdata::~ClientUserUpdata()
{
	free(pData);
}



ClientUserRemove::ClientUserRemove(int height,int width,int starty,int startx,int contype)
							:Form(height,width,starty,startx,contype)
{	
	Control *pCom;
	ActionListen *pAction;
	
	pCom = new Label(this->pCon,3,12,1,8,(char *)"ȷ��ɾ��?",1);
    List_add(pfirst,pCom);
	pCom = new Button(this->pCon,3,8,5,3,(char *)" ȷ�� ",3);
	pAction = new ActionRemoveEnter(this);
    ((Button *)pCom)->AddAction(pAction);
	List_add(pfirst,pCom);
	pCom = new Button(this->pCon,3,8,5,18,(char *)" ȡ�� ",3);
	pAction = new ActionReturn(this);
	((Button *)pCom)->AddAction(pAction);
	List_add(pfirst,pCom);
}
