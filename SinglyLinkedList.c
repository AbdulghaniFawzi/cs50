#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct sllist{
    int num;
    struct sllist* next;
}node;

void firstNode(node* first ,int n);
void addEnd(node*first,int n);
void addFirst(node*first,int n);
void addMid(node*first,int m,int n);
void displayList(node*first);
int Count(node*first);
void deletFirst(node*first);
void deletEnd(node*first);
void deletMid(node*first,int m);
bool search(node *first, int s);


//declaration the list 
int main (void)
{
    node* first=NULL;
    int i=0;
    int o= 15;
    int x=1;
    int m=8;
    int s=12;
    for(i=0;i<o;i++)
    firstNode(first ,i);
    addEnd(first,x);
    addFirst(first,s);
    addMid(first,m,x);
    displayList(first);
    Count(first);
    deletFirst(first);
    deletEnd(first);
    deletMid(first,m);
    search(first,s);
}
//creat first node and store values in
void firstNode(node* first ,int n)
{
    if(first==NULL)
    {
        first=malloc(sizeof(node));
        first->num=n;
        first->next=NULL;
    }
    else
    {
        printf("error in memoray");
    }
}

// add nodes in the end of list (right)

void addEnd(node*first,int n)
{
    node* move, *neo;
    move=first;
    while(move->next!=NULL)
    {
        move=move->next;
    }
    neo=malloc(sizeof(node));
    
    neo->num=n;
    neo->next=NULL;
    move->next=neo;
}

//add nodes in the first (left)
void addFirst(node*first,int n)
{
    node* move,*neo;
    move=first;
    neo=malloc(sizeof(node));
    neo->num=n;
    neo->next=NULL;
    neo->next=move;
    first=neo;
}

//add nodes in the middle

void addMid(node*first,int m,int n)
{
    node* move,*neo;
    move=first;
    while(move->num!=m && move->next!=NULL)
    {
       move=move->next;
    }
    neo=malloc(sizeof(node));
    neo->num=n;
    neo->next=move->next;
    move->next=neo;
    
}

// view all nodes into linked list
void displayList(node*first)
{
    node* move;
    move=first;
    while(move!=NULL)
    {
        printf("value:%d \n",move->num);
        move=move->next;
    }
}

//count the nodes which are inside the list
int Count(node*first)
{
    node* move;
    move= first;
    int count=0;
    while(move!=NULL)
    {
        count++;
        move=move->next;
    }
    return count;
}

//delet node from the first (left)
void deletFirst(node*first)
{
    node* d;
    if(first->next !=NULL)
    {
        d=first->next;
        d->next=first->next->next;
        free(first);
        first=d;
    }
    else
    {
        free(first);
    }
}

//delete nodes from the end (right)
void deletEnd(node*first)
{
    node* move,*d;
    move=first;
    while(move->next->next!=NULL)
    {
        move=move->next;
    }
    d=move->next;
    move->next=NULL;
    free(d);
    
}

//delete node from middle
void deletMid(node*first,int m)
{
    node* move,*d;
    move=first;
    while(move->next->num!=m && move->next->next!=NULL)
    {
        move=move->next;
        
    }
    d=move->next;
    move->next=d->next;
    free(d);
}

//search for value in list
bool search(node *first, int s)
{
    node *move;
    move=first;
    while(move!=NULL)
    {
        if(move->num==s)
        {
            return true;
        }
       // printf("the value %d is founded\n",first->num);
        
        else if(move->num!=s &&move->next !=NULL)
        {
            move=move->next;
        }
    }
    return false;
}

