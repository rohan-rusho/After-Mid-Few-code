#include<iostream>
using namespace std;
   class Box{
   public:
        Box *next, *prev;
        int data;
   };

   Box *start=NULL, *last=NULL;

   void create (int n)
   {

       Box *new_node;
       for(int i=1; i<=n; i++)
       {
           new_node=new Box();
           cout<<"Enter data: ";
           cin>>new_node->data;
           new_node->next=NULL;
           new_node->prev=last;


           if(start==NULL)
           {
             start=new_node;
             last=start;
           }
           else
           {
               last->next=new_node;
               last=last->next;

           }

       }
   }

   void display()
   {
      Box *temp=start;
      cout<<endl;

      while(temp!=NULL)
      {


          cout<<temp<<" "<<temp->data<<" "<<temp->prev<<" "<<temp->next<<endl;
          temp=temp->next;
      }
   }

void Finser(int n1)
{
    Box *new_node;
    new_node=new Box();
    new_node->data=n1;
    new_node->next =NULL;
    new_node->prev=NULL;


    if(start==NULL)
    {

        start=new_node;
    }

    else
    {
        new_node->next=start;
        start->prev = new_node;
        start=new_node;
    }
}


void Linsert(int n2)
{
    Box *new_node;
    new_node=new Box();
    new_node->data=n2;
    new_node->next=NULL;
    new_node->prev=last;
    last->next=new_node;
    last=last->next;
}

void InsertAny(int p, int n3)
{
    Box *temp=start, *new_node;

    for(int i=1; i<p; i++)
        {
        temp=temp->next;
        }
        new_node=new Box();
        new_node->data=n3;
        new_node->prev=temp->prev;
        temp->prev->next=new_node;
        new_node->next=temp;
        temp->prev=new_node;

}

int main ()
{
    int n1,n2,n,op,p,n3;
    cout<<"How Many: ";
    cin>>n;
    create(n);
    display();

    for(;;)
    {

        cout<<"\n1 for first insert. \n2 for Insert any pos. \n3 for Insert Last \n4 for display. \n5 for exit.\n";
        cout<<"Enter option: ";
        cin>>op;

        if(op==1)
        {
            cout<<"Enter Data: ";
            cin>>n1;
           Finser(n1);
        }

        else if(op==2)
        {
            cout<<"Enter Pos: ";
            cin>>p;
             cout<<"Enter Data: ";
            cin>>n3;
            InsertAny(p,n3);
        }

        else if(op==3)
        {
            cout<<"Enter Data: ";
            cin>>n2;
            Linsert(n2);

        }
        else if (op==4)
        {

            display();

        }
        else if(op==5)
        {
            cout<<"<\t\t\n\nExit";

           break;

        }
        else{
            cout<<"\t\t\nInvalid Option.\n\n";
    }
    }
    return 0;

}



