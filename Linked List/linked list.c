// Linked List Basic Operations 
#include<stdio.h>
#include<stdlib.h>
void append(void);
void addBegin(void);
void addAfter(void);
int length();
void display(void);
void delete(void);
int len;
struct node
{
    int data;
    struct node* link;
};
struct node* root=NULL;
int main()
{
    /* Menu Driven Program */
    int o;
    while(1){
    printf("Enter Opearation : \n");
    printf("1.Append\n");
    printf("2.addBegin\n");
    printf("3.addAfter\n");
    printf("4.Length\n");
    printf("5.Display\n");
    printf("6.Delete\n");
    printf("7.Quit\n");
    scanf("%d",&o);
   
switch (o)
{
case 1 :
    append();
    break;
case 2 :
    addBegin();
    break;
case 3 :
    addAfter();
    break;
case 4 :
    length();
    len = length();
    printf("Length : %d\n\n",len);
    break;
case 5 :
    display();
    break;
case 6 :
    delete();
    break;
case 7 :
    exit(1);
    break;
default:
    printf("Invalid Operation\n");
    break;
}
}
    return 0;
}

void append()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter node data :");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(root==NULL)
    { 
        root=temp;
    }
    else if(root!=NULL)
    {
        struct node *p;
        p=root;
        while(p->link!=NULL)
        {
            p = p->link;
        }
        p->link=temp;
    }

}

int length()
{
    struct node* temp;
   int count=0;
   temp=root;
   while(temp!=NULL)
   {
       count++;
       temp=temp->link;
   }
   return count;
    
}
void display()
{
    struct node* temp;
    temp=root;
    if(temp==NULL)
    {
        printf("List Empty\n\n");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d-->",temp->data);
            temp=temp->link;
        }
        printf("\n\n");
    }
    
}
void delete()
{

}
void addBegin()
{

}
void addAfter()
{

}