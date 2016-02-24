#include <string.h>
#include "../LoginForm/LoginForm.h"
#include "../LoginForm/LoginAction.h"

LoginForm::LoginForm(int height,int width,int starty,int startx,int contype)
                    :Form(height,width,starty,startx,contype)
{
	
    Control *pCom;
    ActionListen *pAction;
	strcpy(role_id,"");
    pCom = new Label(this->pCon,3,30,1,8,(char *)"��Ƶ�㲥������������̨����",1);
    List_add(pfirst,pCom);
	pCom = new Label(this->pCon,3,10,4,8,(char *)"�û�����",1);
    List_add(pfirst,pCom);
	pCom = new Label(this->pCon,3,10,7,8,(char *)"��  �룺",1);
    List_add(pfirst,pCom);
    pCom = new Edit(this->pCon,3,20,4,18,10,1,2,true);
	pName = pCom->Getdata();
    List_add(pfirst,pCom);
    pCom = new Edit(this->pCon,3,20,7,18,6,2,2);
    pWd = pCom->Getdata();
    List_add(pfirst,pCom);
    pCom = new Button(this->pCon,3,10,11,10,(char *)"  ��¼  ",3);
    pAction = new ActionEnter(this);
    ((Button *)pCom)->AddAction(pAction);
    List_add(pfirst,pCom);
    pCom = new Button(this->pCon,3,10,11,27,(char *)"  ȡ��  ",3);
    pAction = new ActionCancel(this);
    ((Button *)pCom)->AddAction(pAction);
    List_add(pfirst,pCom);

}


