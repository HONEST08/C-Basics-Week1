#include <stdio.h>

int main() {
    
    printf("My name is Honest.\n");
    printf("I am 20 years old.\n");
    printf("My favorite hobby is Coding.\n\n");

    
    char name[50];
    int age;

    
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Hello, %s! You are %d years old.\n", name, age);

    return 0;
}
