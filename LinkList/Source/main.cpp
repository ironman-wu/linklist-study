#define _CRT_SECURE_NO_WARNINGS 1
#include <malloc.h>
#include<stdio.h>
#include<stdlib.h>
#include"Headers.h"
struct LNode* L, * p, * N;//LΪ�������ͷ�ڵ㣬��ȫ�ֱ���������ֱ���ڸ��������е���
int W = 0;//W������¼������Ľڵ���
struct LNode1* L1, * p1, * N1;
int W1 = 0;//������¼˫����Ľڵ���
void mulu()
{
	printf("  ******************************************\n");
	printf("  ***1.��������***          ***6.ɾ���ڵ�***\n");
	printf("  ***2.����ڵ�***          ***7.�ҵ��е�***\n");
	printf("  ***3.��ת����***          ***8.��ż��ת***\n");
	printf("  ***4.��ѯ�ڵ�***          ***9.����ɻ�***\n");
	printf("  ***5.�������***          *10.�ж��Ƿ�ɻ�*\n");
	printf("             ***11.��������***\n");
	printf("  **12.����˫������**     **13.���˫������**\n");
	printf("  ******************************************\n");

}
void mulu1()
{
	printf("******************\n");
	printf("***1.����Ų�ѯ***\n");
	printf("***2.�����ݲ�ѯ***\n");
	printf("******************\n");
}
void shengcheng()//��������
{
	N = L = p = (LNode*)malloc(sizeof(LNode));
	printf("������ڵ�������");
	scanf("%d", &W);
	getchar();
	for (int i = 1; i <= W; i++)
	{
		printf("�ڵ�%d������:", i);
		int w;
		scanf("%d", &w);
		getchar();
		N->data = w;//�����ݴ�������
		if (i == W)break;//���һ�β��ô����µ�����
		p = (LNode*)malloc(sizeof(LNode));//�����½ڵ�
		N->next = p;//����������
		N = p;
	}
	p->next = NULL;
}
void shuchu()//�������
{
	p = L;
	for (int a = 1; a <= W; a++)
	{

		printf("��%d���������ݣ�%d\n", a, p->data);
		p = p->next;
	}
}
void charu()//��������
{
	struct LNode* t;
	shuchu();
	p = L;
tiao:
	printf("��ѡ����Ҫ�������ݵ�ǰһ�����ݵ���ţ�");
	int a;
	scanf("%d", &a);
	if (a > W)//�ж��Ƿ����Ľڵ㲻����
	{
		printf("��������ȷ�����\n");
		goto tiao;
	}
	getchar();
	printf("��������Ҫ��������ݣ�");
	int b;
	scanf("%d", &b);
	getchar();
	for (int i = 1; i < a; i++)
	{
		p = p->next;//��ָ�뵽����Ҫ�޸ĵĽڵ�
	}
	if (p->next != NULL)//�жϲ���Ľڵ��Ƿ�Ϊ���һ������
	{
		t = p->next;
		N = (LNode*)malloc(sizeof(LNode));
		N->data = b;
		p->next = N;
		N->next = t;
	}
	else//���ǣ�
	{
		N = (LNode*)malloc(sizeof(LNode));
		N->data = b;
		p->next = N;
		N->next = NULL;
	}
	W++;
}
void xiaohui()//���������ͷ��ڴ�
{
	p = L;
	for (int i = 1; i <= W; i++)
	{
		if (p->next != NULL)
			p = p->next;
		free(L);//��free�����ͷ��ڴ�
		L = p;
	}
}
int panduan()//�ж������Ƿ�ɻ�
{
	N = p = L;
	while (1)//N�ƶ����ٶ���p��������ͨ���ж��Ƿ����������ж��ܷ�ɻ�
	{
		if (N->next == NULL)
		{
			printf("�������ɻ�������\n");
			return 0;
		}
		N = N->next;
		if (N == p)
		{
			printf("������ɻ�������\n");
			return 1;
		}
		if (N->next == NULL)
		{
			printf("�������ɻ�������\n");
			return 0;
		}
		N = N->next;
		if (N == p)
		{
			printf("������ɻ�������\n");
			return 1;
		}
		p = p->next;
	}
}
void fanzhuan()//��ת����
{
	if (panduan() == 1)
	{
		printf("�����Ѿ��ɻ����޷���ת\n");
		goto tiao;
	}
	struct LNode* t;
	p = L;
	N = p->next;
	t = N->next;
	for (int i = 1; i < W; i++)
	{
		N->next = p;//ͨ������ʵ�ֶ�����ķ�ת
		p = N;
		N = t;
		if (N->next != NULL)
			t = N->next;
	}
	L->next = NULL;//�ͷ�ԭ������ͷָ��
	L = N;//��ת���ͷָ��
	printf("��ת����ɹ�������");
tiao:
	;
}

void chaxun1()//����Ų�ѯ����
{
tiao:
	printf("��������Ҫ��ѯ����ţ�");
	int a;
	scanf("%d", &a);
	getchar();
	if (a > W)
	{
		printf("��������ȷ�����\n");
		goto tiao;
	}
	p = L;
	for (int i = 1; i < a; i++)
	{
		p = p->next;
	}
	printf("���Ϊ%d������Ϊ%d\n", a, p->data);
}
void chaxun2()//���������ݲ�ѯ����
{
	printf("��������Ҫ��ѯ�����ݣ�");
	int a;
	scanf("%d", &a);
	getchar();
	p = L;
	for (int i = 1; i <= W; i++)
	{
		if (p->data == a)
		{
			printf("�����ݴ��ڣ�����\n");
			break;
		}
		if (i == W)printf("�����ݲ����ڣ�����\n");
		p = p->next;
	}
}
void shanchu()//ɾ���ڵ�
{
	struct LNode* t;

	shuchu();
tiao:
	printf("��������Ҫɾ���Ľڵ㣺");
	p = L;
	int a;
	scanf("%d", &a);
	getchar();
	if (a > W)
	{
		printf("��������ȷ����ţ�\n");
		goto tiao;
	}
	if (a == 1)
	{
		L = L->next;
		p->next = NULL;
		free(p);
	}
	else
	{
		for (int i = 1; i < a - 1; i++)//������Ҫɾ���ڵ��ǰһ���ڵ�
		{
			p = p->next;
		}
		t = p->next;//tΪ��Ҫɾ���Ľڵ�
		if (t->next != NULL)
			N = t->next;//NΪt����һ���ڵ�
		else
			N = NULL;
		p->next = N;
		t->next = NULL;
		free(t);
	}
	printf("ɾ���ɹ�������");
	W--;
}
void chaxun()//��ѯ����
{
	mulu1();
	int a;
	scanf("%d", &a);
	getchar();
	switch (a)
	{
	case 1:
		chaxun1();
		break;
	case 2:
		chaxun2();
		break;
	}
}
void zhongdian()//�ҵ��е�
{
	if (panduan() == 1)
	{
		return;
	}
	N = p = L;
	int a = 1;
	while (1)
	{
		p = p->next;//P��ÿ���ƶ�һ��
		a++;
		if (N->next == NULL)break;//�����ж���һ�ڵ��Ƿ�Ϊ�գ�Ϊ�յĻ�����ֱ�ӽ���
		N = N->next;
		if (N->next == NULL)break;
		N = N->next;//N��ÿ���ƶ�����
		if (N->next == NULL)break;
	}
	printf("�м�ڵ�����Ϊ%d\n", a);
	printf("�м�ڵ������Ϊ%d\n", p->data);
}
void jiou()//��ż��ת
{
	if (panduan() == 1)
	{
		return;
	}
	p = L;
	if (p->next != NULL)//�ж��Ƿ�ڵ�ֻ��һ��
	{
		N = p->next;
		while (1)
		{
			int a = p->data;
			p->data = N->data;
			N->data = a;
			if (N->next == NULL)break;
			N = N->next;
			p = N;//p��ÿ���ƶ�һ��
			if (N->next == NULL)break;
			N = N->next;//N��ÿ���ƶ�����
		}
	}
	printf("��ż��ת�ɹ�������\n");
}
void chenghuan()//�����������Ϊѭ������
{
	p = L;
	for (int i = 1; i < W; i++)
	{
		p = p->next;
	}
	p->next = L;//�����һ���ڵ��������
	printf("�����Ѿ��ɻ�������\n");
}
void shuangxiang()//����˫������
{
	p1 = L1 = (LNode1*)malloc(sizeof(LNode1));
	printf("����������Ľڵ�����");
	int a;
	scanf("%d", &a);
	getchar();
	W1 = a;
	for (int i = 1; i <= a; i++)
	{
		printf("������ڵ�%d�����ݣ�", i);
		int b;
		scanf("%d", &b);
		getchar();
		p1->data = b;
		if (i != a)
		{
			N1 = (LNode1*)malloc(sizeof(LNode1));
			p1->next = N1;
			N1->front = p1;
			p1 = N1;
		}
	}
	p1->next = NULL;
}
void shuchu1()//���˫������
{
	p1 = L1;
	for (int i = 1; i <= W1; i++)
	{
		printf("��%d���ڵ������Ϊ%d\n", i, p1->data);
		if (i != W1)
			p1 = p1->next;
	}
}
int main()
{
	while (1)
	{
		mulu();
		int a;
		scanf("%d", &a);
		getchar();
		switch (a)
		{
		case 1:
			shengcheng();
			break;
		case 2:
			charu();
			break;
		case 3:
			fanzhuan();
			break;
		case 4:
			chaxun();
			break;
		case 5:
			shuchu();
			break;
		case 6:
			shanchu();
			break;
		case 7:
			zhongdian();
			break;
		case 8:
			jiou();
			break;
		case 9:
			chenghuan();
			break;
		case 10:
			panduan();
			break;
		case 11:
			xiaohui();
			goto tiao;
		case 12:
			shuangxiang();
			break;
		case 13:
			shuchu1();
			break;
		}
		printf("�밴���������....");
		getchar();
		system("cls");
	}
tiao:
	;
}