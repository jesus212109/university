#!/bin/bash

# Función para generar una cadena aleatoria de longitud N con caracteres alfanuméricos
generate_random_string() {
    random_string=""

    # Selección del conjunto de caracteres según el tipo especificado
    case $charset in
    "alfa")
        charset='[:alpha:]' # Solo letras mayúsculas o minúsculas
        ;;
    "num")
        charset='[:digit:]' # Solo números
        ;;
    "alfanum")
        charset='[:alnum:]' # Letras mayúsculas, minúsculas y números
        ;;
    *)
        echo "Tipo de cadena no válido. Debe ser 'alfa', 'num' o 'alfanum'."
        exit 1
        ;;
    esac

    # # Generación de la cadena aleatoria. La selección aleatoria de caracteres se realiza mediante el comando tr y /dev/urandom. El comando tr traduce o elimina caracteres desde la entrada estándar y es utilizado aquí para seleccionar aleatoriamente un carácter del conjunto de caracteres especificado
    # for ((i = 0; i < $length; i++)); do
    #     random_char=$(LC_CTYPE=C tr -dc "$charset" </dev/urandom | head -c 1) #La opción -d indica que se deben eliminar los caracteres que no coinciden con los especificados, y -c indica que se deben conservar solo los caracteres que coinciden.
    #     random_string="$random_string$random_char"  #< /dev/urandom: < redirige la entrada estándar del comando tr desde /dev/urandom, que es un generador de números aleatorios del sistema operativo.
    # done

    random_string=$(tr -dc $charset < /dev/urandom | head -c $1) #Elimina de debug random "-d" todo lo que sea distinto "-c" de $charset y capto los N primeros caracteres
  
    echo "$random_string"
}

# Verificación del número de argumentos. Se permite introducir solo un argumento
if [ $# -lt 1 ] || [ $# -gt 2 ]; then
    echo "Uso: $0 <longitud> [alfa|num|alfanum]"
    exit 1
fi

# Longitud de la cadena
length=$1

# Tipo de cadena (opcional)
charset=$2

# Si el tipo de cadena no se especifica, pedir al usuario que lo ingrese.  while que se ejecutará mientras la variable $charset esté vacía
while [ -z "$charset" ]; do
    read -p "Tipo de cadena (alfa, num o alfanum): " charset
    case $charset in
    "alfa" | "num" | "alfanum")
        break
        ;;
    *)
        echo "Tipo de cadena no válido. Inténtalo de nuevo."
        ;;
    esac
done

# Generación de la cadena aleatoria
random_string=$(generate_random_string "$length" "$charset")

echo "Cadena aleatoria de longitud $length con caracteres $charset: $random_string"
