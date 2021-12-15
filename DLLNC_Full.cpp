#include <iostream>
#include <string.h> //strcpy(a,b)
#include <conio.h> //getch()
#include <windows.h> //gotoxy(x,y)
using namespace std;
void gotoxy(int x, int y){
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


//========================================================================= STRUCT
struct Node{
     char nama[30];
     int umur;
     Node *next;
     Node *prev;
};
Node *head = NULL;
Node *tail = NULL;

//========================================================================= TAMBAH DATA
int no_urut=0;
void tmbh_belakang(){
	string a; fflush(stdin);
	int b;
	gotoxy(49,3); getline(cin, a);
	gotoxy(49,4); cin>>b;
	
	Node *baru;
	baru= new Node;
	strcpy(baru->nama, a.c_str());
	baru->umur=b;
	
	if(head==NULL){
		head=tail=baru;	
		head->next=NULL;
		head->prev=NULL;
	}
	else{
		tail->next=baru;
		baru->prev=tail;
		tail=baru;
		tail->next=NULL;
	}
	no_urut++;
}
void tmbh_depan(){
	string a; fflush(stdin);
	int umurorg;
	gotoxy(49,3); getline(cin, a);
	gotoxy(49,4); cin>>umurorg;
	
	Node *baru = new Node;
	strcpy(baru->nama, a.c_str());
	baru->umur = umurorg;

	baru->prev = NULL;
	baru->next = head;
	if(head==NULL){
		head=tail=baru;	
		head->next=NULL;
		head->prev=NULL;
	}
	else{
		head->prev=baru;
		baru->next=head;
		head=baru;
		head->prev=NULL;
	}
	no_urut++;
}
void tmbh_setelah(){
	string a; fflush(stdin);
	int umurorg;
	bool found;
	gotoxy(49,3); getline(cin, a);
	gotoxy(49,4); cin>>umurorg;
	
	Node *baru = new Node;
	strcpy(baru->nama, a.c_str());
	baru->umur = umurorg;
	
	if(head==NULL){
		baru->prev = NULL;
		baru->next = NULL;
		head=tail=baru;
		found = true;
		no_urut++;
	}	
	else{
		gotoxy(40,6);cout<<"| Tambahkan Setelah Nama:           |";
		gotoxy(40,7);cout<<"|                                   |";
		gotoxy(40,8);cout<<"-------------------------------------";
		char cari[30];
		string aa; fflush(stdin);
		gotoxy(42,7);getline(cin, aa); strcpy(cari, aa.c_str());
		Node *bantu = head;
		while(bantu!=NULL){
			if(strcmp(cari,bantu->nama)==0){
				baru->next = bantu->next;
				bantu->next = baru;
				baru->prev = bantu;
				if(baru->next != NULL)
					baru->next->prev = baru;
				if(bantu==tail)
					tail = baru;
				found = true;
				no_urut++;
				break;
			}
			bantu = bantu->next;
		}
		gotoxy(40,9);cout<<"|                                   |";
		gotoxy(40,10);cout<<"-------------------------------------";
		if(found) {gotoxy(41,9);cout<<"    ==DATA TELAH DIPERBARUI==      ";}
		else {gotoxy(41,9);cout<<"     ==PEMBARUAN DATA GAGAL==      ";}
		gotoxy(40,11);getch();
	}
}
void tmbh_sebelum(){
	string a; fflush(stdin);
	int umurorg;
	bool found = false;
	gotoxy(49,3); getline(cin, a);
	gotoxy(49,4); cin>>umurorg;
	
	Node *baru = new Node;
	strcpy(baru->nama, a.c_str());
	baru->umur = umurorg;
	
	if(head==NULL){
		baru->prev = NULL;
		baru->next = NULL;
		head=tail=baru;
		found = true;
		no_urut++;
	}	
	else{
		gotoxy(40,6);cout<<"| Tambahkan Sebelum Nama:           |";
		gotoxy(40,7);cout<<"|                                   |";
		gotoxy(40,8);cout<<"-------------------------------------";
		char cari[30];
		string aa; fflush(stdin);
		gotoxy(42,7);getline(cin, aa); strcpy(cari, aa.c_str());
		Node *bantu = head;
		while(bantu!=NULL){
			if(strcmp(cari,bantu->nama)==0){
				baru->prev = bantu->prev;
				baru->next = bantu;
				bantu->prev = baru;
				if(baru->prev!=NULL)
					baru->prev->next = baru;
				if(bantu==head)
					head = baru;
				found = true;
				no_urut++;
				break;
			}
			bantu = bantu->next;
		}
		gotoxy(40,9);cout<<"|                                   |";
		gotoxy(40,10);cout<<"-------------------------------------";
		if(found) {gotoxy(41,9);cout<<"    ==DATA TELAH DIPERBARUI==      ";}
		else {gotoxy(41,9);cout<<"     ==PEMBARUAN DATA GAGAL==      ";}
		gotoxy(40,11);getch();
	}	
}

//========================================================================= HAPUS DATA
void hps_belakang(){
	Node *hapus;
	if (head!=NULL){
		if(tail->prev != NULL){
			hapus = tail;
			tail = tail->prev;
			tail->next = NULL;
			delete hapus;
	 	}
		else{
			tail=head=NULL;
		}
		no_urut--;
	} 
	else{
		gotoxy(40,6);cout<<"==DATA KOSONG==\n";	
		gotoxy(40,7);getch();
	} 
} 
void hps_depan(){
	Node *hapus;
	if (head!=NULL){
		if(head->next != NULL){
			hapus = head;
			head = head->next;
			head->prev = NULL;
			delete hapus;
	 	}
		else{
			tail=head=NULL;
		}
		no_urut--;
	} 
	else{
		gotoxy(40,6);cout<<"==DATA KOSONG==\n";	
		gotoxy(40,7);getch();
	} 
}
void hps_setelah(){
	if (head != NULL){
		if (head->next != NULL){
			bool found;
			gotoxy(49,3);cout<<"-";
			gotoxy(49,4);cout<<"-";
			gotoxy(40,6);cout<<"| Hapus Setelah Nama:               |";
			gotoxy(40,7);cout<<"|                                   |";
			gotoxy(40,8);cout<<"-------------------------------------";
			char cari[30];
			string aa; fflush(stdin);
			gotoxy(42,7);getline(cin, aa); strcpy(cari, aa.c_str());
			Node *bantu = head;
			Node *hapus;
			while(bantu!=NULL){
				if(strcmp(cari,bantu->nama)==0){
					if (bantu->next != NULL){
						if (bantu->next != tail){
							hapus = bantu->next;
							if (hapus->next != NULL)
								hapus->next->prev = hapus->prev;
							hapus->prev->next = hapus->next;
						}
						else{
							hapus = tail;
							tail = tail->prev;
							tail->next = NULL;
						}
						delete hapus;
						found = true;
						no_urut--;
						break;	
					}
				}
				bantu = bantu->next;
			}
			gotoxy(40,9);cout<<"|                                   |";
			gotoxy(40,10);cout<<"-------------------------------------";
			if(found) {gotoxy(41,9);cout<<"    ==DATA TELAH DIPERBARUI==      ";}
			else {gotoxy(41,9);cout<<"     ==PEMBARUAN DATA GAGAL==      ";}
			gotoxy(40,11);getch();
		}
		else{
			gotoxy(40,6);cout<<"==DATA HANYA 1==\n";	
			gotoxy(40,7);getch();		
		}
	}
	else{
		gotoxy(40,6);cout<<"==DATA KOSONG==\n";	
		gotoxy(40,7);getch();
	} 
}
void hps_sebelum(){
	if (head != NULL){
		if (head->next != NULL){
			bool found;
			gotoxy(49,3);cout<<"-";
			gotoxy(49,4);cout<<"-";
			gotoxy(40,6);cout<<"| Hapus Sebelum Nama:               |";
			gotoxy(40,7);cout<<"|                                   |";
			gotoxy(40,8);cout<<"-------------------------------------";
			char cari[30];
			string aa; fflush(stdin);
			gotoxy(42,7);getline(cin, aa); strcpy(cari, aa.c_str());
			Node *bantu = head;
			Node *hapus;
			while(bantu!=NULL){
				if(strcmp(cari,bantu->nama)==0){
					if (bantu->prev != NULL){
						if (bantu->prev != head){
							hapus = bantu->prev;
							if (hapus->prev != NULL)
								hapus->prev->next = hapus->next;
							hapus->next->prev = hapus->prev;
						}
						else{
							hapus = head;
							head = head->next;
							head->prev = NULL;
						}
						delete hapus;
						found = true;
						no_urut--;
						break;	
					}
				}
				bantu = bantu->next;
			}
			gotoxy(40,9);cout<<"|                                   |";
			gotoxy(40,10);cout<<"-------------------------------------";
			if(found) {gotoxy(41,9);cout<<"    ==DATA TELAH DIPERBARUI==      ";}
			else {gotoxy(41,9);cout<<"     ==PEMBARUAN DATA GAGAL==      ";}
			gotoxy(40,11);getch();
		}
		else{
			gotoxy(40,6);cout<<"==DATA HANYA 1==\n";	
			gotoxy(40,7);getch();	
		}
	}
	else{
		gotoxy(40,6);cout<<"==DATA KOSONG==\n";	
		gotoxy(40,7);getch();
	} 
}
void hps_bebas(){
	if (head != NULL){
		if (head != tail){
			bool found;
			gotoxy(49,3);cout<<"-";
			gotoxy(49,4);cout<<"-";
			gotoxy(40,6);cout<<"| Hapus Nama:                       |";
			gotoxy(40,7);cout<<"|                                   |";
			gotoxy(40,8);cout<<"-------------------------------------";
			char cari[30];
			string aa; fflush(stdin);
			gotoxy(42,7);getline(cin, aa); strcpy(cari, aa.c_str());
			Node *bantu = head;
			Node *hapus;
			while(bantu!=NULL){
				if(strcmp(cari,bantu->nama)==0){
						if (bantu == head){
							hapus = head;
							head = head->next;
							head->prev = NULL;
						}
						else if (bantu == tail){
							hapus = tail;
							tail = tail->prev;
							tail->next = NULL;
						}
						else{
							hapus = bantu;
							hapus->next->prev = hapus->prev;
							hapus->prev->next = hapus->next;
						}
					delete hapus;
					found = true;
					no_urut--;
					break;
				}
				bantu = bantu->next;
			}
			gotoxy(40,9);cout<<"|                                   |";
			gotoxy(40,10);cout<<"-------------------------------------";
			if(found) {gotoxy(41,9);cout<<"    ==DATA TELAH DIPERBARUI==      ";}
			else {gotoxy(41,9);cout<<"     ==PEMBARUAN DATA GAGAL==      ";}
			gotoxy(40,11);getch();
		}
		else{
			head=tail=NULL;
			no_urut--;
		}
	}
	else{
		gotoxy(40,6);cout<<"==DATA KOSONG==\n";	
		gotoxy(40,7);getch();
	} 
}

//========================================================================= DISPLAY
void ctk_mundur(){
	system("cls");
	if (head != NULL){
		cout <<"CETAK MUNDUR (DESCENDING):\n";
		int no=no_urut;
		Node *bantu = tail;
		while(bantu != NULL){
			cout <<"=====================================\n";
	    	cout <<no<<".)\t"
						<<bantu->nama<<"\n"
						<<"\t"<<bantu->umur<<" tahun\n";
			no--;
			bantu = bantu->prev;
		} 
		cout <<"=====================================\n";	
	}
	else cout <<"DATA KOSONG\n";
	getch();
}
void ctk_maju(){
	system("cls");
		if (head != NULL){
		cout <<"CETAK MAJU (ASCENDING):\n";
		int no=1;
		Node *bantu = head;
		while(bantu != NULL){
			cout <<"=====================================\n";
	    	cout <<no<<".)\t"
						<<bantu->nama<<"\n"
						<<"\t"<<bantu->umur<<" tahun\n";
			no++;
			bantu = bantu->next;
		} 
		cout <<"=====================================\n";
	}
	else cout <<"DATA KOSONG\n";
	getch();
}

//========================================================================= MAIN
void inputan(){
	gotoxy(40,1);cout<<"             INPUT DATA:             ";
	gotoxy(40,2);cout<<"-------------------------------------";
	gotoxy(40,3);cout<<"| Nama :                            |";
	gotoxy(40,4);cout<<"| Umur :                            |";
	gotoxy(40,5);cout<<"-------------------------------------";

}
int main(){
	string pilih;
	bool exit = false;
	do{
		fflush(stdin);
		system("cls");
		cout<<"-------------------------------------"<<endl;
		cout<<"========== PROGRAM DLL-NC ==========="<<endl;
		cout<<"-------------------------------------"<<endl;
		cout<<"|            TAMBAH DATA            |"<<endl;
		cout<<"| 1. Menambah Data Di Belakang      |"<<endl;
		cout<<"| 2. Menambah Data Di Depan         |"<<endl;
		cout<<"| 3. Menambah Data Setelah          |"<<endl;
		cout<<"| 4. Menambah Data Sebelum          |"<<endl;
		cout<<"|                                   |"<<endl;
		cout<<"|            HAPUS DATA             |"<<endl;
		cout<<"| 5. Menghapus Data Di Belakang     |"<<endl;
		cout<<"| 6. Menghapus Data Di Depan        |"<<endl;
		cout<<"| 7. Menghapus Data Setelah         |"<<endl;
		cout<<"| 8. Menghapus Data Sebelum         |"<<endl;
		cout<<"| 9. Menghapus Data di Mana Saja    |"<<endl;
		cout<<"|                                   |"<<endl;
		cout<<"|          TAMPILKAN DATA           |"<<endl;
		cout<<"| A. Menampilkan Data Dari Depan    |"<<endl;
		cout<<"| B. Menampilkan Data Dari Belakang |"<<endl;
		cout<<"|                                   |"<<endl;
		cout<<"| C. Keluar Program                 |"<<endl;
		cout<<"-------------------------------------"<<endl;
		inputan();
		gotoxy(36,22);cout<<"|";
		gotoxy(0,23);cout<<"-------------------------------------"<<endl;
		gotoxy(0,22);cout<<"| Masukkan Pilihan ==> "; getline(cin, pilih);
		cout<<"\n";
		
		if(pilih=="1") tmbh_belakang();
		if(pilih=="2") tmbh_depan();
		if(pilih=="3") tmbh_setelah();
		if(pilih=="4") tmbh_sebelum();
		if(pilih=="5") hps_belakang();
		if(pilih=="6") hps_depan();
		if(pilih=="7") hps_setelah();
		if(pilih=="8") hps_sebelum();
		if(pilih=="9") hps_bebas();
		if(pilih=="A" || pilih=="a") ctk_maju();
		if(pilih=="B" || pilih=="b") ctk_mundur();
		if(pilih=="C" || pilih=="c") exit = true;
	}
	while(exit!=true);
	return 0;
}
