#include "bintree.h"
#include <stdlib.h>
#include "queue.h"

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

boolean IsBiner(BinTree P) {
    return (P != Nil && Left(P) != Nil && Right(P) != Nil);
}

boolean IsEmpty(BinTree P) {
    return (P == Nil);
}

void PreOrder(BinTree P) {
    if (P != Nil) {
        printf("%d ", Info(P));
        PreOrder(Left(P));
        PreOrder(Right(P));
    }
}

void InOrder(BinTree P) {
    if (P != Nil) {
        InOrder(Left(P));
        printf("%d ", Info(P));
        InOrder(Right(P));
    }
}

void PostOrder(BinTree P) {
    if (P != Nil) {
        PostOrder(Left(P));
        PostOrder(Right(P));
        printf("%d ", Info(P));
    }
}

void PrintTree(BinTree P, int h) {
    int i;
    if (P != Nil) {
        PrintTree(Right(P), h + 1);
        for (i = 0; i < h; i++) printf("  ");
        printf("%d\n", Info(P));
        PrintTree(Left(P), h + 1);
    }
}

boolean Search(BinTree P, infotype X) {
    if (P == Nil) return false;
    if (Info(P) == X) return true;
    return (Search(Left(P), X) || Search(Right(P), X));
}

int nbElmt(BinTree P) {
    if (P == Nil) return 0;
    return 1 + nbElmt(Left(P)) + nbElmt(Right(P));
}

int nbDaun(BinTree P) {
    if (P == Nil) return 0;
    if (Left(P) == Nil && Right(P) == Nil) return 1;
    return nbDaun(Left(P)) + nbDaun(Right(P));
}

int Level(BinTree P, infotype X) {
    if (P == Nil) return 0;
    if (Info(P) == X) return 1;
    int leftLevel = Level(Left(P), X);
    if (leftLevel > 0) return 1 + leftLevel;
    int rightLevel = Level(Right(P), X);
    if (rightLevel > 0) return 1 + rightLevel;
    return 0;
}

int Depth(BinTree P) {
    if (P == Nil) return 0;
    return 1 + Max(Depth(Left(P)), Depth(Right(P)));
}

int Max(infotype Data1, infotype Data2) {
    return (Data1 > Data2) ? Data1 : Data2;
}

void AddDaunTerkiri(BinTree *P, infotype X) {
    if (*P == Nil) {
        *P = Alokasi(X);
    } else {
        AddDaunTerkiri(&Left(*P), X);
    }
}

void AddDaun(BinTree *P, infotype X, infotype Y, boolean Kiri) {
    if (*P != Nil && Info(*P) == X) {
        if (Kiri && Left(*P) == Nil) {
            Left(*P) = Alokasi(Y);
        } else if (!Kiri && Right(*P) == Nil) {
            Right(*P) = Alokasi(Y);
        }
    } else {
        if (Left(*P) != Nil) AddDaun(&Left(*P), X, Y, Kiri);
        if (Right(*P) != Nil) AddDaun(&Right(*P), X, Y, Kiri);
    }
}

void DelDaunTerkiri(BinTree *T, infotype *X) {
    if (*T != Nil) {
        if (Left(*T) == Nil && Right(*T) == Nil) {
            *X = Info(*T);
            DeAlokasi(*T);
            *T = Nil;
        } else {
            DelDaunTerkiri(&Left(*T), X);
        }
    }
}

void DelDaun(BinTree *T, infotype X) {
    if (*T != Nil) {
        if (Left(*T) != Nil && Info(Left(*T)) == X && Left(Left(*T)) == Nil && Right(Left(*T)) == Nil) {
            DeAlokasi(Left(*T));
            Left(*T) = Nil;
        } else if (Right(*T) != Nil && Info(Right(*T)) == X && Left(Right(*T)) == Nil && Right(Right(*T)) == Nil) {
            DeAlokasi(Right(*T));
            Right(*T) = Nil;
        } else {
            DelDaun(&Left(*T), X);
            DelDaun(&Right(*T), X);
        }
    }
}

ListOfNode MakeListDaun(BinTree P) {
    ListOfNode L = Nil;
    if (P != Nil) {
        if (Left(P) == Nil && Right(P) == Nil) {
            address1 New = (address1)malloc(sizeof(ElmtList));
            if (New != Nil) {
                InfoList(New) = Info(P);
                Next(New) = L;
                L = New;
            }
        }
        L = MakeListDaun(Left(P));
        L = MakeListDaun(Right(P));
    }
    return L;
}

ListOfNode MakeListPreOrder(BinTree P) {
    ListOfNode L = Nil;
    if (P != Nil) {
        address1 New = (address1)malloc(sizeof(ElmtList));
        if (New != Nil) {
            InfoList(New) = Info(P);
            Next(New) = L;
            L = New;
        }
        L = MakeListPreOrder(Left(P));
        L = MakeListPreOrder(Right(P));
    }
    return L;
}

ListOfNode MakeListLevel(BinTree P, int N) {
    ListOfNode L = Nil;
    if (P != Nil) {
        if (N == 1) {
            address1 New = (address1)malloc(sizeof(ElmtList));
            if (New != Nil) {
                InfoList(New) = Info(P);
                Next(New) = L;
                L = New;
            }
        }
        L = MakeListLevel(Left(P), N - 1);
        L = MakeListLevel(Right(P), N - 1);
    }
    return L;
}

boolean BSearch(BinTree P, infotype X) {
    return Search(P, X);
}

address BinSearch(BinTree P, infotype X) {
    if (P == Nil || Info(P) == X) return P;
    address leftResult = BinSearch(Left(P), X);
    if (leftResult != Nil) return leftResult;
    return BinSearch(Right(P), X);
}

void InsSearch(BinTree *P, infotype X) {
    if (*P == Nil) {
        *P = Alokasi(X);
    } else if (X < Info(*P)) {
        InsSearch(&Left(*P), X);
    } else if (X > Info(*P)) {
        InsSearch(&Right(*P), X);
    }
}

void DelBTree(BinTree *P, infotype X) {
    if (*P != Nil) {
        if (Info(*P) == X) {
            if (Left(*P) == Nil) {
                address temp = *P;
                *P = Right(*P);
                DeAlokasi(temp);
            } else if (Right(*P) == Nil) {
                address temp = *P;
                *P = Left(*P);
                DeAlokasi(temp);
            } else {
                address successor = Left(*P);
                while (Right(successor) != Nil) successor = Right(successor);
                Info(*P) = Info(successor);
                DelBTree(&Left(*P), Info(successor));
            }
        } else if (X < Info(*P)) {
            DelBTree(&Left(*P), X);
        } else {
            DelBTree(&Right(*P), X);
        }
    }
}

void DelNode(BinTree *P) {
    if (*P != Nil && Left(*P) == Nil && Right(*P) == Nil) {
        DeAlokasi(*P);
        *P = Nil;
    }
}

void DeAlokasi(address P) {
    free(P);
}

void LevelOrder(BinTree P) {    
    if (IsEmpty(P)) {
        printf("Pohon kosong\n");
        return;
    }
    
    Queue q;
    initQueue(&q);
    enqueue(&q, P);
    
    while (!isEmptyQueue(q)) {
        address current = dequeue(&q);
        printf("%d ", Info(current));
        
        if (Left(current) != NULL) {
            enqueue(&q, Left(current));
        }
        if (Right(current) != NULL) {
            enqueue(&q, Right(current));
        }
    }
}
