#include <iostream>
#include "StackTypeLL.h"
#include "StackTypeLL.cpp"
using namespace std;

int main()
{
    StackTypeLL<int> s;
    s.Push(5);
    s.Push(7);
    s.Push(6);
    s.Push(9);
   s.printStack();
   cout<<endl;

    int i;
    s.pop(i);
    cout<<"Pop::"<<i<<endl;
    cout<<endl;

    s.Push(10);
    s.Push(8);
    cout<<endl;

    cout<<"Pop::";
    for(int j=0;j<5;j++)
        {
            int i;
            s.pop(i);
            cout<<i<<" ";

            if(s.isEmpty())
                cout<<endl<<"Stack is empty"<<endl;
        }
    return 0;
}
