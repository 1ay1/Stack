// Implementing Stack in C++ using vector

#include "imphead.h"

int maxy=10;  // max, it will hold the total number of the nodes of the stack
int top = -1;   // it's the tos ( top of the stack ), top is initiated with -1, so that in the push function top will be 0 after incrementing it and 0 is what is going to start our vector

void push(int); // declared a push function, this function is going to push some value to the tos(top of the stack) after incrementing the top
int pop(); // declared a push function, this function is going to pop out the tos value from the stack and decrement the top

vector<int> stacky(maxy);

int main()
{
    int choice=0, p, j;
    while(choice != 3)
    {
        system("clear") ;
        cout << "1....... Enter 1 for pushing your value into the stack: \n";
        cout << "2....... Enter 2 for popping out the value from top of the stack: \n";
        cout << "3....... Quit.\n";
        cin >> choice;
        switch(choice)
        {
        case 1:
            if (top < maxy-1)
            {
                cout << "Enter the value to be pushed: \n" ;
                cin >> p;
                push(p);
            }
            else
            {
                cout << "Stack is FULL OK?" ;
            }
            break;
        case 2:
            if (top == -1)
            {
                cout << "Stack is empty!!" ;
            }
            else
            {
                j = pop();
                if(j==0)
                {
                    cout << "Stack is empty " ;
                }
                else
                {
                cout << "The value " << j << " is just popped out happy now?" ;
                }
            }
            break;
        default:
            error("Wrong input, Enter any key to get the menu again: ");
            keep_the_fucking_window_open() ;
            break ;
        }
        cout << "\n" << "The elements in Stack are: \n" ;
        int i= top;
        while(top != -1 && i >=0)
        {
            cout << stacky[i] << "\n" ;
            --i ;
        }
        cout << "\n"<< "Enter any key to go to the menu again: " ;
        keep_the_fucking_window_open();
        }

    return 0;
}


void push(int p)
{
    ++top;
    stacky[top] = p;
}

int pop()
{
    if (top == -1)
    {
        return 0;
    }
    else
    {
    int j;
    j=stacky[top];
    --top;
    return j;
    }
}
