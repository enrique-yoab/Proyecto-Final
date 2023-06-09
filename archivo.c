#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//funciones de ensamblador
extern int suma_asm(int a, int b); // Declaración de la función en ensamblador
extern int mult_vector(int *arr1,int *arr2, int n); //funcion que me ayudara a calcular el producto punto de dos vectores
extern int comparar_nasm(int x, int y, int z); //funcion que me ayudara a comparar que numero es mayor
extern int bubble_sort(int *arr,int n);
extern int fibonacci(int x);
extern int factorial(int x);


void imprime(int *arr, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    int valor;
    printf("Ingrese una opcion\n1) Suma de dos numeros\n2) Producto punto de dos vectores\n3) Calculo de numero mayor\n4) Funcion Bubblesort\n");
    printf("5) Serie de Fibonacci\n6) Calculo de Factorial\n");
    printf("\nOpcion elegida == ");
    scanf("%d",&valor);
    
    switch(valor)
    {
    case 1:
            //esta funcion solo tiene dos parametros, los cuales son enteros
            int num1, num2, resultado;
            printf("\nIngrese el primer número: ");
            scanf("%d", &num1);
            printf("\nIngrese el segundo número: ");
            scanf("%d", &num2);
            resultado = suma_asm(num1, num2); // Llamada a la función en ensamblador    
            printf("\nLa suma es: %d\n", resultado);
            break;
    case 2:
            //el arreglo y el tamaño pueden ser modificados desde aqui,
            //donde los parametros son el arreglo y el tamaño del arreglo
            int tamano;
            srand(time(0));
            printf("\nIngrese el tamaño del arreglo =  ");
            scanf("%d",&tamano); 
            int *vec1=malloc(tamano*sizeof(int));
            int *vec2=malloc(tamano*sizeof(int));
            for(int i=0;i < tamano;i++){
                vec1[i]=rand()%30;
                vec2[i]=rand()%30;
            }
            printf("Los arreglos son : \n");
            imprime(vec1,tamano);
            imprime(vec2,tamano);
            int punto = mult_vector(vec1,vec2,tamano); //llama la funcion en ensamblador
            printf("\nEl producto punto de los dos vectores es == %d\n",punto);
            free(vec1);
            free(vec2);
            break;
    case 3:
            //esta funcion nos perimite determinar que numero es mayor
            int x1, x2, x3, res;
            printf("\nIngrese el primer número: ");
            scanf("%d", &x1);
            printf("\nIngrese el segundo número: ");
            scanf("%d", &x2);
            printf("\nIngrese el tercer numero: ");
            scanf("%d", &x3);
            res=comparar_nasm(x1,x2,x3);
            printf("El numero mayor es == %d \n",res);
            break;
    case 4:
            //esta funcion hara el bubblesort de un arreglo n
            int len;
            srand(time(0));
            printf("\nIngrese el tamaño del arreglo =  ");
            scanf("%d",&len); 
            int *bubbl=malloc(len*sizeof(int));
            for(int i=0;i < len;i++){
                bubbl[i]=rand()%30;
            }
            printf("\nEl arreglo se lleno de forma aleatoria\nTiene los siguentes elementos:\n");
            imprime(bubbl,len);
            bubble_sort(bubbl,len);
            printf("\nEl arreglo ordenado es:\n");
            imprime(bubbl,len);
            free(bubbl);
            break;
    case 5:
            //esta funcion hara las serie fibbonaci de un numero
            int x, aux;
            printf("\nEste programa calcula la serie de fibonacci ");
            printf("\nIngrese el numero fibonacci que desea calcular == ");
            scanf("%d",&x);
            aux=fibonacci(x);
            printf("\nEl resultado es == %d \n",aux);
            break;
    case 6:
            int F, fac;
            printf("Esta funcion permite calcular el factorial de un numero\n");
            printf("Ingrese un numero == ");
            scanf("%d",&F);
            fac=factorial(F);
            printf("\nEl factorial de %d es == %d\n",F,fac);
            break;
    case 7:
            break;
    case 8:
            break;
    case 9:
            break;
    case 10:
            break;
    default:
            break;
    }

    return 0;
}
