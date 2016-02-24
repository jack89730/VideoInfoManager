#include <string.h>
#include <malloc.h>
#include "../UserForm/UserForm.h"
#include "../UserForm/UserDb.h"
#include "../DbCon/DbCon.h"


Table *UserForm::pTable = NULL;
UserForm::UserForm(int height,int width,int starty,int startx,int contype)
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
	((Table *)pCom)->flag = 6;
	UserForm::pTable = (Table *)pCom;
	UserForm::pTable->tabtype = 1;
	List_add(pfirst,pCom);
	// Ϊ�û�������潨һ����ؼ���������ʾ��ѯ�õ��ļ�¼
	pCom = new Label(this->pCon,3,8,1,1,(char *)"�û���",1);
    List_add(pfirst,pCom);
	pCom = new Edit(this->pCon,3,14,1,9,10,1,2,true);
	UserForm::pTable->user_name = pCom->Getdata();
    List_add(pfirst,pCom);
	pCom = new Label(this->pCon,3,8,1,24,(char *)"�ʺ�",1);
    List_add(pfirst,pCom);
	pCom = new Edit(this->pCon,3,14,1,31,10,1,2,true);
	UserForm::pTable->user_account = pCom->Getdata();
    List_add(pfirst,pCom);
	pCom = new Button(this->pCon,3,8,1,50,(char *)" ��ѯ ",3);
	pAction = new ActionSearch(this);
	((Button *)pCom)->AddAction(pAction);
	List_add(pfirst,pCom);
	pCom = new Button(this->pCon,3,8,3,(4*COLS)/5+3,(char *)" ���� ",3);
	pAction = new ActionAdd(this);
	((Button *)pCom)->AddAction(pAction);
	List_add(pfirst,pCom);
	pCom = new Button(this->pCon,3,8,7,(4*COLS)/5+3,(char *)" �޸� ",3);
 	pAction = new ActionUpdata(this);
 	((Button *)pCom)->AddAction(pAction);
	List_add(pfirst,pCom);
	pCom = new Button(this->pCon,3,8,11,(4*COLS)/5+3,(char *)" ɾ�� ",3);
	pAction = new ActionRemove(this);
	((Button *)pCom)->AddAction(pAction);
	List_add(pfirst,pCom);
	pCom = new Button(this->pCon,3,8,15,(4*COLS)/5+3,(char *)" Ȩ�� ",3);
	pAction = new ActionPower(this);
	((Button *)pCom)->AddAction(pAction);
	List_add(pfirst,pCom);   
	pCom = new Button(this->pCon,3,8,19,(4*COLS)/5+3,(char *)" ���� ",3);
	pAction = new ActionReturn(this);
	((Button *)pCom)->AddAction(pAction);// ��ӷ��ذ�ť�¼�
	List_add(pfirst,pCom);   
	pCom = new Label(this->pCon,3,8,5,0,(char *)"���",1);
	List_add(pfirst,pCom);   
	pCom = new Label(this->pCon,3,8,5,14,(char *)"�û���",1);
	List_add(pfirst,pCom); 
	pCom = new Label(this->pCon,3,8,5,28,(char *)"�ʺ�",1);
	List_add(pfirst,pCom);   
	pCom = new Label(this->pCon,3,8,5,42,(char *)"��ע",1);
	List_add(pfirst,pCom);  
	pCom = new Label(this->pCon,1,60,LINES-2,1,(char *)"ѡ��:Up/Down  ��ҳ:PageUp/PageDown  ȷ��:Enter  ��ѡ��¼:Esc",1);
	List_add(pfirst,pCom); 
	mvwvline(this->pCon,6,10,0,1);
	mvwvline(this->pCon,6,24,0,1);
	mvwvline(this->pCon,6,39,0,1);
	mvwvline(this->pCon,6,53,0,1);

}




UserRemove::UserRemove(int height,int width,int starty,int startx,int contype)
						:Form(height,width,starty,startx,contype)
{	
	Control *pCom;
	ActionListen *pAction;

	pCom = new Label(this->pCon,3,12,1,8,(char *)"ȷ��ɾ��?",1);
    List_add(pfirst,pCom);
	pCom = new Button(this->pCon,3,8,5,3,(char *)" ȷ�� ",3);
	pAction = new RemoveEnter(this);
    ((Button *)pCom)->AddAction(pAction);
	List_add(pfirst,pCom);
	pCom = new Button(this->pCon,3,8,5,18,(char *)" ȡ�� ",3);
	pAction = new ActionReturn(this);
	((Button *)pCom)->AddAction(pAction);
	List_add(pfirst,pCom);
}


UserUpdata::UserUpdata(int height,int width,int starty,int startx,int contype)
						:Form(height,width,starty,startx,contype)
{
	this->pData = (TableItem *)malloc(sizeof(class TableItem));
	memset(pData,0,sizeof(class TableItem));
	Control *pCom;
	ActionListen *pAction;
	char sql[128] = "select * from Tbl_role"; 
	pCom = new Label(this->pCon,1,21,0,20,(char *)"  �û��޸�  ",1);
    List_add(pfirst,pCom);
	pCom = new Label(this->pCon,3,8,2,2,(char *)"�� �� ��",1);
    List_add(pfirst,pCom);
	pCom = new Edit(this->pCon,3,15,2,11,10,1,2,true);
	strcpy(pCom->Getdata(),UserForm::pTable->pNode->user_name);
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
	strcpy(pCom->Getdata(),UserForm::pTable->pNode->user_account);
	pData->user_account = pCom->Getdata();
    List_add(pfirst,pCom);
	pCom = new Label(this->pCon,3,8,5,30,(char *)"��ɫ����",1);
	List_add(pfirst,pCom);
	pCom = new Combobox(this->pCon,3,15,5,39,6,sql);
	strcpy(((Combobox *)pCom)->ID,UserForm::pTable->pNode->role_id);
	pData->role_id = ((Combobox *)pCom)->ID;
	List_add(pfirst,pCom);
	pCom = new Label(this->pCon,3,8,8,30,(char *)"��    ע",1);
	List_add(pfirst,pCom);
	pCom = new Edit(this->pCon,3,15,8,39,10,1,2,true);
	strcpy(pCom->Getdata(),UserForm::pTable->pNode->user_remark);
	pData->user_remark = pCom->Getdata();
    List_add(pfirst,pCom);
	pCom = new Button(this->pCon,3,8,14,18,(char *)" �޸� ",3);
 	pAction = new UpdataEnter(this);
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


UserUpdata::~UserUpdata()
{
	free(pData);
}



UserAdd::UserAdd(int height,int width,int starty,int startx,int contype)
						:Form(height,width,starty,startx,contype)
{
	this->pData = (TableItem *)malloc(sizeof(class TableItem));
	memset(pData,0,sizeof(class TableItem));
	Control *pCom;
	ActionListen *pAction;	
	char sql[128] = "select * from Tbl_role"; 
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
	pCom = new Label(this->pCon,3,8,5,30,(char *)"��ɫ����",1);
	List_add(pfirst,pCom);
	pCom = new Combobox(this->pCon,3,15,5,39,6,sql);
	pData->role_id = ((Combobox *)pCom)->ID;
	List_add(pfirst,pCom);
	pCom = new Label(this->pCon,3,8,8,30,(char *)"��    ע",1);
	List_add(pfirst,pCom);
	pCom = new Edit(this->pCon,3,15,8,39,10,1,2,true);
	pData->user_remark = pCom->Getdata();
    List_add(pfirst,pCom);
	pCom = new Button(this->pCon,3,8,14,18,(char *)" ���� ",3);
	pAction = new AddEnter(this);
	((Button *)pCom)->AddAction(pAction);
	List_add(pfirst,pCom);
	pCom = new Button(this->pCon,3,8,14,35,(char *)" ȡ�� ",3);
	pAction = new ActionReturn(this);
	((Button *)pCom)->AddAction(pAction);
	List_add(pfirst,pCom);
	pCom = new Label(this->pCon,1,50,11,6,(char *)"Ҫ��:�û�������Ϊ�գ�����������һ�£����벻Ϊ��",1);
	List_add(pfirst,pCom);
	pCom = new Label(this->pCon,1,50,12,5,(char *)"�����8λ�������10λ,��ɫ��Ϊ��",1);
	List_add(pfirst,pCom);
	
}

UserAdd::~UserAdd()
{
	free(pData);
}


UserPower *UserPower::pPower = NULL;
WINDOW *UserPower::pWindow = NULL;
UserPower::UserPower(int height,int width,int starty,int startx,int contype)
					:Form(height,width,starty,startx,contype)
{
	UserPower::pWindow = this->pCon;
	UserPower::pPower = this;
	Control *pCom;
	ActionListen *pAction;
	char sql[128] = "select * from Tbl_role"; 
	pMenu = List_init(NULL);
	pCom = new Label(this->pCon,1,21,0,25,(char *)"  �û�Ȩ��  ",1);
    List_add(pfirst,pCom);
	pCom = new Label(this->pCon,3,11,1,2,(char *)"��ǰ�û���:",1);
    List_add(pfirst,pCom);
    pCom = new Label(this->pCon,3,12,1,12,UserForm::pTable->pNode->user_name,1);
    List_add(pfirst,pCom);
	pCom = new Label(this->pCon,3,5,1,29,(char *)"�˺�:",1);
    List_add(pfirst,pCom);
	pCom = new Label(this->pCon,3,12,1,32,UserForm::pTable->pNode->user_account,1);
    List_add(pfirst,pCom);
	pCom = new Label(this->pCon,3,12,4,1,(char *)"������ɫ:",1);
    List_add(pfirst,pCom);
	pCom = new Combobox(this->pCon,3,16,4,14,6,sql);
	strcpy(((Combobox *)pCom)->ID,UserForm::pTable->pNode->role_id);
	this->role_id = ((Combobox *)pCom)->ID;
	List_add(pfirst,pCom);	
	pCom = new Button(this->pCon,3,8,1,47,(char *)" ȷ�� ",3);
	pAction = new PowerEnter(this);
	((Button *)pCom)->AddAction(pAction);
	List_add(pfirst,pCom);
	pCom = new Button(this->pCon,3,8,6,47,(char *)" ȡ�� ",3);
	pAction = new ActionReturn(this);
	((Button *)pCom)->AddAction(pAction);
	List_add(pfirst,pCom);
}


void UserPower::show()
{
	char sql[512] = "";
	pMenu->pNext = NULL;
	sprintf(sql,"select * from Tbl_menu where menu_id in (select menu_id from Tbl_role_menu where role_id = %s) and menu_id != 2004",this->role_id);
	(DbSingles::GetSingle())->GetData(sql,Power_CallBack,pMenu);
	Control *fp;
    pList pTemp;
	wbkgd(this->pShadow,COLOR_PAIR(4));
	wrefresh(this->pShadow);
	wclear(pCon);
	mvwhline(this->pCon,10,0,0,width);
    box(pCon,0,0);
    wbkgd(pCon,COLOR_PAIR(2));
    wrefresh(pCon);	
    pTemp = pfirst->pNext;
	while (pfirst->pNext)
	{
		fp = (Control *)(pTemp->pData);
		fp->show();
		pTemp = pTemp->pNext;
		if (pTemp == pfirst->pNext)
		{
			break;
		}
	}

	pTemp = pMenu->pNext;
	while (pTemp)
	{
		fp = (Control *)(pTemp->pData);
		fp->show();
		mvwprintw(fp->GetHandle(),0,0,"+ ");
		wrefresh(fp->GetHandle());
		((Power *)fp)->ShowList();
		pTemp = pTemp->pNext;
		if (pTemp == pMenu->pNext)
		{
			break;
		}
   }
}



Power::Power(WINDOW *pFather,int height,int width,int starty,int startx,char *data,char *fid,int contype)
			 :Control(pFather,height,width,starty,startx,contype)
{
	this->data = new char[strlen(data)+1];
	strcpy(this->data,data);
	char sql[256] = "";
	if (fid != NULL)
	{
		pNode = List_init(NULL);
		sprintf(sql,"select menu_name from Tbl_menu where menu_fid = %s",fid);
		(DbSingles::GetSingle())->GetData(sql,PowerItem_CallBack,pNode);
	}
	else 
		pNode = NULL;
}

Power::~Power()
{
	if (pNode != NULL)
	{
		List_free(pNode);
	}
}


void Power::show()
{
	wbkgd(this->pCon,COLOR_PAIR(2));
	mvwprintw(this->pCon,height/2,0,"--");
	mvwprintw(this->pCon,height/2,2,"%s",data);
	wrefresh(this->pCon);
}

void Power::ShowList()
{
	Control *pWin;
	pList pTemp;
	pTemp = pNode->pNext;
	while (pTemp)
	{
		pWin = (Control *)(pTemp->pData);
		pWin->show();
		pTemp = pTemp->pNext;
		if (pTemp == pNode->pNext)
		{
			break;
		}
	}

}