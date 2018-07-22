/* 'Behind the Scenes' Functions */

void gotoxy(int x, int y)
{
COORD coord;
coord.X = x; coord.Y = y;

SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void clreol(void)
{

CONSOLE_SCREEN_BUFFER_INFO Info;
GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&Info);

short int length=Info.dwSize.X;
short int x=Info.dwCursorPosition.X;
short int y=Info.dwCursorPosition.Y;

for(int c=x; c<=length; c++){
	gotoxy(c,y);cout<<" ";}

gotoxy(x,y);
}
int  random(int high_value)
{
srand((unsigned)time(0)); 
    int random_integer; 
    int range=(high_value)+1; 

    random_integer = int(high_value*rand()/(RAND_MAX + 1.0)); 
    return(random_integer);     
}
void Replace (string& ModMe, string FindMe, string NewCh)
{
int i=ModMe.find(FindMe, 0);

if (i !=string::npos)
	ModMe.replace(i, FindMe.size(), NewCh);
}
void Display(string sentence,int d)     //sentance==sentence. easy or what?
{										//d refers to how fast the text is displayed

Replace(sentence,"PLAYER",hero);

string letters;                          
int length=sentence.size();                                       

for (int count=0; count<=length; count++){       
	Sleep(d*10);
	letters=letters+sentence.substr(count,1);
	cout<<sentence.substr(count,1);


	_kbhit();                                          
	}
}
void Wait()
{
Sleep(350);
}