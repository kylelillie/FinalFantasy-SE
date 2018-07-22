/* Enemy AI for battles */
//------------------------------------------------------------------------------
void AI_Magic(Player &Player, int &emp, int emhp,int &ehp,string ename,int eatk)
{
short int choice;
int damage=0;

EnemyCasting();

choice=random(8)+1;

if (((ehp/emhp)*100) < 40)
	choice=random(3)+5;

switch(choice){

// Casts Flame  ----------------------------------------------------------------
case 1:
case 2:{
gotoxy(16,18);cout<<ename<<" is casting Fire.";Sleep(700);

if (emp >=4){

	if(eatk > Player.DEF)
	damage=(eatk-Player.DEF)*random(8)+7;
	else
	damage=(Player.DEF-eatk)*random(8)+7;

	EnemyFire();
	gotoxy(16,19);cout<<"Did "<<damage<<" damage.";
	emp-=4;
	Player.HP=-damage;
		if (Player.HP <= 0)
      	Player.GameOver=true;
	}

else {
	gotoxy(16,19);cout<<"Not enough MP";
	_getch();
	}
Sleep(900);
ClearChoices();
choice=random(4)+1;
break;
}

// Casts Strike  ------------------------------------------------------------------
case 3:
case 4:{
gotoxy(16,18);cout<<ename<<" is casting Strike.";Sleep(700);
if (emp >=4){

	if(eatk > Player.DEF)
	damage=(eatk-Player.DEF)*random(8)+7;
	else
	damage=(Player.DEF-eatk)*random(8)+7;

	EnemyStrike();
	gotoxy(16,19);cout<<"Did "<<damage<<" damage.";
	emp-=4;
	Player.HP-=damage;
   	if (Player.HP <= 0)
			Player.GameOver=true;
   system("cls");
	}

else {
	gotoxy(16,19);cout<<"Not enough MP.";
	_getch();
	}
Sleep(900);
ClearChoices();
choice=random(4)+1;
break;
}


// Casts Bolt ------------------------------------------------------------------
case 5:
case 6:{
gotoxy(16,18);cout<<ename<<" is casting Bolt.";Sleep(700);
if (emp >=4){

	if(eatk > Player.DEF)
	damage=(eatk-Player.DEF)*random(8)+7;
	else
   damage=(Player.DEF-eatk)*random(8)+7;

	EnemyBolt();
	gotoxy(16,19);cout<<"Did "<<damage<<" damage.";
	emp-=4;
	Player.HP-=damage;
   	if (Player.HP <= 0)
			Player.GameOver=true;

   system("cls");
	}

else {
	gotoxy(16,19);cout<<"Not enough MP.";
	_getch();
	}
Sleep(900);
ClearChoices();
choice=random(4)+1;
break;
}


// Casts Cure  -----------------------------------------------------------------
case 7:
case 8:{
if (emp >=5){
	damage=0;

	EnemyCure();
	gotoxy(16,18);cout<<ename<<" cast Heal.";Sleep(700);gotoxy(16,19);cout<<"Healed "<<damage<<" HP.";
	emp-=5;
	ehp+=damage;
	}
else{
	gotoxy(16,19);cout<<ename<<" can't cast Heal.";
	Sleep(700);
   }
Sleep(900);
ClearChoices();
choice=random(4)+1;
break;
}
};

}
//------------------------------------------------------------------------------
void AI_Attack(Player &Player, int eatk, string ename)
{
int damage=0;
damage=random(eatk)+(int)((eatk*1.2)+0.5);
gotoxy(16,18);cout<<ename<<" attacked.";Sleep(400);
gotoxy(16,19);cout<<"Did "<<damage<<" damage.";

Player.HP=Player.HP-damage;
	if (Player.HP <= 0)
      	Player.GameOver=true;

Sleep(900);
ClearChoices();
}
//------------------------------------------------------------------------------
void EnemyBattle(Player &Player,int &ehp,int emhp,int &emp,int eatk,int &edef, string ename)
{
 
short int chance;

chance=random(5);

if (chance==0 || chance==2){
	AI_Attack(Player,eatk,ename);
	chance=random(3);
   }

else{
	EnemyCasting();
	AI_Magic(Player,emp,emhp,ehp,ename,eatk);
   }                      
}
//------------------------------------------------------------------------------