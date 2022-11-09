#include<iostream>
using namespace std;

//Prototipi Funzioni
int menu();
void riempi();
void visualizza();
void ricerca();
int modifica(int);
int cancella(int);
void ricerca_posti();
void controllo(int);
int moltiplicatore(int[],int);

//Variabili Globali
int scelta,cnt=0,index=0,prezzo,molti;  //molti=moltipilicatore
const int TARIFFA=10;
const int DIM=12;
int ID[DIM],mese[DIM],ospiti[DIM],costo[DIM],notti[DIM],stanze[DIM],eliminate[DIM];

//Main
int main(){
	
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
	cin>>mese[cnt];
	cout<<"Inserisci il numero delle notti"<<endl;
	cin>>notti[cnt];
	cout<<"Inserisci il numero degli ospiti"<<endl;
	cin>>ospiti[cnt];
	cout<<"Inserisci il numero della stanza"<<endl;
	cin>>stanze[cnt];
	cout<<"Inserisci L'ID d'associare alla prenotazione"<<endl;
	cin>>ID[cnt];
	
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

void ricerca(){
	
	cout<<"INSERIRE IL NUMERO DELLA PRENOTAZIONE"<<endl;
	cin>>index;
	
	for(int k=0;k<DIM;k++){
		
		if(index==ID[k]){
			
			cout<<"PRENOTAZIONE TROVATA"<<endl;
			cout<<"ID PRENOTAZIONE "<<ID[index]<<endl;
			cout<<"MESE :"<<mese[index]<<endl;
			cout<<"NOTTI :"<<notti[index]<<endl;
			cout<<"OSPITI: "<<ospiti[index]<<endl;
			cout<<"STANZA :"<<stanze[index]<<endl;
			cout<<endl;
			cout<<"COSTO DEL SOGGIORNO"<<costo[index]<<endl;
			
			break;
		}			
	}	
}

int modifica(int cnt){
	
	cout<<"INSERISCI L'INDICE DELLA PRENOTAZIONE DA MODIFICARE"<<endl;
	cin>>cnt;
	
	cout<<"Inserisci il mese"<<endl;
	cin>>mese[cnt];
	cout<<"Inserisci il numero delle notti"<<endl;
	cin>>notti[cnt];
	cout<<"Inserisci il numero degli ospiti"<<endl;
	cin>>ospiti[cnt];
	cout<<"Inserisci il numero della stanza"<<endl;
	cin>>stanze[cnt];
	cout<<"Inserisci L'ID d'associare alla prenotazione"<<endl;
	cin>>ID[cnt];
	
}

int cancella(int cnt){
	
	cout<<"INSERISCI L'INDICE DELLA PRENOTAZIONE DA CANCELLARE"<<endl;
	cin>>cnt;
	
	eliminate[index]=cnt;
	mese[cnt]=0;
	notti[cnt]=0;		//Inizializzo a 0 i vettori di quell'indice
	stanze[cnt]=-2;		//Ho assengnato -2 alla stanza per far si che quando vado alla ricerca dei posti liberi dica che quella stanza è vuota
	ospiti[cnt]=0;			
}

void ricerca_posti(){
	
	
	for(int i=0;i<=DIM;i++){
		
		if((ID[i]==0)||(stanze[i]==-2)){
			
			cout<<"POSTO "<<i<< " DISPONIBILE "<<endl;

		}
		cout<<"POSTO "<<i<< "NON DISPONIBILE"<<endl;
	}
}
		
	

void controllo(int scelta){
	
	switch(scelta){
		
		case 1:
			riempi();
			cnt++;	
			system("PAUSE");
			system("CLS");
		break;
		
		case 2:
			visualizza();
			
			system("PAUSE");
			system("CLS");
		break;
		
		case 3:
			ricerca();
			
			system("PAUSE");
			system("CLS");
		break;
		
		case 4:
			modifica(cnt);
			
			system("PAUSE");
			system("CLS");
		break;
		
		case 5:
			cancella(cnt);
			
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


