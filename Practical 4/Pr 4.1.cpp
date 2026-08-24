#include<iostream>
#include<cstdlib>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
void CriticalPatients(int value)
{
    struct Node *Newnode = (struct Node*) malloc(sizeof(struct Node));
    Newnode -> data = value;
    Newnode -> next = head;
    head = Newnode;
}
void RoutinePatients(int value)
{
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode -> data = value;
    newNode -> next = NULL;
    if (head == NULL)
        { /* empty list */
            head = newNode;
            return;
        }
        struct Node *temp = head;
        while (temp -> next != NULL)
            temp = temp->next;
        temp -> next = newNode;
}
void PriorityPatients(int value,int position)
{
    if (position == 1)
        {
            CriticalPatients(value);
            return;
        }
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    struct Node *temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL)
        { printf("Invalid position\n");
        return;
        }
    newNode->next = temp->next;
    temp->next = newNode;
}
void display()
{
    struct Node *temp = head;
    if (temp == NULL)
        {
            cout<<"List is Empty";
            return;
        }
    while (temp != NULL)
    {
        cout<<"\n";
            cout<<temp -> data;
            temp = temp->next;
    }
    cout<<"\n";
}
int main()
{
    int Choice,id,pos;
    cout<<"Choose from type:-";
    cout<<"\n1.Critical Patient \n2. Routine Patient \n3. Priority Patient";
    do{
    cout<<"\nEnter the Choice:";
    cin>>Choice;
    switch(Choice)
    {
    case 1:
        {
            cout<<"Enter the ID of the Patient:";
            cin>>id;
            CriticalPatients(id);
            break;
        }
    case 2:
        {
            cout<<"Enter the ID of the Patient:";
            cin>>id;
            RoutinePatients(id);
            break;
        }
    case 3:
        {
            cout<<"Enter the ID of the Patient:";
            cin>>id;
            cout<<"Enter the Position:";
            cin>>pos;
            PriorityPatients(id,pos);
            break;
        }
    default:
        {
            cout<<"\nInvalid Choice Entered";
            break;
        }
    }
    }while(Choice!=4);
    display();
    return 0;
}
