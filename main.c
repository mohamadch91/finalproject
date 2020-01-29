//
// Created by Mohammad on ۲۵/۰۱/۲۰۲۰.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "aras.h"



int main() {
    srand(time(0));
    FILE *fp = fopen("map.bin", "rb");
    int size;
    int aras25;
    struct Node *aras2 = NULL;
    struct Node *aras12=NULL;
    int taghsim = 0, block = 0, energy = 0, normal = 0;
    fread(&size, sizeof(int), 1, fp);
    int visualmap[size*size][size];
    struct Node1 aras3[size * size];
    char arr[size][size];
    int size1 = size * size;

    char location[size1];
    int location1[size1];
    fread(location, sizeof(char), size1, fp);
//    char aras79;
    for (int counter1379 = 0; counter1379 <size1 ; ++counter1379) {
        fread(&location, sizeof(char), size1, fp);
        location1[counter1379]=(int)(location[counter1379])-(int)('0');
//        printf("%d\n",location1[counter1379]);
}
    fclose(fp);
    int counter;
    char counter1;
    for (counter = 0; counter < size1; counter++) {
        counter1 = location1[counter];
//        printf("%u",counter1);
        switch (counter1) {
            case 1:
//                printf("hi");
                aras3[counter].energy = 100;
                aras3[counter].type = 1;
                energy++;
//                printf("hi");
                break;
            case 2:
                aras3[counter].energy = 0;
                aras3[counter].type = 2;
                taghsim++;
                break;
            case 3:
                aras3[counter].energy = 0;
                aras3[counter].type = 3;
                block++;
                break;
            case 4:
                aras3[counter].energy = 0;
                aras3[counter].type = 4;
                normal++;
                break;
        }
    }
// printf("%d\n,%d\n,%d\n,%d\n",energy,block,normal,taghsim);
    while (1) {
        int i, j,aras25;
        int cell, cell1,cell2;
        i = showmap();
        FILE *fp1;
        fp1=fopen("save.bin","rb");
        switch (i) {
            case 1:
                load(fp1,aras3,&aras2,size);
                i=showmap();
            case 2:
                printf("HOw many cells do you want?");
                scanf("%d", &cell);
                while (cell > normal) {
                    printf("your cells number are high\n");
                    printf("HOw many cells do you want?\n");
                    scanf("%d", &cell);
                }
                flocation(cell, size, arr, location, &aras2);
                map(size,visualmap,arr);
                while (1) {
                    int j, x;
//                    printf("on\n");
                    cell1 = movemenu(aras2);
                    j = mainmove();
                    FILE *fp2;
                    fp2=fopen("save.bin","wb");
                    switch (j) {
                        case 1:
                            x = movenodemenu();
                            movenode(&aras2, cell1, x, size, arr,aras3);
//                            movemenu(aras2);
                            map(size,visualmap,arr);
                            break;
                        case 2:
                            splitcell(cell, &aras2,size,arr);
                            map(size,visualmap,arr);
                            break;
                        case 3:
                            boostenergy(&aras2, cell1, aras3,size);
                            map(size,visualmap,arr);
                            break;
                        case 4:
                            save(fp2,aras3,aras2,size,cell);
                            map(size,visualmap,arr);
                            break;
                        case 5:
                            return 0;
                    }
                    fclose(fp);
                }
            case 3:
                printf("HOw many cells do you want(fp)?");
                scanf("%d", &cell);
                while (cell > normal) {
                    printf("HOw many cells do you want?");
                    scanf("%d", &cell);
                }
                printf("HOw many cells do you want?");
                scanf("%d", &cell2);
                while (cell > normal) {
                    printf("HOw many cells do you want(sp)?");
                    scanf("%d", &cell2);
                }
                flocation(cell, size, arr, location, aras2);
                flocation(cell2,size,arr,location,aras12);
//                map(size,visualmap,arr);
                int counter55=0;
                while (1) {
                    if(counter55%2==0){
                    int j, x,x1,cell11;
                    cell11 = movemenu(aras2);
                    j = mainmove();
                    FILE *fp;
                    fp=fopen("save.bin","wb");
                    switch (j) {
                        case 1:
                            x = movenodemenu();
                            movenode(&aras2, cell11, x, size, arr,aras3);
//                            map(size,visualmap,arr);
                            break;
                        case 2:
                            splitcell(cell, &aras2,size,arr);
//                            map(size,visualmap,arr);
                            break;
                        case 3:
                            boostenergy(&aras2, cell11, aras3,size);
//                            map(size,visualmap,arr);
                            break;
                        case 4:
                            save(fp,aras3,aras2,size,cell);
                            break;
                        case 5:
                            return 0;
                    }
                    fclose(fp);
                }
                    else{
                        int j, x,x1,cell11;
                        cell11 = movemenu(aras12);
                        j = mainmove();
                        FILE *fp;
                        fp=fopen("save.bin","wb");
                        switch (j) {
                            case 1:
                                x = movenodemenu();
                                movenode(&aras12, cell11, x, size, arr,aras3);
//                                map(size,visualmap,arr);
                                break;
                            case 2:
                                splitcell(cell, &aras12,size,arr);
//                                map(size,visualmap,arr);
                                break;
                            case 3:
                                boostenergy(&aras12, cell11, aras3,size);
//                                map(size,visualmap,arr);
                                break;
                            case 4:
                                save(fp,aras3,aras12,size,cell2);
                                break;
                            case 5:
                                return 0;
                        }
                        fclose(fp);

                    }
                    counter55++;
                }

            case 4:
                return 0;
        }

    }
return 0;
}
