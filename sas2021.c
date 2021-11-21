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

//********* function Create bank account******************
void CreateAccount(BankAccount *CB)
{
    printf("Please enter information about this account\n");
    printf("CIN==>");
    scanf("%s", CB->CIN);
    printf("Fullname==>");
    fflush(stdin);
    gets(CB->FullName);
    printf("Money==>");
    scanf("%f", &CB->Money);
}
//********** function create Bank Accounts*********
void CreateAccounts(BankAccount *CB, int nbrAccount)
{
    int i;
    // reserve memory for Accounts
    for (i = 0; i < nbrAccount; i++)
    {
        CreateAccount(&CB[i]);
    }
}
//**********finction Display Accounts***********
void DisplayAccounts(BankAccount *CB, int nbrAccount)
{
    int i;
    for (i = 0; i < nbrAccount; i++)
    {
        printf("**********************************\n");
        printf("     Info fot account number %d\n", i + 1);
        printf("CIN==>%s\n", CB[i].CIN);
        printf("Fullname==>%s\n", CB[i].FullName);
        printf("Money==>%.4f DH\n", CB[i].Money);
        printf("**********************************\n");
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
//************* function check user is here!**************

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
        printf("%f\n", CB[i].Money);
    }
    else
        printf("isn't here\n");
}
// ************ function for Retrait*************
void DoRetreit(BankAccount *CB, int nbrAccount)
{

    float retrait = 0, money;
    char CIN[10];
    int i, j = 0;
    printf("enter CIN of user");
    fflush(stdin);
    gets(CIN);
    if (IfExist(CB, CIN, nbrAccount) >= 0)
    {
        i = IfExist(CB, CIN, nbrAccount);
        do
        {
            CB[i].Money = CB[i].Money + retrait;
            printf("hna %f \n", CB[i].Money);

            if (j == 0)
            {
                printf("Please add how much money\n");
            }
            else
                printf("Please enter  how much money  but not your account be <0DH\n");
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
//*****************************function main***********************
int main()
{
    BankAccount *CB = NULL;
    int nbrAccount;
    int option, operation, affichage;
    system("cls");
    printf("tape enter pour commence\n");
    system("pause");

    do
    { system("cls");
        printf("*******MENU*************\n");
        printf("1.Introduire un compte bancaire\n");
        printf("2.Introduire plusieurs comptes bancaires\n");
        printf("3.choisi d'un Operations :\n- Retrait\n- Depot \n ");
        printf("4.affiche des comptes bancaires\n");
        printf("Veuillez choisi votre choit:");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("still working .........\n");
            system("pause");
            break;
        case 2:
            printf("enter number of Accounts\n");
            scanf("%d", &nbrAccount);
            CB = (BankAccount *)malloc(nbrAccount * sizeof(BankAccount));
            CreateAccounts(CB, nbrAccount);
            break;
        case 3:
            system("cls");
            printf("Quelle oreration vous voulez faire\n");
            printf("1.- Retrait\t 2.- Depot");
            scanf("%d", &operation);
            if (operation == 1)
                AddDeposit(CB, nbrAccount);
            else
                DoRetreit(CB, nbrAccount);
            break;
        case 4:
            system("cls");
            printf("******affichage******\n");
            printf("1.Par Ordre Ascendant\n");
            printf("2.Par Ordre Descendant\n");
            printf("5.Recherche par CIN\n");
            printf("Veuillez choisi votre choit:");
                scanf("%d", &affichage);
            if (affichage == 1)
            {   system("cls");
                SortedAsc(CB, nbrAccount);
                DisplayAccounts(CB, nbrAccount);
                system("pause");
            }
            else if (affichage == 2)
            {   system("cls");
                SortedDesc(CB, nbrAccount);
                DisplayAccounts(CB, nbrAccount);
                system("pause");
            }else if(affichage==5){
                int i;
                char CIN[10];
                printf("veuillez enter CIN \n");
                scanf("%s",CIN);
                i = IfExist(CB, CIN, nbrAccount);
                DisplayAccount(CB, i,nbrAccount);
                system("pause");
            }
            break;
        case 0:printf("au revoir!!!!!\n");
            exit(0);
        default:
            break;
        }
    } while (option != 0);
    system("cls");
    DoRetreit(CB, nbrAccount);
    free(CB);
    return 0;
}