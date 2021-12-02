#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
struct node
{
    int data;
    struct node *npx;
};
struct node*  xor(struct node *x,struct node *y)
{
    return (struct node *)((uintptr_t)(x) ^ (uintptr_t)(y));
}
void insert(struct node **head,int data)
{
    struct node *new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->npx=xor(*head,NULL);
    if(*head!=NULL)
    {
        struct node *next=xor((*head)->npx,NULL);
        (*head)->npx=xor(new_node,next);
    }
    (*head)=new_node;
}
void traverse(struct node *head)
{
    struct node *cur=head;
    struct node *prev=NULL;
    struct node *next;
    while(cur!=NULL)
    {
        printf("%d\t",cur->data);
        next=xor(prev,cur->npx);
        prev=cur;
        cur=next;
    }
    printf("\n");
}
void delete_last(struct node *head)
{
    struct node *cur=head;
    struct node *prev=NULL;
    struct node *next;
    while(xor(cur->npx,prev)!=NULL)
    {
        next=xor(prev,cur->npx);
        prev=cur;
        cur=next;
    }
    if(prev!=NULL)
    {
        prev->npx=xor(xor(prev->npx,cur),NULL);
    }
    else
    {
        head=NULL;
    }
    free(cur);
}
int main()
{
    int choice;
    int data;

    struct node *head=NULL;
    do{
        printf("1:INSERT\n");
        printf("2:TRAVERSE\n");
        printf("3:DELETE THE LAST NODE\n");
        printf("4:Quit\n");
        printf("Enter Your Choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("Enter the value you want to insert\n");
                scanf("%d",&data);
                insert(&head,data);
                break;
            case 2:traverse(head);
                break;
            case 3:delete_last(head);
                break;
        }
    }while(choice!=4);
    return 0;
}
