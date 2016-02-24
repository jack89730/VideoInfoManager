#include <string.h>
#include "../DbCon/DbCon.h"
#include "../TableForm/TableDb.h"
#include "../TableForm/TableForm.h"
#include "../TableForm/TableAction.h"


TableAction::TableAction(Form *pWin):ActionListen(pWin)
{

}


void TableAction::DoAction(int &key)
{

	int menu_id;
	char sql[256] = "";
	key = 10;
 	if (strcmp(TableForm::pTableForm->menu_id,"") == 0)
	{
		menu_id = 0;
	}
	else
		sscanf(TableForm::pTableForm->menu_id,"%d",&menu_id);
		switch(menu_id)
		{
		case 0:
			sprintf(sql,"select date(\'now\')");//��������ѡ��ʱ��Ĭ�ϴ�ӡȫ��
			(DbSingles::GetSingle())->GetData(sql,Get_CallBack,TableForm::pTableForm->enddate);
			strcpy(TableForm::pTableForm->startdate,"1970-01-01");
			break;
		case 1001://��ʾ���ղ������
			strcpy(TableForm::pTableForm->startdate,"2013-09-28");
			strcpy(TableForm::pTableForm->enddate,"2013-09-28");
			break;
		case 1002://��ʾ���ܲ������
			strcpy(TableForm::pTableForm->startdate,"2013-09-23");
			strcpy(TableForm::pTableForm->enddate,"2013-09-30");
			break;
		case 1003://��ʾ���²������
			strcpy(TableForm::pTableForm->startdate,"2013-09-01");
			strcpy(TableForm::pTableForm->enddate,"2013-09-30");
			break;
		}
		TableForm::pTable->flag = 2;
		TableForm::pTable->KeyListen(key);
}