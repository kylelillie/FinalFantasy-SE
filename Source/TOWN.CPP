/* The first (and only?) town */

void TownChoices(short int x)
{

gotoxy(19,18);

if ( x == 8 ){
	cout<<"[UP] Talk to the Kim-chi Master";Sleep(50);}

else if ( x == 20 ){
		cout<<"[UP] Go into the house";Sleep(50);}

else if ( x == 36 ){
		cout<<"[UP] Go into Inn";Sleep(50);}

else if ( x == 52){
		cout<<"[UP] Go into Shop";Sleep(50);}
	else{
		gotoxy(19,18);clreol();
	}
}
void DrawTown()
{

SetColour(yellow,yellow);

gotoxy(50,2);cout<<"   ";
gotoxy(50,3);cout<<"   ";

SetColour(black,white);

gotoxy(5,7); cout<<" ^           ______         _________        _______   ";
gotoxy(5,8); cout<<"/|\\         /      \\       /   INN    \\    /  SHOP   \\      ^";
gotoxy(5,9); cout<<"/|\\         |      |       |          |    |         |     /|\\";
gotoxy(5,10);cout<<"/|\\         |      |       |          |    |         |     /|\\";

SetColour(white,black);

gotoxy(20,10);cout<<" ";
gotoxy(36,10);cout<<" ";
gotoxy(52,10);cout<<" ";

SetColour(brown,white);

gotoxy(5,11);cout<<"-------------------------------------------------------------------";
gotoxy(5,17);cout<<"-------------------------------------------------------------------";
SetColour(black,white);

gotoxy(10,9);cout<<"Q";
gotoxy(9,10);cout<<"/|\\";
gotoxy(10,11);cout<<"/\\";
}
void Town(Player &Player)
{

Player.location="town";
DrawTown();

	if (Player.checkpoint == "ckF")
	{
		gotoxy(20,9);Display("PLAYER entered Stickleton and....",5);
		Sleep(500);
		system("cls");
	}



/* Add to the dungeon 
		gotoxy(20,9);Display("found a mysterious ball, that was like water",5);
		gotoxy(20,10);Display("but a solid..",5);
		Player.KeyItems.resize(Player.KeyItems.size()+1);
		Player.KeyItems[0].name="Aqua Sphere";Player.KeyItems[0].num=1;
		_getch();system("cls");
	}
*/
char choice;
bool leave=false;
short int count=1;
short int x=6,y=14,c=0;

while (!leave)
{
	if ( x == 1)
		leave = true;

	MovePlayer(x,y,c);
	TownChoices(x);

/*	
	
	if (choice=='D'||choice=='d'){  //Pick a Fight
		system("cls");gotoxy(15,9);cout<<Player.Name<<" picked a fight!!";
		Battle(Player,1,"Punk Kid"); }

	else if (choice=='a'||choice=='A'){  //Enter the Inn
		system("cls");gotoxy(15,7);Display("PLAYER went into the Inn.",1);Sleep(900);
		gotoxy(15,8);Display("Rest [100 G] or Save: ",1);
		cin>>choice;

		if (choice=='r'||choice=='R'){
		gotoxy(15,8);clreol();gotoxy(15,8);Display("HP/MP Restored!",1);Sleep(900);
		Player.HP=Player.MHP;
		Player.MP=Player.MMP;
		Player.gold-=100;}

		else if (choice=='s'||choice=='S'){
		Save(Player,"town");}
		system("cls");
		}
		
	else if (choice=='f'||choice=='F')
		leave=true;
		break;*/
};

system("cls");

Player.X=48;
Player.Y=13;
}