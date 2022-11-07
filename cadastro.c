#include<stdio.h>
#include <time.h>
#define tam 250

char nome[50],rua[50],bai[50],cid[50],uf[50],tel[50],num[50],cep[50],email[50],dtdig[50],comor[50];
int cpf , dtnas,op, ida;
int anof;
int xt;
int anoh,mesh,diah,dn,mn,anon;
int hh, hm,hs;

void cadas();
void pesq();
void lista();
void calcidade();
int temp();
void salvatisco();
int comorb();

int main(void){
	
	do{
	
		system("cls"); // LIMPAAAAAAAAA TELAAAAAAAAAAAAAAAAAAAAAAAAA
	 
		 printf("\n");
        printf ("\t\t\t\t  HOSPITAL XXXXXXXXX!\n");
        printf ("\t\t\t==================================================\n");
        printf ("\t\t\t|\t                                               |\n");
        printf("\t\t\t|    1 - Listar Pacientes                          |\n");
        printf("\t\t\t|    2 - Buscar Pacientes                          |\n");
        printf("\t\t\t|    3 - Cadastrar Pacientes                       |\n");
        printf("\t\t\t|    0 - Sair                                      |\n");
        printf ("\t\t\t|                                                 |\n");
        printf ("\t\t\t==================================================\n");
        printf ("\n\n");
        printf("\t\t\t SELECIONAAAAAAAA: ");
        
        scanf("%d", &op); // PEGA A O VALOR DA VARIAVEL "OP"
        //if(op)
        switch(op) // SWITCH PEGA O VALOR DA VARIAVEL OP E VERIFICA SE O VALOR DE OP É IGUAL ALGUM DOS CASES 
		{
        	
        
        	case 1:        // TENHO QUE PROCURAR SE CONSIGO LISTAR O ARQUIVO SALVO
        		lista();
        		break;
        		
        	case 2: // TENHO QUE PROCURAR SE CONSIGO PESQUISAR O ARQUIVO SALVO
        		pesq();
        	break;
        	case 3: // CASO "OP" = 3 chama a função cadastro
        		cadas(); // chamando função cadastro
        	break;
        	case 4: // CASO "OP" = 4 fecha o programa
        		system("exit"); // FECHA PROGRAMAAAAAAAAAAAAAAAAAAA
        		break;
        		
        	default:
        			printf("\t\t\tPor favor, selecione uma X opcao: ");
        	break;
        			
        		
		}
	}while(op!=4); // RODA ENQUANTO "OP"  FOR DIFERENTE DE 4
	
}

void cadas() // função para cadastrar
{
//	static int  lin;
	do {
		printf("\nDigite o Nome: ");
		scanf("%s", &nome); 
		printf("\nDigite o logradouro: ");
		scanf("%s", &rua);
		printf("\nDigite o Numero: ");
		scanf("%s", &num);
		printf("\nDigite o Bairro: ");
		scanf("%s", &bai);
		printf("\nDigite a Cidade: ");
		scanf("%s", &cid);
		printf("\nDigite o Estado: ");
		scanf("%s", &uf);
		printf("\nDigite o CEP: ");
		scanf("%s", &cep);
		
	
		printf("\nDigite o Telefone: ");
		scanf("%s", &tel);
	
	
		
		printf("\nDigite o email: ");
		scanf("%s", &email);
		
		printf("\nDigite o CPF: ");
		scanf("%d", &cpf);
		temp();
		

		
		comorb();// chamada da função para coletar a data do nascimento e calcular a idade da pessoa
		//printf("\nDigite Comorbidade: ");
		//scanf("%s", &comor[lin]);
		
		
		if(anof >= 65 || xt == 1) // If para saber se o maluco tem mais de 65 ou alguma comorbidade, se alguma for true ele salva o arquivo
		{
			
			salvatisco(); // chamada da função para salvar
		}
		else
		{
			printf("Que Merda");
		}
		
		//salvatisco(temp);
		

		
		
		
		
		
		
		//printf("\nDigite a data hoje: ");
		//scanf("%s", &dtdig[lin]);
		
		printf("\n Digite 1 para cadastrar outro paciente ou outro valor para sair: \n");
		scanf("%d", &op);
		
		//lin++;
		
	
	
	}while(op==1); // SE "OP" FOR IGUAL A 1 REFAZ A OPERAÇÃO, QUALQUER OUTRO VALOR ELE VOLTA PRO MENU
}

void pesq (){

FILE*pont_arq; // criação de variavel ponteiro
	    char buscaq[100];	
	    char cpfq[20];
	    	
		pont_arq =fopen("arquivo_risco.txt", "r"); // abrindo o arquivo com o tipo de abertura "A", existe o "w" mas o W sobscreve os que já existem.
		
		if(pont_arq==NULL) //testando se o arquivo foi criado
		{
			printf("ERRROU");
		
		}
		else 
		{
			printf("Digite um CPF");
			scanf("%d", cpfq);
			
			while(fgets(buscaq, 100, pont_arq) != NULL)
			{
				if(cpfq == buscaq)
				{
					printf("%s", buscaq);	
				}
			
				else
				{
					printf("Pensa De novo");
				}	
			}		
			getchar();
			fclose(pont_arq);
    	}
	
	

		getchar();
 
}
void lista()



{
		FILE*pont_arq; // criação de variavel ponteiro
	    char listaq[100];	
	    	
		pont_arq =fopen("arquivo_risco.txt", "r"); // abrindo o arquivo com o tipo de abertura "A", existe o "w" mas o W sobscreve os que já existem.
		
		if(pont_arq==NULL) //testando se o arquivo foi criado
		{
			printf("ERRROU");
		
		}
		else 
		{
			while(fgets(listaq, 100, pont_arq) !=NULL)
			{
				printf("%s", listaq);	
			}		
			getchar();
			fclose(pont_arq);
    	}
	
	

		getchar();
}


// JOGAR FORA PARTE 2 ????????????????????????????

int temp() // função para  calcular idade e pegar o dia automatico
{
		
	
		int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // declaração das variaveis em array em alusão aos dias dos meses
		time_t t = time(NULL);
		  struct tm tm = *localtime(&t); //
	     //printf("now: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
		  
		  anoh = tm.tm_year + 1900;
		  mesh = tm.tm_mon + 1;
		  diah =  tm.tm_mday;
		  hh = tm.tm_hour;
		  hm = tm.tm_min;
		  hs = tm.tm_sec;
		  
		  printf("\nDigite o dia do Nascimento: ");
		  scanf("%d", &dn); // entrada no valor da variavel "dn"
		  
			printf("\nDigite o Mes do Nascimento : ");
		  scanf("%d", &mn); // entrada no valor da variavel "mn"
		  
		   printf("\nDigite o Ano do Nascimento: ");
		  scanf("%d", &anon); // entrada no valor da variavel anon
		  
		   if (dn > diah) // se o dia de nascimento for maior que o dia atual
		    {
      		diah = diah + month[mn - 1]; //pega a variavel "mn" e substrai 1 do valor dela
      		mesh = mesh - 1; // Mes de Hoje menos 1
   			}
   			
   			if (mn > mesh) // se o o mes de nascimento for maior que o mes atual
			    {
     			 anoh = anoh - 1;  // ano atual é igual ano passado xD
     			 mesh = mesh + 12; // e mes atual é  igual mes atual mais 12
     		}
     		
     		int diaf = diah - dn; // subtração do dia atual por dia do nascimento
   			int mesf = mesh - mn; // subtração do mes atual pelo mes do nascimento
   			 anof = anoh - anon; // subtração do ano atual pelo ano do nascimento
   			printf("Idade: %d Mes: %d Dias: %d", anof, mesf, diaf);
   		
   			
   			 anoh = tm.tm_year + 1900;
		  mesh = tm.tm_mon + 1;
		  diah =  tm.tm_mday;
		  
   			
   			
   			
		  
		  
		  
	}
		  


void salvatisco() // função para salvar no arquivo
{
	
			
		
		
		
		
		FILE*pont_arq; // criação de variavel ponteiro
		
		
		pont_arq =fopen("arquivo_risco.txt", "a"); // abrindo o arquivo com o tipo de abertura "A", existe o "w" mas o W sobscreve os que já existem.
		
		if(pont_arq==NULL) //testando se o arquivo foi criado
		{
			printf("ERRROU");
		
		}
		else // caso ele seja criado ele salva os dados abaixo
		{
				
				// fprintf é para armazenar a string no arquivo que foi criado 
				fprintf (pont_arq,"\n ==========================================================");
				fprintf(pont_arq, "\nNome: %s", nome); // armazena o valor da variavel "nome" no arquivo
				fprintf(pont_arq, "\nCPF: %d", cpf); // armazena o valor da variavel "cpf" no arquivo 
				fprintf(pont_arq, "\nTelefone: %s", tel); // armazena o valor da variavel "tel" no arquivo 
				fprintf(pont_arq, "\nRua: %s", rua); // armazena o valor da variavel "rua" no arquivo 
				fprintf(pont_arq, "\nNumero: %s", num); // armazena o valor da variavel "num" no arquivo 
				fprintf(pont_arq, "\nBairro: %s", bai); // armazena o valor da variavel "bai" no arquivo 
				fprintf(pont_arq, "\nCidade: %s", cid); // armazena o valor da variavel "cid" no arquivo 
				fprintf(pont_arq, "\nEstado: %d", uf); // armazena o valor da variavel "uf" no arquivo 
				fprintf(pont_arq, "\nCEP: %s", cep); // armazena o valor da variavel "cep" no arquivo 
				fprintf(pont_arq, "\nData de Nascimento:  %d/%02d/%02d",dn, mn, anon); // armazena o valor das variaveis "dn,mn,anon" no arquivo
				fprintf(pont_arq, "\nData do Diagnostico: %d/%02d/%02d",diah, mesh, anoh); // armazena o valor das variaveis "diah, mesh, anoh" no arquivo 
					fprintf(pont_arq, "\tHora do Diagnostico: %d:%02d:%02d",hh, hm, hs);
							//fprintf(pont_arq, "\nData do diagnóstico: %s", ); ///// colocar o current time aqui 
				fprintf(pont_arq, "\nComorbidade: %s", comor); // armazena o valor da variavel "comor" no arquivo
				fprintf (pont_arq,"\n ==========================================================");
				fclose(pont_arq); // fclose é para fechar o arquivo
				printf("Tudo Certo");
							
		}
	
}

int comorb() // função para saber se tem comorbidade
{

  do{
		system("cls"); // LIMPAAAAAA TELAAAAAAAA
        printf("O Paciente tem alguma comorbidade ?\n");
        printf("Digite 1: Sim\n");
        printf("Digite 2: Nao\n");
        
		        
		        	scanf("%d", &xt);
	
	

        switch(xt){
        	
        
        	case 1:
        	printf("Qual comobirdade ?\n"); 
        	scanf("%s", comor); // a variavel comor recebe o valor 
        	
        	break;
        		
        	case 2:
        	 printf("Isso ai");
        	 // o comor tem que receber o "Não" Aquiiiiiiiiii
        	break;
        
        	default:
        			printf("\t\t\tPor favor, selecione uma X opcao: ");
        	break;
        			
        		
		}	
	}while(xt!=2 && xt!=1);// Enquanto o valor for diferente de 1 ou 2 ele vai ficar caindo no default 
		
	getchar();
			getchar();
}




