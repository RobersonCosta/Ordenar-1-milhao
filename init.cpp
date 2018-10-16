#include <stdio.h>
#include <stdlib.h>


class Numero {
private:
	int valor;

public:
	Numero(int valor_entrada){
		setValor(valor_entrada);
	}

	Numero(){

	}

	~Numero(){
	}

	void setValor(int valor_entrada){
		valor = valor_entrada;
	}

	double getValor(){
		return valor;
	}
};

void quickSort(Numero **numeros_entrada, int inicio, int fim)
{
	int i, j, pivo;
	Numero *numero_auxiliar;
    if (inicio < fim)
    {
        pivo = fim;
		i = (inicio - 1);
		for (j = inicio; j <= fim-1; j++)
		{
		    if (numeros_entrada[j]->getValor() <= numeros_entrada[pivo]->getValor())
		    {
		        i++;
		        numero_auxiliar = numeros_entrada[i];
		        numeros_entrada[i] = numeros_entrada[j];
		        numeros_entrada[j] = numero_auxiliar;
		    }
		}
		numero_auxiliar = numeros_entrada[i+1];
		numeros_entrada[i+1] = numeros_entrada[fim];
		numeros_entrada[fim] = numero_auxiliar;
		pivo = i+1;

        quickSort(numeros_entrada, inicio, pivo - 1);
        quickSort(numeros_entrada, pivo + 1, fim);
    }



};

int main (){
    Numero *numeros[1000];
    char nome_arquivo[255];
    FILE *arquivo;
    printf("Digite o nome do arquivo para ser ordenado (incluindo a extensao):\n");
    scanf("%s", &nome_arquivo);
    arquivo = fopen(nome_arquivo, "rt");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo!");
        return 1;
    }
    printf("%d!\n", feof(arquivo));

        for (unsigned int i = 0; i < 1000; i += 1)
        {
            int valor;
            fscanf(arquivo, "%d", &valor);
            //printf("%d\n", valor);
            numeros[i] = new Numero(valor);
        }

    fclose(arquivo);
    //quickSort(numeros, 0, 999);
	return 1;
};
