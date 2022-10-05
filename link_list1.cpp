#include <iostream>
using namespace std;
struct list
{
    int data;
    struct list *next;
};
list *start;
void createnode()
{
    int n;
    cin >> n;
    list *newnode;
    newnode = new list;
    newnode->data = n;
    if (start == NULL)
    {
        start = newnode;
        start->next = NULL;
    }
    list *temp;
    temp = start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = NULL;
}
void traverselist(list *start)
{
    list *temp = start;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
list *Rever(list *start)
{
    list *temp = NULL;
    list *nextNode = NULL;
    while (start)
    {
        nextNode = start->next;
        start->next = temp;
        temp = start;
        start = nextNode;
    }
    return temp;
}
int main()
{

    do
    {
        cout << "1.create  2.traverse  3.exit 4.reverse " << endl;
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            createnode();
        }
        if (ch == 2)
        {
            traverselist(start);
        }
        if (ch == 3)
        {
            exit(0);
        }
        if (ch == 4)
        {
            start = Rever(start);
        }

    } while (1);

    return 0;
}
