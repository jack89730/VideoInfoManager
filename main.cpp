#include <ncurses.h>
#include "Control/Control.h"
#include "LoginForm/LoginForm.h"
#include "MenuForm/MenuForm.h"

int main()
{
    LoginForm *pLog;
	MenuForm *pMenu;
    int key;
    initscr();
    raw();
    noecho();
    start_color();
    init_pair(1,COLOR_WHITE,COLOR_BLUE);
    init_pair(2,COLOR_BLACK,COLOR_WHITE);//����ǰ�󱳾�ɫ
    init_pair(3,COLOR_WHITE,COLOR_RED);  //��ťǰ�󱳾�ɫ
    init_pair(4,COLOR_BLACK,COLOR_BLACK);//��Ӱ��ǰ�󱳾�ɫ
    init_pair(5,COLOR_WHITE,COLOR_WHITE);
	init_pair(6,COLOR_BLACK,COLOR_GREEN);//�����˵�ǰ�󱳾�ɫ
	init_pair(7,COLOR_RED,COLOR_WHITE);  //��ʾ��ǰ�󱳾�ɫ
 
	while (1)
	{	
		clear();
		wbkgd(stdscr,COLOR_PAIR(1));
		attron(A_BOLD);
		mvprintw(LINES-1,11,"<���¡�Tab> �ؼ��л�  |  <����> �༭��λ  |  <Enter> ���°�ť");
		refresh();
		pLog = new LoginForm(17,52,(LINES-17)/2,(COLS-52)/2,1);// �½���¼��
		pLog->show();
        pLog->KeyListen(key);
		delete pLog;// ��½�ɹ����ͷŵ�¼��ע������ؽ�
		
	    pMenu = new MenuForm(LINES,COLS,0,0,1,pLog->role_id);// �½��˵�����
	    pMenu->show();
	    pMenu->KeyListen(key);
		delete pMenu; // ѡ��ע�����ܺ��ͷſռ�
		
	}		
		return 0;
}
