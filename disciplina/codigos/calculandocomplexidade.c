#include <stdio.h>

int main(){
    
    int n = 10;
    int soma = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0;j < n; j++)
        {
            soma += 1;
        }
        
    }
    printf("%d\n", soma);
    return 0;
}