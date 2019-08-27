#include <stdio.h>

//TERCEIRA SOLUÇÃO, USANDO STRUCT E VETOR 

int main() {
    /**
        Isso é uma etrutura de dados, podendo ter várias variávies dentro desta mesma.
        Ela é de melhor visualização e entendimento que uma matriz por exemplo, 
        e pode conter informações de diversos tipos, como char e int.
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
     // o looping deverá ser apenas nas linhas da matriz já que sabemos que as colunas são fixas e representam uma informação específica
    for (int i = 0; i < num_cidade; i++) { //usaremos sempre o num_cidade para varrer a matriz.
        printf("------------------------------");
        printf("\n\nCadastro da cidade: %d", i+1);
        
        printf("\nDigite o código da cidade: ");
        scanf("%d", &cidades[i].codigo_cidade); //usamos o "." (ponto) para poder indicar qual variavel da estrutura estamdos usando
        
        printf("Digite o número de veiculos de passeio da cidade:");
        scanf("%d", &cidades[i].numero_veiculo);
        
        printf("Digite o número de acidentes de trânsito com vítimas:");
        scanf("%d", &cidades[i].quantidade_vitimas);
    }
    
    
    printf("\n\nRELATÓRIOS: \n\n");
    printf("\n\n-------------------\n\n");
    /**
     Aqui faremos uma lógica de maior, 
     pegamos as informações da priemira posições do vetor e comparamos com as sbsequentes da mesma
     se o volor da variável for menor que a comparada, ela recebe o valor da comparada, 
     assim no final a variável ficará com o maior valor de todo o array.
    */
    
    struct cidade cidadeMaiorAcidente; //declaramos uma cidade novamente para depois fazer o uso da mesma no resultado, isso facita caso necessitamos pegar outra informação da mesma cidade.
    int maior_n_acidente = cidades[0].quantidade_vitimas;  //variável para guardar o valor do maior numero de acidentes, essa variável será agora apenas de controle, o resultado usarmoes a variavel cidadeMaiorAcidente acima.
    for (int i = 0; i < num_cidade; i++) {
        if(maior_n_acidente < cidades[i].quantidade_vitimas) {
            maior_n_acidente = cidades[i].quantidade_vitimas;
            cidadeMaiorAcidente = cidades[i]; //a variavel cidadeMaiorAcidente receve toda a estrutra da cidades da posição [i] para usarmos posteriormente.
        }
     }
    printf("A cidade com maior indíce de acidentes é: %d", cidadeMaiorAcidente.codigo_cidade);
    printf("\nE o número de acidentes é: %d", cidadeMaiorAcidente.quantidade_vitimas);
    
    
    printf("\n\n-------------------\n\n");
     /**
     Aqui faremos uma lógica de menor, 
     pegamos as informações da priemira posições do vetor e comparamos com as sbsequentes da mesma
     se o volor da variável for maior que a comparada, ela recebe o valor da comparada, 
     assim no final a variável ficará com o menor valor de todo o array.
    */
    struct cidade cidadeMenorAcidente; //declaramos uma cidade novamente para depois fazer o uso da mesma no resultado, isso facita caso necessitamos pegar outra informação da mesma cidade.
    int menor_n_acidente = cidades[0].quantidade_vitimas;  //variável para guardar o valor do menor numero de acidentes, essa variável será agora apenas de controle, o resultado usarmoes a variavel cidadeMenorAcidente acima.
    for (int i = 0; i < num_cidade; i++) {
        if(menor_n_acidente > cidades[i].quantidade_vitimas) {
            menor_n_acidente = cidades[i].quantidade_vitimas;
             cidadeMenorAcidente = cidades[i]; //a variavel cidadeMenorAcidente receve toda a estrutra da cidades da posição [i] para usarmos posteriormente.
        }
     }
    printf("A cidade com  menor indíce de acidentes é: %d", cidadeMenorAcidente.codigo_cidade);
    printf("\nE o número de acidentes é: %d", cidadeMenorAcidente.quantidade_vitimas);
    
    printf("\n\n-------------------\n\n");
     /**
        Lógica de média de veiculos, somamos todos os veiculos do array,
        e no fim dividimos pela quantiade de cidades.
    */
    int total_veiculos = 0;
    for (int i = 0; i < num_cidade; i++) {
        total_veiculos = total_veiculos + cidades[i].numero_veiculo;
    }
    
    float media_veiculo = total_veiculos / num_cidade;
    printf("A méida de veiculos nas cidades juntas é: %.1f", media_veiculo);
    
    printf("\n\n-------------------\n\n");
    /**
        Lógica de média de acidentes de trânsito, 
        desde que a cidade tenha menos que 2000 veiculos.
    */
    int total_acident_transito = 0; //variável para somar os acidentes de trânsito
    int count_cidades_menor_2000 = 0; //varável que irá contar quntas cidade tem menos que 2000, necessária para média, já que não faremos desta vez com a quantiade de cidades.
    for (int i = 0; i < num_cidade; i++) {
        if(cidades[i].numero_veiculo < 2000){
            total_acident_transito = total_acident_transito + cidades[i].quantidade_vitimas;
            count_cidades_menor_2000++;
        }
    }
    
     float media_acidente_transito = total_acident_transito / count_cidades_menor_2000;
     printf("A méida de acidentes de trânsito em cidades com menos de 2000 veículos é: %.1f", media_acidente_transito);
    
    
   
    return 0;
}

