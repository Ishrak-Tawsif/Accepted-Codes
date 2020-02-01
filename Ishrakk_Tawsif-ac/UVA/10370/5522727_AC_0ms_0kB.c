#include<stdio.h>

int main(){

 int num[1011];
    int count=0,test_case,stu,total,i ;
    double avg,ans;

    scanf("%d",&test_case);
        while (test_case--){
            total = 0;
            count = 0;
             scanf("%d", &stu);

               for(i = 0; i < stu; i++){
                    scanf ("%d", &num[i]);
                    total = total + num[i];
                }

                avg = (double)(total/stu);


                for (i = 0; i<stu;i++){
                    if (num[i]>avg){

                        count++;
                    }
                }

                ans =  (double) ((count * 100.0) / stu);
                printf ("%.3lf%%\n", ans);
        }


return 0 ;
}
