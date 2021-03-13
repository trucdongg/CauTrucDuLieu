#include "_graphs.h"

//  -------------------------------------------------------- MO TA HAM ------------------------------------------------------------ //
 	
	// Giao dien ngoai va dang nhap
	void dangNhap();
	void menu();
		void menuMB();
			void menuMBv2();
	    void menuCB();
	    	bool menuVe(CB cb);
	    void menuHK();
	    void menuTK();
	       
    void nutDieukhien( int x, int y, int step, int esc, bool chonlua, bool phantrang, bool chucnang );
	void ThanhHuongDan(string* tieude, int n_tieude, int buoc_nhay, int start_x, int start_y );
	// THONG KE 
	   // cau E // Liet ke hanh khach thuoc 1 chuyen bay
		void lietkeHKthuocCB();
			CB chonCBdeLietke( int x, int y, int xi, int yi, string &tmp, int color, bool ktra_ve_trong = true);
			int chonCBmini( int x, int y, int *indexs, int n, string *a, bool ktra_ve_trong = true);
			void TieudelietkeHK( int x, int y);
			void LietkeHKtheoVe( int x, int y, DsVe ds);
		// cau F // In danh sach ve khoi hanh trong ngay dd/mm/yyyy den noi XXXX ma con ve
		void DsHKtheoNGvaND();
			void LietkeCBtheoNGvaND( int x, int y );
		// cau H // Thong ke so luot thuc hien chuyen bay cua tung may bay theo thu tu giam dan 
		void ThongkeSoluotMB();
			void ThongkeSoluotthuchienCB( int x, int y );
		// cau G // Thong ke so ve trong trong chuyen bay 
		void DsVetrongTK( );
			void DsVetrongcuaCB( int x, int y, CB cb );
			void TieudelietkeVe( int x, int y);
	// May Bay
	string HD_MB[] = {"1 = Them May Bay", "2 = Sua May Bay", "3 =  Xoa May Bay"};
	int n_MB = 3;
       //----------
	bool themMayBay();
	int chonMayBay(int from, int to, int color = GREEN);
	// Version 1 : A - Z 
	
	void suaMayBay(int from, int to, int color = CYAN);
	void xoaMayBay(int from, int to, int color, bool &reload);
	// Version 2 : Z - A 
	
	bool suaMayBayv2(int &from, int &to, int &page, int color = CYAN);
	bool xoaMayBayv2(int &from, int &to, int &page, int color);
	bool timMayBayv2(int &from, int &to, int &page, int color);
	
	// Chuyen Bay 
	string HD_CB[]= {"1 = Them Chuyen Bay","2 = Sua Chuyen Bay","3 = Xoa Chuyen Bay ","4 = Dat Ve May Bay"};
	int n_CB = 4 ;
	// SAN BAY DEN STRING[22]
	
	void TieudeChuyenBay(int start_x,int start_y);
	void ThanhHuongDanCB(string* tieude, int n_tieude, int buoc_nhay, int start_x, int start_y );
	 
	bool themChuyenBay();
		string dropboxSohieu(int x, int y,  string *a, int n, string init, int xi = 0, int yi = 0);
		string dropboxSBden( int x, int y,  string *a, int n, string init ,NG now, int &time,int xi = 0, int yi = 0);
		int mauTrangthai( int tt = 0);
		int mauTrangthaiCB(int tt);
	int chonChuyenBay(int from, int to, int color);
	bool suaChuyenBay( int &from , int &to, int &page, int color);
		void suaTTcapnhatHK(CB cb);
	bool xoaChuyenBay(int &from, int &to,int &page ,int color);
	bool datVe(int &from ,int &to,int &page ,int color );	
	bool timChuyenBay(int &from, int &to,int &page, int color);
			
	// Ve 
	
	void KhungChonVe(int x,int y, int sodong, int soday,DsVe &ds,int mx = 3, int my = 1,bool hienthivedat = true);
		string VetoString(Ve ve);
		bool HKduocdatVekhong( HK hk, CB cb);
		bool ChonVe(int x,int y, int sodong, int soday, CB &cb ,int mx = 3, int my = 1);
		void veChoNgoi(int x,int y,int width,int height,string text,int color = WHITE);
		void toChoNgoi(int x,int y,int width,int height,string text,int bgcolor = BLACK,int color = WHITE);
	void ThanhHuongDanVe(string* tieude, int n_tieude, int buoc_nhay, int start_x, int start_y );
	
	// Hanh khach 
	string HD_HK[] = {"1 = Them Hanh Khach", "2 = Sua Hanh Khach", "3 =  Xoa Hanh Khach"};
	int n_HK = 3;
	   // ---------
	
	int mauTrangthai( bool ranh);
	bool themHanhKhach();
	bool xoaHanhKhach(int &from, int &to, int &page , int color);
	bool suaHanhKhach(int &from, int &to, int &page, int color);
	bool timHanhKhach(int &from, int &to, int &page, int color);
	int chonHanhKhach(int from , int to, int color);
	string HKtoString( HK hk);
	int dropboxHK( int x, int y , CB cb);
	
//  -------------------------------------------------------- --------- ------------------------------------------------------------ //


//----------------------------------------------------------------------------------------------------------------------------------//
//                                                        GIAO DIEN CHINH                                                           //  
//  --------------------------------------------------------------------------------------------------------------------------------//

void menu(){
	int pre = -1, cur = 1;
	bool arrow_press = true, esc = false, enter = false, back = false;
	
	back:
	 if(back) {
	 back = false;
	 clearRect(2,1,178,50);
	 }
	// Ve khung 
	drawRect(70,4,35,4);
	// Ve tieu de 
	drawText(80,6,"QUAN LI MAY BAY",GREEN);
	// Ve giang vien
	drawRect(2,40,35,4);
	drawText(4,42,"Giang vien: Luu Nguyen Ky Thu",BLUE);
	// Ve nhom 
	drawRect(140,35,38,9);
	drawText(150,36,"NHOM 62",RED);
	drawText(142,38,"Duong Truc Dong - N17DCAT017",WHITE);
	drawText(142,40,"Phan Dai - N17DCAT013",WHITE);
	drawText(142,42,"Nguyen Hoang Thao Quyen - N17DCAT080",WHITE);
	// Nut dieu khien 
	nutDieukhien( 50, 40, 6, 85, false, false, true );
	const string menu_item[4] = {"MAY BAY","CHUYEN BAY","KHACH HANG","THONG KE"};
	
	int start_x = GetConsoleWidth()/2 - 15, start_y = GetConsoleHeight()/2 - 15 ;
	// ======================== CHI TIET VE CO DINH ======================== //
	Cursor(false); // Lam con tro~ trong man hinh bien mat
	// ===================================================================== //
	
	// LIET KE CAC TEN CHUC NANG CUA MENU, SAU DO VAO VONG WHILE MOI VE~ KHUNG (CHON / KO CHON)
	for(int i=1;i<=4;i++) drawText(start_x + 9,start_y+i*6,menu_item[i-1],WHITE);
	while(1){
		if (cur > 4) cur = 1;
		if (cur < 1) cur = 4;
		if (arrow_press){
			if (pre > 0){
				frame_not_choose_item(start_x-1,start_y+pre*6-1,menu_item[pre-1],WHITE);
			}
			frame_choose_item(start_x-1,start_y+cur*6-1,menu_item[cur-1],YELLOW);
			arrow_press = false;
			gotoxy(0,0);
//			Sleep(200);
		}
		GUI_KeyMenu(pre,cur,arrow_press,esc,enter);
        if (esc){
        	
        	return;
		}
		if (enter){ 
			enter = false;// thieu dong nay` thi se~ bi loi~ ket phim enter, vi` khi thoat switch case ra thi` enter van = true
			arrow_press = true;
			// FIX THE ESC BUTTON
			system("cls");
			switch(cur){ // 30 la` cai width cua~ rect nho~
				case 1:
					menuMBv2();
					back = true;
					goto back;
					
					break;
				case 2:
					menuCB();
					back = true;
					goto back;
					
					break;
				case 3:
					menuHK();
					back = true;
					goto back;
					
					break;
				case 4:
					menuTK();
					back = true;
					goto back;
					
					break;
				default: // de~ cho co truong hop thoi, ko can cung duoc
					break;
			}
		Cursor(false);
		}
	}

}

void nutDieukhien( int x, int y, int step, int esc , bool chonlua , bool phantrang, bool chucnang ){
	int width = 4;
	
	if(phantrang)
	{
		// <
		drawButton(x,y,CYAN,width,LEFT_ARROW,"","");
		// >
		drawButton(x+step,y,CYAN,width,RIGHT_ARROW,"","CHUYEN TRANG");
	}
	
	if(chonlua){
		
		// <
		drawButton(x,y,CYAN,width,LEFT_ARROW,"","");
		// ^
		drawButton(x+step,y-step/2,CYAN,width,UP_ARROW,"","DI CHUYEN");
		// v
		drawButton(x+step,y,CYAN,width,DOWN_ARROW,"","");
		// >
		drawButton(x+step*2,y,CYAN,width,RIGHT_ARROW,"","CHUYEN TRANG");
		
		
	}
	
	if(chucnang){
		// ^
		drawButton(x+step,y-step/2,CYAN,width,UP_ARROW,"","DI CHUYEN");
		// v
		drawButton(x+step,y,CYAN,width,DOWN_ARROW,"","");
		
		// ENTER
		drawButton(esc,y-step/2,BLUE,width + 2,ESC,"ENTER","CHON");
	}
	
	if ( esc != -1)
	{
		// ENTER
		if(chonlua) drawButton(esc,y-step/2,BLUE,width + 2,ESC,"ENTER","CHON");
		// ESC
		drawButton(esc,y,RED,width,ESC,"ESC","THOAT");
	}
}

void dangNhap(){
	string username="";
	string passwd="";
	bool move = false;
	bool check=false;
	bool esc=false;
	drawRect(70,4,35,4);
	drawText(80,6,"QUAN LI MAY BAY",GREEN);
	drawRect(2,40,35,4);
	drawText(4,42,"Giang vien: Luu Nguyen Ky Thu",BLUE);
	drawRect(140,35,38,9);
	drawText(150,36,"NHOM 62",RED);
	drawText(142,38,"Duong Truc Dong - N17DCAT017",WHITE);
	drawText(142,40,"Phan Dai - N17DCAT013",WHITE);
	drawText(142,42,"Nguyen Hoang Thao Quyen - N17DCAT080",WHITE);
	drawRect(50,12,80,15);
	drawText(65,16,"Ten Dang Nhap : ",WHITE);
	drawText(65,20,"Mat Khau      : ",WHITE);
		drawText(1,0,"Danh sach May Bay : "+itos0( dsmb->laydodai() )+" (MayBay)",GREEN);
		drawText(1,1,"Danh sach Chuyen bay : "+itos0( mcb.getN() )+" (Chuyenbay)",GREEN);
		drawText(1,2,"Danh sach Hanh Khach : "+itos0( mhk.getN() )+" (HanhKhach)",GREEN);
	while(1){
		move:
		InputString(85 + username.length(),16,80,18,5,username,check,esc);
		InputPasswd(85+ passwd.length(),20,80,22,5,passwd,check,esc,move);
		if (move){
			move = false;
			goto move;
		}
		else if(username == "admin" && passwd == "admin"){
		drawText(65,24,"Dang Nhap Thanh Cong",BLUE);
		Sleep(500);
		system("cls");
		menu();
		break;
		}
		else{
		drawText(65,24,"Dang Nhap That Bai",RED);
		}	
	}
	
}

void ThanhHuongDan(string* tieude, int n_tieude, int buoc_nhay, int start_x, int start_y ){
	drawFillRect(2,38,177,1,CYAN);
	drawRect(2,1,177,35);
	draw_high_line(110,1,35);
//	for(int i= 0; i < n_tieude; i++ )
//	drawText( start_x+i*buoc_nhay ,start_y, tieude[i], 10+i);
//	drawText(start_x+n_tieude*buoc_nhay,start_y,"ESC =  Thoat ",RED);
	drawFillRect(2,38,177,1,CYAN);
	drawRect(2,1,177,35);
	draw_high_line(110,1,35);
	drawButton(2,40,YELLOW,4,27,"1","THEM");
	drawButton(32,40,CYAN,4,27,"2","SUA");
	drawButton(62,40,GREEN,4,27,"3","XOA");
	drawButton(92,40,DARKYELLOW,4,27,"4","TIM KIEM");
	drawButton(122,40,RED,4,27,"ESC","THOAT");
}

//----------------------------------------------------------------------------------------------------------------------------------//
//                                                          MAY BAY                                                                 //  
//  --------------------------------------------------------------------------------------------------------------------------------//

void TieudeMayBay(int start_x,int start_y){
	drawRect(start_x,start_y,100,2);
	draw_high_line(start_x+20,start_y,2);
	drawText(start_x+4,start_y+1,"SO HIEU",WHITE);
	draw_high_line(start_x+54,start_y,2);
	drawText(start_x+28,start_y+1,"LOAI ",WHITE);
	draw_high_line(start_x+77,start_y,2);
	drawText(start_x+56,start_y+1,"SO DAY",WHITE);
	drawText(start_x+80,start_y+1,"SO DONG",WHITE);		
}

void menuMB(){
	TieudeMayBay(4,2);
	ThanhHuongDan(HD_MB, n_MB, 40, 3, 40);
	drawText(5, 30, "So hieu chua duoc dang ki", GREEN);
	drawText(5, 32, "So hieu da duoc dang ki", RED);

	int c ;
	bool reload = true, press = false, move = false, esc = false, enter = false;
	int from = 0 , to = (dsmb->laydodai() > 10 ? 10:dsmb->laydodai())
	, cur1, page = 1 , pre = -1, cur2 = 1;
	while(1){
		if(esc){
			
			return;
		}
		if (reload){
			page = 1; from = 0; to = (dsmb->laydodai() > 10 ? 10:dsmb->laydodai());
			// if len > 10 => to = 10 else to = len ( len luc nay` se~ <= 10 )
			reload = false;
			drawNumber(43,27,page,WHITE);
			drawNumber(49,27,(dsmb->laydodai()%10 == 10 ? dsmb->laydodai()/10:1+dsmb->laydodai()/10),YELLOW);
			// Coi giai thich o phan` GUI_MonHocMenu()
			
			clearRect(4,5,87,22);
			dsmb->lietkeMB(4,2,from,to);
			Cursor(false);
		}
		if (move){
			move = false;
			clearRect(4,4,100,22); // Xoa het cac ptu~ de~ in ra trang tiep theo
			dsmb->lietkeMB(4,2,from,to);
			drawNumber(43,27,page,WHITE);
			Cursor(false);
		}
		KeyPress_1(cur1,from,to,page,dsmb->laydodai(),reload,press,move,esc);
		if (press){
			switch(cur1){
				case 1: // Them 
					themMayBay();	
					reload = true;	
					break;
				case 2: // Dieu chinh 
					suaMayBay(from, to , CYAN);
					cur1 = 0;
					reload = true;
					break;
				case 3: // Xoa
					xoaMayBay(from, to, RED,reload);
					cur1 = 0;
					break;
				case ESC: //
					esc = true;
					cur1= 0;
					return;
					break;
				default:
					break;
			}
			press = false;
			Cursor(false);
			
		}
	}
}

void menuMBv2(){
	bool change = false;
	TieudeMayBay(4,2);
	ThanhHuongDan(HD_MB, n_MB, 40, 3, 40);
	nutDieukhien(80,32,6,-1,false,true,false);
	//clearRect(80,32 - 6/2,24,6);
	drawText(5, 30, "So hieu chua duoc dang ki", GREEN);
	drawText(5, 32, "So hieu da duoc dang ki", RED);

	int c ;
	bool reload = true, press = false, move = false, esc = false, enter = false;
	int n= dsmb->laydodai(),to = n,from = ( to - 10 >= 0) ? to - 10 : 0
	, npage = ( n >= 10 ? ( n%10 != 0 )? n/10 + 1 : n/10 : 1) 
	, cur1, page = 1 , pre = -1, cur2 = 1;
	while(1){
		if(esc){
			if(change){
				char c1;
				drawText(140,41,"LUU VA THOAT (Y/N/ESC) ? ",RED);
				c1 = getch();
				if( c1 == 'y' || c1 == 'Y' )
					{
					dsmb->luu(false);
					return;
					}
				else if( c1 == 'n' || c1 == 'N' ) clearRect(140,41,24,1);
				else{ // ESC ESC khi co su thay doi
					delete[] dsmb;
					dsmb = new DSMB();					
					return;
				} 
			}else // ESC ESC khi khong co su thay doi 
				return;
		}
		if (reload){
			n= dsmb->laydodai();
			npage = ( n >= 10 ? ( n%10 != 0 )? n/10 + 1 : n/10 : 1);
			page = 1; to = n, from = ( to - 10 >= 0) ? to - 10 : 0;
			// if len > 10 => to = 10 else to = len ( len luc nay` se~ <= 10 )
			reload = false;
			clearRect(4,5,100,22);
			// Trang 1 / 2 --------------- 
			drawText(36,27,"Trang ",WHITE);
			drawNumber(43,27,page,WHITE);
			drawText(46,27,"/",WHITE);
			drawNumber(49,27,npage,YELLOW);
			// --------------------------- 
			dsmb->lietkeMBnguoc(4,2,from,to);
			Cursor(false);
			cur1 = 0;
		}
		if (move){
			move = false;
			clearRect(4,4,100,22); // Xoa het cac ptu~ de~ in ra trang tiep theo
			dsmb->lietkeMBnguoc(4,2,from,to);
			drawText(36,27,"Trang ",WHITE);
			drawNumber(43,27,page,WHITE);
			drawText(46,27,"/",WHITE);
			drawNumber(49,27,npage,YELLOW);
			Cursor(false);
		}
		KeyPress_3(cur1,from,to,page,dsmb->laydodai(),reload,press,move,esc);
		if (press){
			press = false;
			switch(cur1){
				case 1: // Them 
					reload = themMayBay();	
					if(reload) change = true;
					cur1 = 0;
					break;
				case 2: // Dieu chinh 
					clearRect(80,32 - 6/2,24,6);
					nutDieukhien(75,32,6,-1,true,false,false);
					reload = suaMayBayv2(from, to ,page , CYAN);
					if(reload) change = true; 
					cur1 = 0;
					clearRect(75,32 - 6/2,30,6);
					break;
				case 3: // Xoa
					clearRect(80,32 - 6/2,24,6);
					nutDieukhien(75,32,6,-1,true,false,false);
					reload = xoaMayBayv2(from, to, page, RED);
					if(reload) change = true;
					cur1 = 0;
					clearRect(75,32 - 6/2,30,6);
					break;
				case 4: // Tim kiem
					clearRect(80,32 - 6/2,24,6);
					nutDieukhien(75,32,6,-1,true,false,false);
					reload = timMayBayv2(from, to, page, WHITE);
					if(reload) change = true;
					cur1 = 0;
					clearRect(75,32 - 6/2,30,6);
				break;
				case ESC: //
					esc = true;
					cur1= 0;
					return;
					break;
				default:
					break;
			}
			nutDieukhien(80,32,6,-1,false,true,false);
			press = false;
			Cursor(false);
		}
	}
}

bool themMayBay(){
	bool change = false;
	bool check_abbl = true;
	bool check=false,esc = false;
	int x = 120, y = 4, sohieulen = 0;
	string msg = "THEM MAY BAY";
	drawText(130,2,msg,YELLOW);
	drawText(120,4,"So Hieu : ",WHITE);
	drawText(120,10,"Loai    : ",WHITE);
	drawText(120,16,"So Day  : ",WHITE);
	drawText(120,22,"So Dong : ",WHITE);
	MB mb = {"","",0,0,0};
	move:
	clearRect(140,5,18,1);
	// So hieu : C15, not null, not duplicate 
	InputString(x+10+sohieulen,y,140,5,C15,mb.sohieu,check,esc);
	if (esc) {
		clearRect(x,y,30,20);
		clearRect(130,2,msg.length(),1);
		return change;
	}else mb.sohieu = upper(mb.sohieu);
	if ( dsmb->tim(mb.sohieu) != -1 ) {
		drawText(140,5,"SO HIEU DA TON TAI",RED);
		Sleep(500);
		sohieulen = mb.sohieu.length();
		goto move;
		
	}
	
	// Loai : C40, not null 
	InputString(x+10,y+6,140,11,C40,mb.loai,check,esc);
	if (esc) {
		clearRect(x,y,30,20);
		clearRect(130,2,msg.length(),1);
		return change;
	}
	
	// So day : 1 -> 9 
	drawText(x+15,y+12, " ( 1 <= x <= "+itos0(MAX_DAY)+" )",RED);
	mb.soday = InputNumber2(x+10,y+12,mb.soday,1,MAX_DAY,2,BLACK,GREEN,esc,check_abbl);
	if (esc) {
		clearRect(x,y,35,25);
		clearRect(130,2,msg.length(),1);
		return change;
	}
	// So dong : 1-> 30 
	drawText(x+15,y+18, "( 1 <= x <= "+itos0(MAX_DONG)+" )",RED);
	mb.sodong = InputNumber2(x+10,y+18,mb.sodong,1,MAX_DONG,2,BLACK,GREEN,esc,check_abbl);
	if (esc) {
		clearRect(x,y,35,20);
		clearRect(130,2,msg.length(),1);
		return change;
	}
	mb.tt = 0;
	change = true;
	dsmb->them(mb);
	clearRect(x,y,30,20);
	clearRect(130,2,msg.length(),1);
	return change;
}

void suaMayBay(int from , int to, int color){
	int vitri = -1; 
	// ----------------------Chon May Bay -----------------------------------------------------------------------------
		int width = 3, height = 1, step=2,
		i = 0;
		bool esc = false;
	back:
	Cursor(false);
		char c ;
		int x = 106, y = 5,
		 n = to - from -1,
		 len = dsmb->laydodai();
		i = (vitri == -1) ? 0 : vitri - from ;
	// To mau thang dau tien 
	drawFillRect(x, y + i*step, width, height, color );
	while(1){
		c = getch();
		if (c == -32){
			c = getch();
			// Chon vi tri 
			if (c == UP){ 
				clearRect(x, y + i*step , width, height);		
				if(i > 0) i--;
				else i = 0;
				drawFillRect(x, y + i*step , width, height, color );		
			}
			if (c == DOWN){ 
				clearRect(x, y + i*step , width, height);
				if(i < n) i++;
				else i = n;
				drawFillRect(x, y + i*step, width, height, color );
			}
			// Qua 1 trang moi 
			if (c == LEFT){
				clearRect(x, y + i*step, width, height);
				to = (from != 0) ? from : to;
				from = (from - 10 < 0) ? 0 : from -10;
				clearRect(4,4,100,22);
				
				dsmb->lietkeMB(4,2,from,to);
				i=0; n = to - from -1;
				drawFillRect(x, y + i*step, width, height, color );
			}
			if (c == RIGHT){
				clearRect(x, y + i*step, width, height);
				from = (to != len) ? to : from;
				to = (to + 10 > len) ? len : to + 10;
				clearRect(4,4,100,22);
				
				dsmb->lietkeMB(4,2,from,to);
				i = 0; n = to - from -1;
				drawFillRect(x, y + i*step, width, height, color );
			}
		}
		// Enter => Xuong phia duoi thuc hien tiep
		if (c == ENTER){
			clearRect(x, y + (i)*step, width, height);
			vitri = from+i;
			break;
		}
		// ESC => Thoat ra khoi chuong trinh
		if(c == ESC){
			clearRect(x, y + (i)*step, width, height);
			vitri = -1;
			return;
		}
	}
	// ---------------------- Sua May Bay -----------------------------------------------------------------------------
			x = 120;
			y= 4;
			string msg= "Sua may bay tai vi tri ";
			if(vitri == -1) goto back; 
			MB *mb = dsmb->getMB(vitri);
			if(mb->tt == 1) 
			{
				string msg="KHONG THE SUA VI DANG DUOC DANG KY";
				drawText(120,6,msg,RED);
				Sleep(800);
				clearRect(120,6,msg.length()+3,1);
				goto back;
			}
			esc = false;
			// Viet Label thong bao 
			clearRect(x,y,msg.length()+5, 1);
			drawText(x,y,msg,color);
			drawNumber(x+2+msg.length(),y,vitri+1,color);
			// Viet Label nhap 
			drawText(x,y*2,"So Hieu : ",WHITE);	drawText(x+10,y*2,mb->sohieu,GREEN);
			drawText(x,y*3,"Loai    : ",WHITE);	drawText(x+10,y*3,mb->loai,GREEN);
			drawText(x,y*4,"So Day  : ",WHITE); drawNumber(x+10,y*4,mb->soday,GREEN);
			drawText(x,y*5,"So Dong : ",WHITE);	drawNumber(x+10,y*5,mb->sodong,GREEN);
			int soday_len  = (mb->soday  /10 > 0) ? 2 : 1;
			int sodong_len = (mb->sodong /10 > 0) ? 2 : 1;
			// So hieu : ( Khong thay doi )  
			
			// Loai    : 
				InputString(x+10 + mb->loai.length(),y*3,x+20,y*3+2,40,mb->loai,false,esc);
				if (esc) {
					clearRect(x,y,50,20);
					// Nhan ESC =>  Tro ve vi tri chon luc nay
					goto back;
				}
			// So day  : 
				InputNumber(x+10+soday_len,y*4,x+20,y*4+2,mb->soday,2,true,esc);
				if (esc) {
					clearRect(x,y,50,20);
					// Nhan ESC =>  Tro ve vi tri chon luc nay
					goto back;
				}
			// So Dong  : 
				InputNumber(x+10+sodong_len,y*5,x+20,y*5+2,mb->sodong,2,false,esc);
				if (esc) {
					clearRect(x,y,50,20);
					// Nhan ESC =>  Tro ve vi tri chon luc nay
					goto back;
				}
			// Thoat that su chi khi enter 3 lan 
			clearRect(106, 5 + vitri*2, 3, 1);
			Sleep(900);
			clearRect(x,y,50,20);
			return;
	}

bool suaMayBayv2(int &from , int &to,int &page, int color){
// ----------------------Chon May Bay -----------------------------------------------------------------------------
		int width = 3, height = 1, step=2,
		vitri = -1; 
		bool esc = false, change = false;
	back:
		bool move = false;
		char c;
		int x = 106, y = 5,
		n = dsmb->laydodai(),
		npage = ( n >= 10 ? ( n%10 != 0 )? n/10 + 1 : n/10 : 1);
		int cur = to - 1;
		if( n == 0 ) return change;
	// To mau thang dau tien 
	Cursor(false);
	clearRect(x,y,width,height);
	if(vitri != -1){
		drawFillRect(x, y + (to-1 - vitri)*step, width, height, color );
		cur = vitri;
	}else
	drawFillRect(x, y,width,height,color );
	while(1){
		if(move){
			clearRect(4,4,100,22);
			move = false;
			drawFillRect(x,y+(to-1 - cur)*step,width,height,color);
			
			// Trang 1 / 2 --------------- 
			drawText(36,27,"Trang ",WHITE);
			drawNumber(43,27,page,WHITE);
			drawText(46,27,"/",WHITE);
			drawNumber(49,27,npage,YELLOW);
			// --------------------------- 
			dsmb->lietkeMBnguoc(4,2,from,to);
		}
		c = getch();
		if (c == -32){
			c = getch();
			// Chon vi tri 
			if (c == UP){ 
				if(cur < to-1){
				clearRect(x, y + (to-1 - cur)*step , width, height);		
				cur++;
				drawFillRect(x, y + (to-1 - cur)*step , width, height, color );		
				}
			}
			if (c == DOWN){ 
				if(cur > from){
				clearRect(x, y + (to-1 - cur)*step , width, height);		
				cur--;
				drawFillRect(x, y + (to-1 - cur)*step , width, height, color );		
				}
			}
			// Qua 1 trang moi 
			if (c == LEFT){
//				clearRect(x, y + (to-1 - cur)*step, width, height);
					if( to + 10 <= n){
					clearRect(x, y + (to-1 - cur)*step, width, height);
					from = to;
					to = to + 10 >= n? n : to + 10 ;
					move = true;
					page--;	
					cur = to-1;
					drawFillRect(x,y + (to-1 - cur)*step, width, height, color );
				}	
				
			}
			if (c == RIGHT){
//				clearRect(x, y + (to-1 - cur)*step, width, height);
				if( to > 10 ){
					clearRect(x, y + (to-1 - cur)*step, width, height);
					to = from;
					from = to - 10 <= 0? 0 : to - 10 ;
					move = true;
					page++;	
					cur = to-1;
					drawFillRect(x, y + (to-1 - cur)*step, width, height, color );
				}	
			
			}
		}
		// Enter => Xuong phia duoi thuc hien tiep
		if (c == ENTER){
			vitri = cur;
			break;
		}
		// ESC => Thoat ra khoi chuong trinh
		if(c == ESC){
			gotoxy(0,0);
			clearRect(120,4,40, 20);
			clearRect(x, y + (to-1-cur)*step, width, height);
			vitri = -1;
			return change;
		}
	}
	// ---------------------- Sua May Bay -----------------------------------------------------------------------------
			x = 120;
			y= 4;
			string msg= "SUA MAY BAY TAI VI TRI ";
			if(vitri == -1) goto back; 
			MB *mb = dsmb->getMB(vitri);
			if(mb->tt == 1) 
			{
				string msg="KHONG THE SUA VI DANG DUOC DANG KY";
				drawText(120,6,msg,RED);
				Sleep(800);
				clearRect(120,6,msg.length()+3,1);
				goto back;
			}
			esc = false;
			// Viet Label thong bao 
			clearRect(x,y,msg.length()+5, 1);
			drawText(x,y,msg,color);
			drawNumber(x+2+msg.length(),y,vitri+1,color);
			// Viet Label nhap 
			drawText(x,y*2,"So Hieu : ",WHITE);	drawText(x+10,y*2,mb->sohieu,GREEN);
			drawText(x,y*3,"Loai    : ",WHITE);	drawText(x+10,y*3,mb->loai,GREEN);
			drawText(x,y*4,"So Day  : ",WHITE); drawNumber(x+10,y*4,mb->soday,GREEN);
			drawText(x,y*5,"So Dong : ",WHITE);	drawNumber(x+10,y*5,mb->sodong,GREEN);
			int soday_len  = (mb->soday  /10 > 0) ? 2 : 1;
			int sodong_len = (mb->sodong /10 > 0) ? 2 : 1;
			// So hieu : ( Khong thay doi )  
			
			// Loai    : 
				string old = mb->loai;
				InputString(x+10 + mb->loai.length(),y*3,x+20,y*3+2,40,mb->loai,false,esc);
				if (esc) {
					clearRect(x,y,50,20);
					// Nhan ESC =>  Tro ve vi tri chon luc nay
					mb->loai = old;
					goto back;
				}
			// So day  : 
				clearRect(x+10,y*4,2,1);
				int oldsd = mb->soday;
				mb->soday = InputNumber2(x+10+soday_len,y*4,mb->soday,1,MAX_DAY,2,BLACK,GREEN,esc);
				if (esc) {
					clearRect(x,y,50,20);
					// Nhan ESC =>  Tro ve vi tri chon luc nay
					mb->loai = old;
					mb->soday = oldsd; 
					goto back;
				}
			// So Dong  : 
				int oldsdo = mb->sodong;
				clearRect(x+10,y*5,2,1);
				mb->sodong = InputNumber2(x+10+sodong_len,y*5,mb->sodong,1,MAX_DONG,2,BLACK,GREEN,esc);
				if (esc) {
					clearRect(x,y,50,20);
					// Nhan ESC =>  Tro ve vi tri chon luc nay
					mb->loai = old;
					mb->soday = oldsd; 
					mb->sodong = oldsdo;
					goto back;
				}
			// Thoat that su chi khi enter 3 lan 
			
			Cursor(false);
			clearRect(106, 5 + vitri*2, 3, 1);
			if(mb->loai != old || mb->sodong != oldsdo || mb->soday != oldsd )
			{
				gotoxy(0,0);
				drawText(x,y+18, "SUA THANH CONG", GREEN);
				Sleep(900);
				change = true;
			}
			gotoxy(0,0);
			clearRect(x,y,50,25);
			gotoxy(0,0);
			return change;
	}

void xoaMayBay(int from, int to, int color, bool &reload){
	int vitri = -1; 
	// ----------------------Chon May Bay -----------------------------------------------------------------------------
		int width = 3, height = 1, step=2;
		int i = 0;
		bool esc = false;
	back:
		Cursor(false);
		char c ;
		int x = 106, y = 5,
		 n = to - from -1,
		 len = dsmb->laydodai();
	i = (vitri == -1) ? 0 : vitri - from ;
	// To mau thang dau tien 
	drawFillRect(x, y + i*step, width, height, color );
	while(1){
		c = getch();
		if (c == -32){
			c = getch();
			// Chon vi tri 
			if (c == UP){ 
				clearRect(x, y + i*step , width, height);		
				if(i > 0) i--;
				else i = 0;
				drawFillRect(x, y + i*step , width, height, color );		
			}
			if (c == DOWN){ 
				clearRect(x, y + i*step , width, height);
				if(i < n) i++;
				else i = n;
				drawFillRect(x, y + i*step, width, height, color );
			}
			// Qua 1 trang moi 
			if (c == LEFT){
				clearRect(x, y + i*step, width, height);
				to = (from != 0) ? from : to;
				from = (from - 10 < 0) ? 0 : from -10;
				clearRect(4,4,100,22);
				
				dsmb->lietkeMB(4,2,from,to);
				i=0; n = to - from -1;
				drawFillRect(x, y + i*step, width, height, color );
			}
			if (c == RIGHT){
				clearRect(x, y + i*step, width, height);
				from = (to != len) ? to : from;
				to = (to + 10 > len) ? len : to + 10;
				clearRect(4,4,100,22);
				
				dsmb->lietkeMB(4,2,from,to);
				i = 0; n = to - from -1;
				drawFillRect(x, y + i*step, width, height, color );
			}
		}
		// ENTER => Xuong phia duoi thuc hien tiep
		if (c == ENTER){
			clearRect(x, y + (i)*step, width, height);
			vitri = from+i;
			break;
		}
		// ESC => Thoat ra khoi chuong trinh
		if(c == ESC){
			clearRect(x, y + (i)*step, width, height);
			vitri = -1;
			reload = true;
			return;
		}
	}
	// --------------------------- XOA MAY BAY ---------------------------------------------------------
	if(vitri == -1){
		reload = false;
		return ;	
	}else{
		char c;
		MB *mb = dsmb->getMB(vitri);
		string msg= "Xoa may bay tai vi tri [ "+itos(vitri+1)+" ] khong (y,n)? -> ";
		// Neu may bay chua duoc dang ki => Xoa thanh cong ( can reload )
		if(mb->tt == 0){
			clearRect(120,4,msg.length()+3, 1);
			drawText(120,4,msg,color);
			cin>>c;
			if(c == 'y'){
			dsmb->xoa(vitri);
			drawText(120,6,"Xoa thanh cong",color);
			Sleep(900);
			}
			clearRect(106, 5 + vitri*2, 3, 1);
			clearRect(120,4,msg.length()+3, 20);
		}
		// Neu may bay da duoc dang ki  => Xoa that bai ( khi that bai thi khong can reload )
		else{
			msg = "Khong the xoa do da duoc dang ki chuyen bay";
			drawText(120,6,msg,color);
			Sleep(1000);
			clearRect(106, 5 + vitri*2, 3, 1);
			clearRect(120,4,msg.length()+3, 20);
			reload = false;
			// Xoa xong thi tro ve vi tri chon luc nay
			goto back;
		}
		reload = true;
		return ;
	}
}

bool xoaMayBayv2(int &from, int &to, int &page, int color){
// ----------------------Chon May Bay -----------------------------------------------------------------------------
		int width = 3, height = 1, step=2,
		vitri = -1; 
		bool esc = false, change = false;
	back:
		bool move = false;
		char c;
		int x = 106, y = 5,
		n = dsmb->laydodai(),
		npage = ( n >= 10 ? ( n%10 != 0 )? n/10 + 1 : n/10 : 1);
		int cur = to - 1;
		if( n == 0 ) return change;
	// To mau thang dau tien 
	Cursor(false);
	clearRect(x,y,width,height);
	if(vitri != -1){
		drawFillRect(x, y + (to-1 - vitri)*step, width, height, color );
		cur = vitri;
	}else
	drawFillRect(x, y,width,height,color );
	while(1){
		if(move){
			clearRect(4,4,100,22);
			move = false;
			drawFillRect(x,y+(to-1 - cur)*step,width,height,color);
			
			// Trang 1 / 2 --------------- 
			drawText(36,27,"Trang ",WHITE);
			drawNumber(43,27,page,WHITE);
			drawText(46,27,"/",WHITE);
			drawNumber(49,27,npage,YELLOW);
			// --------------------------- 
			dsmb->lietkeMBnguoc(4,2,from,to);
		}
		c = getch();
		if (c == -32){
			c = getch();
			// Chon vi tri 
			if (c == UP){ 
				if(cur < to-1){
				clearRect(x, y + (to-1 - cur)*step , width, height);		
				cur++;
				drawFillRect(x, y + (to-1 - cur)*step , width, height, color );		
				}
			}
			if (c == DOWN){ 
				if(cur > from){
				clearRect(x, y + (to-1 - cur)*step , width, height);		
				cur--;
				drawFillRect(x, y + (to-1 - cur)*step , width, height, color );		
				}
			}
			// Qua 1 trang moi 
			if (c == LEFT){
					if( to + 10 <= n){
					clearRect(x, y + (to-1 - cur)*step, width, height);
					from = to;
					to = to + 10 >= n? n : to + 10 ;
					move = true;
					page--;	
					cur = to-1;
					drawFillRect(x,y + (to-1 - cur)*step, width, height, color );
				}	
				
			}
			if (c == RIGHT){
				if( to > 10 ){
					clearRect(x, y + (to-1 - cur)*step, width, height);
					to = from;
					from = to - 10 <= 0? 0 : to - 10 ;
					move = true;
					page++;	
					cur = to-1;
					drawFillRect(x, y + (to-1 - cur)*step, width, height, color );
				}	
			
			}
		}
		// Enter => Xuong phia duoi thuc hien tiep
		if (c == ENTER){
			vitri = cur;
			break;
		}
		// ESC => Thoat ra khoi chuong trinh
		if(c == ESC){
			gotoxy(0,0);
			clearRect(120,4,40, 20);
			clearRect(x, y + (to-1-cur)*step, width, height);
			vitri = -1;
			return change;
		}
	}

	// --------------------------- XOA MAY BAY ---------------------------------------------------------
	if(vitri == -1){
		goto back;	
	}
		char c1;
		MB *mb = dsmb->getMB(vitri);
		string msg= "XOA MAY BAY CO SO HIEU ";
		// Neu may bay chua duoc dang ki => Xoa thanh cong ( can reload )
		if(mb->tt == 0){
			clearRect(120,4,msg.length()+3, 1);
			drawText(120,4,msg,color);
			drawText(120+msg.length(),4,mb->sohieu,YELLOW);
			drawText(120+msg.length()+mb->sohieu.length(),4," KHONG (Y,N): ",RED);
			c1 = getch();
			if(c1 == 'y' || c1 == 'Y'){
				dsmb->xoa(vitri);
				drawText(120,6,"XOA THANH CONG",GREEN);
				Sleep(600);
				clearRect(106, 5 + (to-1 - vitri)*2, 3, 1);
				clearRect(120,4, 50, 20);
				change = true;
				return change;
			}else{
				gotoxy(0,0);
				clearRect(120,4,50, 20);
				goto back;
			}
		}
		// Neu may bay da duoc dang ki  => Xoa that bai ( khi that bai thi khong can reload )
		else{
			msg = "KHONG THE XOA MAY BAY DO DA DANG KY ";
			drawText(120,6,msg,color);
			Sleep(600);
			clearRect(120,4, 50, 20);
			gotoxy(0,0);
			// Xoa xong thi tro ve vi tri chon luc nay
			goto back;
		}
}

bool timMayBayv2(int &from , int &to, int &page, int color ){
	// ----------------------Chon May Bay -----------------------------------------------------------------------------
		int width = 3, height = 1, step=2, xi = 120 , yi = 4 , mx = 20, 
		vitri = -1, vt = -1; 
		
		bool esc = false, change = false, write = false ,move = false, back = false;
		int txtcolor;
		string tmp = "";
	back:
		clearRect(120,4,55, 28);
		char c = '\0';
		int x = 106, y = 5;
		int n = dsmb->laydodai();
		
		if( n == 0 ) return change;
		string *a; dsmb->laysohieu( a );
		int indexs[n], dem = 0;
		int npage = ( n >= 10 ? ( n%10 != 0 )? n/10 + 1 : n/10 : 1);
		bool lietketen = false;
		if(change) {
			 	if(back) {
					if(to % 10 == 1) { 	
			 			if(page == npage + 1) page--;
						to = ( to + 10 < n) ? to+ 10 : ( to == 11 ) ? n : n + 1;
					} to--;
					from = from == 0 ? from : from - 1;
				 }
			move = true;
		}
		int cur = to - 1;
	// To mau thang dau tien 
	Cursor(false);
	clearRect(x,y,width,height);
	if(vitri != -1){
		if(back) if(vitri == to) vitri = to-1;
		drawFillRect(x, y + (to - 1 - vitri)*step, width, height, color );
		cur = vitri;
	}else
	drawFillRect(x, y,width,height,color );
	string msg = "TIM KIEM MAY BAY : ";
	drawText(xi,yi,msg,YELLOW);
	back = false;
	if(tmp != ""){
		drawText(xi+mx,yi,tmp,txtcolor);
	}
	while(1){
		if(move){
			clearRect(4,4,100,22);
			move = false;
			drawFillRect(x,y+(to-1 - cur)*step,width,height,color);
			
			// Trang 1 / 2 --------------- 
			drawText(36,27,"Trang ",WHITE);
			drawNumber(43,27,page,WHITE);
			drawText(46,27,"/",WHITE);
			drawNumber(49,27,npage,YELLOW);
			// --------------------------- 
			dsmb->lietkeMBnguoc(4,2,from,to);
		}
		
		if(tmp.size() != 0 && c == '\0'){
				dem= 0;
				Reint(indexs,n);
				vt = -1;
				clearRect(xi+mx,yi+1,C15+18,12);
				for( int i = 0 ; i < n ; i++ ){
					if( search(upper(tmp), a[i].substr(0,a[i].length()-1)) != "" ){  
						if(dem < 10){
							indexs[dem++] = i;
						}else{
							drawText( xi + mx + 2, yi + 11,".......",YELLOW);
							drawText( xi + mx , yi + 12, "CHI CHON DUOC KHI SO LUONG <= 10", RED );
						}
						// NEU DEM = 1 THI OUT RA CHO THONG TIN LUON KEM CHUC NANG 
						 	if(dem == 1) vt = i;
						}
					}
					// LIET KE THEO INDEXS STRING TYPE 
					if( dem != 0)
					{
						lietketen = true;
						goto lietketen;	
					}
				}
		// LIET KE THEO TEN 
			lietketen:
			if(lietketen){
				for( int i = 0; i < dem ; i++){
					txtcolor = mauTrangthai(stoi( a[indexs[i]].substr(a[indexs[i]].length()-1,1) ));
					drawText(xi+mx + 2, yi+1 + i , a[indexs[i]].substr(0,a[indexs[i]].length()-1), txtcolor );
				}
				lietketen = false;
				
			}	
		c = getch();
		if (c == -32){
			c = getch();
			// Chon vi tri 
			if (c == UP){ 
				if(cur < to-1){
				clearRect(x, y + (to-1 - cur)*step , width, height);		
				cur++;
				drawFillRect(x, y + (to-1 - cur)*step , width, height, color );		
				}
			}
			if (c == DOWN){ 
				if(cur > from){
				clearRect(x, y + (to-1 - cur)*step , width, height);		
				cur--;
				drawFillRect(x, y + (to-1 - cur)*step , width, height, color );		
				}
			}
			// Qua 1 trang moi 
			if (c == LEFT){
//				clearRect(x, y + (to-1 - cur)*step, width, height);
					if( to + 10 <= n){
					clearRect(x, y + (to-1 - cur)*step, width, height);
					from = to;
					to = to + 10 >= n? n : to + 10 ;
					move = true;
					page--;	
					cur = to-1;
					drawFillRect(x,y + (to-1 - cur)*step, width, height, color );
				}	
				
			}
			if (c == RIGHT){
//				clearRect(x, y + (to-1 - cur)*step, width, height);
				if( to > 10 ){
					clearRect(x, y + (to-1 - cur)*step, width, height);
					to = from != 0 ? from : to ;
					from = to - 10 <= 0? 0 : to - 10 ;
					move = true;
					page++;	
					cur = to-1;
					drawFillRect(x, y + (to-1 - cur)*step, width, height, color );
				}	
			
			}
		}else{
			if( tmp.size() < C15 ){
			if( c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9'){
				gotoxy(xi + mx + tmp.size(), yi);
				tmp += c;
				cout<<c;
				dem= 0;
				Reint(indexs,n);
				vt = -1;
				clearRect(xi+mx,yi+1,C15+18,12);
				for( int i = 0 ; i < n ; i++ ){
					if( search(upper(tmp), a[i].substr(0,a[i].length()-1)) != "" ){  
						if(dem < 10){
							indexs[dem++] = i;
						}else{
							drawText( xi + mx + 2, yi + 11,".......",YELLOW);
							drawText( xi + mx , yi + 12, "CHI CHON DUOC KHI SO LUONG <= 10", RED );
						}
						// NEU DEM = 1 THI OUT RA CHO THONG TIN LUON KEM CHUC NANG 
						 	if(dem == 1) vt = i;
						}
					}
					// LIET KE THEO INDEXS STRING TYPE 
					if( dem != 0)
					{
						lietketen = true;
						goto lietketen;	
					}
					
				
				}
			}	
			if( c == BACKSPACE ){
				
				if ( tmp.size() > 0  )
				{
				tmp.erase(tmp.size() - 1 , 1 ); 
				gotoxy(xi + mx + tmp.size()+1,yi);
				cout<<"\b ";		 
				}
				
				dem= 0;
				Reint(indexs,n);
				vt = -1;
				clearRect(xi+mx,yi+1,C15+18,12);
				if(tmp.size() != 0){
				//clearRect(xi+mx,yi+1,C15+18,12);
				for( int i = 0 ; i < n ; i++ ){
					if( search(upper(tmp), a[i].substr(0,a[i].length()-1)) != "" ){  
						if(dem < 10){
							indexs[dem++] = i;
						}else{
							drawText( xi + mx + 2 , yi + 11,".......",YELLOW);
							drawText( xi + mx , yi + 12, "CHI CHON DUOC KHI SO LUONG <= 10", RED );
						}
						// NEU DEM = 1 THI OUT RA CHO THONG TIN LUON KEM CHUC NANG 
						 	if(dem == 1) vt = i;
						}
					}
					// LIET KE THEO INDEXS STRING TYPE 
					if( dem != 0)
					{
						lietketen = true;
						goto lietketen;	
					}
				}
				
			}
			
			
		}
		// Enter => Xuong phia duoi thuc hien tiep
		
		if (c == ENTER){
			
			// Vitri la luc chon bang con tro
			if( dem == 1 )	{
				txtcolor = mauTrangthai(stoi( a[vt].substr(a[vt].length()-1,1) ));
				drawText(xi+mx, yi, a[vt].substr(0,a[vt].length()-1), txtcolor );
				clearRect(xi+mx, yi+1, 20, 1);	
				goto end_loop;			
			break;
			}else if(dem >1 && dem <= 10){
				clearRect(4,4,100,22);
				clearRect(x, y + (to-1-cur)*step, width, height);
				
				// LIET KE THEO INDEXS dem phan tu 
				dsmb->lietkeMBtheo(4,2,indexs,dem);
				// CHO CHON LUA 
				cur = chonMayBay(0,dem,color);
				if( cur == -1) {
					txtcolor = WHITE;
					move = true;
					goto back;
				}else {
					vt = indexs[cur];
					move = true;
					txtcolor = mauTrangthai(stoi( a[vt].substr(a[vt].length()-1,1) ));
					drawText(xi+mx, yi, a[vt].substr(0,a[vt].length()-1), txtcolor );
					clearRect(xi+mx, yi+1, 20, dem-1);	
					
				goto end_loop;
				}
			
			}else if(dem == 0){
				vitri = cur;
				vt = vitri;
				txtcolor = mauTrangthai(stoi( a[vt].substr(a[vt].length()-1,1) ));
				drawText(xi+mx, yi, a[vt].substr(0,a[vt].length()-1), txtcolor );
				clearRect(xi+mx, yi+1, 20, 1);	
				goto end_loop;			
			}
		}
		// ESC => Thoat ra khoi chuong trinh
		if(c == ESC){
			gotoxy(0,0);
			clearRect(120,4,55, 20);
			clearRect(x, y + (to-1-cur)*step, width, height);
			vitri = -1;
			delete[] a;
			return change;
		}
	
	}	
	end_loop:
	Cursor(false);
	clearRect(x, y + (to-1-cur)*step, width, height);
	gotoxy(0,0);
	clearRect(120,4,58, 20);
	gotoxy(0,0);
	msg = "TIM KIEM MAY BAY : ";
	drawText(xi,yi,msg,YELLOW);
	drawText(xi+mx, yi, a[vt].substr(0,a[vt].length()-1), txtcolor );
	// TRA RA KET QUA CAN TIM 
	MB *mb = dsmb->getMB(vt);
	// lietke theo bang 
	
	// THONG TIN CUA MAY BAY :
	drawText(xi,yi+5,"So Hieu  : ",YELLOW); drawText(xi+20,yi+5,mb->sohieu,mauTrangthai(mb->tt));
	drawText(xi,yi+7,"Loai    : ",YELLOW);  drawText(xi+20,yi+7,mb->loai, CYAN);
	drawText(xi,yi+9,"So Day  : ",YELLOW);  drawText(xi+20,yi+9,itos(mb->soday), CYAN);
	drawText(xi,yi+11,"So Dong : ",YELLOW);  drawText(xi+20,yi+11,itos(mb->sodong), CYAN);
	
	drawText(xi,yi+18," BAN CO MUON CHON CHUC NANG ? ",GREEN);
	
	drawButton(xi,yi+ 20,CYAN,4,27,"2","SUA");
	drawButton(xi, yi+ 23,GREEN,4,27,"3","XOA");
	drawButton(xi, yi+ 26,RED,4,27,"ESC"," QUAY LAI ");
	choose:
	
	char c1 = getch();
	// Sua MINI 
	if( c1 == '2' ){
			x = xi;
			y= yi;
			msg= "SUA MAY BAY TAI VI TRI ";
			if(mb->tt == 1) 
			{
				string msg="KHONG THE SUA VI DANG DUOC DANG KY";
				drawText(xi,yi+14,msg,RED);
				Sleep(600);
				clearRect(xi,yi+14,msg.length(),1);
				goto choose;
			}
			clearRect(120,4,55, 30);
			esc = false;
			// Viet Label thong bao 
			clearRect(x,y,msg.length()+5, 1);
			drawText(x,y,msg,CYAN);
			drawNumber(x+2+msg.length(),y,cur+1,CYAN);
			// Viet Label nhap 
			drawText(x,y*2,"So Hieu : ",WHITE);	drawText(x+10,y*2,mb->sohieu,GREEN);
			drawText(x,y*3,"Loai    : ",WHITE);	drawText(x+10,y*3,mb->loai,GREEN);
			drawText(x,y*4,"So Day  : ",WHITE); drawNumber(x+10,y*4,mb->soday,GREEN);
			drawText(x,y*5,"So Dong : ",WHITE);	drawNumber(x+10,y*5,mb->sodong,GREEN);
			int soday_len  = (mb->soday  /10 > 0) ? 2 : 1;
			int sodong_len = (mb->sodong /10 > 0) ? 2 : 1;
			// So hieu : ( Khong thay doi )  
			
			// Loai    : 
				string old = mb->loai;
				InputString(x+10 + mb->loai.length(),y*3,x+20,y*3+2,40,mb->loai,false,esc);
				if (esc) {
					clearRect(x,y,50,20);
					// Nhan ESC =>  Tro ve vi tri chon luc nay
					mb->loai = old;
					goto end_loop;
				}
			// So day  : 
				clearRect(x+10,y*4,2,1);
				int oldsd = mb->soday;
				mb->soday = InputNumber2(x+10+soday_len,y*4,mb->soday,1,MAX_DAY,2,BLACK,GREEN,esc);
				if (esc) {
					clearRect(x,y,50,20);
					// Nhan ESC =>  Tro ve vi tri chon luc nay
					mb->loai = old;
					mb->soday = oldsd; 
					goto end_loop;
				}
			// So Dong  : 
				int oldsdo = mb->sodong;
				clearRect(x+10,y*5,2,1);
				mb->sodong = InputNumber2(x+10+sodong_len,y*5,mb->sodong,1,MAX_DONG,2,BLACK,GREEN,esc);
				if (esc) {
					clearRect(x,y,50,20);
					// Nhan ESC =>  Tro ve vi tri chon luc nay
					mb->loai = old;
					mb->soday = oldsd; 
					mb->sodong = oldsdo;
					goto end_loop;
				}
			// Thoat that su chi khi enter 3 lan 
			
			Cursor(false);
			clearRect(106, 5 + cur*2, 3, 1);
			if(mb->loai != old || mb->sodong != oldsdo || mb->soday != oldsd )
			{
				gotoxy(0,0);
				drawText(x,y+18, "SUA THANH CONG", GREEN);
				Sleep(900);
				change = true;
				gotoxy(0,0);
				clearRect(x,y,50,25);
				gotoxy(0,0);
				delete[] a;
				goto back;
			}else{
				gotoxy(0,0);
				clearRect(x,y,50,25);
				gotoxy(0,0);
				delete[] a;
				goto end_loop;
			}
			
	}
	// Xoa MINI
	if( c1 == '3'){
			x = xi;
			y= yi;
			msg= "XOA MAY BAY TAI VI TRI ";
			if(mb->tt == 1) 
			{
				string msg="KHONG THE XOA VI DA DUOC DANG KY";
				drawText(xi,yi+14,msg,RED);
				Sleep(600);
				clearRect(xi,yi+14,msg.length(),1);
				goto choose;
			}else{
				
				clearRect(120,4,55, 30);
				clearRect(120,4,msg.length()+3, 1);
				drawText(120,4,msg,RED);
				drawText(120+msg.length(),4,mb->sohieu,YELLOW);
				drawText(120+msg.length()+mb->sohieu.length(),4," KHONG (Y,N): ",RED);
				c1 = getch();
				if(c1 == 'y' || c1 == 'Y'){
					dsmb->xoa(vt);
					drawText(120,6,"XOA THANH CONG",GREEN);
					Sleep(600);
					clearRect(120,4, 50, 20);
					change = true;
					delete[] a;
					back = true;
					goto back;
				}else{
					gotoxy(0,0);
					clearRect(120,4,50, 20);
					goto end_loop;
				}
			}
	}
	
	// QUAY LAI
	if( c1 == ESC ){
		c1 = '\0';
		c = '\0';
		write = true;
		goto back;
	}
	if( c1 != ESC && c1 != '3' && c1 != '2') goto choose;

	
}

int chonMayBay(int from , int to, int color){
	// Khoi tao
	int width = 3, height = 1, step=2, x = 106 , y = 5 , mx = 20, 
		vitri = -1, vt = -1; 
	char c = '\0';
	int cur = from;
	// To mau thang dau tien 
	drawFillRect(x, y , width, height, color );
	while(1){
		c = getch();
		if (c == -32){
			c = getch();
			// Chon vi tri 
			if (c == UP){ 
				clearRect(x, y + cur*step , width, height);
				
				if(cur > from) cur--;
				else cur = from;
				
				drawFillRect(x, y + cur*step , width, height, color );		
			}
			if (c == DOWN){ 
				clearRect(x, y + cur*step , width, height);
				
				if(cur < to - 1) cur++;
				else cur = to - 1;
				
				drawFillRect(x, y + cur*step, width, height, color );
			}
		
		}
		if (c == ENTER){
			clearRect(x, y + (cur)*step, width, height);
			return cur;
		}
		if(c == ESC){
			clearRect(x, y + (cur)*step, width, height);
			return -1;
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------------------//
//                                                           HANH KHACH                                                             //  
//  --------------------------------------------------------------------------------------------------------------------------------//

void TieudeHanhKhach(int start_x,int start_y){
	drawRect(start_x,start_y,100,2);
	draw_high_line(start_x+20,start_y,2);
	drawText(start_x+4,start_y+1,"CMND",WHITE);
	draw_high_line(start_x+54,start_y,2);
	drawText(start_x+28,start_y+1,"HO ",WHITE);
	draw_high_line(start_x+77,start_y,2);
	drawText(start_x+56,start_y+1,"TEN",WHITE);
	drawText(start_x+80,start_y+1,"PHAI",WHITE);		
}

int mauTrangthai( bool ranh){
	return (ranh == 1)? RED: GREEN;
}

void menuHK(){
	bool change = false;
	TieudeHanhKhach(4,2);
	ThanhHuongDan(HD_HK, n_HK, 40, 3, 40);
	nutDieukhien(80,32,6,-1,false,true,false);
	//clearRect(80,32 - 6/2,24,6);
	
	drawText(5,30,"Chua dang ki chuyen bay",GREEN);
	drawText(5,32,"Da dang ki chuyen bay",RED);
	
	int c ;
	bool reload = true, press = false, move = false, esc = false, enter = false;
	int  n = mhk.getN(), to = n , from = ( to - 10 >= 0) ? to - 10 : 0 
	, cur1 = 0, page = 1 , npage = ( n >= 10 ? ( n%10 != 0 )? n/10 + 1 : n/10 : 1)
	, pre = -1;
	while(1){
		if(esc){
			if(change){
				char c1;
				drawText(140,41,"LUU VA THOAT (Y/N/ESC) ? ",RED);
				c1 = getch();
				if( c1 == 'y' || c1 == 'Y' )
					{
					mhk.luu();
					return ; 
					}
				else if( c1 == 'n' || c1 == 'N' ) {
					esc = false;
					clearRect(140,41,23,1);
				}
				// ESC ESC khi co su thay doi
				else{
					mhk = mangHK();
					return;
				} 
			}else return;
		}
		if (reload){
			page = 1;n = mhk.getN();npage = ( n >= 10 ? ( n%10 != 0 )? n/10 + 1 : n/10 : 1);
			to = n; from = ( to - 10 >= 0) ? to - 10 : 0; 
			reload = false;
			clearRect(4,5,100,22);
			// Trang 1 / 2 --------------- 
			drawText(36,27,"Trang ",WHITE);
			drawNumber(43,27,page,WHITE);
			drawText(46,27,"/",WHITE);
			drawNumber(49,27,npage,YELLOW);
			// --------------------------- 
			mhk.lietkeHK(4,2,from,to);
			Cursor(false);
		}
		if (move){
			move = false;
			clearRect(4,4,100,22); // Xoa het cac ptu~ de~ in ra trang tiep theo
			mhk.lietkeHK(4,2,from,to);
			drawNumber(43,27,page,WHITE);
			Cursor(false);
		}
		KeyPress_3(cur1,from,to,page,n,reload,press,move,esc);
		if (press){
			switch(cur1){
				case 1: // 
					reload = themHanhKhach();		
					if(reload) change = true;
					cur1 = 0;
					break;
				case 2: // 
					clearRect(80,32 - 6/2,24,6);	
					nutDieukhien(75,32,6,-1,true,false,false);
					reload =  suaHanhKhach( from, to, page , CYAN );
					if(reload) change = true;
					cur1 = 0;
					clearRect(75,32 - 6/2,30,6);
					break;
				case 3: // 
					clearRect(80,32 - 6/2,24,6);
					nutDieukhien(75,32,6,-1,true,false,false);
					reload =  xoaHanhKhach( from, to, page , RED );
					if(reload) change = true;
					cur1 = 0;
					clearRect(75,32 - 6/2,30,6);
					break;
				case 4: //
					clearRect(80,32 - 6/2,24,6);
					nutDieukhien(75,32,6,-1,true,false,false);
					reload =  timHanhKhach( from, to, page , WHITE );
					if(reload) change = true;
					cur1 = 0;
					clearRect(75,32 - 6/2,30,6);
					break;
				case ESC: //
					esc = true;
					return;
					break;
				default:
					break;
			}
			nutDieukhien(80,32,6,-1,false,true,false);			
			press = false;
			Cursor(false);
			
		}
	}
}

bool themHanhKhach(){
	
	bool check=false,change = false,esc = false;
	string msg = "THEM HANH KHACH";
	clearRect(130,2,msg.length(),1);
	drawText(130,2,msg,YELLOW);
	
	int x = 120, y = 4, sohieulen = 0;
	drawText(120,4,"CMND     : ",WHITE);
	drawText(120,10,"Ho      : ",WHITE);
	drawText(120,16,"Ten     : ",WHITE);
	drawText(120,22,"Phai    : ",WHITE);
	HK hk;
	move:
	clearRect(140,5,18,1);
	InputString(x+20+sohieulen,y,140,5,C12,hk.cmnd,true,esc);
	if ( hk.cmnd.size() < C12 ){
		if (esc) {
		clearRect(x,y,55,20);
		clearRect(130,2,msg.length(),1);
	
		return change;
		}
		drawText(140,5,"CMND BAT BUOC 12 SO",RED);
		Sleep(500);
		sohieulen = hk.cmnd.length();
		goto move;	
	}
	if ( mhk.tim(hk.cmnd) != -1 ){
		if (esc) {
		clearRect(x,y,55,20);
		clearRect(130,2,msg.length(),1);
	
		return change;
		}	
		drawText(140,5,"CMND DA TON TAI",RED);
		Sleep(500);
		sohieulen = hk.cmnd.length();
		goto move;	
	}
	if (esc) {
		clearRect(x,y,55,20);
		clearRect(130,2,msg.length(),1);
	
		return change;
	}
	InputString(x+20,y+6,140,11,C40,hk.ho,check,esc);
	if (esc) {
		clearRect(x,y,55,20);
		clearRect(130,2,msg.length(),1);
	
		return change;
	}
	InputString(x+20,y+12,140,17,C15,hk.ten,false,esc);
	if (esc) {
		clearRect(x,y,55,20);
		clearRect(130,2,msg.length(),1);
	
		return change;
	}
	InputGender(x+20,y+18,hk.phai,esc);
	if (esc) {
		clearRect(x,y,55,20);
		clearRect(130,2,msg.length(),1);
	
		return change;
	}
	hk.scb = 0;
	mhk.them(hk);
	clearRect(x,y,55,20);
	change = true;
	clearRect(130,2,msg.length(),1);
	
	return change;
}

bool suaHanhKhach(int &from, int &to, int &page, int color){
		// -------------------------------------------------- CHON CHUYEN BAY CAN XOA ------------------------------------
		int width = 3, height = 1, step = 2;
		bool check = false, esc = false, change = false;
		int vitri = -1;
	back:
		int  n = mhk.getN() , npage = ( n >= 10 ? ( n%10 != 0 )? n/10 + 1 : n/10 : 1);
		// Muon xoa nhieu hay thay doi nhieu thi sua o day => bo change len tren 
		if( n == 0 ) return change;
		bool move = false; 
		int cur = to-1, x = 106, y = 5;
		char c;
	Cursor(false);
	clearRect(x,y,width,height);
	if(vitri != -1)
	{
	drawFillRect(x,y+(to-1 - vitri)*step,width,height,color);
	cur = vitri;
	}else
	drawFillRect(x,y,width,height,color);
	while(1){
		if(move)
		{
			clearRect(4,4,100,22);
			move = false;
			drawFillRect(x,y+(to-1 - cur)*step,width,height,color);
			// Trang 1 / 2 --------------- 
			drawText(36,27,"Trang ",WHITE);
			drawNumber(43,27,page,WHITE);
			drawText(46,27,"/",WHITE);
			drawNumber(49,27,npage,YELLOW);
			// --------------------------- 
			mhk.lietkeHK(4,2,from,to);
		}
		c = getch();
		if (c == -32){
			c = getch();
			if (c == LEFT){
				if( to + 10 <= n){
					clearRect(x,y+(to-1 - cur)*step,width,height);
					from = to;
					to = to + 10 >= n? n : to + 10 ;
					move = true;
					page--;	
					cur = to-1;
					drawFillRect(x,y+(to-1 - cur)*step,width,height,color);
				}			
			}
		// Luc dau to = maxlen && from = to - 10
			if (c == RIGHT){ 		
				if( to > 10){
					clearRect(x,y+(to-1 - cur)*step,width,height);
					to = from;
					from = to - 10 <= 0? 0 : to - 10 ;
					move = true;
					page++;	
					cur = to-1;
					drawFillRect(x,y+(to-1 - cur)*step,width,height,color);
				}	
			}
			if (c == UP){
				if(cur < to-1){
					clearRect(x,y+(to-1 - cur)*step,width,height);
				 	cur++;
				 	drawFillRect(x,y+(to-1 - cur)*step,width,height,color);
				} 	
			}
			if (c == DOWN){
				if(cur > from) {
					clearRect(x,y+(to-1 - cur)*step,width,height);
					cur--;
					drawFillRect(x,y+(to-1 - cur)*step,width,height,color);
				}	
			}
		}
		if (c == ESC) {
			clearRect(120,2,40,1);
			clearRect(x,y+(to-1 - cur)*step,width,height);
			gotoxy(0,0);
			vitri = -1;
			return change;
		}
		if (c == ENTER) {
			vitri = cur;
			break;
		}
	}
	
	x = 115; y= 4;
	if(vitri == -1){
		goto back;
	}
	HK hk = mhk.getHK(vitri);	
	HK edithk = hk ;
	string msg = " THAY DOI THONG TIN HANH KHACH ";
	string phai = hk.phai ? "1" : "0";
	drawText(130,2,msg,color);
	drawText(120,4,"CMND     : ",WHITE);  	drawText(x+20,4,hk.cmnd,mauTrangthai(hk.ranh));
	drawText(120,10,"Ho      : ",WHITE);	drawText(x+20,10,hk.ho,YELLOW);
	drawText(120,16,"Ten     : ",WHITE);	drawText(x+20,16,hk.ten,YELLOW);
	drawText(120,22,"Phai    : ",WHITE);	drawText(x+20,22,phai,YELLOW);
	InputString(x+20 + edithk.ho.length(),y+6,140,11,C40,edithk.ho,check,esc);
	if (esc) {
		clearRect(x,y,55,20);
		clearRect(130,2,msg.length(),1);
		goto back;
	}
	InputString(x+20 + edithk.ten.length(),y+12,140,17,C15,edithk.ten,false,esc);
	if (esc) {
		clearRect(x,y,55,20);
		clearRect(130,2,msg.length(),1);
		goto back;
	}
	InputGender(x+20,y+18,edithk.phai,esc);
	if (esc) {
		clearRect(x,y,55,20);
		clearRect(130,2,msg.length(),1);
		goto back;
	}
	if(edithk.ho != hk.ho || edithk.phai != hk.phai || edithk.ten != hk.ten){
		drawText(x+10,y+20,"THAY DOI THONG TIN THANH CONG", GREEN);
		Sleep(600);
		change = true;
		mhk.sua(edithk);
	}else{
		drawText(x+10,y+20,"THONG TIN KHONG THAY DOI", GREEN);
		Sleep(600);
	}
	clearRect(120,2,40,1);
	clearRect(x,y,55,20);
	clearRect(130,2,msg.length(),1);
	clearRect(106,5+(to-1 - vitri)*step,width,height);
	
	return change;
}

bool xoaHanhKhach(int &from, int &to, int &page , int color){
		// -------------------------------------------------- CHON CHUYEN BAY CAN XOA ------------------------------------
		int width = 3, height = 1, step = 2;
		bool esc = false, change = false;
		int vitri = -1;
	back:
		int  n = mhk.getN() , npage = ( n >= 10 ? ( n%10 != 0 )? n/10 + 1 : n/10 : 1);
		// Muon xoa nhieu hay thay doi nhieu thi sua o day => bo change len tren 
		if( n == 0 ) return change;
		bool move = false; 
		int cur = to-1, x = 106, y = 5;
		char c;
	Cursor(false);
	clearRect(x,y,width,height);
	if(vitri != -1)
	{
	drawFillRect(x,y+(to-1 - vitri)*step,width,height,color);
	cur = vitri;
	}else
	drawFillRect(x,y,width,height,color);
	while(1){
		if(move)
		{
			clearRect(4,4,100,22);
			move = false;
			drawFillRect(x,y+(to-1 - cur)*step,width,height,color);
			// Trang 1 / 2 --------------- 
			drawText(36,27,"Trang ",WHITE);
			drawNumber(43,27,page,WHITE);
			drawText(46,27,"/",WHITE);
			drawNumber(49,27,npage,YELLOW);
			// --------------------------- 
			mhk.lietkeHK(4,2,from,to);
		}
		c = getch();
		if (c == -32){
			c = getch();
			if (c == LEFT){
				if( to + 10 <= n){
					clearRect(x,y+(to-1 - cur)*step,width,height);
					from = to;
					to = to + 10 >= n? n : to + 10 ;
					move = true;
					page--;	
					cur = to-1;
					drawFillRect(x,y+(to-1 - cur)*step,width,height,color);
				}			
			}
		// Luc dau to = maxlen && from = to - 10
			if (c == RIGHT){ 		
				if( to > 10){
					clearRect(x,y+(to-1 - cur)*step,width,height);
					to = from;
					from = to - 10 <= 0? 0 : to - 10 ;
					move = true;
					page++;	
					cur = to-1;
					drawFillRect(x,y+(to-1 - cur)*step,width,height,color);
				}	
			}
			if (c == UP){
				if(cur < to-1){
					clearRect(x,y+(to-1 - cur)*step,width,height);
				 	cur++;
				 	drawFillRect(x,y+(to-1 - cur)*step,width,height,color);
				} 	
			}
			if (c == DOWN){
				if(cur > from) {
					clearRect(x,y+(to-1 - cur)*step,width,height);
					cur--;
					drawFillRect(x,y+(to-1 - cur)*step,width,height,color);
				}	
			}
		}
		if (c == ESC) {
			clearRect(120,2,40,1);
			clearRect(x,y+(to-1 - cur)*step,width,height);
			gotoxy(0,0);
			vitri = -1;
			return change;
		}
		if (c == ENTER) {
			vitri = cur;
			break;
		}
	}
	
	x = 115; y= 4;
	if(vitri == -1){
		goto back;
	}
	HK hk = mhk.getHK(vitri);
		
		char c1;
		string msg= "XOA HANH KHACH CO SO CMND ";
		// Neu hanh khach do chua ban => Xoa thanh cong ( can reload )
		if( hk.ranh && hk.tgban == "" && hk.scb == 0 ){
			clearRect(120,4,msg.length()+3, 1);
			drawText(120,4,msg,color);
			drawText(120+msg.length(),4,hk.cmnd,YELLOW);
			drawText(120+msg.length()+hk.cmnd.length(),4," KHONG (Y,N): ",RED);
			c1 = getch();
			if(c1 == 'y' || c1 == 'Y'){
				mhk.xoa(hk.cmnd);
				drawText(120,6,"XOA THANH CONG",GREEN);
				Sleep(600);
				clearRect(106, 5 + (to-1 - vitri)*2, 3, 1);
				clearRect(120,4, 50, 20);
				change = true;
				return change;
			}else{
				gotoxy(0,0);
				clearRect(120,4,50, 20);
				goto back;
			}
		}
		// Neu may bay da duoc dang ki  => Xoa that bai ( khi that bai thi khong can reload )
		else if(!hk.ranh){
			msg = "KHONG THE XOA HANH KHACH DO DANG BAN ";
			drawText(120,6,msg,color);
			Sleep(600);
			clearRect(120,4, 50, 20);
			gotoxy(0,0);
			// Xoa xong thi tro ve vi tri chon luc nay
			goto back;
		}else if(hk.tgban != ""){
			msg = "KHONG THE XOA HANH KHACH DA DAT VE ";
			drawText(120,6,msg,color);
			Sleep(600);
			clearRect(120,4, 50, 20);
			gotoxy(0,0);
			// Xoa xong thi tro ve vi tri chon luc nay
			goto back;
		}else if(hk.scb != 0){
			msg = "KHONG THE XOA HANH KHACH DA CO LICH SU DAT VE";
			drawText(120,6,msg,color);
			Sleep(600);
			clearRect(120,4, 50, 20);
			gotoxy(0,0);
			// Xoa xong thi tro ve vi tri chon luc nay
			goto back;
		}
	
}

int chonHanhKhach(int from , int to, int color){
	// Khoi tao
	int width = 3, height = 1, step=2, x = 106 , y = 5 , mx = 20, 
		vitri = -1, vt = -1; 
	char c = '\0';
	int cur = from;
	// To mau thang dau tien 
	drawFillRect(x, y , width, height, color );
	while(1){
		c = getch();
		if (c == -32){
			c = getch();
			// Chon vi tri 
			if (c == UP){ 
				clearRect(x, y + cur*step , width, height);
				
				if(cur > from) cur--;
				else cur = from;
				
				drawFillRect(x, y + cur*step , width, height, color );		
			}
			if (c == DOWN){ 
				clearRect(x, y + cur*step , width, height);
				
				if(cur < to - 1) cur++;
				else cur = to - 1;
				
				drawFillRect(x, y + cur*step, width, height, color );
			}
		
		}
		if (c == ENTER){
			clearRect(x, y + (cur)*step, width, height);
			return cur;
		}
		if(c == ESC){
			clearRect(x, y + (cur)*step, width, height);
			return -1;
		}
	}
}

bool timHanhKhach(int &from, int &to, int &page, int color){
		// -------------------------------------------------- CHON CHUYEN BAY CAN XOA ------------------------------------
		int width = 3, height = 1, step = 2, xi = 120, yi = 4, mx = 25;
		bool esc = false, change = false, back = false, move = false;
		int vitri = -1, vt = -1;
		int txtcolor;
		string tmp;
	back:
		
		clearRect(120,4,55, 28);
		
		int  n = mhk.getN() , npage = ( n >= 10 ? ( n%10 != 0 )? n/10 + 1 : n/10 : 1);
		// Muon xoa nhieu hay thay doi nhieu thi sua o day => bo change len tren 
		int indexs[n], dem = 0;
		if( n == 0 ) return change;
		string *a; mhk.layCMND(a);
		 bool lietketen = false; 
		int x = 106, y = 5;
		char c = '\0';
		Cursor(false);
		clearRect(x,y,width,height);
		if(change) {
			 	if(back) {
					if(to % 10 == 1) { 	
			 			if(page == npage + 1) page--;
						to = ( to + 10 < n) ? to+ 10 : ( to == 11 ) ? n : n + 1;
					} to--;
					from = from == 0 ? from : from - 1;
				 }
			move = true;
		}
	int cur = to-1;
	if(vitri != -1){
		if(back) if(vitri == to) vitri = to-1;
		drawFillRect(x,y+(to-1 - vitri)*step,width,height,color);
		cur = vitri;
	}else
	drawFillRect(x,y,width,height,color);
	back = false;
	string msg = "TIM KIEM HANH KHACH : ";
	drawText(xi,yi,msg,YELLOW);
	if(tmp != ""){
		drawText(xi+mx,yi,tmp,txtcolor);
	}
	while(1){
		if(move)
		{
			clearRect(4,4,100,22);
			move = false;
			drawFillRect(x,y+(to-1 - cur)*step,width,height,color);
			// Trang 1 / 2 --------------- 
			drawText(36,27,"Trang ",WHITE);
			drawNumber(43,27,page,WHITE);
			drawText(46,27,"/",WHITE);
			drawNumber(49,27,npage,YELLOW);
			// --------------------------- 
			mhk.lietkeHK(4,2,from,to);
		}
		
			if(tmp.size() != 0 && c == '\0'){
				dem= 0;
				Reint(indexs,n);
				vt = -1;
				clearRect(xi+mx,yi+1,C15+18,12);
				for( int i = 0 ; i < n ; i++ ){
					if( search(upper(tmp), a[i].substr(0,a[i].length()-1)) != "" ){  
						if(dem < 10){
							indexs[dem++] = i;
						}else{
							drawText( xi + mx + 2, yi + 11,".......",YELLOW);
							drawText( xi + mx , yi + 12, "CHI CHON DUOC KHI SO LUONG <= 10", RED );
						}
						// NEU DEM = 1 THI OUT RA CHO THONG TIN LUON KEM CHUC NANG 
						 	if(dem == 1) vt = i;
						}
					}
					// LIET KE THEO INDEXS STRING TYPE 
					if( dem != 0)
					{
						lietketen = true;
						goto lietketen;	
					}
				}
		// LIET KE THEO TEN 
			lietketen:
			if(lietketen){
				for( int i = 0; i < dem ; i++){
					txtcolor = mauTrangthai2(stoi( a[indexs[i]].substr(a[indexs[i]].length()-1,1) ));
					drawText(xi+mx + 2, yi+1 + i , a[indexs[i]].substr(0,a[indexs[i]].length()-1), txtcolor );
				}
				lietketen = false;
			}
		
		c = getch();
		if (c == -32){
			c = getch();
			if (c == LEFT){
				if( to + 10 <= n){
					clearRect(x,y+(to-1 - cur)*step,width,height);
					from = to;
					to = to + 10 >= n? n : to + 10 ;
					move = true;
					page--;	
					cur = to-1;
					drawFillRect(x,y+(to-1 - cur)*step,width,height,color);
				}			
			}
		// Luc dau to = maxlen && from = to - 10
			if (c == RIGHT){ 		
			
				if( from != 0){
					clearRect(x,y+(to-1 - cur)*step,width,height);
					to = from != 0 ? from : to ;
					from = to - 10 <= 0? 0 : to - 10 ;
					move = true;
					page++;	
					cur = to-1;
					drawFillRect(x,y+(to-1 - cur)*step,width,height,color);
				}	
			}
			if (c == UP){
				if(cur < to-1){
					clearRect(x,y+(to-1 - cur)*step,width,height);
				 	cur++;
				 	drawFillRect(x,y+(to-1 - cur)*step,width,height,color);
				} 	
			}
			if (c == DOWN){
				if(cur > from) {
					clearRect(x,y+(to-1 - cur)*step,width,height);
					cur--;
					drawFillRect(x,y+(to-1 - cur)*step,width,height,color);
				}	
			}
		}else{
			if( tmp.size() < 12 ){
			if( c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9'){
				gotoxy(xi + mx + tmp.size(), yi);
				tmp += c;
				cout<<c;
				dem= 0;
				Reint(indexs,n);
				vt = -1;
				clearRect(xi+mx,yi+1,C15+18,12);
				for( int i = 0 ; i < n ; i++ ){
					if( search(upper(tmp), a[i].substr(0,a[i].length()-1)) != "" ){  
						if(dem < 10){
							indexs[dem++] = i;
						}else{
							drawText( xi + mx + 2, yi + 11,".......",YELLOW);
							drawText( xi + mx , yi + 12, "CHI CHON DUOC KHI SO LUONG <= 10", RED );
						}
						// NEU DEM = 1 THI OUT RA CHO THONG TIN LUON KEM CHUC NANG 
						 	if(dem == 1) vt = i;
						}
					}
					// LIET KE THEO INDEXS STRING TYPE 
					if( dem != 0)
					{
						lietketen = true;
						goto lietketen;	
					}			
				}
			}	
			if( c == BACKSPACE ){
				
				if ( tmp.size() > 0  )
				{
				tmp.erase(tmp.size() - 1 , 1 ); 
				gotoxy(xi + mx + tmp.size()+1,yi);
				cout<<"\b ";		 
				}
				
				dem= 0;
				Reint(indexs,n);
				vt = -1;
				clearRect(xi+mx,yi+1,C15+18,12);
				if(tmp.size() != 0){
				//clearRect(xi+mx,yi+1,C15+18,12);
				for( int i = 0 ; i < n ; i++ ){
					if( search(upper(tmp), a[i].substr(0,a[i].length()-1)) != "" ){  
						if(dem < 10){
							indexs[dem++] = i;
						}else{
							drawText( xi + mx + 2 , yi + 11,".......",YELLOW);
							drawText( xi + mx , yi + 12, "CHI CHON DUOC KHI SO LUONG <= 10", RED );
						}
						// NEU DEM = 1 THI OUT RA CHO THONG TIN LUON KEM CHUC NANG 
						 	if(dem == 1) vt = i;
						}
					}
					// LIET KE THEO INDEXS STRING TYPE 
					if( dem != 0)
					{
						lietketen = true;
						goto lietketen;	
					}
				}
				
			}
			
		}
		if (c == ESC) {
			clearRect(120,2,40,1);
			clearRect(120,4,58, 20);
			clearRect(x,y+(to-1 - cur)*step,width,height);
			gotoxy(0,0);
			vitri = -1;
			return change;
		}
		if (c == ENTER) {
				// Vitri la luc chon bang con tro
			if( dem == 1 )	{
				txtcolor = mauTrangthai2(stoi( a[vt].substr(a[vt].length()-1,1) ));
				drawText(xi+mx, yi, a[vt].substr(0,a[vt].length()-1), txtcolor );
				clearRect(xi+mx, yi+1, 20, 1);	
				goto end_loop;			
			break;
			}
			else if(dem >1 && dem <= 10){
				clearRect(4,4,100,22);
				clearRect(x, y + (to-1-cur)*step, width, height);
				// LIET KE THEO INDEXS dem phan tu 
				mhk.lietkeHKtheo(4,2,indexs,dem);
				// CHO CHON LUA 
				cur = chonHanhKhach(0,dem,color);
				if( cur == -1) {
					txtcolor = WHITE;
					move = true;
					goto back;
				}else {
					vt = indexs[cur];
					move = true;
					txtcolor = mauTrangthai2(stoi( a[vt].substr(a[vt].length()-1,1) ));
					drawText(xi+mx, yi, a[vt].substr(0,a[vt].length()-1), txtcolor );
					clearRect(xi+mx, yi+1, 20, dem-1);	
				goto end_loop;
				}
			
			}
			else if(dem == 0){
				vitri = cur;
				vt = vitri;
				txtcolor = mauTrangthai2(stoi( a[vt].substr(a[vt].length()-1,1) ));
				drawText(xi+mx, yi, a[vt].substr(0,a[vt].length()-1), txtcolor );
				clearRect(xi+mx, yi+1, 20, 1);	
				move = true;
				goto end_loop;			
			}
		}
	}
	end_loop:
	clearRect(x, y + (to-1-cur)*step, width, height);
	gotoxy(0,0);
	clearRect(120,4,58, 20);
	gotoxy(0,0);
	// TRA RA KET QUA CAN TIM 
	msg = "TIM KIEM HANH KHACH : ";
	drawText(xi,yi,msg,YELLOW);
	drawText(xi+mx, yi, a[vt].substr(0,a[vt].length()-1), txtcolor );
	HK hk = mhk.getHK(vt);
	// lietke theo bang 
	string phai = hk.phai ? "Nam" : "Nu";
	// THONG TIN CUA MAY BAY :
	drawText(xi,yi+5,"CMND     : ",WHITE);  drawText(x+25,yi+5,hk.cmnd,mauTrangthai2(hk.ranh));
	drawText(xi,yi+7,"Ho       : ",WHITE);	drawText(x+25,yi+7,hk.ho,YELLOW);
	drawText(xi,yi+9,"Ten      : ",WHITE);	drawText(x+25,yi+9,hk.ten,YELLOW);
	drawText(xi,yi+11,"Phai     : ",WHITE);	drawText(x+25,yi+11,phai,CYAN);
	
	drawText(xi,yi+18," BAN CO MUON CHON CHUC NANG ? ",GREEN);
	
	drawButton(xi, yi+ 20,CYAN,4,27,"2","SUA");
	drawButton(xi, yi+ 23,GREEN,4,27,"3","XOA");
	drawButton(xi, yi+ 26,RED,4,27,"ESC"," QUAY LAI ");
	choose:
	char c1 = getch();
	
	if( c1 == '3'){
		string msg= "XOA HANH KHACH CO SO CMND ";
		// Neu hanh khach do chua ban => Xoa thanh cong ( can reload )
		if(hk.ranh && hk.tgban == "" && hk.scb == 0 ){
			clearRect(120,4,55, 30);
			clearRect(120,4,msg.length()+3, 1);
			drawText(120,4,msg,RED);
			drawText(120+msg.length(),4,hk.cmnd,YELLOW);
			drawText(120+msg.length()+hk.cmnd.length(),4," KHONG (Y,N): ",RED);
			c1 = getch();
			if(c1 == 'y' || c1 == 'Y'){
				mhk.xoa(hk.cmnd);
				drawText(120,6,"XOA THANH CONG",GREEN);
				Sleep(600);
				clearRect(106, 5 + (to-1 - vitri)*2, 3, 1);
				gotoxy(0,0);
				clearRect(120,4, 50, 20);
				gotoxy(0,0);
				change = true;
				delete[] a;
				back = true;
				goto back;
			}else{
				gotoxy(0,0);
				clearRect(120,4,50, 20);
				goto end_loop;
			}
		}
		// Neu may bay da duoc dang ki  => Xoa that bai ( khi that bai thi khong can reload )
		else if(!hk.ranh){
			msg = "KHONG THE XOA HANH KHACH DO DANG BAN ";
			drawText(xi,yi+14,msg,RED);
			Sleep(600);
			clearRect(xi,yi+14, msg.length(),1);
			gotoxy(0,0);
			// Xoa xong thi tro ve vi tri chon luc nay
			goto choose;
		}else if(hk.tgban != ""){
			msg = "KHONG THE XOA HANH KHACH DA DAT VE";
			drawText(xi,yi+14,msg,RED);
			Sleep(600);
			clearRect(xi,yi+14, msg.length(),1);
			gotoxy(0,0);
			goto choose;
		}else if(hk.scb != 0){
			msg = "KHONG THE XOA HANH KHACH DA CO LICH SU DAT VE";
			drawText(xi,yi+14,msg,RED);
			Sleep(600);
			clearRect(xi,yi+14, msg.length(),1);
			gotoxy(0,0);
			goto choose;
		}
	
		
	}
	
	if( c1 == '2'){
		x = 115; y= 4;
		clearRect(120,4,55, 30);
		HK edithk = hk ;
		string msg = " THAY DOI THONG TIN HANH KHACH ";
		string phai = hk.phai ? "1" : "0";
		drawText(130,2,msg,CYAN);
		drawText(120,4,"CMND     : ",WHITE);  	drawText(x+20,4,hk.cmnd,mauTrangthai(hk.ranh));
		drawText(120,10,"Ho      : ",WHITE);	drawText(x+20,10,hk.ho,YELLOW);
		drawText(120,16,"Ten     : ",WHITE);	drawText(x+20,16,hk.ten,YELLOW);
		drawText(120,22,"Phai    : ",WHITE);	drawText(x+20,22,phai,YELLOW);
		esc = false;
		InputString(x+20 + edithk.ho.length(),y+6,140,11,C40,edithk.ho,false,esc);
		if (esc) {
			clearRect(x,y,55,20);
			clearRect(130,2,msg.length(),1);
			goto end_loop;
		}
		InputString(x+20 + edithk.ten.length(),y+12,140,17,C15,edithk.ten,false,esc);
		if (esc) {
			clearRect(x,y,55,20);
			clearRect(130,2,msg.length(),1);
			goto end_loop;
		}
		InputGender(x+20,y+18,edithk.phai,esc);
		if (esc) {
			clearRect(x,y,55,20);
			clearRect(130,2,msg.length(),1);
			goto end_loop;
		}
		if(edithk.ho != hk.ho || edithk.phai != hk.phai || edithk.ten != hk.ten){
			drawText(x+10,y+20,"THAY DOI THONG TIN THANH CONG", GREEN);
			Sleep(600);
			change = true;
			mhk.sua(edithk);
		}else{
			drawText(x+10,y+20,"THONG TIN KHONG THAY DOI", GREEN);
			Sleep(600);
		}
		clearRect(120,2,40,1);
		clearRect(x,y,55,20);
		clearRect(130,2,msg.length(),1);
		clearRect(106,5+(to-1 - vitri)*step,width,height);
		
		goto end_loop;
	}
	
	
	if( c1 == ESC ){
		c1 = '\0';
		c = '\0';
		goto back;
	}
	if( c1 != ESC && c1 != '3' && c1 != '2') goto choose;
}

string HKtoString( HK hk){
	string phai = hk.phai ? "Nam" : "Nu";
	return hk.cmnd + " " + hk.ho + " "+hk.ten+" ( "+ phai + " )";
}

int dropboxHK( int x, int y ,CB cb){
	// Xoa khung begin 
	int width = 50, height = 5;
	clearRect(x,y,width,height);
	gotoxy(0,0);
	// Ve khung 
	drawRect(x,y,width,height);
	drawText(x+width+2,y+1,"Dat ve duoc",GREEN);
	drawText(x+width+2,y+2,"Khong dat duoc",RED);
	bool move = true;
	int mx = 3, n = mhk.getN(), from = 0, to = n >= 4 ? 4 : n  
	, page = 1 , npage = ( n >= 4 ? ( n%4 != 0 )? n/4 + 1 : n/4 : 1), cur = from;
	HK hki ; bool duocdatvehayk[n];
	while(1){
	
	if(move){
		cur = from ;
		clearRect(x+mx,y+1,45,3);
		clearRect(x+mx+49,y+4,4,1 );
		drawText(x+mx+49,y+4,itos0(page)+"/"+itos0(npage),YELLOW);
		for(int i = from ; i < to; i++ ){
			hki = mhk.getHK(i);
			duocdatvehayk[i] = HKduocdatVekhong(hki,cb);
			if( cur == i )
			drawBgText(x+mx,y+1+i-from,HKtoString( hki ), mauTrangthai2( duocdatvehayk[i] ), BLACK );
			else
			drawText(x+mx,y+1+i-from,HKtoString( hki ), mauTrangthai2( duocdatvehayk[i] ) );
		}
		
		move = false;
		hki = mhk.getHK(cur);
	}
	
	char c = getch();
		if( c == -32){
			c = getch();
			if( c == LEFT ){
				if( from != 0){
				from = from - 4 <= 0 ? 0 : from - 4;
				to = from + 4; 
				page--;
				move = true;
				
				}
			}
			
			if( c == RIGHT ){
				if( to != n){
				from = to;
				to = to + 4 < n ? to + 4 : (to + 4 > n) ? to + ( n - to ) : n  ; 
				page++;
				move = true;
				
				}
			}
			if( c == UP ){
				if(cur > from){
				drawText(x+mx,y+1+cur-from,HKtoString( hki ), mauTrangthai2( duocdatvehayk[cur] ));
				cur--;
				hki = mhk.getHK(cur);
				drawBgText(x+mx,y+1+cur-from,HKtoString( hki ), mauTrangthai2( duocdatvehayk[cur] ), BLACK );	
				}
			}
			
			if( c == DOWN ){
				if( cur < to-1 ){
				drawText(x+mx,y+1+cur-from,HKtoString( hki ), mauTrangthai2( duocdatvehayk[cur] ));
				cur ++;
				hki = mhk.getHK(cur);
				drawBgText(x+mx,y+1+cur-from,HKtoString( hki ), mauTrangthai2( duocdatvehayk[cur] ), BLACK );	
				}
			}
		}
		if( c == ESC ){
			cur = -1;
			break;
		}
		if( c == ENTER){
			break;
		}
	}
	// Xoa khung end 
	clearRect(x+mx+49,y+4,5,1);
	clearRect(x,y,width,height);
	clearRect(x+width+2,y+1,15,2);
	gotoxy(0,0);
	return cur;
}

//----------------------------------------------------------------------------------------------------------------------------------//
//                                                           CHUYEN BAY                                                             //  
//  --------------------------------------------------------------------------------------------------------------------------------//

void TieudeChuyenBay(int start_x,int start_y){
	drawRect(start_x,start_y,85,2);
	draw_high_line(start_x+18,start_y,2);
	drawText(start_x+3,start_y+1,"MA CHUYEN BAY",WHITE);
	draw_high_line(start_x+35,start_y,2);
	drawText(start_x+23,start_y+1,"SO HIEU ",WHITE);
	draw_high_line(start_x+60,start_y,2);
	drawText(start_x+40,start_y+1,"THOI GIAN",WHITE);
	drawText(start_x+65,start_y+1,"SAN BAY DEN",WHITE);		
}

void ThanhHuongDanCB(string* tieude, int n_tieude, int buoc_nhay, int start_x, int start_y ){
	drawFillRect(2,38,177,1,CYAN);
	drawRect(2,1,177,35);
	draw_high_line(93,1,35);
	drawButton(2,40,YELLOW,4,27,"1","THEM");
	drawButton(32,40,CYAN,4,27,"2","SUA");
	drawButton(62,40,GREEN,4,27,"3","XOA");
	drawButton(92,40,WHITE,4,27,"4","DAT VE");
	drawButton(122,40,BLUE,4,27,"5","TIM KIEM");
	drawButton(165,40,RED,4,27,"ESC","THOAT");
}

void menuCB(){
	bool change = false;
	TieudeChuyenBay(4,2);
	ThanhHuongDanCB(HD_CB, n_CB, 40, 3, 40);
	nutDieukhien(65,32,6,-1,false,true,false);
//	clearRect(65,32 - 6/2,24,6);
	int c ;
	bool reload = true, press = false, move = false, esc = false, enter = false;
	int  n = mcb.getN(), to = n , from = ( to - 10 >= 0) ? to - 10 : 0 
	, cur1 = 0, page = 1 , npage = ( n >= 10 ? ( n%10 != 0 )? n/10 + 1 : n/10 : 1)
	, pre = -1;
 	drawText(6,28,"Huy chuyen (0)",RED);
	drawText(6,30,"Con ve (1)",YELLOW);
	drawText(6,32,"Het ve (2)",CYAN);
	drawText(6,34,"Hoan tat (3)",GREEN);
	while(1){
		if(esc){
			if(change){
				char c1;
				drawText(140,41,"LUU VA THOAT (Y/N/ESC) ? ",RED);
				c1 = getch();
				if( c1 == 'y' || c1 == 'Y' )
					{
					dsmb->luu(false);
					mcb.luu();
					mhk.luu();
					return ; 
					}
				else if( c1 == 'n' || c1 == 'N' ) {
					esc = false;
					clearRect(140,41,24,1);
				}
				else{
					delete[] dsmb;
					dsmb = new DSMB();	
				 	mcb = mangCB();
					mhk = mangHK();
					return;
				}
			}else return;
		}
		if (reload){
			npage = ( n >= 10 ? ( n%10 != 0 )? n/10 + 1 : n/10 : 1);
			page = 1;n = mcb.getN();to = n; from = ( to - 10 >= 0) ? to - 10 : 0; 
			// if len > 10 => to = 10 else to = len ( len luc nay` se~ <= 10 )
			reload = false;
			clearRect(4,5,85,22);
			// Trang 1 / 2 --------------- 
			drawText(36,27,"Trang ",WHITE);
			drawNumber(43,27,page,WHITE);
			drawText(46,27,"/",WHITE);
			drawNumber(49,27,npage,YELLOW);
			// --------------------------- 
			mcb.lietkeCB(4,2,from,to);
			Cursor(false);
		}
		if (move){
			move = false;
			clearRect(4,5,85,22); // Xoa het cac ptu~ de~ in ra trang tiep theo
			mcb.lietkeCB(4,2,from,to);
			// Trang 1 / 2 --------------- 
			drawText(36,27,"Trang ",WHITE);
			drawNumber(43,27,page,WHITE);
			drawText(46,27,"/",WHITE);
			drawNumber(49,27,npage,YELLOW);
			// --------------------------- 
			Cursor(false);
		}
		KeyPress_3(cur1,from,to,page,n,reload,press,move,esc);
		if (press){
			switch(cur1){
				case 1: // THEM CHUYEN BAY 
					reload = themChuyenBay();
					if(reload) change = true;
					cur1 = 0;		
					break;
				case 2: // SUA CHUYEN BAY 
					clearRect(65,32 - 6/2,24,6);
					nutDieukhien(60,32,6,-1,true,false,false);
					reload = suaChuyenBay(from,to,page,CYAN);
					if(reload) change = true;
					cur1 = 0;	
					clearRect(60,32 - 6/2,30,6);
					break;
				case 3: // XOA CHUYEN BAY 
					clearRect(65,32 - 6/2,24,6);
					nutDieukhien(60,32,6,-1,true,false,false);
					reload = xoaChuyenBay(from,to,page,RED);
					if(reload) change = true;
					cur1 = 0;
					clearRect(60,32 - 6/2,30,6);	
					break;
				case 4: // DAT VE 
					clearRect(65,32 - 6/2,24,6);
					nutDieukhien(60,32,6,-1,true,false,false);
					reload = datVe(from,to,page,WHITE);
					if(reload) change = true;
					reload = true;
					cur1 = 0;	
					clearRect(60,32 - 6/2,30,6);
					break;
				case 5: // TIM CHUYEN BAY 
					clearRect(65,32 - 6/2,24,6);
					nutDieukhien(60,32,6,-1,true,false,false);
					reload = timChuyenBay(from,to,page,BLUE);
					if(reload) change = true;
					cur1 = 0;	
					clearRect(60,32 - 6/2,30,6);
					break;
				case ESC: //
					esc = true;
					break;
				default:
					break;
			}
			nutDieukhien(65,32,6,-1,false,true,false);
			press = false;
			cur1 = 0;
			Cursor(false);	
		}
	}
	
}

int mauTrangthaiCB(int tt){
	if(tt == 0) return RED;
	if(tt == 1) return YELLOW;
	if(tt == 2) return CYAN;
	if(tt == 3) return GREEN;
}

bool themChuyenBay(){
	string msg = "KHONG CO MAY BAY DE THEM CHUYEN BAY";
	if( dsmb->laydodai() == 0){
		drawText(120,4, msg ,RED);
		Sleep(600);
		clearRect(120,4,msg.length(),1);
		return false;
	}
	bool change = false;
	bool check=false,esc = false;
	int x = 120, y = 4, sohieulen = 0;
	clearRect(120,2,30,1);
	drawText(120,2,"THEM CHUYEN BAY MOI ",YELLOW);
	drawText(95,4,"Ma CB :",WHITE);
	string tmp="";
	CB cb ;
	drawText(95,13,"So Hieu :",WHITE);
	drawText(133,4,"Thoi Gian :",WHITE);
	drawText(133,13,"San Bay Den :",WHITE);
	maCB_again:
	InputString(105+cb.maCB.length(),4,115,5,C15,cb.maCB,check,esc);
	if(esc)
	{
		clearRect(95,4,80,24);
		clearRect(120,2,30,1);
		return change;		
	}
	if( mcb.tim( cb.maCB ) != -1){
		drawText(105,5,"MA CHUYEN BAY DA TON TAI",RED);
		Sleep(500);
		clearRect(105,5,25,1);
		goto maCB_again; 
	}
	
	int n = dsmb->laydodai(); string *a; dsmb->laysohieu( a );
	cb.shMB = dropboxSohieu(105 ,15,  a, n, cb.shMB, 110,13 );
		if(cb.shMB == ""){
			clearRect(95,4,80,24);
			clearRect(120,2,30,1);
			return change;	
		}
	
	string *b; laySBden( b );
	cb.sbden = dropboxSBden(150 ,15, b,22, cb.sbden,Baygio(),cb.tgbay,150,13);
		if(cb.sbden == ""){
			clearRect(95,4,80,24);
			clearRect(120,2,30,1);
			return change;	
		}
	
	CB* mang;
	NG rlimit ;
	NG llimit = Baygio();
	int sl = 0; 
	bool had = mcb.mangSohieu(cb.shMB,mang,sl);
	date_again:
	
	// NGhia la may bay nay duoc su dung lan dau 
	string leftside, rightside = "";
	cb.ngaygiokh = Baygio();
	NG newdate = cb.ngaygiokh;
	NG chuyenbaytoithieu = congPhut(newdate,cb.tgbay);
//	gotoxy(0,0); cout<< NGtoString(chuyenbaytoithieu);
	// Moi dau ta co so hieu may bay roi 
	NG ghtren;
	// gioi han duoi luon luon co duoc cap nhat boi hien tai
	NG ghduoi;
	// TH1 : Neu May bay duoc su dung lan dau ( sl = 0 )
	
	if( sl == 0) ghduoi = Baygio(); // Gioi han duoi = hien tai
	else{
		// TH2 : Neu May bay da duoc su dung 1 lan ( sl = 1 ) & lan su dung do co thoi gian ket thuc > hien tai 1 khoang thoi gian di 
		if( sl == 1 ) 
			// Chuyen bay nay chua khoi hanh  
			if ( sosanhNG( mang[sl -1].ngaygiokh, newdate) > 0 )
				// Thi lieu co chen them 1 chuyen bay khac 06:30 -> 07:00 du de chen 1 chuyen bay 10p 
				if( sosanhNG( mang[sl -1].ngaygiokh , chuyenbaytoithieu ) > 0 ){
					ghtren = mang[sl -1].ngaygiokh;
					rightside = NGtoString(ghtren);
					ghduoi = newdate;
				}else
				// Neu khong du thi gioi han duoi chinh la thoi gian ket thuc cua no => Bo qa thang dau tien trong DS 
				{
					ghduoi = tinhTGden(mang[sl -1].ngaygiokh,mang[sl -1].sbden);	
				}
			else
				// Neu khong du thi gioi han duoi chinh la thoi gian ket thuc cua no => Bo qa thang dau tien trong DS 
				{
					ghduoi = tinhTGden(mang[sl -1].ngaygiokh,mang[sl -1].sbden);	
				}
		if( sl >= 2 ){
			// Duyet tu thoi gian ket thuc cua thang dau tien 
				int i = 0;
				bool found = false;
			NG tgketthuc ; 
			ghduoi = Baygio();   
			for( i = 0; i < sl ; i++){
				chuyenbaytoithieu = congPhut( ghduoi, cb.tgbay );
				// Neu Chuyen bay toi thieu > thoi gian khoi hanh cua thang ke tiep thi cap nhat gioi han duoi 
				if ( sosanhNG( chuyenbaytoithieu , mang[i].ngaygiokh ) > 0 ){
					// So sanh neu thang ket thuc ma lon hon ca Baygio() thi cho no la Baygio() 
					// nguoc lai gioihan duoi la ket thuc cua thang truoc do 
					tgketthuc = tinhTGden(mang[i].ngaygiokh, mang[i].sbden);
					ghduoi = sosanhNG( tgketthuc, Baygio() ) > 0 ? tgketthuc : Baygio();
				// Neu Chuyen bay toi thieu < thoi gian khoi hanh cua thang ke tiep thi cap nhat gioi han tren 
				}else if(!found){
					// Tim ra gioi han tren dau tien cua no 
					found = true;
					ghtren = mang[i].ngaygiokh;
					rightside = NGtoString(ghtren);
				}					
			}

			}
		} // if sl != 0 
				
	// THOI GIAN QUY DINH 
	msg = "THOI GIAN QUY DINH";
	leftside = NGtoString(ghduoi);
	drawText(133,6,msg,YELLOW); drawText(133+msg.length()+3,6,">= "+leftside,RED);
			if(rightside != "") drawText(133+msg.length()+3,7,"<  "+rightside, RED);
	InputDate(145,4,newdate,Baygio());
	
	if(rightside != ""){
		if( NGtoString(newdate) < leftside || NGtoString(newdate) >= rightside){
			clearRect(133,6,msg.length()+23,2);
			msg = "THOI GIAN KHOI HANH KHONG HOP LE";
			drawText(133,7,msg,RED);
			Sleep(600);
			clearRect(133,7,msg.length()+2,1);
			goto date_again;	
		}
	}else if( NGtoString(newdate) < leftside ){
		clearRect(133,6,msg.length()+23,1);
		msg = "THOI GIAN KHOI HANH KHONG HOP LE";
		drawText(133,7,msg,RED);
		Sleep(600);
		clearRect(133,7,msg.length()+2,1);
		goto date_again;	
	}
	cb.ngaygiokh = newdate;
	clearRect(133,6,40,2);
    drawText(145,4,NGtoString(cb.ngaygiokh),YELLOW);
	// ---------------- 
	
	drawText(145,4,NGtoString(cb.ngaygiokh),YELLOW);
	drawText(110,22, "BAN CHAC CHAN MUON THEM ? (Y/ N)",GREEN);
	char c1 = getch();
	if( c1 != 'y' && c1 != 'Y') {
	clearRect(95,4,80,24);
	clearRect(110,22,40,1);
	gotoxy(0,0);
	clearRect(120,24,30,1);
	clearRect(120,2,30,1);
	return change;
	}
	int soday = 0 , sodong = 0;
	dsmb->getsoDayvasoDong(cb.shMB,soday,sodong);
	cb.dsve = DsVe(soday*sodong);
	cb.tt = 1; 
	mcb.them(cb);
	MB *mb = dsmb->getMB(cb.shMB);
	mb->tt = 1;
	mb->sudung += 1;
	delete[] a;
	delete[] b;
	drawText(120,23,"THEM CHUYEN BAY THANH CONG",GREEN);
	Sleep(600);
	clearRect(95,4,80,24);
	gotoxy(0,0);
	clearRect(120,2,30,1);
	change = true;
	gotoxy(0,0);
	return change;
	// ----------------- 
}

void suaTTcapnhatHK(CB cb){
	DsVe ds = cb.dsve;
	Ve* dsve = ds.laydanhsach();
	HK hk;
	int n = ds.getSL();
	if( n == 0) return;	
	for( int i = 0; i < n ; i++){
		if(dsve[i].CMND != ""){
			hk = mhk.getHK(dsve[i].CMND);
			capnhatHKranh(hk.tgban);
			if( hk.tgban == "" ) hk.ranh = true; else hk.ranh = false; 
			mhk.sua(hk);
		}
	}
}

bool suaChuyenBay(int &from ,int &to,int &page ,int color){
	// -------------------------------------------------- CHON CHUYEN BAY CAN SUA ------------------------------------
		int width = 2, height = 1, step = 2;
		bool esc = false, change = false;
		int  n = mcb.getN() , npage = ( n >= 10 ? ( n%10 != 0 )? n/10 + 1 : n/10 : 1),
		vitri = -1;
		if( n == 0 ) return change;
	back: 	
		// Muon sua nhieu hay thay doi nhieu thi sua o day => bo change len tren 
		bool move = false; 
		if(change) move = true;
		int cur = to-1, x = 90, y = 5;
		char c;
	Cursor(false);
	clearRect(x,y,width,height);
	if(vitri != -1)
	{
	drawFillRect(x,y+(to-1 - vitri)*step,width,height,color);
	cur = vitri;
	}else
	drawFillRect(x,y,width,height,color);
	
	while(1){
		if(move)
		{
			clearRect(4,4,85,22);
			move = false;
			drawFillRect(x,y+(to-1 - cur)*step,width,height,color);
			
			// Trang 1 / 2 --------------- 
			drawText(36,27,"Trang ",WHITE);
			drawNumber(43,27,page,WHITE);
			drawText(46,27,"/",WHITE);
			drawNumber(49,27,npage,YELLOW);
			// --------------------------- 
			mcb.lietkeCB(4,2,from,to);
		}
		c = getch();
		if (c == -32){
			c = getch();
			if (c == LEFT){
				if( to + 10 <= n){
					clearRect(x,y+(to-1 - cur)*step,width,height);
					from = to;
					to = to + 10 >= n? n : to + 10 ;
					move = true;
					page--;	
					cur = to-1;
					drawFillRect(x,y+(to-1 - cur)*step,width,height,color);
				}			
			}
		// Luc dau to = maxlen && from = to - 10
			if (c == RIGHT){ 		
				if( to > 10){
					clearRect(x,y+(to-1 - cur)*step,width,height);
					to = from != 0 ? from : to ;
					from = to - 10 <= 0? 0 : to - 10 ;
					move = true;
					page++;	
					cur = to-1;
					drawFillRect(x,y+(to-1 - cur)*step,width,height,color);
				}	
			}
			if (c == UP){
				if(cur < to-1){
					clearRect(x,y+(to-1 - cur)*step,width,height);
				 	cur++;
				 	drawFillRect(x,y+(to-1 - cur)*step,width,height,color);
				} 	
			}
			if (c == DOWN){
				if(cur > from) {
					clearRect(x,y+(to-1 - cur)*step,width,height);
					cur--;
					drawFillRect(x,y+(to-1 - cur)*step,width,height,color);
				}	
			}
		}
		if (c == ESC) {
			clearRect(120,2,58,1);
			clearRect(x,y+(to-1 - cur)*step,width,height);
			gotoxy(0,0);
			vitri = -1;
			return change;
		}
		if (c == ENTER) {
			vitri = cur;
			break;
		}
	}
	
	// ---------------------------------- SUA CHUYEN BAY DA CHON --------------------------------------------------- 
	
	if(vitri == -1) goto back; 
	
	// Hoi nguoi dung xem muon thay doi trang thai ntn ?
	// Bien luu trang thai moi 
	CB cb = mcb.getCB(vitri);
	int newtt = -1; int sve = cb.dsve.getSLDB();
	string msg;
	x = 100;
	y = 2;
	// CHECK DIEU KIEN THOA MAN LA KHI CON VE HOAC HET VE 
	if( cb.tt == 3 )
	{
		msg = "CHUYEN BAY NAY DA HOAN TAT KHONG THE SUA" ;
		drawText(x+15,y+4,msg,RED);
		Sleep(600);
		clearRect(x+15,y+4,msg.length()+5,1);
		goto back;
	}else{
		if( sosanhNG( cb.ngaygiokh, Baygio() ) < 0 ){
			if(sosanhNG( congPhut(cb.ngaygiokh, cb.tgbay) , Baygio() ) <= 0){
				cb.tt = (cb.tt == 0)? 0 : 3;	
				mcb.sua(cb);
				mcb.luu();
				msg = (cb.tt == 3) ?"CHUYEN BAY NAY DA HOAN TAT KHONG THE SUA" : "CHUYEN BAY NAY DA HUY KHONG THE SUA";
				drawText(x+15,y+4,msg,RED);
				Sleep(600);
				clearRect(x+15,y+4,msg.length()+5,1);
				goto back;
			}
		}
	}
	
	msg= "SUA CHUYEN BAY TAI VI TRI "+ itos0(vitri+1) +": "+cb.maCB;
	drawText(x+20,y,msg,color); 
	drawText(x,y+3, "TRANG THAI CU: ",WHITE); 
	drawNumber(x+25,y+3,cb.tt,mauTrangthaiCB(cb.tt));
	drawText(x,y+7, "NHAP -1 DE THOAT ",RED);
	drawText(x+40,y+3,"So ve da ban : ",WHITE);	drawNumber(x+70,y+3,sve,YELLOW);
	drawText(x,y+9, "CON VE     (1) DELAY THOI GIAN KHOI HANH ( XOA NEU SO VE DA BAN = 0)",YELLOW);
	drawText(x+20,y+10,"Tips: HET VE (2) se duoc cap nhat tu dong ",YELLOW);
	drawText(x,y+11,"HOAN TAT   (3) KHONG THE SUA HOAC XOA ",RED);
	drawText(x,y+12,"HUY CHUYEN (0) CO THE SUA , KHONG THE XOA ",RED);
	
	do{
		fflush(stdin);
		drawText(x,y+5,"TRANG THAI (0/1/3): ",WHITE);
		gotoxy(x+25,y+5); 
		cin>>newtt;
		if(newtt == -1) {
			clearRect(x,y,70,16);	
			clearRect(90,5+(to-1 - cur)*step,width,height);		
			return change;
		}
	}while(newtt < 0 || newtt > 3 && newtt == 2);
	drawText(x+20, y+14, "BAN CO CHAC CHAN MUON THAY DOI ?",YELLOW );
	
	CB *mang ;
	char c1 = getch();
	if( c1 == 'y' || c1 == 'Y'){
		if(cb.tt != newtt){
			if(newtt == 3)
				msg = " TRANG THAI DA CHUYEN SANG HOAN TAT (3) ";
			if(newtt == 1)
				if( sve == cb.dsve.getSL() ){
					msg = " TRANG THAI DA CHUYEN SANG HET VE (2) ";
					newtt = 2;
				}else
				msg = " TRANG THAI DA CHUYEN SANG CON VE (1) ";
			if(newtt == 0)
				msg = " TRANG THAI DA CHUYEN SANG HUY CHUYEN (0) ";
			change = true;
		}else{
			change = false;
			msg = " TRANG THAI KHONG THAY DOI ";
		}
		drawText(x+10, y+16,msg,GREEN);
		// Khi con ve hoac het ve thi chuyen sang DELAY time
		if(newtt != 1 && newtt != 2 ){
			Sleep(600);
			gotoxy(0,0);
			clearRect(x,y+1,70,17);
			gotoxy(0,0);
			clearRect(120,2,58,1);
			cb.tt = newtt;
			if(change) mcb.sua(cb);
			suaTTcapnhatHK(cb);
			mcb.lietkeCB(4,2,from,to);
			goto back;
		}
		else // NEU DELAY THOI GIAN 
		{
		string tip,tip2;
		
	 	// XU LY NGAY GIO DELAY
		CB* mang;
		int sl = 0; 
		bool had = mcb.mangSohieu(cb.shMB,mang,sl);

		date_again:
		
		// NGhia la may bay nay duoc su dung lan dau 
		string leftside, rightside = "";
		NG newdate = cb.ngaygiokh;
		NG chuyenbaytoithieu = congPhut(newdate,cb.tgbay);
		
		NG ghtren;
		NG ghduoi;
	
		// TH1 : Chi duy nhat 1 may bay de delay 
		if( sl == 1 )  ghduoi = Baygio();
		else if( sl >= 2 ){
		// TH2 : Nhieu may bay de delay  
			int i = 0;
			bool found = false;
			NG tgketthuc ; 
			ghduoi = Baygio();   
			for( i = 0; i < sl ; i++){
			if( sosanhNG(mang[i].ngaygiokh, cb.ngaygiokh) != 0 ){
				chuyenbaytoithieu = congPhut( ghduoi, cb.tgbay );
				// Neu Chuyen bay toi thieu > thoi gian khoi hanh cua thang ke tiep thi cap nhat gioi han duoi 
					if ( sosanhNG( chuyenbaytoithieu , mang[i].ngaygiokh ) > 0 ){
						// So sanh neu thang ket thuc ma lon hon ca Baygio() thi cho no la Baygio() 
						// nguoc lai gioihan duoi la ket thuc cua thang truoc do 
						tgketthuc = tinhTGden(mang[i].ngaygiokh, mang[i].sbden);
						ghduoi = sosanhNG( tgketthuc, Baygio() ) > 0 ? tgketthuc : Baygio();
					// Neu Chuyen bay toi thieu < thoi gian khoi hanh cua thang ke tiep thi cap nhat gioi han tren 
					}else if(!found){
						// Tim ra gioi han tren dau tien cua no 
						found = true;
						ghtren = truPhut( mang[i].ngaygiokh, cb.tgbay);
						rightside = NGtoString(ghtren);
						if( sosanhNG( ghtren, cb.ngaygiokh ) == 0 ) {
							clearRect(x,y+1,70,26);
							gotoxy(0,0);
							clearRect(120,2,58,1);
							drawText(x+10,y+2,"KHONG THE DELAY DUOC VI TRUNG GIO KHOI HANH ",RED);
							drawText(x,y+4," < Gioi han tren : "+NGtoString(ghtren)+" == Ngay gio kh :"+ NGtoString(cb.ngaygiokh) +" >",RED);
							goto back;
						}
					}					
				}
			}
		}
	 	
	 	// KET THUC XU LY NGAY GIO DELAY 
	 	clearRect(x+10, y+16,msg.length(),1);
		// DELAY THOI GIAN KHOI HANH BAT DAU O DAY 	
		drawText(x+20, y+17," DELAY THOI GIAN KHOI HANH ",GREEN);
			
		// GIAO DIEN INIT 
		drawText(x+10,y+20," DEN "+cb.sbden+" :",YELLOW); drawText(x+35,y+20,"+ "+itos0(cb.tgbay)+" phut",CYAN);

		leftside = NGtoString(ghduoi);
		msg = " THOI GIAN KHOI HANH : ";
		drawText(x+10,y+18,msg,YELLOW );
		msg = " THOI GIAN QUY DINH (DELAY) ";
		
		drawText(x+10, y + 23,msg,YELLOW);  drawText(x+msg.length()+15, y + 23,"> "+leftside,RED);
				    if(rightside != "")	 drawText(x+msg.length()+15, y + 24,"< "+rightside,RED);	
		
		InputDate(x+35,y+18, newdate,Baygio());
			if( rightside != ""){
				if( NGtoString(newdate) >= rightside || NGtoString(newdate) <= leftside)
				{
				clearRect(x,y+18,70,1);
				drawText(x+10,y+26,"NGAY GIO KHOI HANH KHONG HOP LE",RED);
				Sleep(600);
				clearRect(x+10,y+26,50,1);
				goto date_again;
				}
			}else
				if(NGtoString(newdate) <= leftside){
				clearRect(x,y+18,70,1);
				drawText(x+10,y+26,"NGAY GIO KHOI HANH KHONG HOP LE",RED);
				Sleep(600);
				clearRect(x+10,y+26,50,1);
				goto date_again;
				}
			msg = "BAN CO MUON LUU THAY DOI KHONG ? (Y/N)";
			drawText(x+10,y+26,msg,RED);
			char c1 = getch();
			if(c1 == 'y' || c == 'Y')
			{
				change = true;
				cb.tt = newtt;
				cb.ngaygiokh = newdate;
				mcb.sua(cb);
				Sleep(600);
				clearRect(120,2,58,1);
				clearRect(x,y+1,70,26);
				goto back;
			}else{
				change = false;
				clearRect(x,y+1,70,26);
				gotoxy(0,0);
				clearRect(120,2,58,1);
				goto back;
			}	
		}
	}else{
		clearRect(120,2,58,1);
		clearRect(x,y+1,70,26);
		goto back;
	}	
}

bool xoaChuyenBay(int &from, int &to,int &page ,int color){
	// -------------------------------------------------- CHON CHUYEN BAY CAN XOA ------------------------------------
		int width = 2, height = 1, step = 2;
		bool esc = false, change = false;
		int vitri = -1;
	back:
		int  n = mcb.getN() , npage = ( n >= 10 ? ( n%10 != 0 )? n/10 + 1 : n/10 : 1);
		// Muon xoa nhieu hay thay doi nhieu thi sua o day => bo change len tren 
		if( n == 0 ) return change;
		bool move = false; 
		int cur = to-1, x = 90, y = 5;
		char c;
	Cursor(false);
	clearRect(x,y,width,height);
	if(vitri != -1)
	{
	drawFillRect(x,y+(to-1 - vitri)*step,width,height,color);
	cur = vitri;
	}else
	drawFillRect(x,y,width,height,color);
	
	while(1){
		if(move)
		{
			clearRect(4,4,85,22);
			move = false;
			drawFillRect(x,y+(to-1 - cur)*step,width,height,color);
			
			// Trang 1 / 2 --------------- 
			drawText(36,27,"Trang ",WHITE);
			drawNumber(43,27,page,WHITE);
			drawText(46,27,"/",WHITE);
			drawNumber(49,27,npage,YELLOW);
			// --------------------------- 
			mcb.lietkeCB(4,2,from,to);
		}
		c = getch();
		if (c == -32){
			c = getch();
			if (c == LEFT){
				if( to + 10 <= n){
					clearRect(x,y+(to-1 - cur)*step,width,height);
					from = to;
					to = to + 10 >= n? n : to + 10 ;
					move = true;
					page--;	
					cur = to-1;
					drawFillRect(x,y+(to-1 - cur)*step,width,height,color);
				}			
			}
		// Luc dau to = maxlen && from = to - 10
			if (c == RIGHT){ 		
				if( to > 10){
					clearRect(x,y+(to-1 - cur)*step,width,height);
					to = from != 0 ? from : to ;
					from = to - 10 <= 0? 0 : to - 10 ;
					move = true;
					page++;	
					cur = to-1;
					drawFillRect(x,y+(to-1 - cur)*step,width,height,color);
				}	
			}
			if (c == UP){
				if(cur < to-1){
					clearRect(x,y+(to-1 - cur)*step,width,height);
				 	cur++;
				 	drawFillRect(x,y+(to-1 - cur)*step,width,height,color);
				} 	
			}
			if (c == DOWN){
				if(cur > from) {
					clearRect(x,y+(to-1 - cur)*step,width,height);
					cur--;
					drawFillRect(x,y+(to-1 - cur)*step,width,height,color);
				}	
			}
		}
		if (c == ESC) {
			clearRect(120,2,40,1);
			clearRect(x,y+(to-1 - cur)*step,width,height);
			gotoxy(0,0);
			vitri = -1;
			return change;
		}
		if (c == ENTER) {
			vitri = cur;
			break;
		}
	}
	
	x = 115; y= 4;
	if(vitri == -1){
		goto back;
	}
	CB cb = mcb.getCB(vitri);
	string msg = "";
	// NEU HOAN TAT HOAC HET VE HOAC CON VE NHUNG CO HK THI KHONG DUOC XOA NO DI 
	if( cb.tt > 1 )
	{
		msg = (cb.tt == 2) ? "KHONG THE XOA VI DA BAN HET VE" : "KHONG THE XOA VI CHUYEN BAY DA HOAN TAT";
	}
	else if(cb.tt == 1 && cb.dsve.getSLDB() != 0 ){
		 
			msg = "KHONG THE XOA VI DA CO VE DUOC MUA"; 
	}else if( cb.tt == 0){
		msg = "KHONG THE XOA VI CHUYEN BAY DA HUY";
	}
	if(msg != ""){
		clearRect(x,y,msg.length() + 2,RED);
		drawText(x,y,msg,RED);
		Sleep(600);
		clearRect(x,y,msg.length() + 2,RED);
		goto back;
	}
	msg = " BAN CHAC CHAN XOA CHUYEN BAY THU "+itos0(vitri+1)+" : "+cb.maCB+ " (Y/N)? "; 
	drawText(x,y,msg,RED);
	char c1 = getch();
	if( c1 == 'y' || c1 == 'Y')
	{
		msg = "XOA CHUYEN BAY THANH CONG";
		drawText(x,y+4,msg,GREEN);
		Sleep(600);
		clearRect(x-10,y,70,5);
		clearRect(90,5+(to-1 - cur)*step,width,height);
		MB* mb = dsmb->getMB(cb.shMB);
		if(mb->sudung <= 1){
			mb->sudung = 0;
			mb->tt = 0;
		}
		else mb->sudung--;
		mcb.xoa(cb.maCB);
		change = true;
		return change;
	}else{
		clearRect(x-10,y,70,5);
		goto back;
	}
}

bool timChuyenBay(int &from, int &to,int &page, int color){
	// -------------------------------------------------- CHON CHUYEN BAY CAN SUA ------------------------------------
		int width = 2, height = 1, step = 2, xi = 100 , yi = 4 , mx = 25
		, vitri = -1, vt = -1;
		bool esc = false, change = false, move = false, back = false;
		int txtcolor;
		string tmp = "";
	back: 	
		drawText(6,28,"Huy chuyen (0)",RED);
		drawText(6,30,"Con ve (1)",YELLOW);
		drawText(6,32,"Het ve (2)",CYAN);
		drawText(6,34,"Hoan tat (3)",GREEN);
		clearRect(xi,yi,78, 28);
		nutDieukhien(60,32,6,-1,true,false,false);
	// Muon sua nhieu hay thay doi nhieu thi sua o day => bo change len tren 
	 	int  n = mcb.getN();
		if( n == 0 ) return change;
		if( change ) move = true;
		int x = 90, y = 5
		, npage = ( n >= 10 ? ( n%10 != 0 )? n/10 + 1 : n/10 : 1)
		, indexs[n], dem = 0;
		string *a; mcb.laymaCB(a);
		bool lietketen = false;
		char c = '\0';
	Cursor(false);
	clearRect(x,y,width,height);
		if(change) {
			 	if(back) {
					if(to % 10 == 1) { 	
			 			if(page == npage + 1) page--;
						to = ( to + 10 < n) ? to+ 10 : ( to == 11 ) ? n : n + 1;
					}
					to--;
					from = from == 0 ? from : from - 1;
				 }
			move = true;
		}
	int cur = to-1;
	if(vitri != -1){
		if(back) if(vitri == to) vitri = to-1;
		drawFillRect(x,y+(to-1 - vitri)*step,width,height,color);
		cur = vitri;
	}else
	drawFillRect(x,y,width,height,color);
	back = false;
	string msg = "TIM KIEM CHUYEN BAY : ";
	drawText(xi,yi,msg,YELLOW);
	
	if(tmp != ""){
		drawText(xi+mx,yi,tmp,txtcolor);
	}
	
	while(1){
		if(move){
			clearRect(4,4,85,22);
			move = false;
			drawFillRect(x,y+(to-1 - cur)*step,width,height,color);
			
			// Trang 1 / 2 --------------- 
			drawText(36,27,"Trang ",WHITE);
			drawNumber(43,27,page,WHITE);
			drawText(46,27,"/",WHITE);
			drawNumber(49,27,npage,YELLOW);
			// --------------------------- 
			mcb.lietkeCB(4,2,from,to);
		}
		if(tmp.size() != 0 && c == '\0'){
				dem= 0;
				Reint(indexs,n);
				vt = -1;
				clearRect(xi+mx,yi+1,C15+18,12);
				for( int i = 0 ; i < n ; i++ ){
					if( search(tmp, a[i].substr(0,a[i].length()-1)) != "" ){  
						if(dem < 10){
							indexs[dem++] = i;
						}else{
							drawText( xi + mx + 2, yi + 11,".......",YELLOW);
							drawText( xi + mx , yi + 12, "CHI CHON DUOC KHI SO LUONG <= 10", RED );
						}
						// NEU DEM = 1 THI OUT RA CHO THONG TIN LUON KEM CHUC NANG 
						 	if(dem == 1) vt = i;
						}
					}
					// LIET KE THEO INDEXS STRING TYPE 
					if( dem != 0)
					{
						lietketen = true;
						goto lietketen;	
					}
				}
		// LIET KE THEO TEN 
			lietketen:
			if(lietketen){
				for( int i = 0; i < dem ; i++){
					txtcolor = mauTrangthaiCB(stoi( a[indexs[i]].substr(a[indexs[i]].length()-1,1) ));
					drawText(xi+mx + 2, yi+1 + i , a[indexs[i]].substr(0,a[indexs[i]].length()-1), txtcolor );
				}
				lietketen = false;
				
			}	
		
		c = getch();
		if (c == -32){
			c = getch();
			if (c == LEFT){
				if( to + 10 <= n){
					clearRect(x,y+(to-1 - cur)*step,width,height);
					from = to;
					to = to + 10 >= n? n : to + 10 ;
					move = true;
					page--;	
					cur = to-1;
					drawFillRect(x,y+(to-1 - cur)*step,width,height,color);
				}			
			}
		// Luc dau to = maxlen && from = to - 10
			if (c == RIGHT){ 		
				if( to > 10){
					clearRect(x,y+(to-1 - cur)*step,width,height);
					to = from != 0 ? from : to ;
					from = to - 10 <= 0? 0 : to - 10 ;
					move = true;
					page++;	
					cur = to-1;
					drawFillRect(x,y+(to-1 - cur)*step,width,height,color);
				}	
					
			}
			if (c == UP){
				if(cur < to-1){
					clearRect(x,y+(to-1 - cur)*step,width,height);
				 	cur++;
				 	drawFillRect(x,y+(to-1 - cur)*step,width,height,color);
				} 	
			}
			if (c == DOWN){
				if(cur > from) {
					clearRect(x,y+(to-1 - cur)*step,width,height);
					cur--;
					drawFillRect(x,y+(to-1 - cur)*step,width,height,color);
				}	
			}
		}else{
			if( tmp.size() < C15 ){
			if( c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9'){
				gotoxy(xi + mx + tmp.size(), yi);
				tmp += c;
				cout<<c;
				dem = 0;
				Reint(indexs,n);
				vt = -1;
				clearRect(xi+mx,yi+1,C15+18,12);
				for( int i = 0 ; i < n ; i++ ){
					if( search(tmp, a[i].substr(0,a[i].length()-1)) != "" ){  
						if(dem < 10){
							indexs[dem++] = i;
						}else{
							drawText( xi + mx + 2, yi + 11,".......",YELLOW);
							drawText( xi + mx , yi + 12, "CHI CHON DUOC KHI SO LUONG <= 10", RED );
						}
						// NEU DEM = 1 THI OUT RA CHO THONG TIN LUON KEM CHUC NANG 
						 	if(dem == 1) vt = i;
						}
					}
					// LIET KE THEO INDEXS STRING TYPE 
					if( dem != 0)
					{
						lietketen = true;
						goto lietketen;	
					}
					
				
				}
			}	
			if( c == BACKSPACE ){
				
				if ( tmp.size() > 0  )
				{
				tmp.erase(tmp.size() - 1 , 1 ); 
				gotoxy(xi + mx + tmp.size()+1,yi);
				cout<<"\b ";		 
				}
				
				dem= 0;
				Reint(indexs,n);
				vt = -1;
				clearRect(xi+mx,yi+1,C15+18,12);
				if(tmp.size() != 0){
				//clearRect(xi+mx,yi+1,C15+18,12);
				for( int i = 0 ; i < n ; i++ ){
					if( search(tmp, a[i].substr(0,a[i].length()-1)) != "" ){  
						if(dem < 10){
							indexs[dem++] = i;
						}else{
							drawText( xi + mx + 2 , yi + 11,".......",YELLOW);
							drawText( xi + mx , yi + 12, "CHI CHON DUOC KHI SO LUONG <= 10", RED );
						}
						// NEU DEM = 1 THI OUT RA CHO THONG TIN LUON KEM CHUC NANG 
						 	if(dem == 1) vt = i;
						}
					}
					// LIET KE THEO INDEXS STRING TYPE 
					if( dem != 0)
					{
						lietketen = true;
						goto lietketen;	
					}
				}
				
			}
			
			
		}
		if (c == ESC) {
			clearRect(xi,yi,78,25);
			clearRect(120,2,40,1);
			clearRect(x,y+(to-1 - cur)*step,width,height);
			gotoxy(0,0);
			vitri = -1;
			return change;
		}
		if (c == ENTER){
			
			// Vitri la luc chon bang con tro
			if( dem == 1 )	{
				txtcolor = mauTrangthaiCB(stoi( a[vt].substr(a[vt].length()-1,1) ));
				drawText(xi+mx, yi, a[vt].substr(0,a[vt].length()-1), txtcolor );
				clearRect(xi+mx, yi+1, 20, 1);	
				goto end_loop;			
			break;
			}else if(dem >1 && dem <= 10){
				clearRect(4,4,85,22);
				clearRect(x, y + (to-1-cur)*step, width, height);
				
				// LIET KE THEO INDEXS dem phan tu 
				mcb.lietkeCBtheo(4,2,indexs,dem);
				// CHO CHON LUA 
				cur = chonChuyenBay(0,dem,color);
				if( cur == -1) {
					txtcolor = WHITE;
					move = true;
					goto back;
				}else {
					vt = indexs[cur];
					move = true;
					txtcolor = mauTrangthaiCB(stoi( a[vt].substr(a[vt].length()-1,1) ));
					drawText(xi+mx, yi, a[vt].substr(0,a[vt].length()-1), txtcolor );
					clearRect(xi+mx, yi+1, 20, dem-1);	
				goto end_loop;
				}
			
			}else if(dem == 0){
				vitri = cur;
				vt = vitri;
				txtcolor = mauTrangthaiCB(stoi( a[vt].substr(a[vt].length()-1,1) ));
				drawText(xi+mx, yi, a[vt].substr(0,a[vt].length()-1), txtcolor );
				clearRect(xi+mx, yi+1, 20, 1);	
				goto end_loop;			
			}
		}
	}
	end_loop:
	clearRect(x, y + (to-1-cur)*step, width, height);
	gotoxy(0,0);
	clearRect(120,4,58, 20);
	gotoxy(0,0);
	msg = "TIM KIEM CHUYEN BAY : ";
	drawText(xi,yi,msg,YELLOW);
	drawText(xi+mx, yi, a[vt].substr(0,a[vt].length()-1), txtcolor );
	// TRA RA KET QUA CAN TIM 
	CB cb = mcb.getCB(vt);
	MB* mb = dsmb->getMB(cb.shMB);
	// lietke theo bang 
	
	// THONG TIN CUA MAY BAY :
	drawText(xi+5,yi+5,"MA CHUYEN BAY                    : ",YELLOW);		drawText(xi+45,yi+5,cb.maCB,mauTrangthaiCB(cb.tt));
	drawText(xi+5,yi+7,"THOI GIAN KHOI HANH              : ",YELLOW);		drawText(xi+45,yi+7,NGtoString(cb.ngaygiokh),CYAN);
	drawText(xi+5,yi+9,"MAY BAY ( Loai / soday x sodong ): ",YELLOW);   	drawText(xi+45,yi+9,cb.shMB, RED);
																			drawText(xi+45,yi+10,mb->loai + " / "+itos0(mb->soday)+"x"+itos0(mb->sodong), YELLOW);
	drawText(xi+5,yi+11,"SAN BAY DEN ( + thoi gian bay )  : ",YELLOW);     	drawText(xi+45,yi+11,cb.sbden+" ( + " + itos0(cb.tgbay) + " phut ) ", CYAN );
																			drawText(xi+45,yi+12, NGtoString( congPhut(cb.ngaygiokh, cb.tgbay) ), CYAN );	
		
	drawText(xi+5,yi+18," BAN CO MUON CHON CHUC NANG ? ",GREEN);
	
	drawButton(xi+5,yi+20,CYAN,4,27,"2","SUA");
	drawButton(xi+5,yi+25,GREEN,4,27,"3","XOA");
	drawButton(xi+20,yi+20,WHITE,4,27,"4","DAT VE");
	drawButton(xi+20,yi+25,RED,4,27,"ESC","QUAY LAI");
	
	choose:
	char c1 = getch();
	// XOA MINI 
	if(c1 == '3'){
		msg = "";
		if(cb.tt == 3) msg = "KHONG THE XOA VI CHUYEN BAY DA HOAN TAT";
		if(cb.tt == 2) msg = "KHONG THE XOA VI DA BAN HET VE";
		if(cb.tt == 1 && cb.dsve.getSLDB() != 0)
			msg = "KHONG THE XOA VI DA CO VE DUOC MUA";
		if(cb.tt == 0) msg = "KHONG THE XOA VI CHUYEN BAY DA HUY";
		if(msg != "") {
			drawText(xi+5,yi+14,msg,RED);
			Sleep(600);
			clearRect(xi+5,yi+14,msg.length(),1);
			goto choose;
		}
		clearRect(xi,yi,78,28);
		x = 115; y= 4;		
		msg = " BAN CHAC CHAN XOA CHUYEN BAY THU "+itos0(vitri+1)+" : "+cb.maCB+ " (Y/N)? "; 
		string tip = " Tips: Ban co the delay thoi gian khoi hanh thay vi xoa tao moi. ";
		drawText(x,y,msg,RED);
		drawText(x-10,y+1,tip,YELLOW);
		char c1 = getch();
		if( c1 == 'y' || c1 == 'Y')
		{
			msg = "XOA CHUYEN BAY THANH CONG";
			drawText(x,y+4,msg,GREEN);
			Sleep(600);
			clearRect(x-10,y,70,5);
			clearRect(90,5+(to-1 - cur)*step,width,height);
			MB* mb = dsmb->getMB(cb.shMB);
			if(mb->sudung <= 1){
				mb->sudung = 0;
				mb->tt = 0;
			}
			else mb->sudung--;
			mcb.xoa(cb.maCB);
			change = true;
			back = true;
			delete[] a;
			goto back;
		}else{
			clearRect(x-10,y,70,5);
			goto end_loop;
		}
	}
	// SUA MINI + Lam them cai fix
	if(c1 == '2'){
		msg = "";
		if(cb.tt == 3) msg = "KHONG THE SUA VI CHUYEN BAY DA HOAN TAT";
		else{
			if( sosanhNG( cb.ngaygiokh, Baygio() ) < 0 ){
				if(sosanhNG( congPhut(cb.ngaygiokh, cb.tgbay) , Baygio() ) <= 0){
					cb.tt = (cb.tt == 0)? 0 : 3;	
					mcb.sua(cb);
					msg = (cb.tt == 3) ?"CHUYEN BAY NAY DA HOAN TAT KHONG THE SUA" : "CHUYEN BAY NAY DA HUY KHONG THE SUA";
					drawText(x+15,y+4,msg,RED);
					Sleep(600);
					clearRect(x+15,y+4,msg.length()+5,1);
					goto back;
					}
				}
		}
		if(msg != "") {
			drawText(xi+5,yi+14,msg,RED);
			Sleep(600);
			clearRect(xi+5,yi+14,msg.length(),1);
			goto choose;
		}
		clearRect(xi,yi,78,28);
		x = 100;
		y = 2;
			int newtt;
			int sve = cb.dsve.getSLDB();
			msg= "SUA CHUYEN BAY TAI VI TRI "+ itos0(vitri+1) +": "+cb.maCB;
			drawText(x+20,y,msg,color); 
			drawText(x,y+3, "TRANG THAI CU: ",WHITE); 
			drawNumber(x+25,y+3,cb.tt,mauTrangthaiCB(cb.tt));
			drawText(x,y+7, "NHAP -1 DE THOAT ",RED);
			drawText(x+40,y+3,"So ve da ban : ",WHITE);	drawNumber(x+70,y+3,sve,YELLOW);
			drawText(x,y+9, "CON VE     (1) DELAY THOI GIAN KHOI HANH ( XOA NEU SO VE DA BAN = 0)",YELLOW);
			drawText(x+20,y+10,"Tips: HET VE (2) se duoc cap nhat tu dong ",YELLOW);
			drawText(x,y+11,"HOAN TAT   (3) KHONG THE SUA HOAC XOA ",RED);
			drawText(x,y+12,"HUY CHUYEN (0) CO THE SUA , KHONG THE XOA ",RED);
			
			do{
				fflush(stdin);
				drawText(x,y+5,"TRANG THAI (0/1/3): ",WHITE);
				gotoxy(x+25,y+5); 
				cin>>newtt;
				if(newtt == -1) {
					clearRect(x,y,70,16);	
					clearRect(90,5+(to-1 - cur)*step,width,height);		
					goto end_loop;
				}
			}while(newtt < 0 || newtt > 3 && newtt == 2);
			drawText(x+20, y+14, "BAN CO CHAC CHAN MUON THAY DOI ?",YELLOW );
			CB *mang ;
			char c1 = getch();
			if( c1 == 'y' || c1 == 'Y'){
			if(cb.tt != newtt){
				if(newtt == 3)
					msg = " TRANG THAI DA CHUYEN SANG HOAN TAT (3) ";
				if(newtt == 1)
					if( sve == cb.dsve.getSL() ){
						msg = " TRANG THAI DA CHUYEN SANG HET VE (2) ";
						newtt = 2;
					}else
					msg = " TRANG THAI DA CHUYEN SANG CON VE (1) ";
				if(newtt == 0)
					msg = " TRANG THAI DA CHUYEN SANG HUY CHUYEN (0) ";
				change = true;
			}else{
				msg = " TRANG THAI KHONG THAY DOI ";
			}
			drawText(x+10, y+16,msg,GREEN);
			// Khi con ve hoac het ve thi chuyen sang DELAY time
			if(newtt != 1 && newtt != 2 ){
				Sleep(600);
				gotoxy(0,0);
				clearRect(x,y+1,70,17);
				gotoxy(0,0);
				clearRect(120,2,58,1);
				cb.tt = newtt;
				if(change) mcb.sua(cb);
					suaTTcapnhatHK(cb);
				mcb.lietkeCB(4,2,from,to);
				delete[] a;
				goto back;
			}
			else // NEU DELAY THOI GIAN 
			{
			string tip,tip2;
				
			 	// XU LY NGAY GIO DELAY
				CB* mang;
				int sl = 0; 
				bool had = mcb.mangSohieu(cb.shMB,mang,sl);
		
				date_again:
				
				// NGhia la may bay nay duoc su dung lan dau 
				string leftside, rightside = "";
				NG newdate = cb.ngaygiokh;
				NG chuyenbaytoithieu = congPhut(newdate,cb.tgbay);
				
				NG ghtren;
				NG ghduoi;
			
				// TH1 : Chi duy nhat 1 may bay de delay 
				if( sl == 1 )  ghduoi = Baygio();
				else if( sl >= 2 ){
				// TH2 : Nhieu may bay de delay  
					int i = 0;
					bool found = false;
					NG tgketthuc ; 
					ghduoi = Baygio();   
					for( i = 0; i < sl ; i++){
					if( sosanhNG(mang[i].ngaygiokh, cb.ngaygiokh) != 0 ){
						chuyenbaytoithieu = congPhut( ghduoi, cb.tgbay );
						// Neu Chuyen bay toi thieu > thoi gian khoi hanh cua thang ke tiep thi cap nhat gioi han duoi 
							if ( sosanhNG( chuyenbaytoithieu , mang[i].ngaygiokh ) > 0 ){
								// So sanh neu thang ket thuc ma lon hon ca Baygio() thi cho no la Baygio() 
								// nguoc lai gioihan duoi la ket thuc cua thang truoc do 
								tgketthuc = tinhTGden(mang[i].ngaygiokh, mang[i].sbden);
								ghduoi = sosanhNG( tgketthuc, Baygio() ) > 0 ? tgketthuc : Baygio();
							// Neu Chuyen bay toi thieu < thoi gian khoi hanh cua thang ke tiep thi cap nhat gioi han tren 
							}else if(!found){
								// Tim ra gioi han tren dau tien cua no 
								found = true;
								ghtren = truPhut( mang[i].ngaygiokh, cb.tgbay);
								rightside = NGtoString(ghtren);
								if( sosanhNG( ghtren, cb.ngaygiokh ) == 0 ) {
									clearRect(x,y+1,70,26);
									gotoxy(0,0);
									clearRect(120,2,58,1);
									drawText(x+10,y+2,"KHONG THE DELAY DUOC VI TRUNG GIO KHOI HANH ",RED);
									drawText(x,y+4," < Gioi han tren : "+NGtoString(ghtren)+" == Ngay gio kh :"+ NGtoString(cb.ngaygiokh) +" >",RED);
									goto back;
								}
							}					
						}
					}
				}
		 	
		 	// KET THUC XU LY NGAY GIO DELAY 
		 	clearRect(x+10, y+16,msg.length(),1);
			// DELAY THOI GIAN KHOI HANH BAT DAU O DAY 	
			drawText(x+20, y+17," DELAY THOI GIAN KHOI HANH ",GREEN);
				
			// GIAO DIEN INIT 
			drawText(x+10,y+20," DEN "+cb.sbden+" :",YELLOW); drawText(x+35,y+20,"+ "+itos0(cb.tgbay)+" phut",CYAN);
	
			leftside = NGtoString(ghduoi);
			msg = " THOI GIAN KHOI HANH : ";
			drawText(x+10,y+18,msg,YELLOW );
			msg = " THOI GIAN QUY DINH (DELAY) ";
			
			drawText(x+10, y + 23,msg,YELLOW);  drawText(x+msg.length()+15, y + 23,"> "+leftside,RED);
					    if(rightside != "")	 drawText(x+msg.length()+15, y + 24,"< "+rightside,RED);	
			
			InputDate(x+35,y+18, newdate ,Baygio());
				if( rightside != ""){
					if( NGtoString(newdate) >= rightside || NGtoString(newdate) <= leftside)
					{
					clearRect(x,y+18,70,1);
					drawText(x+10,y+26,"NGAY GIO KHOI HANH KHONG HOP LE",RED);
					Sleep(600);
					clearRect(x+10,y+26,50,1);
					goto date_again;
					}
				}else
					if(NGtoString(newdate) <= leftside){
					clearRect(x,y+18,70,1);
					drawText(x+10,y+26,"NGAY GIO KHOI HANH KHONG HOP LE",RED);
					Sleep(600);
					clearRect(x+10,y+26,50,1);
					goto date_again;
					}
				msg = "BAN CO MUON LUU THAY DOI KHONG ? (Y/N)";
				drawText(x+10,y+26,msg,RED);
				char c1 = getch();
				if(c1 == 'y' || c == 'Y')
				{
					change = true;
					cb.tt = newtt;
					cb.ngaygiokh = newdate;
					mcb.sua(cb);
					Sleep(600);
					clearRect(120,2,40,1);
					clearRect(x,y+1,70,26);
					goto back;
				}else{
					change = false;
					clearRect(x,y+1,70,26);
					gotoxy(0,0);
					clearRect(120,2,58,1);
					goto end_loop;
				}	
			}
		}else{
			clearRect(120,2,58,1);
			clearRect(x,y+1,70,26);
			goto end_loop;
		}
	}
	// DAT VE MINI 
	if(c1 == '4'){
		esc = false;
		clearRect(xi,yi,78,28);
		x = 100;
		y = 4;
		if( cb.tt == 1 && cb.dsve.getSL() == cb.dsve.getSLDB() ) {
		cb.tt == 2; mcb.sua(cb); mcb.luu();
		}
		drawText(x+30,y-1,"DAT VE",YELLOW);
		drawText(x+20,y,"THONG TIN CUA CHUYEN BAY THU "+itos0(vitri),GREEN);
		
		drawText(x+5,y+2,"MA CHUYEN BAY : ",YELLOW);						drawText(x+45,y+2,cb.maCB,mauTrangthaiCB(cb.tt));
		drawText(x+5,y+4,"THOI GIAN KHOI HANH : ",YELLOW);					drawText(x+45,y+4,NGtoString(cb.ngaygiokh),CYAN);
		drawText(x+5,y+6,"MAY BAY ( Loai / soday x sodong ): ",YELLOW);   	drawText(x+45,y+6,cb.shMB, RED);
																			drawText(x+45,y+7,mb->loai + " / "+itos0(mb->soday)+"x"+itos0(mb->sodong), YELLOW);
		drawText(x+5,y+9,"SAN BAY DEN ( + thoi gian bay ): ",YELLOW);     	drawText(x+45,y+9,cb.sbden+" ( + " + itos0(cb.tgbay) + " phut ) ", CYAN );
																			drawText(x+45,y+10, NGtoString( congPhut(cb.ngaygiokh, cb.tgbay) ), CYAN );	
		if(cb.tt == 3 || cb.tt == 0 || cb.tt == 2){
			msg = (cb.tt == 3)? "CHUYEN BAY NAY DA HOAN TAT" : (cb.tt == 2)? "CHUYEN BAY DA HET VE" :"CHUYEN BAY NAY DA HUY";
			drawText(x+10,y+11,msg,RED);  
			drawText(x+15,y+12,"KHONG THE DAT VE",RED);
			esc = true;
		}
		
		drawText(x+25,y+15,"DANH SACH VE CON TRONG ",YELLOW);
		drawText(x+45,y+16,"So ve da ban : "+itos0(cb.dsve.getSLDB())+" / "+itos0(cb.dsve.getSL()),GREEN);
		
		int sodong = mb->sodong, soday = mb->soday;
		string back;
		string front ;
		Ve* ve = cb.dsve.laydanhsach();
		for(int i=0; i < soday ;i++)
		{
			front = 65 + i;
			drawText(x+5,y+17+i,front, CYAN);
			for(int j=0; j <sodong;j++){
				if( j == 0 ) back = "00";
				else back = ( j/10 < 1 )? "0" + itos(j):itos(j);
				if( ve[i*sodong + j].CMND == "")
					drawText(x+8+j*3,y+17+i,back, YELLOW);
				else
					drawText(x+8+j*3,y+17+i,back, GREEN);
//					veChoNgoi(x+j*(width+mx),y+i*(height+my),width,height,front+back,GREEN);
			}
		}
		char c1;
		if( esc ) {
		drawText(x+25,y+17+soday+1,"Bam ki tu bat ki de thoat ..",RED);
		c1 = getch();
		clearRect(x,y-1,75,30);
		goto end_loop;
		}
		
		drawText(x+20,y+17+soday+1,"BAN CO MUON DAT VE KHONG ? (Y/N)",GREEN);
		drawText(x+15,y+17+soday+2,"Tips: Ve da duoc dang ki se co mau xanh luc ",YELLOW);
		c1 = getch();
		if( c1 == 'y' || c1 == 'Y'){
		clearRect(x,y-1,75,30);	
		change = menuVe(cb);
		clearRect(0,0,FULL_W,FULL_H);
		TieudeChuyenBay(4,2);
		ThanhHuongDanCB(HD_CB, n_CB, 40, 3, 40);
		move = true;
		delete[] a;
		goto back;
		}
		Sleep(500);
		clearRect(x,y-1,75,30);
		goto end_loop;
	//	clearRect(120,2,40,1);
	}
	if( c1 == ESC ){
		c1 = '\0';
		c = '\0';
		goto back;
	}
	if( c1 != ESC && c1 != '4' && c1 != '3' && c1 != '2') {
	
	goto choose;
	}
}

int mauTrangthai( int tt ){
	return (tt == 1 )? RED : GREEN; 	
}

int chonChuyenBay(int from, int to, int color){
		// Khoi tao
	int width = 2, height = 1, step=2, x = 90 , y = 5 , mx = 20, 
		vitri = -1, vt = -1; 
	char c = '\0';
	int cur = from;
	// To mau thang dau tien 
	drawFillRect(x, y , width, height, color );
	while(1){
		c = getch();
		if (c == -32){
			c = getch();
			// Chon vi tri 
			if (c == UP){ 
				clearRect(x, y + cur*step , width, height);
				
				if(cur > from) cur--;
				else cur = from;
				
				drawFillRect(x, y + cur*step , width, height, color );		
			}
			if (c == DOWN){ 
				clearRect(x, y + cur*step , width, height);
				
				if(cur < to - 1) cur++;
				else cur = to - 1;
				
				drawFillRect(x, y + cur*step, width, height, color );
			}
		
		}
		if (c == ENTER){
			clearRect(x, y + (cur)*step, width, height);
			return cur;
		}
		if(c == ESC){
			clearRect(x, y + (cur)*step, width, height);
			return -1;
		}
	}
}

bool datVe(int &from ,int &to,int &page ,int color ){
		// -------------------------------------------------- CHON CHUYEN BAY CAN SUA ------------------------------------
		int width = 2, height = 1, step = 2;
		bool esc = false, change = false;
		int  n = mcb.getN() , npage = ( n >= 10 ? ( n%10 != 0 )? n/10 + 1 : n/10 : 1),
		vitri = -1;
		if( n == 0 ) return change;
	back: 	
		// Muon sua nhieu hay thay doi nhieu thi sua o day => bo change len tren 
		bool move = false; 
		if(change) move = true;
		int cur = to-1, x = 90, y = 5;
		char c;
	Cursor(false);
	clearRect(x,y,width,height);
	if(vitri != -1)
	{
	drawFillRect(x,y+(to-1 - vitri)*step,width,height,color);
	cur = vitri;
	}else
	drawFillRect(x,y,width,height,color);
	
	while(1){
		if(move)
		{
			clearRect(4,4,85,22);
			move = false;
			drawFillRect(x,y+(to-1 - cur)*step,width,height,color);
			
			// Trang 1 / 2 --------------- 
			drawText(36,27,"Trang ",WHITE);
			drawNumber(43,27,page,WHITE);
			drawText(46,27,"/",WHITE);
			drawNumber(49,27,npage,YELLOW);
			// --------------------------- 
			mcb.lietkeCB(4,2,from,to);
		}
		c = getch();
		if (c == -32){
			c = getch();
			if (c == LEFT){
				if( to + 10 <= n){
					clearRect(x,y+(to-1 - cur)*step,width,height);
					from = to;
					to = to + 10 >= n? n : to + 10 ;
					move = true;
					page--;	
					cur = to-1;
					drawFillRect(x,y+(to-1 - cur)*step,width,height,color);
				}			
			}
		// Luc dau to = maxlen && from = to - 10
			if (c == RIGHT){ 		
				if( to > 10){
					clearRect(x,y+(to-1 - cur)*step,width,height);
					to = from;
					from = to - 10 <= 0? 0 : to - 10 ;
					move = true;
					page++;	
					cur = to-1;
					drawFillRect(x,y+(to-1 - cur)*step,width,height,color);
				}	
			}
			if (c == UP){
				if(cur < to-1){
					clearRect(x,y+(to-1 - cur)*step,width,height);
				 	cur++;
				 	drawFillRect(x,y+(to-1 - cur)*step,width,height,color);
				} 	
			}
			if (c == DOWN){
				if(cur > from) {
					clearRect(x,y+(to-1 - cur)*step,width,height);
					cur--;
					drawFillRect(x,y+(to-1 - cur)*step,width,height,color);
				}	
			}
		}
		if (c == ESC) {
			clearRect(120,2,40,1);
			clearRect(x,y+(to-1 - cur)*step,width,height);
			gotoxy(0,0);
			vitri = -1;
			return change;
		}
		if (c == ENTER) {
			vitri = cur;
			break;
		}
	}
	
	// ----------------------------- HIEN THI THONG TIN CUA CHUYEN BAY -------------------------------
	esc = false;
	x = 100;
	y = 4;
	CB cb = mcb.getCB(vitri);
	MB* mb = dsmb->getMB(cb.shMB);
	string msg;
	if( cb.tt == 1 && cb.dsve.getSL() == cb.dsve.getSLDB() ) {
		cb.tt == 2; mcb.sua(cb);
	}
	drawText(x+30,y-1,"DAT VE",YELLOW);
	drawText(x+20,y,"THONG TIN CUA CHUYEN BAY THU "+itos0(vitri),GREEN);
	
	drawText(x+5,y+2,"MA CHUYEN BAY : ",YELLOW);						drawText(x+45,y+2,cb.maCB,mauTrangthaiCB(cb.tt));
	drawText(x+5,y+4,"THOI GIAN KHOI HANH : ",YELLOW);					drawText(x+45,y+4,NGtoString(cb.ngaygiokh),CYAN);
	drawText(x+5,y+6,"MAY BAY ( Loai / soday x sodong ): ",YELLOW);   	drawText(x+45,y+6,cb.shMB, RED);
																		drawText(x+45,y+7,mb->loai + " / "+itos0(mb->soday)+"x"+itos0(mb->sodong), YELLOW);
	drawText(x+5,y+9,"SAN BAY DEN ( + thoi gian bay ): ",YELLOW);     	drawText(x+45,y+9,cb.sbden+" ( + " + itos0(cb.tgbay) + " phut ) ", CYAN );
																		drawText(x+45,y+10, NGtoString( congPhut(cb.ngaygiokh, cb.tgbay) ), CYAN );	
	
	if(cb.tt == 3 || cb.tt == 0 ){
		msg = (cb.tt == 3)? "CHUYEN BAY NAY DA HOAN TAT" :"CHUYEN BAY NAY DA HUY";
		drawText(x+10,y+11,msg,RED);  
		drawText(x+15,y+12,"KHONG THE DAT VE",RED);
		esc = true;
	}else{
		// Qua gio khoi hanh roi thi khong the dat ve du may bay con bat mua ve 
		if( sosanhNG( cb.ngaygiokh, Baygio() ) <= 0 ){
			msg = "CHUYEN BAY DA QUA GIO KHOI HANH";
			drawText(x+10,y+11,msg,RED);  
			drawText(x+15,y+12,"KHONG THE DAT VE",RED);
			esc = true;
		}
	}
	
	drawText(x+25,y+15,"DANH SACH VE CON TRONG ",YELLOW);
	drawText(x+45,y+16,"So ve da ban : "+itos0(cb.dsve.getSLDB())+" / "+itos0(cb.dsve.getSL()),GREEN);
	
	int sodong = mb->sodong, soday = mb->soday;
	string back;
	string front ;
	Ve* ve = cb.dsve.laydanhsach();
	for(int i=0; i < soday ;i++)
	{
		front = 65 + i;
		drawText(x+5,y+17+i,front, CYAN);
		for(int j=0; j <sodong;j++){
			if( j == 0 ) back = "00";
			else back = ( j/10 < 1 )? "0" + itos(j):itos(j);
			if( ve[i*sodong + j].CMND == "")
				drawText(x+8+j*3,y+17+i,back, YELLOW);
			else
				drawText(x+8+j*3,y+17+i,back, GREEN);
//				veChoNgoi(x+j*(width+mx),y+i*(height+my),width,height,front+back,GREEN);
		}
	}
	char c1;
	if( esc ) {
	drawText(x+25,y+17+soday+1,"Bam ki tu bat ki de thoat ..",RED);
	c1 = getch();
	clearRect(x,y-1,75,30);
	goto back;
	}
	
	drawText(x+20,y+17+soday+1,"BAN CO MUON DAT VE KHONG ? (Y/N)",GREEN);
	drawText(x+15,y+17+soday+2,"Tips: Ve da duoc dang ki se co mau xanh luc ",YELLOW);
	c1 = getch();
	if( c1 == 'y' || c1 == 'Y'){
		clearRect(x,y-1,75,30);	
		change = menuVe(cb);
		clearRect(0,0,FULL_W,FULL_H);
		TieudeChuyenBay(4,2);
		ThanhHuongDanCB(HD_CB, n_CB, 40, 3, 40);
		return change;
	}
	Sleep(500);
	clearRect(x,y-1,75,30);
	goto back;
//	clearRect(120,2,40,1);
	return change;
}

string dropboxSohieu(int x, int y, string *a, int n, string init, int xi, int yi ){
	string temp = init ;
	MB* mb;
	back:
	// Khoi tao 
	int dem = 1;
	int mx = (C15/2)-2;
	int vitri = 0;
	int *indexs = new int[n]; 
	Reint(indexs,n);
	int from = 0 , to= ( n < 10 )? n: 10, subn; 
	int color = mauTrangthai(stoi( a[0].substr(a[0].length()-1,1) ));
	int left = ( n%10 != 0 ) ? 1 : 0;
	int npage = n/10 <= 1 ? 1 + left : left + n/10, curpage = 1;
	bool table = true;
	bool updown = true;
	bool write = false;
	
	if(temp != ""){
		drawText(xi,yi,temp,YELLOW);
	}
	 char c;
	// Xu ly giao dien dau 
	drawText(x+mx-2,y+y-3,"< "+itos(curpage)+" / "+itos(npage)+" >",YELLOW);
	drawRect(x,y,C15+2,11);
	// Liet ke
	for(int i=from; i<to; i++){
		color = mauTrangthai(stoi( a[i].substr(a[i].length()-1,1) ));  
		drawText( x + mx, y+i+1, a[i].substr(0,a[i].length()-1), color);
	}
	// 
	color = mauTrangthai(stoi( a[vitri].substr(a[vitri].length()-1,1) )); 
	drawBgText( x + mx, y+vitri-from+1, a[vitri].substr(0,a[vitri].length()-1), color);
	
	Cursor(false);
	while(1){
		// Hien thi thong so 
		if(dem == 1) {
			mb = dsmb->getMB(vitri);
			clearRect(x - 3,y+15,33,3);
			drawText(x - 3, y+15,"Loai MB: ",YELLOW); drawText(x + 7,y+15,mb->loai,CYAN);
			drawText(x - 3, y+16,"Soday x Sodong: ",YELLOW); drawText(x + 17,y+16,itos0(mb->soday)+" x "+itos0(mb->sodong),CYAN);
		}
		// Bat ki tu 
		c =getch();
		
			if (c == -32 || c == 0)
				{
					
					c = getch();
					if(table){
						if( c ==LEFT )
							if( curpage != 1 )
							{
								
								updown = true;
								clearRect(xi,yi,C15,2);
								clearRect(x,y,C15+2+5*(dem/10),11);
								drawText(x+mx-2,y+y-3,"< "+itos(--curpage)+" / "+itos(npage)+" >",YELLOW);
								drawRect(x,y,C15+2,11);
								to = from != 0 ? from : to;
								from = from - 10 <= 0 ? 0 : from -10;
								for(int i=from; i<to; i++){
									color = mauTrangthai(stoi( a[i].substr(a[i].length()-1,1) ));  
									drawText( x + mx, y+i-from+1, a[i].substr(0,a[i].length()-1), color);
								}
								dem = 1;
								vitri = from;
								color = mauTrangthai(stoi( a[vitri].substr(a[vitri].length()-1,1) )); 
								drawBgText( x + mx, y+vitri-from+1, a[vitri].substr(0,a[vitri].length()-1), color);
							}			
						if( c == RIGHT)
							if(curpage != npage)
							{
								
								updown = true;
								clearRect(xi,yi,C15,2);
								clearRect(x,y,C15+2+5*(dem/10),11);
								drawText(x+mx-2,y+y-3,"< "+itos(++curpage)+" / "+itos(npage)+" >",YELLOW);
								drawRect(x,y,C15+2,11);				
								from = to != n ? to : from;
								to = to + 10 <= n ? to+10 : n;
								for(int i=from; i<to; i++){
									color = mauTrangthai(stoi( a[i].substr(a[i].length()-1,1) ));  
									drawText( x + mx, y+i-from+1, a[i].substr(0,a[i].length()-1), color);
								}
								dem = 1;
								vitri = from;
								color = mauTrangthai(stoi( a[vitri].substr(a[vitri].length()-1,1) )); 
								drawBgText( x + mx, y+vitri-from+1, a[vitri].substr(0,a[vitri].length()-1), color);
							}
					if(updown){	
						if( c == UP ){
							dem = 1; 
							if(vitri > from ) {
								color = mauTrangthai(stoi( a[vitri].substr(a[vitri].length()-1,1) )); 
								drawBgText( x + mx, y+vitri-from+1, a[vitri].substr(0,a[vitri].length()-1), BLACK, color);
								vitri--;
								color = mauTrangthai(stoi( a[vitri].substr(a[vitri].length()-1,1) )); 
								drawBgText( x + mx, y+vitri-from+1, a[vitri].substr(0,a[vitri].length()-1), color);
							}
						}
						if( c == DOWN ){
							dem = 1;
							if(vitri < to -1 ) {
								color = mauTrangthai(stoi( a[vitri].substr(a[vitri].length()-1,1) )); 
								drawBgText( x + mx, y+vitri-from+1, a[vitri].substr(0,a[vitri].length()-1), BLACK, color);
								vitri++;
								color = mauTrangthai(stoi( a[vitri].substr(a[vitri].length()-1,1) )); 
								drawBgText( x + mx, y+vitri-from+1, a[vitri].substr(0,a[vitri].length()-1), color);
							}
						}
					}
				}
			}else{ 
			write:
			gotoxy(xi+temp.size(),yi);
			Cursor(true);
			int x9 = 0;
			int y9 = 0;
			if( temp.size() < C15 ){
			if( c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9')
				{
					
					if(write){
						if( c == UP )
							c = '\b';
							write = false;
					}
					
					Reint(indexs,n);
					table = false;
					updown = false;
					vitri = 0;
					x9 = y9 = 0;
					dem = 0;
					gotoxy(xi+temp.size(),yi);
					temp+=c;
					cout<<c; 
					
						clearRect(x,y,C15+2+5*(n/10),13);
						drawText(xi,yi+1,"< FILTER >",YELLOW);
						for(int i = 0; i < n; i++){
							if( search(upper(temp), a[i].substr(0,a[i].length()-1)) != "" ){
								color = mauTrangthai(stoi( a[i].substr(a[i].length()-1,1) ));  
								if(dem % 10 == 0 && dem >= 10) {x9 += 10; y9 -= dem;}
								if(dem < 20){
									indexs[dem] = i;
									drawText( x + mx + x9, y+(dem++)+1 + y9, a[i].substr(0,a[i].length()-1), color);
								}else{
									drawText( x + 10 + mx, y + 11, "...", YELLOW);
									drawText( x , y + 12, "CHI CHON DUOC KHI SO LUONG <= 10", RED );
								}
									if(dem == 1) vitri = i;
								}
							}
						}
					gotoxy(xi+temp.size(),yi);
					
			}
			
			if( c == BACKSPACE )
				if(trim(temp).size() != 0)
				{
				 Reint(indexs,n);
				 table = false;
				 updown = false;
				 vitri = 0;
				 dem = 0;
				 temp.erase(temp.size()-1,1); 
				 gotoxy(xi+temp.size()+1,yi);
				 cout<<"\b \b";
				 
				 	clearRect(x,y,C15+2+5*(n/10),13);
				 	drawText(xi,yi+1,"< FILTER >",YELLOW);
				 	if(temp != "")
					for(int i = 0; i < n; i++){
						if( search(upper(temp), a[i].substr(0,a[i].length()-1)) != ""){
							color = mauTrangthai(stoi( a[i].substr(a[i].length()-1,1) ));  
							if(dem % 10 == 0 && dem >= 10) {x9 += 10; y9 -= dem;}
							if(dem < 20){
									indexs[dem] = i;
									drawText( x + mx + x9, y+(dem++)+1 + y9, a[i].substr(0,a[i].length()-1), color);
								}else{
									drawText( x + 10 + mx, y + 11, "...", YELLOW);
									drawText( x , y + 12, "CHI CHON DUOC KHI SO LUONG <= 10", RED );
								}
							if(dem == 1) vitri = i;	
							}
					}else{
						table = true;
						clearRect(xi,yi,C15,2);
						goto back;
					}
					gotoxy(xi+temp.size(),yi);
				}

				}
			
			if(c == ESC) {
				if(write) goto write;
			clearRect(x,y,C15+2+5*(n/10),13);	
			clearRect(xi,yi,C15,2);
			clearRect(x-3,y+15,30,3);
			delete[] indexs;
			return "";
			}
			if(c == ENTER){
				Cursor(false);
				if(dem == 1){
					clearRect(x,y,C15+2+5*(n/10),13);
					clearRect(xi,yi,C15,2);
					clearRect(x-5,y+15,33,3);
					drawText(xi,yi,a[vitri].substr(0,a[vitri].length()-1),color);
					drawText(xi-10, yi+2,"Loai MB: ",YELLOW); drawText(xi,yi+2,mb->loai,CYAN);
					drawText(xi-10, yi+3,"Soday x Sodong: ",YELLOW); drawText(xi+7,yi+3,itos0(mb->soday)+" x "+itos0(mb->sodong),CYAN);		
					return a[vitri].substr(0,a[vitri].length()-1);
				}else if(dem <= 10 && dem > 0)
				{
					goto small_loop;
				}else{
					clearRect(x,y,C15+2+5*(n/10),13);
					clearRect(xi,yi,C15,2);
					clearRect(x-5,y+15,32,3);
					goto back;
				}
			}
		}
		small_loop:
		int i = 0;
		vitri = indexs[i];
		color = mauTrangthai(stoi( a[vitri].substr(a[vitri].length()-1,1) )); 
		drawBgText( x + mx, y+i+1, a[vitri].substr(0,a[vitri].length()-1), color);
		updown = false;
		write = true;
		Cursor(false);
		while(1){
		// --------------------------------
		c = getch();
		if (c == -32 || c == 0)
			{ c = getch();
				if( c == UP ){
					if( i > 0 ) {
						color = mauTrangthai(stoi( a[vitri].substr(a[vitri].length()-1,1) )); 
						drawBgText( x + mx, y+i+1, a[vitri].substr(0,a[vitri].length()-1), BLACK, color);
						vitri = indexs[--i];
						color = mauTrangthai(stoi( a[vitri].substr(a[vitri].length()-1,1) )); 
						drawBgText( x + mx, y+i+1, a[vitri].substr(0,a[vitri].length()-1), color);
					}else{		
						goto write;
					}
				}
				if( c == DOWN ){
					if(i < dem-1) {
						color = mauTrangthai(stoi( a[vitri].substr(a[vitri].length()-1,1) )); 
						drawBgText( x + mx, y+i+1, a[vitri].substr(0,a[vitri].length()-1), BLACK, color);
						vitri = indexs[++i];
						color = mauTrangthai(stoi( a[vitri].substr(a[vitri].length()-1,1) )); 
						drawBgText( x + mx, y+i+1, a[vitri].substr(0,a[vitri].length()-1), color);
					}
				}
				// HIEN THI THONG TIN KHI HOVER 
				if( i != -1 ) {
					mb = dsmb->getMB(vitri);
					clearRect(x-3,y+15,33,3);
					drawText(x - 3, y+15,"Loai MB: ",YELLOW); drawText(x + 7,y+15,mb->loai,CYAN);
					drawText(x - 3, y+16,"Soday x Sodong: ",YELLOW); drawText(x + 17,y+16,itos0(mb->soday)+" x "+itos0(mb->sodong),CYAN);
				}	
			}
			
			if( c == ENTER){
				clearRect(x,y,C15+2+5*(n/10),13);
				clearRect(xi,yi,C15,2);
				clearRect(x-3,y+15,33,3);
				drawText(xi,yi,a[vitri].substr(0,a[vitri].length()-1),color);
				drawText(xi -10, yi+2,"Loai MB: ",YELLOW); drawText(xi,yi+2,mb->loai,CYAN);
				drawText(xi -10, yi+3,"Soday x Sodong: ",YELLOW); drawText(xi+7,yi+3,itos0(mb->soday)+" x "+itos0(mb->sodong),CYAN);		
				return a[vitri].substr(0,a[vitri].length()-1);
				}
			if( c == ESC){
				clearRect(x,y,C15+2+5*(n/10),13);
				clearRect(xi,yi,C15,2);
				clearRect(x-3,y+15,33,3);
				goto back;
			}
		}
}

string dropboxSBden( int x, int y, string *a, int n, string init, NG now, int &time,  int xi, int yi){
	string temp = init;
	back:
	// Khoi tao 
	int dem = 1;
	int textcolor = BLACK;
	int vitri = 0;
	int mx = C15/3;
	int *indexs = new int[n]; 
	Reint(indexs,n);
	int from = 0 , to= 10, subn; 
	int color = YELLOW;
	int left = ( n%10 != 0 ) ? 1 : 0;
	int npage = n/10 <= 1 ? 1 + left : left + n/10, curpage = 1;
	bool table = true;
	bool updown = true;
	bool write = false;
	NG then; int tgbay = time;
    char c;
    
	if(temp != ""){
		drawText(xi,yi,temp,YELLOW);
	}
//    clearRect(x-8,y,20,15);
	// Xu ly giao dien dau 
	drawText(x+4,y+12,"< "+itos(curpage)+" / "+itos(npage)+" >",YELLOW);
	drawRect(x,y,C15+2,11);
	// Liet ke
	for(int i=from; i<to; i++){
		drawText( x + mx , y+i+1, a[i], color);
	}
	drawBgText( x + mx, y+vitri-from+1, a[vitri], color,textcolor);
	
	Cursor(false);
	while(1){
		if( dem == 1){
			clearRect(x-3,y+15,30,3);
				tgbay = timTGbay( a[vitri] );
				//then = tinhTGden(now, a[vitri] );
			clearRect(x+10,y+14,18,1);
			drawText(x-7,y+14,"Thoi gian bay: ",YELLOW);  drawText(x+10,y+14,itos0(tgbay) + " phut",CYAN);
//			drawText(x-7,y+15,"Den san bay luc: ",YELLOW); drawText(x+10,y+15,NGtoString(then),CYAN);
		}
		c =getch();
			if (c == -32 || c == 0)
				{
					c = getch();
					if(table){
						if( c ==LEFT )
							if( curpage != 1 )
							{
								updown = true;
								clearRect(xi,yi,C15,2);
								clearRect(x,y,C15+2+5*(dem/10),13);
								curpage--;
								drawText(x+4,y+12,"< "+itos(curpage)+" / "+itos(npage)+" >",YELLOW);
								drawRect(x,y,C15+2,11);
								to = from != 0 ? from : to;
								from = from - 10 <= 0 ? 0 : from -10;
								for(int i=from; i<to; i++){
									drawText( x + mx, y+i-from+1, a[i], color);
								}
								dem = 1;
								vitri = from;
								drawBgText( x + mx, y+vitri-from+1, a[vitri], color,textcolor);
							}			
						if( c == RIGHT)
							if(curpage != npage)
							{
								updown = true;
								clearRect(xi,yi,C15,2);
								clearRect(x,y,C15+2+5*(dem/10),13);
								curpage++;
								drawText(x+4,y+12,"< "+itos(curpage)+" / "+itos(npage)+" >",YELLOW);
								drawRect(x,y,C15+2,11);		
								from = to != 22 ? to : from;		
								to = to + 10 < 22 ? to + 10 : 22;
								for(int i=from; i<to; i++){ 
									drawText( x + mx, y+i-from+1, a[i], color);
								}
								dem = 1;
								vitri = from;
								drawBgText( x + mx, y+vitri-from+1, a[vitri], color,textcolor);
							}	
						if(updown){	
							if( c == UP ){
							dem = 1; 
							if(vitri > from ) {
								drawBgText( x + mx, y+vitri-from+1, a[vitri], BLACK, color);
								vitri--;
								drawBgText( x + mx, y+vitri-from+1, a[vitri], color, textcolor );
							}
						}
							if( c == DOWN ){
							dem = 1;
							if(vitri < to-1) {
								drawBgText( x + mx, y+vitri-from+1, a[vitri], BLACK, color);
								vitri++;
								drawBgText( x + mx, y+vitri-from+1, a[vitri], color,textcolor);
							}
						}	
					}
				}
			}
			else{ 
			write:
			gotoxy(xi+temp.size(),yi);
			Cursor(true);
			int x9 = 0;
			int y9 = 0;
			if( temp.size() < C15 ){
			if( c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9' || c == ' ' )
				{
					if(write){
						if( c == UP )
							c = '\b';
							write = false;
					}
					Reint(indexs,n);
					table = false;
				 	updown = false;
					vitri =0;
					x9 = y9 = 0;
					dem = 0;
					gotoxy(xi+temp.size(),yi);
					if ( temp[temp.size()-1] == ' ' && c == ' ')
					{
						c = '\b';
					}
					temp+=c;
					cout<<c; 
						clearRect( x - 6, y + 12, 28, 1 );
						clearRect(x,y,C15+2+5*(n/10),13);
						drawText(xi,yi+1,"< FILTER >",YELLOW);
						for(int i = 0; i < n; i++){
							if( search(temp, a[i]) != "" ){  
								if(dem % 10 == 0 && dem >= 10) {x9 += 10; y9 -= dem;}
								if(dem < 11){
									indexs[dem] = i;
									drawText( x + mx - 5 + x9, y+(dem++)+1 + y9, a[i], color);
								}else{
									drawText( x + mx - 5, y + 11, "...", YELLOW);
									drawText( x - 6, y + 12, "CHI CHON DUOC KHI SO LUONG <= 10", RED );
								}								
							if(dem == 1) vitri = i;
								}
							}
						}
					gotoxy(xi+temp.size(),yi);
			}
			if( c == BACKSPACE )
				if(trim(temp).size() != 0)
				{
				 Reint(indexs,n);
				 table = false;
				 updown = false;
				 vitri = 0;
				 dem = 0;
				 temp.erase(temp.size()-1,1); 
				 gotoxy(xi+temp.size()+1,yi);
				 cout<<"\b \b";
				 	clearRect( x - 6, y + 12, 28, 1 );
				 	clearRect(x,y,C15+2+5*(n/10),13);
				 	drawText(xi,yi+1,"< FILTER >",YELLOW);
				 	if(temp != "")
					for(int i = 0; i < n; i++){
						if( search(temp, a[i]) != ""){  
							if(dem % 10 == 0 && dem >= 10) {x9 += 10; y9 -= dem;}
							if(dem < 11){
								indexs[dem] = i;
								drawText( x + mx - 5 + x9, y+(dem++)+1 + y9, a[i], color);
							}else{
								drawText( x + mx - 5, y + 11, "...", YELLOW);
								drawText( x - 6, y + 12, "CHI CHON DUOC KHI SO LUONG <= 10", RED );
							}
							if(dem == 1) vitri = i;
							}
					
						}else{
							table = true;
							clearRect( x - 6, y + 12, 28, 1 );
							clearRect(xi,yi,C15,2);
							goto back;
						}
						gotoxy(xi+temp.size(),yi);
					}
				}
			if(c == ESC) {
			clearRect( x - 6, y + 12, 28, 1 );
			clearRect(x,y,C15+2+5*(n/10),13);	
			clearRect(xi,yi,C15,2);
			clearRect(x-7,y+14,29,2);
			delete[] indexs;
			return "";
			}
			if(c == ENTER){
				Cursor(false);
				if(dem == 1){
					clearRect( x - 6, y + 12, 28, 1 );
					clearRect(x,y,C15+2+5*(n/10),13);
					clearRect(xi,yi,C15,2);
					drawText(xi,yi,a[vitri],color);		
					drawText(xi-7,yi+2,"Thoi gian bay: ",YELLOW);  drawText(xi+10,yi+2,itos0(tgbay) + " phut",CYAN);
//					drawText(xi-7,yi+3,"Den san bay luc: ",YELLOW); drawText(xi+10,yi+3,NGtoString(then),CYAN);
					clearRect(x-7,y+14,29,2);
					time = tgbay;
					return a[vitri];
				}else if(dem <= 10 && dem > 0)
				{
					goto small_loop;
				}else{
					clearRect( x - 6, y + 12, 28, 1 );
					clearRect(x,y,C15+2+5*(n/10),13);
					clearRect(xi,yi,C15,2);
					clearRect(x-7,y+14,29,2);
					goto back;
				}
			}
		}
		small_loop:
		int i = 0;
		vitri = indexs[i];
		color = YELLOW;
		drawBgText( x + mx - 5, y+i+1, a[vitri], color, textcolor);
		updown = false;
		write = true;
		while(1){
		c = getch();
		if (c == -32 || c == 0)
			{ c = getch();
				if( c == UP ){
					if(i > 0 ) {
						drawBgText( x + mx - 5, y+i+1, a[vitri], BLACK, color);
						vitri = indexs[--i];
						drawBgText( x + mx - 5, y+i+1, a[vitri], color,textcolor);
					}else{
						goto write;
					}
				}
				if( c == DOWN ){
					if(i < dem-1) {
						drawBgText( x + mx - 5, y+i+1, a[vitri], BLACK, color);
						vitri = indexs[++i];
						drawBgText( x + mx - 5, y+i+1, a[vitri], color,textcolor);
					}
				}
			
			}
			if( i >= 0 && i < dem){
					clearRect(x-3,y+15,30,3);
					tgbay = timTGbay( a[vitri] );
					//then = tinhTGden(now, a[vitri] );
					drawText(x-7,y+14,"Thoi gian bay: ",YELLOW);  drawText(x+10,y+14,itos0(tgbay) + " phut",CYAN);
//					drawText(x-7,y+15,"Den san bay luc: ",YELLOW); drawText(x+10,y+15,NGtoString(then),CYAN);
			}	
			if( c == ENTER){
					clearRect(x,y,C15+2+5*(n/10),13);
					clearRect(xi,yi,C15,2);
					clearRect(x-7,y+14,20,2);
					drawText(xi,yi,a[vitri],color);
					drawText(xi-7,yi+2,"Thoi gian bay: ",YELLOW);  drawText(xi+10,yi+2,itos0(tgbay) + " phut",CYAN);
//					drawText(xi-7,yi+3,"Den san bay luc: ",YELLOW); drawText(xi+10,yi+3,NGtoString(then),CYAN);
					clearRect(x-7,y+14,30,2);
					time = tgbay;
					return a[vitri];
				}
			if( c == ESC){
				clearRect(x,y,C15+2+5*(n/10),13);
				clearRect(xi,yi,C15,2);
				clearRect(x-7,y+14,32,2);
				goto back;
			}
		}
}

//----------------------------------------------------------------------------------------------------------------------------------//
//                                                           VE                                                                     //  
//  --------------------------------------------------------------------------------------------------------------------------------//

void KhungChonVe(int x,int y, int sodong, int soday, DsVe &ds, int mx, int my, bool hienthivedat){
	int phantu = sodong * soday;
	// Tim Khoang cach giua 2 khung theo x va theo y
	Ve* dsve = ds.laydanhsach();
	// FIXED 
	int width=4,height=2;
	// theo So day A,B,C,D,E,F 
	for(int i=0;i<soday;i++)
	{
		string back;
		char front = 65 + i;
		// theo So dong 00-99 
		for(int j=0;j<sodong;j++){
			if( j == 0 ) back = "00";
			else back = ( j/10 < 1 )? "0" + itos(j):itos(j);
			if( dsve[i*sodong + j].CMND == "")
				veChoNgoi(x+j*(width+mx),y+i*(height+my),width,height,front+back,YELLOW);
			else if(hienthivedat)
				veChoNgoi(x+j*(width+mx),y+i*(height+my),width,height,front+back,GREEN);
		}
	}
}

void ThanhHuongDanVe(string* tieude, int n_tieude, int buoc_nhay, int start_x, int start_y ){
	drawFillRect(2,38,177,1,CYAN);
	drawRect(2,1,177,35);
	drawButton(5,40,YELLOW,4,27,"1","DAT VE");
	drawButton(32,40,CYAN,4,27,"2","HUY VE");
	drawButton(130,40,GREEN,4,27,"3","TIM CMND");
	drawButton(160,40,RED,4,27,"ESC","THOAT");
}

bool menuVe(CB cb){
	clearRect(0,0,FULL_W,FULL_H);
	int width=4,height=2,mx,my,x,y;
	
	// Lay thong tin MAY BAY 
	MB *mb = dsmb->getMB(dsmb->tim(cb.shMB));
	// De x,y ben ngoai de lat hoi lam cai Chon Ve() 
	int sodong = mb->sodong, soday = mb->soday;
	int n = sodong*soday;
	// Canh kich thuoc cai khung va khoang cach
	if( n == 300 )
	{  x = 15; y = 3; mx = my =1; }
	else{
		x = MID_W - sodong*3 - soday ;
		y = MID_H - 4 - soday*2 ;
		mx=my=0;
	}
	if( mx <= 0)
	{
		if(my <= 0)
		{
			mx = 3;
			my = 1;
		}
	}
	string title = "CHUYEN BAY "+cb.maCB+" den "+cb.sbden+" luc "+NGtoString(cb.ngaygiokh);
	string subtitle ="MAY BAY "+mb->sohieu+" co "+itos(sodong)+" x "+itos(soday)+" cho ngoi";
	int top = 2;y+= top;
	// Phan chinh 
	KhungChonVe(x,y,sodong,soday,cb.dsve,mx,my);
	// Phan thanh cong cu && Khung lon 
	ThanhHuongDanVe(HD_CB, n_CB, 40, 3, 40);
	// Tieu de 
	drawFillRect(MID_W - title.size()/2-1,0,title.size()+2,3,BLACK);
	drawText(MID_W - title.size()/2,1,title,YELLOW);
	drawText(MID_W - subtitle.size()/2,2,subtitle,YELLOW);
	// Chuc nang
	bool change ;
	change = ChonVe(x,y,sodong,soday,cb,mx,my);
		
	if(change){
		if( cb.dsve.getSLDB() == cb.dsve.getSL() ) cb.tt = 2; 
		else
		// Neu ngay khoi hanh > Bay gio thi ko cb.tt = 1 
			if( sosanhNG(cb.ngaygiokh , Baygio()) > 0 ){
				cb.tt = 1;
		//Neu khong, ngaygioketthuc > Bay gio khong ? Co => cb.tt = 1 : cb.tt = ( cb.tt == 0 ) ? 0 : 3;
				}else if( sosanhNG( congPhut(cb.ngaygiokh,cb.tgbay), Baygio()) > 0 ){
					cb.tt = 1;
					}else cb.tt = ( cb.tt == 0 ) ? 0 : 3;
		
		mcb.sua(cb);
		return true;
	}
	return false;
}

void veChoNgoi(int x,int y,int width,int height,string text,int color){
	setColor(color);
	drawRect(x,y,width,height);
	drawText(x+1,y+1,text,color);
	setColor(WHITE);
}

void toChoNgoi(int x,int y,int width,int height,string text,int bgcolor,int color){
	setColor(color);
	setBGColor(bgcolor);
	drawRect(x,y,width,height);
	drawBgText(x+1,y+1,text,bgcolor,color);
	setBGColor(BLACK);
	setColor(WHITE);
}

string VetoString(Ve ve){
	return ve.socn + " " + HKtoString( mhk.getHK( mhk.tim( ve.CMND ) ) ) ;
}

Ve dropboxVe( int x , int y, Ve *a, int n){
	// Xoa khung begin 
	clearRect(x,y,50,5);
	gotoxy(0,0);
	
	// Ve khung 
	drawRect(x,y,50,5);
	bool move = true;
	int mx = 2, from = 0, to = n >= 4 ? 4 : n  
	, page = 1 , npage = ( n >= 4 ? ( n%4 != 0 )? n/4 + 1 : n/4 : 1), cur = from;
	Ve vei;
	while(1){
	
	if(move){
		cur = from ;
		clearRect(x+mx,y+1,47,3);
		drawText(x+mx+49,y+4,itos0(page)+"/"+itos0(npage),YELLOW);
		for(int i = from ; i < to; i++ ){
			vei = a[i];
			if( cur == i )
			drawBgText(x+mx,y+1+i-from,VetoString( vei ), YELLOW , BLACK );
			else
			drawText(x+mx,y+1+i-from,VetoString( vei ), YELLOW );
		}
		
		move = false;
		vei = a[cur];
	}
	
	char c = getch();
		if( c == -32){
			c = getch();
			if( c == LEFT ){
				if( from != 0){
				from = from - 4 <= 0 ? 0 : from - 4;
				to = from + 4; 
				page--;
				move = true;
				
				}
			}
			
			if( c == RIGHT ){
				if( to != n){
				from = to;
				to = to + 4 < n ? to + 4 : (to + 4 > n) ? to + ( n - to ) : n  ; 
				page++;
				move = true;
				
				}
			}
			if( c == UP ){
				if(cur > from){
				drawText(x+mx,y+1+cur-from,VetoString( vei ), YELLOW);
				cur--;
				vei = a[cur];
				drawBgText(x+mx,y+1+cur-from,VetoString( vei ), YELLOW , BLACK );	
				}
			}
			
			if( c == DOWN ){
				if( cur < to-1 ){
				drawText(x+mx,y+1+cur-from,VetoString( vei ), YELLOW );
				cur ++;
				vei = a[cur];
				drawBgText(x+mx,y+1+cur-from,VetoString( vei ), YELLOW , BLACK );	
				}
			}
		}
		if( c == ESC ){
			cur = -1;
			break;
		}
		if( c == ENTER){
			break;
		}
	}
	// Xoa khung end 
	clearRect(x+mx+49,y+4,5,1);
	clearRect(x,y,50,5);
	gotoxy(0,0);
	return vei;
	
}

bool HKduocdatVekhong( HK hk, CB cb){
	bool kq = true;
	hk.ranh = capnhatHKranh(hk.tgban);
	if( hk.ranh ) return kq;
	else{
		string *arr;
		int n = 0;
		char sep = ',';
		NG tgkh = cb.ngaygiokh;
		NG tgkt = congPhut( tgkh , cb.tgbay );
	
		// ARR luu nhung ma Chuyen bay 
		splitStrTo(hk.tgban , arr, n, sep );
		// Tra ra mang cac may bay chua khoi hanh 
		if( n != 0 ){
			CB cbi; 
			// Nghia la chi co 1 Chuyen bay trong mang thi chi can 
			if( n == 1 ){
				// Thang thoi gian khoi hanh cua no 
				cbi = mcb.getCB( arr[0] );
				if( cbi.maCB == "" ) return kq;
				// NgaygioKh cua chuyen bay i nho hon NgaygioKh cua chuyen bay hien tai  
				if( sosanhNG( cbi.ngaygiokh, tgkh ) < 0 ){	
					// so Ngaygiokt cua chuyen bay i co lon hon NgaygioKh cua chuyen bay hien tai khong ? 
					if( sosanhNG( congPhut( cbi.ngaygiokh, cbi.tgbay ) , tgkh ) > 0 ) 
						//   Co : true  // Khong : false 
						kq =  false;
					return kq;
				}
				// NgaygioKH cua chuyen bay i lon hon NgaygioKH cua chuyen bay hien tai 
				else if ( sosanhNG(cbi.ngaygiokh, tgkh) > 0 ){
				// so Ngaygiokt cua chuyen bay i co lon hon NgaygioKh cua chuyen bay hien tai khong ? 
					if( sosanhNG( cbi.ngaygiokh , tgkt ) < 0 ) 
						//   Co : true  // Khong : false 
						kq =  false;
					return kq;
				
				}else if ( sosanhNG(cbi.ngaygiokh,tgkh) == 0 ) return false;
				// Cung dau la dung, khac dau la sai 
			}else
			// n > 1 
			for( int i = 0; i < n; i++){
				cbi = mcb.getCB( arr[i] );
				if( cbi.maCB == "" ) continue;
				// NgaygioKh cua chuyen bay i nho hon NgaygioKh cua chuyen bay hien tai  
				if( sosanhNG( cbi.ngaygiokh, tgkh ) < 0 ){	
					// so Ngaygiokt cua chuyen bay i co lon hon NgaygioKh cua chuyen bay hien tai khong ? 
					if( sosanhNG( congPhut( cbi.ngaygiokh, cbi.tgbay ) , tgkh ) > 0 ){ 
						//   Co : true  // Khong : false 
						kq =  false;
						return kq;
						}
				}
				// NgaygioKH cua chuyen bay i lon hon NgaygioKH cua chuyen bay hien tai 
				else if ( sosanhNG(cbi.ngaygiokh, tgkh) > 0 ){
				// so Ngaygiokt cua chuyen bay i co lon hon NgaygioKh cua chuyen bay hien tai khong ? 
					if( sosanhNG( cbi.ngaygiokh , tgkt ) < 0 ){ 
						//   Co : true  // Khong : false 
						kq =  false;
						return kq;
						}
				
				}else if ( sosanhNG(cbi.ngaygiokh,tgkh) == 0 ) {
						kq =  false;
						return kq;
						}
				// Cung dau la dung, khac dau la sai 
			}
			delete[] arr;
		}
	}
	return kq;
}

bool ChonVe(int x,int y, int sodong, int soday, CB &cb , int mx, int my){
	DsVe ds = cb.dsve;
	Ve* dsve = ds.laydanhsach();
	int width=4,height=2;
	NG tgkh = cb.ngaygiokh;
	NG tgkt = congPhut( tgkh , cb.tgbay );
	bool change = false;
	// i : day , j : dong 
	// cong thuc tim x cua 1 cho ngoi x+j*(width+m_x)
	// cong thuc tim y cua 1 cho ngoi y+i*(height+m_y)
	int i = 0, j = 0;
	// front + back la ten cua cho ngoi 
	toChoNgoi( x+j*(width+mx),y+i*(height+my),width,height,laytenChongoi(i,j),YELLOW,BLACK);
	char c; int socn = 0; string tencn; 
	bool back;
	back:
		Cursor(false);
		if(back) toChoNgoi( x+j*(width+mx),y+i*(height+my),width,height,laytenChongoi(i,j),YELLOW,BLACK);
		back = false;
	while(1){
		// Luc sau front + back = socn // so cho ngoi
		if(dsve[i*sodong + j].CMND ==""){
			clearRect(150,2,28,1);
		}
		else{
			clearRect(150,2,28,1);
			drawText(152,2,"CMND: ",YELLOW);
			drawText(158,2,dsve[i*sodong +j].CMND,GREEN);
			HK hk = mhk.getHK( mhk.tim(dsve[i*sodong +j].CMND) );
			drawText(150,3,hk.ho+" "+hk.ten+" ("+Phai(hk.phai)+")",GREEN);
		}
		c = getch();
		if (c == -32){
			c = getch();
			// Neu cho do khong co cmnd thi khong lam dong nay
			if(dsve[i*sodong + j].CMND =="")
			{	
				veChoNgoi( x+j*(width+mx),y+i*(height+my),width,height, laytenChongoi(i,j),YELLOW);
			}
			else{
				veChoNgoi( x+j*(width+mx),y+i*(height+my),width,height, laytenChongoi(i,j),GREEN);
			}
			// Chon vi tri 
			if (c == UP){ 
				if(i > 0) i--; 
			}
			if (c == DOWN){ 
				if(i < soday -1) i++;
			}
			if (c == LEFT){
				if(j > 0) j--;
			}
			if (c == RIGHT){ 
				if(j < sodong -1) j++;
			}
			toChoNgoi( x+j*(width+mx),y+i*(height+my),width,height,laytenChongoi(i,j),YELLOW,BLACK);
		}
		if( c != 0){
			// Them 1 flag press de an 1 lan duy nhat thoi k bi lac phim
			if( c == NB01)
			{
				// Bat nhap lai 
				if(dsve[i*sodong + j].CMND != "") {
					drawText(158,4,"VE DA DANG KI",RED);
					Sleep(600);
					clearRect(158,4,20,1);	
					back = true;
					goto back;
				}
				string CMND = "";
				HK hk = {"","","",false,"",true};
				bool again = false;
				clearRect(152,2,26,1);
				drawText(152,2,"CMND: ",YELLOW);
				int vitri = -1;
				bool esc = false;
				again:
				if(again) {
				drawText(140,3,"BAN MUON CHON HANH KHACH ? (Y/N)",RED);
				char c1 = getch();
				if( c1 == 'y' || c1 == 'Y' )
				{
					vitri = dropboxHK(60,39,cb);
					if( vitri != -1 ) {
						hk = mhk.getHK( vitri );
						CMND = hk.cmnd;
						clearRect(140,3,38,1);
						clearRect(158,2,12,1);
						drawText(158,2,hk.cmnd,mauTrangthai2(hk.ranh));
						
					}
				}
				clearRect(140,3,38,1);	
				again = false;
				}
				// Neu khong co chon 
				if( hk.cmnd == "" )
				InputString(158+CMND.size(),2,158,3,12,CMND,true,esc);
				// Thoat khoi nhap CMND 
				if(esc) {
					veChoNgoi( x+j*(width+mx),y+i*(height+my),width,height,laytenChongoi(i,j),YELLOW);
					goto esc;
				}
				// Neu ma ko bang do dai 12 thi no cu bat nhap 
				if(trim(CMND).size() != 12 )
					{
						drawText(158,3,"CMND YEU CAU 12 SO",RED);
						Sleep(600);
						clearRect(158,3,18,1);
						again = true;						
						goto again;
					}
				// Neu do dai bang 12 thi to mau xanh ma add CMND 
				else if(trim(CMND).size() == 12){
						int index = mhk.tim(CMND);
						// TIM CMND NAY CO TRONG VE KHONG => CO => DAT VE ROI / KHONG => KIEM TRA CMND CO TON TAI KHONG  
						if(ds.tim(trim(CMND)) == -1){
							// TIM THEO CMND NHAP HOAC CO ROI 
							// LUC NAY CMND da nhap xong roi nen kiem tra coi co trong bang hanh khach hay khong 
							if( index == -1){
								// Tu dong them moi 
								hk.cmnd = CMND;
								string dulieu ;
								esc = false;
								drawText(50,40,"CMND MOI CAN THEM THONG TIN ( HO / TEN / PHAI )",YELLOW);
								clearRect(55,41,C40+5,1);
								drawText(55,41,"HO    : ",YELLOW); InputString(55+10,41,55+C40,42,C40,hk.ho,false,esc);
								if (esc) {
									drawText(55,43,"DANG KI VE THAT BAI",RED);
									Sleep(600);
									clearRect(50,39,C40+10,5);
									
									back = true;
									goto back;
								}
								dulieu += (hk.ho.size() > 25)? hk.ho.substr(0,25) + "..." : hk.ho;
								clearRect(55,41,C40+5,1);
								drawText(55,42,dulieu,GREEN);
								drawText(55,41,"TEN   : ",YELLOW); InputString(55+10,41,55+C40,42,C15,hk.ten,false,esc);
								if (esc) {
									drawText(55,43,"DANG KI VE THAT BAI",RED);
									Sleep(600);
									clearRect(50,39,C40+10,5);
									
									back = true;
									goto back;
								}
								dulieu += +" "+hk.ten;
								clearRect(55,41,C40+5,1);
								drawText(55,42,dulieu,GREEN);
								drawText(55,41,"PHAI  : ",YELLOW); InputGender(55+10,41,hk.phai,esc);
								if (esc) {
									drawText(55,43,"DANG KI VE THAT BAI",RED);
									Sleep(600);
									clearRect(50,39,C40+10,5);
									
									back = true;
									goto back;
								}
								hk.ranh = false;
								hk.scb = 0;
								mhk.them(hk);
								clearRect(50,39,C40+10,5);
							// TIM THAY CMND TRONG DATABASE 
							}else {
								hk = mhk.getHK(index);
								if( !hk.ranh )
									if( !HKduocdatVekhong(hk,cb) ){
											drawText(130,4,"HANH KHACH NAY DANG TRONG CHUYEN BAY KHAC",RED);
											Sleep(600);
											clearRect(130,3,48,1);
											back = true;
											goto back;
										}
							}
							Ve vemoi = { CMND , laytenChongoi(i,j)};
							ds.them(vemoi,i*sodong + j);
							if(hk.tgban == ""){
								hk.tgban = cb.maCB;
								hk.ranh = false;
							}else{
								hk.tgban += ','+cb.maCB;
							}
							string phai = hk.phai ? "Nam" : "Nu";
							hk.scb += 1;
							mhk.sua(hk);
								drawText(150,3,hk.ho+" "+hk.ten+" ("+phai+")",GREEN);
								drawText(155,4,"DANG KI VE THANH CONG",GREEN);
								Sleep(600);
								clearRect(150,2,28,2);
								change = true;
							veChoNgoi( x+j*(width+mx),y+i*(height+my),width,height,laytenChongoi(i,j),GREEN);
						// DA CO CHO TRONG DANH SACH VE 
						}else{	
								hk = mhk.getHK(index);
								drawText(150,3,hk.ho+" "+hk.ten+" ("+Phai(hk.phai)+")",GREEN);
								drawText(155,4,"DA DAT VE ROI",RED);
								int idx = ds.tim(CMND);					
								Sleep(600);
								clearRect(150,2,28,2);
							veChoNgoi( x+j*(width+mx),y+i*(height+my),width,height,laytenChongoi(i,j),YELLOW);
							i = (idx/sodong);
							j = (idx%sodong);
							back = true;
							goto back;
						}
				}
				esc:
					Cursor(false);
				// Lay vi tri tiep theo 
				if(j < sodong -1) j++; else if(i < soday-1) i++; 
				else if(j > 0) j--; else i--;
				// Chon cho ngoi khac 
				toChoNgoi( x+j*(width+mx),y+i*(height+my),width,height,laytenChongoi(i,j),YELLOW,BLACK);
				
			}
			if( c == NB02)
			{
				if( dsve[i*sodong + j].CMND != "") {
					drawText(150,4,"HUY VE NAY (Y/N)? ",RED);
					char c = getch();
					if( c == 'y' || c == 'Y'){
						clearRect(150,3,28,1);
						drawText(150,4,"HUY VE THANH CONG",GREEN);
						Sleep(400);
						clearRect(150,3,28,1);
						change = true;
						// Ra thang hanh khach roi
						HK hk = mhk.getHK(mhk.tim(dsve[i*sodong + j].CMND));
						// Khoi tao tro giup 
						string *arr;
						int n;
						char sep = ',';
						// 
						splitStrTo( hk.tgban , arr , n, sep );
						if( n == 1 ){
							hk.tgban = "";
						} else for(int i = 0; i < n ; i++){
							if (arr[i] == cb.maCB)	arr[i] = "";
								merStrTo(hk.tgban, arr, n, sep);
						}
						if( hk.tgban == "" ){
						 	hk.ranh = true ;
						}else hk.ranh = false;
						if ( hk.scb > 0) hk.scb -= 1;
						mhk.sua(hk);
						dsve[i*sodong + j].CMND = ""; ds.setSLDB(ds.getSLDB()-1);
						veChoNgoi( x+j*(width+mx),y+i*(height+my),width,height,laytenChongoi(i,j),RED);		
						delete[] arr;
					}else{
						clearRect(150,3,28,1);
						veChoNgoi( x+j*(width+mx),y+i*(height+my),width,height,laytenChongoi(i,j),GREEN);
					}
				if(j < sodong -1) j++; else if(i < soday-1) i++; 
				else if(j > 0) j--; else i--;
				toChoNgoi( x+j*(width+mx),y+i*(height+my),width,height,laytenChongoi(i,j),YELLOW,BLACK);
				}
			}
			
			
			if( c == NB03 ){
				choose_again:
				bool esc=  false, again = false;
				string CMND = ""; int vitri = -1;
				clearRect(150,3,28,1);
				// Tim CMND 
				if(ds.getSLDB() == 0){
					drawText(150,4,"KHONG CO VE DAT",RED);
					Sleep(600);
					clearRect(150,3,28,1);
				}else{
					clearRect(150,2,28,1);
					// Drop box HK theo YC 
					drawText(150,2,"TIM CMND :",YELLOW);
					InputString(163,2,158,3,12,CMND,true,esc);
					if(esc){
						goto back;
					}
					// Neu CMND = size thi bo 
					if(CMND.size() == 12){
						vitri = ds.tim(CMND);
						if(vitri == -1)
							drawText(150,4,"KHONG CO VE NAO VOI CMND NAY!",RED);
						else
							drawText(150,4,"CMND NAY O "+dsve[vitri].socn,GREEN);
						Sleep(600);
						clearRect(150,3,28,1);
						if(vitri != -1){
							veChoNgoi( x+j*(width+mx),y+i*(height+my),width,height,laytenChongoi(i,j),YELLOW);
							i = (vitri/sodong);
							j = (vitri%sodong);
							back = true;
							goto back;
						}else goto choose_again;
					}else{
						drawText(150,4,"MOI BAN LUA CHON!",RED);
						Sleep(600);
						clearRect(150,3,28,1);
						int dem = 0;
						Ve *a = new Ve[ds.getSLDB()];
						// Tao 1 Dropbox cho cac CMND dang ton tai o do 
						for( int i = 0; i < ds.getSL(); i++){
							if( dsve[i].CMND != "")
								a[dem++] = dsve[i]; 
						}
						Ve vei = dropboxVe( 60, 39 , a , ds.getSLDB() );						
						int ive,jve; ds.layvtChongoi(vei.socn,ive,jve);
						int oldcolor = dsve[i*sodong + j].CMND == ""? YELLOW : GREEN;
						veChoNgoi( x+j*(width+mx),y+i*(height+my),width,height,laytenChongoi(i,j),oldcolor);
						i = ive;
						j = jve;
						back = true;
						goto back;
					}
					
					// Cho no chon ? Filter khong ? ( toi da 200 phan tu ) 
					
					// Chon xong r cho den vi tri do 
				}
				// Enter neu trung 
				
				// 
			}
		}
		if ( c == ESC){
				drawText(150,4,"BAM ESC LAN NUA DE THOAT",RED);
				char c = getch();
					if( c == ESC)
					{
						cb.dsve = ds;	
						clearRect(150,3,28,1);
						drawText(150,4,"DANG THOAT ..",GREEN);
						Sleep(400);
						clearRect(150,3,28,1);
						return change;
					}else clearRect(150,3,28,1);
				}
	}
}

//----------------------------------------------------------------------------------------------------------------------------------//
//                                                           THONG KE                                                               //  
//  --------------------------------------------------------------------------------------------------------------------------------//

void menuTK(){
	int cur = 0, n = 4, x = 65 , y = 10
	, step = 6, width = 48
	, color = CYAN;
	char c = '\0';
	string msg ;
	back :
	Cursor(false);
	drawRect(2,1,177,40);
	nutDieukhien(10,36,6,80,false,false,true);
	const string items[n] = {"LIET KE HANH KHACH CHUYEN BAY", "DSCB THEO NGAY VA NOI DEN", "SO LUOT THUC HIEN CB THEO MB","DANH SACH VE TRONG CUA CB"};
	for(int i=0;i<n;i++) frame_not_choose_item2( x,y-5+i*6,items[i],width,WHITE);
	frame_choose_item2( x,y-5+cur*6,items[cur],width,color);
	while(1){
		c = getch();
		// ESC 
		if( c == ESC ){
			msg = " -- Bam ESC nua de thoat -- ";
			drawText( x + 10, y-5+n*step + 2, msg , RED );
			if( getch() == ESC )
				return;
			else clearRect( x + 10, y-5+n*step+2, msg.length() ,1);
		}
		if( c == ENTER){
			clearRect( x, y-5, width , n*step +2 );
			clearRect(10,36-6/2,168,6);		
				switch( cur ){
					case 0 :
 						lietkeHKthuocCB();
						goto back;
						break;
					case 1 :
						DsHKtheoNGvaND();
						goto back;
						break;
					case 2 :
						ThongkeSoluotMB();
						goto back;
						break;
					case 3 :
						DsVetrongTK();
						goto back;
						break;
					default : 
						goto back;
						break;
				}
		}
		
		if( c == UP)
			if(cur > 0){
			frame_not_choose_item2( x ,y-5+cur*6,items[cur],width,WHITE);
			cur--;
			frame_choose_item2( x ,y-5+cur*6,items[cur],width,color);
		}
		if( c == DOWN)
			if(cur < n-1){
			frame_not_choose_item2(x,y-5+cur*6,items[cur],width,WHITE);
			cur++;
			frame_choose_item2(x,y-5+cur*6,items[cur],width,color);
		}
		
	}
}

int chonCBmini( int x, int y, int *indexs, int n, string *a , bool ktra_ve_trong){
	char c = '\0';
	int vt = 0, i = 0;
	Cursor(false);
	vt = indexs[i];
	int color = mauTrangthaiCB(stoi( a[vt].substr(a[vt].length()-1,1) )); 
	drawBgText( x, y+1, a[vt].substr(0,a[vt].length()-1), color, BLACK);
	CB cb;
		while(1){
		// HIEN THI THONG TIN KHI HOVER 
			cb = mcb.getCB(vt);
			clearRect(x+20,y,55,3);
			drawText(x+20,y,   "Ngay gio khoi hanh : "  , YELLOW);
			drawText(x+20,y+1, "San bay den ( + thoi gian bay ) : ",YELLOW);
			drawText(x+20,y+2, "So ve da ban : ",YELLOW);
			drawText(x+55,y,  NGtoString(cb.ngaygiokh)  , CYAN);
			drawText(x+55,y+1,  cb.sbden + "( " + itos0(cb.tgbay) + "p )"  , CYAN);
			drawText(x+55,y+2,  itos0(cb.dsve.getSLDB()) +" / "+ itos0(cb.dsve.getSL()) , CYAN);
		// --------------------------------
		c = getch();
		if (c == -32 || c == 0)
			{ 
			c = getch();
				if( c == UP ){
					if( i > 0){
						color = mauTrangthaiCB(stoi( a[vt].substr(a[vt].length()-1,1) )); 
						drawBgText( x, y+i+1, a[vt].substr(0,a[vt].length()-1), BLACK, color);
						vt = indexs[--i];
						color = mauTrangthaiCB(stoi( a[vt].substr(a[vt].length()-1,1) )); 
						drawBgText( x, y+i+1, a[vt].substr(0,a[vt].length()-1), color, BLACK);
					}	
				}
				if( c == DOWN ){
					if(i < n-1) {
						color = mauTrangthaiCB(stoi( a[vt].substr(a[vt].length()-1,1) )); 
						drawBgText( x, y+i+1, a[vt].substr(0,a[vt].length()-1), BLACK, color);
						vt = indexs[++i];
						color = mauTrangthaiCB(stoi( a[vt].substr(a[vt].length()-1,1) )); 
						drawBgText( x, y+i+1, a[vt].substr(0,a[vt].length()-1), color, BLACK);
					}
				}
				
					
			}
			
			if( c == ENTER){
				CB cb = mcb.getCB(vt);
				drawBgText( x, y+i+1, a[vt].substr(0,a[vt].length()-1), BLACK, color);
				if( cb.dsve.getSLDB() == 0 && ktra_ve_trong) {
					drawText(x,y+n+2,"CHUYEN BAY NAY CHUA CO HANH KHACH",RED);
					Sleep(600);
					clearRect(x,y+n+2,35,1);
				drawBgText( x, y+i+1, a[vt].substr(0,a[vt].length()-1), color, BLACK);
				}else
				return vt;
			}
			if( c == ESC){
				clearRect(x+20,y,55,3);
				drawBgText( x, y+i+1, a[vt].substr(0,a[vt].length()-1), BLACK, color);
				return -1;
			}
		}
}

CB chonCBdeLietke( int x,int y, int xi, int yi, string &tmp, int color, bool ktra_ve_trong ){	
	// KHOI TAO
	bool move = true, back = false,lietketen = false,table = true,reset = false;
	CB cb;
	int width = 20 , height = 11, err_x = 1 , err_y = 1 , mx = 4
	, n = mcb.getN(), npage = ( n >= 10 ? ( n%10 != 0 )? n/10 + 1 : n/10 : 1)
	, page = 1 , from = 0, to = (n >= 10)? 10 : n
	, indexs[n], dem = 0, cur = from
	, txtcolor , vt = -1;
	string title;
	string *a; mcb.laymaCB(a);
	char c;
	
	// QUAY LAI
	back:
		title = "TIM CHUYEN BAY :   ";
		c = '\0';
		
		Reint(indexs,n);
	    dem = 1; 
		
		lietketen = false;
			 back = false;	
			table = true;
		Cursor(false);
					
	drawText( xi - title.size() , yi , title ,RED);
	while(1){
			if(tmp.size() != 0 && c == '\0'){
				dem= 0;
				Reint(indexs,n);
				vt = -1;
				drawText( xi + mx, yi ,tmp, WHITE);
				clearRect( x , y , width , height+4 );
				for( int i = 0 ; i < n ; i++ ){
					if( search(tmp, a[i].substr(0,a[i].length()-1)) != "" ){  
						if(dem < 10){
							indexs[dem++] = i;
						}else{
							drawText( xi + mx + 2, yi + 12,".......",YELLOW);
						}
						// NEU DEM = 1 THI OUT RA CHO THONG TIN LUON KEM CHUC NANG 
						 	if(dem == 1) {
							 vt = i;
							cur = vt;
							}
						}
					}
					if(move) move = false;
					if(table) table = false;
					// LIET KE THEO INDEXS STRING TYPE 
					if( dem != 0)
					{
						lietketen = true;
						goto lietketen;	
					}
					
				}
		// LIET KE THEO TEN 
			lietketen:
			if(lietketen){
				for( int i = 0; i < dem ; i++){
					txtcolor = mauTrangthaiCB(stoi( a[indexs[i]].substr(a[indexs[i]].length()-1,1) ));
					drawText( xi +mx + 2, yi + 2 + i , a[indexs[i]].substr(0,a[indexs[i]].length()-1), txtcolor );
				}
				lietketen = false;
				
		}	
		if(move){
			if(reset){
				reset = false;
				cur = from;
			}
			vt = cur;
			clearRect( x+1 , y+1 , width-2 , height-2 );
			drawRect( x, y, width, height );
	
			drawText( x+6,y+height+2,"< "+itos0(page)+" / "+itos0(npage)+" >",YELLOW );
			for(int i = from; i< to; i++){
				if( cur == i ){
					txtcolor = mauTrangthaiCB( stoi(a[i].substr(a[i].length()-1,1) ) );
					drawBgText( x+mx ,y+1+i-from,a[i].substr(0,a[i].length()-1), txtcolor, BLACK );
				}
				else{
					txtcolor = mauTrangthaiCB( stoi(a[i].substr(a[i].length()-1,1) ) );
					drawText( x+mx ,y+1+i-from,a[i].substr(0,a[i].length()-1), txtcolor );
				}
			}
			move = false;
		}
		
		if(dem == 1){
			CB cb = mcb.getCB(cur);
			clearRect(x+25,y,55,3);
			drawText(x+25,y,   "Ngay gio khoi hanh : "  , YELLOW);
			drawText(x+25,y+1, "San bay den ( + thoi gian bay ) : ",YELLOW);
			drawText(x+25,y+2, "So ve da ban : ",YELLOW);
			drawText(x+55,y,  	NGtoString(cb.ngaygiokh)  , CYAN);
			drawText(x+55,y+1,  cb.sbden + "( " + itos0(cb.tgbay) + "p )"  , CYAN);
			drawText(x+55,y+2,  itos0(cb.dsve.getSLDB()) +" / "+ itos0(cb.dsve.getSL()) , CYAN);
		}
	
		if( c == ESC ){
			drawText( x-5, y+height+4, "-- Bam ESC lan nua de thoat --",RED);
			if(getch() == ESC){
			// Clear thong tin
			clearRect(x+25,y,55,3);
			// Clear khung 
			clearRect( xi - 20 , yi , width + mx + 20 , height+4 );
			clearRect(x-10,y+height+4,35,1);
			cb.maCB = "";
			delete[] a;
			return cb;
			}
			clearRect(x-10,y+height+4,35,1);
			move = true;
			goto back;
		}
		if( c == ENTER){
			if( dem == 1){
				cb = mcb.getCB(vt);
				if( cb.dsve.getSLDB() == 0 && ktra_ve_trong) {
					drawText(x-10,y+height+4,"CHUYEN BAY NAY CHUA CO HANH KHACH",RED);
					Sleep(600);
					clearRect(x-10,y+height+4,35,1);
					move = true;
					goto back;
				}
				txtcolor = mauTrangthaiCB(stoi( a[vt].substr(a[vt].length()-1,1) ));
				drawText(xi+mx, yi, a[vt].substr(0,a[vt].length()-1), txtcolor );
				goto end_loop;	
			}
			else if(dem > 1 && dem <= 10){
				vt = chonCBmini( xi+mx+2, yi+1, indexs, dem, a , ktra_ve_trong);
				if(vt != -1){
					txtcolor = mauTrangthaiCB(stoi( a[vt].substr(a[vt].length()-1,1) ));
					drawText(xi+mx, yi, a[vt].substr(0,a[vt].length()-1), txtcolor );
					goto end_loop;
				}
			}else if(dem == 0){
				if( tmp == ""){
				move =  true; 
				goto back;				
				}
			}
		}
		
		c =getch();
		if (c == -32){	
				c = getch();
				if(table){
					if( c == LEFT){
						if( page > 1){
							to = from != 0 ? from : to ;
							from = to - 10 <= 0? 0 : to - 10;
							move = true;
							page--;	
							cur = from;
						}			
					}
					if( c == RIGHT){
						if( page < npage){
						from = to;
						to = to + 10 >= n? n : to + 10;
						page++;
						move = true;
						cur = from;
						}
					}
					if( c == UP ){
						dem = 1; 
						if( cur > from ) {
							txtcolor = mauTrangthaiCB(stoi( a[cur].substr(a[cur].length()-1,1) )); 
							drawBgText( x + mx, y+cur-from+1, a[cur].substr(0,a[cur].length()-1), BLACK, txtcolor);
							cur--;
							txtcolor = mauTrangthaiCB(stoi( a[cur].substr(a[cur].length()-1,1) )); 
							drawBgText( x + mx, y+cur-from+1, a[cur].substr(0,a[cur].length()-1), txtcolor,BLACK);
							vt = cur;
						}
					}
					if( c == DOWN ){
						dem = 1;
						if( cur < to -1 ) {
							txtcolor = mauTrangthaiCB(stoi( a[cur].substr(a[cur].length()-1,1) )); 
							drawBgText( x + mx, y+cur-from+1, a[cur].substr(0,a[cur].length()-1), BLACK ,txtcolor);
							cur++;
							txtcolor = mauTrangthaiCB(stoi( a[cur].substr(a[cur].length()-1,1) )); 
							drawBgText( x + mx, y+cur-from+1, a[cur].substr(0,a[cur].length()-1), txtcolor,BLACK);
							vt = cur;
						}
					}
				}
			}
			else{
				clearRect(x+25,y,55,3);
				table = false;
				if( tmp.size() < C15 ){
				if( c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9'){
					gotoxy(xi + mx + tmp.size(), yi);
					tmp += c;
					cout<<c;
					dem = 0;
					Reint(indexs,n);
					vt = -1;
					clearRect( x , y , width , height+4 );
					for( int i = 0 ; i < n ; i++ ){
						if( search(tmp, a[i].substr(0,a[i].length()-1)) != "" ){  
							if(dem < 10){
								indexs[dem++] = i;
							}else{
								drawText( xi + mx + 2, yi + 12,".......",RED);			
							}
							// NEU DEM = 1 THI OUT RA CHO THONG TIN LUON KEM CHUC NANG 
							 if(dem == 1) {
								 vt = i;
								cur = vt;
								}
							}
						}
						// LIET KE THEO INDEXS STRING TYPE 
						if( dem != 0)
						{
							lietketen = true;
							goto lietketen;	
						}
					}
				}	
				if( c == BACKSPACE ){
					
					if ( tmp.size() > 0  )
					{
					tmp.erase(tmp.size() - 1 , 1 ); 
					gotoxy(xi + mx + tmp.size()+1,yi);
					cout<<"\b ";		 
					}
					
					dem= 0;
					Reint(indexs,n);
					vt = -1;
					clearRect( x , y , width , height+4 );
					if(tmp.size() != 0){
					//clearRect(xi+mx,yi+1,C15+18,12);
					for( int i = 0 ; i < n ; i++ ){
						if( search(tmp, a[i].substr(0,a[i].length()-1)) != "" ){  
							if(dem < 10){
								indexs[dem++] = i;
							}else{
								drawText( xi + mx + 2 , yi + 12,".......",RED);	
							}
							// NEU DEM = 1 THI OUT RA CHO THONG TIN LUON KEM CHUC NANG 
							 	if(dem == 1) {
								 vt = i;
								cur = vt;
								}
							}
						}
						// LIET KE THEO INDEXS STRING TYPE 
						if( dem != 0)
						{
							lietketen = true;
							goto lietketen;	
						}
					}else {
						move = true;
						goto back;
					}
				}
				
				
			}
			

	}	
	end_loop:
	cb = mcb.getCB(vt);
	drawText(x-10,y+height+4,"BAN CHAC CHAN MUON CHON (Y/N) ?",RED);
	char c1 = getch();
	if(c1 == 'y' || c1 == 'Y'){
		clearRect(xi-20,yi,100,18);
		return cb;
	}else{
		clearRect(xi-20,yi,100,18);
		move = true;
		goto back;
	}
}

void lietkeHKthuocCB(){
	drawRect(2,1,177,40);
	int n = mcb.getN() , x = 80, y = 15;
	CB cb;
	// ----------------- PHAN TIM VA CHON MA CHUYEN BAY ------------------------------ 
		string tmp;
		back: 
		nutDieukhien( 10 ,37, 6 , 85, true, false, false);
		if(n == 0){
			Cursor(false);
			drawText(x -5, y,"KHONG CO CHUYEN BAY DE THONG KE !", RED);
			drawText(x -5, y+1,"------- Bam ESC de thoat -------",RED);
			getch();
			return;
		}else{
			cb = chonCBdeLietke(x,y+2,x,y,tmp,BLUE);
			if(cb.maCB == ""){
				clearRect(10,37-6/2,168,6);		
				return;
			}
		}
	// ----------------- PHAN THONG KE ------------------------------
		clearRect(10,37-6/2,168,6);		
	int x_tt= 65, x_mcb = 105, y_mcb = 2, 
		x_nkh = 60, y_nkh = 4,
		x_nd = 125, y_nd = 4;
	// XOA HET TRUOC KHI VE MOI 
	//	clearRect(3,y_mcb,175,30);
	// VE TIEU DE 
	drawText(x_tt,y_mcb,"DANH SACH HANH KHACH THUOC CHUYEN BAY",WHITE);
	drawText(x_mcb,y_mcb,cb.maCB,mauTrangthaiCB(cb.tt));
	drawText(x_nkh-20,y_nkh,"NGAY KHOI HANH : ",WHITE);
	drawText(x_nkh,y_nkh,NGtoString(cb.ngaygiokh),CYAN);
	drawText(x_nd-13,y_nd,"NOI DEN : ",WHITE);
	drawText(x_nd,y_nd,cb.sbden,GREEN);	
	TieudelietkeHK(32,8);
	nutDieukhien( 10 ,37, 6 , 80, false, true, false);
	// NOI DUNG LIET KE 
	LietkeHKtheoVe( 32, 10 , cb.dsve);	
		clearRect(3,y_mcb,175,30);
		gotoxy(0,0);
		clearRect(10,37-6/2,168,6);	
		gotoxy(0,0);
	goto back;
}

void TieudelietkeHK( int x, int y){
int height = 2, 
	line_height  = y + height - 1, mx = 8 , 
	// VE 1 CAI HOP NGOAI BAO TRUM 4 TIEU DE 
	w_stt =  0 , // VE BAT DAU O DAY 
	w_sve =  10,
	w_cm  =  20, // KET THUC STT VA MO DAU CMND W20
	w_ht  =  50, // KET THUC CMND VA MO DAU HO TEN W30
	w_p   =  90, // KET THUC HOTEN VA MO DAU PHAI W20
	width = 110;
	drawRect( x, y, width, height);
	
	// ----------- TIEU DE ----------------- 
	
	drawText( x  +  w_stt + 3, line_height , "STT" ,YELLOW);
	
	draw_high_line( x+ w_sve ,y ,2);
	drawText( x+   w_sve + 4, line_height, "SO VE" ,YELLOW);
	
	draw_high_line( x+ w_cm ,y ,2);
	drawText( x+   w_cm + mx, line_height, "SO CMND" ,YELLOW);
	
	draw_high_line( x+ w_ht ,y ,2);
	drawText( x+  w_ht + mx, line_height, "HO TEN" ,YELLOW);
	
	draw_high_line( x+ w_p ,y ,2);
	drawText( x+ w_p + mx, line_height, "PHAI" ,YELLOW);
	
	// ------------------------------------- 
	return;
}

void LietkeHKtheoVe( int x, int y , DsVe ds){
	Cursor(false);
	int *indexs , n ;
	ds.layvtVedat( indexs, n);
	int npage = ( n >= 10 ? ( n%10 != 0 )? n/10 + 1 : n/10 : 1 );
		string msg = " -- CHUYEN BAY NAY KHONG CO VE NAO -- ";
		if( n == 0 ) {
			drawText( MID_W - msg.length() + 10 , y + 2 , msg , RED );
			return;
		}
	
	HK hki; Ve* dsve = ds.laydanhsach();
		//to = ( n <= 10 )? n : 10; 
	int height = 2, mx = 8 , my = 1, 
		border_line = 0,
		text_line = 0,
		w_stt =  0 , // VE BAT DAU O DAY 
		w_sve =  10,
		w_cm  =  20, // KET THUC STT VA MO DAU CMND W20
		w_ht  =  50, // KET THUC CMND VA MO DAU HO TEN W30
		w_p   =  90, // KET THUC HOTEN VA MO DAU PHAI W20
		width = 110,
		from = 0 , to = (n >= 10)? 10: n, page = 1;
	bool lietke = true; char c;
	while(1){
		if(lietke){
			lietke = false;
//			gotoxy(0,0);for( int i = from; i < to ; i++) cout<<indexs[i]<<endl;
			// Trang 1 / 1
				clearRect(MID_W - 11, y + 11*height, 20, 1);
				drawText( MID_W - 11 , y + 11*height, "Trang  " + itos0(page) +" / ", CYAN);
				drawText( MID_W , y + 11*height, itos0(npage), RED);
			// -----------
			clearRect(x,y,width,height*10);
			// REAL 
			
			for ( int i = from ; i < to; i++ ){
					if( dsve[indexs[i]].CMND != ""){
					border_line = y + (i-from)*height;
					text_line = border_line + 1 ;
					hki = mhk.getHK(dsve[indexs[i]].CMND);
					drawRect( x , border_line , width, height);
					// --------------------- MOI THANG TRONG DSVE ---------------------- //	
					// SO TT 
					drawText( x + w_stt +4 , text_line , itos0(i+1) ,RED);
					gotoxy(x + w_stt , border_line); printf("%c",195);
					
					// VE
					draw_high_line( x + w_sve , border_line ,height);
					drawText( x + w_sve + 4 , text_line , dsve[indexs[i]].socn ,RED);
					gotoxy(x + w_sve , border_line); printf("%c",195);
					
					 
					// SO CMND 
					draw_high_line( x + w_cm , border_line ,height);
					gotoxy(x + w_cm , border_line); printf("%c",195);
					drawText( x+ w_cm + mx, text_line , hki.cmnd , RED);
					
					// HO TEN 
					draw_high_line( x + w_ht , border_line  ,height);
					gotoxy(x + w_ht , border_line); printf("%c",195);
					drawText( x+ w_ht + mx, text_line , hki.ho +" "+hki.ten ,CYAN);
					
					// PHAI
					draw_high_line( x+ w_p , border_line ,height);
					drawText( x+ w_p + mx, text_line , hki.phai == 1? "Nam" : "Nu" , CYAN);
					gotoxy(x + w_p , border_line); printf("%c",195);
					
					
					gotoxy(x + width , border_line); printf("%c",195);
					// ----------------------------------------------------------------- //
					
				}
			}
		}
	// ------------------- PHAN TRANG VA TIM KIEM --------------------------------
		c = getch();
		
		if( c == LEFT)
			if( page > 1){
				to = from != 0 ? from : to ;
				from = to - 10 <= 0? 0 : to - 10;
				lietke = true;
				page--;
					
			}			

		if( c == RIGHT)
			if( page < npage ){
				from = to;
				to = to + 10 >= n? n : to + 10;
				lietke = true;
				page++;
			}
		if( c == ESC) {
			clearRect(x, y+1,width , y + height*6);
			delete[] indexs;
			return;	
		}
	}
	
}

// LIET KE VA PHAN TRANG
void LietkeCBtheoNGvaND( int x, int y ){
	int x_tt= 70, y_tt = 2, 
		x_nkh = 65,
		x_nd = 115, 
		y_nkh , y_nd = y_nkh = 4,
		tgbay = 0 ;
	
	NG ng, null;
	null.gio = 0;
	null.nam = 0;
	null.thang = 0;
	null.ngay = 0;
	null.phut = 0;
	
	ng = null;
	
	string sbd = "";
	NG base = tachNG("01-01-2020 00:00");
	bool hr_min = false;
	drawRect(2,1,177,40);
	drawText(x_tt,y_tt,"DANH SACH CHUYEN BAY KHOI HANH TRONG ",YELLOW);
	drawText(x_nkh-10,y_nkh,"NGAY : ",WHITE); 
	drawText(x_nd-10,y_nd,"NOI DEN : ",WHITE); drawText(x_nd,y_nd,"XXXX",YELLOW); 
	nutDieukhien(10,35,6,85,false,true,false);
		drawButton(120,35,YELLOW,4,27,"1","NGAY GIO KH");
		drawButton(139,35,YELLOW,4,27,"2","SAN BAY DEN");
		drawButton(158,35,GREEN,4,27,"3","RESET");

	drawText( x_nkh, y_nkh , NGtoString(ng,hr_min), CYAN);
	string *b; laySBden( b ); 
		
	// ------------- TIEU DE THONG KE -------------//
	int x_stt =  10,
		x_mcb =  30, // width MaCB 
		x_sh  =  48, // width Sh   
		x_tg  =  70, // width TG   
	    x_sbd =  100, // width SBD  
		height = 2,  
		width =  120,
		mx = 4,
		page = 1 ;
		
	bool lietke = true, change = false, tieude = true;
		Cursor(false);
	// indexs de luu vitri , n la so luong 
	int *indexs , n;
	// Khoi tao indexs se chua cac vi tri ma chuyen bay con ve 
		mcb.dsCBvoisoVe(indexs,n,ng,sbd);
	int npage = ( n >= 10 ? ( n%10 != 0 )? n/10 + 1 : n/10 : 1) 
	,from = 0, to = ( n >= 10 )? 10: n;
	drawText(x,y-1,"So Chuyen bay : "+itos0(n),GREEN);
	char c ;
	while(1){
		if( change ){
			Cursor(false);
			change = false;
			mcb.dsCBvoisoVe( indexs, n, ng, sbd );
			tieude =  true;
			lietke = true;
			clearRect(85 -10, y+12*2,27,1);
			clearRect(x,y+2,width,10*2);
			clearRect(x,y-1,30,1);
			drawText(x,y-1,"So Chuyen bay : "+itos0(n),GREEN);
			from = 0, to = ( n >= 10 )? 10: n;
			npage = ( n >= 10 ? ( n%10 != 0 )? n/10 + 1 : n/10 : 1);
			if ( n == 0 ) clearRect(x,y+2,width,10*2);
		}
		if( tieude ){
			tieude = false;
			drawRect(x,y,width,height);
			// STT 
			drawText( x+ mx ,y+1,"STT",WHITE);
			draw_high_line(x+ x_stt ,y, height);
			
			// MA CHUYEN BAY 
			drawText( x+ x_stt + mx ,y+1,"MA CHUYEN BAY",WHITE);
			draw_high_line(x+ x_mcb ,y, height);
			
			// SO HIEU 
			drawText( x+ x_mcb + mx ,y+1,"SO HIEU ",WHITE);
			draw_high_line(x+ x_sh ,y, height);
			
			// THOI GIAN 
			drawText( x+ x_sh + mx,y+1,"THOI GIAN",WHITE);
			draw_high_line(x+ x_tg ,y, height);
			
			// SAN BAY DEN 
			drawText( x+ x_tg + mx,y+1,"SAN BAY DEN",WHITE);		
			draw_high_line(x+ x_sbd ,y, height);
			
			// SO VE TRONG 
			drawText( x+ x_sbd + mx,y+1,"SO VE TRONG ",WHITE);		
			// -----------------------------------------------//
		}
		if( lietke ){
			if( n != 0) clearRect(x,y+2,width,10*2);
			lietke = false;
		// Trang 1 / 2 --------------- 
			drawText(85-8,y+12*2,"Trang ",WHITE);
			drawNumber(85,y+12*2,page,CYAN);
			drawText(85+2,y+12*2,"/",WHITE);
			drawNumber(85+4,y+12*2,npage,YELLOW);
		// --------------------------- 		
			mcb.lietkeCBtheo(x,y,indexs,n,from,to);
		}
		
		c = getch();
			if( c == -32){
				c = getch();
				if( c == RIGHT)
					if( page < npage){
						from = to != n ? to : from;
						to = to + 10 <= n ? to+10 : n;
						lietke = true;
						page++;
						}	
				if( c == LEFT)
					if( page > 1) {
						to = from != 0 ? from : to ;
						from = to - 10 <= 0? 0 : to - 10;
						lietke = true;
						page--;	
					}	
			}else{
				if ( c == NB01){
					if(sosanhNG3(ng,null) == 0) ng = Baygio();
					InputDate( x_nkh, y_nkh , ng, base,hr_min);		
					change = true;
					
				}
				if ( c == NB02){
					clearRect(x,y-1,width,height*12); // title + content 
					sbd = dropboxSBden( x_nd  , y_nd+2, b , SO_TTHANH , sbd ,Baygio(), tgbay , x_nd , y_nd );
					if(sbd != "" ) {
						drawText(x_nd,y_nd,sbd,GREEN);	
						change = true;
						Sleep(400);
						clearRect(x_nd-10,y_nd+2,40,1);
					}else{
						change = false;
						drawText(x_nd,y_nd,"XXXX",YELLOW);
					}
					
				}
				if ( c == NB03){
					ng = null;
					sbd = ""; 
					clearRect(	x_nkh,	y_nkh, 22 , 1 );
					clearRect( x_nd , y_nd, 20, 1 );
					drawText(x_nkh,y_nkh,NGtoString(ng,hr_min),CYAN); 
					drawText(x_nd,y_nd,"XXXX",YELLOW);
					change = true;
				}
			}
		if ( c == ESC){
			drawText(85 - 10, y+12*2, "-- Bam ESC nua de thoat -- ",RED);
			if( getch() == ESC){
				//	delete[] b;
				delete[] indexs;
				clearRect(x,y-1,width,height*12); // title + content 
				clearRect(x_tt - 15,y_tt, 100  , y_nkh - y_tt);
				clearRect(85 -10, y+12*2,27,1);
				clearRect(10,33,168,4);
				return ;
			}
			clearRect(85 -10, y+12*2,27,1);
			lietke = true;
		}
	}
	
}


// GIAO DIEN CHINH VA SEARCH  
void DsHKtheoNGvaND(){	
	LietkeCBtheoNGvaND( 30,8);
	return ;
}

void ThongkeSoluotthuchienCB( int x, int y ){
	int x_tt = 85 - 15 , y_tt = 4, x_nd = 70, y_nd = 6; 
	
	// Tieu de cho biet May Bay nao duoc thong ke , Dsmb gom bao nhieu MB 	
	drawRect(2,1,177,40);
	
	drawText(x_tt,y_tt,"DANH SACH MAY BAY THUC HIEN CHUYEN BAY ",YELLOW);
	drawText(x_nd-20,y_nd,"So may bay : "+itos(dsmb->laydodai()),GREEN);
	nutDieukhien(10,35,6,85,false,true,false);
	
//	drawButton(158,35,GREEN,4,27,"1","TIM MAY BAY");
	// DANH SACH MAY BAY ( SO HIEU / LOAI / SO LUOT THUC HIEN CHUYEN BAY ) 
	int mx = 4,
		width = 130,
		x_sh =  10 ,
		x_l =   30 ,
		x_sda = 80 ,
		x_sdo = 95 ,
		x_sdu = 110 ,
		height = 2;
	int *indexs, n ,page = 1, npage,
	from = 0, to = 10;
	bool tieude = true, lietke = true, init = true;
	char c = '\0';
	Cursor(false);
	while(1){
	
	// VE TIEU DE -------------------------------- 
		if(tieude){
			tieude = false;
			drawRect(x,y,width,height);
			
			drawText(x+mx,y+1,"STT",WHITE);
			draw_high_line(x+x_sh,y,height);
			
			drawText(x+x_sh+mx,y+1,"SO HIEU",WHITE);
			draw_high_line(x+x_l,y,height);
			
			drawText(x+x_l+mx,y+1,"LOAI ",WHITE);
			draw_high_line(x+x_sda,y,height);
			
			drawText(x+x_sda+mx,y+1,"SO DAY",WHITE);
			draw_high_line(x+x_sdo,y,height);
			
			drawText(x+ x_sdo + mx,y+1,"SO DONG",WHITE);	
			draw_high_line(x+x_sdu,y,height);
			
			drawText(x+x_sdu+mx,y+1,"SO CHUYEN BAY",WHITE);	
		}
		// ------------------------------------------- 
		
		if( lietke ){
			clearRect(x,y+2,width, height*10);
			lietke = false;
			dsmb->layMBcoCB_dec( indexs, n);
			npage = ( n >= 10 ? ( n%10 != 0 )? n/10 + 1 : n/10 : 1);
			// Trang 1 / 2 --------------- 
				drawText(85-8,y+12*2,"Trang ",WHITE);
				drawNumber(85,y+12*2,page,CYAN);
				drawText(85+2,y+12*2,"/",WHITE);
				drawNumber(85+4,y+12*2,npage,YELLOW);
			// --------------------------- 		
			// Them 1 cot su dung nua 
			dsmb->lietkeMBtheo(x,y,indexs,n,from,to ); 
		}
		c = getch();
		
		if( c == RIGHT)
			if( page < npage){
				from = to != n ? to : from;
				to = to + 10 <= n ? to+10 : n;
				lietke = true;
				page++;
				}	
		if( c == LEFT)
			if( page > 1) {
				to = from != 0 ? from : to ;
				from = to - 10 <= 0? 0 : to - 10;
				lietke = true;
				page--;	
			}	
		if( c == ESC ){
			drawText(85-10,y+12*height,"-- Bam ESC lan nua de thoat -- ",RED);
			if(getch() == ESC){
				clearRect(75,y+12*height,40,1);
				clearRect(x,y-2,width, height*13);
				clearRect(x_tt,y_tt,40,1);
				clearRect(10,32,168,6);
				return;
			}
			clearRect(75,y+12*height,40,1);
			lietke = true;
		}
		
	}
}

void ThongkeSoluotMB(){
	int x = 25, y = 8;
	CB cb; MB *mb; int ht = 0;
		for( int j = 0; j < mcb.getN(); j++ ){
			cb = mcb.getCB(j); 
			mb = dsmb->getMB(cb.shMB);
			ht = 0;
			if( cb.tt == 3){
				ht += 1;
			}
				mb->hoanthanh = ht;	
		}
	ThongkeSoluotthuchienCB( x , y );
	return;
}

// Cau g
void TieudelietkeVe( int x, int y){
	int height = 2, 
	line_height  = y + height - 1, mx = 8 , 
	// VE 1 CAI HOP NGOAI BAO TRUM 4 TIEU DE 
	w_stt =  0 , // VE BAT DAU O DAY 
	w_sve =  20,
	w_cm  =  40, // KET THUC STT VA MO DAU CMND W20
	width = 80;
	drawRect( x, y, width, height);
	
	// ----------- TIEU DE ----------------- 
	drawText( x  +  w_stt + 3, line_height , "STT" ,YELLOW);
	
	draw_high_line( x+ w_sve ,y ,2);
	drawText( x+   w_sve + 4, line_height, "SO VE" ,YELLOW);
	
	draw_high_line( x+ w_cm ,y ,2);
	drawText( x+   w_cm + mx, line_height, "SO CMND" ,YELLOW);
	
	// ------------------------------------- 
	return;
}

void DsVetrongcuaCB( int x, int y, CB cb){
	int n = cb.dsve.getSLtrong();
	if( n == 0){
		drawText(85-10,y+2,"CHUYEN BAY NAY KHONG CON VE TRONG",RED);
		drawText(85-8,y+3,"-- Bam nut bat ki de thoat -- ",RED);
		getch();
		clearRect(x,y+2,50,2);
		return;
	}
	
	int soday , sodong;
	dsmb->getsoDayvasoDong(cb.shMB, soday, sodong);
	int height = 2, *indexs,
	line_height  = y + height - 1, mx = 8 , 
	// VE 1 CAI HOP NGOAI BAO TRUM 4 TIEU DE 
	w_stt =  0 , // VE BAT DAU O DAY 
	w_sve =  20,
	w_cm  =  40, // KET THUC STT VA MO DAU CMND W20
	width = 80, top = 1,
	x2,y2,mx2,my2,n2,
	page = 1, from = 0 , to = (n >= 10)? 10: n ,
	border_line , text_line,
	npage = ( n >= 10 ? ( n%10 != 0 )? n/10 + 1 : n/10 : 1 );
	drawRect( x, y, width, height);
	cb.dsve.layvtVechuadat(indexs, n);
	Ve* dsve = cb.dsve.laydanhsach();
 	bool number2 = false;
	
	bool lietke = true; char c;
	while(1){
		if(lietke){
			lietke = false;
			// Trang 1 / 1
				clearRect(MID_W - 11, y + 11*height, 20, 1);
				drawText( MID_W - 11 , y + 11*height, "Trang  " + itos0(page) +" / ", CYAN);
				drawText( MID_W , y + 11*height, itos0(npage), RED);
			// -----------
			clearRect(x,y,width,height*10);
			// REAL 
			
			for ( int i = from ; i < to; i++ ){
					if( dsve[indexs[i]].CMND == ""){
					border_line = y + (i-from)*height;
					text_line = border_line + 1 ;
					drawRect( x , border_line , width, height);
					// --------------------- MOI THANG TRONG DSVE ---------------------- //	
					// SO TT 
					drawText( x + w_stt +4 , text_line , itos0(i+1) ,RED);
					gotoxy(x + w_stt , border_line); printf("%c",195);
					
					// VE
					draw_high_line( x + w_sve , border_line ,height);
					drawText( x + w_sve + 4 , text_line , laytenChongoi(indexs[i]/sodong,indexs[i]%sodong) ,RED);
					gotoxy(x + w_sve , border_line); printf("%c",195);
					
					 
					// SO CMND 
					draw_high_line( x + w_cm , border_line ,height);
					drawText( x+ w_cm +10, text_line , "<TRONG>" , RED);
					gotoxy(x + w_cm , border_line); printf("%c",195);
					
					gotoxy(x + width , border_line); printf("%c",195);
					
	
				}
			}
		}
	// ------------------- PHAN TRANG VA TIM KIEM --------------------------------
		c = getch();
		if( !number2 ){
			if( c == LEFT)
				if( page > 1){
					to = from != 0 ? from : to ;
					from = to - 10 <= 0? 0 : to - 10;
					lietke = true;
					page--;
						
				}			
	
			if( c == RIGHT)
				if( page < npage ){
					from = to;
					to = to + 10 >= n? n : to + 10;
					lietke = true;
					page++;
				}
		}
			if( c == ESC) {
				drawText(85-10,y+12*height,"-- Bam ESC lan nua de thoat -- ",RED);
				c = getch();
				if(c == ESC){
					clearRect(75,y+12*height,40,1);
					clearRect(x,y-2,width, height*13);
					clearRect(10,32,168,7);
					return;
				delete[] indexs;
				}
				if( number2 ) c = '2'; else c = '1'; 
			}
		
		if( c == '1'){
			number2 = false;
			lietke = true;
			clearRect(3,4,175,32);
			TieudelietkeVe(50,8);
		}
		if( c == '2'){
			clearRect(x,y-2,width,height*14);
			number2 = true;
			if( n2 == 300 )
			{  x2 = 15; y2 = 3; mx2 = my2 =1; }
			else{
				x2 = MID_W - sodong*3 - soday ;
				y2 = MID_H - 4 - soday*2 ;
				mx2=my2=0;
			}
			if( mx2 <= 0)
			{
				if(my2 <= 0)
				{
					mx2 = 3;
					my2 = 1;
				}
			}
			KhungChonVe(x2,y2+top,sodong,soday,cb.dsve,mx2,my2,false);
		}
	}
}

void DsVetrongTK( ){
		drawRect(2,1,177,40);
	int n = mcb.getN() , x = 80, y = 15;
	CB cb;
	// ----------------- PHAN TIM VA CHON MA CHUYEN BAY ------------------------------ 
		string tmp;
		back: 
		nutDieukhien( 10 ,37, 6 , 85, true, false, false);
		if(n == 0){
			Cursor(false);
			drawText(x -5, y,"KHONG CO CHUYEN BAY DE THONG KE !", RED);
			drawText(x -5, y+1,"------- Bam ESC de thoat -------",RED);
			getch();
			return;
		}else{
			cb = chonCBdeLietke(x,y+2,x,y,tmp,BLUE, false);
			if(cb.maCB == ""){
				clearRect(10,37-6/2,168,6);		
				return;
			}
		}
			// ----------------- PHAN THONG KE ------------------------------
	clearRect(10,37-6/2,168,6);		
		int x_tt= 70, y_tt = 2; 
		// XOA HET TRUOC KHI VE MOI 
			clearRect(3,y_tt,175,30);
		// VE TIEU DE 
		drawText(x_tt,y_tt,"DANH SACH VE TRONG THUOC CHUYEN BAY",YELLOW);
		TieudelietkeVe(50,8);
		nutDieukhien( 10 ,37, 6 , 80, false, true, false);
		drawButton(130,37,CYAN,4,27,"1","HIEN THI THEO DS");
		drawButton(154,37,CYAN,4,27,"2","HIEN THI THEO O");
		// NOI DUNG LIET KE 
		DsVetrongcuaCB( 50, 10 , cb);	
			clearRect(3,y_tt,175,30);
			gotoxy(0,0);
			clearRect(10,37-6/2,168,6);	
			gotoxy(0,0);
		goto back;
}


