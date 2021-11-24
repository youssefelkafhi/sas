#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// *******define Bank Account*****
typedef struct Cb
{
    char CIN[10];
    char FullName[30];
    float Money;
} BankAccount;

int allAccounts=0;
int size=10;
BankAccount *CB;
//********* function Create bank account******************
void CreateAccount()
{  
     if(size==allAccounts){
         size=size*2;
        CB = realloc(CB,size*sizeof(BankAccount));
     }
     printf("\n");
    printf("Veuillez enter les information de ce compte\n");
    printf("CIN==>");
    scanf("%s", CB[allAccounts].CIN);
    printf("Non et Prenon==>");
    fflush(stdin);
    gets(CB[allAccounts].FullName);
    printf("Montant(DH)==>");
    scanf("%f", &CB[allAccounts].Money);
allAccounts++;
}
//********** function create Bank Accounts*********
void CreateAccounts( int nbrAccount)
{
    int i;
    // reserve memory for Accounts
    for (i = 0; i < nbrAccount; i++)
    {   printf("compte num %d\n",i+1);
        CreateAccount();
    }
}
//**********finction Display Accounts***********
void DisplayAccounts( )
{
    for (int i = 0; i < allAccounts; i++)
    {
        printf("******************************\n");
        printf("   Information  pour compte num  %d\n", i + 1);
        printf("CIN==>%s\n", CB[i].CIN);
        printf("Non et Prenon==>%s\n", CB[i].FullName);
        printf("Montant==>%.4f DH\n", CB[i].Money);
        printf("*******************************\n");
        printf("\n");
    }
}
// *******8 function display one account by index**********
void DisplayAccount(int index)
{
   
    
    for (int i = 0; i < allAccounts; i++)
    {
        if (i==index)
        {  
        printf("**********************************\n");
        printf("     Info fot account number %d\n", index + 1);
        printf("CIN==>%s\n", CB[index].CIN);
        printf("Non et Prenon==>%s\n", CB[index].FullName);
        printf("Montant==>%.4f DH\n", CB[index].Money);
        printf("**********************************\n");
        printf("\n");
        }
        
    }
    

}
//************* function check user is exist!**************
int IfExist(char CIN[10])
{
    
    for (int i = 0; i < allAccounts; i++)
    {
        if (strcmp(CB[i].CIN, CIN) == 0)
        {
            return i;
        }
    }
    return -1;
}
// ************ function for do deposit*************
void AddDeposit( )
{
    float deposit;
    char CIN[10];
    int createAccount;
    int i;
    printf("enter CIN de client : ");
    fflush(stdin);
    gets(CIN);
    if (IfExist(CIN) >= 0)
    {   
        i = IfExist(CIN);
        printf("Le solde de ce compte est :\t");
        printf("%f DH\n", CB[i].Money);
        printf("Veuillez entrer conbien d'argent voulez vous depot\n");
        scanf("%f", &deposit);
        printf("\n");
        CB[i].Money = CB[i].Money + deposit;
        printf("-->l'operation est bien effectuee\n");
        printf("\n");
        printf("Le nouveau sold est:\t");
        printf("%f DH\n", CB[i].Money);
    }
    else if(IfExist(CIN) < 0) {
        printf("Le client n'est pas trouver,Est ce que voulez vous creaer un compte?\n-->si oui clicke 1\n-->si nom clicke 2\n");
        printf("\n");
        scanf("%d",&createAccount);
        if(createAccount==1){
          
           CreateAccount( );
           printf("Maintenant vous peuvez passer a l'operartion depot\n");
           AddDeposit( );
        }
    }
}
// ************ function for Retrait*************
void DoRetreit()
{

    float retrait = 0   ;
    char CIN[10];
    int index, j = 0;
    printf("Veuillez enter CIN de ce compte :");
    fflush(stdin);
    gets(CIN);
    if (IfExist(CIN) >= 0)
    {j=0;
        index = IfExist(CIN);
        do
        {   
            CB[index].Money = CB[index].Money + retrait;
            printf("Le sold de ce compte est : %f DH \n", CB[index].Money);
            if (j == 0) printf("Veuillez enter combien d'argon voulez vous retrait\n");
            else{
            printf("-->Le sold ne permet pas de faire cette l'operation<--\n");
             printf("s'ils vous plait entrer nombre moin de %f\n",CB[index].Money );
             }   
            scanf("%f", &retrait);
            printf("Avant l'operation  %f DH\n", CB[index].Money);
            CB[index].Money = CB[index].Money - retrait;
            printf("Apres l'operation %f DH\n", CB[index].Money);
            j++;
            if(CB[index].Money>0)printf("-->L'operatin est bien effectuee\n");
        } while (CB[index].Money < 0);
        DisplayAccount(index);
    }
    else
        printf("-->Le client n'a pas trouve<-- \n");
}
//*****************************function for sorted ASC**********************
void SortedAsc()
{
    int i,j;
    float Money;
    BankAccount new;
   
    for (i = 0; i < allAccounts - 1; i++)
    {
        for (j = i + 1; j < allAccounts; j++){

            if (CB[j].Money < CB[i].Money)
            {
                new=CB[i];
                CB[i]=CB[j];
                CB[j]=new;
                
            }
        }
    }
}
//*****************************function for sorted ASC**********************
void SortedDesc()
{
    int i,j;
    float Money;
    BankAccount new;
    for (i = 0; i < allAccounts - 1; i++)
    { 
        for (j = i + 1; j < allAccounts; j++){

            if (CB[j].Money > CB[i].Money)
            {
                new=CB[i];
                CB[i]=CB[j];
                CB[j]=new;  
            }
        }
    }
}

//*******************function for users loyalty***********************
void Loyalty(){
    int i ;
    SortedDesc();
    for (i=0;i< allAccounts;i++){
        if (i<3)
        {
            CB[i].Money+=CB[i].Money*1.3/100;
            DisplayAccount(i);
        } 
    }
}
//*****************************function SortedAscByChiffre **********************
void SortedAscByChiffre(float Chiffre){
     SortedAsc();
     for(int i=0;i<allAccounts;i++){
         if(CB[i].Money>=Chiffre){
              DisplayAccount(i);
         }
     }
   
     
}
//*****************************function SortedDescByChiffre ***********************
void SortedDescByChiffre(float Chiffre){
     SortedDesc();
     for(int i=0;i<allAccounts;i++){
         if(CB[i].Money>=Chiffre){
              DisplayAccount(i);
         }
     }
}
//*****************************function do transactionnbetween two accounts***********************
void DoTransaction(){
    int cinA,cinB;
    char CINA[10],CINB[10];
    float transaction;
    printf("Veuillez entrer CIN d'emetteur\n");
    scanf("%s",CINA);
    printf("Veuillez entrer CIN de destinataire\n");
    scanf("%s",CINB);
    cinA = IfExist( CINA);
    // printf("*********%d",IfExist( CINA));
    // system("pause");
    cinB = IfExist(CINB);
    // printf("********%d",IfExist(CINB));
    // system("pause");
    printf("Veuillez enter le nombre de transaction\n");
        scanf("%f",&transaction);
    if (cinA>=0 && cinB>=0){
        
        CB[cinA].Money-= transaction;
        // printf("%f",CB[cinA].Money);
        // system("pause");
        CB[cinB].Money+=transaction;
        // printf("%f",CB[cinB].Money);
        // system("pause");
        printf("la transaction est bien effectuee entre les deux compte\n");
        DisplayAccount(cinA);
        DisplayAccount(cinB);
    }else if(cinA<0 || cinB<0 ){
        printf("il n'a pas d'un compte parmi les deux\n");
    }
}

//*****************************function display menu of display***********************
void MenuDisplay(){
   
    printf("1.Par Ordre Ascendant\n");
    printf("2.Par Ordre Descendant\n");
    printf("3.Par Ordre Ascendant (les comptes bancaire ayant un montant superieur a un chiffre introduit)\n");
    printf("4.Par Ordre Descendant (les comptes bancaire ayant un montant superieur a un chiffre introduit)\n");
    printf("5.Recherche par CIN\n");
    printf("0.Retour a menu principal\n");
}
//*****************************function menu principle***********************
void MenuPrinciple(){
    printf("*******MENU*************\n");
    printf("1.Introduire un compte bancaire\n");
    printf("2.Introduire plusieurs comptes bancaires\n");
    printf("3.choisi d'un Operations :\n- Retrait\n- Depot\n");
    printf("4.affiche des comptes bancaires\n");
    printf("5.Fidelisation\n");
    printf("6.Faire transaction\n");
    printf("0.Quitter l'application :)\n");
}
//*****************************function menu operation**********************
void MenuOperation(){
    printf("Quelle oreration vous voulez faire\n");
    printf("1.--> Retrait\n 2.--> Depot\n");
}
//*****************************function main***********************
int main()
{
    CB = malloc(size * sizeof(BankAccount));
    int option, operation, affichage,nbrAccount;
    float Chiffre;
    system("cls");
    printf("tape enter pour commence\n");
    system("pause");
    do
    { 
        system("cls");
         MenuPrinciple();
        printf("Veuillez choisi votre choit:");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            CreateAccount();
            system("pause");
            break;
        case 2:
            system("cls");
            printf("Veuillez entrer le nombre des comptes\n");
            scanf("%d", &nbrAccount);
            CreateAccounts( nbrAccount);
            system("pause");
            break;
        case 3:
            system("cls");
            MenuOperation();
            do{
            printf("Veuillez enter voter option  (1 ou 2)ICI!!:");
            scanf("%d", &operation);
            }while(operation<1||operation>2);
            if (operation == 1)DoRetreit();
            else if(operation == 2)AddDeposit();
                
            system("pause");
            break;
        case 4:

            system("cls");
             printf("******affichage******\n");
            MenuDisplay();
            do{
            printf("Veuillez choisir :");
                scanf("%d", &affichage);
            }while(affichage <0 || affichage>5);
            if (affichage == 1)
            {   system("cls");
                printf("-->Affichage Par Ordre Ascendant<--\n ");
                SortedAsc( allAccounts);
                DisplayAccounts();
                system("pause");
            }
            else if (affichage == 2)
            {   system("cls");
                printf("-->Affichage par Ordre Descendan<--\n ");
                SortedDesc();
                DisplayAccounts();
                system("pause");
            }else if (affichage == 3)
            {   system("cls");
                printf("-->Affichage par Ordre Ascendant (Chiffre)<--\n ");
                printf("Veuillez entrer le chiffre\n");
                scanf("%f",&Chiffre);
                SortedAscByChiffre(Chiffre);
                system("pause");
            }else if (affichage == 4)
            {   system("cls");
                printf("-->Affichage par Ordre Descendan (Chiffre)<--\n ");
                printf("Veuillez entrer le chiffre\n");
                scanf("%f",&Chiffre);
                SortedDescByChiffre(Chiffre);
                system("pause");
            }else if(affichage==5){
               system("cls");
                printf("-->Recherche par CIN<--\n ");
                int index;
                char CIN[10];
                printf("veuillez enter CIN \n");
                scanf("%s",CIN);
                index = IfExist(CIN);
                DisplayAccount(index);
                system("pause");
            }else if (affichage==0) break;
            break;
        case 5:
            system("cls");
            printf("-->Fidelisation<--\n ");
            Loyalty();
            
            system("pause");
            break;
        case 6: 
            printf("-->Transaction<--\n ");
            DoTransaction();
            
            system("pause");
            break;
        case 0:
            free(CB);
            printf("au revoir!!!!!\n");
            system("pause");
            exit(0);
            break;
        default:
            break;
        }
    } while (option != 0);
    system("cls");
    return 0;
}