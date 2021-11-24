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