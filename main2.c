#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "bintree.h"

void BuildMorseTree(BinTree *P) {
    // Level 5
    BinTree n5 = Tree('5', Nil, Nil);
    BinTree n4 = Tree('4', Nil, Nil);
    BinTree n3 = Tree('3', Nil, Nil);
    BinTree n2 = Tree('2', Nil, Nil);
    BinTree n1 = Tree('1', Nil, Nil);
    BinTree n6 = Tree('6', Nil, Nil);
    BinTree n7 = Tree('7', Nil, Nil);
    BinTree n8 = Tree('8', Nil, Nil);
    BinTree n9 = Tree('9', Nil, Nil);
    BinTree spasi = Tree(' ', Nil, Nil);

    // Level 4
    BinTree H = Tree('H', n5, n4);
    BinTree V = Tree('V', Nil, n3);
    BinTree F = Tree('F', Nil, Nil);
    BinTree empty1 = Tree('\0', Nil, n2);
    BinTree L = Tree('L', Nil, Nil);
    BinTree empty2 = Tree('\0', spasi, Nil);
    BinTree P_ = Tree('P', Nil, Nil);
    BinTree J = Tree('J', Nil, n1);
    BinTree B = Tree('B', n6, Nil);
    BinTree X = Tree('X', Nil, Nil);
    BinTree C = Tree('C', Nil, Nil);
    BinTree Y = Tree('Y', Nil, Nil);
    BinTree Z = Tree('Z', n7, Nil);
    BinTree Q = Tree('Q', Nil, Nil);
    BinTree n0 = Tree('0', n8, Nil);
    BinTree empty3 = Tree('\0', n9, Nil);

    
    // Level 3
    BinTree S = Tree('S', H, V);
    BinTree U = Tree('U', F, empty1);
    BinTree R = Tree('R', L, empty2);
    BinTree W = Tree('W', P_, J);
    BinTree D = Tree('D', B, X);
    BinTree K = Tree('K', C, Y);
    BinTree G_ = Tree('G', Z, Q);
    BinTree O = Tree('O', n0, empty3);
    
    // Level 2
    BinTree I = Tree('I', S, U);
    BinTree A = Tree('A', R, W);
    BinTree N = Tree('N', D, K);
    BinTree M = Tree('M', G_, O);

    // Level 1
    BinTree E = Tree('E', I, A);
    BinTree T = Tree('T', N, M);

    // Root / Level 0
    *P = Tree('#', E, T);
}

int BuildMorseCode(BinTree root, BinTree target, char *path, int depth) {
    if (root == Nil) return 0;
    if (root == target) {
        path[depth] = '\0';
        return 1;
    }
    if (BuildMorseCode(Left(root), target, path, depth + 1)) {
        path[depth] = '.';
        return 1;
    }
    if (BuildMorseCode(Right(root), target, path, depth + 1)) {
        path[depth] = '-';
        return 1;
    }
    return 0;
}

int main() {
    BinTree morseTree = Nil;
    BuildMorseTree(&morseTree);

    char input[256];
    printf("Masukkan kata/kalimat: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    printf("Morse: ");

    int i;
    for (i = 0; i < strlen(input); i++) {
        char ch = toupper(input[i]);
        address node = BinSearch(morseTree, ch);
        if (node != Nil) {
            char code[10];
            BuildMorseCode(morseTree, node, code, 0);
            printf("%s  ", code);
        }
    }

    return 0;
}