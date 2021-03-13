typedef struct Hanhkhach{
	string cmnd; //C11
	string ho; 
	string ten;
	bool phai;
	string tgban; // Thoi gian ket thuc chuyen bay hien tai  
	bool ranh;
	int scb;  
}HK;

struct nodeHK{
	HK dulieuHK;
	nodeHK *pLeft;
	nodeHK *pRight;
};

typedef nodeHK* Tree;

int n_init = 0;
HK ds_init[ MAX_HK ];
HK hkrong;
// HO TRO XU LI
int mauTrangthai2( int tt ){
	return tt == 1 ? GREEN : RED;
}
bool capnhatHKranh( string& tgban){
	bool kq = true; 
	if( tgban == "" ) return kq;
	else{
		string *arr;
		int n = 0; int vitri = -1;
		char sep = ',';
		CB cb ;
		NG now = Baygio();
		splitStrTo(tgban, arr, n ,sep);
		for(int i = 0; i < n; i++)
		// Xu li cho nay moi quan trong 
			{
				vitri = mcb.tim( arr[i] );
				if ( vitri != -1) {
					cb = mcb.getCB( vitri );
					
					if(cb.tt == 3 || cb.tt == 0){
						arr[i] = "";
					} 
					else{
						 //Neu luc khoi hanh nho hon hoac bang bay gio ( DK ( time < tgkh ):  khong duoc dat ve )  
						if( sosanhNG(cb.ngaygiokh,now) <= 0 ){
							arr[i] = "";
						} 
					}
					
				}else{
					arr[i] = "";
				}
			}
		merStrTo(tgban,arr,n,sep);
		// Neu khong con chuyen bay nao nua thi ranh khong thi k 
		kq = (tgban == "") ? true : false;
		delete[] arr;
	}

	return kq;
}



// ---------   CAY TIM KIEM NHI PHAN CAN BANG  ----------------------------------------------------
class DSHK{
	private:
		int n = 0;
		Tree t = NULL;
		const char* FILE_NAME = "./DoanCTDL/DanhsachHanhKhach.dat";
	public:
		DSHK(){
			tai();
		}
		// Cay rong hay khong    -> True / False 
		bool empty();
		// Them 1 khach hang moi -> True / False 
		void them( HK dulieuKH , bool inc = true);
		void them(Tree &t, HK data);		
		// Sua 1 khach hang theo CMND -> True / False 
		bool sua( HK dulieuKH, string cmnd = "");
		// Xoa 1 khach hang theo CMND -> True / False 
		void xoa( string cmnd );
		void xoa( Tree &t, string cmnd );
		// Tim 1 khach hang theo CMND -> Tra lai node*
		Tree tim( string cmnd );
		// Xem 
		void xem();
		void PreOrder(Tree root);
		// Tai tu file vao bien  
		void tai();
		// to string 
		string toString();
		string toString(Tree t );
		// Luu tu bien vao file 
		void luu( bool isAppend = true );
		
};

// Xem du lieu 
void DSHK::PreOrder(Tree root){
    if(root != NULL)
    {
        cout<<root->dulieuHK.cmnd<<endl;
        PreOrder(root->pLeft);
        PreOrder(root->pRight);
    }
}
void DSHK::xem(){
	PreOrder(t);
}
// Them 1 nut vao cay 
void DSHK::them(HK dulieuHK, bool inc){
	them(t, dulieuHK);
	if(inc) if(n < MAX_HK) n++;
}

void DSHK::them(Tree &t, HK data){
    if (t == NULL)
	{
		nodeHK *p = new nodeHK;
		p->dulieuHK = data;
		p->pLeft = p->pRight = NULL;
		t = p;
	}
	else{
		if (data.cmnd < t->dulieuHK.cmnd){
			them(t->pLeft, data);
		}else if (data.cmnd > t->dulieuHK.cmnd){
			them(t->pRight, data);
		}
	}
}

// Kiem tra neu cay co rong hay khong
bool DSHK::empty(){
   return(t == NULL ? true : false);
}

// Tim 1 nut dua tren cmnd => Con tro NodeHK
Tree DSHK::tim( string cmnd ){
	if(empty())
	return NULL;
		Tree p = t;
		while( p != NULL){
			if( cmnd < p->dulieuHK.cmnd ) p = p -> pLeft;
			if( cmnd > p->dulieuHK.cmnd ) p = p -> pRight;
			if( cmnd == p->dulieuHK.cmnd) return p;
		}
	return NULL;
}

// Sua 1 nut dua tren tim cmnd => true/ false
bool DSHK::sua( HK dulieuHK, string cmnd ){
	cmnd = (cmnd != "") ? cmnd : dulieuHK.cmnd ;
	// Tim neu trung hoac 
	Tree p = tim(cmnd);
	
	if(p == NULL) return 0;
	else 
		p->dulieuHK = dulieuHK;
		return 1;
}

// Xoa 1 nut dua tren cmnd => Dequy
void DSHK::xoa( string cmnd ){
	xoa(t,cmnd);
	if(n > 0) n--;
}

void DSHK::xoa(Tree &t, string cmnd)     
{
    if (t==NULL) return ;
    else if (cmnd < t->dulieuHK.cmnd ) xoa(t->pLeft, cmnd);
    else if (cmnd > t->dulieuHK.cmnd ) xoa(t->pRight, cmnd);
    else // cmnd == root
    {
        if (t->pLeft == NULL) t = t->pRight;    // Node chi co cay con phai
        else if (t->pRight == NULL) t = t->pLeft;   // Node chi co cay con trai
        else // Node co ca 2 con
        {
        	// Tim nut con lon nhat ben phai
            Tree Q = t->pLeft;
            while (Q->pRight != NULL)
            {
                Q = Q->pRight;
            }
            t->dulieuHK = Q->dulieuHK;
            xoa(t->pLeft, Q->dulieuHK.cmnd);
        }
    }
    return ;
}

string DSHK::toString(){
	return	itos0(n)+ "\n" + toString(t);
}

string DSHK::toString(Tree t){
	if( t == NULL )
	{
		return "";
	}
	string format;
	string phai = (t->dulieuHK.phai==true)?"1":"0";
	string hanhkhach = t->dulieuHK.cmnd + "/" + t->dulieuHK.ho + "/" + t->dulieuHK.ten +"/" +t->dulieuHK.tgban + "/"+ phai + " " + itos0(t->dulieuHK.scb) +"\n";
	format = hanhkhach + toString(t->pLeft) + toString(t->pRight);
	return format;
}

void DSHK::luu ( bool isAppend ){ 
writeFile( FILE_NAME, toString() , isAppend ); 
}

void DSHK::tai ( ) {
	n = 0;
	
 	ifstream file;
 	file.open(FILE_NAME,ios::in);
 	
 		if(!file){
		file.close();
		// Create new file 
		cout<<"File "<<FILE_NAME<<" dang duoc tao .. Xong (File khong co du lieu luc nay) !!"<<endl;
		file.open(FILE_NAME,ios::out);
		file.close();
    	// Done 
//		file.open(FILE_NAME,ios::in);
		return;
	}
	fflush(stdin);
	// Bien temp xoa dau xuong dong
	string temp;
	string now = NGtoString( Baygio() );
	file >> n; n_init = 0;
	fflush(stdin);
	getline(file,temp,'\n');
	while(!file.eof()){
		HK newHK;
		bool phai;
		fflush(stdin);
		getline(file,newHK.cmnd,'/');
		if(newHK.cmnd == "") break;
		getline(file,newHK.ho,'/');
		if(newHK.ho == "") break;
		getline(file,newHK.ten,'/');
		if(newHK.ten == "") break;
		/// NEED FIX -------------
		getline(file,newHK.tgban,'/');
		/// -----------------------
		fflush(stdin); 
		file >> newHK.phai >> newHK.scb;
		if(newHK.tgban == "") newHK.ranh = true;
		else{
		newHK.ranh = capnhatHKranh(newHK.tgban);
		} 
		them(newHK, false);
		ds_init[n_init++] = newHK;
		getline(file,temp,'\n');
	}

	file.close();
	return;
} 

class mangHK{
	private:
		int n = 0;
		HK ds[ MAX_HK ];
		DSHK dshk = DSHK();
	public:
		mangHK(){
			tai();
		}
		// Liet ke 
		void lietkeHK(int start_x, int start_y, int from, int to);
		void lietkeHKtheo(int start_x, int start_y, int *indexs, int n);
		// Them ( 1 Hanh khach moi ) vao Cay T va mang Ho tro
		void them( HK newHK );
		// Xoa 
		bool xoa ( string cmnd );
		// Sua 
		bool sua ( HK editHK );
		// Tim 
		int tim ( string cmnd );
		// Tai 
		void tai();
		// Luu
		void luu();
		// Laydodai
		void layCMND(string *&a);
		string toString(){
			return dshk.toString();
		}
		int getN() { 
			return n;
		}
		HK getHK(string CMND){
			for(int i = 0; i < n; i++){
				if( ds[i].cmnd == CMND )
					return ds[i];
			}
			return hkrong;
		}
		HK getHK(int atIndex){
			if( atIndex >= 0 && atIndex <= n-1)
			return   ds[atIndex];
		}
};

void mangHK::layCMND( string *&a){
	a = new string[n];
	char tt; 
	for( int i = 0; i < n; i++){
		tt = ds[i].ranh ? '1' : '0'; 
		a[i] += ds[i].cmnd + tt;
	}
	
}

void mangHK::lietkeHK(int start_x, int start_y, int from, int to){
	if(n == 0){
		clearRect(start_x,start_y+3,85,1);
		drawText(start_x+10,start_y+3,"Khong co gia tri nao trong Danh sach Hanh Khach",YELLOW);
	}else if( n > 0){
		clearRect(start_x+1,start_y+4,20,1);
		string now = NGtoString(Baygio());
	for(int i = to-1; i>= from; i--)
		{
		HK dsi = ds[i];
		string now = NGtoString( Baygio() );
		// Canh le
		int	border_line = (to-1 - i+1)*2;
		int line_height = border_line + 1;
		
		// Khung chua ben ngoai
		drawRect(start_x,start_y+border_line,100,2);
		
		// Khung CMND
		string str = dsi.cmnd ; 
		
		// Cap nhat 18/8/2020 4:28
		dsi.ranh = (dsi.tgban == "")? true: false;
		if(dsi.ranh != ds[i].ranh) sua(dsi);
		drawText(start_x+4,start_y+line_height,dsi.cmnd, mauTrangthai2(dsi.ranh) );
		gotoxy(start_x,start_y+border_line); printf("%c",195);
		
		// Khung HO 
		string ho = (dsi.ho.size() > 20 ) ? dsi.ho.substr(0,18) + ".." : dsi.ho;
		draw_high_line(start_x+20,start_y+border_line,2);
		drawText(start_x+28,start_y+line_height,ho,YELLOW);
		gotoxy(start_x+20,start_y+border_line); printf("%c",197);
		
		// Khung TEN 
		string ten = (dsi.ten.size() > 20 ) ? dsi.ten.substr(0,18) + ".." : dsi.ten;
		draw_high_line(start_x+54,start_y+border_line,2);
		drawText(start_x+56,start_y+line_height,ten,YELLOW);
		gotoxy(start_x+54,start_y+border_line); printf("%c",197);
		
		// Khung PHAI 
		string phai = (dsi.phai) ? "Nam" : "Nu";
		draw_high_line(start_x+77,start_y+border_line,2);
		drawText(start_x+80,start_y+line_height,phai,WHITE);
		gotoxy(start_x+77,start_y+border_line); printf("%c",197);
		
		// Doan thang ket thuc dong 
		gotoxy(start_x+100,start_y+border_line); printf("%c",180);	
		}
	}
}

void mangHK::lietkeHKtheo(int start_x, int start_y, int *indexs, int n){
	if(n == 0){
		clearRect(start_x,start_y+3,85,1);
		drawText(start_x+10,start_y+3,"Khong co gia tri nao trong Danh sach Hanh Khach",YELLOW);
	}else if( n > 0){
		clearRect(start_x+1,start_y+4,20,1);
		string now = NGtoString(Baygio());
	for(int i = 0; i< n ; i++)
		{
		HK dsi = ds[indexs[i]];
		string now = NGtoString( Baygio() );
		// Canh le
		int	border_line = (i+1)*2;
		int line_height = border_line + 1;
		
		// Khung chua ben ngoai
		drawRect(start_x,start_y+border_line,100,2);
		
		// Khung CMND
		string str = dsi.cmnd ; 
		
		// Cap nhat 18/8/2020 4:28
		dsi.ranh = (dsi.tgban == "")? true: false;
		if(dsi.ranh != ds[i].ranh) sua(dsi);
		drawText(start_x+4,start_y+line_height,dsi.cmnd, mauTrangthai2(dsi.ranh) );
		gotoxy(start_x,start_y+border_line); printf("%c",195);
		
		// Khung HO 
		string ho = (dsi.ho.size() > 20 ) ? dsi.ho.substr(0,18) + ".." : dsi.ho;
		draw_high_line(start_x+20,start_y+border_line,2);
		drawText(start_x+28,start_y+line_height,ho,YELLOW);
		gotoxy(start_x+20,start_y+border_line); printf("%c",197);
		
		// Khung TEN 
		string ten = (dsi.ten.size() > 20 ) ? dsi.ten.substr(0,18) + ".." : dsi.ten;
		draw_high_line(start_x+54,start_y+border_line,2);
		drawText(start_x+56,start_y+line_height,ten,YELLOW);
		gotoxy(start_x+54,start_y+border_line); printf("%c",197);
		
		// Khung PHAI 
		string phai = (dsi.phai) ? "Nam" : "Nu";
		draw_high_line(start_x+77,start_y+border_line,2);
		drawText(start_x+80,start_y+line_height,phai,WHITE);
		gotoxy(start_x+77,start_y+border_line); printf("%c",197);
		
		// Doan thang ket thuc dong 
		gotoxy(start_x+100,start_y+border_line); printf("%c",180);	
		}
	}
}

void mangHK::tai(){
	n = n_init;
	for( int i = 0; i< n ; i++){
		ds[i] = ds_init[i];
	}
}

void mangHK::luu(){
	dshk.luu(false);
}

void mangHK::them( HK newHK ){
	if(newHK.cmnd == "" || n == MAX_HK)
		return;
	else{
		if(newHK.tgban == "") newHK.ranh = true; else newHK.ranh = false;
		dshk.them(newHK);
		ds[n++] = newHK; 
	}
}

bool mangHK::sua( HK editHK){
	if(editHK.cmnd == "" || n == 0)
		return false;
	else{
		int vitri = tim(editHK.cmnd);
		if( vitri == -1) return false;
		dshk.sua(editHK, editHK.cmnd);
		ds[vitri] = editHK;
	}
	return true;
}

int mangHK::tim(string cmnd){
	if( n == 0 ) return -1;
	for( int i = 0; i< n; i++)
		if( ds[i].cmnd == cmnd )
		{
			return i ;
		}
	return -1;
}

bool mangHK::xoa(string cmnd){
	if(cmnd == "" || n == 0 ) return false;
	int vitri = tim(cmnd);
		if(vitri == -1)
			return false;
		
		if(vitri == n-1){
			n--;
			dshk.xoa(cmnd);
			return true;
		}
	
	for(int i = vitri; i <n-1; i++){
		ds[i] = ds[i+1];
	}
	n--;
	dshk.xoa(cmnd);
	return true;
}




