

print("1) Variables y tipos")
print("2) Cadenas")
print("3) Operadores")
print("4) Listas")
print("5) Tuplas")
print("6) Tupla con nombre")
print("7) Diccionarios")
print("8) Funciones")
print("9) Variables globales")
print("10) Estructuras de control selectivas")
print("11) Estructuras de control repetitivas")
print("12) Iteración de diccionarios")
print("13) Bibliotecas")
print("14) Graficación")
print("----------------------------------------")

opcion = int(input("¿Qué opción desea revisar? -> "))
match opcion:
    case 1:
        x=10
        print(x)
        cadena="Hola mundo"
        print(cadena)
        
    case 2:
        cadena1="Hola "
        cadena2="Mundo"
        print(cadena1)
        print(cadena2)
        concat_cadenas=cadena1+cadena2
        print(concat_cadenas)
        
    case 3:
        print(1+5)
        print(6*3)
        print(10-4)
        print(100/50)
        print(10%2)
        print(((20*3)+(10+1))/10)
        print(2**2)
    case 4:
        lista_diasDelMes=[31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        print(lista_diasDelMes)
        print(lista_diasDelMes[0])
        print(lista_diasDelMes[6])
        print([lista_diasDelMes[8]])
    case 5:
        tupla_diasDelMes=(31,28,31,30, 31, 30, 31, 30, 31, 30, 31)
        print(tupla_diasDelMes)
        print(tupla_diasDelMes[0])
        print(tupla_diasDelMes[3])
        print(tupla_diasDelMes[1])
    case 6:
        from collections import namedtuple
        Planeta = namedtuple("Planeta", ["nombre", "numero"])
        planeta1 = Planeta("Mercurio", 1)
        planeta2 = Planeta("Venus", 2)
        print(planeta1)
        print(planeta2)
        print(planeta1.nombre, planeta1.numero)
        print(planeta2[0], planeta2[1])
        print("Campos de la tupla: {}".format(Planeta._fields))
    case 7:
        elementos={"hidrogeno": 1, "helio":2, "carbon":6}
        print(elementos)
        print (elementos["hidrogeno"])
    case 8:
        def impirime_nombre(nombre):
            print("Hola "+nombre)
        impirime_nombre(Prof)
    case 9:
        vg="global"
        def funcion_v1():
            print(vg)
        funcion_v1()
        print(vg)
        
    case 10:
        def obtenerMayor (param1,param2):
            if param1 < param2:
                print("{} es mayor que {}".format(param2, param1))
        obtenerMayor(5, 7)
    case 11:
        def cuenta(limite):
            i=limite
            while True:
                print(i)
                i=i-1
                if i==0:
                    break
        cuenta(5)
    case 12:
        elementos={"hidrogeno": 1, "helio": 2, "carbon": 6}
        for llave, valor in elementos.items():
            print(llave, "=", valor)
    case 13:
        import math
        x=math.cos(math.pi)
        print(x)
    case 14:
        import numpy as np
        import matplotlib.pyplot as plt

        x = np.linspace(0, 5, 20)

        fig, ax = plt.subplots()
        ax.plot(x, np.sin(x), marker="o")
        ax.grid(True)
        ax.set_xlabel('X')
        ax.set_ylabel('Y')
        ax.legend(["y = sin(x)"])
        plt.title('Puntos')
        plt.show()
        fig.savefig("grafica.png")