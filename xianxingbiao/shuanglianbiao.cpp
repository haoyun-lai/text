//
// Created by 76130 on 2025/3/23.
//
#include "stdio.h"
#include "stdlib.h"
//����˫������
typedef struct DNode{
    int data;
    struct DNode *prior,*next;
}DNode,*DLinklist;

//��ʼ��
bool InitList(DLinklist &L){
    L=(DNode*) malloc(sizeof(DNode));
    L->next=NULL;
    L->prior=NULL;
    return true;
}

//��������
int Length(DLinklist &L){
    int len=0;
    DNode *p=L;
    while(p->next!=NULL){
        p=p->next;
        len++;
    }
    return len;
}

//����Ų���
DNode *GetElem(DLinklist &L,int i){
    int j=0;
    DNode *p=L;
    while(j<i&&p!=NULL){
        p = p->next;
        j++;
    }
    return p;
}

//��ֵ����
DNode *LocateElem(DLinklist &L,int e){
    DNode *p=L->next;
    while(p!=NULL&&p->data!=e){
        p = p->next;
    }
    return p;
}

//����ڵ�
bool ListInsert(DLinklist &L,int i,int e){
    DNode *p=L;
    int j=0;
    while(p!=NULL&&j<i-1){
        p = p->next;
        j++;
    }
    if(p==NULL){
        return false;
    }
    DNode *s=(DNode*) malloc(sizeof(DNode));
    s->data=e;
    s->next=p->next;
    p->next->prior=s;
    p->next=s;
    s->prior=p;
    return true;
}

//ɾ���ڵ�
bool ListDelete(DLinklist &L,int i,int &e) {
    DNode *p = L;
    int j = 0;
    while (p != NULL && j < i - 1) {
        p=p->next;
        j++;
    }
    if(p==NULL){
        return false;
    }
    DNode *s=p->next;
    e=s->data;
    p->next=s->next;
    s->next->prior=p;
    free(s);
    return true;
}

//ͷ�巨
DLinklist List_HeadInsert(DLinklist &L){
    DNode *s;
    int n=0;
    scanf("%d",&n);
    while(n!=9999){
        s=(DNode*) malloc(sizeof (DNode));
        s->data=n;
        s->next=L->next;
        if (L->next != NULL) {
            L->next->prior = s;
        }
        L->next=s;
        s->prior=L;
        scanf("%d",&n);
    }
    return L;
}

//β�巨
DLinklist List_TailInsert(DLinklist &L){
    DNode *s,*p=L;
    int n=0;
    scanf("%d",&n);
    while(n!=9999){
        s=(DNode*) malloc(sizeof (DNode));
        s->data=n;
        p->next=s;
        s->prior=p;
        p=s;
        scanf("%d",&n);
    }
    p->next=NULL;
    return L;
}

//��ӡ����
bool dayin(DLinklist &L){
    DNode *p=L->next;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
    return true;
}

int main() {
    DLinklist L;
    InitList(L);
    printf("������ֵ��\n");
    List_HeadInsert(L);
    printf("���ֵ��\n");
    dayin(L);
    printf("��Ϊ��%d\n", Length(L));
    printf("��2���ڵ��ֵΪ��%d\n", GetElem(L, 2)->data);
    ListInsert(L, 2, 5);
    printf("�ڵ�2���ڵ����ֵΪ5��\n");
    dayin(L);
    int m = 0;
    ListDelete(L, 3, m);
    printf("ɾ���������ڵ㣺\n");
    dayin(L);
}