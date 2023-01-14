#include<stdio.h>
#include<string.h>
#include<stdbool.h>

struct food
{
    char food_name[100];
    double food_price;
    double tax;
    int food_code;
};

struct food input_food(void);
void display_foods(struct food A[],int size);
bool check_food_code(struct food F[],int size,int code);
void take_order(struct food food_list[],int n,int ordered_food[],int *ptr);
void view_total_order(struct food F[],int size,int A[], int n);
void get_payslip(struct food F[],int size,int A[], int n);


int main(void)
{
    printf("#Simple Project by Hazrat Ali!!!\n\n");

    printf("                             Manager Section\n");
    printf("========================================");
    printf("========================================\n\n");
    int n;
    printf("Enter Total Item Number: ");
    scanf("%d",&n);

    struct food food_list[n];

    for(int i=0; i<n; i++)
    {
        printf("\nFood Number %d:\n",i+1);
        printf("-------------------\n",i+1);
        food_list[i]= input_food();
    }
    printf("\n Food List Updated Successfully.\n");
    printf("Going to Customer section...\n\n");



    printf("\n\n\n\n                            Customer Section\n");
    printf("========================================");
    printf("========================================\n\n");


    int ordered_food[100];
    int food_index=0;

    printf("Hello, Sir. Welcome to our Restaurant!!\n\n");

    display_foods(food_list,n);

    printf("To order food, Enter the food code  ");
    printf("Or  Enter 0 to exit...\n");


    take_order(food_list,n,ordered_food,&food_index);


    get_payslip(food_list, n, ordered_food, food_index);

    printf("Thanks For Visiting...\n");
    printf("Have a Nice Day...\n\n\n");

    return 0;
}

struct food input_food(void)
{
    struct food x;
    printf("Food Name: ");
    scanf("%s",x.food_name);
    printf("Food Price: ");
    scanf("%lf",&x.food_price);
    printf("Food Code: ");
    scanf("%d",&x.food_code);
    x.tax = 0.05*x.food_price;
    return x;
}

void display_foods(struct food A[],int size)
{
    printf("                     Displaying Foods\n");
    printf("----------------------------------------");
    printf("----------------------------------------\n");
    for(int i=0; i<size; i++)
    {
        printf("----------------------------------------");
        printf("----------------------------------------\n");
        printf("Food Name: %s\n",A[i].food_name);
        printf("Food Price: %.2lf\n",A[i].food_price);
        printf("Food Code: %d\n",A[i].food_code);
        printf("----------------------------------------");
        printf("----------------------------------------\n\n");
    }
    printf("\n");
}

bool check_food_code(struct food F[],int size,int code)
{
    for(int i=0; i<size; i++)
    {
        if(code==F[i].food_code)
            return true;
    }
    return false;
}

void take_order(struct food food_list[],int n,int ordered_food[],int *ptr)
{
    int code;
    while(1)
    {
        printf("Enter Food code: ");
        scanf("%d",&code);

        if(code==0)
            return;

        if(check_food_code(food_list,n,code))
        {
            ordered_food[*ptr]=code;
            *ptr+=1;

            printf("Order confirmed..\n");
            view_total_order(food_list, n, ordered_food, *ptr);

            printf("To order more food, Enter the Food Code  ");
            printf("Or  Enter 0 for payslip...\n");
        }
        else
            printf("Invalid Food Code. Please Try Again...\n");
    }
}

void view_total_order(struct food F[],int size,int A[], int n)
{
    printf("Confirmed Orders: \n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<size; j++)
        {
            if(A[i]==F[j].food_code)
                printf("%d) %s\n", i+1, F[j].food_name);
        }
    }
    printf("\n");
}

void get_payslip(struct food F[],int size,int A[], int n)
{
    printf("Loading Payment status... \n\n");
    printf("                  Memo\n");
    printf("No    Name                       Price\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    double total_price=0,total_tax=0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<size; j++)
        {
            if(A[i]==F[j].food_code)
            {
                int space = 25 - strlen(F[j].food_name);
                printf("%d.  %s", i+1, F[j].food_name);
                while(space--)
                    printf(" ");
                printf("%.2lf  %.2lf\n",F[j].food_price,F[j].tax);
                total_price+=(F[j].tax + F[j].food_price);
                total_tax += F[j].tax;
            }
        }
    }

    printf("Total Tax                     %.2lf\n",total_tax);
    printf("-----------------------------------------\n");
    printf("                      Total = %.2lf\n",total_price);
    printf("\n");
}

