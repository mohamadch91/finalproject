//
// Created by Mohammad on ۲۵/۰۱/۲۰۲۰.
//
#include<stdio.h>
#include<stdlib.h>
#ifndef mapprint.h
#define mapprint.h
void printvmap( int size) {
    for (int i = 0; i < (size * 2 + 1) * 4 - 2; i++) {
        printf("\n");
        for (int j = 0; j < size * 6; j++) {
            if(j%6==0){
                printf(" ");
            }
            if (i == 0) {
                if ((j  >= 0 && j < 6)||(j >= 12 && j <= 17)){
                    printf("-");
                }
                else{
                    printf(" ");
                }
                continue;
            }
            else if (i == 2) {

                if (j == 0 || j == 5 || j == 12 || j == 17) {
                    printf("|");
                }
                else {
                    printf(" ");
                }
                continue;
            }
            else{
                int x = i % 8;
                int m;
                switch (x) {
                    case 0:
                        if ((j  >= 0 && j < 6)||(j >= 12 && j <= 17)){
                            printf("-");
                            break;
                        }
                        if(j==6||j==11||j==18||j==23){
                            printf("|");
                            break;
                        }
                        printf(" ");
                        break;
                    case 1:
                        m = j % 6;
                        if (m == 0 || m == 5) {
                            printf("|");
                        } else {
                            printf(" ");
                        }
                        break;
                    case 2:

                        if (j == 0 || j == 5 || j == 12 || j == 17) {
                            printf("|");
                        }
                        else if ((j >= 6 && j <= 11) || (j >= 18 && j <= 23)) {
                            printf("-");

                        } else {
                            printf(" ");
                        }
                        break;
                    case 3:
                        if (j == 0 || j == 4 || j == 12 || j == 17) {
                            printf("|");
                        }
                        if ((j >= 6 && j <= 11) || (j >= 18 && j <= 23)) {
                            printf("-");
                        } else {
                            printf(" ");
                        }
                        break;
                    case 4:
                        m = j % 6;
                        if (m == 0 || m == 5) {
                            printf("|");
                        } else {
                            printf(" ");
                        }
                        break;
                    case 5:
                        m = j % 6;
                        if (m == 0 || m == 5) {
                            printf("|");
                        } else {
                            printf(" ");
                        }
                        break;
                    case 6:
                        m = j % 6;
                        if (m == 0 || m == 5) {
                            printf("|");
                        } else {
                            printf(" ");
                        }
                        break;
                    case 7:
                        if ((j  >= 0 && j < 6)||(j >= 12 && j <= 17)){
                            printf("-");
                        }
                        if(j==6||j==11||j==18||j==23){
                            printf("|");
                        }
                        break;
                }
            }}
    }
}
int main(){
    printvmap(4);
    return 0;}

#endif //FINALPROJECT_MAPPRINT_H
