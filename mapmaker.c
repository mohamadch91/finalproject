#include <stdio.h>
#include "aras.h"
#include <time.h>

enum blocks {
    ENERGY = 1, MITOSIS, FORBIDDEN, NORMAL
};
void map1(FILE *fp) {
    int size;
    printf("please enter size");
    scanf("%d",&size);
    printf("how many energy cells you want?");
    int energy;
    scanf("%d",&energy);
    printf("how many mitosits cell you want?");
    int mitosits;
    scanf("%d",&mitosits);
    printf("how many forbidden cells you want?");
    int block;
    scanf("%d",block);
    enum blocks mamad=ENERGY;
    struct Node *aras1 = NULL;
    int x, y;
    int counter, counter1 = 0, counter2 = 0, counter3 = 0;
    for (y = 0; y < size; y++) {
        for (x = 0; x < size; x++) {
            int type;
            type = rand() % 4 + 1;
            char type1='4';

            switch (type) {
                case 1:
                    if (counter1 > energy) {
                        while (type == 1) { type = rand() % 4 + 1; }

                    switch(type){
                    case 1:
                    type1='1';
                    break;
                    case 2:
                    type1='2';
                    break;
                    case 3:
                    type1='3';
                    break;
                    case 4:
                    type1='4';}}
                    pushBack(&aras1, x, y, 100, type1,"energ");
                    counter1++;
                    break;
                case 2:
                    if (counter2 > mitosits) {
                        while (type == 2) {
                            type = rand() % 4 + 1;
                        }

                    switch(type){
        case 1:
            type1='1';
            break;
        case 2:
            type1='2';
            break;
        case 3:
            type1='3';
            break;
        case 4:
            type1='4';}}
//
//}
                    pushBack(&aras1, x, y, 0, type1,"mitos");
                    counter2++;
                    break;
                case 3:
                    if (counter3 > block) {
                        while (type == 3) { type = rand() % 4 + 1; }

                    switch(type){
        case 1:
            type1='1';
            break;
        case 2:
            type1='2';
            break;
        case 3:
            type1='3';
            break;
        case 4:
            type1='4';}}
                    pushBack(&aras1, x, y, 0, type1,"forb");
                    counter3++;
                    break;
                case 4:
                    pushBack(&aras1, x, y, 0, type1,"norm");
            }
        }
    }
    int i = size;
    fwrite(&i, sizeof(int), 1, fp);
    struct Node *curr = aras1;
    for (int mamad = 0; mamad < size*size; mamad++) {
        while (curr != NULL) {
            fwrite(&(curr->type), sizeof(unsigned char), 1, fp);
            curr = curr->next;
        }
    }
}
int main() {
    srand(time(NULL));
    FILE *fp;
    fp = fopen("newmap.bin", "wb");
    if(fp == NULL){
        return -1;}
    map1(fp);
    fclose(fp);
    return 0;
}
