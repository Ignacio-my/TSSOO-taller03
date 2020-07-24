# TSSOO-taller03
autor: Ignacio Miranda

Correo Institucional: ignacio.miranda@alumnos.uv.cl

El diseño de la solucion consiste en 2 funciones, 

Funciones

LLenado(): Esta funcion es la que llena el arreglo de forma paralela con los datos entregados por los parametros, y ocupa los parametros TamanioArreglo, LimiteInf, LimiteSup

SumaParalela(): Esta funcion lo que hace es dividir dependiendo de el numero de hilos el arreglo y esas porciones de arreglo se van sumando por cada hilo independientemente, despues de eso las sumas en conjunto se suman en una soma total

Conjunto de variables por parametro

TamanioArreglo: tamaño de elementos que tendra el arreglo principal

NumThreads: numero de hilos

LimiteInf: limite inferior del conjunto de elementos randomicos

LimiteSup: limite superior del conjunto de elementos randomicos

Arreglos:

Arreglo[]: Arreglo principal y donde se llena gracias a la funcion llenado y luego se ocupa en la suma

ArregloParalelo[]: Arreglo paralelo donde se llena con respecto a las sumas anteriores

Variables: 

Suma: Donde se indica la suma final, esta es la suma del porcion de sumas que realizaron los hilos independientemente

TiempoLLenadoParalela: tiempo el que se tarda en llenar el arreglo principal

TiempoSumaParalela: tiempo en lo que se tarda en sumar el conjunto de porciones y entregar la suma total

tiempototal: el tiempo de la suma de TiempoSumaParalela y TiempoLlenadoParalela

TiempoLlenadOpenmp = tiempo en que se tarda en llenar el arreglo principal con la API OpenMP

TiempoSumaOpenmp = tiempo en que se tarda en sumar conjunto de porciones y entregar la suma total con la API OpenMP

tiempototalopenmp = el tiempo de la suma de TiempoLlenadOpenmp y TiempoSumaOpenmp

  
