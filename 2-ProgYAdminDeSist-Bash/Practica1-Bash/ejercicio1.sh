#PARA CULAQUIER PRACTICA, RECUERDA QUE PUEDES USAR --help o -h

#!/bin/bash
if [ $# -ne 1 ]; # = solo se puede usar para cadenas y -ne para numeros, como es el caso1
then
    echo "Uso: $0 <directorio>"
    echo "Fin de programa"
    exit
fi

directorio=$1

if [ ! -d "$directorio" ]; # Comprueba la existencia del directorio pasado como argumento
#  niega y necesita espacio, por lo cual se ejecuta lo siguiente cuando no exista el fich
then 
    echo "El directorio $directorio no existe"
    echo "Fin de programa"
    exit
fi

# Obtener la lista de archivos en el directorio
archivos="$(ls $directorio)" #Listo los elementos del directorio (basename)

# Inicializar un array para almacenar el número de asistentes por sesión, 
# cada elememto del array es una sesión, por tanto una línea distinta (De cada uno de los ficheros)
asistentes_por_sesion=() # ESTOY DECLARANDO EL VECTOR AUNQUE NO ME HAGA FALTA

# Iterar sobre cada archivo de texto en el directorio
for archivo in $archivos; do
    # Inicializar contador de línea
    contador=1
    # Leer cada línea del archivo
    while read -r linea; do # -r me va leyendo línea a línea
        # Sumar al array el número de asistentes para cada sesión
        let asistentes_por_sesion[$contador]=${asistentes_por_sesion[$contador]}+linea #Los corchetes son necesarios porque es un vector
        # Asigno a cada elemento del vector la suma de lo que había en la linea $contador + el contenido de cada línea (cada linea es una sesión distinta)
        let contador++
    done < "$directorio/$archivo" #Vuelco el archivo para el read la ruta de los archivos
done

# Imprimir el resultado
i=1
for asistentes in "${asistentes_por_sesion[@]}"; do # @ me devuelve todos los elemntos del vector para luego recorrerlo
    echo "Asistieron $asistentes a la sesión $i"
    let i++
done

#imprimir también pero con otro bucle
# echo "Número de asistentes por sesión:"
# for ((i=1; i<=${#asistentes_por_sesion[@]}; i++)); do
#    echo "Asistieron ${asistentes_por_sesion[$i]} a la sesión"
# done