//
// Created by Mohammad on ۲۵/۰۱/۲۰۲۰.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "aras.h"


int main() {
    srand(time(0));

    FILE *fp = fopen("mamad.bin", "rb");
    int size;
    struct Node *aras2 = NULL;
    int taghsim = 0, block = 0, energy = 0, normal = 0;
    fread(&size, sizeof(int), 1, fp);
    struct Node1 aras3[size*size];
    char arr[size][size];
    int size1 = size * size;
    char *location;
    location = readmap(fp);
    fclose(fp);
    int counter;
    char counter1 ;
    for (counter = 0; counter < size1; counter++) {
        counter1 = location[counter];
        switch (counter1) {
            case '1':
                aras3[counter].energy=100;
                aras3[counter].type=1;
                energy++;
                break;
            case '2':
                aras3[counter].energy=0;
                aras3[counter].type=2;
                taghsim++;
                break;
            case '3':
                aras3[counter].energy=0;
                aras3[counter].type=3;
                block++;
                break;
            case '4':
                aras3[counter].energy=0;
                aras3[counter].type=4;
                normal++;
                break;
        }
    }
    while (1) {
        int i, j;
        int cell, cell1;
        i = showmap();
        switch (i) {
            case 1:
                break;
            case 2:
                printf("HOw many cells do you want?");
                scanf("%d", &cell);
                while (cell > normal) {
                    printf("HOw many cells do you want?");
                    scanf("%d", &cell);
                }
                flocation(cell, size, arr, location, aras2);
                while (1) {
                    int j,x;
                    cell1 = movemenu(aras2);
                    j = mainmove();
                    switch (j) {
                        case 1:
                            x = movenodemenu();
                            movenode(&aras2, cell1, x, size, arr);
                        case 2:


                        case 5:
                            return 0;
                    }
                }
            case 3:
                break;
            case 4:
                return 0;
        }

    }

}