#pragma once 
// ------------------------------------------- CAC HAM CHUYEN DOI CAC KIEU DU LIEU ------------------------------------------------
// Chi tiet

// 1. CHUYEN DOI TU INT SANG STRING 

string itos( int num ){
	string result;
	while ( num > 0){
		result += char(num%10 + 48);
		num = num/10;
	}
	int n = result.length();
	for(int i=0;i<n/2;i++)
	swap(result[i],result[n-1-i]);
	return result;
} 
string itos0(int num){
	return itos(num) == "" ? "0" : itos(num); 
}
// 2. CHUYEN DOI TU STRING SANG INT 
int ctoi(char a){
	return a - '0';
}
int stoi(string str) 
{
    int num;
    istringstream(str)>>num;
    return num;
}
// 3. CHUYEN DOI TU STRING SANG CHAR * 
char* stoc(string str){
   char* c = new char[str.size() + 1];
   strcpy(c, str.c_str());
   c[str.length()] ='\0';
   return c;
}
// 4. CHUYEN DOI CHAR * SANG STRING 
string ctos(char* a) 
{ 
    string s = a; 
    return s; 
} 
// 5. CHUYEN DOI CHAR SANG STRING 
string stoc1(char c){
		std::string s(1, c);
		return s;
}
// STRING 
string upper(string txt){
	for(int i =0; i<txt.size(); i++){
		if(txt[i] >= 97 && txt[i] <= 122) txt[i]-= 32; 
	}
	return txt;
}
string trim( string s )
{
	int start = 0;
	int end = s.length()-1;

	while (isspace(s[start])) {
		start++;
	}

	while ( end != start  && isspace(s[end]) ){
		end--;
	}
	if(start != 0 || end != s.length() - 1)
		return s.substr(start,end-start+1);
	return s;	
}
void Reint( int* a, int n){
	for(int i =0; i<n;i++)
		a[i] = -1;
}
string Phai(bool tt){
	return tt ? "Nam" : "Nu";
}

bool Allnumber( string a){
	for(int i = 0; i < a.size(); i++)
		if (a[i] < '0' || a[i] > '9') return false; 
	return true;
}

void splitStrTo(string a, string *&arr , int  &n, char sep ){
	n = 0;
	a = trim(a);
	if( a == "") return;
	if(a[a.size()-1] == ',') a = a.substr(0,a.size()-1);
	if(a[0] == ',') a = a.substr(1,a.size()-1);
	for(int j= 0;  j < a.size(); j++ ){
		if( a[j] == sep) n++;
	}
	// n la so dau phay trong string a 
	n = n+1;
	
	// n + 1 la so phan tu 
	arr = new string[n];
	int last_i = 0, j = 0;
	for( int i = 0; i < a.size() ; i++  ){
	if( a[i] == sep ){
			arr[j++] = trim( a.substr(last_i,i - last_i) );
			last_i = i+1;
		}
	}
	arr[j] = trim( a.substr(last_i,a.size() - last_i) );
}

void merStrTo(string &a, string* arr, int n, char sep){
	a = "";
	for(int i = 0; i < n; i++){
		if(arr[i] != ""){
			a += arr[i];
			a += sep;
		}
	}
	if(a.size() != 0) a.erase(a.length() -1 , 1);
	
}

// ------------------------------------------- HAM FILTER !! ---------------------------------------------------------------

string search(string pat,string txt){
	if( pat == txt) return txt;
	int M = (pat.length());
	int N = (txt.length());
	// txt = apple, pat = ap  
	for(int i=0;i<=N-M;i++){
		int j;
		// Neu 'a' trong 'ap' co trong txt 'a..'
		// Thi tiep tuc xet 'p' trong 'ap' co trong txt 'pp' k?
		 
		for(j=0;j<M;j++)
		if (txt[i+j] !=pat[j]) break;
		// Break thi se bo qua dong nay va tang i len 
		
		// Neu trung thi xuat ra txt luon 
		if(j==M) return txt;
	}
	
	return "";
}

//void find(string txt, string *arr, int n){
//	gotoxy(0,2);
//	int ntxt = txt.length();
//	for(int i=0 ;i<n; i++){
//		search(txt,arr[i]);
//	}
//	return;
//}
//
//void filter(string *arr, int n){
//	string t = "";	
//	char c;
//	while(1){
//		c = getch();
//		if (c == BACKSPACE){ // backspace - xóa 
//			if (t.size() != 0){
//				gotoxy(t.size(),0);
//				t.erase(t.size()-1,1);		// erase cung~ co the xoa string
//				cout<<"\b \b";
//				clearRect(0,2,20,10);
//				if(t != "") find(t,arr,n);
//				// Khi dang o~ trang. thái string maxlen thì khi xóa di kí tu cuoi cùng, thì se~ xóa báo loi~
//			}
//		}
//		if (c == ESC){
//			break;
//		}
//		if (c >= 32)
//			if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9')
//			{
//				gotoxy(t.size(),0);
//				t+= c;
//				cout<<c;
//				clearRect(0,2,20,10);
//				find(t,arr,n);
//			}
//	} 
//}
// ------------------------------------------- CAC HAM RA VAO FILE & TRUYEN DU LIEU ------------------------------------------------


// Mo ta ham
bool writeFile(const char* FILE_NAME,string what, bool isAppend);
string readFile(const char* FILE_NAME, int from_which_line = 0, int many_lines = 0);

//1. VIET FILE ( File nao ? viet gi ? tao moi hay viet tiep ? )
bool writeFile(const char* FILE_NAME, string what, bool isAppend){
	
	if(isAppend) // Append mode 
		file.open(FILE_NAME,ios::app);
	 else // Overwrite mode
		file.open(FILE_NAME,ios::out);
		
	file << what << endl;
	file.close();
	return 1; 
}
//2. DOC FILE => ( File nao ? Doc tu dau ? Bao nhieu dong)
string readFile(const char* FILE_NAME, int from_which_line, int many_lines){
	string data;
	string line;
	file.open(FILE_NAME,ios::in);
	
	if(!file){
		file.close();
		// Create new file 
		cout<<"File "<<FILE_NAME<<" is being created .. Done (File has no data now) !!"<<endl;
		file.open(FILE_NAME,ios::out);
		file.close();
    	// Done 
		file.open(FILE_NAME,ios::in);
	}
	
	// Start from which line in file [0, n-1]
	if(from_which_line > 0) 
		for(int i =0 ; i < from_which_line; i++) file.ignore(MAX_CS_IN_FILE, '\n');
			
	if(many_lines == 0) // READ ALL mode
		while(!file.eof()) {	getline(file, line); data += line+"\n"; }
	else 				// READ many_lines mode	
    	for(int i =0 ; i < many_lines && !file.eof(); i++)
    		{ getline(file, line) ; data += line; }	    	
    
	file.close();
	
	return data;
}
void insertionSort(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
} 
// ------------------------------------------- CAC TEST CASE CHO CAC CLASS ------------------------------------------------

// Copy Paste và unComment de chay 

//                  TEST CHUC NANG CUA DSMB                 
//	DSMB ds = DSMB();
//	MB newMB = MB();
//	newMB.loai= "abc";
//	newMB.soday = 10;
//	newMB.sodong = 10;
//	newMB.sohieu = "MB011";
//	ds.them(newMB);
//	ds.them(newMB);
//	ds.lietkeMB();
////	cout<<ds.tim("MB011")<<endl;
////	cout<<ds.toString()<<endl;
//
//	newMB.loai="def";
//	cout<<"Edit 11th: "<<ds.sua(newMB,10)<<endl;
//	ds.lietkeMB();
//
//	cout<<"DEL 11th "<<ds.xoa(10)<<endl;
//	ds.lietkeMB();
//	
//	ds.luu(0);

//                  TEST CHUC NANG CUA DSHK                 
//	DSHK ds = DSHK();
//	HK newHK;
//	newHK.cmnd ="0129123";
//	newHK.ho   = "Phan";
//	newHK.ten  = "Dai";
//	newHK.phai = 1;
//	ds.them(newHK);
//	newHK.cmnd = "0122222";
//	ds.them(newHK);
//	newHK.cmnd = "0122231";
//	ds.them(newHK);
//	newHK.cmnd = "2222222";
//	ds.them(newHK);
////	ds.sua(newHK,"0129123");
//	ds.xem();
////	cout<<ds.toString();
//	cout<<ds.toString();
//	ds.luu();

//                         TEST CHUC NANG CUA DSCB                 
//	DSCB ds = DSCB();
//	
//	CB a = {"abc",Baygio(10,0),"def",'1',"MB01",DsVe()};
//	ds.them(a);
//	a.maCB = "abcd";
//	ds.them(a);
//	cout<<ds.toString()<<endl;
//	a.sbden = "fefe";
////	cout<<ds.tim("abcd")->cb.maCB<<endl;
//	cout<<"sua: "<<ds.sua(a)<<endl;
//	cout<<ds.toString()<<endl;
//	ds.xoa(1);
//	cout<<ds.toString()<<endl;

//                         TEST HAM CHUC NANG TIM THOI GIAN DEN         
//	string Den = "Ho Chi Minh";
//	
//	NG now = Baygio(22,59);
//	now.ngay = 31;
//	now.thang = 12;
//	int tgbay = timTGbay(Den);
//	NG then = tinhTGden(now,Den);
//	cout<<NGtoString(now)<<endl;
//	cout<<"Thoi gian den "<<Den<<" : "<<tgbay/60<<" gio "<<tgbay%60<<" phut "<<endl;
//	cout<<NGtoString(then)<<endl;
//	cout<<sosanhNG2(now,then);

// MAY USE // HAM NGAU NHIEN CUA DB MAY BAY 
//  srand (time(NULL));
//	int sl = 11;
//	string hhk[sl] = {"ATR","ASA","BBA","ORS","SIA","TGA","VAL","PCA","VAS","VJA","VNA"};
//	for(int i = 0; i < 11; i++){
//		for(int j = 0; j < 5; j++){	
//		int rd = rand() % 10000 + 10000 + rand() % 50 + 1;
//		cout<<hhk[i]<<rd<<endl;
//		}
//	}



//void split_fline( string str){
//	int last_i = 0;
//		int n = str.length();
//		for(int i =0;i <n;i++){
//			if(str[i] == '\n'){
//				cout<<"Line: "<<str.substr(last_i, i - last_i);
//				split_strok(str.substr(last_i, i - last_i));
//				// c15/c40/c2/c2 
//				// find out how to split 
//				
//				// end one line 
//				last_i = i+1;
//			}
//		}
//		// left line 
//		string last = str.substr(last_i);
//		if(last.size() != 0){
//		cout<<"Line-last: "<<last;
//		split_strok(last);
//		}  
//		
//}

