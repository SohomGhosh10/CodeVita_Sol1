#include<stdio.h>

int isPrime(int n){
    if  (n <= 1){
        return 0;
    }else{
        printf("Checking for it to be prime\n");
    }

    for (int i = 2; i*i <= n; i++)
    {
        if (n % i == 0)
        {
            printf("It is prime");
            return 0;
        } 
    }
    return 1;
}

int computeSmallestPrime(int numbers[] , int size){
    int smallestNo = numbers[0];
    for (int i = 1; i < size; i++)
    {
        if (numbers[i] < smallestNo)
        {
            smallestNo = numbers[i];
        }
        
    }

    int p = smallestNo + 1;
    while(1){
        int b = 0;
        for (int i = 0; i < size; i++)
        {
            if (numbers[i] != smallestNo && p % numbers[i] != smallestNo)
            {
                b = 1;
                break;
            }
            
        }

        if (!b && isPrime(p)){
            return p;
        }
        p++;        
        
    }
    
}

int main(){
    int n;
    printf("Enter the number of natural numbers you want to take as input\n");
    scanf("%d",&n);

    int numbers[n];
    printf("Enter the natural numbers one by one\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&numbers[i]);
    }

    int smallestPrime = computeSmallestPrime(numbers , n);
    printf("The smallest prime number is %d\n",smallestPrime);
    return 0; 
    
}