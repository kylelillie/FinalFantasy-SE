/* Animation classes */

void ShowWalkingEast()
{
int x=5,count=0;

for (double c=1; c<=900000; c++);
gotoxy(9,13);cout<<"--------------------------------------------------"<<endl;
for (x=5; x<=53; x++){
count++;


Sleep(55);
gotoxy(9,8);cout<<"--------^^^---^^^^^^^^^^---^^---^^-^^^^^^^^-^^--^^"<<endl;
gotoxy(x,10);cout<<" O"<<endl;

gotoxy(x-1,11);cout<<" /|\\/"<<endl;
if (count%2==0){
	gotoxy(x,12);cout<<" /\\"<<endl;}

else {
	gotoxy(x,12);cout<<" |"<<endl;}

if (_kbhit())
	break;
}
for (int c=1; c<=800000; c++);
system("cls");

}
void ShowWalkingWest()
{
int x=53,count=0;
_getch();
for (double c=1; c<=2000000; c++);
gotoxy(9,13);cout<<"--------------------------------------------------"<<endl;

for (x=53; x>=11; x--){
count++;


Sleep(50);
gotoxy(9,10);cout<<"--------^^^---^^^^^^^^^^---^^---^^-^^^^^^^^-^^--^^"<<endl;
gotoxy(x+1,10);  cout<<"O "<<endl;
gotoxy(x-1,11);  cout<<"\\/|\\ "<<endl;

if (count%2==0){
	gotoxy(x,12);cout<<"/\\ "<<endl;}

else {
	gotoxy(x+1,12);cout<<"| "<<endl;}

if (_kbhit())
	break;
}
for (int c=1; c<=2000000; c++);
_getch();
system("cls");
}
void ShowWalkingNorth()
{
 
int y=15,count=0,x;
x=random(4)+1;


for (int height=23; height>=8; height--){
		gotoxy(20,height);cout<<"|                          |"<<endl; }
gotoxy(20,20);cout<<"<";gotoxy(20,19);cout<<"<";gotoxy(20,10);cout<<"<";
gotoxy(47,16);cout<<">";gotoxy(47,23);cout<<">";

for (y=21; y>=11; y--){
count++;

if (count%2==0){
	gotoxy(30,y-2);cout<<"O   "<<endl;
	gotoxy(29,y-1);cout<<"'|  "<<endl;
	gotoxy(30,y);  cout<<" \\"<<endl;
	gotoxy(29,y+1);cout<<"   "<<endl;
	gotoxy(29,y+2);cout<<"   "<<endl;}

else {
	gotoxy(30,y-2);cout<<"O  "<<endl;
	gotoxy(30,y-1);cout<<"|' "<<endl;
	gotoxy(29,y);  cout<<"/  "<<endl;
	gotoxy(29,y+1);cout<<"   "<<endl;
	gotoxy(29,y+2);cout<<"     "<<endl;}

Sleep(50); //walking speed

if (_kbhit())
	break;
}
	if (x%2==0){
	gotoxy(30,8);cout<<"O / \"Goin North!\""<<endl;
	gotoxy(29,9);cout<<"'|' "<<endl;
	gotoxy(29,10);cout<<" /\\"<<endl;}

	else
		//do nothing

for (double c=1; c<=800000; c++);
gotoxy(62,6);_getch();
system("cls");

}
void ShowWalkingSouth()
{
 
int y=15,count=0,x;
x=random(4)+1;


for (int height=23; height>=8; height--){
	gotoxy(20,height);cout<<"|                          |"<<endl; }
gotoxy(20,20);cout<<"<";gotoxy(20,19);cout<<"<";gotoxy(20,7);cout<<"<";
gotoxy(47,13);cout<<">";gotoxy(47,23);cout<<">";

for (y=9; y<=21; y++){
count++;

if (count%2==0){
	gotoxy(30,y-3);cout<<"   "<<endl;
	gotoxy(30,y-2);cout<<"O   "<<endl;
	gotoxy(29,y-1);cout<<"'|  "<<endl;
	gotoxy(30,y);  cout<<" \\"<<endl;
	gotoxy(29,y+1);cout<<"   "<<endl;
	gotoxy(29,y+2);cout<<"   "<<endl;}

else {
	gotoxy(30,y-3);cout<<"   "<<endl;
	gotoxy(29,y-2);cout<<" O  "<<endl;
	gotoxy(30,y-1);cout<<"|' "<<endl;
	gotoxy(29,y);  cout<<"/  "<<endl;
	gotoxy(29,y+1);cout<<"   "<<endl;
	gotoxy(29,y+2);cout<<"     "<<endl;}

Sleep(50); //walking speed

if (_kbhit())
	break;
}
	if (x%2==0){
	gotoxy(30,19);cout<<"O / \"Goin South!\""<<endl;
	gotoxy(29,20);cout<<"'|' "<<endl;
	gotoxy(29,21);cout<<" /\\"<<endl;}

	else
		//do nothing

for (double c=1; c<=800000; c++);
gotoxy(62,6);_getch();
system("cls");

}

/* Battle Animations */

void ShowAttack()
{

int x,count=0;

for (x=16; x<=26; x++){
	count++;

	Sleep(50);
		if (count%2==0){
			gotoxy(x-1,11); cout<<" \\ O ";
			gotoxy(x,12);cout<<" '|";
			gotoxy(x,13);cout<<"  | ";
			_kbhit(); }
		else{
			gotoxy(x-1,11); cout<<" \\ O ";
			gotoxy(x,12);cout<<" '|";
			gotoxy(x,13);cout<<"  /\\ ";
			_kbhit(); }
		}

SFX(Sword);
gotoxy(26,11); cout<<"  O /";
gotoxy(27,12); cout<<" |' ";
gotoxy(28,13);  cout<<"/\\";
Wait();
gotoxy(25,11);clreol();
gotoxy(25,12);clreol();
gotoxy(25,13);clreol();
}
void ShowPlayer(int x, int y)
{
gotoxy(x,y);cout<<" O / "<<endl;
gotoxy(x,y+1);cout<<"/|'"<<endl;
gotoxy(x,y+2);cout<<" /\\"<<endl;
}

void MovePlayer(short int &x, short int &y, short int &c)
{

if (_getch() == 224)
{
	switch(_getch())
	{
	case 77: 
		x++; 
		c++; 
		
		if ( c%2 == 1 )
		{	
			gotoxy(x-1,y-1);cout<<"  O  ";
			gotoxy(x-1,y);cout<<" /|\\ ";
			gotoxy(x-1,y+1);cout<<"  |  ";		 
		}
		else
		{	
			gotoxy(x-1,y-1);cout<<"  O  ";
			gotoxy(x-1,y);cout<<" /|\\ ";
			gotoxy(x-1,y+1);cout<<"  /\\ "; 
		}
		
		break;

	case 75: 
		x--; 
		c++; 
		
		if ( c%2 == 1 )
		{	
			gotoxy(x,y-1);cout<<"  O ";
			gotoxy(x,y);cout<<" /|\\ ";
			gotoxy(x,y+1);cout<<"  |  ";		 
		}
		else
		{	
			gotoxy(x,y-1);cout<<"  O ";
			gotoxy(x,y);cout<<" /|\\ ";
			gotoxy(x,y+1);cout<<"  /\\ "; 
		}
		
		break;

	case 72:

		if ( x == 8 )//Kim-chi master
		{
		gotoxy(19,18);clreol();
		gotoxy(19,19);clreol();

		gotoxy(19,18);cout<<"Kim-chi Master: ";Display("To master the way of the Kim-chi,",4);
		gotoxy(35,19);Display("seek the round treasure of the Dungeon.",4);
		_getch();

		gotoxy(19,18);clreol();
		gotoxy(19,19);clreol();
		}

		if ( x == 20 )//House
		{
		gotoxy(19,18);clreol();
		gotoxy(19,19);clreol();

		gotoxy(19,18);cout<<"Resident: ";Display("Get out of my house!",4);
		_getch();

		gotoxy(19,18);clreol();
		}

		if ( x == 36 )//Inn
		{
		gotoxy(19,18);clreol();
		gotoxy(19,19);clreol();

		gotoxy(19,18);cout<<"Inn Keeper: ";Display("Would you like to rest or save?",4);
		gotoxy(31,19);cout<<"Rest ";
		gotoxy(31,20);cout<<"Save ";
		_getch();

		gotoxy(19,18);clreol();
		gotoxy(19,19);clreol();
		gotoxy(19,20);clreol();
		}

		
		if ( x == 52 )//Shop
		{
		gotoxy(19,18);clreol();
		gotoxy(19,19);clreol();
		
		char choice;

		gotoxy(19,18);cout<<"Shop Keeper: ";Display("Sorry, we don't serve your kind.",4);
		gotoxy(19,19);cout<<"A- Mind your own buisness and leave";
		gotoxy(19,20);cout<<"S- Pick a fight with the owner       : ";
		cin>>choice;

			if (choice=='A'||choice=='a')
			{
				 gotoxy(16,11);clreol();Display("PLAYER left the store.",1);
				 Sleep(700);
				 system("cls");
			}

			else if (choice=='S'||choice=='s')
			{
				gotoxy(16,9);clreol();
				Display("PLAYER: Predjudiced jerk! Bring it on!",1);Sleep(700);
				system("cls");
				SFX(Engage);
				//Battle(Player,1,"Store Owner");
			}

		gotoxy(19,18);clreol();
		gotoxy(19,19);clreol();
		}

		break;
	};
		
	}
	
Sleep(30);
}