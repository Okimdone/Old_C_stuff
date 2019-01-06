#include<stdio.h>

int main(){
    int T[2][3]={   {1, 2, 3},
                    {4, 5, 6}};

    int T2[3][2];

    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            T2[j][i]=T[i][j];
        }
    }

}