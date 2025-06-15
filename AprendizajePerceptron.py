import matplotlib.pyplot as plt
import numpy as np
import colorama
from   colorama import Style,Back

# Valores conocidos de algunas frutas-------------------------------------------
#El primer valor representa el peso del fruto (p1)
#El segundo valor representa el color promedio del fruto (p2)
mango1=np.stack([1.5,-0.3])
mango2=np.stack([0.9,0.05])
mango3=np.stack([2.1,0.2])
manzana1=np.stack([0.24,-0.87])
manzana2=np.stack([0.45,-0.60])
manzana3=np.stack([0.15,-0.43])

#Definimos la función de activación Hardlim------------------------------------
def Hardlim(r):
   a=0
   if r>0:      
    a=1
   return a  
   
#Para graficar las frutas-------------------------------------------------------
def GraficarDatos():
   
   plt.plot(mango1[0],mango1[1],marker="d",color="Gold",label="Mango")
   plt.plot(mango2[0],mango2[1],marker="d",color="Gold")
   plt.plot(mango3[0],mango3[1],marker="d",color="Gold")
   plt.plot(manzana1[0],manzana1[1], marker="o",color="Greenyellow",label="Manzana")
   plt.plot(manzana2[0],manzana2[1], marker="o",color="Greenyellow")
   plt.plot(manzana3[0],manzana3[1], marker="o",color="Greenyellow")

   plt.title("Aprendizaje del perceptrón", 
          fontdict={'family': 'serif', 
                    'color' : 'darkblue',
                    'weight': 'bold',
                    'size': 18})
   plt.xlabel("Peso", size = 16)
   plt.ylabel("Color", size = 16)

   plt.xlim(-1,3)
   plt.ylim(-3,3)
   plt.legend() 
   plt.grid()
   #Para graficar la frontera de decisión----------------------------------------
   x=np.arange(-1, 3, 0.1)
   y=-(W[0]*x+b)/W[1]
   plt.text(-0.8,2.2,"y="+str(-W[0]/W[1])+"x+"+str(-b/W[1]))
   plt.plot(x,y)


#La matriz P contiene los ejemplos de entrenamiento
P=np.array([mango1,mango2,mango3,manzana1,manzana2,manzana3])
P=np.transpose(P)
print("P: ",P)
t=[1,1,1,0,0,0] # Salidas asociadas a los ejemplos de entrenamiento
e=['nan','nan','nan','nan','nan','nan'] #Inicialización del vector de error 
a=['nan','nan','nan','nan','nan','nan'] #Inicialización del vector de salidas
print("Clases reales (t <Clase 1 = mango>, <Clase 0 = manzana> ):", t)
print("Vector inicial de salidas a (clase predicha):", a)
print("Vector inicial de errores e:", e)

np.random.seed(123)
#Asignación de pesos sinápticos aleatorios entre -1 y 1
W=2*np.random.rand(2)-1 
#Asignación de polarizaciones aleatorias
b=2*np.random.rand()-1 
print("W inicial (aleatorio): ",W)
print("b inicial (aleatorio): ",b)

GraficarDatos()
plt.show()

#Las siguientes líneas constituyen nuestro algoritmo de entrenamiento
for epoca in range (1,3): # de 1 a 2
   for q in range (0,6):# de 0 a 5, 
       print(colorama.Fore.MAGENTA+"-------------------------------------------------------"+colorama.Style.RESET_ALL )
       print("Época : ", epoca)
       print("Ejemplo de entrenamiento q: ", q)
       r=np.dot(W,P[:,q])+b
       print("Entrada neta r: ", r)
       a[q]=Hardlim(r)
       print("Clases reales (t):", t)
       print("Clases predichas (a): ", a)
       e[q]=t[q] - a[q]
       print("Vector de errores (e): ", e)
       W=W+e[q]*np.transpose(P[:,q])
       b=b+e[q]
       print("W actual: ",W)
       print("b actual: ",b)
       GraficarDatos()
       plt.show()
       print(e)
print(colorama.Fore.MAGENTA+"-------------------------------------------------------"+colorama.Style.RESET_ALL )   
   #Ahora nuestra red neuronal ya está entrenada
print("Hemos terminado de entrenar al perceptrón")
print("W final: ",W)
print("b final: ",b)


#Ahora tenemos los valores de una fruta desconocida-----------------------------
frutaX=np.vstack([0,2])

# calculamos la entrada neta
r=np.dot(W,frutaX)+b 

# Programamos la función de activación Hardlims---------------------------------
a=Hardlim(r)

#Clasificamos a la fruta desconocida--------------------------------------------
if a==1:
     print ("Es un mango")
     plt.plot(frutaX[0],frutaX[1], marker="d",color="Red")
else: 
     print ("Es una manzana")
     plt.plot(frutaX[0],frutaX[1], marker="o",color="Red")
     
#tecla=input("Presiona enter para continuar...")
#Graficamos nuevamente-----------------------------------------------------------------
GraficarDatos()
plt.show()
