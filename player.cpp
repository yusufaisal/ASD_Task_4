#include "player.h"

void inputNewSong(infotype &x){
	/**
	* PR : meminta input user untuk mengisi nama dan lokasi file
	* FS : infotype x terisi nama dan lokasi file
	*/

    cout<<"input name song (.wav) : ";
    cin>>x.name;
    cout<<"input song location "<<endl<<"(write - for default location) :";
    cin>>x.location;
    if(x.location=="-"){x.location="";}
}


void printInfo(List L){
	/**
	* PR : menampilkan informasi ID, nama, dan lokasi file
	*/

    address Q = first(L);
    do
    {
        cout<<"name : "<<info(Q).name<<endl;
        cout<<"ID: "<<info(Q).ID<<endl;
        cout<<"location: "<<info(Q).location<<endl;
        Q = next(Q);
    } while(Q != first(L));
}


void playSong(address P){
	/**
	* PR : memainkan lagu yang ditunjuk oleh pointer P
	*/

    string filename = info(P).location+info(P).name;
    cout<<"playing "<<filename<<endl;
    PlaySound(TEXT(filename.c_str()), NULL, SND_FILENAME);
    _sleep(1000); //delay 1 second
}


void playNext(address &P){
	/**
	* PR : memainkan file lagu pada elemen setelah P
	* FS : P menunjuk next lagu dan lagu dimainkan
	*/
    P = next(P);
    playSong(P);
}


void playPrev(address &P){
	/**
	* PR : memainkan file lagu pada elemen sebelum P
	* FS : P menunjuk prev lagu dan lagu dimainkan
	*/
	//-------------your code here-------------
    P = prev(P);
    playSong(P);
    //----------------------------------------

}

void shuffleList(List &L){
	/**
	* PR : mengacak isi (elemen) dari list L
	* FS : isi (elemen) dari list teracak
	*/
	//-------------your code here-------------
    address P,R;
    deleteLast(L,R);
    insertFirst(L,R);
    P = next(first(L));
    deleteAfter(L,P,R);
    insertLast(L,R);
    P = next(P);
    deleteAfter(L,P,R);
    P = first(L);
    insertAfter(L,P,R);

    //----------------------------------------
}

void sortList(List &L, int condition){
	/**
	* PR : mengurutkan isi (elemen) dari list L berdasarkan kondisi
	* FS : isi (elemen) dari list L terurut
	*      jika kondisi = 1, sort by ID
	*      jika kondisi = 2, sort by nama
	*/
	//-------------your code here-------------
	address P,Q,R;
	if ((first(L)!=Nil)&&(first(L)!=last(L))){
        if (condition==1){
            P = next(first(L));
            do {
                Q = P;
                P = next(P);
                do {
                    if (info(Q).ID<info(prev(Q)).ID){
                        if (Q==last(L)){
                            Q=prev(Q);
                            deleteLast(L,R);
                        } else {
                            Q=prev(Q);
                            deleteAfter(L,Q,R);
                        }

                        if (Q==first(L)){
                            insertFirst(L,R);
                        } else {
                            insertAfter(L,prev(Q),R);
                        }
                    }
                    Q = prev(Q);
                }while(Q !=first(L));
            } while(P!=first(L));
        } else if (condition==2) {
            P = next(first(L));
            do {
                Q = P;
                P = next(P);
                do {
                    if (info(Q).name<info(prev(Q)).name){
                        if (Q==last(L)){
                            Q=prev(Q);
                            deleteLast(L,R);
                        } else {
                            Q=prev(Q);
                            deleteAfter(L,Q,R);
                        }

                        if (Q==first(L)){
                            insertFirst(L,R);
                        } else {
                            insertAfter(L,prev(Q),R);
                        }
                    }
                    Q = prev(Q);
                }while(Q !=first(L));
            } while(P!=first(L));
        }
	}


    //----------------------------------------

}

void playRepeat(List &L, int n){
	/**
	* PR : memainkan seluruh lagu di dalam list
	*      dari lagu pertama hingga terakhir sebanyak n kali
	*/
	//-------------your code here-------------
    int  i = 0;
    address P = first(L);
    do {
        playSong(P);
        P = next(P);
        if (P == first(L)) {
            i++;
        }
    } while (i<n);
    //----------------------------------------
}

void deleteSong(List &L){
	/**
	* IS : list L mungkin kosong
	* PR : menerima input user untuk ID lagu yang ingin dihapus
	*      jika ID lagu ditemukan, hapus (dealokasi) lagu dari list
	* FS : elemen dengan ID yang dicari didealokasi
	*/
	//-------------your code here-------------
	int in;
    address Prec, P;

    cout << "Delete by ID : ";
    cin >> in ;
    if (first(L)!=Nil){
        Prec= first(L);
        do{
            if (info(Prec).ID!=in){
                Prec = next(Prec);
            }

        } while ((info(Prec).ID!=in) && (Prec != first(L)));
    }
    if(info(Prec).ID==in) {
        Prec = prev(Prec);
        deleteAfter(L, Prec, P);
        dealokasi(P);

    }
    //----------------------------------------

}
