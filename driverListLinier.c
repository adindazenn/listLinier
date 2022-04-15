/* File : driverListLinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer */
/* Representasi address dengan pointer */
/* infotype adalah integer */
/* NIM/Nama  : 24060120120012/Adinda Destifany Zenniar*/
/* Tanggal   : 26 Oktober 2021*/
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include "listLinier.h"

int main(){
    /*Kamus main*/
    List A,B,Aout,Con,A1,A2,C,Con1,B2,B1,B3;
    address P,Q,R;
    infotype X,Y;

    /*Algoritma*/
    CreateList(&A);
    if(ListEmpty(A)){
        printf("List kosong\n");
    }
    else{
        printf("List tidak kosong\n");
    }

    P=Alokasi(1);
    InsertFirst(&A,P);
    printf("=====Insert First=====\n");
    PrintInfo(A);
    printf("\n");

    P=Alokasi(2);
    InsertFirst(&A,P);
    printf("=====Insert First=====\n");
    PrintInfo(A);
    printf("\n");

    R=Alokasi(3);
    InsertLast(&A,R);
    printf("=====Insert Last=====\n");
    PrintInfo(A);
    printf("\n");

    Q=Alokasi(4);
    InsertAfter(&A,Q,P);
    printf("=====Insert After=====\n");
    PrintInfo(A);
    printf("\n");

    printf("rata-rata A = %f\n", Average(A));
    printf("\n");

    printf("jumlah elemen list = %d\n", NbElmt(A));
    printf("\n");

    printf("Alamat elemen 4 = %x\n", Search(A, 4));
    printf("\n");

    printf("Alamat elemen 5 = %x\n", Search(A, 5));
    printf("\n");

    printf("Alamat sebelum elemen 4 = %x\n", SearchPrec(A, 4));
    printf("\n");

    printf("Alamat sebelum elemen 2 = %x\n", SearchPrec(A, 2));
    printf("\n");

    if(FSearch(A, R)){
        printf("ada elemen beralamat R\n");
    }
    else{
        printf("tidak ada elemen beralamat R\n");
    }
    printf("\n");

    DelFirst(&A,&P);
    printf("=====Del First=====\n");
    PrintInfo(A);
    printf("P=%d\n",info(P));
    printf("\n");

    DelLast(&A,&P);
    printf("=====Del Last=====\n");
    PrintInfo(A);
    printf("\n");

    DelAfter(&A,&P,First(A));
    printf("=====Del After=====\n");
    PrintInfo(A);
    printf("\n");

    InsVFirst(&A,5);
    printf("=====Ins V First=====\n");
    PrintInfo(A);
    printf("\n");

    InsVLast(&A,3);
    printf("=====Ins V Last=====\n");
    PrintInfo(A);
    printf("\n");

    InsVAfter(&A,5);
    printf("=====Ins V After=====\n");
    PrintInfo(A);
    printf("\n");

    DelVFirst(&A,&Y);
    printf("=====Del V First=====\n");
    PrintInfo(A);
    printf("Y=%d\n",Y);
    printf("\n");

    DelVLast(&A,&Y);
    printf("=====Del V Last=====\n");
    PrintInfo(A);
    printf("Y=%d\n",Y);
    printf("\n");

    DelVAfter(&A,&Y);
    printf("=====Del V After=====\n");
    PrintInfo(A);
    printf("Y=%d\n",Y);
    printf("\n");

    InsVFirst(&A,5);
    InsVFirst(&A,4);
    PrintInfo(A);
    printf("\n");

    DelAll(&A);
    printf("=====DelAll=====\n");
    PrintInfo(A);
    printf("\n");

    InsVFirst(&A, 1);
    InsVFirst(&A, 2);
    InsVFirst(&A, 3);
    InsVFirst(&A, 4);
    printf("=====List A=====\n");
    PrintInfo(A);
    printf("\n");

    printf("=====F Copy List=====\n");
    PrintInfo(FCopyList(A));
    printf("\n");

    printf("=====Copy List=====\n");
    CreateList(&C);
    CopyList(&A,&C);
    PrintInfo(C);
    printf("\n");

    printf("=====CP Alok List=====\n");
    CreateList(&Aout);
    CpAlokList(A,&Aout);
    printf("=====List Aout=====\n");
    PrintInfo(Aout);
    printf("\n");

    PrintInfo(A);
    InversList(&A);
    printf("=====Inverse List=====\n");
    PrintInfo(A);
    printf("\n");

    PrintInfo(A);
    printf("=====F Inverse List=====\n");
    PrintInfo(FInversList(A));
    printf("\n");

    CreateList(&Con);
    CreateList(&B);

    InsVFirst(&B,5);
    InsVFirst(&B,6);

    printf("=====List A=====\n");
    PrintInfo(A);
    printf("=====List B=====\n");
    PrintInfo(B);
    printf("\n");

    printf("=====Konkat=====\n");
    Konkat(A,B,&Con);
    PrintInfo(Con);
    printf("\n");

    printf("=====Konkat 1=====\n");
    Konkat1(&A,&B,&Con1);
    PrintInfo(Con1);
    printf("\n");

    printf("=====List A=====\n");
    PrintInfo(A);
    printf("=====List B=====\n");
    PrintInfo(B);
    printf("\n");

    InsVFirst(&Con,7);
    printf("=====Sebelum pecah list=====\n");
    PrintInfo(Con);
    printf("\n");

    CreateList(&A1);
    CreateList(&A2);
    PecahList(&A1,&A2,Con);
    printf("=====List A1=====\n");
    PrintInfo(A1);
    printf("=====List A2=====\n");
    PrintInfo(A2);
    printf("\n");

    printf("=====List C=====\n");
    PrintInfo(C);
    if(IsPolindrome(C)){
        printf("List C Polindrome\n");
    }
    else{
        printf("List C Bukan Polindrome\n");
    }
    printf("\n");

    InsVLast(&C,6);
    InsVLast(&C,4);
    printf("=====List C=====\n");
    PrintInfo(C);
    if(IsPolindrome(C)){
        printf("List C Polindrome\n");
    }
    else{
        printf("List C Bukan Polindrome\n");
    }
    printf("\n");

    DelAll(&C);
    PrintInfo(C);
    if(IsPolindrome(C)){
        printf("List C Polindrome\n");
    }
    else{
        printf("List C Bukan Polindrome\n");
    }
    printf("\n");

    InsVFirst(&C,5);
    PrintInfo(C);
    if(IsPolindrome(C)){
        printf("List C Polindrome\n");
    }
    else{
        printf("List C Bukan Polindrome\n");
    }
    printf("\n");

    CreateList(&B3);
    CreateList(&B1);
    CreateList(&B2);

    InsVLast(&B1,2);
    InsVLast(&B1,3);
    InsVLast(&B1,1);
    InsVLast(&B1,3);
    InsVLast(&B1,1);
    InsVLast(&B1,2);
    InsVLast(&B1,6);
    InsVLast(&B1,8);
    InsVLast(&B1,9);
    InsVLast(&B1,9);

    InsVLast(&B2,7);
    InsVLast(&B2,3);
    InsVLast(&B2,1);
    InsVLast(&B2,3);
    InsVLast(&B2,9);
    InsVLast(&B2,2);
    InsVLast(&B2,6);
    InsVLast(&B2,8);
    InsVLast(&B2,9);
    InsVLast(&B2,9);

    printf("=====List B1=====\n");
    PrintInfo(B1);
    printf("=====List B2=====\n");
    PrintInfo(B2);
    printf("\n");

    SumLargeNumber(B1,B2,&B3);
    printf("=====Sum Large Number=====\n");
    PrintInfo(B3);
    printf("\n");

    DelAll(&B1);
    DelAll(&B2);
    DelAll(&B3);

    InsVLast(&B1,2);
    InsVLast(&B1,3);
    InsVLast(&B1,1);
    InsVLast(&B1,3);
    InsVLast(&B1,1);
    InsVLast(&B1,2);
    InsVLast(&B1,6);
    InsVLast(&B1,8);
    InsVLast(&B1,9);
    InsVLast(&B1,9);

    InsVLast(&B2,7);
    InsVLast(&B2,3);
    InsVLast(&B2,1);
    InsVLast(&B2,3);
    InsVLast(&B2,9);
    InsVLast(&B2,2);
    InsVLast(&B2,6);
    InsVLast(&B2,8);
    InsVLast(&B2,9);
    InsVLast(&B2,9);

    printf("=====List B1=====\n");
    PrintInfo(B1);
    printf("=====List B2=====\n");
    PrintInfo(B2);
    printf("\n");

    MulLargeNumber(B1,B2,&B3);
    printf("=====Mul Large Number=====\n");
    PrintInfo(B3);

    return 0;
}
