// include thu vien 1 lan duy nhat ( ko lap lai )
#include "_Hamhotro.h"
#define MAX_YEAR 3000
#pragma once 
typedef struct NgayGio{
	int ngay = 0;  // 1 -> 30 or 31 
	int thang= 0;  // 1 -> 12 
	int nam  = 0;  // I04 
	int gio  = 0;  // I02 
	int phut = 0;  // I02 
}NG;
string NGtoString ( NG inp , bool hr_min = true);

bool laNamNhuan(int year){
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	return false;
}

bool NGrong(NG ng){
	if(ng.ngay != 0 && ng.thang != 0 && ng.nam != 0)
		return false;
	return true;
}
int laysoNgaythuocThang(int thang, int nam){
	int songay;
	switch (thang){

		// Thang 31 ngay 
	case 1: case 3: case 5: case 7: case 8: case 10: case 12: songay = 31 ; break;

		// Thang 30 ngay 
	case 4: case 6: case 9: case 11: songay = 30 ; break;

		// Thang 28, 29 ngay 
	case 2:	songay = (laNamNhuan(nam))? 29 : 28 ; break;

		// Cac truong hop khac 
	default: return 0;
	}
	return songay;
}
bool NGhople( NG ng){
	// Kiem tra rong 
	if ( NGrong( ng ) ) {
		return false;
	}

	// Ngay - Thang - Nam
	int ngay = ng.ngay;
	int thang = ng.thang;
	int nam = ng.nam;
	
	// Gio - Phut 
	int gio = ng.gio;
	int phut = ng.phut;
	
	// 09 int-> 9 checked
	int songay = laysoNgaythuocThang(thang, nam);

	// Kiem tra ngay [ 0 , songay trong thang ] 
	if(ngay > 0 && ngay < songay)
		// Kiem tra gio [ 0 , 23 ] 
		if( gio > 0 && gio <= 23)
			// Kiem tra phut [ 0 , 59 ]
			if( phut > 0 && phut <= 59);
				return true;
	
	return false;
}
string NGtoString( NG inp , bool hr_min ){
	string out, 
	ngay = itos0(inp.ngay), 
	nam  = itos0(inp.nam),
	thang= itos0(inp.thang);
	string gio, phut; 
	if( hr_min ){
	 gio  = itos0(inp.gio) == ""? "00" : itos0(inp.gio) ; 
     phut = itos0(inp.phut) == ""? "00" : itos0(inp.phut);
	
	// 1 / 10 < 1  -> 01:00 
	gio = gio.size() == 1 ? '0'+gio : gio;	
	phut = phut.size() == 1 ? '0'+phut : phut;
	}
	
	// 12 - 1 -> 12 - 01 
	ngay = ngay.size() == 1 ? '0'+ngay : ngay;
	thang = thang.size() == 1 ? '0'+thang : thang;
	
	// 30-08-1999 10:00 
	if( hr_min )
	out = ngay+"-"+thang+"-"+nam+" "+gio+":"+phut;
	else
	out = ngay+"-"+thang+"-"+nam;
	
	return out; 
} 
// Khong cho nhap ngay vao thi cai nay co tac dung 
// Hoac dung dinh dang dung truoc khi in vao file 

void showNG(NG inp){
	cout<<NGtoString(inp)<<endl;
}
NG Chilayngay(){
	NG ng;
	time_t now = time(0);
	tm *ltm = localtime(&now);
	
	// Gan gia tri 
    ng.nam   = 1900 + ltm->tm_year;
    ng.thang = 1 + ltm->tm_mon    ;
   	ng.ngay  = ltm->tm_mday       ;

	return ng;
}
NG tachNG( string inp){
	NG newNG = NG(); 
	if(inp == "")
	return newNG;
	
	// 30 
	newNG.ngay  = stoi(inp.substr(0,2));
	// 08 
	newNG.thang = stoi(inp.substr(3,2));
	// 1999 
	newNG.nam   = stoi(inp.substr(6,4));
	// 00 
	newNG.gio   = stoi(inp.substr(11,2));
	// 00 
	newNG.phut  = stoi(inp.substr(14,2));
	
	return newNG;
}
NG Baygio(int gio = 0, int phut = 0){
	NG ng;
	time_t now = time(0);
	tm *ltm = localtime(&now);
	
	// Gan gia tri 
    ng.nam   = (1900 + ltm->tm_year);
    ng.thang = (1 + ltm->tm_mon)    ;
   	ng.ngay  = (ltm->tm_mday )      ;
    
    // Gio = 0 thi Lay gio he thong
    if(gio !=  0) ng.gio =  gio;
    else ng.gio = ltm->tm_hour;
    
	// Phut = 0 thi Lay phut he thong
	if(phut != 0) ng.phut = phut;
    else ng.phut = ltm->tm_min;
	
	return ng;
}

void laySBden(string* &Den){
	Den = new string[22];
		Den[0] = "Vung Tau";
		Den[1] = "Binh Dinh";
		Den[2] = "Ca Mau";
		Den[3] = "Can Tho";
		Den[4] = "Dak Lak";
		Den[5] = "Da Nang";
		Den[6] = "Dien Bien";
		Den[7] = "Gia Lai";
		Den[8] = "Hai Phong";
		Den[9] = "Ha Noi";
		Den[10] = "Khanh Hoa";
		Den[11] = "Rach Gia";
		Den[12] = "Phu Quoc";
		Den[13] = "Lam Dong";
		Den[14] = "Nghe An";
		Den[15] = "Phu Yen";
		Den[16] = "Quang Binh";
		Den[17] = "Quang Nam";
		Den[18] = "Hue";
		Den[19] = "Thanh Hoa";
		Den[20] = "Quang Ninh";
		Den[21] = "Ho Chi Minh";
	return;
}

int timTGbay( string den){
	string *Den ; laySBden( Den );
	for(int i= 0; i < 22; i++){
		if( Den[i] == den ) return (i+1)*10; // phut 
	}
	return -1;
}
NG congPhut( NG now, int congphut){
	now.phut += congphut;
	// 30p + 120p => 150p > 60 => 2h + 30p
	if(now.phut >= 60 ) {
		now.gio += floor(now.phut/60);
		if(now.phut == 60) now.phut = 0; else now.phut = now.phut%60; 
	}
	// 24h + 2h => 26h > 24 => 1n + 2h
	if(now.gio >= 24) {
		now.ngay += floor(now.gio/24);
		if(now.gio == 24) now.gio = 0; else now.gio = now.gio%24 - 1;
	}
	// 31n + 1n => 32n > 31n => 1th + 1n
	int max_ngay = laysoNgaythuocThang(now.thang,now.nam);
	if(now.ngay >= max_ngay ){
		now.thang += floor(now.ngay/max_ngay);
		if(now.ngay == max_ngay ) now.ngay = 1; else now.ngay = now.ngay%max_ngay;
	}
	if(now.thang >= 12){
		now.nam += 1;
		if(now.thang == 12 ) now.thang = 1; else now.thang = now.thang%12;
	}
	return now;
}
NG truPhut( NG now, int truphut){
	now.phut -= truphut;
	// 30p + 120p => 150p > 60 => 2h + 30p
	if(now.phut < 0) {
	now.phut = 60 + (now.phut%60);  
	now.gio -= 1;
	}
	now.gio -= floor(truphut/60);
	// 24h + 2h => 26h > 24 => 1n + 2h
	if(now.gio < 0) {
		now.gio = 24 + now.gio ;
		now.ngay -= 1; 
	}
	// 31n + 1n => 32n > 31n => 1th + 1n
	int max_ngay = laysoNgaythuocThang(now.thang - 1,now.nam);
	if(now.ngay < 1 ){
		now.thang -= 1;
		now.ngay = max_ngay;
	}
	if(now.thang < 1){
		now.nam -= 1;
		now.thang = 12; ;
	}
	return now;
}
NG tinhTGden(NG now, string den){
	int tgbay = timTGbay( den );
	return congPhut(now, tgbay);
}

//int tinhKhoangTG(NG now, NG then){
//	if(sosanhNG2(now,then) > 1)
//	{
//		NG temp;
//		temp = now;
//		now = then;
//		then = temp;
//	}
//	// 2020 - 2020 = 0; 2021 - 2020 = 1 ; 2022 -2020 = 2
//	int nam =   (then.nam - now.nam);
//	// 10 - 10 = 0 ; 2 - 10 = -8 + 12 = 4 ; 11 - 10 = 1 + 12 = 13  
//	int thang = (then.thang - now.thang) + 12*nam;
//	// 10 - 10 = 0 ; 2 - 10 = -8 
//	int ngay = (then.ngay - now.ngay)
//}

int sosanhNG2(NG a, NG b){
	string stra = NGtoString(a);
	string strb = NGtoString(b);
	return (stra < strb )? -1 : (stra > strb)? 1 : 0; 
}

int sosanhNG3(NG a, NG b){
	string stra = NGtoString(a, false);
	string strb = NGtoString(b, false);
	return (stra < strb )? -1 : (stra > strb)? 1 : 0; 
}

int sosanhNG(NG a, NG b){
	// 2020
	
	if(a.nam == a.nam)
	{
		// 8 < 9  => 1 
		if(a.thang < b.thang) return -1;
		else // 9 > 8  => -1 
		if(a.thang > b.thang) return 1;
		else{ // 9 = 9 
			// 01 < 03 => 1
			if(a.ngay < b.ngay) return -1;
			else // 03 > 01  => -1 
			if(a.ngay > b.ngay) return 1;
			else // 01 = 01 
			{
				if(a.gio < b.gio) return -1;
				else 
				if(a.gio > b.gio) return 1;
				else
					{
						if(a.phut < b.phut) return -1;
						else  
						if(a.phut > b.phut) return 1;
						else
							return 0; 
					}	
			}	
		}
	}
	// 2020 < 2021 => 1 ( thuan chieu )
	if(a.nam < b.nam) return 1;
	else
	// 2021 < 2020 => -1 ( ngc chieu )
	if(a.nam > b.nam) return -1;
}




