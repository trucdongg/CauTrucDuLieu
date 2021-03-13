// include thu vien 1 lan duy nhat ( ko lap lai )
#pragma once 

typedef struct MayBay {
	string sohieu; //C15
	string loai;   //C40
	int soday;    // I09
	int sodong;   // I99
	int tt; 
	int sudung;  // MB duoc su dung bao nhieu lan ? 
	int hoanthanh;
} MB ;
MB mbrong = {"","",0,0,0};
// ---------  MANG CON TRO ---------------------------------------- 
class DSMB {
	private :
		int n = 0;
		MB * ds[MAX_MAYBAY];
		const char * FILE_NAME = "./DoanCTDL/DanhsachMayBay.dat";
	
	public :
		DSMB(){
			n = 0;
			tai();
		}
		// Liet ke cac sohieuMB, kem theo tt
		void laysohieu(string* &kq);
		void layMBcoCB_dec( int *&indexs, int &n );
		// Lay n 
		int laydodai();
		// Them 1 chiec may bay moi
		void them( MayBay newMB );
		// Sua 1 may bay => if ( ko tim duoc index ) => return false;
		bool sua( MayBay changedMB, int atIndex );
		// Xoa 1 may bay => if ( chuyen do chua co ve dat ) return true; 
		bool xoa ( int atIndex );
		// Tim vi tri cua may bay theo So hieu
		int tim ( string sohieu );
		// GET 
		MB*	getMB( int atIndex);
		MB* getMB( string sohieu);
		void getsoDayvasoDong( string sohieu , int &soday, int &sodong);
		// Format thanh string truoc khi bo vao file 
		string toString ( );
		// Luu vao file
		void luu ( bool isAppend = true );
		// Tai tu file
		void tai ( );
		// Giao dien 
		void lietkeMB( int start_x,int start_y, int from, int to );
		void lietkeMBnguoc( int start_x,int start_y, int from, int to );
		void lietkeMBtheo(int start_x, int start_y, int * indexs, int n);
		void lietkeMBtheo(int start_x, int start_y, int * indexs, int n, int from, int to);
	
};
void DSMB::layMBcoCB_dec( int *&indexs, int &n){
	n = laydodai();
	indexs = new int[n];
	// Khoi tao 
	for( int i =0; i< n; i++){
		indexs[i] = i;
	}
	
	// So sanh va doi cho 
	int i, key, j;  
    for (i = 1; i < n; i++) 
    {  	
        key = indexs[i];  
        j = i - 1;  
        
        while (j >= 0 && ds[indexs[j]]->hoanthanh < ds[key]->hoanthanh) 
        {  
            indexs[j + 1] = indexs[j];  
            j = j - 1;  
        }  
        indexs[j + 1] = key;  
    }  

}

void DSMB::lietkeMBtheo(int start_x, int start_y, int * indexs, int n, int from, int to){
	if(n == 0){
		cout<<endl<<"Khong co gia tri nao trong Danh sach May bay"<<endl;
	}else if( n > 0)
	{
		int mx = 4,
		width = 130,
		x_sh =  10 ,
		x_l =   30 ,
		x_sda = 80 ,
		x_sdo = 95 ,
		x_sdu = 110 ,
		height = 2;
	for(int i = from; i< to; i++)
		{
		MB *dsi = ds[indexs[i]];
		// Canh le
		int	border_line = 2*(i - from +1);
		int line_height = border_line +1;
		
		
		// Khung chua ben ngoai 
		drawRect(start_x,start_y+border_line,width,height);
		gotoxy(start_x,start_y+border_line); printf("%c",195);
		
		
		draw_high_line(start_x+x_sh,start_y+border_line,2);
		drawText(start_x+mx,start_y+line_height,itos(i + 1),YELLOW);
		gotoxy(start_x +x_sh,start_y+border_line); printf("%c",195);
		
		
		// Khung so hieu
		draw_high_line(start_x+x_l,start_y+border_line,2);
		if(dsi->tt == 0)
		drawText(start_x+x_sh+mx,start_y+line_height,dsi->sohieu,GREEN);	
		else if(dsi->tt == 1)
		drawText(start_x+x_sh+mx,start_y+line_height,dsi->sohieu,RED);	
		gotoxy(start_x + x_l,start_y+border_line); printf("%c",195);
		
		// Khung loai
		draw_high_line(start_x+x_sda,start_y+border_line,2);
		string str=  (dsi->loai.length() > 30 ) ? dsi->loai.substr(0,30)+"..." : dsi->loai; 
		drawText(start_x+x_l+mx,start_y+line_height,str,WHITE);
		gotoxy(start_x+x_sda,start_y+border_line); printf("%c",197);
		
		// Khung so day
		draw_high_line(start_x+x_sdo,start_y+border_line,2);
		drawNumber(start_x+x_sda+mx,start_y+line_height,dsi->soday,CYAN);
		gotoxy(start_x+x_sdo,start_y+border_line); printf("%c",197);
		
		// Khung so dong
		draw_high_line(start_x+x_sdu,start_y+border_line,2);
		drawNumber(start_x+x_sdo+mx,start_y+line_height,dsi->sodong,CYAN);	
		gotoxy(start_x+x_sdu,start_y+border_line); printf("%c",197);
		
		// Khung su dung 
		drawNumber(start_x+x_sdu+mx,start_y+line_height,dsi->hoanthanh,GREEN);	
		
		// Khung ngoai
		gotoxy(start_x+width,start_y+border_line); printf("%c",180);
		
		}
	}
}

void DSMB::lietkeMBtheo(int start_x, int start_y, int * indexs, int n){
	if(n == 0){
		cout<<endl<<"Khong co gia tri nao trong Danh sach May bay"<<endl;
	}else if( n > 0)
	{
	for(int i = 0; i< n; i++)
		{
		MB *dsi = ds[indexs[i]];
		// Canh le
		int	border_line = 2*(i+1);
		int line_height = border_line +1;
		
		
		// Khung chua ben ngoai 
		drawRect(start_x,start_y+border_line,100,2);	
		
		// Khung so hieu
		if(dsi->tt == 0)
		drawText(start_x+5,start_y+line_height,dsi->sohieu,GREEN);	
		else if(dsi->tt == 1)
		drawText(start_x+5,start_y+line_height,dsi->sohieu,RED);	
		gotoxy(start_x,start_y+border_line); printf("%c",195);
		
		// Khung loai
		draw_high_line(start_x+20,start_y+border_line,2);
		string str=  (dsi->loai.length() > 20 ) ? dsi->loai.substr(0,20)+"..." : dsi->loai; 
		drawText(start_x+28,start_y+line_height,str,WHITE);
		gotoxy(start_x+20,start_y+border_line); printf("%c",197);
		
		// Khung so day
		draw_high_line(start_x+54,start_y+border_line,2);
		drawNumber(start_x+56,start_y+line_height,dsi->soday,WHITE);
		gotoxy(start_x+54,start_y+border_line); printf("%c",197);
		
		// Khung so dong
		draw_high_line(start_x+77,start_y+border_line,2);
		drawNumber(start_x+80,start_y+line_height,dsi->sodong,WHITE);	
		gotoxy(start_x+77,start_y+border_line); printf("%c",197);
		
		// Khung ngoai
		gotoxy(start_x+100,start_y+border_line); printf("%c",180);
		
		}
	}
}

void DSMB::getsoDayvasoDong(string sohieu, int &soday, int &sodong){
	MB* mb = getMB(sohieu);
	if( mb == NULL ){
		soday = sodong = 0;
		return;
	}
	soday = mb->soday;
	sodong = mb->sodong;
}

MB* DSMB::getMB(string sohieu){
	if(sohieu != "")
	{
		int vitri = tim(sohieu);
		if(vitri != -1)
			return ds[vitri];
	}
	return NULL;
}

void DSMB::laysohieu(string* &kq){
	kq = new string[n];
	for(int i =0; i<n; i++){
		MB *dsi = ds[i];
		char tt = (dsi->tt == 0 )? '0': '1';
		kq[i]+= dsi->sohieu + tt;
//		cout<<kq[i]<<endl;
	}
	return ;
}

MB* DSMB::getMB(int atIndex){
	if(atIndex < 0 || atIndex > n)
	return NULL;
	return ds[atIndex];
}

int DSMB::laydodai(){
	return n;
}

void DSMB::lietkeMB( int start_x,int start_y,int from = 0, int to = 0){
	if(n == 0){
		cout<<endl<<"Khong co gia tri nao trong Danh sach May bay"<<endl;
	}else if( n > 0)
	{
	for(int i = from; i< to; i++)
		{
		MB *dsi = ds[i];
		// Canh le
		int	border_line = 2*(i-from+1);
		int line_height = border_line +1;
		
		
		// Khung chua ben ngoai 
		drawRect(start_x,start_y+border_line,100,2);	
		
		// Khung so hieu
		if(dsi->tt == 0)
		drawText(start_x+5,start_y+line_height,dsi->sohieu,GREEN);	
		else if(dsi->tt == 1)
		drawText(start_x+5,start_y+line_height,dsi->sohieu,RED);	
		gotoxy(start_x,start_y+border_line); printf("%c",195);
		
		// Khung loai
		draw_high_line(start_x+20,start_y+border_line,2);
		string str=  (dsi->loai.length() > 20 ) ? dsi->loai.substr(0,20)+"..." : dsi->loai; 
		drawText(start_x+28,start_y+line_height,str,WHITE);
		gotoxy(start_x+20,start_y+border_line); printf("%c",197);
		
		// Khung so day
		draw_high_line(start_x+54,start_y+border_line,2);
		drawNumber(start_x+56,start_y+line_height,dsi->soday,WHITE);
		gotoxy(start_x+54,start_y+border_line); printf("%c",197);
		
		// Khung so dong
		draw_high_line(start_x+77,start_y+border_line,2);
		drawNumber(start_x+80,start_y+line_height,dsi->sodong,WHITE);	
		gotoxy(start_x+77,start_y+border_line); printf("%c",197);
		
		// Khung ngoai
		gotoxy(start_x+100,start_y+border_line); printf("%c",180);
		
		}
	}
}

void DSMB::lietkeMBnguoc( int start_x,int start_y,int from = 0, int to = 0){
	if(n == 0){
		drawText(start_x+10,start_y+4,"Khong co gia tri nao trong Danh sach May bay",YELLOW);
	}else if( n > 0){
		clearRect(start_x+1,start_y+4,20,1);
		for(int i = to-1; i >= from; i--)
		{
		MB *dsi = ds[i];
		// Canh le
		int	border_line = 2*(to-1-i+1);
		int line_height = border_line +1;
		
		
		// Khung chua ben ngoai 
		drawRect(start_x,start_y+border_line,100,2);	
		
		string str;
		// Khung so hieu
		str = (dsi->sohieu.length() > C15-5 ) ? dsi->sohieu.substr(0,10)+"..." : dsi->sohieu;
		if(dsi->tt == 0)
		drawText(start_x+5,start_y+line_height,str,GREEN);	
		else if(dsi->tt == 1)
		drawText(start_x+5,start_y+line_height,str,RED);	
		gotoxy(start_x,start_y+border_line); printf("%c",195);
		
		// Khung loai
		draw_high_line(start_x+20,start_y+border_line,2);
		str=  (dsi->loai.length() > 20 ) ? dsi->loai.substr(0,20)+"..." : dsi->loai; 
		drawText(start_x+28,start_y+line_height,str,WHITE);
		gotoxy(start_x+20,start_y+border_line); printf("%c",197);
		
		// Khung so day
		draw_high_line(start_x+54,start_y+border_line,2);
		drawNumber(start_x+56,start_y+line_height,dsi->soday,WHITE);
		gotoxy(start_x+54,start_y+border_line); printf("%c",197);
		
		// Khung so dong
		draw_high_line(start_x+77,start_y+border_line,2);
		drawNumber(start_x+80,start_y+line_height,dsi->sodong,WHITE);	
		gotoxy(start_x+77,start_y+border_line); printf("%c",197);
		
		// Khung ngoai
		gotoxy(start_x+100,start_y+border_line); printf("%c",180);
		
		}
	}
}

void DSMB::them ( MayBay newMB ){
	if(n == MAX_MAYBAY) return; 
	newMB.hoanthanh = 0;
	ds[n] = new MB();
 	*ds[n++] = newMB; 
}

bool DSMB::sua ( MayBay changedMB, int atIndex ) { 
	if(atIndex >=0 && atIndex <= n) 
		{
		*ds[atIndex] = changedMB;
		return true; 
		}
	return false;
}

int DSMB::tim( string sohieu){
	for( int i = 0; i< n; i++) 
		if (ds[i]->sohieu == sohieu) return i;
	return -1;
}

string DSMB::toString(){
	string format = "0\n";
	if( n != 0){
		format = "";
		format += itos(n)+"\n";
		for( int i =0; i<n; i++){
			MB dsi = *ds[i];
			format += dsi.sohieu+"/"+dsi.loai+"/"+itos(dsi.soday)+" "+itos(dsi.sodong)+" "+itos0(dsi.sudung)+" "+itos0(0)+" "+itos0(dsi.tt)+"\n";
		}
	}
	return format;
}

bool DSMB::xoa ( int atIndex ){ 
	if(atIndex >=0 && atIndex < n) 
		{
		if(atIndex == n-1)
			delete ds[--n];	
		else{
		for( int i = atIndex; i < n - 1; i++) *ds[i] = *ds[i+1];
			delete ds[--n];
		}
		return true; 
		}
	return false;
}

void DSMB::luu ( bool isAppend ){ 
writeFile( FILE_NAME, toString() , isAppend ); 
}

void DSMB::tai ( ) {
 	fstream file;
 	file.open(FILE_NAME,ios::in);
 	
 		if(!file){
		file.close();
		// Create new file 
		gotoxy(0,0);
		cout<<"File "<<FILE_NAME<<" dang duoc tao .. Xong (File khong co du lieu luc nay) !!"<<endl;
		file.open(FILE_NAME,ios::out);
		file.close();
		return;
    	// Done 
		file.open(FILE_NAME,ios::in);
	}
	file>>n;
	fflush(stdin);
	// Bien temp xoa dau xuong dong
	string temp;
	if( n != 0){
		for(int i=0;i<n;i++){
			MB newMB;
			fflush(stdin);
			getline(file,temp,'\n');
			getline(file,newMB.sohieu,'/');
			getline(file,newMB.loai,'/');
			file>>newMB.soday>>newMB.sodong>>newMB.sudung>>newMB.hoanthanh>>newMB.tt;
			//cout<<newMB.sohieu << " "<<newMB.loai << " "<<newMB.soday<<" "<<newMB.sodong<<endl; 
			ds[i] = new MB();
			*ds[i] = newMB;
		}
	} 
	
	file.close();
} 







