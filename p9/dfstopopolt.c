void ploter(int k)
{

    FILE *f1= fopen("BFSBEST.txt", "a");
    FILE *f2=fopen("BFSWOSR.txt", "a");
    int v,start;
    for(int i=1;i<=10;i++)
  {
    v=i;
  int *arr[v];
  for(int i=0;i<v;i++)
  arr[i]=(int *)malloc(sizeof(int)*v); 


 if(k==0)
 {
  for(int i=0;i<v;i++)
{

   for(int j=0;j<v;j++)
  {
       
       if(i!=j)
       {
        arr[i][j] =1;
       }
       else
       arr[i][j] =0;
  }
}
 }

if(k==1)
{
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
         arr[i][j] =0;
    }
    for(int i=0;i<v-1;i++)
    {
            arr[i][i+1]=1;
    }

}

    bfsCount = 0, cyclic=0;
    count = 0;
    orderCount = 0;
    bfsCount++;
    bfs(v, 0);
    if(count != v){
        start = 1;
        while(count != v){
            if(visited[start] != 1) {
                bfsCount++;
                bfs(v, start);
            }
            start++;
        }
    }
           if(k==0)
         fprintf(f2,"%d\t%d\n",v,orderCount);
         else
          fprintf(f1,"%d\t%d\n",v,orderCount);
         // printf("%d\t%d\n",v,orderCount);


  }

  fclose(f1);
  fclose(f2);

}

void main()
{

    for(int i=0; i<2;i++)
    ploter(i);
}
