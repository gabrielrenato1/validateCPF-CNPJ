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

int verifyDigit(int document[], int digit){
    
    int sum = 0, rest = 0, i = 0, module = digit + 1;
    
    for(i = 0; i < digit; i++){
        sum += document[i] * module--;
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
    
    char document[50];
    int formatedDocument[11];
    int i = 0, count = 0;
    
    printf("Digite seu CPF: ");
    scanf("%s", document);
    printf("\e[1;1H\e[2J");
    
    for(i = 0; i < strlen(document); i++){
        
        if((int) document[i] >= 48 && (int) document[i] <= 57){
            
            formatedDocument[count++] = document[i] - 48;
            
        }
        
    }
    
    printf("CPF: %s\n", document);
    
    if(
        isDigitsDintincts(formatedDocument) &&
        (verifyDigit(formatedDocument, 9) && verifyDigit(formatedDocument, 10))){
        printf("Status: Válido\n");
        getOriginState(formatedDocument[8]);
    }else{
        printf("Status: Inválido");
    }
    
    return 0;
}
