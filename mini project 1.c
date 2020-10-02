#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
void leaderboard(float s,float a);
struct player
{
    float speed;
    char name[20];
    float accu;
};
int main()
{
    system("color 71");
    char ch,c;
    char a[2000];
    int k=0,count=0,i=0,b,wrong=0,flag=0;
    float ac;
    time_t start,end;
    FILE *p;
    p=fopen("filecode1.txt","r");
    while((ch=getc(p))!=EOF)
    {
        putchar(ch);
    }
    fclose(p);
    printf("\n\n");

    p=fopen("filecode1.txt","r");

    while((ch=getc(p))!=EOF)
    {
        label:
        b=0;
        c=getch();
        if(k==0)
        {
            start=time(NULL);
        }
        if(c==ch)
        {
            //Beep(600,100);
             putchar(c);
             if(c==' ')
             {
                count++;
             }
             flag++;

        }
        else if(c=='\r'&&ch=='\n')
        {
            //Beep(600,100);
             putchar(c);
              printf("\n");
              flag++;

        }

        else
        {
            b=1;
            wrong++;
            //Beep(600,100);
        }
        end=time(NULL);
        if(difftime(end,start)>=6)
        {
            printf("\a");
            printf("\n\n\t\t!!!!Time over!!!!\n\n");
            break;
        }
         if(b==1)
        {
            goto label;
        }
        k++;

    }

     float speed;
     //speed=count*2;
     speed=(float)flag/5;
     printf("\n\t\tYour typing speed");
     printf("\n\n\t\t***** %.2f WPM ******\n\n",speed);
     fclose(p);
     ac=(float)flag/(flag+wrong)*100;
     printf("\n\t\tYour accuracy\n");
     printf("\n\t\t----%.1f percentage----",ac);



getch();
getch();
getch();
getch();
getch();


leaderboard(speed,ac);


}
void leaderboard(float s,float a)
{
    struct player p[200],temp;
    FILE *fp;
    char c;
    int l=0,i,j;
    fp=fopen("leaderboard.txt","a");
    printf("\nEnter your name\n");
    while((c=getchar())!='\n')
    {
        putc(c,fp);
    }

   fprintf(fp," %.1f %.1f\n",s,a);
    fclose(fp);
    printf("\n\t\tleaderboard :\n\n");
    printf("\n Name\t\t\t\t\tSpeed\tAccuracy\n\n");

    fp=fopen("leaderboard.txt","r");
    while((c=getc(fp))!=EOF)
    {
        if(c=='\n')
        {
            l++;
        }
    }
    fclose(fp);

    fp=fopen("leaderboard.txt","r");
    for(i=0;i<l;i++)
    {
        fscanf(fp,"%s %f %f",p[i].name,&p[i].speed,&p[i].accu);
        //fseek(fp,1,1);
    }
    fclose(fp);

    for(i=0;i<l;i++)
    {
        for(j=i;j<l;j++)
        {
             if(p[i].speed<p[j].speed)
             {
                 temp=p[i];
                 p[i]=p[j];
                 p[j]=temp;
             }
        }
    }

     for(i=0;i<l;i++)
    {
        printf(" %d. %s \t\t\t\t%.1f  \t %.1f\n",i+1,p[i].name,p[i].speed,p[i].accu);
    }


}

