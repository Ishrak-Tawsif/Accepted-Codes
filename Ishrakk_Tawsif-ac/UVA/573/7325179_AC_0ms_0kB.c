#include<stdio.h>
#include<string.h>
int main(){

    double h, d_c, s_n, f;
    int i;
        while(scanf("%lf %lf %lf %lf", &h,&d_c, &s_n, &f)==4 && h){

            double tot_dis=0;
            double temp_d_c = d_c*1.0;

            for(i=1; ; i++){

                if(temp_d_c>0)tot_dis += temp_d_c;
                if(tot_dis>h) {printf("success on day %d\n",i); break;}
                temp_d_c -= (double) (((double)(f*d_c))/100.0);
                tot_dis -= s_n; if(tot_dis<0){printf("failure on day %d\n",i); break;}
            }
        }
return 0;
}