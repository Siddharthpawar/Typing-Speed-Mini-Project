#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

COORD coord = {0, 0};
// int totalLines = 0;

void userRegistration();
void userLogin();
void adminLogin();
void mainLoadingScreen();
void mainMenu(char UserName[]);
void adminMainMenu();
void adminUserView();
void homePage();
void Typingspeed(char UserName[]);
void Add_To_Typing_Leaderboard(float s,float a,char UserName[]);
void Display_Typing_Leaderboard();
void Readingspeed(char UserName[]);
double Readingcomprehension(int randomNumber);
void Add_To_Reading_Leaderboard(double reading_speed, double reading_comprehension, char UserName[]);
void Display_Reading_Leaderboard();
void viewLeaderBoards();
void Delete_User(char  filename[],char userName[]);
void Delete_User_credentials(char  filename[],char userName[]);
void clear_Leaderboard(char filename[]);
void compete();
void typingCompetition(int typing_duration,float *speed , float *accuracy);
void readingCompetition(float *speed , float *accuracy);
void games();
void gameMenu(char userName[]);
void game1(char userName[], int level, char singleOrNot[]);
void game2(char userName[], int level, char singleOrNot[]);
void ranArray(int randomisedArray[],int n);
int is_Registered_user(char name[], char filename[]);
void display_Feedback(char name[], double present_Typing_speed, double present_Typing_accuracy, char filename[]);
void arrow(int rel,int arrowPosition);
int levelSelector();

struct user
{
    char userName[20];
    char userPassword[20];
    int userAge;
    char gender[8];
    char gameWord[15];
};

struct player
{
    float typing_speed;
    char name[20];
    float typing_accuracy;
    float reading_speed;
    float reading_comprehension;
    int gameScore;
};

void gotoxy(int x, int y)
{
    coord.X = x; coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
    system("color 71");
    mainLoadingScreen();
    homePage();
    return 0;
}

void mainLoadingScreen()
{
    system("cls");

    gotoxy(45,10);printf("************************");
    gotoxy(45,11);printf("*\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB*");
    gotoxy(45,12);printf("*\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB *");
    gotoxy(45,13);printf("*\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB  *");
    gotoxy(45,14);printf("*\xDB\xDB\xDB        \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB   *");
    gotoxy(45,15);printf("*\xDB\xDB\xDB        \xDB\xDB\xDB\xDB\xDB\xDB\xDB    *");
    gotoxy(45,16);printf("*\xDB\xDB\xDB\xDB\xDB\xDB  \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB     *");
    gotoxy(45,17);printf("*\xDB\xDB\xDB\xDB\xDB\xDB  \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB      *");
    gotoxy(45,18);printf("*\xDB\xDB\xDB\xDB\xDB\xDB  \xDB\xDB\xDB\xDB\xDB\xDB\xDB       *");
    gotoxy(45,19);printf("*\xDB\xDB\xDB\xDB\xDB\xDB  \xDB\xDB\xDB\xDB\xDB\xDB        *");
    gotoxy(45,20);printf("*\xDB\xDB\xDB\xDB\xDB\xDB  \xDB\xDB\xDB\xDB\xDB         *");
    gotoxy(45,21);printf("*\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB          *");
    gotoxy(45,22);printf("*\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB           *");
    gotoxy(45,23);printf("*\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB  \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB  *");
    gotoxy(45,24);printf("*\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB   \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB  *");
    gotoxy(45,25);printf("*\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB       \xDB\xDB     *");
    gotoxy(45,26);printf("*\xDB\xDB\xDB\xDB\xDB\xDB\xDB        \xDB\xDB     *");
    gotoxy(45,27);printf("*\xDB\xDB\xDB\xDB\xDB\xDB         \xDB\xDB     *");
    gotoxy(45,28);printf("*\xDB\xDB\xDB\xDB\xDB          \xDB\xDB     *");
    gotoxy(45,29);printf("*\xDB\xDB\xDB\xDB           \xDB\xDB     *");
    gotoxy(45,30);printf("*\xDB\xDB\xDB                   *");
    gotoxy(45,31);printf("*\xDB\xDB                    *");
    gotoxy(45,32);printf("*\xDB                     *");
    gotoxy(45,33);printf("************************");
    char title[30] ="\n T Y P I N G  T U T O R";
    int x_count  = 45;
    for(int i=0 ; i<strlen(title) ; i++)
    {
        gotoxy(x_count,35);
        if(i == 0)
        {
            printf("%c",title[i]);
            i++;
        }
        printf("%c",title[i]);
        Sleep(200);
        x_count++;
    }
    return;
}

void homePage()
{
	system("cls");
	int position = 1;
    char exitPermission;        //for knowing if user wants to exit current page
	int keyPressed = 0;

    while(keyPressed != 13)
    {
            system("cls");

            gotoxy(30,4);
            printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
            gotoxy(30,5);
            printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
            gotoxy(30,6);
            printf("                                                                       ");
            gotoxy(30,7);
            printf("                        HOME                         ");
            gotoxy(30,8);
            printf("                                                                       ");
            gotoxy(30,9);
            printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
            gotoxy(30,10);
            printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");

            gotoxy(30,13);
            printf("-------------------------------------------------------");

            //arrow function prints arrow depending on the up/down key pressed by user
            gotoxy(30,15);
            printf("\t\t"); arrow(1,position); printf("REGISTER");
            gotoxy(30,16);
            printf("\t\t");  arrow(2,position); printf("LOGIN");
            gotoxy(30,17);
            printf("\t\t"); arrow(3,position); printf("ADMIN LOGIN");
            gotoxy(30,18);
            printf("\t\t"); arrow(4,position); printf("GAMES");
            gotoxy(30,19);
            printf("\t\t"); arrow(5,position); printf("EXIT");

            gotoxy(30,21);
            printf("-------------------------------------------------------");

            gotoxy(30,24);
            printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
            gotoxy(30,25);
            printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
            gotoxy(30,26);
            printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
            gotoxy(30,27);
            printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
            keyPressed = getch();


            if(keyPressed == 80 && position != 5)           //increment value of position if down arrow key is pressed
                position++;
            else if(keyPressed == 72 && position != 1)      //decrement value of position if up arrow key is pressed
                position--;
            else                                                                   //no change in value of position if any other key rather than up/down key is pressed
                position = position;
    }

    switch (position)
    {
            case 1: userRegistration();
                        break;
            case 2: userLogin();
                        break;
            case 3: adminLogin();
                        break;
            case 4: games();
                        break;
            case 5:
                            gotoxy(35,29);printf("You want to Exit?(y/n)");
                            exitPermission = getch();
                            if(exitPermission == 'y')
                            {
                                gotoxy(35,31);printf("Exiting...");
                                Sleep(500);
                                exit(0);
                            }
                            else homePage();

                        break;
            default: gotoxy(35,29);printf("Invalid!");
                        break;
    }
}

void mainMenu(char UserName[])
{
	system("cls");
	int position = 1;
	int keyPressed = 0;
    char exitPermission;
	while(keyPressed != 13)
	{
		system("cls");

        gotoxy(30,4);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
		gotoxy(30,5);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
		gotoxy(30,6);
        printf("                                                                       ");
		gotoxy(30,7);
        printf("                    TYPING TUTOR                          ");
		gotoxy(30,8);
        printf("                                                                       ");
		gotoxy(30,9);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
		gotoxy(30,10);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");

		gotoxy(30,13);
        printf("-------------------------------------------------------");

		gotoxy(30,15);
        printf("\t\t"); arrow(1,position); printf("TYPING");
		gotoxy(30,16);
        printf("\t\t");  arrow(2,position); printf("READING & COMPREHENSION");
		gotoxy(30,17);
        printf("\t\t"); arrow(3,position); printf("LEADER BOARD");
        gotoxy(30,18);
        printf("\t\t"); arrow(4,position); printf("EXIT");

		gotoxy(30,20);
        printf("-------------------------------------------------------");

		gotoxy(30,23);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
		gotoxy(30,24);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
        gotoxy(30,25);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
		gotoxy(30,26);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
		keyPressed = getch();

		if(keyPressed == 80 && position != 4)
			position++;
		else if(keyPressed == 72 && position != 1)
			position--;
		else
			position = position;
	}
    switch (position)
    {
                case 1: Typingspeed(UserName);
                            break;
                case 2: Readingspeed(UserName);
                            break;
                case 3: viewLeaderBoards(UserName);
                             break;
                case 4: gotoxy(30,31);printf("You want to log out?(y/n)");
                            exitPermission = getch();
                            if(exitPermission == 'y')homePage();
                            else mainMenu(UserName);
                            break;
                default: gotoxy(30,31);printf("Invalid!");
                            break;
    }
}

void adminMainMenu()
{
	system("cls");
	int position = 1;
    char exitPermission;
	int keyPressed = 0;
	while(keyPressed != 13)
	{
		system("cls");

        gotoxy(30,4);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
		gotoxy(30,5);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
		gotoxy(30,6);
        printf("                                                                       ");
		gotoxy(30,7);
        printf("                       A D M I N                         ");
		gotoxy(30,8);
        printf("                                                                       ");
		gotoxy(30,9);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
		gotoxy(30,10);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");

		gotoxy(30,13);
        printf("-------------------------------------------------------");

		gotoxy(30,15);
        printf("\t\t"); arrow(1,position); printf("LEADER BOARD");
		gotoxy(30,16);
        printf("\t\t");  arrow(2,position); printf("DELETE LEADERBOARD");
		gotoxy(30,17);
        printf("\t\t"); arrow(3,position); printf("DELETE USER");
        gotoxy(30,18);
        printf("\t\t"); arrow(4,position); printf("USER'S CREDENTIALS");
		gotoxy(30,19);
        printf("\t\t"); arrow(5,position); printf("EXIT");

		gotoxy(30,20);
        printf("-------------------------------------------------------");

		gotoxy(30,24);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
		gotoxy(30,25);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
        gotoxy(30,26);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
		gotoxy(30,27);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
		keyPressed = getch();

		if(keyPressed == 80 && position != 5)
			position++;
		else if(keyPressed == 72 && position != 1)
			position--;
		else
			position = position;
	}

    char userName[30];
    switch (position)
     {
                case 1: viewLeaderBoards("admin");
                             break;
                case 2: printf("\n\n\t\t\t\tWhich Leader Board you want to delete?\n\t\t\t\t\t1.Typing Leader Board\n\t\t\t\t\t2. Reading Leader Board\n\t\t\t\t\t3.All\n");
                             int choice;
                             printf("\n\t\t\t\t\t\t");
                             scanf("%d",&choice);
                             switch(choice)
                             {
                                case 1: clear_Leaderboard("Typing_Leaderboard.txt");
                                            printf("\n\n\t\tLeaderboard successfully deleted");
                                            Sleep(1000);
                                            break;
                                case 2: clear_Leaderboard("Reading_Leaderboard.txt");
                                            printf("\n\n\t\tLeaderboard successfully deleted");
                                            Sleep(1000);
                                            break;
                                case 3: clear_Leaderboard("Typing_Leaderboard.txt");
                                            clear_Leaderboard("Reading_Leaderboard.txt");
                                            printf("\n\n\t\tLeaderboards successfully deleted");
                                            Sleep(1000);
                                            break;
                                default:printf("\t\t\t\t\tInvalid entry");
                                            Sleep(1000);
                                            adminMainMenu();
                                            break;
                             }
                             break;
                case 3: printf("\n\t\t\t\t\tEnter a valid UserName:");
                            fflush(stdin);
                            scanf("%s",userName);
                            Delete_User_credentials("usernames.txt",userName);
                            Delete_User("Typing_Leaderboard.txt",userName);
                            Delete_User("Reading_Leaderboard.txt",userName);
                            Sleep(2000);
                            adminMainMenu("admin");
                            break;

                case 4: adminUserView();
                            break;
               case 5:  gotoxy(30,31);printf("You want to log out?(y/n)");
                            exitPermission = getch();
                            if(exitPermission == 'y')homePage();
                            else adminMainMenu();
                            break;
                default: gotoxy(30,31);printf("Invalid!");
                            Sleep(1000);
                            adminMainMenu();
                            break;
     }
}

void arrow(int rel,int arrowPosition)           //just prints arrow on menu pages when parameters are equal
{
	if(rel == arrowPosition)
	{
		printf(" ---> ");
	}
	else
	{
		printf("      ");
	}
}

void userRegistration()
{
    system("cls");
    gotoxy(35,6);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\xB2");gotoxy(80,6);printf("\xB2\n");
    gotoxy(35,7);
    printf("\xB2");gotoxy(80,7);printf("\xB2\n");
    gotoxy(35,8);
    printf("\xB2");gotoxy(80,8);printf("\xB2\n");
    gotoxy(35,9);
    printf("\xB2");gotoxy(80,9);printf("\xB2\n");
    gotoxy(35,10);
    printf("\xB2");gotoxy(80,10);printf("\xB2\n");
    gotoxy(35,11);
    printf("\xB2");gotoxy(80,11);printf("\xB2\n");
    gotoxy(35,12);
    printf("\xB2");gotoxy(80,12);printf("\xB2\n");
    gotoxy(35,13);
    printf("\xB2");gotoxy(80,13);printf("\xB2\n");
    gotoxy(35,14);
    printf("\xB2");gotoxy(80,14);printf("\xB2\n");
    gotoxy(35,15);
    printf("\xB2");gotoxy(80,15);printf("\xB2\n");
    gotoxy(35,16);
    printf("\xB2");gotoxy(80,16);printf("\xB2\n");
     gotoxy(35,17);
    printf("\xB2");gotoxy(80,17);printf("\xB2\n");
    gotoxy(35,18);
       printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    int notEqual = 0,totalLines = 0;
    struct user u[200];
    char UserName[30],UserPassword[30],userGenderString[10],UserAge[3],UserGender[1];
    char male[5] = {'M','a','l','e','\0'};
    char female[7] = {'F','e','m','a','l','e','\0'};
    char others[7] = {'O','t','h','e','r','s','\0'};

    gotoxy(37,8);printf("Enter a UserName: ");
    gotoxy(55,8);scanf("%s",UserName);

    FILE *flines;
    flines = fopen("usernames.txt","r");

    char ch;
    while((ch = getc(flines)) != EOF)
    {
        if(ch == '\n')
        {
            totalLines++;
        }
    }

    FILE *fr;
    fr = fopen("usernames.txt","r");

    for(int i=0 ; i<totalLines ; i++)
    {
        fscanf(fr, "%s %s %d %s",u[i].userName,u[i].userPassword,&u[i].userAge,u[i].gender);
        if(strcmp(u[i].userName,UserName) != 0)             //checking if the username entered already exits in the file
        {
            notEqual++;
        }
        else
        {
            break;
        }
    }

    if(notEqual != totalLines)          //if username is already taken, system prompts to try some other usernames
    {
        gotoxy(35,20);printf("UserName is already taken, try something different");
        Sleep(2000);
        userRegistration();
    }
    fclose(fr);

    password:
    gotoxy(37,10);printf("Enter password:");
    gotoxy(55,10);scanf("%s",UserPassword);

    if(strlen(UserPassword) < 8)            //checking if password is less than 8 characters
    {
        gotoxy(35,20);printf("Password must contain atleast 8 characters");
        gotoxy(55,10);printf("          ");
        Sleep(2000);
        goto password;
    }
    gotoxy(35,20);printf("                                                                            ");
    userage:
    gotoxy(37,12);printf("Enter Age:");
    gotoxy(55,12);printf("          ");
    gotoxy(55,12);scanf("%s",UserAge);
    int userAge;
    if(atoi(UserAge) && (atoi(UserAge) >= 1 && atoi(UserAge) <151))         //checking if age is in permisible range
    {
        userAge = atoi(UserAge);
    }
    else
    {
        gotoxy(30,20);printf("Age must be in the limits of 1-150, please enter valid age");
        Sleep(2000);
        gotoxy(30,20);printf("                                                                      ");
        goto userage;
    }

    usergender:
    gotoxy(37,14);printf("Enter Gender(select one option):");
    gotoxy(37,15);printf("1. Male 2. Female 3. Others");
    gotoxy(55,17);printf("          ");
    gotoxy(55,17);scanf("%s",UserGender);
    if(atoi(UserGender))
    {
         if(atoi(UserGender) == 1)
        {
            strcpy(userGenderString,male);
        }
        else if(atoi(UserGender) == 2)
        {
            strcpy(userGenderString,female);
        }
        else if(atoi(UserGender) == 3)
        {
        strcpy(userGenderString,others);
        }
        else            //for invalid gender input
        {
            gotoxy(30,20);printf("     Enter a valid option for Gender");
            Sleep(1000);
            gotoxy(30,20);printf("                                                                      ");
            goto usergender;
        }
    }
    else            //for invalid gender input
    {
        gotoxy(30,20);printf("     Enter a valid option for Gender");
        Sleep(1000);
        gotoxy(30,19);printf("                                                                      ");
        goto usergender;
    }



    FILE *fua, *fpa;
    fua = fopen("usernames.txt","a");

    //updating the file that contains all the user details
    fprintf(fua,"%s %s %d %s\n",UserName,UserPassword,userAge,userGenderString);

    fclose(fua);
    gotoxy(37,20);printf("Account is successfully registered");
    Sleep(2000);
    homePage();
    return;
}

void userLogin()
{
    int count = 0;
    start:
    system("cls");
    gotoxy(35,14);printf("User Login: ");
    gotoxy(35,15);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\xB2");gotoxy(75,15);printf("\xB2\n");
    gotoxy(35,16);
    printf("\xB2");gotoxy(75,16);printf("\xB2\n");
    gotoxy(35,17);
    printf("\xB2");gotoxy(75,17);printf("\xB2\n");
    gotoxy(35,18);
    printf("\xB2");gotoxy(75,18);printf("\xB2\n");
    gotoxy(35,19);
    printf("\xB2");gotoxy(75,19);printf("\xB2\n");
    gotoxy(35,20);
    printf("\xB2");gotoxy(75,20);printf("\xB2\n");
    gotoxy(35,21);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    int notEqual = 0,totalLines = 0;
    struct user u[200];
    char UserName[30],UserPassword[30];
    gotoxy(37,17);printf("Enter a UserName: ");
    gotoxy(55,17);scanf("%s",UserName);

    FILE *flines;
    flines = fopen("usernames.txt","r");

    char ch;
    while((ch = getc(flines)) != EOF)
    {
        if(ch == '\n')
        {
            totalLines++;
        }
    }

    FILE *fr;
    fr = fopen("usernames.txt","r");

    for(int i=0 ; i<totalLines ; i++)
    {

        fscanf(fr,"%s %s %d %s",u[i].userName,u[i].userPassword,&u[i].userAge,u[i].gender);
        if(strcmp(u[i].userName,UserName) != 0)
        {
            notEqual++;             ///keep incrementing until the username entered is found in the data file
        }
        else
        {
            break;
        }
    }

    char password[30];
    int l=0;

    if(notEqual != totalLines && count<3)
    {

        gotoxy(37,19);printf("Enter password:");
        gotoxy(55,19);

        while(ch != 13)     //to print '*' when entering password
        {
            fflush(stdin);
            ch = getch();
            if(ch != 13 && ch != 8)     //printing '*' when a character other than enter and backspace is entered
            {
                printf("*");
                password[l] = ch;
                l++;
            }
            else if(ch == 8 )
            {
                if(l>0)
                {
                    l--;
                    password[l] = '\0';
                    printf("\b \b");        //when user enters backspace
                }
            }
            if(ch == 13)
            {
                break;
            }
        }
        strcpy(UserPassword,password);
        if(strcmp(UserPassword,u[notEqual].userPassword) != 0)
        {
            gotoxy(39,23);printf("Invalid password!");
            Sleep(1500);
            gotoxy(39,23);printf("Please try again!");
            gotoxy(55,19);printf("          ");
            Sleep(1000);
            count++;
            if(count == 3)      //allows only three invalid attempts to login
            {
                goto counting;
            }
            goto start;
        }
        else
        {
            gotoxy(39,23);printf("Successful login!");
            Sleep(2000);
            mainMenu(UserName);
        }
    }

    else
    {
            gotoxy(39,23);printf("Invalid Username!");
            Sleep(2000);
            userLogin();
    }
    counting:
    if(count == 3)
    {
        gotoxy(35,23);printf("Too many attempts! Please try again!");
        Sleep(2000);
        homePage();
    }

    fclose(fr);
}

void adminLogin()
{
    int count = 0;
    start:
    system("cls");
    gotoxy(35,14);printf("Admin Login: ");
    gotoxy(35,15);
   printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\xB2");gotoxy(75,15);printf("\xB2\n");
    gotoxy(35,16);
    printf("\xB2");gotoxy(75,16);printf("\xB2\n");
    gotoxy(35,17);
    printf("\xB2");gotoxy(75,17);printf("\xB2\n");
    gotoxy(35,18);
    printf("\xB2");gotoxy(75,18);printf("\xB2\n");
    gotoxy(35,19);
    printf("\xB2");gotoxy(75,19);printf("\xB2\n");
    gotoxy(35,20);
    printf("\xB2");gotoxy(75,20);printf("\xB2\n");
    gotoxy(35,21);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

    char adminUserName[30],adminPassword[30];

    /* hardcoded credentials for admin */

    char adminName[6] = {'a','d','m','i','n','\0'};
    char adminPass[10] = {'p','a','s','s','w','o','r','d','\0'};

    gotoxy(37,17);printf("Admin User name: ");
    fflush(stdin);
    gotoxy(55,17);scanf("%s",adminUserName);

    char ch;
    char password[30];
    int l=0;
    if(strcmp(adminUserName,adminName) == 0)
    {
        gotoxy(37,19);printf("Enter password:");
        gotoxy(55,19);
        ch = getch();
        while(ch != 13)         //to print '*' when entering password
        {
            fflush(stdin);
            ch = getch();
            if(ch != 13 && ch != 8)     //printing '*' when a character other than enter and backspace is entered
            {
                printf("*");
                password[l] = ch;
                l++;
            }
            else if(ch == 8)            //when user enters backspace
            {
                if(l>0)
                {
                    l--;
                    password[l] = '\0';
                    printf("\b \b");
                }
            }
            if(ch == 13)
            {
                break;
            }
        }
        strcpy(adminPassword,password);
        if(strcmp(adminPassword,adminPass) != 0)
        {
            gotoxy(39,23);printf("Invalid password!");
            Sleep(1500);
            gotoxy(39,23);printf("Please try again!");
            gotoxy(55,10);printf("          ");
            Sleep(1000);
            count++;
            if(count == 3)          //allows only three invalid attempts to login
            {
                goto counting;
            }
            goto start;
        }
        else
        {
            gotoxy(39,23);printf("Successful login!");
            Sleep(2000);
            adminMainMenu();
        }
    }
    else
    {
            gotoxy(39,23);printf("Invalid Username!");
            Sleep(2000);
            adminLogin();
    }
    counting:
    if(count == 3)
    {
            gotoxy(39,23);printf("Too many attempts! Please try again!");
            Sleep(2000);
            homePage();
    }
}

void adminUserView()
{
    system("cls");
    struct user u[200];
    FILE *fview;
    fview = fopen("usernames.txt","r");
    int totalLines = 0;

    char ch;
    while((ch = getc(fview)) != EOF)
    {
        if(ch == '\n')
        {
            totalLines++;
        }
    }

    FILE *fr;
    fr = fopen("usernames.txt","r");

    for(int i=0 ; i<totalLines ; i++)
    {
        fscanf(fr,"%s %s %d %s",u[i].userName,u[i].userPassword,&u[i].userAge,u[i].gender);
    }

    printf("\n\n\t-------------------------------------------------------\n");
    printf("\tS.No.\tUser Name\tPassword\tAge\tgender\n");
    printf("\t-------------------------------------------------------\n\n");

    for(int i=0 ; i<totalLines ; i++)
    {
        printf( "\t  %-5d\t%-12s\t%-8s\t%-3d\t%-10s\n",i+1,u[i].userName,u[i].userPassword,u[i].userAge,u[i].gender);
    }

    printf("\n\tSearch for particular user's details?(y/n)");
    char choice = getch();
    char searchUser[30];
    int count = 1;

    if(choice == 'y')
    {
        printf("\n\tEnter a valid user name to search:");
        scanf("%s",searchUser);
        for(int i=0 ; i<totalLines ; i++)
        {
            if(strcmp(searchUser,u[i].userName) == 0)
            {
                printf("\n\n\tS.No.\tUser Name\tPassword\tAge\tgender\n\n");
                printf( "\t  %-5d\t %-12s\t %-8s\t %-3d\t %-10s\n",i+1,u[i].userName,u[i].userPassword,u[i].userAge,u[i].gender);
                Sleep(2000);
                printf("\n\n\tPress Enter key to go back to main menu");
                char enter = getch() ;
                adminMainMenu();
            }
            else if(count == totalLines)
            {
                printf("Invalid username");
                Sleep(2000);
                adminMainMenu();
            }
            else
            {
                count++;
            }
        }
    }
    else
    {
        adminMainMenu();
    }
    fclose(fr);
    fclose(fview);
}

void games()
{
    char anonymousUser[30];
    system("cls");

    system("cls");
	int position = 1;
	int keyPressed = 0;
	while(keyPressed != 13)
	{
		system("cls");

        gotoxy(30,4);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
		gotoxy(30,5);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
		gotoxy(30,6);
        printf("                                                                       ");
		gotoxy(30,7);
        printf("                     SELECT MODE                         ");
		gotoxy(30,8);
        printf("                                                                       ");
		gotoxy(30,9);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
		gotoxy(30,10);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");

		gotoxy(30,13);
        printf("-------------------------------------------------------");
		gotoxy(30,15);
        printf("\t\t"); arrow(1,position); printf("SINGLE PLAYER");
		gotoxy(30,16);
        printf("\t\t");  arrow(2,position); printf("MULTI PLAYER (COMPETE)");
		gotoxy(30,17);
        printf("\t\t"); arrow(3,position); printf("EXIT");

		gotoxy(30,18);
        printf("-------------------------------------------------------");

		gotoxy(30,22);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
		gotoxy(30,23);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
        gotoxy(30,24);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
		gotoxy(30,25);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
		keyPressed = getch();

		if(keyPressed == 80 && position != 3)
			position++;
		else if(keyPressed == 72 && position != 1)
			position--;
		else
			position = position;
	}
    switch(position)
    {
        case 1:printf("\n\n\n\t\t\t\tEnter player name: ");
                    scanf("%s",anonymousUser);
                    gameMenu(anonymousUser);
        case 2:compete();
                    break;
        case 3:homePage();
                    break;
        default:printf("Invalid entry!!!");
                    homePage();
                    break;
    }
}

void compete()
{
    int numOfPlayers,gameScore;
    char numPlayers[2], typing_duration[3];
    float speed,accuracy,comprehension;
    float max_reading_speed = 6000.0;
    struct player p[200];
    char score;
    system("cls");

    system("cls");
	int position = 1;
	int keyPressed = 0;
	while(keyPressed != 13)
	{
		system("cls");

        gotoxy(30,4);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
		gotoxy(30,5);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
		gotoxy(30,6);
        printf("                                                                       ");
		gotoxy(30,7);
        printf("                       COMPETE                         ");
		gotoxy(30,8);
        printf("                                                                       ");
		gotoxy(30,9);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
		gotoxy(30,10);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");

		gotoxy(30,13);
        printf("-------------------------------------------------------");
		gotoxy(30,15);
        printf("\t\t"); arrow(1,position); printf("TYPING CHALLENGE");
		gotoxy(30,16);
        printf("\t\t");  arrow(2,position); printf("READING CHALLENGE");
        gotoxy(30,17);
        printf("\t\t");  arrow(3,position); printf("DISAPPEARING WORDS (GAME)");
        gotoxy(30,18);
        printf("\t\t");  arrow(4,position); printf("YOU GOT EM ALL?");
		gotoxy(30,19);
        printf("\t\t"); arrow(5,position); printf("EXIT");
		gotoxy(30,21);
        printf("-------------------------------------------------------");

		gotoxy(30,24);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
		gotoxy(30,25);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
        gotoxy(30,26);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
		gotoxy(30,27);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
		keyPressed = getch();

		if(keyPressed == 80 && position != 5)
			position++;
		else if(keyPressed == 72 && position != 1)
			position--;
		else
			position = position;
	}
    if(position == 5)
    {
        games();
    }
    label:
    system("cls");
    gotoxy(35,10);
    printf("Enter the number of players: ");
    gotoxy(64,10);gets(numPlayers);
    if(atoi(numPlayers) && (atoi(numPlayers) >= 1 && atoi(numPlayers) <=10))        //checking if only permissible number of users number is entered or not
    {
        Sleep(2000);
        system("cls");
    }
    else
    {
        gotoxy(35,12);printf("Enter a number between 1 and 10");
        Sleep(3000);
        gotoxy(35,12);printf("                                           ");
        gotoxy(64,10);printf("      ");
        goto label;
    }

    for(int i=0 ; i<atoi(numPlayers) ; i++)         //systems prompts competitors to enter their names
    {
        players:
        gotoxy(35,14);printf("Enter player %d name: ",i+1);
        gotoxy(35,18);printf("                                                    ");
        gotoxy(35,16);printf("                             ");
        gotoxy(35,16);scanf("%s",p[i].name);
        if(i>0)
        {
             for(int j = i-1 ; j >=0 ; j--)
            {
                    if(strcmp(p[i].name,p[j].name) == 0)
                    {
                        gotoxy(35,18);printf("Name is already taken, try something else");
                        gotoxy(35,16);printf("                             ");
                        Sleep(2000);
                        goto players;
                    }
            }
        }
    }

    if(position == 1)
    {
        system("cls");

        gotoxy(35,10);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(35,11);
        printf("\xB2");gotoxy(75,11);printf("\xB2");
        gotoxy(35,12);
        printf("\xB2");gotoxy(37,12);printf("Enter your typing duration(sec): ");gotoxy(75,12);printf("\xB2");
        gotoxy(35,13);
        printf("\xB2");gotoxy(75,13);printf("\xB2");
        gotoxy(35,14);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

        duration:
        fflush(stdin);
        gotoxy(71,12);scanf("%s",typing_duration);

        int typingDuration;
        if(atoi(typing_duration) && (atoi(typing_duration) < 120 && atoi(typing_duration) >= 1))
        {
            typingDuration = atoi(typing_duration);
        }
        else
        {
            gotoxy(35,16);printf("Enter a value from 1-120");
            Sleep(1000);
            gotoxy(71,12);printf("    ");
            goto duration;
        }

        for(int i=0 ; i<atoi(numPlayers) ; i++)         //system prompts competitor to participate in turns
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\t\t\t\t\t\t%s's turn\n\n",p[i].name);
            typingCompetition(typingDuration,&speed,&accuracy);
            p[i].typing_speed = speed;
            p[i].typing_accuracy = accuracy;
        }

        for(int i=0 ; i < atoi(numPlayers) ; i++)
        {
            for(int j=0 ; j< atoi(numPlayers) ; j++)
            {
                struct player temp;
                if(p[i].typing_speed < p[i].typing_speed)
                {
                    temp=p[i];
                    p[i]=p[j];
                    p[j]=temp;
                }
            }
        }

        system("cls");
        printf("\n\n\t\tResults: ");
        printf("\n\t----------------------------------------------------------------------------------");
        printf("\n\tS.no\tName\t\tTyping Speed\tTyping Accuracy");
        printf("\n\t----------------------------------------------------------------------------------\n\n");
        for(int i=0 ; i<atoi(numPlayers) ; i++)
        {
            printf("\t%4d\t%4s\t\t%12f\t%15f\n",i+1,p[i].name,p[i].typing_speed,p[i].typing_accuracy);
        }
        printf("\n\n\t\t\t%s is the winner, Congratulations!!!\n\n",p[0].name);
    }

    else if(position == 2)
    {
        for(int i=0 ; i<atoi(numPlayers) ; i++)
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\t\t\t\t\t\t%s's turn\n\n",p[i].name);
            Sleep(3000);
            readingCompetition(&speed,&comprehension);
            p[i].reading_speed = speed;
            p[i].reading_comprehension = comprehension;
        }
        system("cls");


        for(int i=0;i<atoi(numPlayers);i++)
        {
            for(int j=i;j<atoi(numPlayers);j++)
            {
                struct player temp;
                int x,y;
                x = (p[i].reading_speed)*100/(max_reading_speed) + p[i].reading_comprehension;
                y = (p[j].reading_speed)*100/(max_reading_speed) + p[j].reading_comprehension;
                if(x < y)
                {
                    temp=p[i];
                    p[i]=p[j];
                    p[j]=temp;
                }
            }
        }

        system("cls");
        printf("\n\n\t\tResults: ");
        printf("\n\t----------------------------------------------------------------------------------");
        printf("\n\tS.no Name\t\tReading Speed Reading Comprehension");
        printf("\n\t----------------------------------------------------------------------------------\n\n");
        for(int i=0 ; i<atoi(numPlayers) ; i++)
        {
            printf("\t%-4d% -4s %-13.1f %-21.1f\n",i+1,p[i].name, p[i].reading_speed,p[i].reading_comprehension);
        }

        printf("\n\n\t\t\t%s is the winner, Congratulations!!!\n\n",p[0].name);
    }
    else if(position == 3)
    {
        int level = levelSelector();
        Sleep(1000);
        if(level == 3)
        {
            compete();
        }
        FILE *gl;

        for(int i=0 ; i<atoi(numPlayers) ; i++)
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\t\t\t\t\t\t%s's turn\n\n",p[i].name);
            Sleep(3000);
            game1(p[i].name,level,"no");
        }
        if(level == 1)
        {
            gl = fopen("game1level1.txt","r");
        }
        else if(level == 2)
        {
            gl = fopen("game1level2.txt","r");
        }

        char c,name[30];
        int i=0;
        while((c = getc(gl)) != EOF)
        {
            fscanf(gl,"%s %d",name,&p[i].gameScore);
            i++;
        }
        fclose(gl);
        system("cls");

        for(int i=0;i<atoi(numPlayers);i++)
        {
            for(int j=i;j<atoi(numPlayers);j++)
            {
                struct player temp;

                if(p[i].gameScore < p[i].gameScore)
                {
                    temp=p[i];
                    p[i]=p[j];
                    p[j]=temp;
                }
            }
        }
        printf("\n\n\t\tResults: ");
        printf("\n\t\t-----------------------------------------------");
        printf("\n\t\tS.no Name\t\tScore");
        printf("\n\t\t-----------------------------------------------\n\n");
        for(int i=0 ; i<atoi(numPlayers) ; i++)
        {
            printf("\t\t%-4d% -4s\t\t%-5d\n",i+1,p[i].name, p[i].gameScore);
        }

        printf("\n\n\t\t\t%s is the winner, Congratulations!!!\n\n",p[0].name);

        clear_Leaderboard("game1level1.txt");
        clear_Leaderboard("game1level2.txt");
    }

    else if(position == 4)
    {
        int level = levelSelector();
        printf("%d",level);
        Sleep(1000);
        if(level == 3)
        {
            compete();
        }
        FILE *gl;

        for(int i=0 ; i<atoi(numPlayers) ; i++)
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\t\t\t\t\t\t%s's turn\n\n",p[i].name);
            Sleep(3000);
            game2(p[i].name,level,"no");
        }

       if(level == 1)
        {
            gl = fopen("game1level1.txt","r");
        }
        else if(level == 2)
        {
            gl = fopen("game1level2.txt","r");
        }

        char c,name[30];
        int i=0;
        while((c = getc(gl)) != EOF)
        {
            fscanf(gl,"%s %d",name,&p[i].gameScore);
            i++;
        }
        fclose(gl);
        system("cls");

        for(int i=0;i<atoi(numPlayers);i++)
        {
            for(int j=i;j<atoi(numPlayers);j++)
            {
                struct player temp;

                if(p[i].gameScore < p[i].gameScore)
                {
                    temp=p[i];
                    p[i]=p[j];
                    p[j]=temp;
                }
            }
        }
        printf("\n\n\t\tResults: ");
        printf("\n\t\t-----------------------------------------------");
        printf("\n\t\tS.no Name\t\tScore");
        printf("\n\t\t-----------------------------------------------\n\n");
        for(int i=0 ; i<atoi(numPlayers) ; i++)
        {
            printf("\t\t%-4d% -4s\t\t%-5d\n",i+1,p[i].name, p[i].gameScore);
        }
        clear_Leaderboard("game1level1.txt");
        clear_Leaderboard("game1level2.txt");
    }

    printf("Press any key to go back to Menu:");
    getch();
    compete();
}

void typingCompetition(int typing_duration,float *speed , float *accuracy)
{
    char ch,c;
    char a[2000];
    int k=0,count=0,i=0,b,wrong=0, num_letters_typed=0;
    float typing_accuracy;
    int randomisedArray[9];             // change size according to number of paragraphs
    time_t start,end;
    FILE *ft;

    printf("\n\t\t\t---------------Passage-----------------\n\n\n");

    ft = fopen("paragraphsTyping.txt","r");

    ranArray(randomisedArray,9);

    int randomNumber = randomisedArray[0];         //takes a random number and prints that numbered paragraph from text file

    int parNumber =0;

    while((ch = getc(ft)) != EOF)
    {
        if(ch == '~')       //paragraphs are separated by '~'
        {
            parNumber++;            //paragraph number in text file
            if(parNumber == randomNumber)       //when paragraph number = rand number, print that paragraph
            {
                int i = 0;
                printf("\t");
                while((ch=getc(ft)) != '~'  && ch != EOF)
                {
                    a[i] = ch;          //copy that particular paragraph for furthur usage
                    if(ch == '\n')
                    {
                        printf("\n\t");
                    }
                    else
                    {
                        putchar(ch);
                    }
                    i++;
                }
                a[i] = '\0';
            }
        }
    }
    fclose(ft);

    printf("\n\n");

    printf("\n\n\t\t---->Timer automatically starts when you start typing <---\n\n\n");

    // p=fopen("Typing_file1.txt","r");
    int m = 0;
    while(a[m] != '\0')         //for assessing user input(whether is matches the paragraph displayed or not)
    {
        label:
        b=0;
        c=getch();
        if(k==0)        //if entering the loop for the first time
        {
            start=time(NULL);
        }
        if(c == a[m])        //if character matches
        {
            //Beep(600,100);
            putchar(c);
             if(c==' ')
             {
                count++;
             }
            num_letters_typed++;
        }
        else if(c=='\r'&&a[m]=='\n')        //if 'enter' is pressed
        {
            //Beep(600,100);
            putchar(c);
            printf("\n");
            num_letters_typed++;
        }
        else        //if character mismatch
        {
            b=1;
            wrong++;
            //Beep(600,100);
        }
        end=time(NULL);
        if(difftime(end,start)>=typing_duration)
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
        m++;
    }

    float typing_speed;
    char lastScore[5];
    typing_speed=((float)num_letters_typed/5)/((float)typing_duration/60);  //calculating typing speed
    printf("\n\t\tYour typing speed");
    printf("\n\n\t\t***** %.2f WPM ******\n\n",typing_speed);
    *speed = typing_speed;

    typing_accuracy=(float)num_letters_typed/(num_letters_typed+wrong)*100;     //calculating typing accuracy

    printf("\n\t\tYour accuracy\n");
    printf("\n\t\t----%.1f percentage----", typing_accuracy);
    *accuracy = typing_accuracy;


    printf("\n\n\t\tPress Enter to continue...\n\n");
    while((getch())!='\r');
}

void readingCompetition(float *speed , float *comprehension)
{
    system("cls");
    int length_of_text = 1,k=0;
    char ch,a[2000];
    double reading_speed, reading_comprehension, time_elapsed;
     int randomisedArray[5];             // change size according to number of paragraphs
    time_t start,end;
    FILE *ft,*fp;

    system("cls");
    gotoxy(50,20);printf("\nPassage will appear in 3 seconds");
    Sleep(3000);

    system("cls");

    ft = fopen("pragraphsTyping.txt","r");

    printf("\n\n\n\t\t\t---------------Passage-----------------\n\n\n");
    ranArray(randomisedArray,5);

    int randomNumber = randomisedArray[0];      //takes a random number and prints that numbered paragraph from text file
    // printf("%d",randomNumber);

    int parNumber =0;

    while((ch = getc(ft)) != EOF)
    {
        if(ch == '~')       //paragraphs are separated by '~'
        {
            parNumber++;
            if(parNumber == randomNumber)
            {
                int i = 0;
                printf("\t");
                while((ch=getc(ft)) != '~'  && ch != EOF)
                {
                    a[i] = ch;      //copy into a char string for surthur purpose
                    if(ch == '\n')
                    {
                        printf("\n\t");
                    }
                    else
                    {
                        putchar(ch);
                    }
                    i++;
                }
                a[i] = '\0';
            }
        }
    }
    fclose(ft);

    printf("\n\n");

    start=time(NULL);       //storing starting time
    printf("\n\nPress Enter if you have completed reading....\n");
    while((getch())!='\r');

    system("cls");
    printf("\n\n");

    end = time(NULL);       //end time when user completes reading
    time_elapsed = difftime(end,start);
    printf("Time elapsed : %.0f sec", time_elapsed);

    int i = 0;
    while(a[i] != '\0')         //using a[] char string for finding length of the paragraph
    {
        if(a[i]=='\n' || a[i]==' ')
        {
            length_of_text++;
        }
        i++;
    }

    reading_speed = (length_of_text/time_elapsed)*60;        //calculating reading speed
    reading_comprehension = Readingcomprehension(randomNumber);  //calculating reading comprehension

    printf("\n\n\t\t----Your Reading speed is %.2f WPM----\n\n", reading_speed);
    *speed = reading_speed;

    printf("\n\n\t\t----Your Reading comprehension is %.2f percentage----\n\n", reading_comprehension);
    *comprehension = reading_comprehension;

    printf("\n\n\t\tPress Enter to continue...\n\n");
    while((getch())!='\r');
}

void Typingspeed(char UserName[])       //Calculates Typing speed
{
    char ch,c;
    char a[2000];       //for storing a random passage into a string
    int k=0,count=0,i=0,b,wrong=0, num_letters_typed=0;
    char typing_duration[3];
    float typing_accuracy;
    time_t start,end;       //keeping the track of starting and ending time
    int randomisedArray[9];
    FILE *ft;

    system("cls");

    gotoxy(35,10);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(35,11);
    printf("\xB2");gotoxy(75,11);printf("\xB2");
    gotoxy(35,12);
    printf("\xB2");gotoxy(37,12);printf("Enter your typing duration(sec): ");gotoxy(75,12);printf("\xB2");
    gotoxy(35,13);
    printf("\xB2");gotoxy(75,13);printf("\xB2");
    gotoxy(35,14);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    duration:
    fflush(stdin);
    gotoxy(71,12);scanf("%s",typing_duration);

    int typingDuration;
    if(atoi(typing_duration) && (atoi(typing_duration) < 120 && atoi(typing_duration) >= 1))
    {
       typingDuration = atoi(typing_duration);
    }
    else
    {
        gotoxy(35,16);printf("Enter a value from 1-120");
        Sleep(1000);
        gotoxy(71,12);printf("    ");
        goto duration;
    }
    system("cls");


    printf("\n\t\t---------------------------------------------------------\n\n");
    printf("\n\t\t                     Typing speed                      \n\n");
    printf("\n\t\t---------------------------------------------------------\n\n");
    printf("\n\t\t\t---------------Passage-----------------\n\n\n");


    ft = fopen("paragraphsTyping.txt","r");

    ranArray(randomisedArray,9);

    int randomNumber = randomisedArray[0];
    // int randomNumber = 4;
    // printf("%d",randomNumber);

    int parNumber =0;

    while((ch = getc(ft)) != EOF)       //traversing the file and choosing a random paragraph
    {

        if(ch == '~')       //Paragraphs are separated by '~'
        {
            parNumber++;
            if(parNumber == randomNumber)
            {
                int i = 0;
                printf("\t");
                while((ch=getc(ft)) != '~'  && ch != EOF)
                {
                    a[i] = ch;
                    if(ch == '\n')
                    {
                        printf("\n\t");
                    }
                    else
                    {
                        putchar(ch);
                    }
                    i++;
                }
                a[i] = '\0';
            }
        }
    }
    fclose(ft);

    printf("\n\n");

    printf("\n\n\t\t---->Timer automatically starts when you start typing <---\n\n\n");
    // p=fopen("Typing_file1.txt","r");
    int m = 0;

    while(a[m] != '\0')
    {
        label:
        b=0;
        c=getch();
        if(k==0)        //if entering the loop for the first time
        {
            start=time(NULL);
        }
        if(c == a[m])       //if character matches
        {
            //Beep(600,100);
            putchar(c);
             if(c==' ')
             {
                count++;
             }
            num_letters_typed++;
        }
        else if(c=='\r'&& a[m]=='\n')       //if 'enter' is pressed
        {
            //Beep(600,100);
            putchar(c);
            printf("\n");
            num_letters_typed++;
        }
        else        //if character mismatch
        {
            b=1;
            wrong++;
            //Beep(600,100);
        }
        end=time(NULL);

        if(difftime(end,start) >= typingDuration)       //if time has finished
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
        m++;
    }

    float typing_speed;

     typing_speed=((float)num_letters_typed/5)/((float)typingDuration/60);      //calculating typing speed
    printf("\n\t\tYour typing speed");
    printf("\n\n\t\t***** %.2f WPM ******\n\n",typing_speed);

    typing_accuracy=(float)num_letters_typed/(num_letters_typed+wrong)*100;     //calculating typing accuracy
    printf("\n\t\tYour accuracy\n");
    printf("\n\t\t----%.1f percentage----", typing_accuracy);
    printf("\n\n\t\tPress Enter to continue...\n\n");


    while((getch())!='\r');     //enter to continue

    Add_To_Typing_Leaderboard(typing_speed, typing_accuracy,UserName);      //adding to typing leaderboard

}

void Add_To_Typing_Leaderboard(float typing_speed, float typing_accuracy, char UserName[])      //adds user to typing leaderboard
{
    struct player p[200],temp;
    FILE *fp;
    char c;
    int l=0,i,j;

    fflush(stdin);

    if(is_Registered_user(UserName, "Typing_Leaderboard.txt"))      //checking if user is registered
    {
        printf("--------------Registered-------------");
        display_Feedback(UserName, typing_speed, typing_accuracy, "Typing_Leaderboard.txt");        //displays feedback
        Delete_User("Typing_Leaderboard.txt", UserName);        //removes the previous record of the user
    }

    fp=fopen("Typing_Leaderboard.txt","a");
   // printf("*****%s********",UserName);
    fprintf(fp,"%s %.1f %.1f\n",UserName, typing_speed, typing_accuracy);       //appending results to file
    fclose(fp);

    Display_Typing_Leaderboard(UserName);       //displays the leaderboard

}

void Display_Typing_Leaderboard(char UserName[])
{
    struct player p[200],temp;
    FILE *fp;
    char c;
    int l=0,i,j;
    system("cls");
    printf("\n\t\tleaderboard :\n\n");
    printf("\n\t----------------------------------------------------------------------------------");
    printf("\n\tS.No   Name\t\t\t\tSpeed\tAccuracy");
    printf("\n\t----------------------------------------------------------------------------------\n\n");

    fp=fopen("Typing_Leaderboard.txt","r");
    while((c=getc(fp))!=EOF)        //calculating the number of lines in the leaderboard file
    {
        if(c=='\n')
        {
            l++;
        }
    }
    fclose(fp);

    fp=fopen("Typing_Leaderboard.txt","r");
    for(i=0;i<l;i++)        //storing the leaderboard data into a structure array
    {
        fscanf(fp,"%s %f %f",p[i].name,&p[i].typing_speed,&p[i].typing_accuracy);
    }
    fclose(fp);

    for(i=0;i<l;i++)        //sorting the data in leaderboard
    {
        for(j=i;j<l;j++)
        {
             if(p[i].typing_speed<p[j].typing_speed)
             {
                 temp=p[i];
                 p[i]=p[j];
                 p[j]=temp;
             }
        }
    }

     for(i=0;i<l;i++)       //displaying the leaderboard
    {
        printf("\t %-4d %-4s\t\t\t\t%-5.1f\t%-8.1f\n",i+1,p[i].name,p[i].typing_speed,p[i].typing_accuracy);
    }

    Sleep(2000);
    printf("\nPress Enter key to go back to main menu");
    char enter = getch() ;
    if(strcmp(UserName,"admin") == 0)
        adminMainMenu();
    else
        mainMenu(UserName);
}

void Readingspeed(char UserName[])
{
    system("cls");
    int length_of_text = 1,k=0;
    char ch,a[2000];
    int randomisedArray[5];
    double reading_speed, reading_comprehension, time_elapsed;
    time_t start,end;
    FILE *ft;

    system("cls");
    gotoxy(35,20);printf("Passage will appear in 3 seconds");
    Sleep(3000);

    system("cls");
    ft = fopen("paragraphsReading.txt","r");

    printf("\n\n\n\t\t\t---------------Passage-----------------\n\n\n");

    ranArray(randomisedArray,5);

    int randomNumber = randomisedArray[0];
    // printf("%d",randomNumber);

    int parNumber =0;

    while((ch = getc(ft)) != EOF)       //choosing a random paragraph
    {
        if(ch == '~')       //paragraphs are separated by '~'
        {
            parNumber++;
            if(parNumber == randomNumber)
            {
                int i = 0;
                printf("\t");
                while((ch=getc(ft)) != '~'  && ch != EOF)
                {
                    a[i] = ch;
                    if(ch == '\n')
                    {
                        printf("\n\t");
                    }
                    else
                    {
                        putchar(ch);
                    }
                    i++;
                }
                a[i] = '\0';
            }
        }
    }
    fclose(ft);

    printf("\n\n");

    start=time(NULL);       //storing starting time
    printf("\n\n\t\t\tPress Enter if you have completed reading....\n");
    while((getch())!='\r');

    system("cls");
    printf("\n\n");

    end = time(NULL);       //end time when user completes reading
    time_elapsed = difftime(end,start);
    printf("Time elapsed : %.0f sec", time_elapsed);

    int i = 0;
    while(a[i] != '\0')     //using a[] char string for finding length of the paragraph
    {
        if(a[i]=='\n' || a[i]==' ')
        {
            length_of_text++;
        }
        i++;
    }

    reading_speed = (length_of_text/time_elapsed)*60;       //calculating reading speed
    reading_comprehension = Readingcomprehension(randomNumber);     //calculating comprehension
    printf("\n\n\t\t----Your Reading speed is %.2f WPM----\n\n", reading_speed);
    printf("\n\n\t\t----Your Reading comprehension is %.2f percentage----\n\n", reading_comprehension);

    printf("\n\n\t\tPress Enter to continue...\n\n");
    while((getch())!='\r');

    Add_To_Reading_Leaderboard(reading_speed, reading_comprehension,UserName);      //adding user to reading leaderboard

}

double Readingcomprehension(int randomNumber)
{
    system("cls");
    printf("\n\n\t\t------------Reading Comprehension------------\n\n");
    int num_questions = 5, points = 0;
    int i;
    char question[100], answer[20], response[20];
    double reading_comprehension;
    char ch;
    FILE *fp;
    fp = fopen("Quiz.txt","r");

    for(int count =0; count < randomNumber; count++)        //to select random quiz questions
    {
        while((ch = getc(fp)) != '~' && ch != EOF);     //group of questions are separated by '~'
    }

    for(i=0; i<num_questions; i++)      //displaying questions and getting responses
    {
        fscanf(fp, "%[^?]s ",question);
        fseek(fp, 1, 1);
        fscanf(fp, "%s ",answer);
        //printf("%s ---- %s\n",question, answer);
        fflush(stdin);
        printf("%s?\nYour response : ", question);
        gets(response);
        printf("\n");

        if(strcmp(response, answer) == 0)           //if correct answer
        {
            points++;
        }
    }

    reading_comprehension = ((double)points/num_questions) * 100;
    return reading_comprehension;
    fclose(fp);

}

void Display_Reading_Leaderboard(char UserName[])
{
    struct player p[200], temp;
    FILE *fp;
    char c;
    float max_reading_speed = 6000.0;       //This is an approximate maximum reading speed
    int l=0,i,j;
    system("cls");
    printf("\n\t\tReading_Leaderboard :\n\n");
    printf("\n\t----------------------------------------------------------------------------------");
    printf("\n\tS.no  Name \t\tReading_speed(WPM)\t\tReading_comprehension(%%)");
    printf("\n\t----------------------------------------------------------------------------------\n\n");

    fp=fopen("Reading_Leaderboard.txt","r");
    while((c=getc(fp))!=EOF)        //calculating number of lines
    {
        if(c=='\n')
        {
            l++;
        }
    }
    fclose(fp);

    fp=fopen("Reading_Leaderboard.txt","r");
    for(i=0;i<l;i++)        //retrieving data from file to a structure array
    {
        fscanf(fp,"%s %f %f",p[i].name,&p[i].reading_speed,&p[i].reading_comprehension);
    }
    fclose(fp);

    for(i=0;i<l;i++)        //sorting leaderboard taking both speed and comprehension into consideration
    {
        for(j=i;j<l;j++)
        {
            int x,y;
             x = (p[i].reading_speed)*100/(max_reading_speed) + p[i].reading_comprehension;
             y = (p[j].reading_speed)*100/(max_reading_speed) + p[j].reading_comprehension;
             if(x < y)
             {
                 temp=p[i];
                 p[i]=p[j];
                 p[j]=temp;
             }
        }
    }

     for(i=0;i<l;i++)       //displaying leaderboard
    {
        printf("\t %-6d%-16s%-18.1f\t\t%-21.1f\n",i+1,p[i].name,p[i].reading_speed,p[i].reading_comprehension);
    }

    Sleep(2000);
    printf("\nPress Enter key to go back to main menu");
    char enter = getch() ;
    if(strcmp(UserName,"admin") == 0)
        adminMainMenu();
    else
        mainMenu(UserName);
}

void Add_To_Reading_Leaderboard(double reading_speed, double reading_comprehension, char UserName[])
{
    struct player p[200],temp;
    FILE *fp;
    char c, name[50], filename[50];
    int l=0,i,j;

    fflush(stdin);

    if(is_Registered_user(UserName, "Reading_Leaderboard.txt"))     //checking if user is registered
    {
        //printf("--------------Registered-----------");
        display_Feedback(UserName, reading_speed, reading_comprehension, "Reading_Leaderboard.txt");        //displaying feedback
        Delete_User("Reading_Leaderboard.txt", UserName);
    }

    fp=fopen("Reading_Leaderboard.txt","a");
    fprintf(fp,"%s %.1f %.1f\n",UserName, reading_speed, reading_comprehension);
    fclose(fp);

    Display_Reading_Leaderboard(UserName);      //displays the leaderboard
}

void viewLeaderBoards(char UserName[])
{
    system("cls");
    int choice,position = 1,keyPressed = 0;
    while(keyPressed != 13)
	{

		system("cls");
        gotoxy(20,4);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
		gotoxy(20,5);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");

        gotoxy(20,7);
        printf("\t  "); arrow(1,position); printf("TYPING SPEED LEADER BOARD");
		gotoxy(20,8);
        printf("\t  ");  arrow(2,position); printf("READING SPEED LEADER BOARD");

        gotoxy(20,10);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
		gotoxy(20,11);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");

        keyPressed = getch();

		if(keyPressed == 80 && position != 4)
			position++;
		else if(keyPressed == 72 && position != 1)
			position--;
		else
			position = position;
    }
    switch (position)
    {
                case 1: Display_Typing_Leaderboard(UserName);
                            break;
                case 2: Display_Reading_Leaderboard(UserName);
                            break;
    }
}

void Delete_User(char  filename[],char userName[])      //deletes a user from all the leaderboars and from the registration file
{
    int temp = 1;
    int num_lines = 0, delete_line, counter = 0, user_found = 0;
    char username[50], c, ch;
    struct player p[200];
    FILE *fp;
    FILE *fileptr1, *fileptr2;

    fp=fopen(filename,"r");
    while((c=getc(fp))!=EOF)        //calculating number of lines
    {
        if(c=='\n')
        {
            num_lines++;
        }
    }
    fclose(fp);

    fp=fopen(filename,"r");
    for(int i=0;i<num_lines;i++)        //searching for the user to be deleted
    {
        counter++;
        fscanf(fp,"%s %f %f",p[i].name,&p[i].typing_speed,&p[i].typing_accuracy);

        if(strcmp(p[i].name, userName) == 0)
        {
            delete_line = counter;
            user_found = 1;
            break;
        }
    }
    // printf("%d",counter);
    fclose(fp);

    if(user_found != 1)     //if user not found
    {
        printf("\n\n\t\t\t\t\t\t---------User Not Found----------\n\n");
        return;
    }
    fileptr1 = fopen(filename, "r");
    fileptr2 = fopen("replica.txt", "w");

    while ((ch = getc(fileptr1)) != EOF)
    {
            if (temp != delete_line)
            {
                //copy all lines in file replica.c
                putc(ch, fileptr2);
            }
            if (ch == '\n') temp++;
    }
    fclose(fileptr1);
    fclose(fileptr2);
    remove(filename);
    //rename the file replica.c to original name
    rename("replica.txt", filename);
    printf("\n\n\t\t\t\t\t\t------------User : successfully removed---------------\n\n");
}

void Delete_User_credentials(char  filename[],char userName[])
{
    int temp = 1;
    int num_lines = 0, delete_line, counter = 0, user_found = 0;
    char username[50], c, ch;
    struct user u[200];
    FILE *fp;
    FILE *fileptr1, *fileptr2;

    fp=fopen(filename,"r");
    while((c=getc(fp))!=EOF)
    {
        if(c=='\n')
        {
            num_lines++;
        }
    }
    fclose(fp);

    fp=fopen(filename,"r");
    for(int i=0;i<num_lines;i++)
    {
        counter++;
        fscanf(fp,"%s %s %d %s",u[i].userName,u[i].userPassword,&u[i].userAge,u[i].gender);

        if(strcmp(u[i].userName, userName) == 0)
        {
            delete_line = counter;
            user_found = 1;
            break;
        }
    }
    // printf("%d",counter);
    fclose(fp);

    if(user_found != 1)
    {
        printf("\n\n\t\t\t\t\t\t---------User Not Found in %s---------- \n\n",filename);
        return;
    }
    fileptr1 = fopen(filename, "r");
    fileptr2 = fopen("replica.txt", "w");

    while ((ch = getc(fileptr1)) != EOF)
    {
            if (temp != delete_line)
            {
                //copy all lines in file replica.c
                putc(ch, fileptr2);
                printf("%c",ch);
            }
            if (ch == '\n') temp++;
    }

    fclose(fileptr1);
    fclose(fileptr2);
    remove("usernames.txt");
    // printf("%s",filename);
    //rename the file replica.c to original name
    rename("replica.txt","usernames.txt");
    printf("\n\n\t\t\t\t\t\t\t------------User successfully removed from %s---------------\n\n",filename);
}

void clear_Leaderboard(char filename[])     //clears the leaderboard
{
    fclose(fopen(filename, "w"));
    // printf("\n\n\t\t--------------Leaderboard cleared----------------\n\n");
}

void gameMenu(char userName[])
{
    system("cls");
	int position = 1;
	int keyPressed = 0;

    while(keyPressed != 13)
    {
            system("cls");

            gotoxy(30,4);
            printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
            gotoxy(30,5);
            printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
            gotoxy(30,6);
            printf("                                                                       ");
            gotoxy(30,7);
            printf("                        GAME                         ");
            gotoxy(30,8);
            printf("                                                                       ");
            gotoxy(30,9);
            printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
            gotoxy(30,10);
            printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");

            gotoxy(30,13);
            printf("-------------------------------------------------------");

            gotoxy(30,15);
            printf("\t\t"); arrow(1,position); printf("DISAPPEARING WORDS");
            gotoxy(30,16);
            printf("\t\t");  arrow(2,position); printf("YOU GOT EM ALL?");
            gotoxy(30,17);
            printf("\t\t"); arrow(3,position); printf("EXIT");

            gotoxy(30,19);
            printf("-------------------------------------------------------");

            gotoxy(30,22);
            printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
            gotoxy(30,23);
            printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
            gotoxy(30,24);
            printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
            gotoxy(30,25);
            printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
            keyPressed = getch();

            if(keyPressed == 80 && position != 3)
                position++;
            else if(keyPressed == 72 && position != 1)
                position--;
            else
                position = position;
    }
    int k;
    switch (position)
    {
            case 1: k = levelSelector();        //lets user select the level of game
                        if(k == 3)
                        {
                            games();
                        }
                        else
                        {
                            game1(userName,k,"yes");            //"yes" parameter for telling that user is playing game in single mode
                        }
                        break;
            case 2: k = levelSelector();
                        if(k == 3)
                        {
                            games();
                        }
                        else
                        {
                            game2(userName,k,"yes");        //"yes" parameter for telling that user is playing game in single mode
                        }
                        break;
            case 3:games();
                        break;
            default: gotoxy(20,27);printf("Invalid!");
                        break;
    }
}

void game1(char userName[], int level, char singleOrNot[])
{
    system("cls");
    struct user u[100];
    char enteredWord[30];
	int position = 1;
    int a[96];
    int points = 0;
	int keyPressed = 0;
    time_t start,end;
    FILE *gf,*gl1,*gl2;
    gf = fopen("gameWords.txt","r");

    if(level == 3)
    {
        gameMenu(userName);
    }
    system("cls");
    printf("\n\n\n\n\n\t\t\t\tWords will be displayed for a limited period of time\n\t\t\t\tcorrectly type in as many words as possible\n\t\t\t\tClock starts ticking as soon as game starts\n\t\t\t\tAll the best!!!");
    Sleep(5000);
    if(level == 1)
    {
        system("cls");
        char ch;
        int i=0;
        while((ch = getc(gf)) != EOF)
        {
            fscanf(gf,"%s",u[i].gameWord);
            i++;
        }

        start = time(NULL);
        ranArray(a,96);
        int j=0;
        end = time(NULL);
        gotoxy(30,18);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

        gotoxy(30,27);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

        while(difftime(end,start) < 30)
        {
            gotoxy(45,20);printf("%s",u[a[j]].gameWord);
            Sleep(500);
            gotoxy(45,20);printf("                   ");
            gotoxy(32,25);printf("Enter the Word:                 ");
            gotoxy(52,25);scanf("%s",enteredWord);
            if(strcmp(enteredWord,u[a[j]].gameWord) == 0)       //if user enters correct word, he/she gets 2 points
            {
                points += 2;
            }
            end = time(NULL);
            j++;
        }

        if(strcmp(singleOrNot,"no") != 0)
        {
            gl1 = fopen("game1level1.txt","a");
            fprintf(gl1,"%s %d\n",userName,points);
            fclose(gl1);
        }
        gotoxy(45,29);printf("Time up!!!");
        gotoxy(45,30);printf("Your score: %d",points);
        Sleep(3000);
    }
    else if(level == 2)
    {
         system("cls");
        char ch;
        int i=0;
        while((ch = getc(gf)) != EOF)
        {
            fscanf(gf,"%s",u[i].gameWord);
            i++;
        }

        start = time(NULL);
        ranArray(a,96);
        int j=0;
        end = time(NULL);
        gotoxy(30,18);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

        gotoxy(30,27);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

        while(difftime(end,start) < 15)
        {
            gotoxy(45,20);printf("%s",u[a[j]].gameWord);
            Sleep(250);
            gotoxy(45,20);printf("                   ");
            gotoxy(32,25);printf("Enter the Word:                 ");
            gotoxy(52,25);scanf("%s",enteredWord);
            if(strcmp(enteredWord,u[a[j]].gameWord) == 0)
            {
                points += 2;
            }
            end = time(NULL);
            j++;
        }


        if(strcmp(singleOrNot,"no") != 0)
        {
            gl2 = fopen("game1level2.txt","a");
            fprintf(gl2,"%s %d",userName,points);
            fclose(gl2);
        }
        gotoxy(45,29);printf("Time up!!!");
        gotoxy(45,30);printf("Your score: %d",points);Sleep(3000);
    }
    fclose(gf);
    printf("\n\t\tPress any key..");
    getch();
    int flag =0;
    if(strcmp(singleOrNot,"no") == 0)       //"no" parameter to show that player is playing in multiple player mode
    {
        flag = 0;
    }
    else
    {
        gameMenu(userName);
    }
}

void game2(char userName[], int level, char singleOrNot[])
{
    system("cls");
    struct user u[100];
    char enteredWord[30];
	int position = 1;
    int a[96];
    int points = 0;
	int keyPressed = 0;
    time_t start,end;
    FILE *gf,*gl1,*gl2;
    gf = fopen("gameWords.txt","r");

    if(level == 3)
    {
        gameMenu(userName);
    }
    system("cls");
    printf("\n\n\n\n\n\t\t\t\tWords will be displayed for a limited period of time\n\t\t\t\tcorrectly type in as many words as possible\n\t\t\t\tClock starts ticking as soon as game starts\n\t\t\t\tAll the best!!!");
    Sleep(5000);
    if(position == 1)
    {
        system("cls");
        char ch;
        int i=0;
        while((ch = getc(gf)) != EOF)
        {
            fscanf(gf,"%s",u[i].gameWord);
            i++;
        }

        start = time(NULL);
        ranArray(a,96);
        int j=0;
        end = time(NULL);
        gotoxy(30,18);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

        gotoxy(30,27);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        int expected_words[100], k=0;
        while(difftime(end,start) < 5)
        {
            gotoxy(45,20);printf("%s",u[a[j]].gameWord);
            Sleep(1000);
            gotoxy(45,20);printf("                   ");
            expected_words[k] = j;
            k++;
            end = time(NULL);
            j++;
        }
        for(int i=0; i<k; i++)
        {
            gotoxy(32,25);printf("Enter the Word:                 ");
            gotoxy(52,25);scanf("%s",enteredWord);
            if(strcmp(enteredWord,u[a[expected_words[i]]].gameWord) == 0)
            {
                points += 2;
            }
            else
            {
                break;
            }

        }

        if(strcmp(singleOrNot,"no") != 0)        //"no" parameter to show that player is playing in multiple player mode
        {
            gl1 = fopen("game1level1.txt","a");
            fprintf(gl1,"%s %d\n",userName,points);
            fclose(gl1);
        }
        gotoxy(45,30);printf("Your score: %d",points);
        Sleep(3000);
    }
    else if(level == 2)
    {
         system("cls");
        char ch;
        int i=0;
        while((ch = getc(gf)) != EOF)
        {
            fscanf(gf,"%s",u[i].gameWord);
            i++;
        }

        start = time(NULL);
        ranArray(a,96);
        int j=0;
        end = time(NULL);
        gotoxy(30,18);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

        gotoxy(30,27);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        int expected_words[100], k=0;
        while(difftime(end,start) < 10)
        {
            gotoxy(45,20);printf("%s",u[a[j]].gameWord);
            Sleep(500);
            gotoxy(45,20);printf("                   ");
            end = time(NULL);
            expected_words[k] = j;
            k++;
            j++;
        }
        for(int i=0; i<k; i++)
        {
            gotoxy(32,25);printf("Enter the Word:                 ");
            gotoxy(52,25);scanf("%s",enteredWord);
            if(strcmp(enteredWord,u[a[expected_words[i]]].gameWord) == 0)
            {
                points += 2;
            }
            else
            {
                    break;
            }

        }

        if(strcmp(singleOrNot,"no") != 0)
        {
            gl2 = fopen("game1level2.txt","a");
            fprintf(gl2,"%s %d",userName,points);
            fclose(gl2);
        }
        // gotoxy(45,29);printf("Time up!!!");
        gotoxy(45,30);printf("Your score: %d",points);
        Sleep(3000);
    }
    fclose(gf);
    printf("\n\n\t\t\tPress any key..");
    getch();
    int flag =0 ;
    if(strcmp(singleOrNot,"no") == 0)
    {
        flag = 0;
    }
    else
    {
        gameMenu(userName);
    }
}

void ranArray(int randomisedArray[],int n)
{
	int i,j,temp;
	srand(time(NULL));

	for(i=0;i<n;i++)
		randomisedArray[i]=i+1;

	for(i=n-1;i>=1;i--)
	{
        j = rand()%(i+1);
		temp = randomisedArray[i];
		randomisedArray[i]=randomisedArray[j];
		randomisedArray[j] = temp;
	}
}

void display_Feedback(char name[], double present_Typing_speed, double present_Typing_accuracy, char filename[])        //displays feedback
{
    struct player p[200],temp;
    FILE *fp;
    char c;
    int l=0,i,j, position=0;

    system("cls");

    printf("\n\n\t=================================================================================================");
    printf("\n\t\t                                       User Feedback                                                                                                            ");
    printf("\n\t=================================================================================================\n");

    fp=fopen(filename,"r");
    while((c=getc(fp))!=EOF)        //calculating number of lines
    {
        if(c=='\n')
        {
            l++;
        }
    }
    fclose(fp);

    fp=fopen(filename,"r");
    for(i=0;i<l;i++)        //retrieving data into a structure array
    {
        fscanf(fp,"%s %f %f",p[i].name,&p[i].typing_speed,&p[i].typing_accuracy);
    }
    fclose(fp);

    for(i=0; i<l; i++)      //searching for the user in file
    {
        if(strcmp(p[i].name, name) == 0)
        {
            position = i;
            break;
        }
    }

     printf("\n\n\t\t---->present speed: %f",present_Typing_speed);
     printf("\t\t---->previous speed : %f",p[position].typing_speed);

     //comparing with past performance and giving suitable feedback

    if(present_Typing_speed > p[position].typing_speed )
    {
        printf("\n\n\t\tHurrayy!!!! you have performed better than last time");
    }
    else if(present_Typing_speed == p[position].typing_speed)
    {
        printf("\n\n\t\tYou are performing consistently, keep it up");
    }
    else
    {
        printf("\n\n\t\tYour performance has decreased, better luck next time");
    }

    printf("\n\n\t\tPress Enter to continue...");
    while((getch())!='\r');
}

int is_Registered_user(char name[], char filename[])        //checks if user is registered
{
    int temp = 1;
    int num_lines = 0, delete_line, counter = 0, user_found = 0;
    char username[50], c, ch;
    struct player p[200];
    FILE *fp;
    FILE *fileptr1, *fileptr2;

    fp=fopen(filename,"r");
    while((c=getc(fp))!=EOF)        //counting number of lines
    {
        if(c=='\n')
        {
            num_lines++;
        }
    }
    fclose(fp);

    fp=fopen(filename,"r");
    for(int i=0;i<num_lines;i++)        //searching for the user in the file
    {
        counter++;
        fscanf(fp,"%s %f %f",p[i].name,&p[i].typing_speed,&p[i].typing_accuracy);

        if(strcmp(p[i].name, name) == 0)
        {
            printf("\n\n\t\t---------User Found----------\n\n");
            fclose(fp);
            return 1;
        }
    }
    printf("\n\n\t\t---------User Not Found----------\n\n");
    fclose(fp);
    return 0;
}

int levelSelector()
{
    int keyPressed = 0;
    int position = 1;
    while(keyPressed != 13)
    {
            system("cls");

            gotoxy(30,13);
            printf("-------------------------------------------------------");

            gotoxy(30,15);
            printf("\t\t"); arrow(1,position); printf("LEVEL 1");
            gotoxy(30,16);
            printf("\t\t");  arrow(2,position); printf("LEVEL 2");
            gotoxy(30,17);
            printf("\t\t"); arrow(3,position); printf("EXIT");

            gotoxy(30,19);
            printf("-------------------------------------------------------");

            keyPressed = getch();

            if(keyPressed == 80 && position != 3)
                position++;
            else if(keyPressed == 72 && position != 1)
                position--;
            else
                position = position;
    }
    return position;
}
