#ifndef GRAPHS_H
#define GRAPHS_H

// Define color
#define BLACK 0
#define DARKBLUE 1
#define DARKGREEN 2
#define DARKCYAN 3
#define DARKRED 4
#define DARKPINK 5
#define DARKYELLOW 6
#define WHITESMOKE 7
#define GRAY 8
#define BLUE 9
#define GREEN 10
#define CYAN 11
#define RED 12
#define PINK 13
#define YELLOW 14
#define WHITE 15
// Define control & func key

// Control key 
#define UP 72
#define DOWN 80

// Func key 
#define ESC 27
#define ENTER 13

// SIZE
#define MID_W 90
#define FULL_W 180

#define MID_H 27
#define FULL_H 45
void gotoxy(int x,int y);
void getxy(int &x,int &y);
void Cursor(bool on);
int GetConsoleWidth();
int GetConsoleHeight();
void resizeConsole(int width, int height);
void setColor(int x);
void setBGColor(WORD color);
void font(int width,int height);
void listColor();
void drawTitle_1(int START_X, int START_Y);
void drawTitle_2(int START_X, int START_Y);
void drawRect(int START_X, int START_Y, int width, int height);
void drawFillRect(int START_X, int START_Y, int width, int height, int color);
void drawText(int x, int y, string text, int color);
void drawBgText(int x, int y, string text, int color = BLACK, int textcolor = WHITE);
void drawNumber(int x, int y, int number, int color);
void drawBgNumber(int x, int y, int number,int color = BLACK, int textcolor = WHITE);
void draw_high_line(int START_X,int START_Y,int height);
void draw_flat_line(int START_X,int START_Y,int width);
void clearRect(int X,int Y,int width,int height);
void frame_not_choose_item(int x, int y, string item_name, int color);
void frame_choose_item(int x, int y, string item_name, int color);
void drawButton(int x, int y, int color, int width, int ascii, string name, string do_what); // ascii or name, chi chon 1 trong 2 cai
void drawFillRectwithText(int START_X, int START_Y, int width, int height, string text, int color);
void setBGColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void drawFillRectwithText(int START_X, int START_Y, int width, int height, string text, int color){
	
}
void gotoxy(int x,int y){
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void getxy(int &x, int&y) {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {	
		x = csbi.dwCursorPosition.X;
		y = csbi.dwCursorPosition.Y;		
	}
}
void Cursor(bool on){
	CONSOLE_CURSOR_INFO info; info.dwSize = 10;
	if (on) info.bVisible = TRUE;
	else info.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}
int GetConsoleWidth(){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    return width;
}
int GetConsoleHeight(){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    return height;
}
void resizeConsole(int width, int height){
	HWND console = GetConsoleWindow(); 
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void setColor(int x){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
}
void font(int width,int height){
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = width;                   // Width of each character in the font
	cfi.dwFontSize.Y = height;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

void listColor(){
	for(int i=0;i<=255;i++){
		setColor(15);
		printf("%3d :",i);
		setColor(i);
		cout <<"This is color"<<endl;
	}
	setColor(15);
}

void GUI_KeyMenu(int &pre, int &cur, bool &arrow_press, bool &esc, bool &enter){
	char c;
	if (kbhit()){
		c = getch();
		if (c == -32 || c == 0){ // nhung~ TH dac biet
	        c = getch();
	        if(c == UP){ 
				pre = cur--;
				arrow_press = true;
	        }
	        if(c == DOWN){ 
	        	pre = cur++;
	            arrow_press = true;
	        }
	    }
	    if (c == ESC) esc = true;
	    if (c == ENTER) enter = true;
	}
}
void drawRect(int START_X, int START_Y, int width, int height){
	int END_X = START_X + width, END_Y = START_Y + height ;
	gotoxy(START_X,START_Y);
	printf("%c",218);
	// Draw left border
	for(int y = START_Y+1; y < END_Y; y++){
		gotoxy(START_X,y);
		printf("%c",179);
	}
	gotoxy(START_X,END_Y);
	printf("%c",192);
	// Draw bottom border
	for(int x = START_X+1; x < END_X; x++){
		gotoxy(x,END_Y);
		printf("%c",196);
	}
	gotoxy(END_X,END_Y);
	printf("%c",217);
	// Draw right border
	for(int y = END_Y-1; y > START_Y; y--){
		gotoxy(END_X,y);
		printf("%c",179);
	}
	gotoxy(END_X,START_Y);
	printf("%c",191);
	// Draw up border
	for(int x = END_X-1; x > START_X; x--){
		gotoxy(x,START_Y);
		printf("%c",196);
	}
}

void drawFillRect(int START_X, int START_Y, int width, int height, int color){
	string r;
	setColor(color*16 + color);
	for(int x = 0 ; x < width ; x++) r.push_back(' ');
	for(int y = START_Y ; y < START_Y + height ; y++){
		gotoxy(START_X,y);
		cout << r;
	}
	setColor(15);
}

void drawText(int x, int y, string text, int color){
	setColor(color);
	gotoxy(x,y);
	cout << text;
	setColor(15);
}
void drawBgText(int x, int y, string text, int bgcolor, int color){
	setColor(color);
	setBGColor(bgcolor);
	gotoxy(x,y);
	cout << text;
	setBGColor(BLACK);
	setColor(WHITE);
	
}
void drawNumber(int x, int y, int number, int color){
	setColor(color);
	gotoxy(x,y);
	printf("%d",number);
	setColor(15);
}
void drawBgNumber(int x, int y, int number, int bgcolor, int color){
	setColor(color);
	setBGColor(bgcolor);
	gotoxy(x,y);
	cout << number;
	setBGColor(BLACK);
	setColor(WHITE);
}

void draw_high_line(int START_X,int START_Y,int height){
	gotoxy(START_X,START_Y);
	printf("%c",194);
	for(int y = START_Y+1; y < START_Y + height; y++){
		gotoxy(START_X,y);
		printf("%c",179);
	}
	gotoxy(START_X,START_Y + height);
	printf("%c",193);
}

void draw_flat_line(int START_X,int START_Y,int width){
	gotoxy(START_X,START_Y);
	printf("%c",195);
	for(int x = START_X + 1; x < START_X + width; x++){
		gotoxy(x,START_Y);
		printf("%c",196);
	}
	gotoxy(START_X+width,START_Y);
	printf("%c",180);
}

void clearRect(int X,int Y,int width,int height){
	for(int y = Y; y <= Y + height; y++){
		for(int x = X; x <= X + width; x++){
			gotoxy(x,y);
			printf(" ");
		}
	}
}

void frame_not_choose_item(int x, int y, string item_name, int color){
	setColor(0);
	drawRect(x,y,30,2);
	gotoxy(x+10,y+1);
	setColor(color);
	cout << item_name;
	setColor(15);
}

void frame_choose_item(int x, int y, string item_name, int color){
	setColor(color);
	drawRect(x,y,30,2);
	gotoxy(x+10,y+1);
	cout << item_name;
	setColor(15);
}

void frame_not_choose_item2(int x, int y, string item_name,int width ,  int color){
	setColor(0);
	drawRect(x,y,width,2);
	gotoxy(x+10,y+1);
	setColor(color);
	cout << item_name;
	setColor(15);
}

void frame_choose_item2(int x, int y, string item_name,int width , int color){
	setColor(color);
	drawRect(x,y,width,2);
	gotoxy(x+10,y+1);
	cout << item_name;
	setColor(15);
}

void drawButton(int x, int y, int color, int width, int ascii, string name, string do_what){
	setColor(color);
	drawRect(x,y, width, 2); // x,y
	// x+2, y+1
	if (name.size() != 0){
		gotoxy(x+width/2-name.size()/2,y+1);
		cout << name;
	}
	if (name.size() == 0){
		gotoxy(x+width/2,y+1);
		printf("%c",ascii);
	}
	gotoxy(x+width+2,y+1); // x+8, y+1
	cout << do_what;
	setColor(15);
	gotoxy(0,0);
}
#endif

