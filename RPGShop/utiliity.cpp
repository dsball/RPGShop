#include "utility.h"

CONSOLE_SCREEN_BUFFER_INFO csbi;
CONSOLE_SCREEN_BUFFER_INFO initconfig;

HANDLE hstdin  = GetStdHandle( STD_INPUT_HANDLE  );
HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
WORD   index   = 0;


//replace system("PAUSE")
void pause()
{
	cout<<"Press Enter to continue...";
	cin.clear();
	cin.sync();
	cin.get();
}

//replace clearScreen()
void clearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };
	

	hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(hStdOut, (TCHAR) ' ', cellCount, homeCoords, &count)) 
	{
		return;
	}

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount, homeCoords, &count)) 
	{
		return;
	}

	/* Move the cursor home */
	SetConsoleCursorPosition( hStdOut, homeCoords );
}

//opens a file and prints it with fileToString()
bool printFile(string inFile)
{
	ifstream splashFile;
	clearScreen();
	splashFile.open(inFile);
	if(splashFile.fail())
	{
		return false;
	}
	cout << fileToString(splashFile);
	splashFile.close();
	return true;
}

//stores an ifstream in a string and returns it
string fileToString(ifstream &inFile)
{
	string printMe = "";
	string temp;

	if(inFile)
	{
		while(inFile.good())
		{
			getline(inFile, temp);
			temp += "\n";
			printMe += temp;
		}
	}
	else
	{
		cout<<"No input detected!";
	}

	clearScreen();
	return printMe;

}

void colorset(WORD myColors)
{
	SetConsoleTextAttribute(hstdout, myColors );
}

void cursorpos( int x, int y )
{
    COORD p = { x, y };
    SetConsoleCursorPosition( hstdout, p );
}

string intToStr(int convertMe)
{
	stringstream ss;
	ss<<convertMe;
	return ss.str();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//THIS CODE IS FROM http://www.3dbuzz.com/vbforum/showthread.php?102195-How-do-you-resize-a-console-window-in-C //
// It is used to rezise the console and returns false if resizing failed. **I modified the code to not have     //
// multiple returns.**																							//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool SetWindow(int Width, int Height) 
{ 
	bool success = true;
	_COORD coord; 
	coord.X = Width; 
	coord.Y = Height; 

	_SMALL_RECT Rect; 
	Rect.Top = 0; 
	Rect.Left = 0; 
	Rect.Bottom = Height - 1; 
	Rect.Right = Width - 1; 

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE); 
	if (Handle == NULL) 
	{ 
		cout<<"Failure in getting the handle\n"<<GetLastError(); 
		success = false; 
	} 

	if(!SetConsoleScreenBufferSize(Handle, coord)) 
	{ 
		cout<<"Failure in setting buffer size\n"<<GetLastError(); 
		success = false; 
	} 

	if(!SetConsoleWindowInfo(Handle, TRUE, &Rect)) 
	{ 
		cout<<"Failure in setting window size\n"<<GetLastError(); 
		success = false;  
    } 
	return success; 
} 