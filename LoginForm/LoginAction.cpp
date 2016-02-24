#include "LoginAction.h"
#include "../LoginForm/LoginForm.h"
#include "../DbCon/DbCon.h"
#include "../LoginForm/LoginDb.h"


ActionEnter::ActionEnter(Form *pWin):ActionListen(pWin)
{
	
	
}

void ActionEnter::DoAction(int &key)
{
    Control *pNotic;// ��ʾ��ָ��	
	char sql[256] = "";// sql��֤���
	sprintf(sql,"select role_id from Tbl_user,Tbl_user_role where user_name = \"%s\" and user_pwd = \"%s\" and Tbl_user.user_id = Tbl_user_role.user_id and Tbl_user.user_stat =1",
		    ((LoginForm *)pWin)->pName,((LoginForm  *)pWin)->pWd);
	//��ѯ��¼�û��Ľ�ɫID 
	(DbSingles::GetSingle())->GetData(sql,Login_Callback,((LoginForm *)pWin)->role_id);
	// �����ݿⲢ��֤��¼�û�
	if (strcmp(((LoginForm *)pWin)->role_id,"") !=0)
	{
       
		pNotic = new Notic(NULL,5,14,LINES/2-4,COLS/2-6,(char *)"��¼�ɹ�",5);
		pNotic->show();
		usleep(700000);
		delete pNotic;//��½�ɹ�����ʧ�ܶ����ͷ���ʾ��ָ��
		pWin->flag = false;
		//��½�ɹ���־�������˳���¼���ڵ�keylisten����
	}
	else
	{
		pNotic = new Notic(NULL,5,14,LINES/2-4,COLS/2-6,(char *)"��¼ʧ��",5);
		pNotic->show();
		usleep(1000000);
		delete pNotic;
		memset(((LoginForm  *)pWin)->pWd,0,sizeof(((LoginForm  *)pWin)->pWd));
		pWin->show();		
		key = 0;
		
    }
	
	
}


ActionCancel::ActionCancel(Form *pWin):ActionListen(pWin)
{
	
}

void ActionCancel::DoAction(int &key)
{
    delete pWin;
    endwin();// �˳�Ncurses���ͷ�ռ���ڴ�
    exit(0); //�����˳����ر������ļ�����ֹ����ִ�еĳ���
}
