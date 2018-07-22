/* an attempt at a crappy map */
void RandomBattle(Player &Player,const EName &Enemies)
{

SFX(Engage);

int enemy=random(Enemies.size());

gotoxy(30,10);cout<<Player.Name<<" was attacked!"<<endl;
Sleep(1000);
system("cls");
	
Battle(Player,1,Enemies[random(Enemies.size())]);

system("cls");

MapPlayer(Player,Enemies);
}
//------------------------------------------------------------------------------
void DrawMap()
{
	int x;

	gotoxy(20,2);cout<<"Cavern";
	SetColour(white,black);
	gotoxy(22,3);cout<<" ";

	SetColour(brown,white);

	for (x=0; x<=68; x++){
		gotoxy(x+2,1);cout<<"-";
		gotoxy(x+2,24);cout<<"-";}

	SetColour(black,white);

	gotoxy(53,10);cout<<"Stickleton";

	SetColour(brown,white);

	gotoxy(52,12);cout<<"/\\  /\\_/\\";
	gotoxy(52,13);cout<<"||  |   |";
	gotoxy(52,14);cout<<"--  ------";

	SetColour(black,white);

};
//------------------------------------------------------------------------------
void Move(Player &Player)
{

_getch();

if( _getch() == 224 )  //Maybe some arrow key pressed
        {
			switch(_getch())
			{

			case 75:
						Player.X--;
						Player.Y=Player.Y;
						break;
			case 72:
						Player.X=Player.X;
						Player.Y--;
						break;

			case 77:
						Player.X++;
						Player.Y=Player.Y;
						break;

			case 80:
						Player.X=Player.X;
						Player.Y++;
						break;
		
	}
}

gotoxy(Player.X,Player.Y-1);cout<<" ";
gotoxy(Player.X,Player.Y+1);cout<<" ";
gotoxy(Player.X-1,Player.Y);cout<<" ";
gotoxy(Player.X+1,Player.Y);cout<<" ";

gotoxy(Player.X,Player.Y);cout<<"!";

};

//------------------------------------------------------------------------------
void Limits(Player &Player, bool &town, bool &dungeon)
{
if (Player.X == 71) //Right most
	{
	Player.X=70;
	gotoxy(Player.X+1,Player.Y);cout<<" ";
	}

if (Player.X == 0) //Left most
	{
	Player.X=1;
	gotoxy(Player.X-1,Player.Y);cout<<" ";
	}

if(((Player.X>=52)&&(Player.X<=56))&&((Player.Y==12)||(Player.Y==13)||(Player.Y==14)))
	town=true;//Break to the Town

}
//------------------------------------------------------------------------------
void MapPlayer(Player &Player,const EName &Enemies)
{
	Player.location="map";
	Play(Map);

	int steps=0;
	bool town=false, dungeon=false;

while (!town || !dungeon)
{

if (steps>=35)
	steps=0;

if (steps==random(9)+20)
	{
		FMUSIC_StopSong(mod);
		FMUSIC_FreeSong(mod);
		FSOUND_Close();
		RandomBattle(Player,Enemies);
	}

if (Player.GameOver)
		break;
if (town)
	break;

Move(Player);

switch(_getch())
{
case 'p':
case 'P':
case 32:{
			Menu(Player);
			break;
		}
case 's':
case 'S':
case  13:{
			Save(Player,"map");
			gotoxy(19,4);clreol();
			break;
		 }

}; //End Switch

Limits(Player, town, dungeon);

DrawMap();

steps++;

}//End While(town, dungeon)
		FMUSIC_StopSong(mod);
		FMUSIC_FreeSong(mod);
		FSOUND_Close();
}
//---------------168 Lines of Code-----------------------------------------------