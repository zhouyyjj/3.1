#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Maxsize 20

//定义顺序列表结构体 
typedef struct PalindromeQueue                       
{
	char LinlistQ[Maxsize];
	int front ;
	int rear ;
}PalindromeQueue;

//定义顺序栈结构体
typedef struct PalindromeStack                             
{
	char LinklistS[Maxsize];
	int top;
}PalindromeStack;

//初始化指针 
void Init(PalindromeQueue *Q,PalindromeStack *S)            
{     
	Q->front=Q->rear=0;
	S->top=-1;
}

void Judje(PalindromeQueue *Q,PalindromeStack *S)
{
	while (S->top != -1 )
	{
		if(Q->LinlistQ[Q->front] != S->LinklistS[S->top]){
			printf("该字符序列不是回文序列 \n");
			break;
		}
		(S->top)--;
		(Q->front)++;
	}
	if (S->top = -1 && Q->front == Q->rear)
	{ 
		printf("该序列式是回文序列 \n"); 
	} 
}

int main()
{
	int j=0;
	char List[Maxsize];
	PalindromeQueue  Q;
	PalindromeStack  S;  
	printf("请输入一段需要判断是否是“回文序列”的字符序列并以'@'字符作为结束标识符\n");  
	while(1)//输入的合法性检验
	{
		scanf("%s",List,sizeof(List)); //sizeof时是一个操作符，可测量变量声明后所占内存数
		if(List[strlen(List)-1] != '@')
		{    //strlen(char*)是一个函数，求的是字符串的实际长度，从第一个'\0'开始到'\0'结束，所测必须赋值
			printf("输入不合法，输入序列结束时未加'@',请重新输入\n");
			continue;
		}
		break;
	}  
	
	Init(&Q,&S);//初始化队列和栈
	while(List[j] != '@')
	{
		Q.LinlistQ[j]=List[j];//进入队列
		Q.rear++; //队尾后移
		S.LinklistS[j]=List[j];//进栈
		S.top++;
		j++;  
	} 
	Judje(&Q,&S);//判断是否是回文序列
	return 0;
}