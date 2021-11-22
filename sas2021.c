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
    printf("Veuillez enter les information de ce compte\n");
    printf("CIN==>");
    scanf("%s", CB[allAccounts].CIN);
    printf("Fullname==>");
    fflush(stdin);
    gets(CB[allAccounts].FullName);
    printf("Money==>");
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
void DisplayAccounts(BankAccount *CB, int nbrAccount)
{
    int i;
    for (i = 0; i < nbrAccount; i++)
    {
        printf("******************************\n");
        printf("   Information  pour compte num  %d\n", i + 1);
        printf("CIN==>%s\n", CB[i].CIN);
        printf("Fullname==>%s\n", CB[i].FullName);
        printf("Money==>%.4f DH\n", CB[i].Money);
        printf("*******************************\n");
        printf("\n");
    }
}
// *******8 function display one account by index**********
void DisplayAccount(BankAccount *CB, int index,int nbrAccount)
{
   int i;
    
    for ( i = 0; i < nbrAccount; i++)
    {
        if (i==index)
        {  
        printf("**********************************\n");
        printf("     Info fot account number %d\n", index + 1);
        printf("CIN==>%s\n", CB[index].CIN);
        printf("Fullname==>%s\n", CB[index].FullName);
        printf("Money==>%.4f DH\n", CB[index].Money);
        printf("**********************************\n");
        printf("\n");
        }
        
    }
    
    
}
//************* function check user is exist!**************
int IfExist(BankAccount *CB, char CIN[10], int nbrAccount)
{
    int i;
    for (i = 0; i < nbrAccount; i++)
    {
        if (strcmp(CB[i].CIN, CIN) == 0)
        {
            return i;
        }
    }
    return -1;
}
// ************ function for do deposit*************
void AddDeposit(BankAccount *CB, int nbrAccount)
{
    float deposit;
    char CIN[10];
    int i;
    printf("enter CIN of user");
    fflush(stdin);
    gets(CIN);
    if (IfExist(CB, CIN, nbrAccount) >= 0)
    {   
        printf("Please add how much money\n");
        scanf("%f", &deposit);
        i = IfExist(CB, CIN, nbrAccount);
        CB[i].Money = CB[i].Money + deposit;
        printf("Le nouveau sold est:\t");
        printf("%f\n", CB[i].Money);
    }
    else if(IfExist(CB, CIN, nbrAccount) < 0) {
        printf("%d",IfExist(CB, CIN, nbrAccount));
        printf("isn't here\n");
    }
}
// ************ function for Retrait*************
void DoRetreit(BankAccount *CB, int nbrAccount)
{

    float retrait = 0, money;
    char CIN[10];
    int i, j = 0;
    printf("Veuillez enter CIN de ce compte");
    fflush(stdin);
    gets(CIN);
    if (IfExist(CB, CIN, nbrAccount) >= 0)
    {
        i = IfExist(CB, CIN, nbrAccount);
        do
        {   j=0;
            CB[i].Money = CB[i].Money + retrait;
            printf("Ce compte a  %f DH \n", CB[i].Money);

            if (j == 0)
            {
                printf("Veuillez enter combien d'argon voulez vous retrait\n");
            }
            else printf("s'ils vous plait entrer nombre moin de %f\n",CB[i].Money );
            scanf("%f", &retrait);
            printf("before %f \n", CB[i].Money);
            CB[i].Money = CB[i].Money - retrait;
            printf("after %f \n", CB[i].Money);
            j++;
        } while (CB[i].Money < 0);
    }
    else
        printf("isn't here\n");
}
//*****************************function for sorted ASC**********************
void SortedAsc(BankAccount *CB, int nbrAccount)
{
    int i,j;
    float Money;
    BankAccount new;
   
    for (i = 0; i < nbrAccount - 1; i++)
    {
        for (j = i + 1; j < nbrAccount; j++){

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
void SortedDesc(BankAccount *CB, int nbrAccount)
{
    int i,j;
    float Money;
    BankAccount new;
    for (i = 0; i < nbrAccount - 1; i++)
    { 
        for (j = i + 1; j < nbrAccount; j++){

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
void Loyalty(BankAccount *CB,int nbrAccount){
    int i ;
    SortedDesc(CB, nbrAccount);
    for (i=0;i< nbrAccount;i++){
        if (i<3)
        {
            CB[i].Money+=CB[i].Money*1.3/100;
        }
        
    }
}
//*****************************function SortedAscByChiffre ***********************

// void SortedAscByChiffre(BankAccount *CB,int nbrAccount){
//     int i;
//      SortedAsc(CB,  nbrAccount);
//      for(i=0;i<nbrAccount){
         
//      }
// }
//*****************************function main***********************
int main()
{
    CB = malloc(size * sizeof(BankAccount));
 
    int option, operation, affichage,nbrAccount;
    system("cls");
    printf("tape enter pour commence\n");
    system("pause");
    do
    { system("cls");
        printf("*******MENU*************\n");
        printf("1.Introduire un compte bancaire\n");
        printf("2.Introduire plusieurs comptes bancaires\n");
        printf("3.choisi d'un Operations :\n- Retrait\n- Depot\n");
        printf("4.affiche des comptes bancaires\n");
        printf("5.Fidélisation\n");
        printf("0.Quitter l'application :)\n");
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
            printf("Quelle oreration vous voulez faire\n");
            printf("1.- Retrait\t 2.- Depot\n");
            printf("Veuillez enter voter option ICI!!:");
            scanf("%d", &operation);
            if (operation == 1)
                DoRetreit(CB, nbrAccount);
            else
                AddDeposit(CB, nbrAccount);
            system("pause");
            break;
        case 4:
            // system("cls");
            // printf("******affichage******\n");
            // printf("1.Par Ordre Ascendant\n");
            // printf("2.Par Ordre Descendant\n");
            // printf("3.Par Ordre Ascendant (les comptes bancaire ayant un montant supérieur à un chiffre introduit)  ");
            // printf("5.Recherche par CIN\n");
            // printf("Veuillez choisi votre choit:");
            //     scanf("%d", &affichage);
            // if (affichage == 1)
            // {   system("cls");
            //     SortedAsc(CB, allAccounts);
            //     DisplayAccounts(CB, allAccounts);
            //     system("pause");
            // }
            // else if (affichage == 2)
            // {   system("cls");
            //     SortedDesc(CB, allAccounts);
            //     DisplayAccounts(CB, allAccounts);
            //     system("pause");
            // }else if(affichage==5){
            //     int i;
            //     char CIN[10];
            //     printf("veuillez enter CIN \n");
            //     scanf("%s",CIN);
            //     i = IfExist(CB, CIN, allAccounts);
            //     DisplayAccount(CB, i,allAccounts);
            //     system("pause");
            // }
            
               for (int i = 0; i < allAccounts; i++)
    {
        printf("******************************\n");
        printf("   Information  pour compte num  %d\n", i + 1);
        printf("CIN==>%s\n", CB[i].CIN);
        printf("Fullname==>%s\n", CB[i].FullName);
        printf("Money==>%.4f DH\n", CB[i].Money);
        printf("*******************************\n");
        printf("\n");
    }
            system("pause");
            
            break;
        case 5: Loyalty(CB, allAccounts);
            DisplayAccounts(CB, allAccounts);
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