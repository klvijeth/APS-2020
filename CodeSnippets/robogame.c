#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct robot
{
    int index;
    int left;
    int right;
    int flag;
};
//typedef struct robot robot;
int main()
{
    long long t,i;
    char s[55];
    int j,count,k,u,v,flagg;
    struct robot robo[55];
    scanf("%lld",&t);
    for(i=0;i<t;i++)
    {
        count=0;
        flagg=0;
        j=0;
        k=0;
        scanf("%s",s);
        while(s[j]!='\0')
        {
            if(isdigit(s[j]))
                {
                    v=j-(s[j]-'0');
                    u=j+(s[j]-'0');
                    //printf("%d\n",v);
                    //printf("%d\n",u);
                    if(v<0)
                    {
                        if(u>=strlen(s))
                        {
                            robo[k].index=j;
                            robo[k].left=0;
                            robo[k].right=strlen(s)-1;
                            robo[k].flag=0;
                            k++;
                        }
                        else
                        {
                            robo[k].index=j;
                            robo[k].left=0;
                            robo[k].right=u;
                            robo[k].flag=0;
                            k++;
                        }
                    }
                    else
                    {
                        if(u>=strlen(s))
                        {
                            robo[k].index=j;
                            robo[k].left=v;
                            robo[k].right=strlen(s)-1;
                            robo[k].flag=0;
                            k++;
                        }
                        else
                        {
                            robo[k].index=j;
                            robo[k].left=v;
                            robo[k].right=u;
                            robo[k].flag=0;
                            k++;
                        }
                    }
                    count++;
                }
            j++;
        }
        if(count<=1)
            printf("safe\n");
        else
        {
            for(int q=0;q<k;q++)
            {
                //if(robo[])
                //printf("%d\n",robo[q].left);
                if(robo[q].flag==0)
                {
                    for(int p=q+1;q<k-1;q++)
                    {
                        if((robo[q].left>=robo[q+1].left && robo[q].left<=robo[q+1].right) || (robo[q+1].left>=robo[q].left && robo[q+1].left<=robo[q].right) || (robo[q].right>=robo[q+1].left && robo[q].right<=robo[q+1].right) || (robo[q+1].right>=robo[q].left && robo[q+1].right<=robo[q].right) )
                        {
                            flagg=1;
                            goto c;

                        }

                    }
                }
            }
            c:
            if(flagg==0)
                printf("safe\n");
            else
                printf("unsafe\n");
        }
        //printf("%d",count);
    }


    return 0;
}
