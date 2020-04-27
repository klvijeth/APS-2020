#include "search.c"
#include<string.h>
ED collection[100];
int num=0;
void quicksort(ED search_list[],int first,long long last)
{
   int i, j, pivot;
   ED temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(search_list[i].priority<=search_list[pivot].priority&&i<last)
            i++;
         while(search_list[j].priority>search_list[pivot].priority)
            j--;
         if(i<j){
            temp=search_list[i];
            search_list[i]=search_list[j];
            search_list[j]=temp;
         }
      }

      temp=search_list[pivot];
      search_list[pivot]=search_list[j];
      search_list[j]=temp;
      quicksort(search_list,first,j-1);
      quicksort(search_list,j+1,last);

   }
}
void search(char s2[],ED a[])
{
    int n = 0;
   int m = 0;
   int times = 0;
   int  ch;
   int len ;
   int z=0;
   for(int i=0;i<global_count;i++)
   {
       n=0;
      m=0;
      len=strlen(s2);
      while(a[i].search_feed[n] != '\0')
        {

      if(a[i].search_feed[n] == s2[m]  || (a[i].search_feed[n] == toupper(s2[m]))){
         while((a[i].search_feed[n] == s2[m] ||(a[i].search_feed[n] == toupper(s2[m]))) && a[i].search_feed[n] !='\0')
            {
            n++;
            m++;
         }
         if(m == len && (a[i].search_feed[n] == ' ' || a[i].search_feed[n] == '\0'))
            {
            times++;
            //printf("%s\n",a[i].search_feed);
            collection[num]=a[i];
            num++;
            /*printf("Do you want more result 1 or 0\n");
            scanf("%d",&ch);
            if(ch==1)
            {
                times=0;
                goto c;
            }
            else
            {
                printf("Thank You\n");
                return;
            }*/
         }
      } else {            // if first character of search string DOES NOT match
         while(a[i].search_feed[n] != ' ') {        // Skip to next word
            n++;
            if(a[i].search_feed[n] == '\0')
            break;
         }
      }

      n++;
      c:
     m=0;// reset the counter to start from first character of the search string.
   }
   }
   if(times==0)
   {
       printf("No results found\n");
       return;
   }
}
int main()
{
    char key[20];
    int z=0;
    int ch;
    int count=0;
    int q=0;
    int l;
    welcome();
    load_from_file();
    /*for(int i=0;i<global_count;i++)
    printf("%d\t%s\n", search_list[i].priority, search_list[i].search_feed);*/
    // TODO
    printf("Enter the word you want to search for\n");
    scanf("%s",&key);
    while(key[q]!='\0')
    {
        if(isalpha(key[q]))
        {
            count++;
        }
        q++;
    }
    l=strlen(key);
    if(count!=l)
    {
        printf("Enter valid input\n");
        return 0;
    }

    //printf("%s\n", search_list[6].search_feed);
    search(key,search_list);
    quicksort(collection,0,num-1);
    if(num==0)
        printf("No results\n");
    else
    {
         while(num>z)
    {
        printf("%s\n",collection[z].search_feed);
         printf("Do you want more results 1 or 0\n");
            scanf("%d",&ch);
            if(ch==1)
            {
                z++;
                if(z>=num)
                {
                    printf("No more results to show\n");
                    return 0;
                }
            }
            else
            {
                printf("Thank You\n");
                return 0;
            }
    }
    }

    return 0;
}
