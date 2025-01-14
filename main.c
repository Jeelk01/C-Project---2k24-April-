#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<unistd.h>
#define D1 300000
#define D2 400000
#define D3 500000

struct Items{
    char Item_Name[15];
    float Item_Price;
};

struct Customer{
    char Customer_Name[10];
    char Customer_mobile[11];
    struct Items Purchase[10];
    int Customer_Item_Qty[10];
    float Item_Cost_Qty[10];
    float Total_Bill;
    int Total_Qty;
};

void SignUp()
{
    char Username[7],Password[7];
    printf("\n\n");
    printf("-------------------------------------\n");
    printf("               Sign Up               \n");
    printf("-------------------------------------\n");

    printf("Username must be of 6 Characters only.\n");
    printf("Enter your username : ");
    scanf("%s",Username);

    while(strlen(Username)!=6)
    {
        printf("Enter Username with 6 characters only : ");
        scanf("%s",Username);
    }

    printf("Password must be of 6 characters only.\n");
    printf("Enter your Password : ");
    scanf("%s",Password);

    while(strlen(Password)!=6)
    {
        printf("Enter password with 6 characters only : ");
        scanf("%s",Password);
    }

    FILE *User_SignUp = NULL;

    User_SignUp = fopen("User_data.txt","a");
    if(User_SignUp == NULL)
        {
            printf("File doesn't open properly.\n");
            return;
        }

    fprintf(User_SignUp,"%s | %s\n",Username,Password);

    fclose(User_SignUp);
    User_SignUp = NULL;

    printf("Sign Up Successfully......!\n");
}

int SignIn()
{
    
    char Username[7],Password[7],U1[7],P1[7];
    printf("\n");
    printf("-------------------------------------\n");
    printf("               Sign In               \n");
    printf("-------------------------------------\n");
    
    printf("Enter Username : ");
    scanf("%s",Username);

    printf("Enter Password : ");
    scanf("%s",Password);

    FILE *User_SignIn = NULL;

    User_SignIn = fopen("User_data.txt","r");
    if(User_SignIn == NULL)
        {
            printf("File doesn't open properly.\n");
            return;
        }

    while(fscanf(User_SignIn,"%s | %s",U1,P1)==2)
    {
        if( ( strcmp(Username,U1) == 0 ) && ( strcmp(Password,P1) == 0 ) )
        {
            printf("Sign In Successfully......!\n");
            fclose(User_SignIn);
            User_SignIn = NULL;
            return 1;
        }
    }
    printf("Invalid Username or Password.\n");
    
    fclose(User_SignIn);
    User_SignIn = NULL;
    return 0;
}

int Admin_SignIn()
{
    char Username[5],Password[5],U1[5],P1[5];

    printf("\n");
    printf("-------------------------------------\n");
    printf("            Admin Sign In            \n");
    printf("-------------------------------------\n");
    printf("Enter Username : ");
    scanf("%s",Username);

    printf("Enter Password : ");
    scanf("%s",Password);

    FILE *Admin_SignIn = NULL;
    Admin_SignIn = fopen("Admin_data.txt","r");
    if(Admin_SignIn == NULL)
        {
            printf("File doesn't open properly.\n");
            return;
        }


    while(fscanf(Admin_SignIn,"%s | %s",U1,P1)==2)
    {
        if( ( strcmp(Username,U1) == 0 ) && ( strcmp(Password,P1) == 0 ) )
        {
            printf("Sign In Successfully......!\n");
            fclose(Admin_SignIn);
            Admin_SignIn = NULL;
            return 1;
        }
    }
    printf("Invalid Username or Password.\n");
    
    fclose(Admin_SignIn);
    Admin_SignIn = NULL;
    return 0;
}

void Add_Items()
{
    printf("\n\n");
    while(1)
    {
        int Item_Qty;
        struct Items Add[5];

        printf("You can add only 5 Items At a time.\n");
        for(int i=0;i<5;++i)
        {
            printf("Item Number : %d.\n",i+1);
            printf("Enter Item Name : ");
            scanf("%10s",Add[i].Item_Name);
            printf("Enter Item Price : ");
            scanf("%f",&Add[i].Item_Price);
        }

        FILE*ptr = NULL;
        ptr = fopen("Item_list.txt","a");
        if(ptr == NULL)
        {
            printf("File doesn't open properly.\n");
            return;
        }

        for(int i=0;i<5;++i)
        {
            fprintf(ptr,"%15s\t\t%5.2f\n",Add[i].Item_Name,Add[i].Item_Price);
        }

        fclose(ptr);
        ptr = NULL;

        printf("\nAll items Added Successfully.\n\n");
        int choice_to_add = 0;
        printf("Want to add another items (Yes - 1)(No - 0) : ");
        scanf("%d",&choice_to_add);

        if(choice_to_add == 1)
        {
            continue;
        }else if(choice_to_add == 0)
        {
            break;
        }else
        {
            printf("Invalid Input......!\n\n");
        }
    }
}

void Display_Item()
{
    struct Items Display[40];
    FILE *ptr = NULL;
    ptr = fopen("Item_list.txt","r");
    if(ptr == NULL)
    {
        printf("File doesn't open properly.\n");
        return;
    }

    int i = 0;

    while(fscanf(ptr,"%s\t\t%f",&Display[i].Item_Name,&Display[i].Item_Price)==2)
    {
        ++i;
    }

    printf("\n\n");
    printf("-------------------- Item List --------------------\n");
    printf("===================================================\n");
    printf("%3s\t%15s\t\t\t%7s\n","No.","Item Name","Item Price");
    printf("---------------------------------------------------\n");

    for(int j=0;j<i;++j)
    {
        printf("%0.2d.\t\t%10s\t\t%5.2f\n", j+1 , Display[j].Item_Name , Display[j].Item_Price );
    }
    fclose(ptr);
    ptr = NULL;
}

void User_List(){

    char Username[10],Password[10];
    FILE* User_List = NULL;
    User_List = fopen("User_data.txt","r");

    int i = 0;
    printf("\n\n");
    printf("---------- User List ----------\n");
    printf("===============================\n");
    printf("%10s\t \t%10s\n","Username","Password");
    printf("===============================\n");

    while(fscanf(User_List,"%s | %s",Username,Password)==2)
    {
        printf("%10s\t\t|\t%10s\n",Username,Password);
        i++;
    }
}
// I want to creat it with date wise. 
void Accounts() 
{
    char Customer_Name[15];
    float Total_Price;
    int Items, Qty, choice;
    
    FILE* User_Accounts = NULL;
    
    User_Accounts = fopen("User_Accounts.txt", "r");
    printf("---------------------------\n");
    printf("| 1. Today's Accounts     |\n");
    printf("| 2. All Accounts         |\n");
    printf("---------------------------\n");

    printf("Enter That you want : ");
    scanf("%d",&choice);

    switch(choice) 
        {
            case 1:
            break;

            case 2:
            break;

            default:
            printf("Invalid Input......!");
        }

    
}

void Admin_Panel()
{
    while(1)
    {
        int Admin_Flag = 0;
        printf("\n\n");
        printf("---------------------------\n");
        printf("| 1. Add Items            |\n");
        printf("| 2. Display Items        |\n");
        printf("| 3. All User List        |\n");
        printf("---------------------------\n");


        printf("Enter your Need : ");
        scanf("%d",&Admin_Flag);

        switch(Admin_Flag)
        {
            case 1:
                Add_Items();
                break;
            case 2:
                Display_Item();
                break;
            case 3:
                User_List();
                break;
            default:
                printf("Invalid input...!\n");
        }

        int exit = -1;
        printf("Want to exit.....? (Yes - 1)(No - 0) : ");
        scanf("%d",&exit);

        if(exit == 1)
        {
            break;
        }else if(exit == 0)
        {
            continue;
        }else{
            break;
        }
    }
}

void User_Interface()
{
    printf("\n\n");
    printf("______________ WelCome To Our Store ______________\n");
    printf("___________________ XYZ  Store ___________________\n");

    struct Customer C1;

    printf("Enter your name : ");
    scanf("%s",C1.Customer_Name);
    printf("--------------------------------------------------\n");

    printf("Enter your Mobile Number : ");
    scanf("%s",C1.Customer_mobile);
    getchar();

    while(strlen(C1.Customer_mobile)!=10)
    {
        printf("Re-Enter your Mobile Number : ");
        scanf("%s",C1.Customer_mobile);
        getchar();
    }

    printf("--------------------------------------------------\n");
    printf("\v");
    printf("The Product list is Given Here.\n");

    struct Items Display[40];
    FILE *ptr = NULL;
    ptr = fopen("Item_list.txt","r");
    if(ptr == NULL)
    {
        printf("File doesn't open properly.\n");
        return;
    }
    int i = 0;
    while(fscanf(ptr,"%s\t\t%f",&Display[i].Item_Name,&Display[i].Item_Price)==2)
    {   
        ++i;
    }

    printf("--------------------------------------------------\n");
    printf("%3s \t%15s \t  \t%3s\n","No.","Item Name","Rate");
    printf("--------------------------------------------------\n");
    
    for(int j=0;j<i;++j)
    {   
        printf("%0.2d.\t%15s\t--\t\t%0.2f\n",j+1,Display[j].Item_Name,Display[j].Item_Price);
    }
    fclose(ptr);
    ptr = NULL;

    int Itemnumber = 0,Itemcount = 0,ItemQty = 0,Total_Item_Purchase = 10,Add_Other_Item;
    printf("\n");
    printf("You can purchase only 10 item at a time.\n");

    while(1)
    {
        Itemnumber = 0;
        printf("Enter number that item want purchase : ");
        scanf("%d",&Itemnumber);
        if(Itemnumber>i)
        {
            printf("Invalid Item number.\n");
            continue;
        }
        
        printf("Enter Quantity : ");
        scanf("%d",&ItemQty);
        printf("\n");
        strcpy(C1.Purchase[Itemcount].Item_Name,Display[Itemnumber-1].Item_Name);
        C1.Purchase[Itemcount].Item_Price = Display[Itemnumber-1].Item_Price;
        C1.Customer_Item_Qty[Itemcount] = ItemQty;
        Itemcount++;

        printf("Do you want to add another product (Yes - 1 , No - 0): ");
        scanf("%d",&Add_Other_Item);

        if((Add_Other_Item) == 1)
        {
            continue;
        }else if (Add_Other_Item == 0){
            break;
        }else{
            printf("Invalid Input......!\n");
        }
    }

    printf("\n");
    Generate_Bill(C1,Itemcount);

}

void Generate_Bill(struct Customer C1, int Itemcount)
{
    C1.Total_Qty = 0,C1.Total_Bill = 0;
    for(int j = 0;j<Itemcount;++j)
    {
        C1.Total_Qty+=C1.Customer_Item_Qty[j];
        C1.Item_Cost_Qty[j] = C1.Purchase[j].Item_Price * C1.Customer_Item_Qty[j];
        C1.Total_Bill+=C1.Item_Cost_Qty[j];
    }

    FILE * User_Bill_List = NULL;
    User_Bill_List = fopen("User_Accounts.txt","a");
    fprintf(User_Bill_List,"%10s \t\t\t%10s \t\t\t%2.0d \t\t\t%2.0d \t\t%5.2f \t\t\t%s \t\t\t%s\n",C1.Customer_Name,C1.Customer_mobile,Itemcount,C1.Total_Qty,C1.Total_Bill,__DATE__,__TIME__);

    fclose(User_Bill_List);
    User_Bill_List = NULL;
    
    FILE * Bill_User = NULL;
    FILE * Bill_Admin = NULL;
    
    Bill_User = fopen("Bill.txt","w");
    Bill_Admin = fopen("Bill_Admin.txt","a");
    
    if((Bill_User)==NULL || (Bill_Admin)==NULL)
    {
        printf("File doesn't open properly.\n");
        return;
    }

    
    fprintf(Bill_Admin,"\n\n");
    fprintf(Bill_Admin,"-------------------Bill-Reciept-------------------\n");
    fprintf(Bill_User,"-------------------Bill-Reciept-------------------\n");
    
    fprintf(Bill_Admin,"Name : %10s \t  Mobile No. : %10s \n",C1.Customer_Name,C1.Customer_mobile);
    fprintf(Bill_User,"Name : %10s \t  Mobile No. : %10s \n",C1.Customer_Name,C1.Customer_mobile);
    
    fprintf(Bill_Admin,"--------------------------------------------------\n");
    fprintf(Bill_User,"--------------------------------------------------\n");

    fprintf(Bill_Admin,"%s \t\t\t\t\t %s\n",__DATE__,__TIME__);
    fprintf(Bill_User,"%s  \t\t\t\t\t %s\n",__DATE__,__TIME__);
    
    fprintf(Bill_Admin,"--------------------------------------------------\n");
    fprintf(Bill_User,"--------------------------------------------------\n");
    
    fprintf(Bill_Admin,"%3s \t%10s \t\t%5s \t\t%3s \t%6s \n","No.","Item Name","Rate","Qty","Amount");
    fprintf(Bill_User,"%3s \t%10s \t\t%5s \t\t%3s \t%6s \n","No.","Item Name","Rate","Qty","Amount");
    
    fprintf(Bill_Admin,"--------------------------------------------------\n");
    fprintf(Bill_User,"--------------------------------------------------\n");
    
    for(int j=0;j<Itemcount;++j)
    {
        fprintf(Bill_Admin,"%2.0d. \t%10s \t\t%5.2f \t\t%2.0d \t\t%5.2f \n", j+1, C1.Purchase[j].Item_Name, C1.Purchase[j].Item_Price, C1.Customer_Item_Qty[j], C1.Item_Cost_Qty[j]);

        fprintf(Bill_User,"%2.0d. \t%10s \t\t%5.2f \t\t%2.0d \t\t%5.2f \n", j+1, C1.Purchase[j].Item_Name, C1.Purchase[j].Item_Price, C1.Customer_Item_Qty[j], C1.Item_Cost_Qty[j]);
    }
    fprintf(Bill_Admin,"--------------------------------------------------\n");
    fprintf(Bill_User,"--------------------------------------------------\n");
    
    // char ch1[] = "Total Item : ";
    // char ch2[] = "Total Qty : ";
    // fprintf(Bill_Admin,"%s \t%d \t%s \t%s \n","Total Item : ",Itemcount,"Total Qty : ",C1.Total_Qty);
    // fprintf(Bill_User,"%s \t%d \t%s \t%s \n","Total Item : ",Itemcount,"Total Qty : ",C1.Total_Qty);

    // fprintf(Bill_Admin,"%s \t%d \t%s \t%s \n",ch1,Itemcount,ch2,C1.Total_Qty);
    // fprintf(Bill_User,"%s \t%d \t%s \t%s \n",ch1,Itemcount,ch2,C1.Total_Qty);

    
    fprintf(Bill_Admin,"    \t          \t\t        Total : %5.2f\n",C1.Total_Bill);
    fprintf(Bill_User,"    \t          \t\t        Total : %5.2f\n",C1.Total_Bill);
    
    fprintf(Bill_Admin,"--------------------------------------------------\n");
    fprintf(Bill_User,"--------------------------------------------------\n");
    
    fprintf(Bill_Admin,"-----------Visit Again - Have a good day----------\n");
    fprintf(Bill_User,"-----------Visit Again - Have a good day----------\n");
    
    fprintf(Bill_Admin,"--------------------------------------------------\n");
    fprintf(Bill_User,"--------------------------------------------------\n");
    
    fclose(Bill_Admin);
    Bill_Admin = NULL;
    fclose(Bill_User);
    Bill_User = NULL;

    printf("\nYour Bill is Generated Successfully.....!\n");
    printf("--------------- Visit again ---------------\n");
}

void main()
{
    printf("===============================================\n");
    printf("| Welcome ! we are glad you're here.           |\n");
    printf("| Just Let us know. How can we help you..?     |\n");
    printf("| Enjoy Your Visit.                            |\n");
    printf("===============================================\n");

    usleep(2000000); // Delay for 1 second.

    printf("\n\n");
    printf("---------------------------\n");
    printf("| 1. User                 |\n");
    printf("| 2. Admin                |\n");
    printf("---------------------------\n");
    
    int choice = 0,choice1;
    printf("Enter your choice : ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            printf("\n");
            printf("Do you have account already (1 - yes) (0 - No) : ");
            scanf("%d",&choice1);
            usleep(D1);
                switch(choice1)
                {
                    case 1:
                        if(SignIn())
                        {
                            User_Interface();
                        }
                        break;
                    case 0:
                        SignUp();
                        usleep(D3);
                        if(SignIn())
                        {
                            User_Interface();
                        }
                        break;
                    default:
                        printf("Invalid Input.....!\n");
                        return;
                }
            break;
        
        case 2:
            printf("\n");
            if(Admin_SignIn())
            {
                usleep(D3);
                Admin_Panel();
            }
            break;

        default:
        printf("Invalid Input.....!\n");
    }
}
