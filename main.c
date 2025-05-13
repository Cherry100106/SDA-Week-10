#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bintree.h"

void Menu();
void InsertNode(BinTree *tree);

int main() {
    BinTree tree = Nil;
    int pilihan;
    do {
        Menu();
        printf("Pilih menu: ");
        scanf("%d", &pilihan);
        getchar();

        switch (pilihan) {
            case 1:
                InsertNode(&tree);
                break;
            case 2:
                PrintTree(tree, 0);
                break;
            case 3:
                PreOrder(tree);
                printf("\n");
                break;
            case 4:
                InOrder(tree);
                printf("\n");
                break;
            case 5:
                PostOrder(tree);
                printf("\n");
                break;
            case 6: {
                int d = Depth(tree);
                int i;
                for (i = 1; i <= d; i++) {
                    ListOfNode L = MakeListLevel(tree, i);
                    while (L != Nil) {
                        printf("%d ", InfoList(L));
                        L = Next(L);
                    }
                }
                printf("\n");
                break;
            }
            case 7: {
                infotype x;
                printf("Masukkan info node yang dicari: ");
                scanf(" %d", &x);
                printf(Search(tree, x) ? "Node ditemukan\n" : "Node tidak ditemukan\n");
                break;
            }
            case 8:
                printf("Jumlah daun: %d\n", nbDaun(tree));
                break;
            case 9: {
                infotype x;
                printf("Masukkan info node: ");
                scanf(" %d", &x);
                printf("Kedalaman node %d adalah %d\n", x, Level(tree, x));
                break;
            }
            case 10: {
                infotype a, b;
                printf("Masukkan info node pertama: ");
                scanf(" %d", &a);
                printf("Masukkan info node kedua: ");
                scanf(" %d", &b);
                int max = Max(a, b);
                printf("Node dengan nilai lebih besar: %d\n", max);
                break;
            }
            case 11:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 11);

    return 0;
}

void Menu() {
    printf("\nMenu:\n");
    printf("1. Insert Node\n");
    printf("2. Print Tree\n");
    printf("3. Transversal PreOrder\n");
    printf("4. Transversal InOrder\n");
    printf("5. Transversal PostOrder\n");
    printf("6. Transversal LevelOrder\n");
    printf("7. Search Node Tree\n");
    printf("8. Jumlah Daun\n");
    printf("9. Mencari Kedalaman Node Tree\n");
    printf("10. Membandingkan 2 Node Tree\n");
    printf("11. Exit\n");
}

void InsertNode(BinTree *tree) {
    infotype x, parent;
    printf("Masukkan info node yang ingin ditambahkan: ");
    scanf("%d", &x);

    if (IsEmpty(*tree)) {
        *tree = Alokasi(x);
        printf("Node %d berhasil menjadi akar.\n", x);
    } else {
        printf("Masukkan info parent node: ");
        scanf("%d", &parent);
        address pNode = BinSearch(*tree, parent);

        if (pNode != Nil) {
            if (Left(pNode) == Nil || Right(pNode) == Nil) {
                char posisi[6];
                printf("Masukkan posisi anak (left/right): ");
                scanf("%s", posisi);

                if (strcmp(posisi, "left") == 0) {
                    if (Left(pNode) == Nil) {
                        Left(pNode) = Tree(x, Nil, Nil);
                        printf("Node %d ditambahkan sebagai left son dari %d\n", x, parent);
                    } else {
                        printf("Insert gagal: Left son sudah ada.\n");
                    }
                } else if (strcmp(posisi, "right") == 0) {
                    if (Right(pNode) == Nil) {
                        Right(pNode) = Tree(x, Nil, Nil);
                        printf("Node %d ditambahkan sebagai right son dari %d\n", x, parent);
                    } else {
                        printf("Insert gagal: Right son sudah ada.\n");
                    }
                } else {
                    printf("Posisi tidak valid. Gunakan 'left' atau 'right'.\n");
                }
            } else {
                printf("Insert gagal: Node %d sudah memiliki dua anak.\n", parent);
            }
        } else {
            printf("Parent tidak ditemukan dalam tree.\n");
        }
    }
}
