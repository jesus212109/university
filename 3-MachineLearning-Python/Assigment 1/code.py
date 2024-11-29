import pandas as pd  # Importamos la librería pandas para trabajar con dataframes

# Función para dividir los datos de reseñas
def split_reviews(file_path):
    # Cargamos el archivo Excel con las reseñas
    df = pd.read_excel(file_path)

    # Filtramos el dataframe para crear el conjunto de entrenamiento basado en la columna 'Split'
    # y extraemos solo las reseñas de entrenamiento en forma de lista.
    train_data = df[df['Split'] == 'train']['Review'].tolist()

    # Filtramos las filas donde la columna 'Split' es igual a 'train' (el conjunto de entrenamiento).
    # Luego, seleccionamos la columna 'Review' que contiene las reseñas y convertimos esa columna en una lista con .tolist().
    train_labels = df[df['Split'] == 'train']['Sentiment'].tolist()

    # Hacemos lo mismo para el conjunto de test, extrayendo las reseñas de evaluación.
    test_data = df[df['Split'] == 'test']['Review'].tolist()

    # Extraemos las etiquetas de sentimiento del conjunto de evaluación.
    test_labels = df[df['Split'] == 'test']['Sentiment'].tolist()

    # Contamos cuántas reseñas son positivas y cuántas negativas en el conjunto de entrenamiento.
    train_positive = train_labels.count('positive')
    train_negative = train_labels.count('negative')

    # Contamos cuántas reseñas son positivas y cuántas negativas en el conjunto de evaluación.
    test_positive = test_labels.count('positive')
    test_negative = test_labels.count('negative')

    # Mostramos en la consola el número de reseñas positivas y negativas del conjunto de entrenamiento.
    print(f"Training set: {train_positive} positive reviews, {train_negative} negative reviews")

    # Mostramos en la consola el número de reseñas positivas y negativas del conjunto de test.
    print(f"Test set: {test_positive} positive reviews, {test_negative} negative reviews")

    # Devolvemos cuatro listas: las reseñas de entrenamiento, sus etiquetas, las reseñas de test y sus etiquetas.
    return train_data, train_labels, test_data, test_labels

# Ejemplo de uso, donde llamamos a la función pasándole la ruta del archivo Excel
train_data, train_labels, test_data, test_labels = split_reviews('movie_reviews.xlsx')



# Función para procesar las reseñas y extraer características relevantes
def extract_features(train_data, min_word_length=3, min_occurrences=2):
    # Diccionario para almacenar la frecuencia de cada palabra
    word_counts = {}

    # Procesar cada reseña en el conjunto de entrenamiento
    for review in train_data:
        review_clean = ''.join([char if char.isalnum() or char.isspace() else ' ' for char in review])
        # 1. Eliminar caracteres no alfanuméricos: Recorremos cada carácter y mantenemos solo letras y números
        #Esto recorre cada carácter de la reseña y verifica si es alfanumérico (char.isalnum()) o un espacio en blanco (char.isspace()).
        # Si no lo es, lo reemplazamos por un espacio, Ya que luego hacemos split(), no importa si quedan espacios de más

        # 2. Convertir la reseña a minúsculas
        review_clean = review_clean.lower()

        # 3. Dividir la reseña en palabras
        words = review_clean.split()

        # 4. Contar la frecuencia de cada palabra
        for word in words:
            if len(word) >= min_word_length:  # Consideramos solo las palabras con longitud mínima
                if word in word_counts:
                    word_counts[word] += 1
                else:
                    word_counts[word] = 1

        # 5. Filtrar palabras que cumplen con los requisitos de frecuencia mínima
        # word_counts es un diccionario en el que cada clave es una palabra, y el valor es el número de veces que esa palabra aparece en las reseñas.
        # items() es un método que devuelve una vista de pares clave-valor (en este caso, palabra y frecuencia) del diccionario.
        # Trabajamos desempaquetando los elementos
        filtered_words = []  # Inicializamos la lista de palabras filtradas
        for word, count in word_counts.items():
            if count >= min_occurrences:
                filtered_words.append(word)  # Agregamos la palabra a la lista filtrada

    return filtered_words

# Ejemplo de uso
#filtered_words = extract_features(train_data,10,100)
#print(filtered_words)


def count_feature_frequencies(reviews, words):
    # Inicializamos un diccionario para almacenar la frecuencia de cada palabra en reseñas
    word_frequencies = {word: 0 for word in words}

    # Iterar sobre cada reseña en el conjunto de reseñas
    for review in reviews:
        # Convertimos la reseña a minúsculas y la dividimos en palabras
        review_clean = ''.join([char if char.isalnum() or char.isspace() else ' ' for char in review])
        review_clean = review_clean.lower()
        review_words = review_clean.split()

        # Usamos un conjunto para evitar contar múltiples apariciones de la misma palabra en una reseña
        unique_words = set(review_words)

        # Contamos las palabras únicas que están en el conjunto de palabras a contar
        for word in unique_words:
            if word in word_frequencies:
                word_frequencies[word] += 1

    return word_frequencies

# Ejemplo de uso
# Suponiendo que ya tienes las listas de reseñas positivas y negativas
filtered_words = extract_features(train_data,5,250)
#print(filtered_words)
positive_reviews = [review for review, label in zip(train_data, train_labels) if label == 'positive']
negative_reviews = [review for review, label in zip(train_data, train_labels) if label == 'negative']

word_frequencies_positive = count_feature_frequencies(positive_reviews, filtered_words)
word_frequencies_negative = count_feature_frequencies(negative_reviews, filtered_words)
#print(word_frequencies_positive)
#print(word_frequencies_negative)


# Función para calcular verosimilitudes y probabilidades a priori
def calculate_likelihoods_and_priors(word_frequencies_pos, word_frequencies_neg, train_positive, train_negative,
                                     alpha=1):
    # Inicializamos los diccionarios para las verosimilitudes
    likelihoods = {}

    # Número total de palabras en reseñas positivas y negativas (with Laplace smoothing that explains the (+ alpha * len(word_fre...) )
    total_positive_words = sum(word_frequencies_pos.values()) + alpha * len(word_frequencies_pos)
    total_negative_words = sum(word_frequencies_neg.values()) + alpha * len(word_frequencies_neg)

    # Calculamos la verosimilitud de cada palabra
    for word in word_frequencies_pos:
        # P(word | positive) con Laplace smoothing
        # likelihood_pos is the probability of encountering a specific word given that the review is positive

        # word_frequencies_pos.get(word, 0): This retrieves the frequency (count) of the word from the positive reviews. If the word does not appear in positive reviews, .get() returns 0.
        # + alpha: This is where Laplace smoothing comes in. By adding alpha (usually 1), we ensure that the likelihood never becomes zero, even if the word doesn’t appear in any positive review.
        likelihood_pos = (word_frequencies_pos.get(word, 0) + alpha) / total_positive_words
        # P(word | negative) con Laplace smoothing
        # likelihood_neg is the probability of encountering a specific word given that the review is negative
        likelihood_neg = (word_frequencies_neg.get(word, 0) + alpha) / total_negative_words
        # Guardamos las verosimilitudes en el diccionario
        likelihoods[word] = {'positive': likelihood_pos, 'negative': likelihood_neg}

    # Cálculo de las probabilidades a priori
    # The prior is the overall probability of a review being positive, regardless of the words in the review
    prior_positive = train_positive / (train_positive + train_negative)
    prior_negative = train_negative / (train_positive + train_negative)

    return likelihoods, prior_positive, prior_negative

# Ejemplo de uso

#It's done on the task1 locally (as its not returned then is erased) but now we need to use the variables
train_positive = train_labels.count('positive')
train_negative = train_labels.count('negative')

likelihoods, prior_positive, prior_negative = calculate_likelihoods_and_priors(word_frequencies_positive, word_frequencies_negative, train_positive, train_negative)

print(f"Priors: Positive={prior_positive}, Negative={prior_negative}")
#print(likelihoods)



import math  # Usaremos math.log para los logaritmos

# Función para predecir el sentimiento de una nueva reseña utilizando un clasificador Naive Bayes
def naive_bayes_predict(review, likelihoods, prior_positive, prior_negative):
    # Limpiar y procesar la nueva reseña
    review_clean = ''.join([char if char.isalnum() or char.isspace() else ' ' for char in review])
    review_clean = review_clean.lower()
    words = review_clean.split()

    # Iniciar los valores de logaritmo de las probabilidades a priori
    log_prob_positive = math.log(prior_positive)
    log_prob_negative = math.log(prior_negative)

    # Calcular las probabilidades logarítmicas de que la reseña sea positiva o negativa
    for word in words:
        if word in likelihoods:
            # Sumar los logaritmos de las verosimilitudes para reseñas positivas y negativas
            log_prob_positive += math.log(likelihoods[word]['positive'])
            log_prob_negative += math.log(likelihoods[word]['negative'])

    # Predecir la clase con la mayor probabilidad logarítmica
    if log_prob_positive > log_prob_negative:
        return 'positive'
    else:
        return 'negative'

# Ejemplo de uso
#new_review = "I loved this movie, it was fantastic!"
#prediction = naive_bayes_predict(new_review, likelihoods, prior_positive, prior_negative)
#print(f"The predicted sentiment is: {prediction}")

from sklearn.model_selection import KFold
from sklearn.metrics import confusion_matrix, accuracy_score


# Función para realizar la validación cruzada k-fold
def k_fold_cross_validation(train_data, train_labels, k=5, min_word_lengths=[1, 2, 3, 4, 5]): #Modificar min_word_lengths para pruebas
    best_accuracy = 0
    best_word_length = 1

    # Probar diferentes longitudes mínimas de palabra
    for min_word_length in min_word_lengths:
        accuracies = []

        # Preparar k-fold
        kf = KFold(n_splits=k, shuffle=True, random_state=42)

        for train_index, val_index in kf.split(train_data):
            # Dividimos los datos en conjunto de entrenamiento y validación
            train_fold_data = [train_data[i] for i in train_index]
            val_fold_data = [train_data[i] for i in val_index]
            train_fold_labels = [train_labels[i] for i in train_index]
            val_fold_labels = [train_labels[i] for i in val_index]

            # Extraemos las palabras relevantes del conjunto de entrenamiento
            filtered_words = extract_features(train_fold_data, min_word_length=min_word_length)

            # Calculamos las frecuencias de las palabras en reseñas positivas y negativas
            positive_reviews = [review for review, label in zip(train_fold_data, train_fold_labels) if
                                label == 'positive']
            negative_reviews = [review for review, label in zip(train_fold_data, train_fold_labels) if
                                label == 'negative']
            word_frequencies_pos = count_feature_frequencies(positive_reviews, filtered_words)
            word_frequencies_neg = count_feature_frequencies(negative_reviews, filtered_words)

            # Calculamos las verosimilitudes y las probabilidades a priori
            train_positive = train_fold_labels.count('positive')
            train_negative = train_fold_labels.count('negative')
            likelihoods, prior_positive, prior_negative = calculate_likelihoods_and_priors(
                word_frequencies_pos, word_frequencies_neg, train_positive, train_negative
            )

            # Validamos el modelo en el conjunto de validación
            predictions = [naive_bayes_predict(review, likelihoods, prior_positive, prior_negative)
                           for review in val_fold_data]

            # Calculamos la precisión en el conjunto de validación
            accuracy = accuracy_score(val_fold_labels, predictions)
            accuracies.append(accuracy)

        # Calculamos la precisión media para esta longitud de palabra
        mean_accuracy = sum(accuracies) / len(accuracies)

        # Actualizamos la mejor longitud de palabra si es necesario
        if mean_accuracy > best_accuracy:
            best_accuracy = mean_accuracy
            best_word_length = min_word_length

    return best_word_length, best_accuracy


# Función para evaluar el modelo en el conjunto de test y generar la matriz de confusión
def evaluate_on_test(test_data, test_labels, best_word_length, train_data, train_labels):
    # Extraemos las palabras relevantes del conjunto de entrenamiento usando la mejor longitud
    filtered_words = extract_features(train_data, min_word_length=best_word_length)

    # Calculamos las frecuencias de palabras en reseñas positivas y negativas
    positive_reviews = [review for review, label in zip(train_data, train_labels) if label == 'positive']
    negative_reviews = [review for review, label in zip(train_data, train_labels) if label == 'negative']
    word_frequencies_pos = count_feature_frequencies(positive_reviews, filtered_words)
    word_frequencies_neg = count_feature_frequencies(negative_reviews, filtered_words)

    # Calculamos las verosimilitudes y las probabilidades a priori
    train_positive = train_labels.count('positive')
    train_negative = train_labels.count('negative')
    likelihoods, prior_positive, prior_negative = calculate_likelihoods_and_priors(
        word_frequencies_pos, word_frequencies_neg, train_positive, train_negative
    )

    # Generamos predicciones para el conjunto de test
    predictions = [naive_bayes_predict(review, likelihoods, prior_positive, prior_negative) for review in test_data]

    # Calculamos la matriz de confusión
    conf_matrix = confusion_matrix(test_labels, predictions, labels=['positive', 'negative'])

    # Calculamos la precisión final
    final_accuracy = accuracy_score(test_labels, predictions)

    return conf_matrix, final_accuracy


# Ejemplo de uso para k-fold cross-validation
#best_word_length, best_accuracy = k_fold_cross_validation(train_data, train_labels)

# Evaluamos el mejor modelo en el conjunto de test
#conf_matrix, final_accuracy = evaluate_on_test(test_data, test_labels, best_word_length, train_data, train_labels)
#print(f"Confusion Matrix:\n{conf_matrix}")
#print(f"Final Accuracy: {final_accuracy}")


# Función para probar el clasificador con reseñas más extensas y realistas
def test_personal_reviews(classifier_func, likelihoods, prior_positive, prior_negative):
    # Reseña positiva
    positive_review = ("I recently watched The Grand Budapest Hotel, and it was an absolute masterpiece. "
                       "The visuals were stunning, with every scene looking like a carefully crafted painting. "
                       "The quirky characters were perfectly portrayed by an incredible cast, and the plot was "
                       "both whimsical and deeply touching. What I loved the most was the balance between humor "
                       "and emotion — it never felt forced, and the pacing was just right. The director's attention "
                       "to detail is impeccable, from the elaborate set design to the playful yet meaningful dialogue. "
                       "This is one of those movies that you can watch multiple times and still discover something new "
                       "each time. Truly a work of art.")

    # Reseña negativa
    negative_review = ("Last night, I watched The Room, and it was honestly one of the worst movies I’ve ever seen. "
                       "The acting was wooden, and the dialogue felt like it was written by someone who had never "
                       "heard real people talk. The plot, if you can call it that, was disjointed and full of absurd "
                       "twists that made no sense. There was no character development, and by the end of the movie, "
                       "I couldn’t care less about what happened to any of them. The special effects and production "
                       "quality were so bad they felt like a student project. It was almost impossible to take any scene "
                       "seriously. Overall, a painful experience that I wouldn’t recommend to anyone.")

    # Prueba el clasificador en ambas reseñas
    positive_prediction = classifier_func(positive_review, likelihoods, prior_positive, prior_negative)
    negative_prediction = classifier_func(negative_review, likelihoods, prior_positive, prior_negative)

    # Mostrar los resultados
    print(f"Positive review prediction: {positive_prediction}")
    print(f"Negative review prediction: {negative_prediction}")


# Ejemplo de uso
test_personal_reviews(naive_bayes_predict, likelihoods, prior_positive, prior_negative)
