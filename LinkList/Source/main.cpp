#define _CRT_SECURE_NO_WARNINGS 1
#include <malloc.h>
#include<stdio.h>
#include<stdlib.h>
#include"Headers.h"
struct LNode* L, * p, * N;//L为单链表的头节点，作全局变量，可以直接在各个函数中调用
int W = 0;//W用来记录单链表的节点数
struct LNode1* L1, * p1, * N1;
int W1 = 0;//用来记录双链表的节点数
void mulu()
{
	printf("  ******************************************\n");
	printf("  ***1.生成链表***          ***6.删除节点***\n");
	printf("  ***2.插入节点***          ***7.找到中点***\n");
	printf("  ***3.反转链表***          ***8.奇偶反转***\n");
	printf("  ***4.查询节点***          ***9.链表成环***\n");
	printf("  ***5.输出链表***          *10.判断是否成环*\n");
	printf("             ***11.销毁链表***\n");
	printf("  **12.生成双向链表**     **13.输出双向链表**\n");
	printf("  ******************************************\n");

}
void mulu1()
{
	printf("******************\n");
	printf("***1.按序号查询***\n");
	printf("***2.按数据查询***\n");
	printf("******************\n");
}
void shengcheng()//生成链表
{
	N = L = p = (LNode*)malloc(sizeof(LNode));
	printf("请输入节点数量：");
	scanf("%d", &W);
	getchar();
	for (int i = 1; i <= W; i++)
	{
		printf("节点%d的数据:", i);
		int w;
		scanf("%d", &w);
		getchar();
		N->data = w;//将数据存入链表
		if (i == W)break;//最后一次不用创建新的链表
		p = (LNode*)malloc(sizeof(LNode));//创建新节点
		N->next = p;//将链表连接
		N = p;
	}
	p->next = NULL;
}
void shuchu()//输出链表
{
	p = L;
	for (int a = 1; a <= W; a++)
	{

		printf("第%d个链表数据：%d\n", a, p->data);
		p = p->next;
	}
}
void charu()//插入数据
{
	struct LNode* t;
	shuchu();
	p = L;
tiao:
	printf("请选择需要插入数据的前一个数据的序号：");
	int a;
	scanf("%d", &a);
	if (a > W)//判断是否插入的节点不存在
	{
		printf("请输入正确的序号\n");
		goto tiao;
	}
	getchar();
	printf("请输入需要插入的数据：");
	int b;
	scanf("%d", &b);
	getchar();
	for (int i = 1; i < a; i++)
	{
		p = p->next;//让指针到达需要修改的节点
	}
	if (p->next != NULL)//判断插入的节点是否为最后一个（否）
	{
		t = p->next;
		N = (LNode*)malloc(sizeof(LNode));
		N->data = b;
		p->next = N;
		N->next = t;
	}
	else//（是）
	{
		N = (LNode*)malloc(sizeof(LNode));
		N->data = b;
		p->next = N;
		N->next = NULL;
	}
	W++;
}
void xiaohui()//销毁链表，释放内存
{
	p = L;
	for (int i = 1; i <= W; i++)
	{
		if (p->next != NULL)
			p = p->next;
		free(L);//用free函数释放内存
		L = p;
	}
}
int panduan()//判断链表是否成环
{
	N = p = L;
	while (1)//N移动的速度是p的两倍，通过判断是否能相遇来判断能否成环
	{
		if (N->next == NULL)
		{
			printf("该链表不成环！！！\n");
			return 0;
		}
		N = N->next;
		if (N == p)
		{
			printf("该链表成环！！！\n");
			return 1;
		}
		if (N->next == NULL)
		{
			printf("该链表不成环！！！\n");
			return 0;
		}
		N = N->next;
		if (N == p)
		{
			printf("该链表成环！！！\n");
			return 1;
		}
		p = p->next;
	}
}
void fanzhuan()//反转链表
{
	if (panduan() == 1)
	{
		printf("链表已经成环，无法反转\n");
		goto tiao;
	}
	struct LNode* t;
	p = L;
	N = p->next;
	t = N->next;
	for (int i = 1; i < W; i++)
	{
		N->next = p;//通过迭代实现对链表的反转
		p = N;
		N = t;
		if (N->next != NULL)
			t = N->next;
	}
	L->next = NULL;//释放原来链表头指针
	L = N;//反转后的头指针
	printf("反转链表成功！！！");
tiao:
	;
}

void chaxun1()//按序号查询链表
{
tiao:
	printf("请输入需要查询的序号：");
	int a;
	scanf("%d", &a);
	getchar();
	if (a > W)
	{
		printf("请输入正确的序号\n");
		goto tiao;
	}
	p = L;
	for (int i = 1; i < a; i++)
	{
		p = p->next;
	}
	printf("序号为%d的数据为%d\n", a, p->data);
}
void chaxun2()//按数据内容查询链表
{
	printf("请输入需要查询的数据：");
	int a;
	scanf("%d", &a);
	getchar();
	p = L;
	for (int i = 1; i <= W; i++)
	{
		if (p->data == a)
		{
			printf("该数据存在！！！\n");
			break;
		}
		if (i == W)printf("该数据不存在！！！\n");
		p = p->next;
	}
}
void shanchu()//删除节点
{
	struct LNode* t;

	shuchu();
tiao:
	printf("请输入需要删除的节点：");
	p = L;
	int a;
	scanf("%d", &a);
	getchar();
	if (a > W)
	{
		printf("请输入正确的序号：\n");
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
		for (int i = 1; i < a - 1; i++)//到达需要删除节点的前一个节点
		{
			p = p->next;
		}
		t = p->next;//t为需要删除的节点
		if (t->next != NULL)
			N = t->next;//N为t的下一个节点
		else
			N = NULL;
		p->next = N;
		t->next = NULL;
		free(t);
	}
	printf("删除成功！！！");
	W--;
}
void chaxun()//查询链表
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
void zhongdian()//找到中点
{
	if (panduan() == 1)
	{
		return;
	}
	N = p = L;
	int a = 1;
	while (1)
	{
		p = p->next;//P点每次移动一步
		a++;
		if (N->next == NULL)break;//这里判断下一节点是否为空，为空的话可以直接结束
		N = N->next;
		if (N->next == NULL)break;
		N = N->next;//N点每次移动两步
		if (N->next == NULL)break;
	}
	printf("中间节点的序号为%d\n", a);
	printf("中间节点的数据为%d\n", p->data);
}
void jiou()//奇偶反转
{
	if (panduan() == 1)
	{
		return;
	}
	p = L;
	if (p->next != NULL)//判断是否节点只有一个
	{
		N = p->next;
		while (1)
		{
			int a = p->data;
			p->data = N->data;
			N->data = a;
			if (N->next == NULL)break;
			N = N->next;
			p = N;//p点每次移动一步
			if (N->next == NULL)break;
			N = N->next;//N点每次移动两步
		}
	}
	printf("奇偶反转成功！！！\n");
}
void chenghuan()//将单向链表改为循环链表
{
	p = L;
	for (int i = 1; i < W; i++)
	{
		p = p->next;
	}
	p->next = L;//将最后一个节点进行连接
	printf("链表已经成环！！！\n");
}
void shuangxiang()//生成双向链表
{
	p1 = L1 = (LNode1*)malloc(sizeof(LNode1));
	printf("请输入链表的节点数：");
	int a;
	scanf("%d", &a);
	getchar();
	W1 = a;
	for (int i = 1; i <= a; i++)
	{
		printf("请输入节点%d的数据：", i);
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
void shuchu1()//输出双向链表
{
	p1 = L1;
	for (int i = 1; i <= W1; i++)
	{
		printf("第%d个节点的数据为%d\n", i, p1->data);
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
		printf("请按任意键继续....");
		getchar();
		system("cls");
	}
tiao:
	;
}