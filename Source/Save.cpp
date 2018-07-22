void Save(Player Player, string location)
{
	char s;
	bool saved=true;
	gotoxy(19,4);cout<<"Save[Y/N]? ";
	cin>>s;
	if (s=='y' ||s=='Y'){
	ofstream SaveFile;
	SaveFile.open("Saved.xse");
	SaveFile<<Player.Name<<endl; //0
	SaveFile<<location<<endl; //1
	SaveFile<<Player.checkpoint<<endl;
	SaveFile<<Player.HP<<endl; //2
	SaveFile<<Player.MHP<<endl; //3
	SaveFile<<Player.MP<<endl; //4
	SaveFile<<Player.MMP<<endl; //5
	SaveFile<<Player.ATK<<endl; //6
	SaveFile<<Player.DEF<<endl; //7
	SaveFile<<Player.Level<<endl; //8
	SaveFile<<Player.exp<<endl; //9
	SaveFile<<Player.gold<<endl; //10
    SaveFile<<Player.nxlvl<<endl; //11
	SaveFile<<Player.X<<endl; //12
	SaveFile<<Player.Y<<endl; //13

	SaveFile.close();

	gotoxy(19,4);cout<<"              ";
	gotoxy(19,4);cout<<"Saved"<<endl;
	_getch();
	gotoxy(19,4);cout<<"     ";}

	else{
	gotoxy(19,4);cout<<"              ";}

}
void EraseSave(void)
{
	char save;
	system("cls");
	gotoxy(18,10);Display("Previous game will be erased.",3);
	gotoxy(18,11);cout<<"Delete save? ";
	cin>>save;
	system("cls");
	switch(save){
	case 'y':
	case 'Y':{
		remove("Saved.xse");
		system("cls");
		gotoxy(18,10);cout<<"Your save file has been deleted.";
		break;
			}
	default:{
		system("cls");
		gotoxy(18,10);cout<<"Save file retained.";
		}}

	_getch();
   system("cls");
}
bool Continue(char &save,Player &Player)
{
ifstream Load("Saved.xse",ios::in);

if (Load.fail()){
	gotoxy(31,13);cout<<"No Saved Data";
	_getch();
	gotoxy(31,13);clreol();
	return(false);
	}

else{

system("cls");
int check=0;

vector <string> Strings(3);
vector <int>    data(12);

getline(Load,Strings[0]);
getline(Load,Strings[1]);
getline(Load,Strings[2]);

for (int x=0; x<=11; x++)
	{
	Load>>data[x];
	}

//Load Data into Player
Player.Name=Strings[0];
Player.location=Strings[1];
Player.checkpoint=Strings[2];

Player.HP=data[0];
Player.MHP=data[1];
Player.MP=data[2];
Player.MMP=data[3];
Player.ATK=data[4];
Player.DEF=data[5];
Player.Level=data[6];
Player.exp=data[7];
Player.gold=data[8];
Player.nxlvl=data[9];
Player.X=data[10];
Player.Y=data[11];

Player.saved=true;

Load.close();

system("cls");
return(true);}
}