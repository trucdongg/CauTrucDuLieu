// Control key 
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

// Func key 
#define ESC 27
#define ENTER 13
#define BACKSPACE 8

#define NB01 49
#define NB02 50
#define NB03 51
#define NB04 52
#define NB05 53
#define NB06 54

#define F12 -122


void KeyPress_1(int &cur, int &from, int &to, int &page, int maxlen, bool &reload, bool &press, bool &move, bool &esc);
void KeyPress_2(int &cur, int &pre, int &from, int &to, int &page, int maxlen, bool &press, bool &move, bool &esc, bool &enter);
void KeyPress_3(int &cur, int &from, int &to, int &page, int maxlen, bool &reload, bool &press, bool &move, bool &esc);


void InputString(int x, int y, int x_e, int y_e, int len, string &tmp, bool check_0_9, bool &esc);
void InputDate(int x, int y, NG &now ,NG base, bool hr_min =true);
void InputPasswd(int x, int y, int x_e, int y_e, int len, string &tmp, bool check_0_9, bool &esc, bool &move);
void InputGender(int x, int y, bool &gender, bool &esc);
void InputNumber(int x, int y, int x_e, int y_e, int &var, int maxlen, bool onetoten, bool &esc);
int InputNumber2(int x, int y, int var, int above , int bellow , int maxlen , int color , int textcolor , bool &esc, bool check_abbl = false);

void RemoveSpace(string &tmp,bool athead);
void ToUpper(string &tmp);

bool file_exist(const char *link);
bool Yes();
void Pause();
bool check_max_length(string tmp, int length);

void KeyPress_1(int &cur, int &from, int &to, int &page, int maxlen, bool &reload, bool &press, bool &move, bool &esc){
	char c; // Lay ds mon hoc lam` vi du.
	c = getch();
	if (c != 0){
//		c = getch();
		if (c == NB01){ // F1: Them
			cur = 1; press = true;
		}
		if (c == NB02){ // F2: Dieu Chinh
			cur = 2; press = true;
		}
		if (c == NB03){ // F3: Xoa 
			cur = 3; press = true;
		}
		if (c == NB04){ // F4: Tim 
			cur = 4; press = true;
		}
		if (c == NB05){ // F5:
			cur = 5; press = true;
		}
		if (c == NB06){ // F6
			cur = 6; press = true;
		}
	}
	if (c == -32){
		c = getch();
		if (c == LEFT){ // left arrow - Lui
			if (from != 0){ // Neu from = 0 thi` ko can` phai~ chuyen~ trang
				move = true;
				to = from;
				page--;
			}
			if (from - 10 < 0){ // Neu dang o~ trang dau tien thi` ko can` phai~ thay doi~ thong so
				from = 0;
			}
			else from -= 10;
		}
		if (c == RIGHT){ // right arrow - Tien
			if (to != maxlen){ // Neu to van~ con` co` the~ tien toi thi` tiep tuc 
				move = true;
				from = to;
				page++;
			} 
			// vd: from = 0, to = 10, in ra array tu 0->9, thi minh chi can gan from = to se` in ra bat dau o ptu~ 10
			if (to + 10 > maxlen){ // Neu to+10 > do dai ds thi` set to = max length cua~ ds
				to = maxlen;
			}
			else to += 10; // neu ko thi` to += 10
		}
	}
	if (c == ESC) esc = true;
	
}

void KeyPress_3(int &cur, int &from, int &to, int &page, int maxlen, bool &reload, bool &press, bool &move, bool &esc){
	char c; 
	c = getch();
	if (c != 0){
//		c = getch();
		if (c == NB01){ // F1: Them
			cur = 1; press = true;
		}
		if (c == NB02){ // F2: Dieu Chinh
			cur = 2; press = true;
		}
		if (c == NB03){ // F3: Xoa 
			cur = 3; press = true;
		}
		if (c == NB04){ // F4: Tim 
			cur = 4; press = true;
		}
		if (c == NB05){ // F5:
			cur = 5; press = true;
		}
		if (c == NB06){ // F6
			cur = 6; press = true;
		}
	}
	if (c == -32){
		c = getch();
		if (c == LEFT){
			// maxlen = 25 
			
			// Neu to = 15 va from = 5 
			// if to + 10 <= maxlen => to = 25; from = 15 <= 0 ? 0
			
			// Neu to = 25 va from = 15 
			// if to + 10 > maxlen => Giu nguyen  
			
			// Neu to = 5 va from = 0 
			// if to + 10 > maxlen => Giu nguyen 
			
			// Neu to = 10 va from = 0
			// if to + 10 > maxlen => Giu nguyen
			
			if( to + 10 <= maxlen){
				from = to;
				to = to + 10 >= maxlen? maxlen : to + 10 ;
				move = true;
				press = true;
				page--;	
			}	
			
		}
		// Luc dau to = maxlen && from = to - 10
		if (c == RIGHT){ 
			
			// Neu to = 15 va from = 5 
			// if to - 10 >= 0 => to = 5; from = 5 - 10 <= 0 ? 0
			
			// Neu to = 25 va from = 15 
			// if to - 10 >= 0 => to = 15; from = 5  
			
			// Neu to = 5 va from = 0 
			// if to -10 >= 0 => Giu nguyen from va to  
			
			if( to > 10){
				to = from;
				from = to - 10 <= 0? 0 : to - 10 ;
				move = true;
				press = true;
				page++;	
			}	
		}
	}
	if (c == ESC) esc = true;
	
}

void KeyPress_2(int &cur, int &pre, int &from, int &to, int &page, int maxlen, bool &press, bool &move, bool &esc, bool &enter){
	char c; 
	c = getch();
	if (c == -32){
		c = getch();
		if (c == LEFT){ // left arrow - Lui
			if (from != 0){ // Neu from = 0 thi` ko can` phai~ chuyen~ trang
				move = true;
				to = from;
				page--;
			}
			if (from - 10 < 0){ // Neu dang o~ trang dau tien thi` ko can` phai~ thay doi~ thong so
				from = 0;
			}
			else from -= 10;
		}
		if (c == RIGHT){ // right arrow - Tien
			if (to != maxlen){ // Neu to van~ con` co` the~ tien toi thi` tiep tuc 
				move = true;
				from = to;
				page++;
			} 
			// vd: from = 0, to = 10, in ra array tu 0->9, thi minh chi can gan from = to se` in ra bat dau o ptu~ 10
			if (to + 10 > maxlen){ // Neu to+10 > do dai ds thi` set to = max length cua~ ds
				to = maxlen;
			}
			else to += 10; // neu ko thi` to += 10
		}
		if (c == UP){ // up arrow
			pre = cur--; press = true;
		}
		if (c == DOWN){ // down arrow
			pre = cur++; press = true;
		}
	}
	if (c == ESC) esc = true;
	if (c == ENTER) enter = true;
}

void InputPasswd(int x, int y, int x_e, int y_e, int len, string &tmp, bool check_0_9, bool &esc, bool &move){
	Cursor(true);
	char c; bool max = false, empty = false; 
	gotoxy(x,y);
	x = x - tmp.size(); 
	// Cai nay dung cho phan` edit, vi` khi edit string tmp co gia tri. vd: khi nhap 1 sv moi chang~ han. thi` tmp.size = 0
	// va` x gui~ vo la` 5 (Diem bat dau ghi cua~ con tro~), thi` khi báo loi~ con tro~ se~ nhay~ lai. cho~ cu~ 5+len=5+40=45. 
	// Nhung neu cho tmp = "duc" thi` khi gui~ vao` x = 8 de~ cho con tro vi tri hien tai. sau chu~ "duc"
	// va` neu bao loi~ = 8 + 40 = 48 la` sai, vi` cho~ cu~ mac dinh la` 45. Nen ta phai~ cho 8 - tmp.size = 8-3 = 5
	string e1 = "KHONG DUOC BO TRONG";
	string e2 = "KHONG THE NHAP DUOC NUA";
	while(true){
		c = getch();
		if (c == ENTER){ // enter - bao loi khong duoc bo trong
			if (tmp.size() > 0) break;
			else{
				empty = true;
				drawText(x_e - e1.size()/2,y_e,e1,RED);
				gotoxy(x,y); // vi bo~ trong thi` chi~ can tro lai vi tri ban dau
			}
		}
		if (c == BACKSPACE){ // backspace - xóa 
			if (tmp.size() != 0){
//				tmp.replace(tmp.size()-1,1,""); // Uncomment dong` nay` neu ban. chua~ them '-std=c++11'
				tmp.erase(tmp.size()-1,1);		// erase cung~ co the xoa string
//				tmp.pop_back(); 				// Neu bao loi~ dung` lenh tren
				printf("\b \b");
				// Khi dang o~ trang. thái string maxlen thì khi xóa di kí tu cuoi cùng, thì se~ xóa báo loi~
				if (max){ // khi xoa di thi` xoa dong bao loi~
					clearRect(x_e - e2.size()/2,y_e,e2.size(),1); // xoa bao loi~
					gotoxy(x+tmp.size(),y); // tro ve cho~ bi xoa
					max = false;
				}
			}
		}
		if (c == ESC){ // escape = back
			esc = true;
			clearRect(x_e - 20,y_e,40,1); // xoa bao loi~
			return;
		}
		if (c == -32 || c == 0){ // da~ fix dc BUG gay bat phim arrow
			c = getch();
			if (c == UP){
				move = true;
				return ;
			}
			else continue;
			// trong if nay`, ta de~ them 1 dong` c = getch() la` vi` neu c == -32 or 0 thi` nó se~ tu. dong. getch them 1
			// lan nua~ khi lap lai. vong loop nay` va` cai c = getch() o~ dau` se~ bat nham` phím => gay loi~
		}
		if(!check_max_length(tmp,len)){ // Neu string này chua dat. toi gioi han. max thì se~ tiep tuc. push_back 
			if (c != BACKSPACE && c != ENTER && c >= 32){ 
			// nut backspace && enter no cung~ pusb_back dc,và nhung~ ki tu nho~ hon 32 
			// se~ lam` sai dieu kien bao loi va` in sai 
				if (!check_0_9){ // Neu ko kich hoat che do nhap string kieu number thì có the nhap toan bo ki tu vào
					if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9'){ // 32 = SPACE
						// ko dc nhap ki tu dac biet nhu ; . ' " ? /
						tmp.push_back(c);
						printf("*");	
					}
					if (c == 32 && tmp.size() > 0){
						tmp.push_back(c);
						printf("*");
					}
				}
				//!check_0_9 && c >= '0' && c <= '9' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'
				else{
					if (c >= '0' && c <= '9'){
						tmp.push_back(c);
						printf("*");
					}
				}
				if (empty){ // vi` khi nhap 1 ki tu nao` do thi` no se~ tu dong xoa bao loi empty di
					empty = false;
					clearRect(x_e - e1.size()/2,y_e,e1.size(),1);
					if (tmp.size() != 0) gotoxy(x+1,y);
					else gotoxy(x,y); 
					// x+1 la` vi` khi tmp.size() = 0, thi` khi 1 char duoc push vao`, thi` tmp.size() = 1
					// dong nghia voi viec 1 ki tu duoc in ra, va` ki tu do duoc ghi o~ (x,y)
				} // lam nhu the nay` de~ no clearRect 1 lan thoi
			}
		}
		else { // Khi string da~ du~ do. dài mà còn nhap. them thì se~ kich hoat. báo loi~ max = true
			max = true;
			drawText(x_e - e2.size()/2,y_e,e2,RED);
			gotoxy(x+len,y); // (10+1+17) la cai x co dinh, + len la vi tri max o cuoi string
		}
		
	}
	clearRect(x_e - 20,y_e,40,1); // xoa tat ca~ thong bao loi~
	Cursor(false);
}

int InputNumber2(int x, int y, int var, int above  , int bellow , int maxlen ,  int color , int textcolor, bool &esc , bool check_abbl){
	// 22_ con tro se o day
	// 1_ con tro se o day x-=1
	int len = ( var == 0 ? 1: 1+ floor(log10(var)) ); 	
	gotoxy(x,y);
	// Clear dong do di ( clear 2 so )
	clearRect(x,y,1,1);
	Cursor(true);
	// Luu lai gia tri ban dau
	int first_var = (var >= bellow)? bellow: var;
	first_var = (var <= above)? above : var;
	// Format de hien thi so 1 -> "01"
	string format = "";
	// To mau voi mau bg = CYAN (default)
	drawBgNumber(x,y,var,color,textcolor);
		
	// Loop 
	char c;
		// Neu do dai lon nhat khong co => return
		if(maxlen == 0) return 0;
		setColor(textcolor);
		setBGColor(color);
	while(true){
		c = getch();
		if( c == -32 || c == 0){
			c = getch();
			// Normal
			setColor(WHITE);
			setBGColor(BLACK);
			
			clearRect(x,y,1,1);
			
			// Highlight
			setColor(textcolor);
			setBGColor(color);
			// + Tang giam bang nut len xuong 
			if(c == UP){
				// Var < toi da 
				if(var < bellow){
					var++;
					gotoxy(x,y);
					printf("%d",var);
					// Fix loi hien thi khi var = toi da
				}else if(var == bellow){
					gotoxy(x,y);
					printf("%d",var);
				}
			}
			if(c == DOWN){
				// Var > toi thieu 
				if(var > above){
					var--;
					gotoxy(x,y);
					printf("%d",var);
					// Fix loi hien thi khi var = toi thieu
				}else if(var == above){
					gotoxy(x,y);
					printf("%d",var);
				}
			}
		}
		if (c == BACKSPACE && len > 0) { // Backspace - xóa. Neu var != 0, vd var = 85 -> var = int(85/10) = 8, do dài giam~
				var /= 10; len--;
				printf("\b \b");
		}

		if (c >= '0' && c <= '9' && len < maxlen){ // Bam phim 8 và var = 0 -> var = 0*10 + 8 = 8
				var = var * 10 + (int(c) - 48);
				len++; // Bam phim 5 và var = 8 -> var = 8*10 + 5 = 85
				printf("%c",c);	

			
		}
		
		if (c == ENTER)
			if(!check_abbl){ 
			setColor(WHITE);
			setBGColor(BLACK);
			if ( var > bellow) var = bellow;
			if ( var <= above) var = above;
			format = (var < 10) ? '0' + itos(var) : itos(var);	
			if(var == 0) format = "00";
			drawText(x,y,format,CYAN);
			return var;
			}else if( var > bellow || var < above ){
				drawText(x,y+2,"KHONG HOP LE",RED);
				Sleep(600);
				clearRect(x,y+2,12,1);
				format = (var < 10) ? '0' + itos(var) : itos(var);	
				if(var == 0) format = "00";
				drawText(x,y,format,GREEN);
			}else{
				format = (var < 10) ? '0' + itos(var) : itos(var);	
				if(var == 0) format = "00";
				drawText(x,y,format,CYAN);
				return var;
			}
			
		if( c == ESC){
			esc = true;
			setColor(WHITE);
			setBGColor(BLACK);
			if ( var > bellow) var = bellow;
			if ( var <= above) var = above;
			format = (var < 10) ? '0' + itos(var) : itos(var);	
			if(var == 0) format = "00";
			drawText(x,y,format,CYAN);
			return var;
		}
	}
	
}

void InputDate(int x, int y, NG &now, NG base, bool hr_min ){
	int color = CYAN, textcolor = BLACK;
	bool esc = false;
	int maxlen = 16;
	// "11-02-2020 10:00" 
	drawText(x,y,NGtoString(now,hr_min),YELLOW);
	// Cac buoc nhay cua field ngay 
	int step[] = {x+0,x+3,x+6,x+11,x+14};
	int cur = 0;
	// Giup hien thi 
	string text = NGtoString(now,hr_min);
//	NG base = Baygio();
	string* ngay;
	if(hr_min){
	ngay = new string[5];
	ngay[0]=text.substr(0,2); ngay[1] = text.substr(3,2); ngay[2] = text.substr(6,4); ngay[3]= text.substr(11,2); ngay[4]=text.substr(14,2);
	}else{
	ngay = new string[3];
	ngay[0] = text.substr(0,2); ngay[1]=text.substr(3,2); ngay[2]=text.substr(6,4);
	}
	drawText(step[cur],y,ngay[cur],CYAN);
	// Loop
	char c;
	while(1){
	c = getch();
		// Di chuyen chon truoc khi dieu chinh 
		if( c == -32 || c == 0)
		{
			c = getch();
			if( c == LEFT ){
				if(cur > 0){
				drawText(step[cur],y,ngay[cur],YELLOW);
				cur-- ;	
				drawText(step[cur],y,ngay[cur],CYAN);
				}
			}
			if( c == RIGHT)
			if (hr_min){
				if(cur < 4 ){
				drawText(step[cur],y,ngay[cur],YELLOW);
				 cur++ ;
				drawText(step[cur],y,ngay[cur],CYAN);
				}
			}else{
				if(cur < 2 ){
				drawText(step[cur],y,ngay[cur],YELLOW);
				 cur++ ;
				drawText(step[cur],y,ngay[cur],CYAN);
				}
			}
			
		}
		// Enter de chon muc dieu chinh 
		if(c == ENTER){
			bool namtrcnhuan = laNamNhuan(now.nam);
			switch(cur){
			// NGAY ( 0 -> laysoNgaythuocThang( THANG , NAM ) )
			case 0:
			now.ngay = InputNumber2(step[0],y,now.ngay,base.ngay,laysoNgaythuocThang(now.thang,now.nam),2,color,textcolor,esc);
			ngay[0] = (now.ngay < 10) ?'0' + itos(now.ngay): itos(now.ngay);
			break;
			// THANG ( 0 -> 12 )
			case 1:
			now.thang = InputNumber2(step[1],y,now.thang,base.thang,12,2,color,textcolor,esc);
				if(laysoNgaythuocThang(now.thang,now.nam) < now.ngay )
					{
					now.ngay = laysoNgaythuocThang(now.thang,now.nam);
					drawNumber(step[0],y,now.ngay,YELLOW);
					ngay[0] = (now.ngay < 10) ?'0' + itos0(now.ngay): itos0(now.ngay);
					}
					ngay[1] = (now.thang < 10) ?'0' + itos0(now.thang): itos0(now.thang);
			break;
			// NAM ( NOW -> MAX_YEAR < 3000 > )
			case 2:
			now.nam = InputNumber2(step[2],y,now.nam,base.nam,MAX_YEAR,4,color,textcolor,esc);	
				if( laNamNhuan(now.nam) != namtrcnhuan )
					{
					if(now.thang == 2 && now.ngay > laysoNgaythuocThang(now.thang,now.nam))
						{
						now.ngay = laysoNgaythuocThang(now.thang,now.nam);
						drawNumber(step[0],y,now.ngay,YELLOW);
						ngay[0] = (now.ngay < 10) ?'0' + itos0(now.ngay): itos0(now.ngay);
						}
					}
					ngay[2] = itos(now.nam);
			break;
			// GIO ( 0 -> 24 ) 
			  // Neu GIO = 24 => GIO = 0 va tang NGAY len 1 
			  // Neu NGAY = 31 => NGAY = 1 va tang THANG len 1 
			  // Neu THANG = 12 => THANG = 1 va tang NAM len 1 
			case 3:
			now.gio = InputNumber2(step[3],y,now.gio,0,24,2,color,textcolor,esc);
				if(now.gio == 24){
					now.gio = 0;
					now.ngay++;
					if(now.ngay > laysoNgaythuocThang(now.thang,now.nam) )
					{
					   now.ngay = 1;
					  now.thang++;
					  if( now.thang > 12 ){
					  	now.nam++;
					  	now.thang = 1;
					  }
					  ngay[1] = (now.thang < 10) ?'0' + itos0(now.thang): itos0(now.thang);
					  drawText(step[1],y,ngay[1],YELLOW);
					  ngay[2] = itos(now.nam);
					  drawText(step[2],y,ngay[2],YELLOW);
					}
					ngay[0] = (now.ngay < 10) ?'0' + itos0(now.ngay): itos0(now.ngay);
					drawText(step[0],y,ngay[0],YELLOW);
				}
					ngay[3] = (now.gio < 10) ? '0' + itos0(now.gio) : itos0(now.gio);
					if(now.gio == 0) ngay[3] = "00";
					drawText(step[3],y,ngay[3],YELLOW);
			break;
			// PHUT ( 0 -> 60 )
			  // Neu PHUT = 60 => PHUT = 0 va tang GIO len 1 
			  // Neu GIO = 24 => GIO = 0 va tang NGAY len 1 
			  // Neu NGAY = 31 => NGAY = 1 va tang THANG len 1 
			  // Neu THANG = 12 => THANG = 1 va tang NAM len 1 
			case 4:
			now.phut = InputNumber2(x+14,y,now.phut,0,60,2,color,textcolor,esc);
				ngay[4] = (now.phut < 10) ?'0' + itos0(now.phut): itos0(now.phut);
				if(now.phut == 60)
				{
					now.gio++;
					now.phut = 0;		
					if(now.gio == 24){
					now.gio = 0;
					now.ngay++;
					if(now.ngay > laysoNgaythuocThang(now.thang,now.nam) )
					{
					   now.ngay = 1;
					  now.thang++;
					  if( now.thang > 12 ){
					  	now.nam++;
					  	now.thang = 1;
					  }
					  ngay[1] = (now.thang < 10) ?'0' + itos0(now.thang): itos0(now.thang);
					  drawText(step[1],y,ngay[1],YELLOW);
					  ngay[2] = itos(now.nam);
					  drawText(step[2],y,ngay[2],YELLOW);
					}
					ngay[0] = (now.ngay < 10) ?'0' + itos0(now.ngay): itos0(now.ngay);
					drawText(step[0],y,ngay[0],YELLOW);
				}
					ngay[3] = (now.gio < 10) ? '0' + itos0(now.gio) : itos0(now.gio);
					if(now.gio == 0) ngay[3] = "00";
					drawText(step[3],y,ngay[3],YELLOW);
				}
				ngay[4] = (now.phut < 10) ? '0' +  itos0(now.phut) : itos0(now.phut);
				if(now.phut == 0) ngay[4] = "00";
				drawText(step[4],y,ngay[4],YELLOW);
			break;
			}
		}
		// BAM ESC DE THOAT
		if(c == ESC) {
			delete[] ngay;
			return;
		}
	}
}

void InputString(int x, int y, int x_e, int y_e, int len, string &tmp, bool check_0_9, bool &esc){
	Cursor(true);
	char c; bool max = false, empty = false; 
	gotoxy(x,y);
	x = x - tmp.size(); 
	// Cai nay dung cho phan` edit, vi` khi edit string tmp co gia tri. vd: khi nhap 1 sv moi chang~ han. thi` tmp.size = 0
	// va` x gui~ vo la` 5 (Diem bat dau ghi cua~ con tro~), thi` khi báo loi~ con tro~ se~ nhay~ lai. cho~ cu~ 5+len=5+40=45. 
	// Nhung neu cho tmp = "duc" thi` khi gui~ vao` x = 8 de~ cho con tro vi tri hien tai. sau chu~ "duc"
	// va` neu bao loi~ = 8 + 40 = 48 la` sai, vi` cho~ cu~ mac dinh la` 45. Nen ta phai~ cho 8 - tmp.size = 8-3 = 5
	string e1 = "KHONG DUOC BO TRONG";
	string e2 = "KHONG THE NHAP DUOC NUA";
	while(true){
		c = getch();
		if (c == ENTER){ // enter - bao loi khong duoc bo trong
			if (tmp.size() > 0) break;
			else{
				empty = true;
				drawText(x_e - e1.size()/2,y_e,e1,RED);
				gotoxy(x,y); // vi bo~ trong thi` chi~ can tro lai vi tri ban dau
			}
		}
		if (c == BACKSPACE){ // backspace - xóa 
			if (tmp.size() != 0){
//				tmp.replace(tmp.size()-1,1,""); // Uncomment dong` nay` neu ban. chua~ them '-std=c++11'
				tmp.erase(tmp.size()-1,1);		// erase cung~ co the xoa string
//				tmp.pop_back(); 				// Neu bao loi~ dung` lenh tren
				printf("\b \b");
				// Khi dang o~ trang. thái string maxlen thì khi xóa di kí tu cuoi cùng, thì se~ xóa báo loi~
				if (max){ // khi xoa di thi` xoa dong bao loi~
					clearRect(x_e - e2.size()/2,y_e,e2.size(),1); // xoa bao loi~
					gotoxy(x+tmp.size(),y); // tro ve cho~ bi xoa
					max = false;
				}
			}
		}
		if (c == ESC){ // escape = back
			esc = true;
			clearRect(x_e - 20,y_e,40,1); // xoa bao loi~
			return;
		}
		if (c == -32 || c == 0){ // da~ fix dc BUG gay bat phim arrow
			c = getch(); continue;
			// trong if nay`, ta de~ them 1 dong` c = getch() la` vi` neu c == -32 or 0 thi` nó se~ tu. dong. getch them 1
			// lan nua~ khi lap lai. vong loop nay` va` cai c = getch() o~ dau` se~ bat nham` phím => gay loi~
		}
		if(!check_max_length(tmp,len)){ // Neu string này chua dat. toi gioi han. max thì se~ tiep tuc. push_back 
			if (c != BACKSPACE && c != ENTER && c >= 32){ 
			// nut backspace && enter no cung~ pusb_back dc,và nhung~ ki tu nho~ hon 32 
			// se~ lam` sai dieu kien bao loi va` in sai 
				if (!check_0_9){ // Neu ko kich hoat che do nhap string kieu number thì có the nhap toan bo ki tu vào
					if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9'){ // 32 = SPACE
						// ko dc nhap ki tu dac biet nhu ; . ' " ? /
						tmp.push_back(c);
						printf("%c",c);	
					}
					if (c == 32 && tmp.size() > 0){
						tmp.push_back(c);
						printf("%c",c);
					}
				}
				//!check_0_9 && c >= '0' && c <= '9' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'
				else{
					if (c >= '0' && c <= '9'){
						tmp.push_back(c);
						printf("%c",c);
					}
				}
				if (empty){ // vi` khi nhap 1 ki tu nao` do thi` no se~ tu dong xoa bao loi empty di
					empty = false;
					clearRect(x_e - e1.size()/2,y_e,e1.size(),1);
					if (tmp.size() != 0) gotoxy(x+1,y);
					else gotoxy(x,y); 
					// x+1 la` vi` khi tmp.size() = 0, thi` khi 1 char duoc push vao`, thi` tmp.size() = 1
					// dong nghia voi viec 1 ki tu duoc in ra, va` ki tu do duoc ghi o~ (x,y)
				} // lam nhu the nay` de~ no clearRect 1 lan thoi
			}
		}
		else { // Khi string da~ du~ do. dài mà còn nhap. them thì se~ kich hoat. báo loi~ max = true
			max = true;
			drawText(x_e - e2.size()/2,y_e,e2,RED);
			gotoxy(x+len,y); // (10+1+17) la cai x co dinh, + len la vi tri max o cuoi string
		}
		
	}
	clearRect(x_e - 20,y_e,40,1); // xoa tat ca~ thong bao loi~
	Cursor(false);
}

void InputGender(int x, int y,bool &gender, bool &esc){
	gotoxy(x,y); Cursor(true);
	char c; string tmp = "\0";
	if (gender == 1) tmp = "1"; // Dung` cho ham` edit sinh vien
	else if (gender == 0) tmp = "0";
	else tmp = "";
	cout<<tmp;
	while(true){
		c = getch();
		if (tmp.size() == 1){ // Khi string tmp có do dai` == 1 thi` se~ ko dc push_back them nua~
			if (c == BACKSPACE){
				if (tmp.size() != 0){
					tmp.replace(tmp.size()-1,1,"");
					printf("\b \b");
				}
			}
			if (c == ENTER) break;
		}
		else{
			if (c == '1' || c == '0'){
				tmp.push_back(c);
				printf("%c",c);
			}
		}
		if (c == ESC){ // escape = back
			esc = true;
			return;
		}
	}
	if (tmp == "1") gender = 1;
	if (tmp == "0") gender = 0;
	Cursor(false);
}

void InputNumber(int x, int y, int x_e, int y_e, int &var, int maxlen, bool onetoten, bool &esc){
	gotoxy(x,y); Cursor(true);
	int len = (var == 0 ? 0:1+floor(log10(var))); // do dai cai chuoi~ so moi vua` truyen` vào
	x = x - len; // x = x - len là vì dùng cho nhung~ lan` gotoxy ve` cho~ cu~ khi da~ báo loi~
	char c; // var = 0;
	bool empty = false, max = false;
	string e1 = "KHONG DUOC BO TRONG", e2 = "SO LUONG QUA LON";
	
	while(true){ // co the bi sai || chua xong, viet tiep di
		c = getch();
		if (c == ENTER){ // enter
			// Có giá tri. thì lay ko thì báo loi~ 
			if (var != 0) break;
			else{
				empty = true;
				drawText(x_e - e1.size()/2,y_e,e1,RED);
				gotoxy(x,y);
			}
		}
		if (c == BACKSPACE && len > 0) { // Backspace - xóa. Neu var != 0, vd var = 85 -> var = int(85/10) = 8, do dài giam~
			var /= 10; len--;
			printf("\b \b");
			if (max){ // Neu len dang max thì khi giam~ di gia tri. thì se~ set max = false và xóa báo loi~
				max = false;
				clearRect(x_e - 20,y_e,40,1); // xoa bao loi~
				gotoxy(x+maxlen-1,y); // 5 chu so (qua gioi han), khi xoa di 1 chu so thi` con 4 nen x + 4 
			}
		}
		if (c == ESC){ // escape = back
			esc = true;
			clearRect(x_e - 20,y_e,40,1); // xoa bao loi~
			return;
		}
		if (c >= '0' && c <= '9' && len < maxlen){ // Bam phim 8 và var = 0 -> var = 0*10 + 8 = 8
			if (var == 0 && c != '0' || onetoten && var == 1 && c == '0' || !onetoten && var >= 0) {
				var = var * 10 + (int(c) - 48);
				if (var != 0){
					len++; // Bam phim 5 và var = 8 -> var = 8*10 + 5 = 85
					printf("%c",c);
					if (empty){ // Neu có bat che do kiem tra bo~ trong thì khi enter mà var = 0 thì empty se~ dc set = true
								// Nên khi nhap 1 giá tri. nào vào thì empty se~ dc set lai. = false
						empty = false;
						clearRect(x_e - 20,y_e,40,1); // xoa bao loi~
						gotoxy(x+1,y);// Dang de~ khi ma` them 1 chu so vao` thi` khi xoa bao loi~, phai~ tro~ ve` x + 1
					}	
				}
			} 
			else continue;
		}
		else if (len == maxlen){
			// Neu hien tai do. dai` cua~ chuoi so dang == 5 thi` khi nhap tiep tuc se~ bao loi~
			max = true;
			drawText(x_e - e2.size()/2,y_e,e2,RED);
			gotoxy(x+maxlen,y); // ve lai vi tri max cua~ chuoi~ so
		}
	}
	clearRect(x_e - 20,y_e,40,1); // xoa bao loi~
	Cursor(false);
}

void ToUpper(string &tmp){
	for(int i=0;i<tmp.size();i++) tmp[i] = char(toupper(tmp[i]));
}

void RemoveSpace(string &tmp,bool athead){ // athead nghia~ la` chi~ xoa nhung~ thang space dau tien, con ko thi xoa het space
	if (athead){
		int slxoa = 0;
		for(int i=0;i<tmp.size();i++){
			if (!isspace(tmp[i])) break; 
			else slxoa++;
			// Néu char i ko phai~ là khoang~ trang thì slxoa++, néu nhu char i là 1 kí tu. ngay lan` dau tien thì break
		}
		tmp.erase(0,slxoa); // xóa slxoa kí tu. bat dau tu` char[0] 
	}
	else{
		for(int i=0;i<tmp.size();i++){
			if (isspace(tmp[i])){
				tmp.erase(i,1);
				i=-1; // Tai. sao i ko = 0 mà là -1. Vì khi vong lap duoc lap. lai. thi` i++ => i = 0
			}
		}
	}
}

bool file_exist(const char *link){
	fstream f(link);
	if (!f) return false;
	else return true;
}

bool Yes(){
	char c;
	while(true){
		c = getch();
		if (c == 'y' || c == 'Y') return true;
		else if ( c == 'n' || c == 'N') return false;
	}
}

void Pause(){
	char c;
	c = getch();
	if (c == -32 || c == 0) c = getch();
}

bool check_max_length(string tmp, int length){
	if (tmp.size() == length) return true;
	else return false;
}
