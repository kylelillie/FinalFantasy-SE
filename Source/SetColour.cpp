/* Change the text colour */
//Declare global colour variables
short int red=12;
short int yellow=14;
short int blue=9;
short int green=10;
short int pink=13;
short int brown=6;
short int gray=8;
short int white=15;
short int black=0;

void SetColour(int fg, int bg)
{
//White background

	if( bg == white ){
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),fg|
														BACKGROUND_BLUE | 
														BACKGROUND_RED |
														BACKGROUND_GREEN |
														BACKGROUND_INTENSITY);
	};

	if ( bg == green ){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),fg|
														BACKGROUND_GREEN);
	};

	if ( bg == blue ){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),fg|
													BACKGROUND_BLUE);
	};

	if ( bg == yellow ){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),fg|
													BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	};

	if ( bg == black)
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),fg);

}