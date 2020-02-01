#include<iostream>
using namespace std;


int main(){

    //char flag[101][101];
    int row,columns;
    bool ispossible;
        while(cin>> row>> columns){
            ispossible=true;
            char flag[row][columns];
                for(int i=0; i<row; i++){
                    for(int j=0; j<columns; j++){
                        cin>> flag[i][j];
                    }
                }
                    ///column checking
                    for(int i=0; i<row; i++){
                        for(int j=0; j<columns-1; j++){
                            if(flag[i][j] != flag[i][j+1]){
                                ispossible=false;
                                break;
                            }
                        }
                        if(ispossible == false) break;
                    }
                        ///row checking
                        for(int i=0; i<row-1; i++){
                            for(int j=0; j<columns; j++){
                                if(flag[i][j] == flag[i+1][j])
                                    ispossible=false;
                            }
                            if(ispossible == false) break;
                        }

                            if(ispossible == true) cout << "YES" << endl;
                            else cout << "NO" << endl;
        }
    return 0;
}
