/* File : listLinier.c */
/* contoh ADT list berkait dengan representasi fisik pointer */
/* Representasi address dengan pointer */
/* infotype adalah integer */
/* NIM/Nama  : 24060120120012/Adinda Destifany Zenniar*/
/* Tanggal   : 26 Oktober 2021*/
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include "listLinier.h"

/*Prototype*/
/* ----- Test List Kosong ----- */
/* Mengirim true jika list kosong */
boolean ListEmpty (List L){
    /*Kamus lokal*/

    /*Algoritma*/
    return First(L)==Nil;
}

/* ----- Pembuatan List Kosong ----- */
/* I.S.		: sembarang
   F.S.		: Terbentuk list kosong */
void CreateList (List *L){
    /*Kamus lokal*/

    /*Algoritma*/
    First(*L)=Nil;
}

/* ----- Manajemen Memori ----- */
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil,
   dan misalnya menghasilkan P, maka
   Info(P) = X, Next(P) = Nil
   Jika alokasi gagal, mengirimkan Nil */
address Alokasi (infotype X){
    /*Kamus lokal*/
    address P;

    /*Algoritma*/
    P = (address) malloc(sizeof(ElmtList));
    if (P != Nil )
    {
        info(P) = X;
        next(P) = Nil;
    }
    return P;
}

/* I.S.		: P terdefinisi
   F.S.		: P dikembalikan ke sistem
   Melakukan dealokasi/pengembalian address P */
void Dealokasi (address *P){
    /*Kamus lokal*/

    /*Algoritma*/
    info(*P)=0;
    next(*P)=Nil;
    free(*P);
}

/* ----- Primitif Berdasarkan Alamat ------ */
/* Penambahan Elemen Berdasarkan Alamat */
/* I.S. 	: Sembarang, P sudah dialokasi
   F.S.		: Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertFirst (List *L, address P){
    /*Kamus lokal*/

    /*Algoritma*/
    next(P)=First(*L);
    First(*L)=P;
}

/* I.S.		: Prec pastilah elemen list dan bukan elemen terakhir,
			  P sudah dialokasi
   F.S. 	: Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertAfter (List *L, address P, address Prec){
    /*Kamus lokal*/

    /*Algoritma*/
    next(P)=next(Prec);
    next(Prec)=P;
}

/* I.S.		: Sembarang, P sudah dialokasi
   F.S.		: P ditambahkan sebagai elemen terakhir yang baru */
void InsertLast (List *L, address P){
    /*Kamus lokal*/
    address Last;

    /*Algoritma*/
    if(First(*L)==Nil){
        InsertFirst(&(*L),P);
    }
    else{
        Last=First(*L);
        while(next(Last)!=Nil){
            Last=next(Last);
        }
        InsertAfter(&(*L),P,Last);
    }
}

/* Penghapusan Sebuah Elemen */
/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen pertama list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              First element yang baru adalah suksesor elemen pertama yang
              lama */
void DelFirst (List *L, address *P){
    /*Kamus lokal*/

    /*Algoritma*/
    *P=First(*L);
    First(*L)=next(First(*L));
}

/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen terakhir list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              Last element baru adalah predesesor elemen pertama yang
              lama, jika ada */
void DelLast (List *L, address *P){
    /*Kamus lokal*/
    address Last, PrecLast;

    /*Algoritma*/
    Last=First(*L);
    PrecLast=Nil;
    while(next(Last)!=Nil){
        PrecLast=Last;
        Last=next(Last);
    }
    *P=Last;
    if(PrecLast==Nil){
        First(*L)=Nil;
    }
    else{
        next(PrecLast)=Nil;
    }
}

/* I.S.     : List tidak kosong. Prec adalah anggota list L.
   F.S.     : Menghapus Next(Prec :
              Pdel adalah alamat elemen list yang dihapus*/
void DelAfter (List *L, address * Pdel, address Prec){
    /*Kamus lokal*/

    /*Algoritma*/
    *Pdel=next(Prec);
    next(Prec)=next(next(Prec));
    next(*Pdel)=Nil;
}

/* ----- Primitif Berdasarkan Nilai ----- */
/* Penambahan Elemen */
/* I.S.		: L mungkin kosong
   F.S. 	: X ditambahkan sebagai elemen pertama L
   Proses 	: Melakukan alokasi sebuah elemen dan menambahkan elemen
   			  pertama dengan nilai X jika alokasi berhasil.
   			  Jika alokasi gagal, maka I.S.= F.S. */
void InsVFirst (List *L, infotype X){
    /*Kamus lokal*/
    address P;

    /*Algoritma*/
    P=Alokasi(X);
    if(P!=Nil){
        next(P)=First(*L);
        First(*L)=P;
    }
}

/* I.S. 	: L mungkin kosong
   F.S.		: X ditambahkan sebagai elemen terakhir L
   Proses 	: Melakukan alokasi sebuah elemen dan menambahkan elemen list
   			  di akhir yaitu
   			  jika alokasi berhasil, elemen terakhir yang baru bernilai X
   			  Jika alokasi gagal, maka I.S.= F.S. */
void InsVLast (List *L, infotype X){
    /*Kamus lokal*/
    address P;

    /*Algoritma*/
    P=Alokasi(X);
    if(P!=Nil){
        InsertLast(&(*L),P);
    }
}

/* I.S. 	: L mungkin kosong
   F.S.		: X ditambahkan sebagai elemen setelah Prec
   Proses 	: Melakukan alokasi sebuah elemen dan menambahkan elemen list
   			  setelah Prec yaitu
   			  jika alokasi berhasil, elemen setelah Prec yang baru bernilai X
   			  Jika alokasi gagal, maka I.S.= F.S. */
void InsVAfter (List *L, infotype X){
    /*Kamus lokal*/
    address P,Prec,Last;

    /*Algoritma*/
    if(!ListEmpty(*L)){
        AdrLast(&(*L),&Prec,&Last);
        P=Alokasi(X);
        if(P!=Nil){
            InsertAfter(&(*L),P,Prec);
        }
    }
    else{
        InsVFirst(&(*L),X);
    }
}

/*mencari alamat elemen terakhir dan sebelumnya*/
void AdrLast(List *L, address *Prec, address *Last){
    /*Kamus lokal*/

    /*Algoritma*/
    *Last=First(*L);
    *Prec=Nil;
    while(next(*Last)!=Nil){
        *Prec=*Last;
        *Last=next(*Last);
    }
}

/* Penghapusan ELemen */
/* I.S.		: List L tidak kosong
   F.S.		: Elemen pertama list dihapus den nilai info disimpan pada X
   			 dan alamat elemen pertama di-dealokasi */
void DelVFirst (List *L, infotype *X){
    /*Kamus lokal*/
    address P;

    /*Algoritma*/
    P=First(*L);
    *X=info(P);
    First(*L)=next(P);
    Dealokasi(&P);
}

/* I.S.		: List L tidak kosong
   F.S.		: Elemen terakhir list dihapus : nilai info disimpan pada X
   			  dan alamat elemen terakhir di-dealokasi */
void DelVLast (List *L, infotype *X){
    /*Kamus lokal*/
    address P;

    /*Algoritma*/
    DelLast(&(*L),&P);
    *X=info(P);
    Dealokasi(&P);
}

/* I.S.		: List L tidak kosong
   F.S.		: Elemen list setelah Prec dihapus : nilai info disimpan pada X
   			  dan alamat elemen setelah Prec di-dealokasi */
void DelVAfter (List *L, infotype *X){
    /*Kamus lokal*/
    address P, Prec, Last;

    /*Algoritma*/
    AdrLast(&(*L),&Prec,&Last);
    DelAfter(&(*L),&P,Prec);
    *X=info(P);
    Dealokasi(&P);
}

/* ----- Proses Semua Elemen List ----- */
/* I.S.     : List mungkin kosong
   F.S.     : Jika list tidak kosong, semua info yg disimpan pada elemen
              list diprint
              Jika list kosong, hanya menuliskan "list kosong" */
void PrintInfo (List L){
    /*Kamus lokal*/
    address P;

    /*Algoritma*/
    if(ListEmpty(L)){
        printf("list kosong\n");
    }
    else{
        P=First(L);
        while(P!=Nil){
            printf("%d ", info(P));
            P=next(P);
        }
        printf("\n");
    }
}

/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
int NbElmt (List L){
    /*Kamus lokal*/
    address P;
    int num;

    /*Algoritma*/
    num = 0;
    P = First(L);
    while(P!=Nil){
        num++;
        P = next(P);
    }
    return num;
}

address Search (List L, infotype X){
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

    /*Kamus lokal*/
    address P;

    /*Algoritma*/
    P=First(L);
    while(P!=Nil && X!=info(P)){
        P=next(P);
    }
    return P;
}

boolean FSearch (List L, address P){
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */

    /*Kamus lokal*/
    boolean Found;
    address Q;

    /*Algoritma*/
    Q=First(L);
    Found=false;
    while(Q!=Nil && Found==false){
        if(Q==P){
            Found=true;
        }
        else{
            Q=next(Q);
        }
    }
}

address SearchPrec (List L, infotype X){
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P */
/* dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain*/

    /*Kamus lokal*/
    address P;
    boolean Found;

    /*Algoritma*/
    P=First(L);
    if(info(P)==X){
        return Nil;
    }
    else{
        Found = false;
        while(next(P)!=Nil && Found==false){
            if(info(next(P))==X){
                Found = true;
            }
            else{
                P=next(P);
            }
        }
        return P;
    }
}

float Average (List L){
/* Mengirimkan nilai rata-rata info(P) */
    /*Kamus lokal*/
    address P;
    float jml, rata;

    /*Algoritma*/
    jml=0.0;
    P=First(L);
    while(P!=Nil){
        jml=jml+(float)info(P);
        P=next(P);
    }
    rata= jml/NbElmt(L);
    return rata;
}

void DelAll (List *L){
/* I.S. sembarang */
/* F.S. Delete semua elemen list dan alamat elemen di-dealokasi */
/*      List L menjadi list kosong */
    /*Kamus lokal*/
    address P;

    /*Algoritma*/
    while(!ListEmpty(*L)){
        DelFirst(&(*L),&P);
        Dealokasi(&P);
    }
}

void InversList (List *L){
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
    /*Kamus lokal*/
    address Cur, Prec, Next;

    /*Algoritma*/
    Cur = First(*L);
    Prec = Nil;
    while (Cur != Nil) {
        Next = next(Cur);
        next(Cur) = Prec;
        Prec = Cur;
        Cur = Next;
    }
    First(*L) = Prec;
}

List FInversList (List L){
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
    /*Kamus lokal*/
    address P,Q;
    List M;

    /*Algoritma*/
    CreateList(&M);
    P=First(L);
    while(P!=Nil){
        Q=Alokasi(info(P));
        if(Q!=Nil){
            InsertFirst(&M, Q);
            P=next(P);
        }
        else{
            DelAll(&M);
        }
    }
    return M;
}

void CopyList (List *L1, List *L2){
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */

    /*Kamus lokal*/

    /*Algoritma*/
    First(*L2)=First(*L1);
}

List FCopyList (List L ){
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */

    /*Kamus lokal*/
    address P,Q;
    List M;

    /*Algoritma*/
    CreateList(&M);
    P=First(L);
    while(P!=Nil){
        Q=Alokasi(info(P));
        if(Q!=Nil){
            InsertLast(&M,Q);
            P=next(P);
        }
        else{
            DelAll(&M);
        }
    }
    return M;
}

void CpAlokList (List Lin, List *Lout){
/* I.S. Lin sembarang. */
/* F.S. Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
/* Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* Lout adalah list kosong jika ada alokasi elemen yang gagal */

    /*Kamus lokal*/
    address P,Q;

    /*Algpritma*/
    P=First(Lin);
    while(P!=Nil){
        Q=Alokasi(info(P));
        if(Q!=Nil){
            InsertLast(&(*Lout),Q);
            P=next(P);
        }
        else{
            DelAll(&(*Lout));
        }
    }
}


void Konkat (List L1, List L2, List *L3){
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 */
/* Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi*/
/* Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi */
/* harus di-dealokasi dan L3=Nil*/
/* Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang “baru” */
/* Elemen L3 adalah hasil alokasi elemen yang “baru”. */
/* Jika ada alokasi yang gagal, maka L3 harus bernilai Nil*/
/* dan semua elemen yang pernah dialokasi didealokasi */

    /*kamus lokal*/

    /*Algoritma*/
    CpAlokList(L1,&(*L3));
    CpAlokList(L2,&(*L3));
}

void Konkat1 (List *L1, List *L2, List *L3){
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2 */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2)*/
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */

    /*Kamus lokal*/
    address last;

    /*Algoritma*/
    CreateList(&(*L3));
    First(*L3)=First(*L1);
    last=First(*L1);
    while(next(last)!=Nil){
        last=next(last);
    }
    next(last)=First(*L2);
    First(*L1)=Nil;
    First(*L2)=Nil;
}

void PecahList (List *L1, List *L2, List L){
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 */

    /*Kamus lokal*/
    address P,Q;
    int i;

    /*Algoritma*/
    P=First(L);
    for(i=1;i<=NbElmt(L)/2;i++){
        Q=Alokasi(info(P));
        if(Q!=Nil){
            InsertLast(&(*L1),Q);
            P=next(P);
        }
        else{
            DelAll(&(*L1));
        }
    }
    for(i=(NbElmt(L)/2)+1;i<=NbElmt(L);i++){
        Q=Alokasi(info(P));
        if(Q!=Nil){
            InsertLast(&(*L2),Q);
            P=next(P);
        }
        else{
            DelAll(&(*L2));
        }
    }
}

boolean IsPolindrome (List L){
/*Mengirikan nilai TRUE jika semua elemen list membentuk palindrome*/
/*List kosong, dan list 1 elemen TRUE*/

    /*Kamus lokal*/
    int i;
    address P,Q;
    boolean cek;
    List L1;

    /*Algoritma*/
    if(ListEmpty(L)){
        cek=true;
    }
    else{
        P=First(L);
        L1=FInversList(L);
        Q=First(L1);
        cek=true;
        for(i=1;i<=(NbElmt(L)/2)+1;i++){
            if(info(P) != info(Q)) {
                cek =false;
                i=NbElmt(L);
            }
            else{
                P = next(P);
                Q = next(Q);
            }
        }
    }
    return cek;
}

void SumLargeNumber (List L1, List L2, List *L){
/*Diketahui L1 dan L2 merupakan 2 buah bilangan integer large number*/
/*Buatlah algoritma program utama untuk menjumlahkan L1 dan L2 yang*/
/*hasilnya di simpan pada list baru L*/

    /*Kamus lokal*/
    address P,Q;
    int total, save, sum;

    /*Algoritma*/
    InversList(&L1);
    InversList(&L2);
    P = First(L1);
    Q = First(L2);
    save = 0;
    while(P!=Nil && Q!=Nil){
        total = save + info(P) + info(Q);
        sum = total%10;
        save = total/10;
        InsVFirst(&(*L),sum);
        P = next(P);
        Q = next(Q);
    }
    while(P!=Nil){
        total = save + info(P);
        sum = total%10;
        save = total/10;
        InsVFirst(&(*L),sum);
        P = next(P);
    }
    while(Q!=Nil){
        total = save + info(Q);
        sum = total%10;
        save = total/10;
        InsVFirst(&(*L),sum);
        Q = next(Q);
    }
}

void MulLargeNumber (List L1, List L2, List *L){
/*Diketahui L1 dan L2 merupakan 2 buah bilangan integer large number*/
/*Buatlah algoritma program utama untuk perkalian L1 dan L2 yang*/
/*hasilnya di simpan pada list baru L*/
    /*Kamus lokal*/
    address P,Q;
    unsigned long long int num1, num2, total;

    /*Algoritma*/
    num1=0;
    num2=0;
    P=First(L1);
    Q=First(L2);
    while(P!=Nil){
        num1=(num1*10)+info(P);
        P=next(P);
    }
    while(Q!=Nil){
        num2=(num2*10)+info(Q);
        Q=next(Q);
    }
    total=num1*num2;
    while(total!=Nil){
        InsVFirst(&(*L),total%10);
        total=total/10;
    }
}
