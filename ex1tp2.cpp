#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct patient{
	char nom[20];
	char prenom[20];
	int  age;
}patient;
typedef struct liste{
	patient data;
	struct liste *next;
}liste;
 void read(liste **L){
      liste* e=(liste*)malloc(sizeof(liste));
 	  printf("saisir le nom du patient:\n");
 	  scanf("%s",e->data.nom);
 	  printf("saisir le prenom de patient:\n");
 	  scanf("%s",e->data.prenom);
 	  printf("saisir l'age du patient: \n");
 	  scanf("%d",&e->data.age);
 	  e->next=*L;
 	  *L=e;
	 }
void printListe(liste *L){
	liste *p=L;
	printf("|le nom |le prenom |l'age | \n");
	while(p != 0){
	printf("%s \t",p->data.nom);
	printf("%s \t",p->data.prenom);
	printf("%d \t",p->data.age);
	printf("\n");
	p=p->next;}
}
void   chercher(liste *L,liste **q){
	  int max,i,j;
	  liste *p=L;
    	max=p->data.age;
    	while(p!=NULL){
    		if(p->data.age>=max){
    		   max=p->data.age;
    	       *q=p;
    	    }
    	    p=p->next;
	     }
	}
int main()
{ 
	liste *L=0;
	int a;
	liste *q;
	printf("saisir le nombre 1 pour saisir un patient: \n");
		scanf("%d",&a);
	do{ read(&L);
		printf("saisir le nombre 1 pour saisir un patient: \n");
		scanf("%d",&a);
	}while(a==1);
	printf("\n-------les elements de la liste-------\n");
	printListe(L);
	chercher(L,&q);
	printf("le patient le plus age est: %s %s",q->data.nom,q->data.prenom);
	}
