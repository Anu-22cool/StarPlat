#include"input8.h"

void test(graph& g,int src)
{
  int* prop=new int[g.num_nodes()];
  #pragma omp parallel for
  for (int t = 0; t < g.num_nodes(); t ++) 
  {
    prop[t] = 10;
  }
  int sumV = 0;
  #pragma omp parallel for
  for (int v = 0; v < g.num_nodes(); v ++) 
  {
    sumV = sumV + prop[v];
  }
  while (true ){
    for (int v = 0; v < g.num_nodes(); v ++) 
    {
      int temp = prop[v];
      temp++;
    }
  }

}