//
// Created by Mohammad on ۲۳/۰۱/۲۰۲۰.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef aras.h
#define aras.h
void map(int size, int aras79[size*size][size],char arr[size][size]){
    char *a[4]={"   ","___","/","\\"};
    char *b[1]={"   "};
    for(int i=1;i<=size;i++){
        if(i%2!=0){
            aras79[0][i]=a[1];
        }
        if(i%2==0){
            aras79[0][i]=a[0];
        }
        printf(" %s",aras79[0][i]);
    }

    printf("\n");
    for(int i=1;i<=2*size+1;i+=2){
        for(int j=1;j<=2*size+1;j++){
            if(j%4==1){
                aras79[i][j]=a[2];
            }
            if(j%4==2){
                aras79[i][j]=a[0];
            }
            if(j%4==3){
                aras79[i][j]=a[3];
            }
            if(j%4==0){
                aras79[i][j]=a[1];
            }
            if(size%2==0&&i==1){
                aras79[i][2*size+1]="";
            }
            if(i==2*size+1){
                aras79[i][1]=" ";
                aras79[i][2*size+1]="";
            }
            if(size%2==0&&i==2*size+1){
                aras79[2*size+1][2*size+1]="/";
            }
            printf("%s",aras79[i][j]);
        }
        printf("\n");
        for(int j=1;j<=2*size+1;j++){
            if(j%4==1){
                aras79[i+1][j]=a[3];
            }
            if(j%4==2){
                aras79[i+1][j]=a[1];
            }
            if(j%4==3){
                aras79[i+1][j]=a[2];
            }
            if(j%4==0){
                aras79[i+1][j]=a[0];
            }
            if(size%2==0&&i==2*size-1){
                aras79[i+1][2*size+1]="";
            }
            if(i==2*size+1){
                for(int k=1;k<=2*size+1;k++){
                    aras79[i+1][k]="";
                }
            }
            if(size%2==0&&i==2*size-1){
                aras79[2*size][2*size+1]="\\";
            }
            aras79[1][1]="a";
            printf("%s",aras79[i+1][j]);
        }
        printf("\n");
    }
}


struct Node {
    char name[20];
    int x;
    char type;
    int y;
    int point;
    int energy;
    struct Node *next;
};
struct Node1 {
    int energy;
    int type;
};

struct Node *newNode(int x, int y, int point, char type, char *name) {
    struct Node *new_Node = (struct Node *) malloc(sizeof(struct Node));
    new_Node->x = x;
    new_Node->y = y;
    new_Node->point = point;
    new_Node->type = type;
    new_Node->next = NULL;
    strcpy(new_Node->name, name);
    return new_Node;
}

char *rand_string(size_t size) { // reserves a place for NULL c
    //
    char *str = malloc((size + 1) * sizeof(char));
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (size_t i = 0; i < size; i++) {
        int key = rand() % (sizeof(charset) / sizeof(char) - 1);
        str[i] = charset[key];
    }
    str[size] = '\0';
    return str;
}

void addid(struct Node **head, int x, int y, char *name, char type, int id) {
    struct Node *curr = *head;
    struct Node *temp = NULL;
    int counter = 1;
    while (curr != NULL) {
        if (counter == id) {
            temp = curr->next;
            char str[10];
            strcpy(str, rand_string(5));
            curr->next = newNode(x, y, 40, type, name);
            curr->next->next = temp;
        }
        curr = curr->next;
        counter++;
    }
}

void movenode(struct Node **head, int i, int j, int size, char arr[size][size], struct Node1 *head1) {
    struct Node *curr = *head;
    int counter = 1;
    while (curr != NULL) {
        if (counter == i) {
            switch (j) {
                case 1:
                    if (arr[curr->x][(curr->y) + 1] == '1') {
                        arr[curr->x][(curr->y) + 1] = 'e';
                        arr[curr->x][(curr->y)] = '4';
                        head1[(curr->x) * size + curr->y].type = 'e';
                        curr->y++;

                    } else if (arr[curr->x][(curr->y) + 1] == '2') {
                        head1[(curr->x) * size + curr->y + 1].type = 't';
                        arr[curr->x][(curr->y) + 1] = 't';
                        arr[curr->x][(curr->y)] = '4';

                        curr->y++;
                    } else if (arr[curr->x][(curr->y) + 1] == '4') {
                        arr[curr->x][(curr->y) + 1] = 'x';
                        arr[curr->x][(curr->y)] = '4';
                        curr->y++;

                    } else printf("forbidden");
                    break;
                case 2:
                    if (arr[curr->x][(curr->y) - 1] == '1') {
                        head1[(curr->x) * size + curr->y - 1].type = 'e';
                        arr[curr->x][(curr->y) - 1] = 'e';
                        arr[curr->x][(curr->y)] = '4';
                        curr->y--;
                    } else if (arr[curr->x][(curr->y) - 1] == '2') {
                        head1[(curr->x) * size + curr->y - 1].type = 't';
                        arr[curr->x][(curr->y) - 1] = 't';
                        arr[curr->x][(curr->y)] = '4';
                        curr->y--;
                    } else if (arr[curr->x][(curr->y) - 1] == '4') {
                        arr[curr->x][(curr->y) - 1] = 'x';
                        arr[curr->x][(curr->y)] = '4';
                        curr->y--;
                    } else printf("forbidden");
                    break;
                case 3:
                    if (arr[(curr->x) + 1][(curr->y) + 1] == '1') {
                        arr[(curr->x) + 1][(curr->y) + 1] = 'e';
                        arr[curr->x][(curr->y)] = '4';
                        head1[(curr->x + 1) * size + curr->y + 1].type = 'e';
                        curr->y++;
                        curr->x++;
                    } else if (arr[curr->x + 1][(curr->y) + 11] == '2') {
                        head1[(curr->x + 1) * size + curr->y + 1].type = 't';
                        arr[curr->x + 1][(curr->y) + 1] = 't';
                        arr[curr->x][(curr->y)] = '4';
                        curr->y++;
                        curr->x++;
                    } else if (arr[curr->x + 1][(curr->y) + 1] == '4') {
                        arr[curr->x + 1][(curr->y) + 1] = 'x';
                        arr[curr->x][(curr->y)] = '4';
                        curr->y++;
                        curr->x++;
                    } else printf("forbidden");
                    break;
                case 4:
                    if (arr[(curr->x) - 1][(curr->y) + 1] == '1') {
                        head1[(curr->x) * size + curr->y].type = 'e';
                        arr[(curr->x) - 1][(curr->y) + 1] = 'e';
                        arr[curr->x][(curr->y)] = '4';
                        curr->y++;
                        curr->x--;
                    } else if (arr[curr->x][(curr->y) - 1] == '2') {
                        head1[(curr->x) * size + curr->y].type = 't';
                        arr[curr->x][(curr->y) - 1] = 't';
                        arr[curr->x][(curr->y)] = '4';

                        curr->y++;
                        curr->x++;
                    } else if (arr[curr->x + 1][(curr->y) + 1] == '4') {
                        arr[curr->x][(curr->y) - 1] = 'x';
                        arr[curr->x][(curr->y)] = '4';
                        curr->y++;
                        curr->x++;
                    } else printf("forbidden");
                    break;
                case 5:
                    if (arr[(curr->x) + 1][(curr->y) - 1] == '1') {
                        head1[(curr->x) * size + curr->y].type = 'e';
                        arr[(curr->x) + 1][(curr->y) - 1] = 'e';
                        arr[curr->x][(curr->y)] = '4';
                        curr->y--;
                        curr->x++;
                    } else if (arr[curr->x][(curr->y) - 1] == '2') {
                        head1[(curr->x) * size + curr->y].type = 't';
                        arr[curr->x][(curr->y) - 1] = 't';
                        arr[curr->x][(curr->y)] = '4';
                        curr->y++;
                        curr->x++;
                    } else if (arr[curr->x + 1][(curr->y) + 1] == '4') {
                        arr[curr->x][(curr->y) - 1] = 'x';
                        arr[curr->x][(curr->y)] = '4';
                        curr->y++;
                        curr->x++;
                    } else printf("forbidden");
                    break;
                case 6:
                    if (arr[(curr->x) - 1][(curr->y) - 1] != '3') {
                        head1[(curr->x) * size + curr->y].type = 'e';
                        arr[(curr->x) - 1][(curr->y) - 1] = 'e';
                        arr[curr->x][(curr->y)] = '4';
                        curr->y--;
                        curr->x--;
                    } else if (arr[curr->x][(curr->y) - 1] == '2') {
                        head1[(curr->x) * size + curr->y].type = 't';
                        arr[curr->x][(curr->y) - 1] = 't';
                        arr[curr->x][(curr->y)] = '4';
                        curr->y++;
                        curr->x++;
                    } else if (arr[curr->x + 1][(curr->y) + 1] == '4') {
                        arr[curr->x][(curr->y) - 1] = 'x';
                        arr[curr->x][(curr->y)] = '4';
                        curr->y++;
                        curr->x++;
                    } else printf("forbidden");
                    break;

            }
        }
    }
}

void addFront(struct Node **head, int x, int y, int point, char type, char *name) {
    struct Node *new_node = newNode(x, y, point, type, name);
    new_node->next = *head;
    *head = new_node;
}

void pushBack(struct Node **head, int x, int y, int point, char type, char *name) {
    if (*head == NULL) {
        *head = newNode(x, y, point, type, name);
        return;
    }
    struct Node *curr = *head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode(x, y, point, type, name);
}

void deleteNode(struct Node **head, int data) {
    if (*head == NULL) {
        return;
    }
    if ((*head)->x == data) {
        struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    struct Node *current = *head;
    struct Node *last = NULL;
    while (current != NULL) {
        if (current->x == data) {
            last->next = current->next;
            free(current);
            return;
        }
        last = current;
        current = current->next;
    }
}

void printNodes(struct Node *head) {
    struct Node *curr = head;
    while (curr != NULL) {
        printf("%d ", curr->x);
        curr = curr->next;
    }
    printf("\n");
}

int movenodemenu() {
    printf("[ 1 ] North \n [ 2 ] South \n[ 3 ] Northeast\n [ 4 ] Northwest\n [ 5 ] Southeast \n[ 6 ] Southwest\n");
    int i;
    scanf("%d", &i);
    return i;

}

int mainmove() {
    printf("[1 ] Move\n [ 2 ] Split a cell \n[ 3 ] Boost energy\n [ 4 ] Save \n[ 5 ] Exit\n");
    int i;
    scanf("%d", &i);
    return i;
}

char *readmap(FILE *fp) {
    int size;
    fread(&size, sizeof(int), 1, fp);
    printf("%d", size);
    int size1 = size * size;
    int counter;
    char aras1[size1];
    fread(aras1, sizeof(char), size1, fp);
    return aras1;
}

int showmap() {
    printf("[1] Load\n");
    printf("[2] New single player\n");
    printf("[3]New multi player\n");
    printf("[4]exit\n");
    int i, counter;
    scanf("%d", &i);
    switch (i) {
        case 1:
            counter = 1;
            break;
        case 2:
            counter = 2;
            break;
        case 3:
            counter = 3;
            break;
        case 4:
            counter = 4;
            break;
    }
    return counter;
}

void flocation(int cell, int size1, char arr[size1][size1], char *location, struct Node *head) {
    int counter, counter1, i = 0, j = 0, counter3 = 0, rand1;
    for (counter = 0; counter < size1; counter++) {
        for (counter1 = size1; counter1 >= 0; counter1--) {
            arr[counter1][counter] = location[counter3];
        }
    }
    for (i = 0; i < cell; i++) {
        int x, y;
        x = rand() % size1;
        y = rand() % size1;
        while (arr[x][y] != '4'&&arr[x][y]=='x') {
            x = rand() % size1;
            y = rand() % size1;
        }
        char *str = rand_string(3);
        pushBack(&head, x, y, 0, 'x', str);
        arr[x][y] = 'x';
    }
}
int movemenu(struct Node *head) {
    struct Node *curr = head;
    printf("please choose one of you cells");
    int counter = 1;
    while (curr != NULL) {
        printf("[%d] %s (%d,%d)\n", counter, curr->name, curr->x, curr->y);
        curr = curr->next;
        counter++;
    }
    int j;
    scanf("%d", &j);
    return j;
}

void splitcell(int cell, struct Node **head) {
    int x, y;
    struct Node *curr = *head;
    int counter = 1;
    char str[20];
    strcpy(str, rand_string(5));
    while (curr != NULL) {
        if (counter == cell) {

            if (curr->energy >= 80) {
                x = rand() % 2 - 1;
                y = rand() % 2 - 1;
                addid(&head, curr->x + x, curr->y + y, str, '4', cell);
            }
        }
        curr = curr->next;
        counter++;

    }


}

void boostenergy(struct Node **head, int cell, struct Node1 head1[], int size) {
    struct Node *curr = *head;
    int counter = 1;
    while (curr != NULL) {
        if (counter == cell) {
            int x = curr->x;
            int y = curr->y;
            if (head1[size * x + y].type == 'e') {
                curr->energy += 15;
                head1[size * x + y].energy -= 15;
            }
        }
        counter++;
        curr = curr->next;
    }
}

void save(FILE *fp, struct Node1 head1[], struct Node *head, int size,int cell) {
    int size1 = size * size;
    for (int counter = 0; counter < size1; counter++) {
        fwrite(&head1[counter], sizeof(struct Node1), 1, fp);

    }
    int counter1 = 1;
    struct Node *curr = head;
    fwrite(&cell, sizeof(int),1,fp);
    while (curr != NULL) {
        counter1++;
        fwrite(curr, sizeof(struct Node), 1, fp);
        curr = curr->next;
    }

}
void load(FILE *fp, struct Node1 head1[], struct Node **head, int size) {
    int size1 = size * size;
    for (int counter = 0; counter < size1; counter++) {
        fread(&head1[counter], sizeof(struct Node1), 1, fp);
    }
    int j;
    fread(&j, sizeof(int),1,fp);
    struct Node *curr = NULL;
    for (int counter1 = 0; counter1 < j; ++counter1) {
        fread(curr, sizeof(struct Node), 1, fp);
        pushBack(&head, curr->x, curr->y, curr->point, curr->type, curr->name);
    }
}

#endif