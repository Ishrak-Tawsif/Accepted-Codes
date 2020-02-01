#include <iostream>
#include<cstdio>
using namespace std;
int main (){

    int testcase,student,num,sum = 0,total = 0;
    int arr[1001];
    cin >> testcase;
        while (testcase --){

            cin >> student;
            sum = 0;
            total = 0;

                for (int i = 0; i<student; i++){
                    cin >> num;
                    arr[i] = num;
                    sum+=num;
                }
                double avg = (double)sum/student;

                    for (int i = 0; i<student;i++){
                        if(arr[i]>avg)
                            total++;
                    }

                    printf("%.3lf%%\n",(double)((total*100.00)/(double)student));
        }
return 0;
}
