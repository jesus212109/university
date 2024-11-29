import pandas as pd
import matplotlib.pyplot as plt

#TASK 1

# Step 1: Load the dataset
data = pd.read_csv('fashion-mnist_train.csv')

# Step 2: Filter to keep only sandals, sneakers, and ankle boots
filtered_data = data[data['label'].isin([1, 2, 3, 4, 5, 7, 9])]#Modify this to consider the rest of elements <<<<<<<<<<<<<<<<<<<<

# Step 3: Separate labels and features
labels = filtered_data['label'].values
features = filtered_data.drop('label', axis=1).values

# Step 4: Display one example for each class (5 - Sandal, 7 - Sneaker, 9 - Ankle Boot)
sample_classes = {5: "Sandal", 7: "Sneaker", 9: "Ankle Boot"}

verbose = False # Controls the print of the 3 images
if verbose:
    for label, class_name in sample_classes.items():
        # Select one sample for the current label
        sample_image = features[labels == label][0].reshape(28, 28)

        # Plot the image
        plt.imshow(sample_image, cmap='gray')
        plt.title(f"{class_name} Example")
        plt.axis('off')
        plt.show()



from sklearn.model_selection import KFold
from sklearn.metrics import accuracy_score, confusion_matrix
from sklearn.base import clone
import numpy as np
import time

def cross_validation_evaluation(model, features, labels, k=5, sample_size=None):
    verbose = False # Controls the print of the confusion matrix
    kf = KFold(n_splits=k, shuffle=True, random_state=42)
    train_times, predict_times, accuracies = [], [], []

    # Limit the sample size if needed
    if sample_size:
        features, labels = features[:sample_size], labels[:sample_size]

    for train_index, test_index in kf.split(features):
        model = clone(model)  #Reset del modelo

        X_train, X_test = features[train_index], features[test_index]
        y_train, y_test = labels[train_index], labels[test_index]

        # Measure training time
        start_train = time.time()
        model.fit(X_train, y_train) #entrena el modelo
        end_train = time.time()

        # Measure prediction time
        start_predict = time.time()
        predictions = model.predict(X_test) #Hago predicciones
        end_predict = time.time()

        # Calculate metrics
        train_time = end_train - start_train
        predict_time = end_predict - start_predict
        accuracy = accuracy_score(y_test, predictions) # funcion sklearn

        train_times.append(train_time)
        predict_times.append(predict_time)
        accuracies.append(accuracy)

    # Print confusion matrix for further inspection
        if verbose:
            print("Confusion Matrix for this fold:")
            print(confusion_matrix(y_test, predictions))
    if verbose:
        print(f"Training Time per Sample - Min: {min(train_times)}, Max: {max(train_times)}, Avg: {np.mean(train_times)}")
        print(f"Prediction Time per Sample - Min: {min(predict_times)}, Max: {max(predict_times)}, Avg: {np.mean(predict_times)}")
        print(f"Prediction Accuracy - Min: {min(accuracies)}, Max: {max(accuracies)}, Avg: {np.mean(accuracies)}")

    # Return average values for training and prediction times
    return np.mean(train_times), np.mean(predict_times), np.mean(accuracies)

# Example usage (assuming the model and data are loaded)
from sklearn.linear_model import Perceptron
from sklearn.tree import DecisionTreeClassifier

# Define the model (needed  for using task 2 funtion)
#my_model = Perceptron()
#my_model = DecisionTreeClassifier()

#cross_validation_evaluation(model=my_model, features=features, labels=labels, k=5, sample_size=1000)



def evaluate_perceptron(features, labels, sample_sizes=[100, 500, 1000, 5000]):
    perceptron_model = Perceptron()
    training_times, prediction_times, accuracies = [], [], []

    for size in sample_sizes:
        print(f"Evaluating for sample size: {size}")
        avg_train_time, avg_predict_time, avg_accuracy = cross_validation_evaluation(
            model=perceptron_model, features=features, labels=labels, k=5, sample_size=size)

        training_times.append(avg_train_time)
        prediction_times.append(avg_predict_time)
        accuracies.append(avg_accuracy)

    mean_accuracy = np.mean(accuracies)
    print(f"Mean Prediction Accuracy for Perceptron: {mean_accuracy:.4f}")

    # Plot the effect of sample size on runtime
    plt.plot(sample_sizes, training_times, label="Training Time")
    plt.plot(sample_sizes, prediction_times, label="Prediction Time")
    plt.xlabel("Sample Size")
    plt.ylabel("Time (seconds)")
    plt.title("Perceptron Runtime vs Sample Size")
    plt.legend()
    plt.show()


# Example usage
evaluate_perceptron(features, labels)



def evaluate_decision_tree(features, labels, sample_sizes=[100, 500, 1000, 5000]):
    # Initialize the Decision Tree model
    decision_tree_model = DecisionTreeClassifier()
    training_times, prediction_times, accuracies = [], [], []

    for size in sample_sizes:
        print(f"Evaluating for sample size: {size}")
        avg_train_time, avg_predict_time, avg_accuracy = cross_validation_evaluation(
            model=decision_tree_model, features=features, labels=labels, k=5, sample_size=size)

        training_times.append(avg_train_time)
        prediction_times.append(avg_predict_time)
        accuracies.append(avg_accuracy)

    mean_accuracy = np.mean(accuracies)
    print(f"Mean Prediction Accuracy for Perceptron: {mean_accuracy:.4f}")

    # Plotting the effect of sample size on runtime
    plt.plot(sample_sizes, training_times, label="Training Time")
    plt.plot(sample_sizes, prediction_times, label="Prediction Time")
    plt.xlabel("Sample Size")
    plt.ylabel("Time (seconds)")
    plt.title("Decision Tree Runtime vs Sample Size")
    plt.legend()
    plt.show()

# Example usage
evaluate_decision_tree(features, labels)



from sklearn.neighbors import KNeighborsClassifier

def evaluate_knn(features, labels, k_values=[2, 3, 4], sample_sizes=[100, 500, 1000, 5000]):
    best_k = None
    best_accuracy = 0  # Initialize the best accuracy as zero

    for k in k_values:
        print(f"Evaluating k-NN with k={k}")
        knn_model = KNeighborsClassifier(n_neighbors=k)
        accuracies = []
        training_times, prediction_times = [], []

        for size in sample_sizes:
            print(f"Sample size: {size}")
            avg_train_time, avg_predict_time, avg_accuracy = cross_validation_evaluation(
                model=knn_model, features=features, labels=labels, k=5, sample_size=size)

            training_times.append(avg_train_time)
            prediction_times.append(avg_predict_time)
            accuracies.append(avg_accuracy)

        # Calculate mean accuracy across all sample sizes for current k
        mean_accuracy_k = np.mean(accuracies)
        print(f"Mean accuracy for k={k}: {mean_accuracy_k}")

        # Update best k if this k's accuracy is higher
        if mean_accuracy_k > best_accuracy:
            best_accuracy = mean_accuracy_k
            best_k = k

        # Plot accuracy and runtime for each k
        plt.figure()
        plt.plot(sample_sizes, accuracies, label="Accuracy")
        plt.xlabel("Sample Size")
        plt.ylabel("Accuracy")
        plt.title(f"k-NN Accuracy vs Sample Size (k={k})")
        plt.legend()
        plt.show()

        plt.figure()
        plt.plot(sample_sizes, prediction_times, label="Prediction Time")
        plt.xlabel("Sample Size")
        plt.ylabel("Time (seconds)")
        plt.title(f"k-NN Prediction Time vs Sample Size (k={k})")
        plt.legend()
        plt.show()

    print(f"The best value for k is {best_k} with a mean prediction accuracy of {best_accuracy:.4f}")


# Example usage
#evaluate_knn(features, labels)


from sklearn.svm import SVC
from sklearn.preprocessing import MinMaxScaler

# Normalize features
scaler = MinMaxScaler()
features_normalized = scaler.fit_transform(features)


def evaluate_svm(features, labels, gamma_values=[0.0275, 0.03, 0.0325], sample_sizes=[100, 500, 1000, 5000]):
    best_gamma = None
    best_accuracy = 0

    for gamma in gamma_values:
        print(f"Evaluating SVM with gamma={gamma}")
        svm_model = SVC(kernel='rbf', gamma=gamma)
        accuracies, training_times, prediction_times = [], [], []

        for size in sample_sizes:
            print(f"Sample size: {size}")
            avg_train_time, avg_predict_time, avg_accuracy = cross_validation_evaluation(
                model=svm_model, features=features, labels=labels, k=5, sample_size=size)

            training_times.append(avg_train_time)
            prediction_times.append(avg_predict_time)
            accuracies.append(avg_accuracy)

        # Calculate mean accuracy for the current gamma
        mean_accuracy_gamma = np.mean(accuracies)
        print(f"Mean accuracy for gamma={gamma}: {mean_accuracy_gamma}")

        # Update best gamma if this gamma's accuracy is higher
        if mean_accuracy_gamma > best_accuracy:
            best_accuracy = mean_accuracy_gamma
            best_gamma = gamma

        # Plot accuracy and runtime for each gamma
        plt.figure()
        plt.plot(sample_sizes, accuracies, label="Accuracy")
        plt.xlabel("Sample Size")
        plt.ylabel("Accuracy")
        plt.title(f"SVM Accuracy vs Sample Size (gamma={gamma})")
        plt.legend()
        plt.show()

        plt.figure()
        plt.plot(sample_sizes, prediction_times, label="Prediction Time")
        plt.xlabel("Sample Size")
        plt.ylabel("Time (seconds)")
        plt.title(f"SVM Prediction Time vs Sample Size (gamma={gamma})")
        plt.legend()
        plt.show()

    print(f"The best value for gamma is {best_gamma} with a mean prediction accuracy of {best_accuracy:.4f}")

# Example usage with normalized features
#evaluate_svm(features_normalized, labels)



def evaluate_all_classifiers(features, labels, sample_size= None):
    classifiers = {
        "Perceptron": Perceptron(),
        "Decision Tree": DecisionTreeClassifier(),
        "k-NN": KNeighborsClassifier(n_neighbors=4),
        "SVM": SVC(kernel='rbf', gamma=0.03)
    }

    results = {"Classifier": [], "Mean Accuracy": [], "Mean Prediction Time": [], "Mean Training Time": []}

    for name, model in classifiers.items():
        print(f"Evaluating {name}...")

        avg_train_time, avg_predict_time, avg_accuracy = cross_validation_evaluation(
            model=model, features=features, labels=labels, k=5, sample_size=sample_size)

        results["Classifier"].append(name)
        results["Mean Accuracy"].append(avg_accuracy)
        results["Mean Prediction Time"].append(avg_predict_time)
        results["Mean Training Time"].append(avg_train_time)

        print(f"{name} - Mean Accuracy: {avg_accuracy:.4f}, Mean Prediction Time: {avg_predict_time:.4f} seconds, Mean Training Time: {avg_train_time:.4f} seconds")

    fig, ax1 = plt.subplots(figsize=(10, 6))  # Tamaño ajustado para mejorar la visibilidad

    # Gráfico de barras para Mean Accuracy
    ax1.bar(results["Classifier"], results["Mean Accuracy"], color='b', alpha=0.6, label='Mean Accuracy')
    ax1.set_xlabel('Classifier')
    ax1.set_ylabel('Mean Accuracy', color='b')
    ax1.tick_params(axis='y', labelcolor='b')

    # Gráfico de línea para Mean Prediction Time y Mean Training Time
    ax2 = ax1.twinx()
    ax2.plot(results["Classifier"], results["Mean Prediction Time"], color='r', marker='o', label='Mean Prediction Time')
    ax2.plot(results["Classifier"], results["Mean Training Time"], color='g', marker='x', label='Mean Training Time')
    ax2.set_ylabel('Time (seconds)', color='g')
    ax2.tick_params(axis='y', labelcolor='g')

    # Ajuste de márgenes y leyenda
    fig.subplots_adjust(left=0.15, right=0.85)  # Expande márgenes para evitar recortes
    fig.tight_layout(pad=2.0)  # Ajuste adicional para espaciar bien los elementos

    # Añadir leyendas para cada eje
    ax1.legend(loc="upper left")
    ax2.legend(loc="upper right")

    plt.title("Comparison of Classifiers: Accuracy, Prediction Time, and Training Time")
    plt.show()

    return results

# Ejemplo de uso
#evaluate_all_classifiers(features_normalized, labels)