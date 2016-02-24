#include <stdlib.h>
#include "../MenuForm/MenuAction.h"
#include "../MenuForm/MenuForm.h"
#include "../UserForm/UserForm.h"
#include "../ClientForm/ClientForm.h"
#include "../TableForm/TableForm.h"
#include "../DbCon/DbCon.h"

ActionSystem::ActionSystem(Form *pWin):ActionListen(pWin)
{

}

void ActionSystem::DoAction(int &key)
{
	Control *pUser;
	Control *pNotic;	
	switch(((MenuForm *)pWin)->menu_sid)
	{
	case 2010: // ��֯��������
	case 2012: // ϵͳ�������ã�δ��ͨ�˹��ܣ�������ʾ
		pNotic = new Notic(NULL,5,18,LINES/2-4,COLS/2-6,(char *)"��δ��ͨ�˹���",5);
		pNotic->show();
		usleep(1000000);
		wclear(pNotic->GetHandle());
		wrefresh(pNotic->GetHandle());
		delete pNotic;
		break;
	case 2011: // ϵͳ�û�����
		pUser = new UserForm(LINES,COLS,0,0,1);
		pUser->show();	
		pUser->KeyListen(key);
	    delete pUser;
		break;
	}

}


ActionClient::ActionClient(Form *pWin):ActionListen(pWin)
{

}


void ActionClient::DoAction(int &key)
{
	Control *pClient;
	Control *pNotic;	
	switch(((MenuForm *)pWin)->menu_sid)
	{
	case 2014: 
		pNotic = new Notic(NULL,5,18,LINES/2-4,COLS/2-6,(char *)"��δ��ͨ�˹���",5);
		pNotic->show();
		usleep(1000000);
		wclear(pNotic->GetHandle());
		wrefresh(pNotic->GetHandle());
		delete pNotic;
		break;
	case 2013: 
		pClient = new ClientForm(LINES,COLS,0,0,1);//�ͻ����û�����
		pClient->show();	
		pClient->KeyListen(key);
		delete pClient;
		break;
	}
}



ActionVideo::ActionVideo(Form *pWin):ActionListen(pWin)
{

}

void ActionVideo::DoAction(int &key)//��Ƶ������δ��ͨ
{
	Control *pNotic;
	pNotic = new Notic(NULL,5,18,LINES/2-4,COLS/2-9,(char *)"��δ��ͨ�˹���",5);
	pNotic->show();
	usleep(1000000);
	wclear(pNotic->GetHandle());
	wrefresh(pNotic->GetHandle());
	delete pNotic;
}

ActionTable::ActionTable(Form *pWin):ActionListen(pWin)
{

}

void ActionTable::DoAction(int &key)
{
	Control *pTableForm;
	if(((MenuForm *)pWin)->menu_sid == 2019)// ����ͳ�ƶ����˵��¼�
	{
		pTableForm = new TableForm(LINES,COLS,0,0,1);
		pTableForm->show();
 		pTableForm->KeyListen(key);
 		//delete pTableForm;
 		TableForm::pTable = NULL;
		TableForm::pTableForm =NULL;
	}

}

ActionLogout::ActionLogout(Form *pWin):ActionListen(pWin)
{
	
}


void ActionLogout::DoAction(int &key)
{	
	switch(((MenuForm *)pWin)->menu_sid)
	{
	case 2020:// ע��
		pWin->flag  = false;
		break;
	case 2021:// �˳�
		delete pWin;	
		endwin();//�˳�Ncurses
		ReleaseDb();//�ر����ݿ�
		exit(0);
	}
	
}












