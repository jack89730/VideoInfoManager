/************************************************************************
* ��Ȩ����  (c)2008,   ׿Խ�����ְҵ��ѵѧУ��
* �ļ����ƣ� List.c

  * ����ժҪ��
  *     ���ļ�ʵ�ֹ���������������Ĺ��ܡ�
  * ��ʷ��¼��
  *     �������ڣ�2013-08-05   �޸��ˣ�����ľ
*************************************************************************/
#include <stdio.h>
#include <malloc.h>
#include <string.h> //memset()ͷ�ļ�
#include "../List/List.h"
#include "../Control/Control.h"

pList List_init(void * data)
{
	pList head;
	head = (pList) malloc(sizeof(struct List));// ������ռ�
	if (head == NULL)
	{
		printf("Memory error.\n");
		return NULL;
	}
	memset(head,0,sizeof(struct List));// ����
	head->pData = data;// ������ֵ
	return head;
}




void List_add(pList head,void *pData)
{
	pList ps,pNew,pt;
	if (head->pNext != NULL&&head->pData != NULL)
	{
		printf("ͷ���û�г�ʼ��");
		return;
	}
	pNew = List_init(pData);
	ps = head;
	pt = head;
	while(head->pNext)
	{
		ps = pt;
		pt=pt->pNext;
		if (pt->pNext == head->pNext)
			break;
	}

	pt->pNext = pNew;
	((head->pNext)->pRev) = pNew;
	pNew->pRev = ps->pNext;
	pNew->pNext = head->pNext;
}



int  List_count(pList head)
{
	pList pL;
	int nCount = 0;
	pL=head->pNext;
	while(pL)
	{
		nCount++;
		pL=pL->pNext;
		if(pL == head->pNext)
			break;
	}
	return nCount;
}



void List_free(pList head)
{
	pList pd,
	pt = head->pNext;
	while(pt)
	{
		pd=pt->pNext;
		delete (Control *)(pt->pData);// ���ͷ�������ռ�
		free(pt);// ���ͷŽ��ռ�
		if (pd == head->pNext)
	    break;
		pt = pd;
	}
		free(head);// ����ͷ�ͷ���
}
