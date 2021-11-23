if (cinA>=0 && cinB>=0){
        
        CB[cinA].Money-= transaction;
        printf("%f",CB[cinA].Money);
        system("pause");
        CB[cinB].Money+=transaction;
        printf("%f",CB[cinB].Money);
        system("pause");
        printf("la transaction est bien effectuee\n");
    }else if(cinA<0 || cinB<0 ){
        printf("il n'a pas d'un compte parmi les deux\n");
    }