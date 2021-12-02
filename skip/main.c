#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
    
      int key;
      Node **forward;
      Node(int,int);
};
Node::Node(int key,int level)
{
    this->key=key;
    forward=new Node*[level+1];
    memset(forward,0,sizeof(struct node*)*(level+1));
};
class skiplist
{
    int maxlvl;
    float p;
    int level;
    Node *head;
    public:
       skiplist(int,float);
       int randomlevel();
       Node* creatNode(int,int);
       void insertElement(int);
       void display();
       void search(int);
       void delete_node(int);
};
skiplist::skiplist(int maxlvl,float p)
{
    this->maxlvl=maxlvl;
    this->p=p;
    level=0;
    head=new Node(-1,maxlvl);
};
int skiplist::randomlevel()
{
    float r=(float)rand()/RAND_MAX;
    int lvl=0;
    while(r<p && lvl<maxlvl)
    {
        lvl++;
        r=(float)rand()/RAND_MAX;
    }
    return lvl;
};
Node* skiplist::creatNode(int key,int level)
{
    Node *n=new Node(key,level);
    return n;
};
void skiplist::insertElement(int key)
{
    Node *current=head;
    Node *update[maxlvl+1];
    memset(update,0,sizeof(struct node*)*(maxlvl+1));
    for(int i=level;i>=0;i--){
        while(current->forward[i]!=NULL && current->forward[i]->key<key){
            current=current->forward[i];
        }
        update[i]=current;
    }
    current=current->forward[0];
    if(current==NULL || current->key!=key){
        int rlevel=randomlevel();
        if(rlevel>level){
            for(int i=level+1;i<rlevel+1;i++){
                update[i]=head;
            }
            level=rlevel;
        }
        Node *n=creatNode(key,rlevel);
        for(int i=0;i<=rlevel;i++){
            n->forward[i]=update[i]->forward[i];
            update[i]->forward[i]=n;
        }
        cout<<"Successfully Inserted key\n";
    }
};
void skiplist::search(int key)
{
    Node *current=head;
    Node *update[maxlvl+1];
    memset(update,0,sizeof(struct node*)*(maxlvl+1));
    for(int i=level;i>=0;i--){
        while(current->forward[i]!=NULL && current->forward[i]->key<key){
            current=current->forward[i];
        }
        update[i]=current;
    }
    current=current->forward[0];
    if(current && current->key==key){
        cout<<"Found Key : "<<key<<"\n";
    }
    else{
        cout<<"Key not found\n";
    }
};
void skiplist::delete_node(int key)
{
    Node *current=head;
    Node *update[maxlvl+1];
    memset(update,0,sizeof(struct node*)*(maxlvl+1));
    for(int i=level;i>=0;i--){
        while(current->forward[i]!=NULL && current->forward[i]->key<key){
            current=current->forward[i];
        }
        update[i]=current;
    }
    current=current->forward[0];
    if(current!=NULL && current->key==key){
        for(int i=0;i<=level;i++){
            if(update[i]->forward[i]!=current)
                break;
            update[i]->forward[i]=current->forward[i];
        }
        while(level>0 && head->forward[level]==0){
            level--;
        }
        cout<<"Successfully Deleted  Key "<<key<<"\n";
    }
    else{
        cout<<"Deletion Unsuccessful\n";
    }
};
void skiplist::display()
{
    for(int i=0;i<=level;i++)
    {
        Node *node = head->forward[i];
        cout<<"Level "<<i<<" : ";
        while(node != NULL)
        {
            cout<<node->key<<" ";
            node = node->forward[i];
        }
        cout<<"\n";
    }
};
int main()
{
    int choice,n,i,j;
    srand((unsigned)time(0));
    skiplist lst(3, 0.5);
    for(;;){
        cout<<"\n1.Insertion\n2.Deletion\n3.Search\n4.Display\n5.Exit\n";
        cin>>choice;
        switch(choice){
            case 1: cout<<"Enter element : ";
                cin>>n;
                lst.insertElement(n);
                break;
            case 2: cout<<"Enter element : ";
                cin>>n;
                lst.delete_node(n);
                break;
            case 3: cout<<"Enter element : ";
                cin>>n; 
                lst.search(n);
                break;
            case 4: lst.display();
                break;
            case 5: exit(0);
            default: cout<<"Enter proper instruction\n";
        }
    }
    return 0;
}
