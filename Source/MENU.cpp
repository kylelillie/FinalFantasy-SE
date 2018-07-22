/* Menu for FFSE */
void TextChoice(short int ypoint)
{

if (_getch()==224){
switch(_getch()){
//up

case 'r':
case 72 :{
			ypoint-=2;
			if (ypoint<2)
				{
				ypoint=15;
				gotoxy(65,5);cout<<"  ";
				gotoxy(65,15);cout<<"<-";
				gotoxy(65,15);
				}
			else if (ypoint>3)
				{
			gotoxy(65,ypoint+2);cout<<"  ";
			gotoxy(65,ypoint);
			cout<<"<-";
			gotoxy(65,ypoint-2);cout<<"  ";
			//return pointer to arrow
			gotoxy(65,ypoint);
				}
			break;

			}
//down
case 'c':
case 80 :   {
			ypoint+=2;
			if(ypoint>15){
				ypoint=5;
				gotoxy(65,15);cout<<"  ";
				gotoxy(65,5);cout<<"<-";
				gotoxy(65,5);}

			else if(ypoint<=15){
			gotoxy(65,ypoint-2);cout<<"  ";
			gotoxy(65,ypoint);
			cout<<"<-";
			gotoxy(65,ypoint+2);cout<<"  ";
			//return pointer to arrow
			gotoxy(65,ypoint);}
			break;
		}
}
}
}

void ItemMenu(const Player &Player)
{
//Display total # of Items
gotoxy(3,4);cout<<"Total Items: "<<Player.Items.size();
for(int x=0; x < (int)Player.Items.size(); x++){
gotoxy(3,6+x);cout<<Player.Items[x].name<<"    "<<Player.Items[x].numitems;}
_getch();
gotoxy(3,4);cout<<"                                           ";
gotoxy(3,6);cout<<"                                           ";
};
//------------------------------------------------------------------------------
void StatsMenu(const Player &Player)
{
gotoxy(4,4);cout<<Player.Name<<"     Level "<<Player.Level;

//Draw a line under player's name
for(int line=0; line < (int)Player.Name.size(); line++){
	gotoxy(4+line,5);cout<<"-";}

gotoxy(4,7);cout<<"HP: "<<Player.HP<<"/"<<Player.MHP;
gotoxy(4,8);cout<<"MP: "<<Player.MP<<"/"<<Player.MMP;
gotoxy(4,10);cout<<"Attack: "<<Player.ATK;
gotoxy(4,11);cout<<"Defense: "<<Player.DEF;
gotoxy(4,13);cout<<"Total Exp:  "<<Player.totalexp;
gotoxy(4,14);cout<<"Next Level: "<<Player.nxlvl-Player.exp;
_getch();
for (int clear=4; clear < 16; clear++){
	gotoxy(3,clear);cout<<"                                           ";}

};
//------------------------------------------------------------------------------
void MagicMenu()
{
gotoxy(4,4);cout<<"MAGIC";

gotoxy(4,6);cout<<"Flame";
	gotoxy(5,7);cout<<"- Fire magic attack";

gotoxy(30,6);cout<<"Ice";
	gotoxy(31,7);cout<<"- Ice magic attack";

gotoxy(4,11);cout<<"Bolt";
	gotoxy(5,12);cout<<"- Lighting magic attack";

gotoxy(30,11);cout<<"Cure";
	gotoxy(31,12);cout<<"- Curative magic ";
_getch();
for (int clear=4; clear < 16; clear++){
	gotoxy(3,clear);cout<<"                                                   ";}  
};
//------------------------------------------------------------------------------
void ControlMenu()
{
gotoxy(3,4);cout<<"MOVEMENT";
gotoxy(4,6);cout<<"Up Arrow =  Up";   
gotoxy(4,7);cout<<"Down Arrow = Down";
gotoxy(4,8);cout<<"Right Arrow = Right";
gotoxy(4,9);cout<<"Left Arrow = Left";

gotoxy(3,11);cout<<"SAVING";
gotoxy(4,13);cout<<"On World Map = S";
gotoxy(4,14);cout<<"In Menu      = SAVE";
gotoxy(4,15);_getch();
//Clear Controls
for (int clear=4; clear < 16; clear++){
	gotoxy(3,clear);cout<<"                                           ";}

};

//------------------------------------------------------------------------------
void Menu(const Player &Player)
{
system("cls");
bool Return=false;
bool Exit=false;
bool Item=false, Stats=false, Magic=false, Controls=false, Saved=false; //Selections
int border;

//Display Borders-------------------------------------------->
//Top (border = x-axis)

for (border=2; border < 80; border++){
	gotoxy(border,2);cout<<"_";}

//Bottom  (border = x-axis)
for (border=2; border < 80; border++){
	gotoxy(border,23);cout<<"_";}

//Options Menu------------------------>
//Right Menu Border (border = y-axis)
for (border=3; border < 24; border++){
	gotoxy(62, border);cout<<"|";}

//Bottom Right square
for (border=0; border<17; border++){
	gotoxy(border+63, 20);cout<<"_";}

//------------------------------------------------------------>
//Display Instructions at top
gotoxy(2,1);cout<<"Hit [Enter] or [->] to select option";
//Display Player's Gold
gotoxy(64,22);cout<<"$ "<<Player.gold;

int ypoint=3;
while(!Return){

//Display Menu Options
SetColour(black,white);
gotoxy(68,5);cout<<"ITEMS";
gotoxy(68,7);cout<<"STATS";
gotoxy(68,9);cout<<"MAGIC";
gotoxy(68,11);cout<<"CONTROLS";
gotoxy(68,13);cout<<"SAVE";
gotoxy(68,15);cout<<"EXIT";

//Pointer Movement to select option

if (_getch()==224){
switch(_getch()){
//up

case 'r':
case 72 :{
			ypoint-=2;
			if (ypoint<5){
				ypoint=15;
				gotoxy(65,5);cout<<"  ";
				gotoxy(65,15);cout<<"->";
				gotoxy(65,15);
				}
			else if (ypoint>3){
			gotoxy(65,ypoint+2);cout<<"  ";
			gotoxy(65,ypoint);
			cout<<"->";
			gotoxy(65,ypoint-2);cout<<"  ";
			//return pointer to arrow
			gotoxy(65,ypoint);}
			break;

			}
//down
case 'c':
case 80 :   {
			ypoint+=2;
			if(ypoint>15){
				ypoint=5;
				gotoxy(65,15);cout<<"  ";
				gotoxy(65,5);cout<<"->";
				gotoxy(65,5);}

			else if(ypoint<=15){
			gotoxy(65,ypoint-2);cout<<"  ";
			gotoxy(65,ypoint);
			cout<<"->";
			gotoxy(65,ypoint+2);cout<<"  ";
			//return pointer to arrow
			gotoxy(65,ypoint);}
			break;
		}
//Get Selection Choice
case 'f':
case 13 :
case 77 :  {
			if (Exit){
				Return=true;
				break;}

			if (Item){
				SetColour(blue,white);
				gotoxy(68,ypoint); cout<<"ITEMS";
				ItemMenu(Player);
				break;}

			if (Stats){
				SetColour(blue,white);
				gotoxy(68,ypoint); cout<<"STATS";
				StatsMenu(Player);
				break;}

			if (Magic){
				SetColour(blue,white);
				gotoxy(68,ypoint); cout<<"MAGIC";
				MagicMenu();
				break;}

			if (Controls){
				SetColour(blue,white);
				gotoxy(68,ypoint); cout<<"CONTROLS";
				ControlMenu();
				break;}

			if (Saved){
				SetColour(blue,white);
				gotoxy(68,ypoint); cout<<"SAVE";
				Save(Player,"map");
				gotoxy(65,13);
				break;}
			}

case 27:{
			Return=true;
			}

};//End of Move cursor
};//End if statement
//Determine where curosr is at
switch(ypoint){
case 5:{  Item = true;      Stats=false;     Exit=false;      break; }
case 7:{  Stats = true;     Item=false;      Magic=false;     break; }
case 9:{  Magic = true;     Stats=false;     Controls=false;  break; }
case 11:{ Controls = true;  Magic=false;     Saved=false;     break; }
case 13:{ Saved = true;     Controls=false;  Exit=false;      break; }
case 15:{ Exit = true;      Item=false;      Saved=false;     break; }
};//End Cursor bool

}
system("cls");

}
//------------------------------------------------------------------------------
