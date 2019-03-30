#include<iostream>
using namespace std;
#include<string.h>
#include<stdlib.h>

#define  OK 1
#define  OVERFLOW -2  
#define  ERROR 0


typedef int ElemType;
typedef int Status;

typedef struct LNode{
     ElemType   data;       
     struct LNode  *next;   
}LNode,*LinkList;   

//2.6 
Status InitList(LinkList &L)
{ 
   L=new LNode;
   L->next=NULL;
   return OK; 
} 

//2.7 
Status GetElem (LinkList L,int i,ElemType &e)
{
 LinkList p=L->next;
 int j=1;
 while(p&&j<i)
 {
  p=p->next;
  ++j;
 }
 if(!p||j>i)
 return ERROR;
 e=p->data;
 return OK;
}
//2.8 
LNode *LocateElem(LinkList L,ElemType e)
{
 LinkList p=L->next;
 while(p&&p->data!=e)
     p=p->next;
 return p;
}

//2.9 
Status LinkInsert(LinkList &L,int i,ElemType e)
{
 LinkList p=L;
 int j=0;
 while(p&&(j<i-1))
 {
  p=p->next;
  ++j;
 }
 if(!p||j>i-1)
     return ERROR;
 LinkList s=new LNode;
 s->data=e;
 s->next=p->next;
 p->next=s;
 return OK;
}

//2.10 
Status ListDelete(LinkList &L,int i)
{
 LinkList p=L;
 int j=0;
 while((p->next)&&(j<i-1))
 {
  p=p->next;
  ++j;
 } 
 if(!(p->next)||(j>i-1))
     return ERROR;
 LinkList q=p->next;
 p->next=q->next;
 delete q;
 return OK;
}

//2.11 
void CreateList_H(LinkList &L,int n)
{
 L=new LNode;
 L->next=NULL;
 for(int i=0;i<n;++i)
 {
  LinkList p=new LNode;
  cin>>p->data;
  p->next=L->next;
  L->next=p;
 }
}

//2.12
void CreateList_R(LinkList &L,int n)
{
 L=new LNode;
 L->next=NULL;
 LinkList r=L;
 for(int i=0;i<n;++i)
 {
  LinkList p=new LNode;
  cin>>p->data;
  p->next=NULL;
  r->next=p;
  r=p;
 }
}

void print(LinkList &L)
{
 LNode*p=L->next;
 while(p)
 {
  cout<<"地址是："<<p<<"數據元素是："<<p->data<<endl; 
  p=p->next;
 }
 cout<<endl;
}

int main(){    
    LinkList h;    
    InitList(h);
 ElemType e;
    int i;
 char choice;
    
 cout<<"  1.創建鏈表"<<endl;
 cout<<"  2.取值元素"<<endl;
 cout<<"  3.查找元素"<<endl;
 cout<<"  4.插入元素"<<endl;
 cout<<"  5.刪除元素"<<endl;
 cout<<"請輸入想要執行的選項"<<endl;
 while(cin>>choice)
 {
 switch(choice)
 {
  case'1':
   InitList(h);
   cout<<"單鏈表要存幾個元素"<< endl;
   cin>>i;
   CreateList_R(h,i);
   print(h);
break;
  
  case'2':
   cout<<"要取第幾個元素？"<<endl;
      cin>>i;
      if(GetElem(h,i,e)==0)
      {
       cout<<"元素不合法"<<endl;
      }
      else
          cout<<"元素位置是"<<e<<endl;
  break;
  case'3':
   cout<<"要查詢第幾個元素？"<<endl;
      cin>>i;
      if(LocateElem(h,e)==0)
      {
       cout<<"位置不合法"<<endl;
      }
      else
          cout<<"第"<<i<<"個元素是"<<e<<endl;
  break;
  case'4':
      cout<<"要在第幾個位置插入"<<endl;
      cin>>i;
      cout<<"要插入甚麼元素？"<<endl;
      cin>>e;
      if(LinkInsert(h,i,e)==0)
      {
       cout<<"插入位置錯誤"<<endl; 
      }
     break;
  
  case'5':
   cout<<"要刪除第幾個元素？"<<endl;
      cin>>i;
      if(ListDelete(h,i)==0)
      {
       cout<<"刪除位置不合法"<<endl;
      }
      else
          cout<<"要刪除的元素是："<<e<<endl;
  break;
 }
 }  
 return 0;
}