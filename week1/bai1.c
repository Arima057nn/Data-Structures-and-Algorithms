printf("==================MENU=================\n");
    printf(" \n");
    printf("1.\n");
    printf("2.\n");
    printf("3.\n");
    printf("4.\n");
    printf("5.\n");
    do{
    printf("\nBan chon? ");
    scanf("%d",&luaChon);
    if(luaChon !=2 && luaChon !=3 && luaChon !=4 && luaChon != 5){
        i=1;
    }
    if((luaChon ==2 || luaChon ==3 || luaChon ==4 || luaChon == 5) && i == 0 ){
        do{
            printf("Chon 1 de doc du lieu tu file .dat sang danh sach lien ket: ");
            scanf("%d",&luaChon);
        }while(luaChon ==2 || luaChon ==3 || luaChon ==4 || luaChon == 5 );
        

    }
    switch (luaChon){
    case 1:
       
        break;
    case 2:
        
        break;
    case 3:
       
        break;
    case 4:
        
        break;
    case 5:
    
        
        break;
    case 6: 
        printf("Da thoat chuong trinh");
    default:
        printf("Khong co chuc nang nay");
        break;
    }
    }while(luaChon != 6);






