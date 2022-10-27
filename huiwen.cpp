#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Maxsize 20

//����˳���б�ṹ�� 
typedef struct PalindromeQueue                       
{
	char LinlistQ[Maxsize];
	int front ;
	int rear ;
}PalindromeQueue;

//����˳��ջ�ṹ��
typedef struct PalindromeStack                             
{
	char LinklistS[Maxsize];
	int top;
}PalindromeStack;

//��ʼ��ָ�� 
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
			printf("���ַ����в��ǻ������� \n");
			break;
		}
		(S->top)--;
		(Q->front)++;
	}
	if (S->top = -1 && Q->front == Q->rear)
	{ 
		printf("������ʽ�ǻ������� \n"); 
	} 
}

int main()
{
	int j=0;
	char List[Maxsize];
	PalindromeQueue  Q;
	PalindromeStack  S;  
	printf("������һ����Ҫ�ж��Ƿ��ǡ��������С����ַ����в���'@'�ַ���Ϊ������ʶ��\n");  
	while(1)//����ĺϷ��Լ���
	{
		scanf("%s",List,sizeof(List)); //sizeofʱ��һ�����������ɲ���������������ռ�ڴ���
		if(List[strlen(List)-1] != '@')
		{    //strlen(char*)��һ��������������ַ�����ʵ�ʳ��ȣ��ӵ�һ��'\0'��ʼ��'\0'������������븳ֵ
			printf("���벻�Ϸ����������н���ʱδ��'@',����������\n");
			continue;
		}
		break;
	}  
	
	Init(&Q,&S);//��ʼ�����к�ջ
	while(List[j] != '@')
	{
		Q.LinlistQ[j]=List[j];//�������
		Q.rear++; //��β����
		S.LinklistS[j]=List[j];//��ջ
		S.top++;
		j++;  
	} 
	Judje(&Q,&S);//�ж��Ƿ��ǻ�������
	return 0;
}