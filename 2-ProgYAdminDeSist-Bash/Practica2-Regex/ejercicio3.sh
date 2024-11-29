#!/bin/bash

# Verificar si se proporciona un directorio como argumento
if [ $# -ne 2 ]; then # Comprueba si el número de argumentos es diferente de 2
    echo "Uso: $0 <directorio/fichero.txt> <segundos>"
    exit
fi

# Leer el contenido del archivo línea por línea
cat $1 | while read archivo; do
    ip=$archivo

    # Realizar el traceroute a la IP especificada con el límite de tiempo especificado
    ms=$(traceroute -w$2 "$ip" | sed -r -n "s/(.*\.)/\1/p" | sed -n "2p" | sed -r -n "s/^ [0-9]+ //p" | sed -r -n "s/^ [^ ]+ +[^ ]+//p" | sed "s/ms//g" | sed "s/*//g")

    # Contar el número de valores de ms obtenidos
    num=$(echo "$ms" | wc -w) # Recuerda que tenemos una variable 'h' también

    # Sumar los valores de ms para obtener el tiempo total
    ms=$(echo "$ms" | sed -r "s/ +/+/g" | sed "s/^+//g" | sed "s/+$//g" | bc)

    # Comprobar si no se recibió respuesta
    if [[ "$ms" == "" ]]; then
        echo "Error: No se recibió respuesta para $ip en $2 segundos"
    else
        # Calcular el tiempo promedio por salto
        ms=$(echo "scale=5; $ms/$num" | bc)
        echo "IP: $ip ha tardado $ms ms en el primer salto"
    fi

done
