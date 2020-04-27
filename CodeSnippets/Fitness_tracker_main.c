#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TRUE 1
#define FALSE 0
#define INFINITY 9999
#define MAX 20
int dijkstra(float G[MAX][MAX],int n,int startnode,int destination);
int N=10;
int step_var;
int dist_var;
int cal_var;
int max_streak=0;
int node_count=0;
int user_flag=0;
/* structure to store the details of the user*/
struct details
{
    char name[20];
    int height;
    int weight;
    int age;
    int cal_goal;
    char gender[10];
};
typedef struct details DET;
DET user;
/*structure to store the activity details*/
struct fitness
{
    int steps;
    int distance;
    int calories;

};
typedef struct details FIT;
/* linked list to store calculated fitness details*/
struct node
{
	struct fitness data;
	struct	node *next;
	struct	node *prev;
};
typedef struct node LIST;
struct node *head;
struct Date
{
	int date;

	int month;

	int year;
};
/*Function:       dijkstra
Description:    finds the shortest distance between two places
Input parameters:    adjacency matrix,number of places,source,destination
Return Type:   distance*/
int dijkstra(float G[MAX][MAX],int n,int startnode,int destination)
{
    float cost[MAX][MAX],distance[MAX];
    int visited[MAX],count,mindistance,nextnode,i,j;
    for(i=0;i<n;i++)
    {
            for(j=0;j<n;j++)
            {
                if(G[i][j]==0)
                    cost[i][j]=INFINITY;
                else
                    cost[i][j]=G[i][j];
            }
    }
    for(i=0;i<n;i++)
    {
        distance[i]=cost[startnode][i];
        visited[i]=0;
    }
    distance[startnode]=0;
    visited[startnode]=1;
    count=1;
    while(count<n-1)
    {
        mindistance=INFINITY;
        //nextnode gives the node at minimum distance
        for(i=0;i<n;i++)
        {
         if(distance[i]<mindistance&&!visited[i])
            {
                mindistance=distance[i];
                nextnode=i;
            }
        }
            //check if a better path exists through nextnode
            visited[nextnode]=1;
            for(i=0;i<n;i++)
            {
             if(!visited[i])
             {
                    if(mindistance+cost[nextnode][i]<distance[i])
                    {
                        distance[i]=mindistance+cost[nextnode][i];
                    }
             }
            }
        count++;
    }
    return distance[destination];
}
typedef struct Date DATE;
DATE today;
struct bst
{
	int calories;
	DATE day;
	struct node* left;
	struct node* right;
};
typedef struct bst NODE;
NODE* root=NULL;
/* True if leap year */
int isLeapYear( int year );
/* The number of leap year */
int leapYears( int year );
/* The number of leap year */
int todayOf( int y, int m, int d);
/* The number of days since the beginning of the year */
long days( int y, int m, int d);
/* Total number of days */
void calendar(int y, int m);
/* display calendar at m y */
int getDayNumber(int d,int m,int y);
char *getName(int day);
//keeps the count of number of reminders
int globalCount=0;
float bmi;
//keeps the track of the present reminder priority
int globalPriority=0;
//variable to store present month for reminder
int todaysMonth=0;
//variable to store present date for reminder
int todaysDay=0;
//structure for reminders
struct rem
{
    int priority;
    char message[20];
    int date;
    int month;
};
typedef struct rem REM;

//array to store the present reminders
REM reminders[10];

//Structure for Sleep monitoring
struct sleep_monitor
{
    int day;
    char name[100];
    int age;
    char gender[10];
    //st -> sleeping time
    int st_hour;
    int st_minute;
    //wkt -> waking time
    int wkt_hour;
    int wkt_minute;
    // d ->duration of sleep
    int d_hour;
    int d_minute;
    struct sleep_monitor *prev;
    struct sleep_monitor *next;
};
typedef struct sleep_monitor SM;

typedef struct {
  int day;
  int month;
  int year;
  int day2;
  char note[255];
} Note;

char c[1000];
FILE *fptr;

int currnode=0;
int position=0;

//Functions for Sleep Monitoring Function
void welcome();
SM *getnode();
int getdata(SM* newnode);
int check_user(SM* start);
SM* update_record(SM* start);
void display_sleep_profile(SM* start);
SM* delete_record(SM* start);
SM* delete_from_start(SM* start);
void display_profile(SM* start);
float average_sleep(SM* start);
SM* delete_from_end(SM* start);
void sleep_analysis(SM* start);
void tips();
void sleep_monitoring();

//Functions for BM1,BMR,WHR calculation functions
void BMI_calculator();
void bmi_calc();
void bmi_info();
void bmi_chart();
void bmr_chart();
void whr_chart();
void BMR_calculator();
void bmr_calc();
void bmr_info();
void WHR_calculator();
void whr_calc();
void whr_info();
void calc_ratios();

//Functions for setting up reminders
void deletePriority(int priority1);
void Delete();
void addReminder();
void dump();
void addPriority();
void printReminders();
int empty();
int full();

//Funtions for period tracking
void flush();
int isLeapYear( int y );
char *getName(int day);
int getDayNumber(int d, int m, int y);
void calendar(int y, int m);
long days( int y, int m, int d);
int todayOf( int y, int m, int d);
int leapYears( int y );
void Period_tracking();
void pms_text();

/**
Function Name: Period_tracking
Input Params: Nil
Return Type: Void
Description: Interface for tracking periods
**/
void Period_tracking()
{
    printf("Hello dear!! Welcome to Period Tracker!!\n\n");
    int year,month, day;
    int temp;
    int n;
    char choice;
    int choice1;
    Note note;
    FILE *fp;

    fp = fopen("note.bin", "r");
    if (fp == NULL) {
      fp = fopen("note.bin", "w");
    }
    fclose(fp);

    while(1) {
      printf("1. Enter the date of your period:\n");
      printf("2. Print calendar of a month\n");
      printf("3. Add Note\n");
      printf("4. How to handle PMS?\n");
      printf("5. Exit\n");
      printf("Enter your choice: ");
      scanf("\n%c", &choice);
      switch(choice) {
        case '1':
        printf("Enter the day, month and year: ");
        scanf("%d %d %d", &day, &month, &year);
        if(day>31 || month>12)
        {
            printf("Invalid Input\n");
            exit(-1);
        }
        printf("How long does it lasts regularly?\n");
        scanf("%d",&n);
        if(n>5)
        {
            printf("This is not normal.Are there any further complications?\n");
            printf("1-Yes\n");
            printf("2-No\n");
            scanf("%d",&choice1);
            switch(choice1)
            {
                case 1:printf("Consult a doctor!!\n You should.\n");
                return;
                case 2:break;
            }
        }
        if(month>12)
        {
            temp=month%12;
            year=year+1;
        }
        else
            temp=month+1;
        printf("Your next period will start from: %s %d-", getName(getDayNumber(day, temp, year)),day);
        if(temp==1)
        {
            printf("Jan-");
        }
        else if(temp==2)
        {
            printf("Feb-");
        }
        else if(temp==3)
        {
            printf("March-");
        }
        else if(temp==4)
        {
            printf("April-");
        }
        else if(temp==5)
        {
            printf("May-");
        }
        else if(temp==6)
        {
            printf("June-");
        }
        else if(temp==7)
        {
            printf("July-");
        }
        else if(temp==8)
        {
            printf("Aug-");
        }
        else if(temp==9)
        {
            printf("Sep-");
        }
        else if(temp==10)
        {
            printf("Oct-");
        }
        else if(temp==11)
        {
            printf("Nov-");
        }
        else if(temp==12)
        {
            printf("Dec-");
        }
        printf("%d",year);
        printf("and end by %s\n\n",getName(getDayNumber(day+n, temp, year)));
        break;
        case '2':
        printf("Enter the month and year: ");
        scanf("%d %d", &month, &year);
        if(month>12)
        {
            printf("Invalid Input\n");
            exit(-1);
        }
        printf("Please enter 's' to see the notes\n Press any other key to continue\n");
        calendar(year, month);
        break;
        case '3':
        printf("Enter the day, month and year: ");
        if(day>31 || month>12)
        {
            printf("Invalid Input\n");
            exit(-1);
        }
        scanf("%d %d %d", &note.day, &note.month, &note.year);
        flush();
        printf("Enter the note: ");
        fgets(note.note, 255, stdin);
        fp = fopen("note.bin", "a+");
        if (fp == NULL) {
          printf("File note.bin can not be opened\n");
          exit(1);
        }
        fwrite(&note, sizeof(Note), 1, fp);
        printf("Note added sucessfully\n");
        fclose(fp);
        break;
        case '4':pms_text();
        break;
        case '5':
        printf("Bye!!\n\n");
        return;
        default:
        printf("Not a valid option\n");
        break;
      }
    }
}

/**
Function Name: set_remainders
Input Params: Nil
Return Type: Void
Description: Interface for setting up reminders
**/
void set_remainders()
{
    int priority1=0;
    int choice;

    while(1)
    {
       printf("\n****MENU****\n");
       printf("1.Add reminder\n");
       printf("2.Display Reminders\n");
       printf("3.Delete\n");
       printf("4.Custom Deletion\n");
       printf("5.Exit Program\n");
       printf("***************\n");

       printf("\nEnter the choice\n");
       fflush(stdin);
       scanf("%d",&choice);

        switch(choice)
       {
        case 1:addReminder();
               addPriority();
               printReminders();
               break;

        case 2:printReminders();
               break;

        case 3: /*
                Data to be taken from file
                Date
                Day
                */
                printf("Enter Today's Month\n");
                scanf("%d",&todaysMonth);
                printf("Enter Today's Day\n");
                scanf("%d",&todaysDay);
                Delete();
                break;

        case 4:printReminders();
               printf("Enter the priority of alarm to be deleted\n");
               scanf("%d",&priority1);
               deletePriority(priority1);
               printReminders();
               break;

        case 5:return;

       }
    }
}

/**
Function Name: calc_ratios
Input Params: Nil
Return Type: Void
Description: Interface for BMI,BMR,WHR calculator
**/
void calc_ratios()
{
    int choice;
    while(1)
    {
    printf("Hello ! Let us know more about our body!!\n");
    printf("1-BMI calculator\n");
    printf("2-WHR calculator\n");
    printf("3-BMR calculator\n");
    printf("4-Exit\n\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: BMI_calculator();
        break;

        case 2:WHR_calculator();
        break;

        case 3:BMR_calculator();
        break;

        case 4:printf("Exiting...!!\n");
        return;
    }
    }
}
/**
Function Name: sleep_monitoring
Input Params: NILL
Return Type: void
Description: Monitors the sleeping durations of the user
**/
void sleep_monitoring()
{
    int i=0;
    welcome();
    SM *start;
    float avg_sleep;
    start=NULL;
    while(1)
    {
    printf("1-Update sleep record\n");
    printf("2-Display sleep record\n");
    printf("3-Calculate Average sleep\n");
    printf("4-Display sleep profile\n");
    printf("5-Delete sleep record\n");
    printf("6-How can you improve your sleep cycle?\n");
    printf("7-Sleep Analysis\n");
    printf("8-Exit\n");
    int choice;
    printf("Enter your choice:\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: start=update_record(start);
        break;
        case 2:display_profile(start);
        break;
        case 3:avg_sleep=average_sleep(start);
        break;
        case 4:display_sleep_profile(start);
        break;
        case 5:start=delete_record(start);
        break;
        case 6:tips();
        break;
        case 7:sleep_analysis(start);
        break;
        case 8:printf("Hope you sleep well !\n EXITING...\n\n");
        return;
    }
    }
}
/**
Function Name: welcome
Input Params: NILL
Return Type: void
Description: Prints a welcome message
**/
void welcome()
{
    printf("Welcome to Sleep Monitoring!\nYou are required to put in the details of your sleep over the last one week.\n\n");
}
/**
Function Name:getnode
Input Params: NILL
Return Type: Address
Description:Creates a newnode
**/
SM *getnode()
{
    SM* newnode;
    newnode=(SM*)malloc(sizeof(SM));
    if(newnode==NULL)
    {
        printf("Memory allocation failed\n");
        return newnode;
    }
}
/**
Function Name: getdata
Input Params: Address of the node
Return Type: integer
Description: Fills in the data contents of the node
**/
int getdata(SM* newnode)
{
    SM* prevnode;
    char names[100];
    char sex[10];
    int temp1=0,temp2=0;
    int count=0;
    int x=0;
    int choice;
    newnode->day=position;
    strcpy(names,user.name);
    strcpy(newnode->name,names);
    strcpy(sex,user.gender);
    strcpy(newnode->gender,sex);
    newnode->age=user.age;
    printf("When did you sleep?\nFormat:HH MM (in 24 hours)\n");
    scanf("%d%d",&newnode->st_hour,&newnode->st_minute);
    printf("When did you wake up?\nFormat:HH MM (in 24 hours)\n");
    scanf("%d%d",&newnode->wkt_hour,&newnode->wkt_minute);
    //CASE 1: When the input time is Invalid
    if(newnode->st_minute >60 || newnode->wkt_minute>60 || newnode->st_hour>24 || newnode->wkt_hour>24)
    {
        printf("Invalid Time!\n\n");
        return FALSE;
    }
    //CASE 2: When the input sleeping time is in pm
    else if(newnode->st_hour>=12 && newnode->st_hour<24)
    {
        temp1=60-newnode->st_minute;
        x=newnode->st_hour+1;
        temp2=24-x;
        newnode->d_hour=temp2+newnode->wkt_hour;
    }
    //CASE 3: When the input sleeping time is in am
    else if(newnode->st_hour>0 && newnode->st_hour<12)
    {
        temp1=60-newnode->st_minute;
        x=newnode->st_hour+1;
        temp2=newnode->wkt_hour-x;
        newnode->d_hour=temp2+count;
    }
    //CASE 4: When the input sleeping time coincides with midnight.
    else if(newnode->st_hour==24 || newnode->st_hour==0)
     {
         temp1=60-newnode->st_minute;
         temp2=newnode->wkt_hour-1;
         newnode->d_hour=temp2+count;
     }
         temp1=temp1+newnode->wkt_minute;
        if(temp1>60)
        {
            while(temp1>=60)
            {
                count++;
                temp1=temp1-60;
            }
        }
        if(newnode->d_hour<0)
        {
            temp2=24-x;
            newnode->d_hour=temp2+newnode->wkt_hour;
        }
        newnode->d_hour=newnode->d_hour+count;
        newnode->d_minute=temp1;
        newnode->next=NULL;
        newnode->prev=NULL;
        printf("You slept for %d hours and %d minutes",newnode->d_hour,newnode->d_minute);
        printf("\n\n");
        return TRUE;
}
/**
Function Name: update_record
Input Params: Address of the starting node of the doubly linked list
Return Type: Address
Description: Calls the creation of new nodes/records. At once,sleep records of 7 days can be taken
and average sleep patterns can be calculated
**/
SM* update_record(SM* start)
{
    SM* newnode, *tempnode,*xnode, *prevnode;
    int i=0,k;
    int x;
    int check,choice;
    //Keeps a check on the number of sleep records entered. It should be max 7.
    if(currnode<7)
    {
    printf("Enter day number:\t");
    scanf("%d",&position);
    if(position<1 || position>currnode+1)
    printf("Invalid position\n");
    else
    {
        newnode=getnode();
        if(newnode==NULL)
            return start;
        x=getdata(newnode);
        if(x==FALSE)
        {
         printf("Record not created\n");
         return start;
        }
        if(start==NULL)
            start=newnode;
        else if(position==1)
        {
            newnode->next=start;
            start->prev=newnode;
            start=newnode;
        }
        else if(position==currnode+1)
        {
            tempnode=start;
            while(tempnode->next!=NULL)
                tempnode=tempnode->next;
            tempnode->next=newnode;
            newnode->prev=tempnode;
            check=check_user(newnode);
            {
                if(check==0)
                {
                    printf("Please confirm your identity as your previous record entries don't match\n");
                    printf("1-Same User\n");
                    printf("2-New User\n");
                    scanf("%d",&choice);
                    switch(choice)
                    {
                        case 1:printf("Okay! Let's continue %s\n",newnode->name);
                        break;
                        case 2:printf("Sorry! Make a new record \n");
                        for(k=currnode;k>=0;k--)
                        start=delete_from_start(start);
                        currnode=0;
                        return start;
                    }
                }
                else
                printf("Okay! Let's continue %s\n",newnode->name);
            }
        }
        else
        {
            tempnode=start;
            for(i=2;i<position;i++)
            {
                tempnode=tempnode->next;
            }
            newnode->next=tempnode->next;
            newnode->prev=tempnode;
            xnode=tempnode->next;
            xnode->prev=newnode;
            tempnode->next=newnode;
            check=check_user(newnode);
            {
                if(check==0)
                {
                    printf("Please confirm your identity as your previous record entries don't match\n");
                    printf("1-Same User\n");
                    printf("2-New User\n");
                    scanf("%d",&choice);
                    switch(choice)
                    {
                        case 1:printf("Okay! Let's continue %s\n",newnode->name);
                        break;
                        case 2:printf("Sorry! Make a new record \n");
                        for(k=currnode;k>=0;k--)
                        start=delete_from_start(start);
                        currnode=0;
                        return start;
                    }
                }
                else
                printf("Okay! Let's continue %s\n",newnode->name);
            }
           }
        }
        currnode++;
    }
    else
    {
        int choice,k;
        printf("You have already entered records for 1 week!!\n");
        printf("Do you want to clear and make new record?\n ");
        printf("1-YES\n2-NO\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:for(k=currnode;k>=0;k--)
            {
                start=delete_from_start(start);
            }
            printf("All records have been deleted\n");
            currnode=0;
            break;

            case 2: return start;
        }
    }

        return start;
}
/**
Function Name: check_user
Input Params: Address of the node
Return Type: integer
Description: Checks the current node details with previous node details
**/
int check_user(SM* newnode)
{
        SM* prevnode;
        int x1,x2,x3;
        prevnode=newnode->prev;
        x1=strcmpi(prevnode->name,newnode->name);
        x2=strcmpi(prevnode->gender,newnode->gender);
        if(prevnode->age==newnode->age)
            x3=0;
        else
            x3=1;

        if(x1!=0 || x2!=0 || x3!=0)
        {
            return 0;
        }
        else
        {
          return 1;
        }
}
/**
Function Name: display_sleep_profile
Input Params: Address of the starting node
Return Type: void
Description: Dislplays the current number of sleep records
**/
void display_sleep_profile(SM* start)
{
    SM* temp;
    int temp1=0,temp2=0;
    int x;
    int day;
    if(currnode==0)
    {
        printf("Empty Records\n");
    }
    else
    {
        temp=start;
        printf("Your sleep profile is...\n\n");
        while(temp!=NULL)
        {
            printf("Day %d:-\n",temp->day);
            printf("Name:%s\n",temp->name);
            printf("Gender:%s\n",temp->gender);
            printf("Age:%d\n",temp->age);
            printf("You slept at %d hours %d minutes\n",temp->st_hour,temp->st_minute);
            printf("You woke up at %d hours %d minutes\n",temp->wkt_hour,temp->wkt_minute);
            printf("RESULT:-\n");
            if(temp->st_hour>=22 && temp->st_hour<24)
            {
               if(temp->st_hour==22)
                printf("You slept at time\n");
               else
                printf("You slept late by %d hour and %d minutes\n",temp->st_hour-22,temp->st_minute);
            }
            else if(temp->st_hour>=12 && temp->st_hour<22)
            {
                temp1=60-temp->st_minute;
                x=temp->st_hour+1;
                temp2= 22 -x;
                printf("You slept early by %d hours and %d minutes\n",temp2,temp1);
            }
            else if(temp->st_hour>=0 && temp->st_hour<12)
            {
                printf("You slept late by %d hour and %d minutes\n",temp->st_hour+2,temp->st_minute);
            }
            if(temp->wkt_hour>6)
            {
                printf("You woke up late by %d hour and %d minutes\n\n",temp->wkt_hour-6,temp->wkt_minute);
            }
            else if(temp->wkt_hour==6)
            {
                printf("You woke up at time!!\n\n");
            }
            else
            {
                temp1=60-temp->wkt_minute;
                x=temp->wkt_hour + 1;
                temp2= 6 -x;
                printf("You woke up early by %d hours and %d minutes\n\n",temp2,temp1);
            }
            temp=temp->next;
        }
        printf("NULL\n\n");
    }
}
/**
Function Name: delete_record
Input Params: Address of the starting node
Return Type: Address
Description: Deletes the sleep record of a given day
**/
SM* delete_record(SM* start)
{
    SM* temp,*prevnode,*xnode;
    int position=0,i=0;

    if(start==NULL)
    {
        printf("Empty Records\n");
        return start;
    }
        printf("Enter delete position\n");
        scanf("%d",&position);
        if(position<1 || position>currnode)
            printf("Invalid position\n");
        else
        {
            if(currnode==1)
            {
                temp=start;
                start=NULL;
            }
            else if(position==1)
            {
                temp=start;
                start=start->next;
                start->prev=NULL;
            }
            else if(position==currnode)
            {
                temp=start;
            while(temp->next!=NULL)
                temp=temp->next;

            prevnode=temp;
            prevnode=prevnode->prev;
            prevnode->next=NULL;
            }
            else
            {
                prevnode=NULL;
                temp=start;
                i=2;
                while(i<=position)
                {
                    prevnode=temp;
                    temp=temp->next;
                    i++;
                }
                prevnode->next=temp->next;
                temp->next=xnode;
                xnode->prev=prevnode;
            }
            free(temp);
            currnode--;
        }
  return start;
}
/**
Function Name: delete_from_start
Input Params: Address of the starting variable
Return Type: Address
Description: Always deletes the node at the beginning
**/
SM* delete_from_start(SM* start)
{
    SM* temp;
    if(start==NULL)
        printf("Empty Record\n");
    else
    {
        if(currnode==1 || start->next==NULL)
        {
            temp=start;
            start=NULL;
        }
        else{
            temp=start;
            start=start->next;
            start->prev=NULL;
            }
        free(temp);
        currnode--;
    }
    return start;
}
/**
Function Name: display_profile
Input Params: Address of the starting node
Return Type: void
Description: Prints the sleep durations over the current number of days
**/
void display_profile(SM* start)
{
    SM* temp;
    int day=1;
    if(currnode==0)
    {
        printf("Empty Record\n");
    }
    else
    {
        temp=start;
        printf("The sleeping durations over last week are...\n");
        while(temp!=NULL)
        {
            printf("%d Day--->%d:%d hours\n",day,temp->d_hour,temp->d_minute);
            day++;
            temp=temp->next;
        }
        printf("NULL\n");
    }
}
/**
Function Name: tips
Input Params: NILL
Return Type: void
Description: Prints a file containing tips to have a good sleep
**/
void tips()
{
  char str;
  FILE * file;
  file = fopen( "tips.txt" , "r");
   while(1)
   {
       str=fgetc(file);
       if(str==EOF)
        break;
       else
        printf("%c",str);
   }
   printf("\n\n");
   fclose(file);
   return;
}
/**
Function Name: average_sleep
Input Params: Address of the starting address
Return Type: void
Description: Prints the average sleep duration over the current number of sleep records
**/
float average_sleep(SM* start)
{
    SM* newnode;
    newnode=start;
    int temp1=0;
    int temp2=0;
    int total_minutes=0;
    float mean=0;
    float average=0;
    int k;
    int count=0;
    k=currnode;
    while(newnode->next!=NULL && k>=0)
    {
        temp1=temp1+newnode->d_hour;
        temp2=temp2+newnode->d_minute;
        newnode=newnode->next;
        k--;
        count++;
    }
    temp1=temp1+newnode->d_hour;
    temp2=temp2+newnode->d_minute;
    count++;
    total_minutes=temp1*60;
    total_minutes=total_minutes+temp2;
    mean=(float)total_minutes/count;
    average=mean/60;
    printf("Average over %d days is = %f hours\n",count,average);
    return average;
}

/**
Function Name: delete_from_start
Input Params: Address of the starting node
Return Type:Address
Description: Always deletes from the current last node;
**/
SM* delete_from_end(SM* start)
{
    SM* temp,*prevnode;
    if(start==NULL)
        printf("Empty records\n");
    else
    {
        if(currnode==1)
        {
            temp=start;
            start=NULL;
        }
        else
        {
            temp=start;
            while(temp->next!=NULL)
                temp=temp->next;

            prevnode=temp;
            prevnode=prevnode->prev;
            prevnode->next=NULL;
        }
        free(temp);
        currnode--;
    }
    return start;
}

/**
Function Name: insert_from_start
Input Params: Address of the starting node
Return Type:Address
Description: Always inserts node at the beginning
**/
SM* insert_at_start(SM* start)
{
    SM* newnode;
    newnode=getnode();
    if(newnode==NULL)
        return start;
    getdata(newnode);

    if(start==NULL)
        start=newnode;
    else
    {
        newnode->next=start;
        start->prev=newnode;
        start=newnode;
    }
    currnode++;
    return start;
}

/**
Function Name: insert_at_end
Input Params: Address of the starting node
Return Type:Address
Description: Always inserts node from the end
**/
SM* insert_at_end(SM* start)
{
    SM* newnode,*tempnode;
    newnode=getnode();
    if(newnode==NULL)
        return start;
    getdata(newnode);

    if(start==NULL)
        start=newnode;
    else
    {
        tempnode=start;
        while(tempnode->next!=NULL)
            tempnode=tempnode->next;

        tempnode->next=newnode;
        newnode->prev=tempnode;
    }
    currnode++;
    return start;
}

/**
Function Name: sleep_analysis
Input Params: Address of the starting node
Return Type: Nil
Description: Generates an overall sleep report for the user
**/
void sleep_analysis(SM* start)
{
    int choice1;
    int choice2;
    int choice3;
    int choice4;
    int nshift=0;
    int wrk=0;
    float avg_sleep=0;
    if(currnode!=7)
    {
       printf("Dear User,this analysis happens for sleep records over 1 week.Your entries are not enough\n");
       printf("Do you still want to continue?\n");
       printf("1-YES\n");
       printf("2-NO\n");
       printf("3-Want to complete the record?I can help.\n");
       printf("Enter your choice\n");
       scanf("%d",&choice1);
       switch(choice1)
       {
           case 1:printf("Okay,As you wish\n");
           break;
           case 2:printf("Come back later :)\n");
           return;
           case 3:printf("Sure,let's go ahead\n\n");
           start=update_record(start);
           break;
       }
    }
    avg_sleep=average_sleep(start);
    printf("What are your working hours per day?\n");
    scanf("%d",&wrk);
    printf("Do you have night shifts as well?\n");
    printf("1-Everyday\n");
    printf("2-Somedays\n");
    printf("3-NOOO !(pheww)\n");
    printf("Enter your choice\n");
    scanf("%d",&choice3);
    switch(choice3)
    {
        //Only night shift hours
        case 1:printf("Okay!!\n");
        printf("What are the working hours per night?\n");
        scanf("%d",&nshift);
        wrk=nshift;
        break;
        //Night shift hours plus day shift hours
        case 2:printf("What are the extra working hours per night?\n");
        scanf("%d",&nshift);
        wrk=wrk+nshift;
        break;
        case 3:printf("Thank God\n\n");
        break;
    }
    printf("Which one are you?\n");
    printf("1-LARKS(morning types)\n");
    printf("2-OWLS(night lovers)\n");
    printf("Enter your choice\n");
    scanf("%d",&choice2);
    printf("Do you have dream everyday?\n");
    printf("1-Everyday\n");
    printf("2-Somedays\n");
    printf("3-NOOO !(Damn)\n");
    printf("Enter your choice\n");
    scanf("%d",&choice4);
    //Main Report
    printf("******SLEEP ANALYSIS REPORT******\n\n");
    printf("Average Sleep=%f\n",avg_sleep);
    if(avg_sleep>7 && avg_sleep<9)
    {
        printf("Good!! You have proper sleep durations.\n\n");
    }
    else if(avg_sleep<7)
    {
        printf("Sleep duration is less than it should be.\n\n");
    }
    else
    {
        printf("You are oversleeping!!\n\n");
    }
    printf("Working hours over one week are %d\n\n",wrk*7);
    if(wrk>45)
        printf("Manage your working hours to avoid sleep deprivation and distress\n\n");
    else
        printf("Your working hours are ideal.Always maintain this balance\n\n");
    switch(choice2)
    {
    case 1:printf("Since you're a morning person, try sleeping early at night\n\n");
    break;
    case 2:printf("Since you're a night person,you might have less sleep hours\n");
    printf("Try taking afternoon naps to refresh\n\n");
    break;
    }
    switch(choice4)
    {
        case 1:printf("Dreams occur in stage 3 of sleeping i.e REM stage. Dreams also occur in deep sleep.\n");
        printf("Though many researchers say that you don't dream in deep sleep,dreaming everyday isn't a bad thing\n");
        printf("Your deep sleep hours are less\n\n");
        break;
        case 2:printf("Your deep sleep and light sleep hours are balanced\n");
        printf("Keep dreaming!!\n\n");
        break;
        case 3:printf("You might have very deep sleep at night\n\n");
        printf("You should try dreaming.\n");
        break;
    }
    printf("-------END-------\n\n");
}
/**
Function Name: bmr_info
Input Params: Nil
Return Type: Void
Description: Describes about Basal Metabolic Rate
**/
void bmr_info()
{
  char str;
  FILE * file;
  file = fopen( "bmr.txt" , "r");
   while(1)
   {
       str=fgetc(file);
       if(str==EOF)
        break;
       else
        printf("%c",str);
   }
   printf("\n\n");
   fclose(file);
   return;
}
/**
Function Name: bmr_chart
Input Params: Nil
Return Type: Void
Description: Displays the bmi chart
**/
void bmr_chart()
{
  char str;
  FILE * file;
  file = fopen( "bmr-chart.txt" , "r");
   while(1)
   {
       str=fgetc(file);
       if(str==EOF)
        break;
       else
        printf("%c",str);
   }
   printf("\n\n");
   fclose(file);
   return;
}
/**
Function Name: bmr_calc
Input Params: Nil
Return Type:Void
Description: Calculates the bmr index
**/
void bmr_calc()
{
    float weight,height,bmr,age;
    char gender;
    printf("Enter your weight in kgs\n");
    scanf("%f",&weight);
    printf("Enter your height in centimeter\n");
    scanf("%f",&height);
    printf("Enter your age in years\n");
    scanf("%f",&age);
    printf("What is your gender?\nPress M/m for Male\nPress F/f for Female\n\n");
    scanf(" %c",&gender);
    if(gender=='M' || gender=='m')
    {
        bmr=88.362+(13.397*weight)+(4.799*height)-(5.677*age);
    }
    else if(gender=='F' || gender=='f')
    {
        bmr=447.593+(9.247*weight)+(3.098*height)-(4.330*age);
    }
    else
    {
        printf("INVALID CHOICE\n\n");
        bmr_calc();
    }
    printf("Your Basal Metabollic Rate is %f\n\n\n",bmr);
}
/**
Function Name: BMR_calculator
Input Params: Nil
Return Type: Void
Description: Interface for BMR calculator
**/
void BMR_calculator()
{
   int choice;
while(1)
{
  printf("***Welcome to BMR calculator***\n");
  printf("1-What is BMR?\n");
  printf("2-Calculate your BMR\n");
  printf("3-BMR chart for men and women\n");
  printf("4-Exit\n");
  printf("Enter your choice\n");
  scanf("%d",&choice);
  switch(choice)
  {
      case 1: bmr_info();
      break;

      case 2:bmr_calc();
      break;

      case 3:printf("Opening file\n");
      bmr_chart();
      break;

      case 4:printf("Exiting...\n\n\n");
      return;
  }
 }
}
/**
Function Name: whr_info
Input Params: Nil
Return Type:Void
Description: Describes about Waist Hip Ratio
**/
void whr_info()
{
  char str;
  FILE * file;
  file = fopen( "whr.txt" , "r");
   while(1)
   {
       str=fgetc(file);
       if(str==EOF)
        break;
       else
        printf("%c",str);
   }
   printf("\n\n");
   fclose(file);
   return;
}
/**
Function Name: whr_chart
Input Params: Nil
Return Type: Void
Description: Displays the whr chart
**/
void whr_chart()
{
    char str;
  FILE * file;
  file = fopen( "whr-chart.txt" , "r");
   while(1)
   {
       str=fgetc(file);
       if(str==EOF)
        break;
       else
        printf("%c",str);
   }
   printf("\n\n");
   fclose(file);
   return;
}
/**
Function Name: whr_calc
Input Params: Nil
Return Type: Void
Description: Calculates the whr ratio
**/
void whr_calc()
{
    float waist,hip,whr;
    char gender;
    printf("Enter your waist size in centimeters\n");
    printf("HOW TO MEASURE:\nuse your tape measure to measure midway between your lowest rib and the top of your hips - it should be the part just above your belly button.\n\n");
    scanf("%f",&waist);
    printf("Enter your hip size in centimeters\n");
    printf("HOW TO MEASURE:\nmeasure at the widest point around the buttocks. Again, hold the tape snugly but don't pull it in, and make sure it's level all the way around.\n\n");
    scanf("%f",&hip);
    whr=waist/hip;
    printf("Waist hip ratio is %f\n\n",whr);
    printf("What is your gender?\nPress M/m for Male\nPress F/f for Female\n\n");
    scanf(" %c",&gender);
    if(gender=='M' || gender=='m')
    {
        if(whr<=0.95)
        {
            printf("LOW HEALTH RISK !!!\n\n");
            printf("Women with a ratio of 0.8 or below, and men at 0.95 or below are pear shaped.\n");
            printf("People with pear shaped bodies are in the lower risk category for health problems such as heart disease, type 2 diabetes and some forms of cancer.\n\n\n");
        }
        else if(whr>= 0.96 && whr<=1.0)
        {
            printf("MODERATE HEALTH RISK !!!\n\n");
            printf("People whose ratios fall between these apple and pear thresholds are at moderate risk of health problems, and are sometimes called avocados.\n\n\n");
        }
        else
        {
            printf("HIGH HEALTH RISK !!!\n\n");
            printf("Women with a ratio of 0.85 or above, and men with a ratio of 1.0 or above are considered to have apple shaped bodies.\n");
            printf("Fat tends to gather around the middle, and apple shaped bodies face a high risk of type 2 diabetes and heart disease, and even some types of cancer.\n\n\n");
        }
    }
    else if(gender=='F' || gender=='f')
    {
        if(whr<=0.80)
        {
            printf("LOW HEALTH RISK !!!\n\n");
            printf("Women with a ratio of 0.8 or below, and men at 0.95 or below are pear shaped.\n");
            printf("People with pear shaped bodies are in the lower risk category for health problems such as heart disease, type 2 diabetes and some forms of cancer.\n\n\n");
        }
        else if(whr>= 0.81 && whr<=0.84)
        {
            printf("MODERATE HEALTH RISK !!!\n\n");
            printf("People whose ratios fall between these apple and pear thresholds are at moderate risk of health problems, and are sometimes called avocados.\n\n\n");
        }
        else
        {
            printf("HIGH HEALTH RISK !!!\n\n");
            printf("Women with a ratio of 0.85 or above, and men with a ratio of 1.0 or above are considered to have apple shaped bodies.\n");
            printf("Fat tends to gather around the middle, and apple shaped bodies face a high risk of type 2 diabetes and heart disease, and even some types of cancer.\n\n\n");
        }
    }
    else
    {
        printf("INVALID CHOICE\n\n\n");
        whr_calc();
    }

}
/**
Function Name: WHR_calculator
Input Params: Nil
Return Type: Void
Description:Provides the interface for whr calculation
**/
void WHR_calculator()
{
int choice;
while(1)
{
  printf("***Welcome to WHR calculator***\n");
  printf("1-What is WHR?\n");
  printf("2-Calculate your WHR\n");
  printf("3-WHR chart for men and women\n");
  printf("4-Exit\n");
  printf("Enter your choice\n");
  scanf("%d",&choice);
  switch(choice)
  {
      case 1: whr_info();
      break;

      case 2:whr_calc();
      break;

      case 3:printf("Opening file\n");
      whr_chart();
      break;

      case 4:printf("Exiting...\n\n\n");
      return;
  }
}
}
/**
Function Name:bmi_info;
Input Params: Nil
Return Type: Void
Description: Describes Body Mass Index
**/
void bmi_info()
{
  char str;
  FILE * file;
  file = fopen( "bmi.txt" , "r");
   while(1)
   {
       str=fgetc(file);
       if(str==EOF)
        break;
       else
        printf("%c",str);
   }
   printf("\n\n");
   fclose(file);
   return;
}

/**
Function Name: bmi_calc
Input Params: Nil
Return Type: Void
Description: Calculates the bmi index
**/
void bmi_calc()
{
  float weight,height;
  printf("Enter weight in kgs and height in meters\n");
  scanf("%f%f",&weight,&height);
  bmi=weight/(height*height);
  printf("Body Mass Index: %f\n",bmi);
    if(bmi<18.5)
    {
        printf("You are Underweight !\nLearn how to gain weight\n\n");
    }
    else if(bmi<25)
    {
        printf("You are fit and fine.Normal weight!\n\n");
    }
    else if(bmi<30)
    {
        printf("You are over weight\n Learn how to lose weight\n\n");
    }
    else
    {
        printf("You suffer from obesity\nTry reading our tips to cure obesity\n\n");
    }
}
/**
Function Name: bmi_chart
Input Params: Nil
Return Type: Void
Description: Displays the bmi chart
**/
void bmi_chart()
{
  char str;
  FILE * file;
  file = fopen( "bmi-chart.txt" , "r");
   while(1)
   {
       str=fgetc(file);
       if(str==EOF)
        break;
       else
        printf("%c",str);
   }
   printf("\n\n");
   fclose(file);
   return;
}
/**
Function Name: BMI_calculator
Input Params: Nil
Return Type: Void
Description: Provides the interface for BMI calculation
**/
void BMI_calculator()
{
int choice;
while(1)
{
  printf("***Welcome to BMI calculator***\n");
  printf("1-What is BMI?\n");
  printf("2-Calculate your BMI\n");
  printf("3-BMI chart for men and women\n");
  printf("4-Exit\n");
  printf("Enter your choice\n");
  scanf("%d",&choice);
  switch(choice)
  {
      case 1: bmi_info();
      break;

      case 2:bmi_calc();
      break;

      case 3:printf("Opening file\n");
      bmi_chart();
      break;

      case 4:printf("Exiting...\n\n\n");
      return;
  }

}
}

/**
Function Name:full
Input Params: NILL
Return Type: int
Description: checks if the reminders array is full or not
**/
int full()
{
    if(globalCount == 20)
    {
        return TRUE;
    }
    return FALSE;
}

/**
Function Name:empty
Input Params: NILL
Return Type: int
Description: checks if the reminders array is empty or not
**/

int empty()
{
    if(globalCount <= 0)
    {
        return TRUE;
    }

    return FALSE;
}

/**
Function Name:printReminders
Input Params: NILL
Return Type: void
Description: Prints the current reminders
**/
void printReminders()
{
    int i=0;
    if(!empty())
    {
       printf("The present reminders are:\n");
       for(i=0;i<globalCount;i++)
       {
            printf("REMINDER:%s\t",reminders[i].message);
            printf("MONTH:%d\t",reminders[i].month);
            printf("DATE:%d\t",reminders[i].date);
            printf("PRIORITY:%d\t\n",reminders[i].priority);
            printf("\n");
       }
       return;
    }

    printf("No reminders at present\n");
}

/**
Function Name:addPriority
Input Params: NILL
Return Type: void
Description: adds priority to the reminder based on date and month and sorts the reminders accordingly
**/
void addPriority()
{
   if(globalCount == 0)
            return;
    if(globalCount == 1)
    {
        globalPriority=1;
        reminders[globalCount-1].priority = globalPriority;
        return;
    }

        globalPriority=reminders[globalCount-2].priority+1;
        reminders[globalCount-1].priority = globalPriority;

   REM temp;
   int swap=0;
   int key1=0;
   int flag=0;
   int i, key, j;

   for (i = 1; i < globalCount; i++)
   {
       temp=reminders[i];
       key = reminders[i].month;

       j = i-1;

       while (j >= 0 && reminders[j].month >= key)
       {
           if(reminders[j].month == key)
           {
                key1=reminders[i].date;
                while(j>=0 && reminders[j].date>key1)
                {
                     swap=temp.priority;
                     temp.priority=reminders[j].priority;
                     reminders[j].priority=swap;
                     reminders[j+1] = reminders[j];
                     j--;
                }
                reminders[j+1] = temp;
                flag=1;
           }

           if(j>=0  && reminders[j].month > key)
           {
              swap=temp.priority;
              temp.priority=reminders[j].priority;
              reminders[j].priority=swap;
              reminders[j+1] = reminders[j];
              j = j-1;
           }

           if(flag == 0)
            {
              reminders[j+1] = temp;
            }

           if(flag == 1)
           {
               flag=0;
               break;
           }
       }
   }

}

/**
Function Name:dump
Input Params: NILL
Return Type: void
Description: dumps the reminders into the respective respective file,
**/
void dump()
{
    int date=0;
    int month=0;
    int priority=0;
    char r[20];
    int i;

    FILE *fptr = fopen("reminders.txt", "w");
    if (fptr == NULL)
    {
        printf("Could not open file");
        return;
    }

    for (i=0; i<globalCount; i++)
    {

        strcpy(r,reminders[i].message);
        fprintf(fptr,"REMINDER:%s\t",r);

        month=reminders[i].month;
        fprintf(fptr,"MONTH:%d\t",month);

        date=reminders[i].date;
        fprintf(fptr,"DATE:%d\t",date);

        priority=reminders[i].priority;
        fprintf(fptr,"PRIORITY:%d\t\n",priority);

        fprintf(fptr,"\n");

    }
    fclose(fptr);
    return ;
}

/**
Function Name:addReminder
Input Params: NILL
Return Type: void
Description: adds reminders based on the user input
**/
void addReminder()
{
    if(!full())
    {
      printf("Enter the date\n");
      fflush(stdin);
      scanf("%d",&reminders[globalCount].date);

      printf("Enter the month\n");
      fflush(stdin);
      scanf("%d",&reminders[globalCount].month);

      printf("Enter the reminder\n");
      fflush(stdin);
      scanf("%[^\n]s",reminders[globalCount].message);

      globalCount++;
      dump();
      printf("Reminder has been successfully added.\n\n");
    }
    else
        printf("Sorry no more reminders can be added due to insuffcient space\n");
}

/**
Function Name:Delete
Input Params: NILL
Return Type: void
Description: deletes all the outdated reminders
**/
void Delete()
{
    if(!empty())
    {
    int i=0,count=0;
    while(reminders[i].month <= todaysMonth)
    {
        if(reminders[i].date<=todaysDay)
        {
          reminders[i].priority=-1;
          i++;
          count++;
        }
        dump();

    }

    int j=0;
    for(;i<globalCount;i++)
    {
        reminders[i].priority=j+1;
        reminders[j]=reminders[i];
        j++;
    }
    globalCount=globalCount-count;
    printReminders();
    }
    else
        printf("No reminders present\n");
}

/**
Function Name:deletePriority
Input Params: priority of the specified reminder
Return Type: void
Description: deletes the user specified reminder
**/
void deletePriority(int priority1)
{
    int i=0;
    if(!empty())
        {
        if(priority1<=globalCount && priority1>=1)
        {
            reminders[priority1-1].priority=-1;
            for(i=priority1;i<globalCount;i++)
                {
                    reminders[i].priority=i;
                    reminders[i-1]=reminders[i];
                }
            globalCount=globalCount-1;
            dump();
            return;
        }
        else
        {
            printf("Invalid priority\n");
        }
       }
        else
        printf("No reminders at present\n");
}

/**
Function Name: isLeapyear
Input Params: month
Return Type: Integer
Description: Determines whether the month is a leap year or not
**/
int isLeapYear( int y ){
    return(y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0));
}
/**
Function Name: leapYears
Input Params: month
Return Type: Integer
Description: Prints the leap years
**/
int leapYears( int y ){
    return y/4 - y/100 + y/400;
}
/**
Function Name: todayOf
Input Params: day,month,year
Return Type: Integer
Description: Returns the day of the given month
**/
int todayOf( int y, int m, int d) {
    static int DayOfMonth[] =
        { -1,0,31,59,90,120,151,181,212,243,273,304,334};
    return DayOfMonth[m] + d + ((m>2 && isLeapYear(y))? 1 : 0);
}
/**
Function Name: days
Input Params: year,month and day
Return Type: long
Description: Gives the number of days in the year
**/
long days( int y, int m, int d){
    int lastYear;
    lastYear = y - 1;
    return 365L * lastYear + leapYears(lastYear) + todayOf(y,m,d);
}
/**
Function Name: calender
Input Params: year and month
Return Type: void
Description: Prints the calender of the given month and year
**/
void calendar(int y, int m){
    FILE *fp;
    Note* notes, note;
    int len, j, hasNote = 0;
    char choice;
    const char *NameOfMonth[] = { NULL/*dummp*/,
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    char Week[] = "Su   Mo   Tu   We   Th   Fr   Sa";
    int DayOfMonth[] =
        { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
    int weekOfTopDay;
    int i,day;

    weekOfTopDay = days(y, m, 1) % 7;

    fp = fopen("note.bin", "rb");
    if (fp == NULL) {
      printf("Couldn't read notes\n");
    }
    len = 0;
    while(fread(&note, sizeof(Note), 1, fp)) {
      if (note.year == y && note.month == m) {
        len++;
      }
    }
    rewind(fp);
    j = 0;
    notes = (Note*) malloc (sizeof(Note) * len);
    while(fread(&note, sizeof(Note), 1, fp)) {
      if (note.year == y && note.month == m) {
        notes[j] = note;
        j++;
      }
    }

    fclose(fp);

    if(isLeapYear(y))
        DayOfMonth[2] = 29;
    printf("\n     %s %d\n%s\n", NameOfMonth[m], y, Week);

    for(i=0;i<weekOfTopDay;i++)
        printf("   ");
    for(i=weekOfTopDay,day=1;day <= DayOfMonth[m];i++,day++){
        hasNote = 0;
        for (j = 0; j < len; j++) {
          if (notes[j].day == day) {
            printf("|%2d| ",day);
            hasNote = 1;
            break;
          }
        }
        if (hasNote == 0) {
          printf("%2d   ",day);
        }
        if(i % 7 == 6)
            printf("\n");
    }
    printf("\n");
    scanf("\n%c", &choice);
    if (choice == 's') {
      printf("Here are list of notes for %d %d\n", m, y);
      for (j = 0; j < len; j++) {
        printf("%d: %s\n", notes[j].day, notes[j].note);
      }
    } else {
      return;
    }
}
/**
Function Name: getDayNumber
Input Params: date,month and year
Return Type: Integer
Description: Gets the position of day in the month
**/
int getDayNumber(int d, int m, int y){ //retuns the day number
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
    return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}
/**
Function Name: getName
Input Params: day
Return Type: string
Description: Displays the corresponding day
**/
char *getName(int day){ //returns the name of the day
   switch(day){
      case 0 :return("Sunday");
      case 1 :return("Monday");
      case 2 :return("Tuesday");
      case 3 :return("Wednesday");
      case 4 :return("Thursday");
      case 5 :return("Friday");
      case 6 :return("Saturday");
      default:return("Error: Invalid Argument Passed");
   }
}
/**
Function Name: flush
Input Params: NILL
Return Type: void
Description: Prints the notes from a file
**/
void flush()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
Function Name: pms_text
Input Params: NILL
Return Type: void
Description: Prints the tips to handle PMS
**/
void pms_text()
{
  char str;
  FILE * file;
  file = fopen( "pms.txt" , "r");
   while(1)
   {
       str=fgetc(file);
       if(str==EOF)
        break;
       else
        printf("%c",str);
   }
   printf("\n\n");
   fclose(file);
   return;
}
/**
Function Name: 	read_calories_burnt_today
Input Params:  	calories_burnt
Return Type:   	void
Description:   	In this function we take calories burnt as input(call by reference),
                calories burnt is read from fitness module and stored in a binary
                search tree.
**/
void read_calories_burnt_today(int *pcalories_burnt)
{
	int calorie_burnt=0;
	if(head!=NULL)
        calorie_burnt=head->data.calories;
	int choice,quantity,calorie_intake;
	int calorie_value[6]={400,870,550,600,500,600};
	printf("\nSelect food you had today\n");
	printf("1-Roti\t400\n");
	printf("2-Chicken Kurma\t870\n");
	printf("3-Aloo gobi\t550\n");
	printf("4-Biriyani\t600\n");
	printf("5-curry\t500\n");
	printf("6-pulav\t600\n");
	printf("Enter food and quantity");
	scanf("%d %d",&choice,&quantity);
	calorie_intake=calorie_value[choice-1]*quantity;
	if((calorie_intake-calorie_burnt)<100)
        printf("You are eating too less please eat more to maintain a healthy lifestyle\n");
    else if((calorie_intake-calorie_burnt)>500)
        printf("you are not exercising enough please try to burn more calories everyday\n");
	*pcalories_burnt=calorie_burnt;
}
/**
Function Name: 	insert_bst
Input Params:  	address of root node and calories burnt today
Return Type:   	pointer to NODE
Description:   	In this function we take calories as input(call by reference),
	       	    calories burnt is read from fitness module and stored in a binary
                search tree.
**/
NODE* insert_bst(NODE* root,int calories)
{
	NODE* newnode;
    newnode=(NODE*)malloc(sizeof(NODE));
	newnode->calories= calories;
	newnode->day.date=today.date;
	newnode->day.month=today.month;
	newnode->day.year=today.year;
	newnode->left=NULL;
	newnode->right=NULL;
	if(root==NULL)
	{
		return newnode;
	}
	NODE *curr;
	NODE *prev;
	curr=root;
	prev=NULL;
	while(curr!=NULL)
	{
		prev=curr;
		if(curr->calories>newnode->calories)

			curr=curr->left;
		else
			curr=curr->right;
	}
	if(prev->calories>newnode->calories)
		prev->left=newnode;
	else
		prev->right=newnode;
	return root;
}
/**
Function Name: 	delete_bst
Input Params:  	address of root node and the calorie date to be deleted
Return Type:   	pointer to NODE
Description:   	In this function we take calories burnt as input(call by reference),
	       	    calories burnt is read from fitness module and stored in a binary
                search tree.
**/
NODE* delete_bst(NODE* root,int item)
{
	if(root==NULL)
	{
		printf("NO DATA TO BE DELETED");
		return root;
	}
	NODE *curr,*parent,*successor,*p;
	curr=root;
	parent=NULL;
	while(curr!=NULL && curr->calories!=item)
	{
		parent=curr;
		if(item<(curr->calories))
			curr=curr->left;
		else
			curr=curr->right;
	}
	if(curr==NULL)
	{
		printf("calorie value to be deleted not found\n");
		return root;
	}
	if(curr->left==NULL)
	{
		p=curr->right;
	}
	else if(curr->right==NULL)
	{
		p=curr->left;
	}
	else
	{
		successor=curr->right;
		while(successor->left!=NULL)
			successor=successor->left;
		p=curr->right;
		successor->left=curr->left;
	}
	if(parent==NULL)
	{
		free(curr);

		return p;
	}
	if(curr==parent->left)
		parent->left=p;
	else
		parent->right=p;
	free(curr);
	return root;
}
/**
Function Name: 	computeLPSArray
Input Params:   pattern to be searched for, length of pattern,
                pointer to starting address of lps array.
Return Type:    void
Description:   	This is a function to compute pie table for
                KMP algorithm
**/
// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(char* pat, int M, int* lps)
{
    // length of the previous longest prefix suffix
    int len = 0;
    lps[0] = 0; // lps[0] is always 0
    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
	{
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // to search step.
            if (len != 0)
		{
                len = lps[len - 1];
                // Also, we do not increment i here
            	}
            else // if (len == 0)
            {
                lps[i] = 0;

                i++;
            }
        }
    }
}
/**
Function Name: 	KMP
Input Params:  	text typed by the end user.
Return Type:   	void
Description:   	In this function we find if user has entered certain
                words which give away that he/she is depressed.
**/
void KMP(char* txt)
{
	char pattern_words[5][20]={"depression","disappointed","suicide","die","hate myself"};
	char pat[20];
	for(int h=0; h<5; h++)
	{
		strcpy(pat,pattern_words[h]);
		int M = strlen(pat);
		int N = strlen(txt);
    		// create lps[] that will hold the longest prefix suffix
		// values for pattern
    		int lps[M];
    		// Preprocess the pattern (calculate lps[] array)
    		computeLPSArray(pat, M, lps);
    		int i = 0; // index for txt[]
		int j = 0; // index for pat[]
    		while (i < N)
		{
        		if (pat[j] == txt[i])
			{
                    j++;
			        i++;
        		}
        		if (j == M)
			{
                printf("\nJust remeber help will always be given to those who ask for it \nhelpline no-9902253085\n");
				break;
                    j = lps[j - 1];
        		}
        		// mismatch after j matches
        		else if (i < N && pat[j] != txt[i])
            {
            		// Do not match lps[0..lps[j-1]] characters,
            		// they will match anyway
            		if (j != 0)
	                	j = lps[j - 1];
            		else
                		i = i + 1;
        		}
    		}
	}
}
/**
Function Name: 	Hash_Planner
Input Params:  	NULL
Return Type:   	void
Description:   	Our purpose is to suggest a diet for user
                for this we use global variable bmi and compute
                which of the pre-stored diet plan is ideal for user.
**/
void Hash_Planner()
{
	int index;
	char diets[4][10000]={"Let's get fat! \n\n Foods that should be included every day \n a-Full-cream milk: 750 - 1000 ml (3 to 4 cups) \n b-Meat, fish, eggs and other protein foods: \n c-3-5 servings (90 to 150 g) Bread and cereals: \n d-8-12 servings (e.g. up to 6 cups of starch a day) Fruit and vegetables: \n e-3-5 servings Fats and oils: \n f-90 g (6 tablespoons) Healthy desserts: 1-2 servings","You have a healthy body let's keep that going\n a-base meals on starchy foods like potatoes, bread, rice or pasta\nb- have some dairy or dairy alternatives (such as soya drinks)\nc- eat some beans, pulses, fish, eggs, meat and other protein\nd- choose unsaturated oils and spreads, eaten in small amounts \n e- drink plenty of fluids\n","\nBeing a bit chubby is not bad, well we are here to help you \na- Whole grains (whole wheat, steel cut oats, brown rice, quinoa)\nb- Vegetables (a colorful variety-not potatoes\nc- Whole fruits (not fruit juices)\nd- Nuts, seeds, beans, and other healthful sources of protein (fish and poultry)\ne- Plant oils (olive and other vegetable oils)\n","Well you have been ignoring your health too much get a med as soon as possible\nThe National Heart,\n Lung and Blood Institute recommends that you lose 1 to 2 pounds per week by lowering the amount of calories you consume by between 500 and 1,000 calories per day or by consuming a low-calorie daily diet that contains between 1,000 and 1,200 calories or between 1,200 and 1,600 calories if you weigh more than 165 pounds or exercise regularly. Taking nutritional supplements can ensure you fulfill all of the recommended daily allowances for vitamins, minerals and other nutrients."};
    int bmi;
	index=(bmi-15)/4;
	if(index>4)
		index=4;
	printf("\n********************************************************************\n Ideal diet for you %s \n",diets[index]);
}
/**
Function Name: 	Update_date
Input Params:  	NULL
Return Type:   	void
Description:   	Function updates date and date, month,year,
                input has to be given from end user.
**/
void Update_date()
{
	printf("Enter day\n");
	scanf("%d",&today.date);
	printf("Enter  month in numbers\n");
	scanf("%d",&today.month);
	printf("Enter year\n");
	scanf("%d",&today.year);
}
/**
Function Name: 	Print_date
Input Params:  	NULL
Return Type:   	void
Description:   	Prints last updated date.
**/
void Print_date()
{
	printf("%d/%d/%d",today.date,today.month,today.year);
}
/**
Function Name: 	insert_bst
Input Params:  	address of root node and calories burnt today
Return Type:   	pointer to NODE
Description:   	In this function we take calories burnt as input(call by reference),
                calories burnt is read from fitness module and stored in a binary
                search tree.
**/
void inorder(NODE *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("calories=%d  date=%d/%d/%d\n",root->calories,root->day.date,root->day.month,root->day.year);
        inorder(root->right);
    }
}
/**
Function Name: 	pre-order
Input Params:  	pointer to root NODE
Return Type:   	void
Description:   	print inorder tranfer
**/
void preorder(NODE* root)
{
    if(root!=NULL)
    {
        printf("calories=%d  date=%d/%d/%d\n",root->calories,root->day.date,root->day.month,root->day.year);
        preorder(root->left);
        preorder(root->right);
    }
}
/**
Function Name: 	postorder
Input Params:  	pointer to root NODE
Return Type:   	void
Description:   	prints bst in postorder.
**/
void postorder(NODE* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("calories=%d  date=%d/%d/%d\n",root->calories,root->day.date,root->day.month,root->day.year);
    }
}
/**
Function Name: 	min
Input Params:  	pointer to root NODE
Return Type:   	void
Description:   	traverses to the left most node therefore the least
                calorie value and prints it.
**/
void min(NODE* root)
{
    NODE *curr;
    curr=root;
    while(curr->left!=NULL)
    {
        curr=curr->left;
    }
    printf("calories=%d  date=%d/%d/%d\n",curr->calories,curr->day.date,curr->day.month,curr->day.year);
}
/**
Function Name: 	max
Input Params:  	pointer to root NODE
Return Type:   	void
Description:   	traverses to the maximum most node therefore prints the maximum
                calorie value and prints it.
**/
void max(NODE* root)
{
    NODE *curr;
    curr=root;
    while(curr->right!=NULL)
    {
        curr=curr->right;
    }
    printf("calories=%d  date=%d/%d/%d\n",curr->calories,curr->day.date,curr->day.month,curr->day.year);
}
// print BST reverse Order
/**
Function Name: 	insert_bst
Input Params:  	address of root node and calories burnt today
Return Type:   	pointer to NODE
Description:   	In this function we take calories burnt as input(call by reference),
	       	calories burnt is read from fitness module and stored in a binary
		search tree.
**/
void reverseOrder(NODE* root, int n,int i)
{
	if (root == NULL)
		return;
        reverseOrder(root->right,n,i);
        if(++i<n)
        	printf("calories=%d\n  date=%d/%d/%d \n",root->calories,root->day.date,root->day.month,root->day.year);
        reverseOrder(root->left,n,i);
}
/**
Function Name: 	print_below_average
Input Params:  	pointer to root NODE and average calorie value.
Return Type:   	void
Description:    prints the calorie value along with date that are below average.
**/
void print_below_average(NODE *root, int k)
{
	if(root != NULL)
	{
        /* Recursively print smaller nodes in left sub-tree */
        print_below_average(root->left, k);
        /* If current node is less than k, then prints it */
        if(root->calories < k)
        	printf("calories=%d  date=%d/%d/%d\n",root->calories,root->day.date,root->day.month,root->day.year);
        /* Recursively print smaller nodes in right sub-tree */
        print_below_average(root->right, k);
	}
}
/**
Function Name: 	print_above_average
Input Params:  	pointer to root NODE and average calorie value.
Return Type:   	void
Description:    prints the calorie value along with date that are above average.
**/
void print_above_average(NODE *root, int k)
{
	if(root != NULL)
	{
        /* Recursively print smaller nodes in left sub-tree */
        print_below_average(root->left, k);
        /* If current node is less than k, then prints it */
        if(root->calories > k)
        	printf("calories=%d  date=%d/%d/%d\n",root->calories,root->day.date,root->day.month,root->day.year);
        /* Recursively print smaller nodes in right sub-tree */
        print_below_average(root->right,k);
	}
}
/**
Function Name: 	calorie_menu
Input Params:  	NULL.
Return Type:   	void
Description:    prints the menu for calorie management.
**/
void calorie_menu()
{
    printf("\n***********************************************************************\n");
	printf("1-View calories burnt today\n");
	printf("2-Update todays calorie data\n");
	printf("3-Delete certain calorie data\n");
	printf("4-Print calorie report\n");
	printf("5-Have a look at my high1est performing days\n");
	printf("6-Update today's date\n");
	printf("7-Worst performing day\n");
	printf("8-Best Performing day\n");
	printf("9-Average calories Burnt\n");
	printf("10-Days calories burnt in more than average calories\n");
	printf("11-Days calories burnt is less than average calories\n");
	printf("12-Print today's date\n");
	printf("13-Write about how you feel about your physical and mental health, we are here to help you, ALWAYS\n");
	printf("14-Plan a diet for me\n");
	printf("15-Terminate calorie keeper\n");
	printf("*************************************************************************\n");
}
/**
Function Name: 	calorie_chart
Input Params:  	NULL.
Return Type:   	void
Description:    function for calorie chart.
**/
void calorie_chart()
{
	int calories_burnt=0,del_calorie;
	int choice=0;
	char text[1000];
	while(1)
{
    calorie_menu();
	printf("\n**Enter choice**\n");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:	printf("%d",calories_burnt);
		    break;
	case 2:read_calories_burnt_today(&calories_burnt);
		   root=insert_bst(root,calories_burnt);
		   break;
	case 3:	inorder(root);
           printf("Enter calorie value to be deleted");
		   scanf("%d",&del_calorie);
		   root=delete_bst(root,del_calorie);
		   break;
	case 4:inorder(root);
		   break;
	case 5:reverseOrder(root,5,0);
		   break;
	case 6:Update_date();
		   break;
	case 7:min(root);
		   break;
	case 8:max(root);
		   break;
	case 9:printf("Average calories burnt: %d",root->calories);
           break;
	case 10:print_above_average(root,root->calories);
		    break;
	case 11:print_below_average(root,root->calories);
            break;
	case 12:Print_date();
            break;
	case 13:printf("\nWrite your heart out...your body is all you have\n");
		    scanf("%s",text);
		    KMP(text);
		    break;
	case 14:Hash_Planner();
            break;
	case 15:return;
	}
}
}
/*Function:       read_list
Description:    reads the fitness data from the file.
Input parameters:    pointer to the head node of the linked list
Return Type:   pointer to the head node of the linked list*/
struct node* read_list(struct node *head)
{
    FILE *fp;
    fp = fopen("fitness_list.txt", "r");
    if(fp == NULL)
    {
        printf("Unable to open file\n");
        return 0;
    }
    while(1)
    {
        if(feof(fp))
            break;
        struct node *p;
        p=(struct node *)malloc(sizeof(struct node));
        if(p==NULL)
        {
            printf("Node creation failed\n");
            return head;
        }
        node_count++;
        fscanf(fp, "%d %d %d\n", &p->data.steps, &p->data.distance , &p->data.calories);
        p->next=head;
        if(head!=NULL)
        head->prev=p;
        head=p;
    }
    fclose(fp);
    return head;
}
/*Function:       easter_egg
Description:    prints an easter egg.
Input parameters:    NULL
Return Type:   NULL*/
void easter_egg()
{
    printf("                                               88\n");
    printf("                                               ##\n");
    printf("\n");
    printf("8b,dPPYba, 88       88 8b,dPPYba,  8b,dPPYba,  88 8b,dPPYba,   ,adPPYb,d8\n");
    printf("88P'   Y8  88       88 88P'    `8a 88P'    `8a 88 88P'    `8a a8     `Y88\n");
    printf("88         88       88 88       88 88       88 88 88       88 8b       88\n");
    printf("88         8a,   ,a88  88       88 88       88 88 88       88  8a,   ,d88\n");
    printf("88          `YbbdP'Y8  88       88 88       88 88 88       88  ` YbbdPY88\n");
    printf("                                                               aa,    ,88\n");
    printf("                                                                #Y8bbdP;\n");
    printf("Created by:\n");
    printf("Vibha Hegde\n");
    printf("Srushti B\n");
    printf("Sneha B\n");
    printf("Shweta Roy\n");
    printf("K L Vijeth\n");
    printf("EE Sala Cup pakka namde;)\n");
}
/*Function:       write_list
Description:    writes the fitness data into the file.
Input parameters:    pointer to the head node of the linked list
Return Type:   NULL*/
void write_list(struct node* head)
{
    FILE *fp;
    struct node *p;
    fp = fopen("fitness_list.txt", "w");
    if(fp == NULL)
    {
        printf("Unable to open file\n");
        return;
    }
    p=head;
    if(head==NULL)
        return;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    while(p!=NULL)
    {
        fprintf(fp, "%d %d %d\n", p->data.steps, p->data.distance , p->data.calories);
        p=p->prev;
    }
    fclose(fp);
}
/*Function:       user_read
Description:    reads the user data from the file.
Input parameters:    NULL
Return Type:   NULL*/
void user_read()
{
    FILE *fp;
    int x;
    fp = fopen("user.txt", "r");
    if(fp == NULL)
    {
        printf("Unable to open file\n");
        return ;
    }
    fscanf(fp, "%d\n", &x);
    if(!x)
    {
        fclose(fp);
        return;
    }
    fscanf(fp, "%[^\n]s\n", user.name);
    fscanf(fp, "%d\n", &user.height);
    fscanf(fp, "%d\n", &user.weight);
    fscanf(fp, "%d\n", &user.age);
    fscanf(fp, "%d\n", &user.cal_goal);
    fscanf(fp, "%s\n", user.gender);
    user_flag=1;
    fclose(fp);
}
/*Function:       write_read
Description:    writes the user data into the file.
Input parameters:    NULL
Return Type:   NULL*/
void user_write()
{
    FILE *fp;
    int x=1;
    fp = fopen("user.txt", "w");
    if(fp == NULL)
    {
        printf("Unable to open file\n");
        return ;
    }
    fprintf(fp, "%d\n", x);
    fprintf(fp, "%s\n", user.name);
    fprintf(fp, "%d\n", user.height);
    fprintf(fp, "%d\n", user.weight);
    fprintf(fp, "%d\n", user.age);
    fprintf(fp, "%d\n", user.cal_goal);
    fprintf(fp, "%s\n", user.gender);
    fclose(fp);
}
/*Function:       clear_user_data
Description:    clears all the data
Input parameters:    NULL
Return Type:   NULL*/
void clear_user_data()
{
    int choice;
    printf("Are you sure you want to delete all your data??\n");
    printf("Press 1 to continue\n");
    scanf("%d",&choice);
    if(choice!=1)
    {
        return;
    }
    FILE *fp,*fp1;
    int x=0;
    fp = fopen("user.txt", "w");
    if(fp == NULL)
    {
        printf("Unable to open file\n");
        return ;
    }
    fprintf(fp, "%d\n", x);
    fclose(fp);
    fp1 = fopen("fitness_list.txt", "w");
    if(fp1 == NULL)
    {
        printf("Unable to open file\n");
        return;
    }
    fclose(fp1);
}
/*Function:       print_today
Description:    prints tracked data of the day.
Input parameters:    pointer to the head node of the linked list
Return Type:   NULL*/
void print_today(struct node *head)
{
    if(head!=NULL)
    {
        printf("Your activity today\n");
        printf("Steps:%d\n",head->data.steps);
        printf("Distance:%d\n",head->data.distance);
        printf("calories burned:%d\n",head->data.calories);
    }
    else
        printf("No data to display\n");
}
/*Function:       average_week
Description:    calculates and prints the weekly average of the tracked data
Input parameters:    pointer to the head node of the linked list
Return Type:   NULL*/
void average_week(struct node *head)
{
    struct node *p=head;
    int i=0;
    int sum_step=0,sum_dist=0,sum_cal=0;
    if(head==NULL)
    {
        printf("No data to display\n");
        return;
    }
    while (i<7&&p!=NULL)
    {
       sum_step= sum_step+p->data.steps;
       sum_dist= sum_dist+p->data.distance;
       sum_cal= sum_cal+p->data.calories;
       p=p->next;
       i++;
    }
    printf("Average steps:%d\n",(sum_step/i));
    printf("Average distance:%d\n",(sum_dist/i));
    printf("Average calories burned:%d\n",(sum_cal/i));
}
/*Function:       average
Description:    calculates and prints the average of the tracked data
Input parameters:    pointer to the head node of the linked list
Return Type:   NULL*/
void average(struct node *head)
{
    struct node *p=head;
    int i=0;
    int sum_step=0,sum_dist=0,sum_cal=0;
    if(head==NULL)
    {
        printf("No data to display\n");
        return;
    }
    while (p!=NULL)
    {
       sum_step= sum_step+p->data.steps;
       sum_dist= sum_dist+p->data.distance;
       sum_cal= sum_cal+p->data.calories;
       p=p->next;
       i++;
    }
    printf("Average steps:%d\n",(sum_step/i));
    printf("Average distance:%d\n",(sum_dist/i));
    printf("Average calories burned:%d\n",(sum_cal/i));
}
/*Function:       get_user_data
Description:    gets the details from the user
Input parameters:    NULL
Return Type:   NULL*/
void get_user_data()
{
    printf("******Welcome to the fitness tracker******\n");
    printf("Please Enter your name\n");
    scanf("%[^\n]s",user.name);
    printf("Enter your age\n");
    scanf("%d",&user.age);
    printf("Enter your weight\n");
    scanf("%d",&user.weight);
    printf("Enter your height in meters\n");
    scanf("%d",&user.height);
    printf("Enter your daily calorie goal\n");
    scanf("%d",&user.cal_goal);
    printf("Enter gender: Male/Female\n");
    scanf("%s",user.gender);
}
/*Function:       new_node
Description:    creates a new node in the linked list and initialises all values to 0
Input parameters:    pointer to the head node of the linked list
Return Type:   pointer to the new head node*/
struct node* new_node(struct node *head)
{
    struct node *p;
	p=(struct node *)malloc(sizeof(struct node));
	if(p==NULL)
    {
        printf("Node creation failed\n");
        return head;
    }
    node_count++;
	p->data.steps=0;
	p->data.distance=0;
	p->data.calories=0;
	if(head==NULL)
        return p;
	p->next=head;
	head->prev=p;
    return p;
}
/*Function:       walking
Description:    calculates the steps distance and calories for walking
Input parameters:    pointer to the head node of the linked list
Return Type:   pointer to the head node*/
struct node* walking(struct node *head)
{
    if (user.height<160)
    {
        if(user.weight<60)
        {
            step_var=73;
            dist_var=70;
            cal_var=2;
        }
        else
        {
            step_var=73;
            dist_var=65;
            cal_var=4;
        }
    }
    else
    {
      if(user.weight>70)
        {
            step_var=68;
            dist_var=73;
            cal_var=2;
        }
        else
        {
            step_var=68;
            dist_var=68;
            cal_var=4;
        }
    }
    int x;
	printf("Enter the duration of walking in minutes \n");
    scanf("%d",&x);
	head->data.steps= (head->data.steps)+(step_var*x);
	head->data.distance= (head->data.distance)+(dist_var*x);
	head->data.calories= (head->data.calories+cal_var*x);
	return head;
}
/*Function:       jogging
Description:    calculates the steps distance and calories for jogging
Input parameters:    pointer to the head node of the linked list
Return Type:   pointer to the head node*/
struct node* jogging(struct node *head)
{
     if (user.height<160)
    {
        if(user.weight<60)
        {
            step_var=130;
            dist_var=100;
            cal_var=4;
        }
        else
        {
            step_var=125;
            dist_var=95;
            cal_var=8;
        }
    }
    else
    {
      if(user.weight>70)
        {
            step_var=135;
            dist_var=105;
            cal_var=4;
        }
        else
        {
            step_var=130;
            dist_var=100;
            cal_var=8;
        }
    }
    int x;
	printf("Enter the duration of jogging in minutes \n");
    scanf("%d",&x);
	head->data.steps=head->data.steps+step_var*x;
	head->data.distance=head->data.distance+dist_var*x;
	head->data.calories=head->data.calories+cal_var*x;
	return head;
}
/*Function:       running
Description:    calculates the steps distance and calories for running
Input parameters:    pointer to the head node of the linked list
Return Type:   pointer to the head node*/
struct node* running(struct node *head)
{
    if (user.height<160)
    {
        if(user.weight<60)
        {
            step_var=170;
            dist_var=130;
            cal_var=7;
        }
        else
        {
            step_var=165;
            dist_var=125;
            cal_var=9;
        }
    }
    else
    {
      if(user.weight<70)
        {
            step_var=170;
            dist_var=130;
            cal_var=8;
        }
        else
        {
            step_var=165;
            dist_var=125;
            cal_var=9;
        }
    }
    int x;
	printf("Enter the duration of running in minutes \n");
    scanf("%d",&x);
	head->data.steps=head->data.steps+step_var*x;
	head->data.distance=head->data.distance+dist_var*x;
	head->data.calories=head->data.calories+cal_var*x;
	return head;
}
/*Function:       swimming
Description:    calculates the calories for swimming
Input parameters:    pointer to the head node of the linked list
Return Type:   pointer to the head node*/
struct node* swimming(struct node *head)
{    if (user.height<160)
    {
        if(user.weight<60)
        {
            cal_var=7;
        }
        else
        {
            cal_var=9;
        }
    }
    else
    {
      if(user.weight<70)
        {
            cal_var=7;
        }
        else
        {
            cal_var=9;
        }
    }
    int x;
	printf("Enter the duration of swimming in minutes \n");
    scanf("%d",&x);
	head->data.calories=head->data.calories+cal_var*x;
	return head;
}
/*Function:       threadmill
Description:    calculates the steps distance and calories for thread mill
Input parameters:    pointer to the head node of the linked list
Return Type:   pointer to the head node*/
struct node* threadmill(struct node *head)
{
    int speed,time;
    int thread_cal=2,thread_dist=16,thread_step=33;
    printf("Enter the speed\n");
    scanf("%d",&speed);
    printf("Enter the time in minutes\n");
    scanf("%d",&time);
    head->data.calories=head->data.calories+speed*time*thread_step;
    head->data.distance=head->data.distance+speed*time*thread_dist;
    head->data.steps=head->data.steps+speed*time*thread_cal;
    return head;
}
/*Function:       cycling
Description:    calculates the calories for cycling
Input parameters:calorie_intake-calorie_burnt<100    pointer to the head node of the linked list
Return Type:   pointer to the head node*/
struct node* cycling(struct node *head)
{
    if (user.height<160)
    {
        if(user.weight<60)
        {
            cal_var=11;
        }
        else
        {
            cal_var=12;
        }
    }
    else
    {
      if(user.weight<70)
        {
            cal_var=13;
        }
        else
        {
            cal_var=14;
        }
    }
    int x;
    printf("Enter the duration of cycling in minutes\n");
    scanf("%d",&x);
    head->data.calories=head->data.calories+cal_var*x;
    return head;
}
/*Function:       skipping
Description:    calculates the calories for skipping
Input parameters:    pointer to the head node of the linked list
Return Type:   pointer to the head node*/
struct node* skipping(struct node *head)
{
    if (user.height<160)
    {
        if(user.weight<60)
        {
            cal_var=9;
        }
        else
        {
            cal_var=10;
        }
    }
    else
    {
      if(user.weight<70)
        {
            cal_var=12;
        }
        else
        {
            cal_var=13;
        }
    }
    int x;
    printf("Enter the duration of skipping in minutes\n");
    scanf("%d",&x);
    head->data.calories=head->data.calories+cal_var*x;
    return head;
}
/*Function:       steps
Description:    calculates the calories for climbing steps
Input parameters:    pointer to the head node of the linked list
Return Type:   pointer to the head node*/
struct node* steps(struct node *head)
{
        int count;
        float cal=0.17;
        printf("Enter the number of steps\n");
        scanf("%d",&count);
        head->data.calories=head->data.calories+cal*count;
        head->data.steps+=count;
        return head;
}
/*Function:       stand
Description:    calculates the calories for standing
Input parameters:    pointer to the head node of the linked list
Return Type:   pointer to the head node*/
struct node* stand(struct node *head)
{
        int time;
        cal_var=2;
        printf("Enter the duration for which you were standing in minutes\n");
        scanf("%d",&time);
        head->data.calories=head->data.calories+cal_var*time;
        return head;
}
/*Function:       situps
Description:    calculates the calories for sit ups
Input parameters:    pointer to the head node of the linked list
Return Type:   pointer to the head node*/
struct node* situps(struct node *head)
{
        int count;
        float cal=0.15;
        printf("Enter the number of situps\n");
        scanf("%d",&count);
        head->data.calories=head->data.calories+cal*count;
        return head;
}
/*Function:       pushups
Description:    calculates the calories for push ups
Input parameters:    pointer to the head node of the linked list
Return Type:   pointer to the head node*/
struct node* pushups(struct node *head)
{
        int count;
        float cal=0.2;
        printf("Enter the number of pushups\n");
        scanf("%d",&count);
        head->data.calories=head->data.calories+cal*count;
        return head;
}
/*Function:       crunches
Description:    calculates the calories for crunches
Input parameters:    pointer to the head node of the linked list
Return Type:   pointer to the head node*/
struct node* crunches(struct node *head)
{
        int count;
        float cal=0.14;
        printf("Enter the number of crunches\n");
        scanf("%d",&count);
        head->data.calories=head->data.calories+cal*count;
        return head;
}
/*Function:       lunges
Description:    calculates the calories for lunges
Input parameters:    pointer to the head node of the linked list
Return Type:   pointer to the head node*/
struct node* lunges(struct node *head)
{
        int count;
        float cal=0.13;
        printf("Enter the number of lunges\n");
        scanf("%d",&count);
        head->data.calories=head->data.calories+cal*count;
        return head;
}
/*Function:       squats
Description:    calculates the calories for squats
Input parameters:    pointer to the head node of the linked list
Return Type:   pointer to the head node*/
struct node* squats(struct node *head)
{
        int count;
       float cal=0.125;
        printf("Enter the number of squats\n");
        scanf("%d",&count);
        head->data.calories=head->data.calories+cal*count;
        return head;
}
/*Function:       wall_sit
Description:    calculates the calories for wall sit
Input parameters:    pointer to the head node of the linked list
Return Type:   pointer to the head node*/
struct node* wall_sit(struct node *head)
{
        int time;
        float cal=0.13;
        printf("Enter the duration of wall sit in minutes\n");
        scanf("%d",&time);
        head->data.calories=head->data.calories+cal_var*time;
        return head;
}
/*Function:       planks
Description:    calculates the calories for planks
Input parameters:    pointer to the head node of the linked list
Return Type:   pointer to the head node*/
struct node* planks(struct node *head)
{
        int time;
        float cal=0.16;
        printf("Enter the duration of plank in minutes\n");
        scanf("%d",&time);
        head->data.calories=head->data.calories+cal*time;
        return head;
}
/*Function:       dumb_bell
Description:    calculates the calories burned by lifting dumbbells
Input parameters:    pointer to the head node of the linked list
Return Type:   pointer to the head node*/
struct node* dumb_bell(struct node *head)
{
    int weight,times;
    float weight_var;
    if (user.height<160)
    {
        if(user.weight<60)
        {
            weight_var=0.08;
        }
        else
        {
            weight_var=0.07;
        }
    }
    else
    {
      if(user.weight<70)
        {
            weight_var=0.08;
        }
        else
        {
            weight_var=0.07;
        }
    }
    printf("Enter the weight in KG\n");
    scanf("%d",&weight);
    printf("enter the number of times you lifted it\n");
    scanf("%d",&times);
    head->data.calories+=weight*times*weight_var;
    return head;

}
/*Function:       weight_lift
Description:    calculates the calories burned by weightlifting
Input parameters:    pointer to the head node of the linked list
Return Type:   pointer to the head node*/
struct node* weight_lift(struct node *head)
{
    int weight,times;
    float weight_var;
    if (user.height<160)
    {
        if(user.weight<60)
        {
            weight_var=0.04;
        }
        else
        {
            weight_var=0.035;
        }
    }
    else
    {
      if(user.weight<70)
        {
            weight_var=0.04;
        }
        else
        {
            weight_var=0.035;
        }
    }
    printf("Enter the weight you lifted in KG\n");
    scanf("%d",&weight);
    printf("enter the number of times you lifted it\n");
    scanf("%d",&times);
    head->data.calories+=weight*times*weight_var;
    return head;
}
/*Function:       resistance_menu
Description:    prints the menu for activity tracking
Input parameters:    NULL
Return Type:   NULL*/
void resistance_menu()
{
    printf("Enter the type of resistance training\n");
    printf("1:Dumbbells\n");
    printf("2.Sit ups\n");
    printf("3.push ups\n");
    printf("4.Weight lifting\n");
    printf("5.Crunches\n");
    printf("6.Lunges\n");
    printf("7.Wall sit\n");
    printf("8.Planks\n");
    printf("9.Squats\n");
    printf("10.Go back\n");
}
/*Function:      resistance
Description:    calculates the calories burned by resistance training
Input parameters:    pointer to the head node of the linked list
Return Type:   pointer to the head node*/
struct node* resistance(struct node *head)
{
    resistance_menu();
    int choice;
    printf("Enter your choice\n");
    scanf("%d",&choice);
    while(1)
    {
        switch(choice)
        {
            case 1: head=dumb_bell(head);
                    break;
            case 2: head=situps(head);
                    break;
            case 3: head=pushups(head);
                    break;
            case 4: head=weight_lift(head);
                    break;
            case 5: head=crunches(head);
                    break;
            case 6: head=lunges(head);
                    break;
            case 7: head=wall_sit(head);
                    break;
            case 8: head=planks(head);
                    break;
            case 9: head=squats(head);
                    break;
            case 10: return head;
            default: printf("Enter valid input\n");
        }
    }
}
/*Function:       fitness_menu
Description:    prints the menu for activity tracking
Input parameters:    NULL
Return Type:   NULL*/
void fitness_menu()
{
        printf("***Enter the type of activity***\n");
        printf("1:Walking\n");
        printf("2:Jogging\n");
        printf("3.Running\n");
        printf("4.Swimming\n");
        printf("5.Cycling\n");
        printf("6.Thread Mill\n");
        printf("7.Skipping rope\n");
        printf("8.Resistance training\n");
        printf("9.Climbing steps\n");
        printf("10.Standing\n");
        printf("11.Finish the entry\n");
}
/*Function:       activity_today
Description:    reads the activity for the day
Input parameters:    pointer to the head node of the linked list
Return Type:   pointer to the head node*/
struct node* activity_today(struct node *head)
{
    head=new_node(head);
    int choice;
    while (1)
    {
        fitness_menu();
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: head=walking(head);
                    break;
            case 2: head=jogging(head);
                    break;
            case 3: head=running(head);
                    break;
            case 4: head=swimming(head);
                    break;
            case 5: head=cycling(head);
                    break;
            case 6: head=threadmill(head);
                    break;
            case 7: head=skipping(head);
                    break;
            case 8: head=resistance(head);
                    break;
            case 9: head=steps(head);
                    break;
            case 10: head=stand(head);
                    break;
            case 11: return head;
            default: printf("Enter valid input\n");
        }
    }
}
/*Function:       streak
Description:    calculates the maximum streak of goal achievement
Input parameters:    pointer to the head node of the linked list
Return Type:   NULL*/
void streak(struct node *head)
{
    struct node *p;
    p=head;
    int streak=0;
    if(p==NULL)
    {
        printf("No data to display\n");
        return;
    }
    while(p!=NULL && p->data.calories>user.cal_goal)
    {
        streak++;
        p=p->next;
    }
    if(streak>max_streak)
        max_streak=streak;
    printf("Congratulations you have maintained a streak of %d days\n",streak);
    printf("Maximum streak is %d days\n",max_streak);
}
/*Function:       today_compare
Description:    compares the activity for the day with average activity
Input parameters:    pointer to the head node of the linked list
Return Type:   NULL*/
void today_compare(struct node *head)
{
    struct node *p=head;
    int i=0;
    int sum_step=0,sum_dist=0,sum_cal=0;
    int avg_step,avg_dist,avg_cal;
    while (p!=NULL)
    {
       sum_step= sum_step+p->data.steps;
       sum_dist= sum_dist+p->data.distance;
       sum_cal= sum_cal+p->data.calories;
       p=p->next;
       i++;
    }
    avg_step=sum_step/i;
    avg_dist=sum_dist/i;
    avg_cal=sum_cal/i;
    if(head->data.steps>avg_step)
    {
        printf("you walked %d steps more than average\n",(head->data.steps-avg_step));
    }
    else
    {
        printf("you walked %d steps less than average\n",(avg_step-head->data.steps));
    }
    if(head->data.distance>avg_dist)
    {
        printf("Distance is %d greater than average\n",(head->data.distance-avg_dist));
    }
    else
    {
        printf("Distance is %d lesser than average\n",(avg_dist-head->data.distance));
    }
    if(head->data.calories>avg_cal)
    {
        printf("You burned %d more calories than average\n",(head->data.calories-avg_cal));
    }
    else
    {
        printf("You burned %d lesser calories than average\n",(avg_cal-head->data.calories));
    }
}
/*Function:       distance_sum
Description:    calculates and displays the total distance covered
Input parameters:    pointer to the head node of the linked list
Return Type:   NULL*/
void distance_sum(struct node *head)
{
    float sum;
    struct node *p;
    p=head;
    if(head==NULL)
    {
        printf("No data to display\n");
        return;
    }
    while (p!=NULL)
    {
        sum=sum+p->data.distance;
        p=p->next;
    }
    sum=sum/1000;
    printf("The total distance covered is %f kilometers\n",sum);
}
/*Function:       step_sum
Description:    calculates and displays the total number of steps
Input parameters:    pointer to the head node of the linked list
Return Type:   NULL*/
void step_sum(struct node *head)
{
    int sum;
    struct node *p;
    p=head;
    if(head==NULL)
    {
        printf("No data to display\n");
        return;
    }
    while (p!=NULL)
    {
        sum=sum+p->data.steps;
        p=p->next;
    }
    printf("The total number of steps is %d\n",sum);
}
/*Function:       calorie_sum
Description:    calculates and displays the total calories burned
Input parameters:    pointer to the head node of the linked list
Return Type:   NULL*/
void calorie_sum(struct node *head)
{
    int sum;
    struct node *p;
    p=head;
    if(head==NULL)
    {
        printf("No data to display\n");
        return;
    }
    while (p!=NULL)
    {
        sum=sum+p->data.calories;
        p=p->next;
    }
    printf("The total calories burned is %d\n",sum);
}
/*Function:       goal_count
Description:    counts and displays the number of times the goal has been reached
Input parameters:    pointer to the head node of the linked list
Return Type:   NULL*/
void goal_count(struct node *head)
{
    int count=0;
    struct node *p;
    p=head;
    if(head==NULL)
    {
        printf("No data to display\n");
        return;
    }
    while (p!=NULL)
    {
        if(p->data.calories>=user.cal_goal)
        {
            count++;
        }
        p=p->next;
    }
    printf("You have reached your goal %d times\n",count);
}
/*Function:       maximum
Description:    displays the maximum steps,distance covered and calories burned
Input parameters:    pointer to the head node of the linked list
Return Type:   NULL*/
void maximum(struct node *head)
{
    int max_dist=0,max_step=0,max_cal=0;
    struct node *p;
    p=head;
    if(head==NULL)
    {
        printf("No data to display\n");
        return;
    }
    while(p!=NULL)
    {
        if(p->data.steps>max_step)
        {
            max_step=p->data.steps;
        }
        if(p->data.steps>max_dist)
        {
            max_dist=p->data.distance;
        }
        if(p->data.steps>max_cal)
        {
            max_cal=p->data.calories;
        }
        p=p->next;
    }
    printf("Maximum steps on a single day is %d\n",max_step);
    printf("Maximum distance covered on a single day is %d\n",max_dist);
    printf("Maximum calories burned on a single day is %d\n",max_cal);
}
/*Function:       minimum
Description:    displays the minimum steps,distance covered and calories burned
Input parameters:    pointer to the head node of the linked list
Return Type:   NULL*/
void minimum(struct node *head)
{
    int min_dist=0,min_step=0,min_cal=0;
    struct node *p;
    p=head;
    if(head==NULL)
    {
        printf("No data to display\n");
        return;
    }
    min_step=head->data.steps;
    min_dist=head->data.distance;
    min_cal=head->data.calories;
    while(p!=NULL)
    {
        if(p->data.steps<min_step)
        {
            min_step=p->data.steps;
        }
        if(p->data.steps<min_dist)
        {
            min_dist=p->data.distance;
        }
        if(p->data.steps<min_cal)
        {
            min_cal=p->data.calories;
        }
        p=p->next;
    }
    printf("Minimum steps on a single day is %d\n",min_step);
    printf("Minimum distance covered on a single day is %d\n",min_dist);
    printf("Minimum calories burned on a single day is %d\n",min_cal);
}
/*Function:       clear
Description:    Clears all the fitness data
Input parameters:    pointer to the head node of the linked list
Return Type:   pointer to the head node of the linked list*/
struct node* clear(struct node *head)
{
    struct node *p,*temp;
    int choice;
    p=head;
    if(head==NULL)
    {
        printf("No data to delete!!\n");
        return head;
    }
    printf("Are you sure you want to clear all the data?...\npress 1 to confirm\n");
    scanf("%d",&choice);
    if(choice!=1)
        return head;
    while(p!=NULL)
    {
        temp=p;
        p=p->next;
        free(temp);
    }
    head=NULL;
    node_count=0;
    printf("Your fitness data has been deleted\n");
    return head;
}
/*Function:       clear_days
Description:    Clears all the fitness data of last n days
Input parameters:    pointer to the head node of the linked list
Return Type:   pointer to the head node of the linked list*/
struct node* clear_days(struct node *head)
{
    int days,choice;
    struct node *p;
    if(head==NULL)
    {
        printf("No data to delete!!\n");
        return head;
    }
    printf("Enter the number of days\n");
    scanf("%d",&days);
    if(days>node_count)
    {
        printf("You don't have %d days of fitness data\n",days);
        return head;
    }
    printf("Are you sure you want to clear the data?...\npress 1 to confirm\n");
    scanf("%d",&choice);
    if(choice!=1)
        return head;
    p=head;
    for(int i=0;i<days;i++)
    {
        p->data.steps=0;
        p->data.distance=0;
        p->data.calories=0;
        p=p->next;
    }
    printf("The fitness data of last %d days has been deleted\n",days);
    return p;
}
/*Function:      day_details
Description:    Prints the fitness data of of a given days
Input parameters:    pointer to the head node of the linked list
Return Type:  NULL*/
void day_details(struct node *head)
{
    int day,x;
    struct node *p;
    p=head;
    if(head==NULL)
    {
        printf("No data to display\n");
        return;
    }
    printf("Enter the day number\n");
    scanf("%d",&day);
    x=node_count-day;
    if(x<0)
    {
        printf("No details found on day %d\n",day);
        return;
    }
    for(int i=0;i<x;i++)
    {
        p=p->next;
    }
    printf("Your activity on day %d is\n",day);
    printf("Steps:%d\n",p->data.steps);
    printf("Distance:%d\n",p->data.distance);
    printf("calories burned:%d\n",p->data.calories);
}
/*Function:       delete_day_details
Description:    Clears all the fitness data of a given day
Input parameters:    pointer to the head node of the linked list
Return Type:   pointer to the head node of the linked list*/
struct node* delete_day_details(struct node *head)
{
    int day,x;
    struct node *p;
    p=head;
    if(head==NULL)
    {
        printf("No data present\n");
        return head;
    }
    printf("Enter the day number\n");
    scanf("%d",&day);
    x=node_count-day;
    if(x<0)
    {
        printf("No details found on day %d",day);
        return head;
    }
    if(x==0)
    {
        head->data.steps=0;
        head->data.distance=0;
        head->data.calories=0;
        printf("The activity details of day %d has been cleared\n",day);
        return head;
    }
    for(int i=0;i<x;i++)
    {
        p=p->next;
    }
    p->data.steps=0;
	p->data.distance=0;
	p->data.calories=0;
    printf("The activity details of day %d has been cleared\n",day);
    return head;
}
/*Function:       delete_today
Description:    Clears all the fitness data of the day
Input parameters:    pointer to the head node of the linked list
Return Type:   pointer to the head node of the linked list*/
struct node* delete_today(struct node *head)
{
    struct node *temp;
    temp=head;
    head=head->next;
    free(temp);
    printf("Todays activity details have been deleted\n");
    return head;
}
/*Function:       fit_menu
Description:    prints the menu for fitness tracking
Input parameters:    NULL
Return Type:   NULL*/
void fit_menu()
{
    printf("Welcome to the fitness tracker :)\n");
    printf("*****Menu*****\n");
    printf("1.Feed todays activity details\n");
    printf("2.See todays activity details\n");
    printf("3.See average activity details of this week\n");
    printf("4.See overall average activity details\n");
    printf("5.See your streak\n");
    printf("6:See the total distance covered\n");
    printf("7.See the total number of steps\n");
    printf("8.See the total calories burned\n");
    printf("9.See the number of times you have reached your goal\n");
    printf("10.See the maximum steps,distance and calories burned\n");
    printf("11.See the minimum steps,distance and calories burned\n");
    printf("12.Clear the fitness data of the last n days\n");
    printf("13.Clear all the fitness data\n");
    printf("14.See the activity details of a particular day\n");
    printf("15.Delete the activity details of a particular day\n");
    printf("16.Delete todays fitness data\n");
    printf("17.Clear all data\n");
    printf("18.Exit\n");
}
/*Function:       fitness-tracking
Description:    function for fitness tracking
Input parameters:    NULL
Return Type:   NULL*/
void fitness_tracking()
{
    int choice;
    while (1)
    {
    fit_menu();
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: head=activity_today(head);
                break;
        case 2: print_today(head);
                if(head!=NULL)
                today_compare(head);
                break;
        case 3: average_week(head);
                break;
        case 4: average(head);
                break;
        case 5: streak(head);
                break;
        case 6: distance_sum(head);
                break;
        case 7: step_sum(head);
                break;
        case 8: calorie_sum(head);
                break;
        case 9: goal_count(head);
                break;
        case 10: maximum(head);
                 break;
        case 11: minimum(head);
                 break;
        case 12: head=clear_days(head);
                 break;
        case 13: head=clear(head);
                 break;
        case 14: day_details(head);
                 break;
        case 15: head=delete_day_details(head);
                 break;
        case 16: head=delete_today(head);
                 break;
        case 17: clear_user_data();
                 exit(0);
        case 18: user_write();
                 write_list(head);
                 exit;
        case 999: easter_egg();
                  break;
        default: printf("Invalid input\n");
                 printf("Please select between 1 and 9\n");
    }
}
return;
}
/*Function:       menu
Description:    prints the menu
Input parameters:    NULL
Return Type:   NULL*/
void menu()
{
    printf("**********Welcome to your activity and health tracker**********\n");
    printf("1.Fitness training\n");
    printf("2.Calorie chart\n");
    printf("3-Calculate BMI,BMR,WHR\n");
    printf("4-Sleep Monitoring\n");
    printf("5-Remainders\n");
    printf("6-Period Tracking\n");
    printf("7.First Aid\n");
    printf("8.Hubli map Itinerary\n");
    printf("9.Exit\n");
}
/*Function:     first_aid_reckoner
Description:    function for information regarding first aid
Input parameters:    NULL
Return Type:   NULL*/
void first_aid_reckoner()
{
    int observation;
    char text[1000];
    printf("\n\n************************Welcome to the First Aid Directory************************\n\n");
    printf("\t\tThis directory is a tool to refresh your memory on what to do in case of a medical emergency that migh be faced. Always good to be prepared.\n");
    printf("Please do not take this literally. And do not depend on this, (or google) to understand what to do in such a situation.\n");
    printf("\t\t ACT! Before it is too late! First Aid is damage control.\n");
    printf("But today, let us assume you are hurt. You may begin.\n");
    printf("Answer this simulator with either a 0 for no or 1 for yes.\n");
    printf("Are you bruised?\t");
    scanf("%d",&observation);
    if(observation==1)
    {
        printf("Is it a deep cut?\n");
        scanf("%d",&observation);
        if(observation==0)
        {
            printf("Clean the wound under running water. Apply a disinfectant. Dress in a cotton swab.\n");
            printf("\n\n\nThat was a great drill! Do come back in case you have forgotten any of these. It is important to know. It is more important to help!\n");
        }
        else
        {
            printf("Don't panic. Hold the part with the cut tightly and at a height from the ground to stop bleeding.\n");
            printf("Now clean the wound under running water. Apply a disinfectant. Dress in a cotton swab.\n");
            printf("\n\n\nThat was a great drill! Do come back in case you have forgotten any of these. It is important to know. It is more important to help!\n");
        }
    }
    else
    {
        printf("Are you sprained?");
        scanf("%d",&observation);
        if(observation==1)
        {
            printf("Can you move at all?\n");
            scanf("%d",&observation);
            if(observation==1)
            {
                printf("Stretching around much? Be careful!\n");
                printf("Slowly try to get mobile. A crepe bandage might help to support the joint. Spray some pain relief.\n");
                printf("\n\n\nThat was a great drill! Do come back in case you have forgotten any of these. It is important to know. It is more important to help!\n");
            }
            else
            {
                printf("Carefully immobilise the part. It might be a fracture. Please consult an orthopaedician.\n");
                printf("\n\n\nThat was a great drill! Do come back in case you have forgotten any of these. It is important to know. It is more important to help!\n");
            }
        }
        else
        {
            printf("Encountered a burn?\n");
            scanf("%d",&observation);
            if(observation==1)
            {
                printf("Was it caused by water or steam?\n");
                scanf("%d",&observation);
                if(observation==1)
                {
                    printf("Submerge the part in cold water. Use an ice pack until the irritation comes down.\n");
                    printf("Apply an antiseptic cream\n");
                    printf("In case of severe burns or in sensitive parts of the body like the eye, consult the concerned specialist.\n");
                    printf("\n\n\nThat was a great drill! Do come back in case you have forgotten any of these. It is important to know. It is more important to help!\n");
                }
                else
                {
                    printf("Is it an oil burn?\n");
                    scanf("%d",&observation);
                    if(observation==1)
                    {
                        printf("Do not apply butter or other oil based substances that might work for steam burns.\n");
                        printf("Run the burn under cold water and put a cold pack.\n");
                        printf("Do not poke or pop the blister. It might scar\n");
                        printf("\n\n\nThat was a great drill! Do come back in case you have forgotten any of these. It is important to know. It is more important to help!\n");
                    }
                    else
                    {
                        printf("For any other burns, chemical or electric immediately consult a doctor. Do not wash with water. \n");
                        printf("Use sterile towels to hold blisters and call for help immediately.\n");
                        printf("\n\n\nThat was a great drill! Do come back in case you have forgotten any of these. It is important to know. It is more important to help!\n");
                    }
                }
            }
            else
            {
                printf("Is it an animal or an insect bite?\n");
                scanf("%d",&observation);
                if(observation==1)
                {
                    printf("Wash the wound gently with soap and water.\n");
                    printf("Apply pressure with a clean towel or gauze to the injured area to stop any bleeding.\n");
                    printf("Apply antibiotic ointment, such as bacitracin, to the area twice a day until it heals.Apply a sterile bandage to the wound.\n");
                    printf("\n\n\nThat was a great drill! Do come back in case you have forgotten any of these. It is important to know. It is more important to help!\n");
                }
                else
                {
                    printf("Is it a sting?\n");
                    scanf("%d",&observation);
                    if(observation==1)
                    {
                       printf("Use a cloth dampened with cold water or filled with ice. \n");
                       printf("This helps reduce pain and swelling. If the injury is on an arm or leg, elevate it.\n");
                       printf("\n\n\nThat was a great drill! Do come back in case you have forgotten any of these. It is important to know. It is more important to help!\n");
                    }
                    else
                    {
                        printf("Do you feel stressed?");
                        scanf("%d",&observation);
                        if(observation==1)
                        {
                            printf("Look. I know you are sad. But that doesn't mean you need first aid.\n");
                            printf("It is alright to score less in minor 2. You have learnt a LOT!\n");
                            printf("But do feel free to write how you feel. Remember, there are people to help you. Everywhere. All you need to do is see.\n");
                            scanf("%s",text);
                            KMP(text);
                        }
                        else
                        {
                            printf("Then why are you here man? It was a tiring drill! Mostly for you... That bored? I feel sorry for your existance.\n");
                            printf("Pretty sure you are hurt now. Go seek help.\n");
                            scanf("%s",text);
                            KMP(text);
                        }
                    }
                }
            }
        }
    }
}
/*Function:     hubli_map
Description:    function for hubli map ititnerary
Input parameters:    NULL
Return Type:   NULL*/
void hubli_map()
{
    int source,destination;
    float distance;
    char start[30];
    char end[30];
    float G[MAX][MAX]={{0,2.3,4.5,3.2,4.7,3.9,2.6,4.9,3.7,4.2,2.6,4.4,4.1,3.4,2.9,7.5},{2.3,0,99,99,99,2,99,99,99,99,99,2.8,1.8,99,99,99},{4.5,99,0,99,99,99,99,99,99,5.6,99,5.5,5.5,99,99,99},{32,99,99,0,99,3,99,99,3.1,99,6.1,2.1,1.9,99,1.4,6.3},{4.7,99,99,99,0,1.2,99,99,99,5.2,99,99,4.4,99,99,99},{3.9,2,99,3,1.2,0,99,99,99,4.0,4.7,4.1,99,3.1,3.4,4.1},{2.6,99,99,99,99,99,0,99,99,99,99,7.5,6.7,99,7.3,99},{4.9,99,99,99,99,99,99,0,99,99,99,2.7,99,99,99,99},{3.7,99,99,3.1,99,99,99,99,0,0.6,3.1,99,0.4,99,99,99},{4.2,99,5.6,99,5.2,4.0,99,99,0.6,0,99,1.1,0.7,99,1.1,8.1},{2.6,99,99,6.1,99,4.7,99,99,3.1,99,0,99,3.4,99,99,99},{4.4,2.8,5,5,2.1,99,4.1,7.5,2.7,99,1.1,99,0,4.4,99,2.1,7.4},{4.1,1.8,5.5,1.9,4.4,99,6.7,99,0.4,0.7,3.4,4.4,0,99,99,99},{3.4,99,99,99,99,3.1,99,99,99,99,99,99,99,0,6.4,99},{2.9,99,99,1.4,99,3.4,7.3,99,99,1.1,99,2.1,99,6.4,0,6.6},{7.5,99,99,6.3,99,4.1,99,99,99,8.1,99,7.4,99,99,6.6,0}}; //Enter the adjacency matrix of the map here
    printf("This feature is still under beta testing so it works for only a selective list of places in Hubli\n");
    //choosing the source
    printf("Enter the starting point:\n");
    printf("1.KLE Technological University\n");
    printf("2.Indira Gandhi Glass house\n");
    printf("3.Nrupatunga Betta\n");
    printf("4.Old bus-stand\n");
    printf("5.Urban-Oasis Mall\n");
    printf("6.New bus stand");
    printf("7.Unkal Lake\n");
    printf("8.Sidharoodha Matha\n");
    printf("9.U mall\n");
    printf("10.CBT(Central Bus Terminal)\n");
    printf("11.Chinmaya Vidyalaya(CBSE)\n");
    printf("12.Reliance Market\n");
    printf("13.Sapna Book house\n");
    printf("14.Nehru Stadium\n");
    printf("15.Railway Station\n");
    printf("16.Airport\n");
    scanf("%d",&source);
    switch(source)
    {
        case 1: strcpy(start,"KLE Technological University");
                break;
        case 2: strcpy(start,"Indira Gandhi Glass house");
                break;
        case 3: strcpy(start,"Nrupatunga Betta");
                break;
        case 4: strcpy(start,"Old bus-stand");
                break;
        case 5: strcpy(start,"Urban-Oasis Mall");
                break;
        case 6: strcpy(start,"New bus stand");
                break;
        case 7: strcpy(start,"Unkal Lake");
                break;
        case 8: strcpy(start,"Sidharoodha Matha");
                break;
        case 9: strcpy(start,"U mall");
                break;
        case 10: strcpy(start,"CBT(Central Bus Terminal)");
                break;
        case 11: strcpy(start,"Chinmaya Vidyalaya(CBSE)");
                break;
        case 12: strcpy(start,"Reliance Market");
                break;
        case 13: strcpy(start,"Sapna Book house");
                break;
        case 14: strcpy(start,"Nehru Stadium");
                break;
        case 15: strcpy(start,"Railway Station");
                break;
        case 16: strcpy(start,"Airport");
                break;
    }
    // choosing the destination
    printf("\n\nEnter the destination:\n");
    printf("1.KLE Technological University\n");
    printf("2.Indira Gandhi Glass house\n");
    printf("3.Nrupatunga Betta\n");
    printf("4.OLd bus-stand\n");
    printf("5.Urban-Oasis Mall\n");
    printf("6.New bus stand");
    printf("7.Unkal Lake\n");
    printf("8.Sidharoodha Matha\n");
    printf("9.U mall\n");
    printf("10.CBT(Central Bus Terminal)\n");
    printf("11.Chinmaya Vidyalaya(CBSE)\n");
    printf("12.Reliance Market\n");
    printf("13.Sapna Book house\n");
    printf("14.Nehru Stadium\n");
    printf("15.Railway Station\n");
    printf("16.Airport\n");
    scanf("%d",&destination);
    switch(destination)
    {
        case 1: strcpy(end,"KLE Technological University");
                break;
        case 2: strcpy(end,"Indira Gandhi Glass house");
                break;
        case 3: strcpy(end,"Nrupatunga Betta");
                break;
        case 4: strcpy(end,"Old bus-stand");
                break;
        case 5: strcpy(end,"Urban-Oasis Mall");
                break;
        case 6: strcpy(end,"New bus stand");
                break;
        case 7: strcpy(end,"Unkal Lake");
                break;
        case 8: strcpy(end,"Sidharoodha Matha");
                break;
        case 9: strcpy(end,"U mall");
                break;
        case 10: strcpy(end,"CBT(Central Bus Terminal)");
                break;
        case 11: strcpy(end,"Chinmaya Vidyalaya(CBSE)");
                break;
        case 12: strcpy(end,"Reliance Market");
                break;
        case 13: strcpy(end,"Sapna Book house");
                break;
        case 14: strcpy(end,"Nehru Stadium");
                break;
        case 15: strcpy(start,"Railway Station");
                break;
        case 16: strcpy(start,"Airport");
                break;
    }
    distance=dijkstra(G,16,source-1,destination-1);
    printf("The minimum distance between %s and %s is %f KM\n",start,end,distance);
    return;
}
int main()
{
    head=NULL;
    user_read();
    if(user_flag!=0)
        head=read_list(head);
    if(user_flag==0)
        get_user_data();
    int choice;
    while(1)
    {
        menu();
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: fitness_tracking();
                    break;
            case 2: calorie_chart();
                    break;
            case 3: calc_ratios();
                    break;
            case 4: sleep_monitoring();
                    break;
            case 5: set_remainders();
                    break;
            case 6: Period_tracking();
                    break;
            case 7: first_aid_reckoner();
                    break;
            case 8: hubli_map();
                    break;
            case 9: printf("|\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n");
    printf("| |||||||||||||||||||||||||||||\n");
    printf("| |    ||,,,,.  |  .,,,,||       __\t\n");
    printf("| |    .d8888b.   .d8888b.      (    )          ___\t\n");
    printf("| |   o8'  o '8o o8'o   `8o     |    |         (     )\t\n");
    printf("||||  o8.    .8o o8.    .8o     |    | ___ |     |\t\n");
    printf("|      `Y8888P'   `Y8888P'      |    |(       )|     |\t\n");
    printf("|     ,||''|| |   | ||''||,     |    ||       ||     |\t\n");
    printf("|    ,||   ||, | | .||   ||,    |    ||       ||     |\t\n");
    printf("|    ||     ||  `  ||     ||    |    ||       ||     |\t\n");
    printf("|   ,||     '||   ||'     ||,   |    ||       ||     | _\t\n");
    printf("|   ||      '||   ||'      ||   |    ||       ||     || |\t\n");
    printf("|   ||       |;   ;|       ||   |    ||       ||     ||  |\t\n");
    printf("|   ||      ,|     |,      ||   |    ||       ||     ||   |\t\n");
    printf("|   ||,    ,||     ||,    ,||   |    ||       ||     ||   |\t\n");
    printf("|    ||,  ,|||     |||,  ,||    |    ||       ||     ||   |\t\n");
    printf("|    '||,,||||,...,||||,,||     |    ||       ||     ||_|\t\n");
    printf("|      `|||... ||| ...|||'      (_)(__)(__)|_|\t\n");
    printf("||~~~WWWW~~WWWW~~~~~~~~~~~~|\t\n");
    printf("|`~~~~3$F~#$F~~~~~~~~~~~~~~'\t\n");
    printf("|           @$....'$B\t\n");
    printf("|          d$$$$$$$$$b\t\n");
    printf("|          `````\t\n");
                    printf("~*~*~*~May the force be with you~*~*~*~;)");
                    user_write();
                    write_list(head);
                    return(0);
        }
    }
}
