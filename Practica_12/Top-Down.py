memoria = {1:0, 2:1, 3:1}

def fibonacci_top_down(numero):
    if numero in memoria:
        return memoria[numero]
    f = fibonacci_top_down(numero - 1) + fibonacci_top_down(numero - 2)

    memoria[numero] = f
    return memoria[numero]

resultado = fibonacci_top_down(12)
print(f"El resultado es: {resultado}")