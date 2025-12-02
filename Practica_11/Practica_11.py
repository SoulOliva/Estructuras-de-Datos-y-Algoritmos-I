
def fibonacci_iterativo_v2(numero):
    f1 = 0
    f2 = 1
    
    if numero == 0:
        return 0
    if numero == 1:
        return 1

    for i in range(1, numero - 1):
        f1, f2 = f2, f1 + f2  # asignación paralela basada insana 💀
    return f2

# Posiciones pedidas
posiciones = [7, 21, 40, 71, 94]

for p in posiciones:
    print(f"F({p}) = {fibonacci_iterativo_v2(p)}")
