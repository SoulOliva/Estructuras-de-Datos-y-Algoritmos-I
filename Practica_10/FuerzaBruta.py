from string import ascii_letters, digits
from itertools import product
import time


caracteres = ascii_letters + digits

def buscador (con):
    
    archivo = open("combinaciones.txt", "w")
    if len(con) in (4, 8, 10):
        for i in (4, 8, 10):
        for comb in product(caracteres, repeat = i):
                prueba = "".join(comb)
                archivo.write(prueba + "\n")
                if prueba == con:
                    print('Tu contraseña es {}'.format(prueba))
                    archivo.close()
                    return
    else:
        print('Ingresa una contraseña que contenga de 4, 8 o 10 caracteres'
    archivo.close()
    print('La contraseña no cumple con las longitudes requeridas o no se encontró en la búsqueda.')

t0 = time.time()
con = 'H014' 
buscador(con)
print("Tiempos de ejecución {}".format(round(time.time() - t0, 6)))