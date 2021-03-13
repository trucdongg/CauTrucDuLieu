// include thu vien 1 lan duy nhat ( ko lap lai )
#pragma once 
#include "Ngaygio.h"
#include "Ve.h"

typedef struct ChuyenBay{
	string maCB;
	NG ngaygiokh;     // ngay gio khoi hanh  Filter 
	string sbden; 	  // san bay den  // Filter
	int tt;           // trang thai chuyen bay         
	string shMB;      // so hieu May Bay C15
	DsVe dsve ;       // Danh sach Ve voi n =  MB.sodong * MB.soday
	int tgbay;		  // thoi gian bay ( them )
}CB;
CB cbrong = {"",Baygio(),"",0,""};
typedef struct nodeCB{
	ChuyenBay cb;
	struct nodeCB *next;
};

typedef struct nodeCB* PTCB;

// ---------   DANH SACH LIEN KET DON  ----------------------------------------------------
class DSCB{
	private: 
		int n = 0;
		PTCB First, Last;
		const char* FILE_NAME = "./DoanCTDL/DanhsachChuyenBay.dat";
	public:
		DSCB(){
			First = Last = NULL;
			tai();
		}
		// Them 1 chuyen bay moi // 2 lua chon 1 them ve dau va 1 them ve cuoi 
		void them(ChuyenBay newCB, bool veCuoi = true);
		// Them 1 chuyen bay moi co so sanh dk MaCB
		bool themtheothutu(ChuyenBay newCB);
		// Tim 1 chuyen bay bat ki theo tat ca cac lua chon trong giao dien
		PTCB tim( string maCB  );
		// Tim nhieu <Loc> cac ChuyenBay theo sohieu, trang thai , san bay den 
		
		// Sua 1 chuyen bay bat ki => True or False
		bool sua( ChuyenBay editCB , string maCB );
		// Xoa 1 chuyen bay bat ki ( neu tren do chua co ve dat ) => True or False 
		bool xoa( string maCB );
		// Luu vao file 
		void luu( bool isAppend = true);
		// Tai tu file 
		void tai();
		// ToString 
		string toString();
		// Get n 
		int getN(){ return n;}
		// Get CB dua vao Index
		CB getCB(int atIndex);
		CB getCB(string shMB);
		// Giao dien 

};

CB DSCB::getCB(int atIndex){
	PTCB p;int i;
	if(atIndex >= 0 && atIndex < n){
		for(i =0 ,p = First; p != NULL && i<atIndex ; i++ , p = p->next);
//		for(i = 0 ;i < atIndex ; i++ ) p = p -> next;
			return p->cb;
		}
	return cbrong;
}

CB DSCB::getCB(string shMB){
	PTCB p;
	if(shMB != ""){
		for(p = First; p != NULL && p->cb.maCB != shMB; p = p->next);
//		for(i = 0 ;i < atIndex ; i++ ) p = p -> next;
		if( p != NULL)
			return p->cb;
		}
	return cbrong;
}

void DSCB::them(ChuyenBay newCB, bool veCuoi){
	// Them ve Dau hoac ve Cuoi
	nodeCB *temp = new nodeCB();
	temp->cb = newCB;
	if(First == NULL){
		temp->next = First; // temp -> next = NULL
		First = Last = temp;
		n++;
		return;
	}
	// Them ve Cuoi 
	if(veCuoi)
		{
		temp->next = Last->next; // NULL
		Last->next = temp;
		Last = temp;
		n++;
		return;
		}
	// Them ve Dau 
	else {
		temp->next = First; // First dai dien thang dau tien
		First = temp;
		n++;
		return;
	}	
	
	
}

bool DSCB::themtheothutu(ChuyenBay newCB){
	// Them theo thu tu so sanh maCB cua ChuyenBay 
	PTCB p = tim(newCB.maCB) ;
	if(n == 0){
		them(newCB);
	}else
	if(p == NULL){
		PTCB pnew = new nodeCB();
		pnew -> cb = newCB;
		if(First->cb.maCB > newCB.maCB){
			pnew->next = First; // temp -> next = NULL
			First = pnew;
			n++;
			return true;
		}
	for( p = First; p->next != NULL && p->next->cb.maCB <= newCB.maCB ; p= p->next);
		if(p->next == NULL){
			pnew->next = Last->next; // NULL
			Last->next = pnew;
			Last = pnew;
		}else{
			pnew -> next = p -> next ;
			p ->next = pnew;
		}
		n++;
	return true;
	}
	return false;
}

PTCB DSCB::tim(string maCB ){
	// Tim 1 ChuyenBay theo findCB or theo atIndex 
	PTCB p ;
	if( n == 0) return NULL;
	
	// Tim theo maCB (duy nhat) 
	if(maCB != "") 
	for( p = First; p != NULL; p = p->next )
		if( p->cb.maCB == maCB ) return p;
	// Tim theo atIndex -> Phuc vu cho cac ham THEM , XOA 
	
	return NULL;
	
}

bool DSCB::sua(ChuyenBay editCB, string maCB){
	// Sua 1 ChuyenBay tai i = atIndex 
	if(maCB != "")
	{
		PTCB p = tim(maCB);
		if( p != NULL ){
			p->cb = editCB;
			return true;
		}
	}
	return false;
}

bool DSCB::xoa( string maCB ){
	if( maCB != "")
		if(First != NULL){
			// DS co 1 nut
			// XOA DAU
			PTCB p = First->next, q; 
			if (p == First ){ 
				First = NULL;
				delete p; n = (--n <= 0)? 0 : n;
				return true;
			}
			if( First->cb.maCB == maCB){
				p = First;
				First = p->next; // NULL OR NEXT POINTER 
				delete p; n = (--n <= 0)? 0 : n;
				return true;
			}
			// XOA KHI TIM
			for( p = First ; p->next != NULL && p->next->cb.maCB != maCB; p= p->next );
			if(p->next != NULL){
				q = p->next;
				p->next = q->next; // Thang nay bang Thang kia cach nhau 1 don vi
				delete q; n = (--n <= 0)? 0 : n;
				return true;
			}
		}
	return false;
}

string DSCB::toString(){
	string format = "0\n";
	if(n != 0){
		format = "";
		format += itos(n)+"\n";
		PTCB p = First;
		for( p = First; p != NULL; p = p -> next){
			format += p->cb.maCB + "/" + NGtoString(p->cb.ngaygiokh) + "/" + p->cb.sbden + "/" + p->cb.shMB + "/" + itos0(p->cb.tgbay) + " " + itos0(p->cb.tt) + " " + itos0(p->cb.dsve.getSLDB()) +"\n";
			if(!p->cb.dsve.isEmpty())
			format += p->cb.dsve.toString() + "\n";
		}
	}
	// Khong bao gom danh sach ve 
	return format;
}

void DSCB::luu ( bool isAppend ){ 
writeFile( FILE_NAME, toString() , isAppend ); 
}

void DSCB::tai(){
	fstream file;
 	file.open(FILE_NAME,ios::in);
 	
 		if(!file){
		file.close();
		// Create new file 
		cout<<"File "<<FILE_NAME<<" dang duoc tao .. Xong (File khong co du lieu luc nay) !!"<<endl;
		file.open(FILE_NAME,ios::out);
		file.close();
    	// Done 
		return;
		file.open(FILE_NAME,ios::in);
		
	}
	
	int n = 0, sldb = 0, soday, sodong, day, dong;
	string CMND;
	Ve vemoi;
	file>>n;
	if(n != 0){
	fflush(stdin);
		for(int k=0;k<n;k++){
		CB newCB;
		fflush(stdin);
		string temp;
		getline(file,temp,'\n');
		getline(file,newCB.maCB,'/');
		// Tach tmp -> struct Ngay gio
		getline(file,temp,'/');
		newCB.ngaygiokh = tachNG(temp);
		getline(file,newCB.sbden,'/');
		getline(file,newCB.shMB,'/');
		dsmb->getsoDayvasoDong(newCB.shMB,soday,sodong);
		sldb = 0;
		fflush(stdin); file >> newCB.tgbay >> newCB.tt >> sldb;
		if( timTGbay(newCB.sbden) != -1 
		&& sosanhNG( tinhTGden(newCB.ngaygiokh,newCB.sbden) , Baygio()) <= 0 )
			newCB.tt = 3;	
		newCB.dsve = DsVe(soday*sodong);
		newCB.dsve.setSLDB(sldb);
		if(sldb != 0){
			if( sldb == soday*sodong ) newCB.tt = (newCB.tt == 3 ) ? 3 : 2; // HET VE
			for(int i=0;i< sldb; i++){
					fflush(stdin);
					file>>day>>dong>>CMND;			
					fflush(stdin);
					getline(file,temp,'/');
					vemoi = {CMND, laytenChongoi(day,dong)};		
					newCB.dsve.setVe(day*sodong + dong,vemoi);
				}
			
		}
		them(newCB);
		
		}
	}
	file.close();
}

class mangCB{
	private:
		int n = 0;
		CB ds[ MAX_CB ];
		DSCB dscb = DSCB();
	public:
		mangCB(){
			tai();
		}
		int laydodai(){ return n;}
		// Liet ke 
		void dsCBvoisoVe( int *&indexs, int &n, NG ng, string sbd );
		void lietkeCBtheo(int start_x, int start_y, int *indexs, int n);
		void lietkeCBtheo(int start_x, int start_y, int *indexs, int n, int from, int to);
		void lietkeCB(int start_x, int start_y, int from= 0, int to=0);
		// Them ( 1 Hanh khach moi ) vao Cay T va mang Ho tro
		void them( CB newCB );
		// Xoa 
		bool xoa ( string maCB );
		// Sua 
		bool sua ( CB editCB );
		// Tim 
		int tim ( string maCB );
		int timSoluong ( string sohieu ){
			int dem = 0;
			for(int i = 0; i < n; i++)
				if( ds[i].shMB == sohieu && (ds[i].tt == 1 || ds[i].tt == 2) ) dem++;	
			return dem;
		}
		// Tim 
		bool mangSohieu( string sohieu, CB *&mang, int &n);		
		void laymaCB(string *&kq);
		NG getRighttime( string sohieu, int vitri = -1);
		NG getLefttime( string sohieu, int vitri = -1);
		int getN(){ return n; }
		CB getCB( int atIndex );
		CB getCB( string maCB);
		// Tai tu file len
		void tai();
		void luu();
};
void mangCB::lietkeCBtheo(int start_x, int start_y, int *indexs, int n, int from, int to){
	if(n == 0){
		clearRect(start_x,start_y+4,85,1);
		drawText(start_x+30,start_y+4,"Khong co chuyen bay nao CON VE ",RED);
	}else if( n > 0){
		clearRect(start_x+1,start_y+4,20,1);
		int mx = 4,
			x_stt =  10,
			x_mcb =  30, 
			x_sh  =  48, // width Sh   
			x_tg  =  70, // width TG   
			x_sbd =  100, // width SBD  
			width = 120;
	
	for(int i = from; i < to; i++)
		{
		CB dsi = ds[indexs[i]];
		// Canh le
		int	border_line =(i +1 - from)*2;
		int line_height = border_line + 1;
		
		// Khung chua ben ngoai
		drawRect(start_x,start_y+border_line,width,2);
		gotoxy(start_x,start_y+border_line); printf("%c",195);
		
		// Khung stt 
		draw_high_line(start_x+x_stt,start_y+border_line,2);
		drawText(start_x+ mx,start_y+line_height,itos(i+1),YELLOW);
		gotoxy(start_x + x_stt,start_y+border_line); printf("%c",195);
		
		
		// Khung ma chuyen bay
		draw_high_line(start_x+x_mcb,start_y+border_line,2);
		string str = (dsi.maCB.size() > C15 -3 ) ? dsi.maCB.substr(0,12) + ".." : dsi.maCB;  
		
		
		// Da qua gio khoi hanh 
		if( dsi.tt == 1 || dsi.tt == 2 )
		if( sosanhNG( dsi.ngaygiokh, Baygio() ) < 0 ){
			if(sosanhNG( congPhut(dsi.ngaygiokh, dsi.tgbay) , Baygio() ) <= 0){
				dsi.tt = (dsi.tt == 0)? 0 : 3;	
				sua(dsi);
			}
		}
		
		if(dsi.tt == 3) drawText(start_x+x_stt+mx,start_y+line_height,str,GREEN);
		if(dsi.tt == 2) drawText(start_x+x_stt+mx,start_y+line_height,str,CYAN);
		if(dsi.tt == 1) drawText(start_x+x_stt+mx,start_y+line_height,str,YELLOW);
		if(dsi.tt == 0) drawText(start_x+x_stt+mx,start_y+line_height,str,RED);
		gotoxy(start_x+x_mcb,start_y+border_line); printf("%c",195);
		
		// Khung so hieu 
		draw_high_line(start_x+x_sh,start_y+border_line,2);
		drawText(start_x+x_mcb+mx,start_y+line_height,dsi.shMB,RED);
		gotoxy(start_x+x_sh,start_y+border_line); printf("%c",197);
		
		// Khung thoi gian xuat phat 
		draw_high_line(start_x+x_tg,start_y+border_line,2);
		drawText(start_x+x_sh+mx,start_y+line_height,NGtoString(dsi.ngaygiokh),WHITE);
		gotoxy(start_x+x_tg,start_y+border_line); printf("%c",197);
		
		// Khung san bay den 
		draw_high_line(start_x+x_sbd,start_y+border_line,2);
		drawText(start_x+x_tg+mx,start_y+line_height,dsi.sbden,WHITE);
		gotoxy(start_x+x_sbd,start_y+border_line); printf("%c",197);
		// Doan thang ket thuc dong 
		drawText(start_x+x_sbd+mx,start_y+line_height,itos0(dsi.dsve.getSLtrong()),WHITE);
		gotoxy(start_x+width,start_y+border_line); printf("%c",180);	
		}
	}
}

void mangCB::dsCBvoisoVe( int *&indexs, int &n, NG ng, string sbd ){
	int dem = 0;
	n = getN();
		if( sbd == "" && NGrong(ng)  ){
			// Tim so luong 
			for (int i = 0; i < n; i++)
				if( ds[i].tt == 1) dem++;
			// Neu dem = 0 thoat 
			if(dem == 0) {
				n = dem;
				return ;
			}
			// Lay cac vi tri 
			indexs = new int[dem];
			dem = 0;
			for (int i = 0; i < n; i++)
				if( ds[i].tt == 1 ) indexs[dem++] = i;
			n = dem;
			return ;
		}
		if( sbd != "" && NGrong(ng) ){
			// Tim so luong 
			for (int i = 0; i < n; i++)
				if( sbd == ds[i].sbden && ds[i].tt == 1) dem++;
			// Neu dem = 0 thoat 
			if(dem == 0) {
				n = dem;
				return ;
			}
			// Lay cac vi tri 
			indexs = new int[dem];
			dem = 0;
			for (int i = 0; i < n; i++)
				if( sbd == ds[i].sbden && ds[i].tt == 1 ) indexs[dem++] = i;
			n = dem;
			return ;
		}
		if( !NGrong(ng) && sbd == ""){
			// Tim so luong 
			for (int i = 0; i < n; i++)
				if( sosanhNG3( ng, ds[i].ngaygiokh) == 0 && ds[i].tt == 1 ) dem++;
			// Neu dem = 0 thoat  
			if(dem == 0) {
				n = dem;
				return ;
			}
			// Lay cac vi tri;
			indexs = new int[dem];
			dem = 0;
			for (int i = 0; i < n; i++)
			if( sosanhNG3( ng, ds[i].ngaygiokh) == 0 && ds[i].tt == 1 ) indexs[dem++] = i;
			n = dem;
			return ;
		}
		if( !NGrong(ng) && sbd != ""){
			for (int i = 0; i < n; i++)
			if( sosanhNG3( ng, ds[i].ngaygiokh) == 0 && ds[i].sbden == sbd && ds[i].tt == 1 ) dem++;
			if(dem == 0) {
				n = dem;
				return ;
			}
			indexs = new int[dem];
			dem = 0;
			for (int i = 0; i < n; i++)
			if( sosanhNG3( ng, ds[i].ngaygiokh) == 0 && ds[i].sbden == sbd && ds[i].tt == 1 ) indexs[dem++] = i;
			n = dem;
			return ;
		}
		
}

CB mangCB::getCB(string maCB){
	if(maCB == "") return cbrong;
	if(ds[0].maCB == maCB){
		return ds[0];
	}
	if(ds[n-1].maCB == maCB){
		return ds[n-1];
	}
	for(int i =0; i<n ; i++ )
	{
		if(ds[i].maCB == maCB )	return ds[i];
	}
}

void mangCB::laymaCB( string *&kq ){
	kq = new string[n];
	for(int i =0; i<n; i++){
		CB dsi = ds[i];
		char tt = (dsi.tt == 3 )? '3': (dsi.tt == 2)? '2' : (dsi.tt == 1)? '1': '0';
		kq[i]+= dsi.maCB + tt;
	}
	return ;
	
}

void mangCB::lietkeCBtheo(int start_x, int start_y, int *indexs, int n){
	if(n == 0){
		clearRect(start_x,start_y+3,85,1);
		drawText(start_x+10,start_y+3,"Khong co gia tri nao trong Danh sach May bay",YELLOW);
	}else if( n > 0){
		clearRect(start_x+1,start_y+4,20,1);
	for(int i = 0; i < n; i++)
		{
		CB dsi = ds[indexs[i]];
		// Canh le
		int	border_line = (i+1)*2;
		int line_height = border_line + 1;
		
		// Khung chua ben ngoai
		drawRect(start_x,start_y+border_line,85,2);
		gotoxy(start_x,start_y+border_line); printf("%c",195);
		
		// Khung ma chuyen bay
		draw_high_line(start_x+18,start_y+border_line,2);
		string str = (dsi.maCB.size() > C15 -3 ) ? dsi.maCB.substr(0,12) + ".." : dsi.maCB; 
		
		
		// Da qua gio khoi hanh 
		if( dsi.tt == 1 || dsi.tt == 2 )
		if( sosanhNG( dsi.ngaygiokh, Baygio() ) < 0 ){
			if(sosanhNG( congPhut(dsi.ngaygiokh, dsi.tgbay) , Baygio() ) <= 0){
				dsi.tt = (dsi.tt == 0)? 0 : 3;	
				sua(dsi);
			}
		}
		
		if(dsi.tt == 3) drawText(start_x+4,start_y+line_height,str,GREEN);
		if(dsi.tt == 2) drawText(start_x+4,start_y+line_height,str,CYAN);
		if(dsi.tt == 1) drawText(start_x+4,start_y+line_height,str,YELLOW);
		if(dsi.tt == 0) drawText(start_x+4,start_y+line_height,str,RED);
		gotoxy(start_x+18,start_y+border_line); printf("%c",195);
		
		// Khung so hieu 
		draw_high_line(start_x+35,start_y+border_line,2);
		drawText(start_x+23,start_y+line_height,dsi.shMB,RED);
		gotoxy(start_x+35,start_y+border_line); printf("%c",197);
		
		// Khung thoi gian xuat phat 
		draw_high_line(start_x+60,start_y+border_line,2);
		drawText(start_x+40,start_y+line_height,NGtoString(dsi.ngaygiokh),WHITE);
		gotoxy(start_x+60,start_y+border_line); printf("%c",197);
		
		// Khung san bay den 
		drawText(start_x+65,start_y+line_height,dsi.sbden,WHITE);

		// Doan thang ket thuc dong 
		gotoxy(start_x+85,start_y+border_line); printf("%c",180);	
		}
	}
}

bool mangCB::mangSohieu( string sohieu , CB *&mang , int &sl){
	sl = timSoluong(sohieu);
	if( sl == 0) return false;
	mang = new CB[sl];
	int dem = 0;
	for(int i =0 ; i< n; i++){
		if( ds[i].shMB == sohieu && (ds[i].tt == 1 || ds[i].tt == 2 ))
		{
			mang[dem] = ds[i];
			dem++;
		}
	}
	int i, j;
	CB key ;
    for (i = 1; i < sl; i++) 
    {  
        key = mang[i];  
        j = i - 1;  
        while (j >= 0 && sosanhNG(mang[j].ngaygiokh,key.ngaygiokh) > 0) 
        {  
            mang[j + 1] = mang[j];  
            j = j - 1;  
        }  
        mang[j + 1] = key;  
    }  
	
	return true;
}

NG mangCB::getRighttime( string sohieu, int vitri ){
	NG max = Baygio(), time ;
	if(vitri != -1) 
		max = ds[vitri].ngaygiokh ;
	for(int i = 0 ; i < n ; i++ ){
		if(vitri != -1){
			// Tim tat ca ngoai tru vi tri 
			if( ds[i].shMB == sohieu && ds[i].tt != 0 && i != vitri){
				time = ds[i].ngaygiokh ;
				if( sosanhNG(max,time) <= 0 ) max = time;
				return max;
				}
		}else {
			// Tim tat ca neu vitri == -1
			if( ds[i].shMB == sohieu && ds[i].tt != 0 ){
			time = ds[i].ngaygiokh ;
			if( sosanhNG(max,time) <= 0 ) max = time;
			return max;
			}
		}
	}
	return Baygio();
}

NG mangCB::getLefttime( string sohieu, int vitri ){
	// LAY BAY GIO LA THUOC DO, BASE LA BAY GIO,   
	// LA BAY GIO HOAC MAY BAY TRUOC NO KET THUC
	NG min = getRighttime(sohieu, vitri), time = min , base = Baygio();
	for(int i = 0 ; i < n ; i++ ){
		if(vitri != -1){
			// Tim tat ca ngoai tru vi tri 
			if( ds[i].shMB == sohieu && ds[i].tt != 0 && i != vitri){
				time =  ds[i].ngaygiokh ;
				if( sosanhNG(time,base) >= 0 && sosanhNG(time,min) <= 0 ) min = time;
				return min;
				}
		}else {
			// Tim tat ca neu vitri == -1
			if( ds[i].shMB == sohieu && ds[i].tt != 0 ){
			time =  ds[i].ngaygiokh ;
			if( sosanhNG(time,base) >= 0 && sosanhNG(time,min) <= 0 ) min = time;
			return min;
			}
		}
	}
	return base;
}

CB mangCB::getCB( int atIndex ){
	if(atIndex >= 0 && atIndex < n){
		return ds[atIndex];
	}
	return cbrong;
}

void mangCB::tai(){
	for(int i=0; i< dscb.getN(); i++){
		CB cb = dscb.getCB(i);
		ds[n++] = cb; 
	}
}

void mangCB::luu(){
	dscb.luu(false);
}

void mangCB::them( CB newCB ){
	if(newCB.maCB == "")
		return;
	else{
		dscb.themtheothutu(newCB);
		ds[n++] = newCB;
	}
	
}

bool mangCB::sua( CB editCB ){
	if(editCB.maCB == "")
		return false;
	else{
		int vitri = tim(editCB.maCB);
		if(tim(editCB.maCB) == -1)
			return false;
		ds[vitri] = editCB;
		dscb.sua(editCB, editCB.maCB);
	}
	return true;
}

bool mangCB::xoa( string maCB ){
	if(maCB == "")
		return false;
	else{
		int vitri = tim(maCB);
		if(vitri == -1){
			return false;
		}
		if(vitri == n-1){
			n--;
			dscb.xoa(maCB);
			return true;
		}
	for(int i = vitri; i< n-1; i++)
		ds[i] = ds[i+1];
		n--;
		dscb.xoa(maCB);
	}
	return true;
}

int mangCB::tim( string maCB ){
	if( n == 0 ) return -1;
	if(ds[0].maCB == maCB){
		return 0;
	}
	if(ds[n-1].maCB == maCB){
		return n-1;
	}
	for(int i =0; i<n ; i++ )
	{
		if(ds[i].maCB == maCB )	return i;
	}
	return -1;
}

void mangCB::lietkeCB(int start_x, int start_y, int from, int to){
	if(n == 0){
		clearRect(start_x,start_y+3,85,1);
		drawText(start_x+10,start_y+3,"Khong co gia tri nao trong Danh sach May bay",YELLOW);
	}else if( n > 0){
		clearRect(start_x+1,start_y+4,20,1);
	for(int i = to-1; i>= from; i--)
		{
		CB dsi = ds[i];
		// Canh le
		int	border_line = (to-1 - i+1)*2;
		int line_height = border_line + 1;
		
		// Khung chua ben ngoai
		drawRect(start_x,start_y+border_line,85,2);
		gotoxy(start_x,start_y+border_line); printf("%c",195);
		
		// Khung ma chuyen bay
		draw_high_line(start_x+18,start_y+border_line,2);
		string str = (dsi.maCB.size() > C15 -3 ) ? dsi.maCB.substr(0,12) + ".." : dsi.maCB; 
		
		
		// Da qua gio khoi hanh 
		if( dsi.tt == 1 || dsi.tt == 2 )
		if( sosanhNG( dsi.ngaygiokh, Baygio() ) < 0 ){
			if(sosanhNG( congPhut(dsi.ngaygiokh, dsi.tgbay) , Baygio() ) <= 0){
				dsi.tt = (dsi.tt == 0)? 0 : 3;	
				sua(dsi);
			}
		}
		
		if(dsi.tt == 3) drawText(start_x+4,start_y+line_height,str,GREEN);
		if(dsi.tt == 2) drawText(start_x+4,start_y+line_height,str,CYAN);
		if(dsi.tt == 1) drawText(start_x+4,start_y+line_height,str,YELLOW);
		if(dsi.tt == 0) drawText(start_x+4,start_y+line_height,str,RED);
		gotoxy(start_x+18,start_y+border_line); printf("%c",195);
		
		// Khung so hieu 
		draw_high_line(start_x+35,start_y+border_line,2);
		drawText(start_x+23,start_y+line_height,dsi.shMB,RED);
		gotoxy(start_x+35,start_y+border_line); printf("%c",197);
		
		// Khung thoi gian xuat phat 
		draw_high_line(start_x+60,start_y+border_line,2);
		drawText(start_x+40,start_y+line_height,NGtoString(dsi.ngaygiokh),WHITE);
		gotoxy(start_x+60,start_y+border_line); printf("%c",197);
		
		// Khung san bay den 
		drawText(start_x+65,start_y+line_height,dsi.sbden,WHITE);

		// Doan thang ket thuc dong 
		gotoxy(start_x+85,start_y+border_line); printf("%c",180);	
		}
	}
}
//	if(ds.getN() != 0){
//		menuCB();
//		themChuyenBay();
//		ds.lietkeCB(4,5);
//		getch();
//	}
	

