#include <stdio.h>

int main() {
    float num1, num2;

    printf("Enter First Number");
    scanf("%f", &num1");

    
    printf("Enter Second Number");
    scanf("%f, &num2");
    
    printf("\nSum = %.2f\n", num1 + num2);
    printf("Difference = %.2f\n", num1 - num2);
    printf("Product = %.2f\n", num1 * num2);

    if(num2 != 0)
        printf("Quotient = %.2f\n", num1 / num2);
      else {
        printf("Quotient = Undefined (division by zero)\n");
      }  

      return 0;
    }        

    


    
}