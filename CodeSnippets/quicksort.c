#include<stdio.h>
void quicksort(long long number[],int first,long long last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
}

int main(){
   int i,t,k,v,u;
   long long x,count,z,y;
   scanf("%d",&u);
   while(u>0)
   {
   scanf("%lld",&count);
   scanf("%lld",&x);
   long long number[count];
   for(i=0;i<count;i++)
   {
       scanf("%lld",&y);
       number[i]=(-1*y);
   }
   quicksort(number,0,count-1);

      v=number[x-1];
      z=x;
       while(number[z]==v && z<count)
       {
           z++;
       }
       printf("%lld\n",z);
       u--;

   }

   return 0;
}
