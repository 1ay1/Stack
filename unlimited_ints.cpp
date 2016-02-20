#include "imphead.h"

using namespace std;

void getInts(vector<int> & arr)
{
    int intread =0;
    int inval;

    while(cin >> inval)
    {
        if(intread == arr.size())
        {
            arr.resize(intread+1);
        }
        arr[intread] = inval;
        ++intread;
    }
}

int main()
{
    vector<int> arr;
    cout << "Keep entering the numbers: " ;
    getInts(arr);

    cout << "Your entered: " ;
    for (int i = 0 ; i < arr.size() ; ++i)
    {
         cout << "\n" <<arr[i] ;
    }
    return 0;
}
