 #include <iostream>                                                                                   
  #include <cstdio>
  #include <algorithm>
  #include <functional>
  
  #define swap(x, y) x ^= y; y ^=x; x ^= y;

  int n, itm[200200];
  using namespace std;

void sort(int arr[], int n){
    int i, k;
	for (int j = 2; j <= n; j++){
		k = arr[j];
		i = j - 1;
		while (i>0 && arr[i] < k){
			arr[i + 1] = arr[i];
			i--;
		}
		arr[i + 1] = k;
	}
}
int main(int argc, const char* argv[]){
      //ios_base::sync_with_stdio(0);
      FILE * fin, * fout;
      fin = fopen("shopping.inp", "r");
      
      int i, sum;
      fscanf(fin, "%d", &n);
      for(i = 1; i <= n; i++)
          fscanf(fin, "%d", &itm[i]);
  
      sort(itm, n); 
      i = 3;
      sum  = 0;
      while(i <= n){ 
          sum += itm[i];
          i += 3;
      }   
      
      fout = fopen("shopping.out", "w");
  
      fprintf(fout, "%d", sum);
      fclose(fin); fclose(fout);
  
       
      return 0;
  
  }