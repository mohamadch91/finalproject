#include <stdio.h>
#include "aras.h"
#include <time.h>

enum blocks {
    ENERGY = 1, MITOSIS, FORBIDDEN, NORMAL
};

//map jadid 2 ta khone energy 2 ta khone taghsim 1 khone block va 4*4
void map(FILE *fp) {
    enum blocks mamad=ENERGY;
    struct Node *aras1 = NULL;
    int x, y;
    int counter, counter1 = 0, counter2 = 0, counter3 = 0;

    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            int type;
            type = rand() % 4 + 1;
            switch (type) {
                case 1:
                    if (counter1 > 2) {
                        while (type == mamad) { type = rand() % 4 + 1; }

                    }
                    pushBack(&aras1, x, y, 100, '1');
                    counter1++;
                    break;
                case 2:
                    if (counter2 > 2) {
                        while (type == mamad+1) {
                            type = rand() % 4 + 1;
                        }
                    }
                    pushBack(&aras1, x, y, 0, '2');
                    counter2++;
                    break;
                case 3:
                    if (counter3 > 1) {
                        while (type == mamad+2) { type = rand() % 4 + 1; }
                    }
                    pushBack(&aras1, x, y, 0, '3');
                    counter3++;
                    break;
                case 4:
                    pushBack(&aras1, x, y, 0, '4');
            }
        }
    }
    int i = 4;
    fwrite(&i, sizeof(int), 1, fp);
    struct Node *curr = aras1;
    for (int mamad = 0; mamad < 16; mamad++) {
        while (curr != NULL) {
            fwrite(&(curr->type), sizeof(char), 1, fp);
            curr = curr->next;
        }
    }
}

int main() {
    srand(time(NULL));
    FILE *fp;
    fp = fopen("mamad.bin", "wb");
    if(fp == NULL){
        return -1;
    }
    map(fp);
    printf("%s","hi khobi");
    fclose(fp);

    return 0;
}