#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int notconfict=0;
    int i,j,k;

    int a1,h1;
    scanf(" %d",&a1);
    scanf(" %d",&h1);
    char list1[h1][9];
    for (i=0;i<h1;i++){
            scanf(" %s",list1[i]); }
    int b2,h2;
    scanf(" %d",&b2);
    scanf(" %d",&h2);
    char list2[h2][9];
    for (i=0;i<h2;i++){
            scanf(" %s",list2[i]);}
    int c3,h3;
    scanf(" %d",&c3);
    scanf(" %d",&h3);
    char list3[h3][9];
    for (i=0;i<h3;i++){
            scanf(" %s",list3[i]);}
    for (j=0;j<h1;j++){
            for(k=0;k<h2;k++){
                if (strcmp(list1[j],list2[k])==0){
                    printf("%d and %d conflict on %s",a1,b2,list1[j]);
                    notconfict=1;}
                if (notconfict){
                        list2[k][9]=0;
                notconfict=0;}}}
    for (j=0;j<h1;j++){
            for(k=0;k<h3;k++){
                if (strcmp(list1[j],list3[k])==0){
                    printf("%d and %d conflict on %s",a1,c3,list1[j]);
                    notconfict=1;}
                if (notconfict){
                        list3[k][9]=0;
                notconfict=0;}}}
    for (j=0;j<h2;j++){
            for(k=0;k<h3;k++){
                if (strcmp(list2[j],list3[k])==0){
                    printf("%d and %d conflict on %s",b2,c3,list2[j]);
                    notconfict=1;}
                if (notconfict){
                        list3[k][9]=0;
                notconfict=0;}}}
}
