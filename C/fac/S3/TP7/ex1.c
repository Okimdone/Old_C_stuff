int trace(int **M,int N){
    int tr = 0;
    for(int i=0;i<N;i++)
    {
       tr += M[i][i];

    }
    return tr;
}