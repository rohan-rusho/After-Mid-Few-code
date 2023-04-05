#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
node *top = NULL;
void push(int val)
{
    node *newnode = new node();
    newnode->data = val;
    newnode->next = top;
    top = newnode;
}
void pop()
{
    if (top == NULL)
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        top = top->next;
    }
}
void display()
{
    node *temp;
    if (top == NULL)
    {
        cout << "Stack is Empty." << endl;
    }
    else
    {
        temp = top;
        cout << "Stack elements are: " << endl;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
}
int main()
{
    int n;
    cout << "How many?: ";
    cin >> n;
    int value;
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        push(value);
    }
    display();
    pop();
    cout<<endl;
    display();
    return 0;
}