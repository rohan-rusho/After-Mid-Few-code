#include<iostream>
using namespace std;
const int MAX = 20;
int Stack[MAX];
int top=-1;

void push(int element)
{
        if (top == MAX - 1)
        {
            cout << "Error: Stack overflow." << endl;
            return;
        }
        else
         {
            top++;
        Stack[top] = element;
         }
}

    int pop() {
    int element;
        if (top == -1) {
            cout << "Error: Stack underflow." << endl;
            return -1;
        }
        else

        element = Stack[top];
        top--;

        return element;
    }

    int Top() {
        if (top == -1) {
            cout << "Error: Stack underflow." << endl;
            return -1;
        }
        return Stack[top];
    }

    void display()
    {

   if(top>=0)
   {
      cout<<"Stack elements are:";
      for(int i=0; i<=top; i++)
      cout<<Stack[i]<<" ";
      cout<<endl;
   }
   else cout<<"Stack is empty";

    }


    int main ()
    {

         push(10);
         push(20);
         push(40);
         push(70);
        display();
        cout<<"After Pop: "<<pop()<<endl;
        display();
        push(100);
        display();
        cout<<"After Pop: "<<pop()<<endl;
        display();
         return 0;
    }