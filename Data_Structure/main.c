/*Ҫ���������Ա�ĳ�ʼ������ɾ�ռ䣬��ɾԪ�أ����ң����*/ 
#define OVERFLOW -1
#define OK 1
#define ERROR 0
#define MAXSIZE 6   		//�ռ��ʼ��������Ϊ�˼���ռ���չ����ֵȡСһ��
#define INCREMENT 10	//�ռ��������
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef int Status;
typedef int ElemType;
typedef struct {
    ElemType *elem;     		//�洢�ռ��ַ
    int length;		  		//��ǰ˳�����ʵ��Ԫ�صĸ���
    int listsize;	 			//��ǰ����Ĵ洢����
} SqList;

int InitList(SqList *L)		// ��ʼ��˳���
{
	L->elem=(ElemType *)malloc(MAXSIZE*sizeof(ElemType));
	if(!L->elem)  
		exit(OVERFLOW);
	L->elem=0;
    L->listsize=MAXSIZE;
	return OK;
}

int  InsertList (SqList *L, int i, ElemType e) 
{
//����Ԫ��e���뵽˳���L�ĵ�i��λ����
    if (i > L->length)  
    return  ERROR;
    ElemType  *p;
    int  j;
    if(L->length == L->listsize) 
	{		//��˳�����������������ռ�
    	p=(ElemType *)realloc(L->elem, (L->listsize+INCREMENT)*sizeof(ElemType));
        if (!p) 
			exit (OVERFLOW);
        L->elem=p;
        L->listsize += INCREMENT;
    }
    for(j = L->length-1 ; j>=i-1 ; j--) 
		L->elem[j]=L->elem[j-1];
    L->elem[i-1]=e;			//������Ԫ��
    L->length++;
    return OK;
}

void PrintList(SqList L)				// ���˳���Ԫ��
{
    int  i;
    for(i=0 ; i<L.length ; i++)
       printf("%d  ", L.elem[i]);
    printf("\n");
}

int SearchList(SqList L, ElemType e)
// ��˳���L�в���ֵΪe�ĵ�һ��Ԫ�أ����ҳɹ�����Ԫ�ص�λ�ã�ʧ�ܷ���-1
{
    int i;
    for(i=0; i<L.length; i++)
        if(L.elem[i]==e)   		// �ҵ���ͬ��Ԫ�أ�����λ��
        	return i;
    return -1;
}

int Del_List1(SqList *L, ElemType e)
// ��˳���L��ɾ��ֵΪe�ĵ�һ��Ԫ�أ�ɾ���ɹ�����Ԫ��λ�ã�ʧ���򷵻�-1
{
    int i, j;
    for(i=0; i<L->length; i++)
        if(L->elem[i]==e)              		// �ҵ���ͬ��Ԫ��
           break;
    if(i<L->length)
	{
        for(j=i; j<L->length -1; j++)			// ɾ��
        L->elem[j]=L->elem[j+1]; 
        L->length--;
        return i;
    }
    return -1;
}

Status  Del_List2(SqList *L, int i, ElemType *e)
// ��˳���L��ɾ����i��Ԫ�أ���ɾԪ���ò���e����
{
	e=0;
    if (i>L->length) 
		return  ERROR;
	int  j;
	e=L->elem[i-1];
    for(j=i; j<L->length; j++) 
    	L->elem[j+1]=L->elem[j];
    --L->length;
	return OK;
}

void main()
{
    SqList  LL;
    ElemType x;
    int r,i;
    printf("(1)��ʼ��˳�����\n");
    if( !InitList(&LL) )  
		return;
    printf("  ��ʼ���ɹ���\n");
    printf("(2)˳���Ĳ����������\n");
    while(1)      
    {
        printf("  �������Ԫ�ص�ֵ(0:����)=>");
        scanf("%d", &x);
        if(x==0)  
            break;
        printf("    �������λ�ã�");
        scanf("%d", &r);
        InsertList(&LL , r , x);
        printf("  ���Ա������");
        PrintList(LL);
    }
    printf("(3)˳����ϵĲ��Ҳ�������\n");
    while(1)      //��˳����в���ָ��ֵ��Ԫ�أ������Ԫ������λ��
    {
    printf("  �������Ԫ�ص�ֵ(0:����)=>");
        scanf("%d", &x);
        if(x==0)
            break;
        r=SearchList(LL , x);
        if(r<0)
            printf("    û�ҵ���\n");
       else
            printf("  �з���������Ԫ�أ�λ��Ϊ��%d\n", r+1);
    }
    printf("(4)˳�����ָ��Ԫ��ֵ��ɾ����������\n");
    while(1)        //��˳�����ɾ��ָ��ֵ��Ԫ��
    {
    printf("  ����ɾ��Ԫ�ص�ֵ(0:����)=>");
        scanf("%d", &x);
        if(x==0)
            break;
        r=Del_List1(&LL , x);
		if(r<0)
            printf("  û�ҵ�\n");
        else {
            printf("  ɾ���ɹ�����ɾԪ�ص�λ���ǣ�%d\n  ���Ա������", r+1);
            PrintList(LL);
        }
    }
    printf("(5)˳�����ָ��Ԫ��λ�õ�ɾ����������\n");
    while(1) 
    {
    	printf("  ����ɾ��Ԫ�ص�λ��(0:����)=>");
        scanf("%d", &r);
        if(r==0)
            break;
        if(!Del_List2(&LL, r , &x))
            printf("  λ��Խ��!\n");
        else {
            printf("  ���Ա������");
            PrintList(LL);
        }
    }
}
