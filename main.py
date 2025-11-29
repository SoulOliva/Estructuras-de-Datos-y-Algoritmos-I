'''
PARTE 1:
a) Explicación
Dado el arreglo de n elementos, la idea es partir el arreglo a la mitad, de esa mitad
hacer la mitad, asi sucesivamente hasta llegar a caso base, que seria un solo elemento
y empezar a comparar mitades entre si, hasta llegar al verdadero arreglo

---------------------------------------------------------------------------------

b) Psudocodigo recursivo

MAX (arreglo, inicio, fin)
if (inicio==fin) 
    return arreglo[0]
    
mitad = arreglo/2

max_iz = MAX(arreglo, inicio hasta mitad)
max_de = MAX(arreglo, mitad hasta fin)     
    
if (max_iz > max_de)
   return max_iz
else
   return max_de

END

--------------------------------------------------------------------------------

C) Explicación del caso base
En el caso base, se obtiene al dividir el arreglo, y con una de las mitades, dividirla
de modo que el arreglo se reduzca a un solo elemento, es decir; 

[1, 2, 3, 4] se divide a la mitad

[1, 2] y [3, 4] nuevamente se divide uno de las mitades

[1] y [2] este seria el caso base, ya que no se puede obtener la mitad, 
y de ahi se comparar entre hasta llegar al arreglo original.


PARTE 2: IMPLEMENTACIÓN EN PYTHON
'''
def max_recursivo(lista, inicio, fin):
    if inicio==fin:
       return lista[inicio]
    mitad=(inicio+fin)//2
    
    max_iz= max_recursivo(lista, inicio, mitad)
    max_de= max_recursivo(lista, mitad+1, fin)
    
    if max_iz>max_de:
        return max_iz
    else:
        return max_de
        
n= int(input("Ingresa el tamano del arreglo: "))
lista=[]
print("Ingresa los elementos: ")
for _ in range(n):
    lista.append(int(input()))
resultado=max_recursivo(lista, 0, n-1)
print ("El valor maximo es:", resultado)



