#!/bin/bash

# Verifica el número correcto de argumentos
if [ "$#" -ne 4 ]; then
    echo "Argumentos incorrectos. Uso: $0 <directorio_origen> <directorio_destino> <compresion> <sobreescribir>"
    exit 1
fi

# Asigna los argumentos a variables
directorio_origen="$1"
directorio_destino="$2"
compresion="$3"
sobreescribir="$4"

# Verifica si el directorio de destino existe y si no, lo crea
if [ ! -d "$directorio_destino" ]; then
    mkdir -p "$directorio_destino"  # Creo la carpeta, (-p)  si existe no la genera y crea su camino 
fi

# Genera el nombre del archivo de copia
nombreDirectorio="$(basename "$directorio_origen")"
usuario="$(whoami)"
fecha=$(date +"%Y%m%d")
extension=".tar"
if [ "$compresion" -eq 1 ]; then
    extension=".tar.gz"
fi
nombre_copia="${nombreDirectorio}_${usuario}_${fecha}_${extension}" #Porque tienen que estar entre llaves?? ( Problema con los _ , pero porque? ) <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

#Verifica si la copia ya existe y si se debe sobreescribir
if [ -e "$directorio_destino/$nombre_copia" ] && [ "$sobreescribir" -eq 0 ]; then
    echo "Ya se ha realizado esta copia hoy ($directorio_destino}/$nombre_copia)."
    echo "No se sobreescribirá la copia."
    exit 1
else
    echo "Existe ya el archivo, pero se sobreescribirá"
fi

echo "$directorio_destino/$nombre_copia"
echo "$directorio_origen"

# Crea la copia de seguridad
if [ "$compresion" -eq 1 ]; then    #depura con echo
    tar -czf "$directorio_destino/$nombre_copia" "$directorio_origen"          # -czf tiene z porque comprime
else
    tar -cf "$directorio_destino/$nombre_copia" "$directorio_origen"
fi

echo "Copia realizada en $directorio_destino/$nombre_copia"
