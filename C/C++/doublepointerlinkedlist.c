#include<iostream>
using namespace std;
#include<math.h>
#define TRUE 1
#define FALSE 0
# define STACKSIZE 10

/***********/
struct node{
int info;
struct node *next;
};

/**********/
struct node *GetNode(){
struct node *p;
p=(struct node *)malloc(sizeof(struct node));
return p;
}
/**********/
void InsBeg(struct node **s,int x){
struct node *temp;
temp =GetNode();
temp->info=x;
temp->next=(*s);
(*s)=temp;
 }
/***********/
void InsAft(struct node **q,int x){
    struct node *temp;
    temp=GetNode();
    temp->info=x;
    temp->next=(*q)->next;
    (*q)->next=temp;

}
/***********/
void InsEnd(struct node **s,int x){
struct node * q;
q=(*s);
while(q->next!=NULL){
        q=q->next;
}
struct node * p;
p=GetNode();
p->info=x;
p->next=NULL;
q->next=p;
}
/**********/
 void Traverse(struct node **s){
 struct node *t;
 t=(*s);
 while(t!=NULL){
    cout<<t->info<<" ";
    t=t->next;
 }
 cout<<endl;
 }
 /**********/
 int DelBeg(struct node **s){
 struct node *p;
 int x;
 p=(*s);
 x=p->info;
 (*s)=(*s)->next;
 free(p);
 return x;
 }
 /***********/
 int DelEnd(struct node **s){
 struct node *p;
 struct node *q;
 p=(*s);
 q=NULL;
 while(p->next!=NULL){
    q=p;
    p=p->next;

 }
 q->next=NULL;
 int x=p->info;
 free(p);
 return x;
 }
 /**********/
 int DelAft(struct node **q){
 struct node *p;
 struct node *r;
 int x;
 p=(*q)->next;
 r=p->next;
 (*q)->next=r;

 x=p->info;
 free(p);
 return x;
 }
 /************/
 void DeleteAllOccurence(struct node **s,int x){
    struct node *p=(*s);
    struct node *q=NULL;
    int y;
    while(p!=NULL){
        if(p->info==x){
            p=p->next;
            if(q==NULL){
               y=DelBeg(s);
            }
            else{
                y=DelAft(&q);
            }
        }
        else{
            q=p;
            p=p->next;
        }
    }
}
/***********/

/***********/
 int main(){
 struct node *start=NULL;
struct node *t;
 InsBeg(&start,1);
 InsBeg(&start,2);
 InsBeg(&start,3);
 InsBeg(&start,6);
 InsBeg(&start,5);
 InsBeg(&start,6);
 InsEnd(&start,0);
 Traverse(&start);
t=start;
while(t->info!=3)
    t=t->next;
InsAft(&t,6);
Traverse(&start);
int x=DelBeg(&start);
Traverse(&start);
int y=DelEnd(&start);
Traverse(&start);
t=start;
while(t->info!=4)
    t=t->next;
int z=DelAft(&t);
Traverse(&start);
DeleteAllOccurence(&start,6);
Traverse(&start);
 }
