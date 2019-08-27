#include <stdio.h>

//TERCEIRA SOLU��O, USANDO STRUCT E VETOR 

int main() {
    /**
        Isso � uma etrutura de dados, podendo ter v�rias vari�vies dentro desta mesma.
        Ela � de melhor visualiza��o e entendimento que uma matriz por exemplo, 
        e pode conter informa��es de diversos tipos, como char e int.
    */
    struct cidade {
        int codigo_cidade;
        int numero_veiculo;
        int quantidade_vitimas;
    };
  
    int num_cidade;
    printf("==== IBGE ==== \n \n");
    printf("Digite a quantidade de cidades a serem cadastradas: ");
    scanf("%d", &num_cidade); // numero de cidades a ser cadastradas
    
  
    struct cidade cidades[num_cidade]; //aqui temos um vetor da estrutura cidade, declarada anteriormente
   
    printf("\n\nAgora digite os dados da cidade: \n\n"); 
     // o looping dever� ser apenas nas linhas da matriz j� que sabemos que as colunas s�o fixas e representam uma informa��o espec�fica
    for (int i = 0; i < num_cidade; i++) { //usaremos sempre o num_cidade para varrer a matriz.
        printf("------------------------------");
        printf("\n\nCadastro da cidade: %d", i+1);
        
        printf("\nDigite o c�digo da cidade: ");
        scanf("%d", &cidades[i].codigo_cidade); //usamos o "." (ponto) para poder indicar qual variavel da estrutura estamdos usando
        
        printf("Digite o n�mero de veiculos de passeio da cidade:");
        scanf("%d", &cidades[i].numero_veiculo);
        
        printf("Digite o n�mero de acidentes de tr�nsito com v�timas:");
        scanf("%d", &cidades[i].quantidade_vitimas);
    }
    
    
    printf("\n\nRELAT�RIOS: \n\n");
    printf("\n\n-------------------\n\n");
    /**
     Aqui faremos uma l�gica de maior, 
     pegamos as informa��es da priemira posi��es do vetor e comparamos com as sbsequentes da mesma
     se o volor da vari�vel for menor que a comparada, ela recebe o valor da comparada, 
     assim no final a vari�vel ficar� com o maior valor de todo o array.
    */
    
    struct cidade cidadeMaiorAcidente; //declaramos uma cidade novamente para depois fazer o uso da mesma no resultado, isso facita caso necessitamos pegar outra informa��o da mesma cidade.
    int maior_n_acidente = cidades[0].quantidade_vitimas;  //vari�vel para guardar o valor do maior numero de acidentes, essa vari�vel ser� agora apenas de controle, o resultado usarmoes a variavel cidadeMaiorAcidente acima.
    for (int i = 0; i < num_cidade; i++) {
        if(maior_n_acidente < cidades[i].quantidade_vitimas) {
            maior_n_acidente = cidades[i].quantidade_vitimas;
            cidadeMaiorAcidente = cidades[i]; //a variavel cidadeMaiorAcidente receve toda a estrutra da cidades da posi��o [i] para usarmos posteriormente.
        }
     }
    printf("A cidade com maior ind�ce de acidentes �: %d", cidadeMaiorAcidente.codigo_cidade);
    printf("\nE o n�mero de acidentes �: %d", cidadeMaiorAcidente.quantidade_vitimas);
    
    
    printf("\n\n-------------------\n\n");
     /**
     Aqui faremos uma l�gica de menor, 
     pegamos as informa��es da priemira posi��es do vetor e comparamos com as sbsequentes da mesma
     se o volor da vari�vel for maior que a comparada, ela recebe o valor da comparada, 
     assim no final a vari�vel ficar� com o menor valor de todo o array.
    */
    struct cidade cidadeMenorAcidente; //declaramos uma cidade novamente para depois fazer o uso da mesma no resultado, isso facita caso necessitamos pegar outra informa��o da mesma cidade.
    int menor_n_acidente = cidades[0].quantidade_vitimas;  //vari�vel para guardar o valor do menor numero de acidentes, essa vari�vel ser� agora apenas de controle, o resultado usarmoes a variavel cidadeMenorAcidente acima.
    for (int i = 0; i < num_cidade; i++) {
        if(menor_n_acidente > cidades[i].quantidade_vitimas) {
            menor_n_acidente = cidades[i].quantidade_vitimas;
             cidadeMenorAcidente = cidades[i]; //a variavel cidadeMenorAcidente receve toda a estrutra da cidades da posi��o [i] para usarmos posteriormente.
        }
     }
    printf("A cidade com  menor ind�ce de acidentes �: %d", cidadeMenorAcidente.codigo_cidade);
    printf("\nE o n�mero de acidentes �: %d", cidadeMenorAcidente.quantidade_vitimas);
    
    printf("\n\n-------------------\n\n");
     /**
        L�gica de m�dia de veiculos, somamos todos os veiculos do array,
        e no fim dividimos pela quantiade de cidades.
    */
    int total_veiculos = 0;
    for (int i = 0; i < num_cidade; i++) {
        total_veiculos = total_veiculos + cidades[i].numero_veiculo;
    }
    
    float media_veiculo = total_veiculos / num_cidade;
    printf("A m�ida de veiculos nas cidades juntas �: %.1f", media_veiculo);
    
    printf("\n\n-------------------\n\n");
    /**
        L�gica de m�dia de acidentes de tr�nsito, 
        desde que a cidade tenha menos que 2000 veiculos.
    */
    int total_acident_transito = 0; //vari�vel para somar os acidentes de tr�nsito
    int count_cidades_menor_2000 = 0; //var�vel que ir� contar quntas cidade tem menos que 2000, necess�ria para m�dia, j� que n�o faremos desta vez com a quantiade de cidades.
    for (int i = 0; i < num_cidade; i++) {
        if(cidades[i].numero_veiculo < 2000){
            total_acident_transito = total_acident_transito + cidades[i].quantidade_vitimas;
            count_cidades_menor_2000++;
        }
    }
    
     float media_acidente_transito = total_acident_transito / count_cidades_menor_2000;
     printf("A m�ida de acidentes de tr�nsito em cidades com menos de 2000 ve�culos �: %.1f", media_acidente_transito);
    
    
   
    return 0;
}

