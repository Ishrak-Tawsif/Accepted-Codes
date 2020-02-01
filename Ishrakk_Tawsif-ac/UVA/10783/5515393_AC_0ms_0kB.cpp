#include<iostream>
using namespace std;
int main ()
{
        int testCases;
        int a,b;
       
        cin>>testCases;
        for(int i=0; i<testCases; i++)
        {
                int sumOfOdd = 0;
                cin>>a>>b;
                for(int j=a; j<=b; j++)
                {
                        if(j%2 !=0)
                        {
                                sumOfOdd+=j;
                        }
                        else
                        {
                                continue;
                        }
                }
                cout<<"Case "<<i+1<<": "<<sumOfOdd<<endl;
        }
        return 0;
}