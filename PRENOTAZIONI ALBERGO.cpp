#include<iostream>
#include<cstdlib>
#include<ctime>
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
int moltiplicatore(int[],int);

//Variabili Globali
int scelta,cnt=0,index=0,prezzo,molti;  //molti=moltipilicatore
const int TARIFFA=10;
const int DIM=12;
int ID[DIM],mese[DIM],ospiti[DIM],costo[DIM],notti[DIM],stanze[DIM],eliminate[DIM];
int m,o,c,n,s,i;

//Main
int main(){
	
	srand(time(NULL));
	
	while(scelta!=7){
		
		scelta=menu();
		controllo(scelta);
	}
	
  return 0;	
}

int menu(){
	
	int s;
	
	cout<<"1 PER INSERIRE PRENOTAZIONE"<<endl;
	cout<<"2 PER VISUALIZZARE PRENOTAZIONE"<<endl;
	cout<<"3 PER RICERCARE PRENOTAZIONE"<<endl;
	cout<<"4 PER MODIFICARE PRENOTAZIONE"<<endl;
	cout<<"5 PER CANCELLARE PRENOTAZIONE"<<endl;
	cout<<"6 PER RICERCARE POSTI LIBERI"<<endl;
	cout<<"7 PER USCIRE ------>        "<<endl;
	cout<<endl;
	cout<<"INSERIRE LA TUA SCELTA"<<endl;
	cin>>s;
	
	return s;
}

void riempi(){
	
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
	
	cnt++;
	
	molti=moltiplicatore(mese,cnt);
	
	costo[cnt]=TARIFFA*notti[cnt]*molti;
	
}

void visualizza(){
	
	
	for( int i=0;i<cnt;i++){
		
		cout<<"ID PRENOTAZIONE "<<ID[i]<<endl;
		cout<<"MESE :"<<mese[i]<<endl;
		cout<<"NOTTI :"<<notti[i]<<endl;
		cout<<"OSPITI: "<<ospiti[i]<<endl;
		cout<<"STANZA :"<<stanze[i]<<endl;
		cout<<endl;
		cout<<"COSTO DEL SOGGIORNO :"<<costo[i]<<endl;
	}
}

void ricerca(int i){
	
	
	
	for(int k=0;k<DIM;k++){
		
		if(i==ID[k]){
			
			cout<<"PRENOTAZIONE TROVATA"<<endl;
			cout<<"ID PRENOTAZIONE "<<ID[k]<<endl;
			cout<<"MESE :"<<mese[k]<<endl;
			cout<<"NOTTI :"<<notti[k]<<endl;
			cout<<"OSPITI: "<<ospiti[k]<<endl;
			cout<<"STANZA :"<<stanze[k]<<endl;
			cout<<endl;
			cout<<"COSTO DEL SOGGIORNO"<<costo[k]<<endl;
			

			break;
		}
		else	
			cout<<"Prenotazione Inesistente"<<endl;			
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
				
			break;	
			
		}
		
	}
	
		
}

void cancella(){
	
	int modified;
	
	cout<<"INSERISCI L'INDICE DELLA PRENOTAZIONE DA MODIFICARE"<<endl;
	cin>>modified;
	
	
	for(int k=0;k<DIM;k++){
		
		
		if(modified==ID[k]){
			
				
			eliminate[index]=cnt;
			mese[k]=0;
			notti[k]=0;		//Inizializzo a 0 i vettori di quell'indice
			stanze[k]=-2;		//Ho assengnato -2 alla stanza per far si che quando vado alla ricerca dei posti liberi dica che quella stanza è vuota
			ospiti[k]=0;
				
			break;	
			
		}
		
	}


	

		
	
		

	
				
}

void ricerca_posti(){
	
	
	int nDisponibili=0;
	int nonDisponibili=0;
	
	for(int i=0;i<=DIM;i++){
		
		if(stanze[i]==-2){
			
			nDisponibili++;
			
		}
		else{
			
			nonDisponibili++;
		}
	}
	
	cout<<"Sono disponibili "<<nDisponibili<<" posti"<<endl;
	cout<<"Non sono disponibili "<<nonDisponibili<<" posti"<<endl;
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
		
		default:
			cout<<"USCITA EFFETTUATA"<<endl;						
	}
	
}

int moltiplicatore(int mese[],int cnt){		//Casistiche del moltiplicatore
	
	int m;
	
	switch(mese[cnt]){
		
		case 1:
			m=2;
		break;
		
		case 2:
			m=3;
		break;
		
		case 3:
			m=4;
		break;
		
		case 4:
			m=5;
		break;
		
		case 5:
			m=7;
		break;
		
		case 6:
			m=9;
		break;
		
		case 7:
			m=12;
		break;
		
		case 8:
			m=15;
		break;
		
		case 9:
			m=14;
		break;
		
		case 10:
			m=5;
		break;
		
		case 11:
			m=3;
		break;
		
		case 12:
			m=1;
		break;												
	}
	
	return m;
}


