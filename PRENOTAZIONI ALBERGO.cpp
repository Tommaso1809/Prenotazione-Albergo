#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#define DIM 1000
#define TARIFFA 100

using namespace std;

//Prototipi Funzioni
int menu();
void riempi();
void visualizza();
void ricerca(int);
void modifica();
void cancella();
void ricerca_posti();
void controllo(int);


//Variabili Globali
int scelta,cnt=0,index=0,nDisponibili=0,o,c,n,s,i;  
bool scl;
int ID[DIM],ospiti[DIM],notti[DIM],stanze[DIM],liberi[DIM];
double prezzi[DIM],p;
string mese[DIM],m;

//Main
int main(){
	
	srand(time(NULL));
	
	do{
		
		scelta=menu();
		controllo(scelta);
		
		cout<<"Vuoi continuare 1|0 ?"<<endl;
		cin>>scl;
		
	}while(scl);
	
  return 0;	
}

int menu(){
	
	int s;
	
	cout<<"****PRENOTAZIONI ALBERGO *****"<<endl;
	cout<<"*1 INSERIRE PRENOTAZIONE     *"<<endl;
	cout<<"*2 VISUALIZZARE PRENOTAZIONE *"<<endl;
	cout<<"*3 RICERCARE PRENOTAZIONE    *"<<endl;
	cout<<"*4 MODIFICARE PRENOTAZIONE   *"<<endl;
	cout<<"*5 CANCELLARE PRENOTAZIONE   *"<<endl;
	cout<<"*6 RICERCARE POSTI LIBERI    *"<<endl;
	cout<<"*7 PER USCIRE ------>        *"<<endl;
	cout<<"******************************"<<endl;
	cout<<endl;
	cout<<"INSERIRE LA TUA SCELTA 1|7"<<endl;
	cin>>s;
	
	return s;
}

void riempi(){
	
	if(cnt==DIM){
		
		cout<<"Albergo Pieno"<<endl;
		
	}
	else{
	
	
		cout<<"Inserisci il mese"<<endl;
		cin>>m;
		mese[cnt]=m;
		cout<<"Inserisci il numero delle notti"<<endl;
		cin>>n;
		notti[cnt]=n;
		cout<<"Inserisci il numero degli ospiti"<<endl;
		cin>>o;
		ospiti[cnt]=o;
		cout<<"Inserisci il numero della stanza"<<endl;
		cin>>s;
		stanze[cnt]=s;
		
		i=rand()%1000+1;
		ID[cnt]=i;
		
		p=(TARIFFA*notti[cnt]);
		prezzi[cnt]=p;
		
		cnt++;
	}
	
}

void visualizza(){
	
	
	for( int i=0;i<cnt;i++){
		
		if(stanze[i]!=-2){
		
		
			cout<<"ID PRENOTAZIONE "<<ID[i]<<endl;
			cout<<"MESE :"<<mese[i]<<endl;
			cout<<"NOTTI :"<<notti[i]<<endl;
			cout<<"OSPITI: "<<ospiti[i]<<endl;
			cout<<"STANZA :"<<stanze[i]<<endl;
			cout<<endl;
			cout<<"PREZZO: "<<prezzi[i]<<" euro"<<endl;
			cout<<endl;
		}
	}
}

void ricerca(int i){
	
	
	
	for(int k=0;k<DIM;k++){
		
		if(i==ID[k]){
		
			
			cout<<"PRENOTAZIONE TROVATA"<<endl;
			cout<<"--------------------"<<endl;
			cout<<"ID PRENOTAZIONE "<<ID[k]<<endl;
			cout<<"MESE :"<<mese[k]<<endl;
			cout<<"NOTTI :"<<notti[k]<<endl;
			cout<<"OSPITI: "<<ospiti[k]<<endl;
			cout<<"STANZA :"<<stanze[k]<<endl;
			cout<<endl;
			cout<<"PREZZO: "<<prezzi[i]<<" euro"<<endl;
			cout<<endl;

			break;
		}	
		
	}
	
	
}

void  modifica(){
	
	int modified;
	
	cout<<"INSERISCI L'INDICE DELLA PRENOTAZIONE DA MODIFICARE"<<endl;
	cin>>modified;
	
	
	for(int k=0;k<DIM;k++){
		
		
		if(modified==ID[k]){
			
				
			cout<<"Inserisci il mese"<<endl;
			cin>>m;
			mese[k]=m;
			cout<<"Inserisci il numero delle notti"<<endl;
			cin>>n;
			notti[k]=n;
			cout<<"Inserisci il numero degli ospiti"<<endl;
			cin>>o;
			ospiti[k]=o;
			cout<<"Inserisci il numero della stanza"<<endl;
			cin>>s;
			stanze[k]=s;
			
			p=(TARIFFA*notti[cnt]);
			prezzi[cnt]=p;
			
			cout<<"Modifica Effettuata"<<endl;
			cout<<"\n";	
				
			break;	
			
		}
		
	}
	
		
}

void cancella(){
	
	int modified;

	
	cout<<"INSERISCI L'INDICE DELLA PRENOTAZIONE DA CANCELLARE"<<endl;
	cin>>modified;
	
	
	for(int k=0;k<DIM;k++){
		
		
		if(modified==ID[k]){
			
			liberi[nDisponibili]=stanze[k];
			nDisponibili++;
			
			mese[k]="";
			notti[k]=0;		//Inizializzo a 0 i vettori di quell'indice
			stanze[k]=-2;		//Ho assengnato -2 alla stanza per far si che quando vado alla ricerca dei posti liberi dica che quella stanza è vuota
			ospiti[k]=0;
				
			cout<<"Cancellazione Effettuata"<<endl;
			cout<<"\n";	
			break;	
			
		}
	}
		
}



void ricerca_posti(){
	
	cout<<"Posti Liberi "<<endl;
	
	for(int i=0;i<nDisponibili;i++){
		
		cout<<liberi[i]<<"\t";
	}
	cout<<endl;
	
	
}
		
	

void controllo(int scelta){
	
	switch(scelta){
		
		case 1:
			riempi();
			system("PAUSE");
			system("CLS");
		break;
		
		case 2:
			visualizza();
			
			system("PAUSE");
			system("CLS");
		break;
		
		case 3:
			
			int id,indice;
			
			cout<<"Inserire l'Id da ricercare"<<endl;
			cin>>id;
			
			ricerca(id);
			
			
			
			system("PAUSE");
			system("CLS");
		break;
		
		case 4:
			modifica();
			
			system("PAUSE");
			system("CLS");
		break;
		
		case 5:
			cancella();
			
			system("PAUSE");
			system("CLS");
		break;
		
		case 6:
			ricerca_posti();
			
			system("PAUSE");
			system("CLS");
		break;
		
		case 7:
			
			abort();
			
		break;	
								
	}
	
}


