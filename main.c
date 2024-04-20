
#include<stdio.h>
#include<string.h>
#include<conio.h>

struct Items{
    char Item_Name[10];
    float Item_Price;
};
struct Customer{
    char Customer_Name[10];
    char Customer_mobile[10];
    int Customer_Age;
    struct Items Purchase[10];
    int Customer_Item_Qty[10];
};

void SignUp()
{
    char Username[7],Password[7];
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

    printf("Password must be of 6 characters only : ");
    printf("Enter your Password : ");
    scanf("%s",Password);

    while(strlen(Password)!=6)
    {
        printf("Enter password with 6 characters only : ");
        scanf("%s",Password);
    }

    FILE *User_SignUp = NULL;

    User_SignUp = fopen("User_data.txt","a");

    fprintf(User_SignUp,"%s | %s\n",Username,Password);

    fclose(User_SignUp);
    User_SignUp = NULL;

    printf("Sign Up Successfully......!\n");
}

int SignIn()
{
    char Username[7],Password[7],U1[7],P1[7];

    printf("Enter Username : ");
    scanf("%s",Username);

    printf("Enter Password : ");
    scanf("%s",Password);

    FILE *User_SignIn = NULL;

    User_SignIn = fopen("User_data.txt","r");

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
    char Username[4],Password[4],U1[4],P1[4];

    printf("Enter Username : ");
    scanf("%s",Username);

    printf("Enter Password : ");
    scanf("%s",Password);

    FILE *Admin_SignIn = NULL;

    Admin_SignIn = fopen("Admin_data.txt","r");

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
    int Item_Qty;
    printf("You can add only 5 Items At a time.\n");

    struct Items Add[5];
    for(int i=0;i<5;++i)
    {
        printf("Item Number : %d.\n",i+1);
        printf("Enter Item Name : ");
        scanf("%s",Add[i].Item_Name);
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
        fprintf(ptr,"%s\t\t%f\n",Add[i].Item_Name,Add[i].Item_Price);
    }

    fclose(ptr);
    ptr = NULL;

    printf("\nAll items Added Successfully.\n");
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

    for(int j=0;j<i;++j)
    {
        printf("%d.\t%s\t\t\t%f\n", j+1 , Display[j].Item_Name , Display[j].Item_Price );
    }
    fclose(ptr);
    ptr = NULL;
}

void Admin_Panel()
{
    int Admin_Flag = 0;

    printf("1. Add Items\n");
    printf("2. Display Items\n");
}

void User_Interface()
{
    printf("_______________WelCome To Our Store_______________\n");
    printf("____________________XYZ  Store____________________\n");

    struct Customer C1;

    printf("Enter your name : ");
    gets(C1.Customer_Name);
    printf("--------------------------------------------------\n");

    printf("Enter your Mobile Number : ");
    gets(C1.Customer_mobile);
    while(strlen(C1.Customer_mobile)!=10)
    {
        printf("Re-Enter your Mobile Number : ");
        gets(C1.Customer_mobile);
    }
    printf("--------------------------------------------------\n");

    printf("Enter Your Age : ");
    scanf("%d",&C1.Customer_Age);
    printf("--------------------------------------------------\n");
    printf("\n");
    printf("The Product list is Given Here.\n");

    printf("%s\n",C1.Customer_Name);
    printf("%s\n",C1.Customer_mobile);
    printf("%d\n",C1.Customer_Age);

    struct Items Display[40];
    FILE *ptr = NULL;
    ptr = fopen("Item_list.txt","r");
    printf("File opening.\n");
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
    for(int j=0;j<i;++j)
    {   
        printf("%0.2d.\t%10s\t--\t%0.2f\n",j+1,Display[j].Item_Name,Display[j].Item_Price);
    }
    fclose(ptr);
    ptr = NULL;

    int Itemnumber = 0,Itemcount = 0,ItemQty = 0,Total_Item_Purchase = 10,Add_Other_Item;

    printf("\n");
    printf("You can purchase only 10 item at a time.\n");

//     struct Items{
//          char Item_Name[10];
//          float Item_Price;
//     };
//     struct Customer{
//          char Customer_Name[10];
//          char Customer_mobile[10];
//          int Customer_Age;
//          struct Items Purchase[10];
//          int Customer_Item_Qty[10];
//     };

    while(1)
    {
        Itemnumber = 0;
        printf("Executed .\n\n");
        printf("Enter number that item want purchase : ");
        scanf("%d",&Itemnumber);
        if(Itemnumber>i)
        {
            printf("Invalid Item number.\n");
            continue;
        }
        
        printf("Enter Quantity : ");
        scanf("%d",&ItemQty);
        printf("scanf executed.\n");
        strcpy(C1.Purchase[Itemcount].Item_Name,Display[Itemnumber-1].Item_Name);
        printf("strcopied.\n");
        C1.Purchase[Itemcount].Item_Price = Display[Itemnumber-1].Item_Price;
        C1.Customer_Item_Qty[Itemcount] = ItemQty;
        Itemcount++;

        printf("Do you want to add another product (Yes - 1 , No - 0): ");
        scanf("%d",&Add_Other_Item);

        if((Add_Other_Item)==0)
        {
            break;
        }
    }

}

int main()
{
    User_Interface();
    return 0;
}
