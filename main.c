#include <stdio.h>
#include <string.h>

int isDigitsDintincts(int document[]){
    
    int i = 0, sum = 0;
    
    for(i = 0; i < 10; i++){
        
        if(document[i] != document[i+1]){
            return 1;
        }
        
    }
    
    return 0;
    
}

int verifyDigit(int document[], int digit, int module[]){
    
    int sum = 0, rest = 0, i = 0;
    
    for(i = 0; i < digit; i++){
        
        sum += document[i] * module[i];
        
    }
    
    rest = ((sum * 10) % 11) % 10;
    
    return rest == document[digit];
    
}

void getOriginState(int digit){
    
    char states[10][80] = {
        "Rio Grande do Sul",
        "Distrito Federal, Goiás, Mato Grosso, Mato Grosso do Sul e Tocantins",
        "Amazonas, Pará, Roraima, Amapá, Acre e Rondônia",
        "Ceará, Maranhão e Piauí",
        "Paraíba, Pernambuco, Alagoas e Rio Grande do Norte",
        "Bahia e Sergipe",
        "Minas Gerais",
        "Rio de Janeiro e Espírito Santo",
        "São Paulo",
        "Paraná e Santa Catarina",
    };
    
    printf("Origem: %s\n", states[digit]);
    
}

int main()
{
    
    int modules[4][13] = {
        {10,9,8,7,6,5,4,3,2},
        {11,10,9,8,7,6,5,4,3,2},
        {5,4,3,2,9,8,7,6,5,4,3,2},
        {6,5,4,3,2,9,8,7,6,5,4,3,2},
    };
    char document[50];
    int formatedDocument[11];
    int i = 0, count = 0;
    
    printf("Digite seu CPF ou CNPJ: ");
    scanf("%s", document);
    printf("\e[1;1H\e[2J");
    
    for(i = 0; i < strlen(document); i++){
        
        if((int) document[i] >= 48 && (int) document[i] <= 57){
            
            formatedDocument[count++] = document[i] - 48;
            
        }
        
    }
    
    printf("Documento: %s\n", document);
    
    if(isDigitsDintincts(formatedDocument)){
        
        if(count == 11){
            
            if(verifyDigit(formatedDocument, 9, modules[0]) &&
                verifyDigit(formatedDocument, 10, modules[1])){
                printf("Status: Válido\n");
                getOriginState(formatedDocument[8]);
            }else{
                printf("Error: CPF inválido");
            }
        
        }else if(count == 14){
            
            if(verifyDigit(formatedDocument, 12, modules[2]) &&
                verifyDigit(formatedDocument, 13, modules[3])){
                printf("Status: Válido\n");
            }else{
                printf("Error: CNPJ inválido");
            }
            
        }else{
            printf("Error: quantidade de dígitos inválida");
        }
        
    }else{
        printf("Error: dígitos não distintos");
    }
    
    return 0;
    
}
