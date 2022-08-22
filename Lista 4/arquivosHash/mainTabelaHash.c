#include "tabelaHashbasica.h"


int main(void){
	Hash HASH ;
	int opt;
	inicializaHash(HASH);
	
	do{
		opt=menu();
		opcao(HASH,opt);
	}while(opt!=4);

	return 0;
}
