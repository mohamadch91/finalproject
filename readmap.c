#include<stdio.h>
#include<stdio.h>
int main(){
FILE *fp;
fp=fopen("newmap.bin","rb");
int size;
fread(&size,sizeof(int),1,fp);
unsigned char mamad[size*size];
fread(mamad,sizeof(unsigned char),size*size,fp);
printf("%d\n",size);
int counter=0;
for(counter=0;counter<size*size;counter++){
    printf("%u\n",mamad[counter]-'0');

}
}
