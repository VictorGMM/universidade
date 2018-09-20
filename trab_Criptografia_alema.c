#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool eh_possivel(int , const char * , const char * );
int main()

/*                                         funcao main:
menasagem  -  eh referente a mensagem que deve ser informada pelo usuario, assim como o exercicio descreve.
x          -  numero de caracteres da string mensagem.
crib       -  string que contem o crib que deve ser informada pelo usuario, assim como o exercicio descreve.
y          -  numero de caracteres da string crib.
index      -  numero da possicao que deve ser informada como valida ou nao pela funcao "eh_possivel".
tot        -  ultilizada para dizer quando parar de procurar as possibilidades de crib.
k          -  ultilizada para saber numero de possibilidades de que o crib esteja localizado a partir da posição index da mensagem.
i          -  ultilizada para varrer as strings.
j          -  numero de caracteres da string crib.

                                           funcao eh_possivel:
recebe como parametro da funcao main: index, ponteiro de mensagem e o ponteiro de crib.
x  -  numero de caracteres da string mensagem.
y  -  numero de caracteres da string crib.
i  -  recebe valor de index para varrer o ponteiro de mensagem.
j  -  varre o ponteiro de crib.
k  -  ultilizada para saber se tem a possibilidade de que o crib esteja localizado a partir da posição index da mensagem.
*/
{
    char mensagem[10000];
    int x,y,index,tot,k=0,i,j;
    for(;;){

    gets(mensagem);
    x=strlen(mensagem);
    for(i=0; i<x; i++){//confere se a mensagem eh valida para o exercicio
        if(mensagem[i]<'A' || mensagem[i]>'Z'){
                k++;
            for(j=i; j<x; j++){
                mensagem[j]=mensagem[j+1];
            }
            x--;
            mensagem[j]='\0';
            i=0;
        if(mensagem[0]<'A' || mensagem[0]>'Z'){
            k++;
            for(j=0; j<x; j++){
                mensagem[j]=mensagem[j+1];
            }
            x--;
            mensagem[j]='\0';
        }
        }
    }
    if(strlen(mensagem)>0 && strlen(mensagem)<10000 && mensagem[0]<='A' && mensagem[0]<='Z'){
            if(k>0){
            puts(mensagem);
            k=0;
            }
        break;
    }else{
    }
    }

    char crib[x];
    for(;;){
    gets(crib);
    y=strlen(crib);
    for(i=0; i<y; i++){//confere se crib eh valido para o exercicio
        if(crib[i]<'A' || crib[i]>'Z'){
            k++;
            for(j=i; j<y; j++){
                crib[j]=crib[j+1];
            }
            y--;
            crib[j]='\0';
            i=0;
            if(crib[0]<'A' || crib[0]>'Z'){
                    k++;
            for(j=0; j<x; j++){
                crib[j]=crib[j+1];
            }
            y--;
            crib[j]='\0';
        }
        }
    }
    if(strlen(crib)>0 && y<=x && crib[0]>='A' && crib[0]<='Z'){
            if(k>0){
            puts(crib);
            k=0;
            }
        break;
    }
    }

    tot=x-y;
    k=0;
    for(index=0; index<=tot; index++){
        if((eh_possivel(index, mensagem, crib))==true){
            k++;
        }
    }
    printf("%d",k);

    return 0;
}

bool eh_possivel(int index, const char * mensagem, const char * crib){
    int x,y,i,j,k;
    x=strlen(mensagem);
    y=strlen(crib);
    k=0;
    for(i=index, j=0; j<y; j++,i++){
        if(crib[j]==mensagem[i]){
            k++;
        }
    }
    if(k==0){
        return true;
    }else{
    return false;
    }
}
