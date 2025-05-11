#include "bintree.h"
#include <stdlib.h>

/* Konstruktor */
address Alokasi (infotype X) {
    address P = (address) malloc(sizeof(Node));
    if (P != Nil) {
        Info(P) = X;
        Left(P) = Nil;
        Right(P) = Nil;
    }
    return P;
}

BinTree Tree (infotype Akar, BinTree L, BinTree R) {
    address P = Alokasi(Akar);
    if (P != Nil) {
        Left(P) = L;
        Right(P) = R;
    }
    return P;
}

void MakeTree (infotype Akar, BinTree L, BinTree R, BinTree *P) {
    *P = Tree(Akar, L, R);
}