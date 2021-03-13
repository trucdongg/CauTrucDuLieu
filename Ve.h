#pragma once 
typedef struct Ve {
	string CMND;
	string socn; // so cho ngoi
};

// ---------   MANG DONG ----------------------------------------------------
class DsVe{
	private:
		Ve *ve;
		int sl = 0; 
		int sldb = 0; // so luong ve da ban  
	public:
		DsVe(){
			sl = 0; 
			sldb = 0;
		}
		DsVe(int soluong){
			sl = soluong;
			ve = new Ve[sl];
			sldb = 0;
		}
		// Them 1 Ve moi tai 1 vi tri 
		bool them(Ve vemoi,int atIndex);
		bool xoa( int atIndex);
		bool sua( Ve vesua, int atIndex);
		int  tim( string CMND );
		bool  dadangki (string socn);
		Ve* laydanhsach(){
			return ve;
		}
		void setVe(int vitri, Ve vemoi);
		int getSLtrong(){
			return this->sl - this->sldb;
		}
		void setSLDB(int sldb){ this->sldb = sldb; }
		int getSLDB() { return this->sldb; }
		int getSL(){ return this->sl;}
		void layvtChongoi(string tencn, int &day, int &dong);
		void layvtVedat( int *&index, int &n);
		void layvtVechuadat(int *&indexs, int &n);
		// Giup cho Tai va Luu ben CB 
			// Luu
		string toString();
		bool isEmpty();
		// giao dien ( nho bat loi rong )
		void xem();
};
void DsVe::layvtVechuadat(int *&indexs, int &n){
		n = getSLtrong();
	if( n == 0 ) return;
	
	indexs = new int[n];
	int dem = 0;
	for ( int i = 0 ; i < getSL() ; i++ ){
		if( ve[i].CMND == "" ) indexs[dem++] = i;
	}
	
}

void DsVe::layvtVedat( int *&indexs, int &n){
	n = getSLDB();
	if( n == 0 ) return;
	
	indexs = new int[n];
	int dem = 0;
	for ( int i = 0 ; i < getSL() ; i++ ){
		if( ve[i].CMND != "" ) indexs[dem++] = i;
	}
	
}

void DsVe::setVe(int vitri, Ve vemoi){
	if(vemoi.CMND == "") return;
	ve[vitri] = vemoi;
}

string laytenChongoi(int i,int j){
	char front = 65 + i;
	string back = (j == 0) ? "00" : ( j/10 < 1 )? "0" + itos(j):itos(j);
	return front+back;
}

bool DsVe::isEmpty(){
	return sldb == 0 ? true : false;
}

void DsVe::layvtChongoi(string tencn, int &day, int &dong){
	char front = tencn[0];
	day = int(front - 65);
	dong = stoi(tencn.substr(1,2));
}

bool DsVe::dadangki(string socn){
	for(int i=0;i<sldb;i++){
		if( ve[i].socn == socn)
			return ve[i].CMND != "" ? true : false ;
	}
	 
}

bool DsVe::them(Ve vemoi, int atIndex){
	// Them 1 ve cuoi day
	if(sldb == sl || vemoi.CMND == "" && vemoi.socn == "" || tim(vemoi.CMND) != -1) // Khong con ve 
		return false;
	ve[atIndex] = vemoi;	
	sldb++;
	return true;
}

bool DsVe::xoa(int atIndex){
	// Xoa 1 diem tai day
	if(sldb == 0 || atIndex > sl || atIndex < 0)
		return false;
	ve[atIndex].CMND == "";
	sldb--;
	return true;
}

bool DsVe::sua(Ve vesua, int atIndex){
	// Neu sua trung CMND thi sao 
	if(sldb == 0 || atIndex > sl || atIndex < 0 || vesua.CMND == "" && vesua.socn == "")
		return false;
	ve[atIndex] = vesua;
	return true;
}

string DsVe::toString(){
	if(sldb == 0) return "";
	int dong= 0, day=0;
	string items = "",item = "";
	for(int i=0; i < sl; i++){
		if(ve[i].CMND != ""){
			layvtChongoi(ve[i].socn,day,dong);
			item = itos0(day)+" "+itos0(dong)+" "+ve[i].CMND+" /";
			items += item;
		}
	}
	return items;
}

int DsVe::tim( string CMND ){
	// Neu danh sach rong
	if(sldb == 0)
	return -1;
	
    for(int i = 0; i< sl; i++){
    	if(ve[i].CMND == CMND) 
    		return i;
	}
	return -1;
}
