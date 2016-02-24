#include <malloc.h>
#include <string.h>
#include "../ClientForm/ClientAction.h"
#include "../ClientForm/ClientForm.h"
#include "../DbCon/DbCon.h"


ActionClientSearch::ActionClientSearch(Form *pWin):ActionListen(pWin)
{
	
	
}

void ActionClientSearch::DoAction(int &key)// �ͻ����û���ѯ
{

	ClientForm::pTable1->KeyListen(key);	 
}



ActionClientAdd::ActionClientAdd(Form *pWin):ActionListen(pWin)
{
	
}


void ActionClientAdd::DoAction(int &key)
{
	Control *pAdd;
	Control *pNotic;
	pAdd = new ClientUserAdd(19,61,2,4,1);
	pAdd->show();
	pAdd->KeyListen(key);
	if (key == 1)
	{
		pNotic = new Notic(pAdd->GetHandle(),5,26,7,18,(char *)"���ӳɹ������Ժ�",5);
		pNotic->show();
		usleep(1000000);
		delete pNotic;
		if (ClientForm::pTable1->sum != 0)
		{
			ClientForm::pTable1->sum = ClientForm::pTable1->sum + 1;
		}
		
	}
	pWin->show();
	ClientForm::pTable1->UpdataTable();
	key = 10;
	delete pAdd;	
}


ActionAddEnter::ActionAddEnter(Form *pWin):ActionListen(pWin)
{
	
}


void ActionAddEnter::DoAction(int &key)
{
	Control *pNotic;
	ClientUserAdd *pAdd = (ClientUserAdd *)pWin;
	char ID[10] = "";
	char sql[512] = "";
	int user_id;
	char date[20];
	if (strcmp(pAdd->pData->user_pwd,pAdd->passwd) != 0 || strcmp(pAdd->passwd,"") == 0 || strcmp(pAdd->pData->user_name,"") == 0)
		// ��֤�����һ����,�û�����Ϊ��
	{
		pNotic = new Notic(pAdd->GetHandle(),5,26,7,18,(char *)"������Ҫ������������",5);
		pNotic->show();
		usleep(1000000);
		wclear(pNotic->GetHandle());
		delete pNotic;
		memset(pAdd->pData->user_pwd,0,sizeof(pAdd->pData->user_pwd));
		memset(pAdd->passwd,0,sizeof(pAdd->pData->user_pwd));
		pAdd->show();
		key = 0;
		return;
	}
	sprintf(sql,"select date(\'now\')");
	(DbSingles::GetSingle())->GetData(sql,Get_CallBack,date);
	sprintf(sql,"select count(*) as sum from Tbl_cuser");
	(DbSingles::GetSingle())->GetData(sql,Get_CallBack,ID);// ��ȡ��ǰ�ж����û�
	sscanf(ID,"%d",&user_id);
	user_id++;// �ܵ��û���һ������������û�ID
	sprintf(sql,"insert into Tbl_cuser values(%d,\"%s\",\"%s\",\"%s\",1,\"%s\",\"%s\")",user_id,pAdd->pData->user_name,pAdd->pData->user_pwd,pAdd->pData->user_account,date,pAdd->pData->user_remark);
	(DbSingles::GetSingle())->GetData(sql,NULL,NULL);// �����������ݵ��ͻ����û���	
	key = 1;
	pWin->flag = false;
}



/******************************************************************************
�ͻ����û������޸İ�ť�¼�������void ActionClientUpdata::DoAction(int &key)

*******************************************************************************/
ActionClientUpdata::ActionClientUpdata(Form *pWin):ActionListen(pWin)
{

}

void ActionClientUpdata::DoAction(int &key)
{
	Control *pUpdata;
	Control *pNotic;
	if (ClientForm::pTable1->pNode == NULL)
	{
		pNotic = new Notic(pWin->GetHandle(),5,30,9,17,(char *)"����ѡ��һ����¼",5);
		pNotic->show();
		usleep(1000000);
		wclear(pNotic->GetHandle());
		wrefresh(pNotic->GetHandle());
		delete pNotic;
		return;
	}
		pUpdata = new ClientUserUpdata(19,61,2,4,1);
		pUpdata->show();
		pUpdata->KeyListen(key);
		if (key == 1)
		{
			pNotic = new Notic(pUpdata->GetHandle(),5,26,8,18,(char *)"�޸ĳɹ������Ժ�",5);
			pNotic->show();
			usleep(1000000);
			delete pNotic;
		}
		pWin->show();
	    ClientForm::pTable1->UpdataTable();
		key = 10;
	    delete pUpdata;	
}

/************************************************************************
ȷ���޸��¼�������void ActionUpdataEnter::DoAction(int &key)

*************************************************************************/
ActionUpdataEnter::ActionUpdataEnter(Form *pWin):ActionListen(pWin)
{
	
}

void ActionUpdataEnter::DoAction(int &key)
{
	Control *pNotic;
	char sql[512] = "";
	ClientUserUpdata *pUpdata;
	pUpdata = (ClientUserUpdata *)pWin;
	if (strcmp(pUpdata->pData->user_pwd,pUpdata->passwd) != 0 || strcmp(pUpdata->passwd,"") == 0 || strcmp(pUpdata->pData->user_name,"") == 0)
		// ��֤�����һ���ԣ����벻Ϊ�գ��û�����Ϊ��
	{
		pNotic = new Notic(pUpdata->GetHandle(),5,26,8,18,(char *)"������Ҫ������������",5);
		pNotic->show();
		usleep(1000000);
		wclear(pNotic->GetHandle());
		delete pNotic;
		memset(pUpdata->pData->user_pwd,0,sizeof(pUpdata->pData->user_pwd));
		memset(pUpdata->passwd,0,sizeof(pUpdata->pData->user_pwd));
		pUpdata->show();
		key = 0;
		return;
	}
	sprintf(sql,"update Tbl_cuser set user_name = \"%s\",user_pwd = \"%s\",user_account = \"%s\",user_remark = \"%s\" where user_id = %s",pUpdata->pData->user_name,pUpdata->pData->user_pwd,pUpdata->pData->user_account,pUpdata->pData->user_remark,ClientForm::pTable1->pNode->user_id);
	(DbSingles::GetSingle())->GetData(sql,NULL,NULL);
	key = 1;
	pWin->flag = false;
}



/************************************************************************
�ͻ����û�����ɾ����ť�¼�������void ActionClientRemove::DoAction(int &key)

*************************************************************************/
ActionClientRemove::ActionClientRemove(Form *pWin):ActionListen(pWin)
{
	
	
}

void ActionClientRemove::DoAction(int &key)
{
	Control *pRemove;
	Control *pNotic;
	if (ClientForm::pTable1->pNode == NULL || ClientForm::pTable1->sum == 0)
	{
		pNotic = new Notic(pWin->GetHandle(),5,30,9,17,(char *)"����ѡ��һ����¼",5);
		pNotic->show();
		usleep(1000000);
		wclear(pNotic->GetHandle());
		wrefresh(pNotic->GetHandle());
		delete pNotic;
		return;
	}	
		pRemove = new ClientUserRemove(10,30,8,21,1);
		pRemove->show();
	    pRemove->KeyListen(key);// �Ƿ�ȷ��ɾ����¼�ļ��̼���,key����ֵ���ж�ȷ�����
		if (key == 1)
		{
			pNotic = new Notic(pRemove->GetHandle(),3,18,1,6,(char *)"ɾ���ɹ������Ժ�",5);
			pNotic->show();
			usleep(1000000);
			delete pNotic;
			pWin->show();
			ClientForm::pTable1->count = ClientForm::pTable1->count-1;
			ClientForm::pTable1->sum = ClientForm::pTable1->sum-1;//�ܼ�¼������һ��
			if(ClientForm::pTable1->count == 0)
			{
				ClientForm::pTable1->count=1;
			}
			ClientForm::pTable1->UpdataTable();// ���±��еļ�¼
		}
		else
		{
			pWin->show();
			ClientForm::pTable1->show();
			ClientForm::pTable1->pNode->SelectFocus();
		}
			key = 10;
			delete pRemove;	  
}

/************************************************************************
ȷ��ɾ���¼�������void ActionRemoveEnter::DoAction(int &key)

*************************************************************************/
ActionRemoveEnter::ActionRemoveEnter(Form *pWin):ActionListen(pWin)
{

}


void ActionRemoveEnter::DoAction(int &key)
{
	char sql[256] = "";
	sprintf(sql,"update Tbl_cuser set user_stat = 0 where user_id = %s",ClientForm::pTable1->pNode->user_id);
	(DbSingles::GetSingle())->GetData(sql,Search_CallBack,NULL);
	key = 1;
	pWin->flag = false;
}