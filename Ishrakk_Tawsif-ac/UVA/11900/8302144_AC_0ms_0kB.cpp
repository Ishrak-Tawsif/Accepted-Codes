///solved 6 may 2016 ... 10.20 am

#include<iostream>
#include<cstdio>
using namespace std;
int main(){

    int testcase,num_of_egg,max_gm_of_bawl,max_egg_of_bawl,gm_of_egg[31],total_gm,total_egg;

        cin>> testcase;
            for(int i=1; i<=testcase; i++){
               total_egg = 0;
               total_gm = 0;
                cin >>num_of_egg >>max_egg_of_bawl >>max_gm_of_bawl;

                    for(int j=0; j<num_of_egg; j++){
                        cin >>gm_of_egg[j];
                    }

                        for(int j=0; j<num_of_egg; j++){
                                total_gm += gm_of_egg[j];
                            if(total_egg < max_egg_of_bawl && total_gm <= max_gm_of_bawl)
                                total_egg++;

                        }
                        printf ("Case %d: %d\n",i,total_egg);
            }
  return 0;
}