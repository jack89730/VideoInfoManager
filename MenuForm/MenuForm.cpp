#include "../MenuForm/MenuForm.h"
#include "../MenuForm/MenuDb.h"
#include "../DbCon/DbCon.h"
#include "../MenuForm/MenuAction.h"
#include <string.h>


/*************************************************************************************
 MenuForm�˵������๫�г�Ա�����Ķ���

*************************************************************************************/
MenuForm *MenuForm::pForm = NULL;
MenuForm::MenuForm(int height,int width,int starty,int startx,int contype,char *role)
                  :Form(height,width,starty,startx,contype)
                  
{
	pForm = this;
	char sql[300] = "";
    sprintf(sql,"select * from Tbl_menu where menu_id in (select menu_id from Tbl_role_menu where role_id = %s)",role);  
    (DbSingles::GetSingle())->GetData(sql,Menu_Callback,pfirst);

}


void MenuForm::show()
{
	pList pTemp;
    Control *fp;
	clear();
	curs_set(0);// �رչ��
	wbkgd(stdscr,COLOR_PAIR(2));	
	mvhline(0,0,0,COLS);// �������˵���ˮƽ��
	refresh();

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

}

void MenuForm::KeyListen(int &key)
{
    MenuBar *pMenuBar;
	MenuItem *pMenuItem;
    pList pTemp,pTemp1;
	pTemp = pfirst->pNext;
	while (flag)
	{
		pMenuBar = (MenuBar *)(pTemp->pData);
		pMenuBar->GetFocus();
		pTemp1 = (pMenuBar->psecond)->pNext;
		while (flag)
		{
			pMenuItem = (MenuItem *)(pTemp1->pData);
			pMenuItem->GetFocus();
			key = wgetch(pMenuItem->GetHandle());
			switch(key)
			{
			case KEY_DOWN:
				pTemp1 = pTemp1->pNext;
				break;
			case KEY_UP:
				pTemp1 = pTemp1->pRev;
				break;
			case 10:
				this->menu_sid = pMenuItem->menu_sid;
				pMenuBar->pAction->DoAction(key);
				show();
				pMenuBar->GetFocus();
				break;
			}
			if (key == KEY_LEFT)
			{
				pTemp = pTemp->pRev;
				break;
			}
			else if (key == KEY_RIGHT)
			{
				pTemp = pTemp->pNext;
				break;
			}
			pMenuItem->show();	   
		}
        pMenuBar->show();
	}
}


/*************************************************************************************
 MenuBar�˵�����һ���˵����๫�г�Ա�����Ķ���

*************************************************************************************/
MenuBar::MenuBar(WINDOW *pFather,int height,int width,int starty,int startx,char *colvalu,char *data,int contype)
                   :Control(pFather,height,width,starty,startx,contype)
{
	psecond = List_init(NULL);
	this->data = new char[strlen(data)+1];
	strcpy(this->data,data);
	char sql[300] = "";
    sprintf(sql,"select * from Tbl_menu where menu_fid = %s",colvalu);  
    (DbSingles::GetSingle())->GetData(sql,MenuBar_Callback,psecond);
}

MenuBar::~MenuBar()
{
	delete []data;
	List_free(psecond);
}

void MenuBar::show()
{
	Control *fp;
	pList pTemp;
	pTemp = psecond->pNext;
	while (psecond->pNext)
	{
		fp = (Control *)(pTemp->pData);
		wbkgd(fp->GetHandle(),COLOR_PAIR(5));// �ı���ɫ�ԣ����ض����˵�
		wrefresh(fp->GetHandle());
		pTemp = pTemp->pNext;
		if (pTemp == psecond->pNext)
		{
			break;
		}
	}
    wclear(this->pCon);// ɾ���˵����߿�
	wbkgd(this->pCon,COLOR_PAIR(2));
	mvwprintw(this->pCon,1,(width-strlen(data))/2,"%s",data);
	mvhline(4,0,0,COLS); //�������˵���ˮƽ��
	refresh();
	wrefresh(this->pCon);
		
}

void MenuBar::GetFocus()
{
	Control *fp;
	pList pTemp;

	box(this->pCon,0,0);
	wattron(pCon,A_BOLD);
	mvwprintw(this->pCon,1,(width-strlen(data))/2,"%s",data);
	wrefresh(pCon);
	wattroff(pCon,A_BOLD);
    // ��ʾ��ǰ���˵����ӱ߿������Ӵּ���
	pTemp = psecond->pNext;
	while (psecond->pNext)// ��ʾ��ǰ�˵���ӵ�еĶ����˵�
	{
		fp = (Control *)(pTemp->pData);
	    fp->show();
		pTemp = pTemp->pNext;
		if (pTemp == psecond->pNext)
		{
			break;
		}
	}
	
}
	

void MenuBar::AddAction(char *menu_fid)
{
	int fid;
	sscanf(menu_fid,"%d",&fid);
	switch(fid)// ����һ���˵�ID�����������Ķ����˵��¼�
	{
	case 2000:
			pAction = new ActionSystem(MenuForm::pForm);// ϵͳ�����¼�
			break;
	case 2001:
			pAction = new ActionClient(MenuForm::pForm);//�ͻ��˹����¼�
			break;
	case 2002:
			pAction = new ActionVideo(MenuForm::pForm);//��Ƶ�����¼�
			break;
	case 2003:
			pAction = new ActionTable(MenuForm::pForm);// ����ͳ���¼�
			break;
	case 2004:
			pAction = new ActionLogout(MenuForm::pForm);// �˳���¼�¼�
			break;
	}
}


/*************************************************************************************
 MenuItem�Ӳ˵��������˵����๫�г�Ա�����Ķ���

*************************************************************************************/
MenuItem::MenuItem(WINDOW *pFather,int height,int width,int starty,int startx,char *data,int contype)
                   :Control(pFather,height,width,starty,startx,contype)
{
	this->data = new char[strlen(data)+1];
	strcpy(this->data,data);

}

MenuItem::~MenuItem()
{
	delete []data;
}


void MenuItem::show()
{
	wbkgd(this->pCon,COLOR_PAIR(6));
	mvwprintw(this->pCon,1,(width-strlen(data))/2,"%s",data);
    box(pCon,0,0);
	wrefresh(this->pCon);
}


void MenuItem::GetFocus()
{
	keypad(pCon,true);
	wbkgd(this->pCon,COLOR_PAIR(1));
	wattron(pCon,A_BOLD);
	mvwprintw(this->pCon,1,(width-strlen(data))/2,"%s",data);
	wrefresh(pCon);
	wattroff(pCon,A_BOLD);

}