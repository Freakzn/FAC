// ROGER NATAN DA SILVA PORTO
// ANTÔNIO LIMA DE SOUSA JÚNIOR
// 0.05, 0.10, -0.03, 0.20, 0.07, -0.08, 0.12, -0.04, 0.09, 0.06 --> percentual

#include <stdio.h>

void exibe_produtos(int vCod[], int vEstoque[], int tamanho){
    int pos;
    for(pos = 0; pos < tamanho; pos++){
        printf("Código: %d e Estoque: %d\n", vCod[pos], vEstoque[pos]);
    }
}
void ler_percentuais(float percentuais[], int tamanho, float minimo, float maximo){ // falta validar o cod
    
    for(int pos = 0; pos < tamanho; pos++){ 
        printf("Digite 10 percentuais [%d]: ", pos+1);
        scanf("%f", &percentuais[pos]);
        while(percentuais[pos] < minimo || percentuais[pos] > maximo){
            printf("Número inválido. Digite novamente: ");
            scanf("%f", &percentuais[pos]);
        }
    } 

}
void calcular_limites_diamicos(int codigo, float *min, float *max){
    float margem;
    margem = 0.1 + (((codigo % 100) / 100.0) * 0.2);
    *min = 0.01 - margem;
    *max = 0.01 + margem;
}
int calcular_alteracao(int codigo, int *quantidade, float percentuais[]){
    float min, max;
    int ulti_digito = codigo % 10;
    calcular_limites_diamicos(codigo, &min, &max);
    if(ulti_digito >= min || ulti_digito <= max){

        *quantidade = *quantidade + (*quantidade * percentuais[ulti_digito]);
        return 1;
    } else {
        return 0;
    }
}

int main(){
    float percentuais[10];
    int vcodigos[5] = {2374, 1259, 9860, 4123, 3051};
    int vquantidades[5] = {100, 150, 200, 80, 50};
    int tamanho = 10;
    
    
    ler_percentuais(percentuais, tamanho, -0.10, 0.15);
    exibe_produtos(vcodigos, vquantidades, tamanho);
    for(int pos = 0; pos < 5; pos++) {
        calcular_alteracao(vcodigos[pos], &vquantidades[pos], percentuais);
    }
    return 0;
}