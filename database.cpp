#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define max 1000
int popullsia =  0;
FILE *fptr;

void menu();
void rikthe();
void regjistro();
void export_info();
void load_info();
int findID();
void modifikoTeDhenat();
void fshiTeDhenat();
void kerkoSipasEmrit();
void kerkoSipasMbiemrit();
void kerkoSipasNumritTelefonit();
void rradhitSipasEmrit();
void rradhitSipasMbiemrit();
void afishoTeDhenat();

struct Qytetar{
	char ID[20];
	char emri[20];
	char mbiemri[20];
	char nr_cel[10];
	char adresa[50];
	char email[50];
}test[max];


int main(){
	load_info();
	menu();
	return 0;
}

void menu(){
		system("cls");
		printf("Mire se erdhet!\n");
	printf("1-Regjistro nje qytetar te ri.\n");
	printf("2-Modifiko te dhenat.\n");
	printf("3-Fshi te dhenat e nje qytetari.\n");
	printf("4-Kerko sipas emrit.\n");
	printf("5-Kerko sipas mbiemrit.\n");
	printf("6-Afisho te dhenat e ruajtura me pare.\n");
	printf("7-Rradhit qytetaret sipas emrit.\n");
	printf("8-Rradhit qytetaret sipas mbiemrit.\n");
	printf("0-Dil nga programi.\n");
	
	while (true){
		int opsioni;
		scanf("%d", &opsioni);
		switch(opsioni){
			case 1	:
			regjistro();
			rikthe();
			break;
			
			case 2:
			modifikoTeDhenat();
			rikthe();
			break;
			
		     case 3:
			fshiTeDhenat();
			rikthe();
			break;
			
			case 4:
			kerkoSipasEmrit();
			rikthe();
			break;
			
			case 5:
			kerkoSipasMbiemrit();
			rikthe();
			break;
			
			case 6:
			afishoTeDhenat();
			rikthe();
			break;
			
			case 7:
			rradhitSipasEmrit();
			rikthe();
			break;
			
			case 8:
			rradhitSipasMbiemrit();
			rikthe();
			break;
			
			case 0:
				return;
				
			default:
			printf("\nOpsion i gabuar.Zgjidh perseri!");
			break;
				
}
}
}

void load_info(){
fptr = fopen("test.txt", "r");
if (fptr == NULL) {
        fprintf(stderr, "\nError ne hapjen e file-s!\n");
        exit(1);
    }
    int struktura;
	fptr = fopen("test.txt", "r");
	fscanf(fptr, "%d", &popullsia);
	for(int i = 0; i < struktura; i++){
		fscanf(fptr, "%s ", &test[i].emri);
		fscanf(fptr, "%s ", &test[i].mbiemri);
		fscanf(fptr, "%s ", &test[i].adresa);
		fscanf(fptr, "%s ", &test[i].ID);
		fscanf(fptr, "%s ", &test[i].nr_cel);
		fscanf(fptr, "%s ", &test[i].email);
	}
	fclose(fptr);
}

void export_info() {
fptr = fopen("test.txt", "w");
if (fptr == NULL) {
        fprintf(stderr, "\nError ne hapjen e file-s!\n");
        exit(1);
    }
	fptr = fopen("test.txt", "w");
	fprintf(fptr, "%d\n", popullsia);
	for(int i = 0; i < popullsia; i++){
		fprintf(fptr,"%s\n", test[i].emri);
		fprintf(fptr,"%s\n", test[i].mbiemri);
		fprintf(fptr,"%s\n", test[i].adresa);
		fprintf(fptr,"%s\n", test[i].ID);
		fprintf(fptr,"%s\n", test[i].nr_cel);
		fprintf(fptr,"%s\n", test[i].email);
	}
	fclose(fptr);
}
void rikthe() {
	printf("Do te zgjedhesh opsion tjeter?\n1 - po\n2 - jo\n\n:");
	int opsion;
	scanf("%d", &opsion);
	if(opsion == 1){
		menu();
	} else {
		exit(0);
	}
}

void regjistro(){
	if (popullsia < max){
		printf("\nEmri:");
        scanf("%s", test[popullsia].emri);
        printf("Mbiemri:");
        scanf("%s", test[popullsia].mbiemri);
        printf("ID:");
        scanf("%s", test[popullsia].ID);
        printf("Numri i telefonit:");
        scanf("%s", test[popullsia].nr_cel);
        printf("Adresa:");
        scanf("%s", test[popullsia].adresa);
        printf("Email:");
        scanf("%s", test[popullsia].email);
        popullsia++;
        export_info();
        printf("\nQytetari u regjistrua!.");
    } else {
        printf("\nNuk ka me vend ne databaze!");
    }
  }

int findID(){
	char find[20];
	printf("Vendos ID:");
	scanf("%s", find);
	int i;
    for(i = 0; i < popullsia; i++){
		if(strcmp(find, test[i].ID) == 0) {
		   return i;
		}
	}
	return -1;
}
void modifikoTeDhenat() {
int gjetur = findID ();
	if (gjetur == -1) {
        printf("Nuk u gjet asnje person me ID-in e dhënë.\n");
    }
	printf("Zgjidhni te dhënat për të ndryshuar:\n");
            printf("1. Emri\n");
            printf("2. Mbiemri\n");
            printf("3. Adresa\n");
            printf("4. Numri i telefonit\n");
            printf("5. Email\n");
            printf("0. Anulo\n");

            int opsioni;
            scanf("%d", &opsioni);

            switch (opsioni) {
                case 1:
                    printf("Emri i ri: ");
                    scanf("%s", test[gjetur].emri);
                    printf("Emri u ndryshua me sukses.\n");
                    break;
                case 2:
                    printf("Mbiemri i ri: ");
                    scanf("%s", test[gjetur].mbiemri);
                    printf("Mbiemri u ndryshua me sukses.\n");
                    break;
                case 3:
                    printf("Adresa e re: ");
                    scanf("%s", test[gjetur].adresa);
                    printf("Adresa u ndryshua me sukses.\n");
                    break;
                case 4:
                    printf("Numri i ri i telefonit: ");
                    scanf("%s", test[gjetur].nr_cel);
                    printf("Numri i telefonit u ndryshua me sukses.\n");
                    break;
                case 5:
                    printf("Email-i i ri: ");
                    scanf("%s", test[gjetur].email);
                    printf("Email-i u ndryshua me sukses.\n");
                    break;
                case 0:
                    printf("Ndryshimet u anuluan.\n");
                    break;
                default:
                    printf("Opsioni i zgjedhur nuk ekziston.\n");
					break;
            } 
}

void fshiTeDhenat() {
	
	int gjetur = findID();
	if (gjetur = -1) {
        printf("Nuk u gjet asnje person me ID-in e dhënë.\n");
    }
    int i;
    for(i = gjetur; i < popullsia; i++){
		test[i]=test[i+1];
		}
	popullsia--;
	export_info();
}

void kerkoSipasEmrit(){
	printf("Vendos emrin qe do te kerkosh:");
	char kerko_emer[50];
	scanf("%s", kerko_emer);
	printf("\nTe dhenat:\n");
	int i;
    for (i = 0; i < popullsia; i++) {
        if (strcmp (test[i].emri, kerko_emer)== 0) {
            printf("ID: %s\n", test[i].ID);
            printf("Emri: %s\n", test[i].emri);
            printf("Mbiemri: %s\n", test[i].mbiemri);
            printf("Adresa: %s\n", test[i].adresa);
            printf("Numeri i telefonit: %\n", test[i].nr_cel);
            printf("Email: %s\n", test[i].email);
    }
  }
}

void kerkoSipasMbiemrit(){
	printf("Vendos mbiemrin qe do te kerkosh:");
	char kerko_mbiemer[50];
	scanf("%s", kerko_mbiemer);
	printf("\nTe dhenat:\n");
	int i;
    for (i = 0; i < popullsia; i++) {
        if (strcmp (test[i].mbiemri, kerko_mbiemer)== 0) {
            printf("ID: %s\n", test[i].ID);
            printf("Mbiemri: %s\n", test[i].mbiemri);
            printf("Emri: %s\n", test[i].emri);
            printf("Adresa: %s\n", test[i].adresa);
            printf("Numeri i telefonit: %s\n", test[i].nr_cel);
            printf("Email: %s\n", test[i].email);
    }
  }
}
void kerkoSipasNumritTelefonit(){
	printf("Vendos numrin e telefonit qe do te kerkosh:");
	char kerko_nr[50];
	scanf("%s", kerko_nr);
	printf("\nTe dhenat:\n");
	int i;
    for (i = 0; i < popullsia; i++) {
        if (strcmp (test[i].nr_cel, kerko_nr)== 0) {
            printf("ID: %s\n", test[i].ID);
            printf("Numsri i telefonit: %s\n", test[i].nr_cel);
            printf("Emri: %s\n", test[i].emri);
            printf("Mbiemri: %s\n", test[i].mbiemri);
            printf("Adresa: %s\n", test[i].adresa);
            printf("Email: %s\n", test[i].email);
    }
  }
}

void afishoTeDhenat() {
    int i;
    printf("\nTë dhënat e personave:\n");
    for (i = 0; i < popullsia; i++) {
	if (popullsia == 0) {
        printf("Nuk ka të dhëna të regjistruara.\n");
        return;
	}
       else {
	    printf("Personi %d:\n", i);
        printf("ID: %d\n", test[i].ID);
        printf("Emri: %s\n", test[i].emri);
        printf("Mbiemri: %s\n", test[i].mbiemri);
        printf("Adresa: %s\n", test[i].adresa);
        printf("Numri i telefonit: %s\n", test[i].nr_cel);
        printf("Email: %s\n", test[i].email);
        printf("---------------------------\n");
	   } 
    }
}
void rradhitSipasEmrit() {
    if (popullsia == 0) {
        printf("Nuk ka të dhëna të regjistruara.\n");
        return;
    }
    int i,j;
    struct Qytetar temp[max];
    
    for ( i = 0; i < popullsia- 1; i++) {
        for (j = i + 1; j < popullsia; j++) {
            if (strcmp(test[i].emri, test[j].emri) > 0) {
				 temp[i]=test[i]; 
                test[i] = test[j];
                test[j] = temp[i];
            }
        }
    }

    printf("Qytetarët e rradhitur sipas emrit:\n");
    for (i = 0; i < popullsia; i++) {
        printf("Personi %d:\n", i);
        printf("ID: %d\n", test[i].ID);
        printf("Emri: %s\n", test[i].emri);
        printf("Mbiemri: %s\n", test[i].mbiemri);
        printf("Adresa: %s\n", test[i].adresa);
        printf("Numeri i telefonit: %s\n", test[i].nr_cel);
        printf("Email: %s\n", test[i].email);
        printf("---------------------------\n");
    }
    export_info();
}
void rradhitSipasMbiemrit() {
    if (popullsia == 0) {
        printf("Nuk ka të dhëna të regjistruara.\n");
        return;
    }
    int i,j;
    struct Qytetar temp[max];
    for ( i = 0; i < popullsia- 1; i++) {
        for (j = i + 1; j < popullsia; j++) {
            if (strcmp(test[i].mbiemri, test[j].mbiemri) > 0) {
				 temp[i]=test[i]; 
                test[i] = test[j];
                test[j] = temp[i];
            }
        }
    }

    printf("Qytetarët e rradhitur sipas mbiemrit:\n");
    for (i = 0; i < popullsia; i++) {
        printf("Personi %d:\n", i);
        printf("ID: %d\n", test[i].ID);
        printf("Emri: %s\n", test[i].emri);
        printf("Mbiemri: %s\n", test[i].mbiemri);
        printf("Adresa: %s\n", test[i].adresa);
        printf("Numri i telefonit: %s\n", test[i].nr_cel);
        printf("Email: %s\n", test[i].email);
        printf("---------------------------\n");
    }
    export_info();
}
