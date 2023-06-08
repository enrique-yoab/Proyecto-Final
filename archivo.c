#include <stdio.h>

extern int suma_asm(int a, int b); // Declaración de la función en ensamblador
extern int mult_vector(int *arr1,int *arr2, int n); //funcion que me ayudara a calcular el producto punto de dos vectores
extern int comparar_nasm(int x, int y, int z); //funcion que me ayudara a comparar que numero es mayor


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
    printf("Ingrese una opcion\n1) Suma de dos numeros\n2) Producto punto de dos vectores\n3) Calculo de numero mayor\n");
    printf("opcion = ");
    scanf("%d",&valor);
    
    switch (valor)
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
        int arreglo1[5]={4,3,2,1,5};
        int arreglo2[5]={1,5,8,6,9};
        int tamano=5;
        printf("Los arreglos son : \n");
        imprime(arreglo1,tamano);
        imprime(arreglo2,tamano);
        int punto = mult_vector(arreglo1,arreglo2,tamano); //llama la funcion en ensamblador
        printf("\nEl producto punto de los dos vectores es == %d\n",punto);
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
        break;
    default:
        break;
    }

    return 0;
}