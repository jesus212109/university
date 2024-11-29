import pandas as pd
import numpy as np
from sklearn.model_selection import KFold
import matplotlib.pyplot as plt



def task_1_load_and_analyze_data():
    """
    Task 1: Load the dataset, split it into features and targets, and determine
    the minimum and maximum heating and cooling loads.

    Returns:
        features (DataFrame): DataFrame of input variables (features).
        targets (DataFrame): DataFrame of target variables (Heating and Cooling loads).
        min_max_values (dict): Dictionary with min and max values of heating and cooling loads.
    """
    # Step 1: Load the dataset
    data = pd.read_csv("energy_performance.csv")

    # Step 2: Separate features and targets
    features = data.iloc[:, :-2]  # Extract all columns except the last two
    targets = data.iloc[:, -2:]  # Extract the last two columns (Heating and Cooling loads)

    # Step 3: Determine minimum and maximum values for heating and cooling loads
    heating_min = targets["Heating load"].min()
    heating_max = targets["Heating load"].max()
    cooling_min = targets["Cooling load"].min()
    cooling_max = targets["Cooling load"].max()

    # Prepare min-max results in a dictionary for better readability
    min_max_values = {
        "Heating Load": {"min": heating_min, "max": heating_max},
        "Cooling Load": {"min": cooling_min, "max": cooling_max}
    }

    # Output the results for inspection if True
    if(False):
        print("Minimum and Maximum Heating and Cooling Loads:")
        print(min_max_values)

    return features, targets, min_max_values


# Example usage:
features, targets, min_max_values = task_1_load_and_analyze_data()



def polynomial_model(degree, features, coefficients):
    """
    Polynomial model function to calculate the predicted target values.

    Parameters:
        degree (int): Degree of the polynomial.
        features (numpy.ndarray): Array of input features with shape (n_samples, n_features).
        coefficients (numpy.ndarray): Coefficient vector for the polynomial model.

    Returns:
        numpy.ndarray: Predicted target values with shape (n_samples,).
    """
    # Step 1: Create the design matrix for the polynomial terms
    n_samples, n_features = features.shape
    design_matrix = np.ones((n_samples, 1))  # Start with the bias term (intercept)

    # Generate polynomial terms for all feature combinations
    for d in range(1, degree + 1):
        for combination in np.ndindex(*(d + 1,) * n_features):
            if sum(combination) == d:
                term = np.prod(features ** np.array(combination), axis=1, keepdims=True)
                design_matrix = np.hstack((design_matrix, term))

    # Step 2: Validate coefficient vector size
    expected_size = design_matrix.shape[1]
    assert coefficients.shape[0] == expected_size, (
        f"Coefficient vector size mismatch. Expected {expected_size}, got {coefficients.shape[0]}"
    )

    # Step 3: Calculate the predicted values
    predictions = np.dot(design_matrix, coefficients)
    return predictions

def calculate_coefficient_size(degree, n_features):
    """
    Calculate the required size of the coefficient vector for a polynomial of a given degree.

    Parameters:
        degree (int): Degree of the polynomial.
        n_features (int): Number of input features.

    Returns:
        int: Required size of the coefficient vector.
    """
    from math import comb
    size = comb(degree + n_features, n_features)
    return size

# Example usage
def task_2_polynomial_model(features, degree):
    """
    Wrapper for Task 2 to demonstrate predictions using features from Task 1.

    Parameters:
        features (DataFrame): Feature data extracted in Task 1.
        degree (int): Polynomial degree.

    Returns:
        numpy.ndarray: Predicted values for a random coefficient vector.
    """
    # Convert features from DataFrame to numpy array
    features_array = features.to_numpy()

    # Determine the size of the coefficient vector
    n_features = features_array.shape[1]
    coefficient_size = calculate_coefficient_size(degree, n_features)

    # Generate a random coefficient vector for demonstration
    coefficients = np.random.rand(coefficient_size)

    # Generate predictions using the polynomial model
    predictions = polynomial_model(degree, features_array, coefficients)
    return predictions

# Task 2 example with degree 2 polynomial
degree = 2
predictions = task_2_polynomial_model(features, degree) # Features given by task1
#print("Example Predictions (Task 2):", predictions)



def calculate_jacobian(degree, features, coefficients):
    """
    Calculates the predicted target values and the Jacobian matrix at a given linearization point.

    Parameters:
        degree (int): Degree of the polynomial.
        features (numpy.ndarray): Array of input features with shape (n_samples, n_features).
        coefficients (numpy.ndarray): Coefficient vector at the linearization point.

    Returns:
        tuple:
            numpy.ndarray: Predicted target values with shape (n_samples,).
            numpy.ndarray: Jacobian matrix with shape (n_samples, n_coefficients).
    """
    # Step 1: Create the design matrix for the polynomial terms
    # The design matrix is built by generating all polynomial terms for the features
    # using the same procedure as in Task 2's model function.
    n_samples, n_features = features.shape
    design_matrix = np.ones((n_samples, 1))  # Start with the bias term (intercept)

    for d in range(1, degree + 1):
        for combination in np.ndindex(*(d + 1,) * n_features):
            if sum(combination) == d:
                term = np.prod(features ** np.array(combination), axis=1, keepdims=True)
                design_matrix = np.hstack((design_matrix, term))

    # Step 2: Calculate the predicted target values
    # The predicted values are obtained by multiplying the design matrix with the coefficients.
    # This directly calls the model logic from Task 2, where predictions are based on the polynomial terms.
    predictions = np.dot(design_matrix, coefficients)

    # Step 3: Calculate the Jacobian matrix
    # The Jacobian matrix is equal to the design matrix in polynomial regression. This is because:
    # Partial derivatives of the polynomial terms w.r.t. each coefficient are constant and equal to the corresponding term in the design matrix.
    jacobian = design_matrix

    return predictions, jacobian


def task_3_linearization_and_jacobian(features, degree):
    """
    Wrapper for Task 3 to compute predictions and the Jacobian matrix.

    Parameters:
        features (DataFrame): Feature data extracted in Task 1.
        degree (int): Polynomial degree.

    Returns:
        tuple:
            numpy.ndarray: Predicted values.
            numpy.ndarray: Jacobian matrix.
    """
    # Convert features to numpy array
    features_array = features.to_numpy()

    # Generate a random coefficient vector for demonstration
    n_features = features_array.shape[1]
    coefficient_size = calculate_coefficient_size(degree, n_features)
    coefficients = np.random.rand(coefficient_size)

    # Compute predictions and Jacobian using the linearization point (coefficients)
    predictions, jacobian = calculate_jacobian(degree, features_array, coefficients)
    return predictions, jacobian

# Task 3 example with degree 2 polynomial
degree = 2
predictions, jacobian = task_3_linearization_and_jacobian(features, degree)
if(False):
    print("Predictions (Task 3):", predictions)
    print("Jacobian Shape (Task 3):", jacobian.shape)



def calculate_parameter_update(target_vector, estimated_vector, jacobian, regularization_lambda=1e-5):
    """
    Calculates the optimal parameter update using the normal equation procedure.

    Parameters:
        target_vector (numpy.ndarray): The actual target values (training data targets) with shape (n_samples,).
        estimated_vector (numpy.ndarray): The estimated target values from the model with shape (n_samples,).
        jacobian (numpy.ndarray): The Jacobian matrix with shape (n_samples, n_coefficients).
        regularization_lambda (float): Regularization term to prevent singular matrices (default: 1e-5).

    Returns:
        numpy.ndarray: Optimal parameter update vector with shape (n_coefficients,).
    """
    # Step 1: Calculate residuals
    # The residuals are the difference between the actual target values and the estimated values.
    residuals = target_vector - estimated_vector
    # Explanation: Residuals measure the error of the model at the current linearization point.
    # Smaller residuals indicate closer alignment between predictions and true values.

    # Step 2: Build the normal equation matrix
    # The normal equation is J.T @ J, where J is the Jacobian.
    # A regularization term (lambda * I) is added to ensure numerical stability.
    # This prevents the matrix from being singular, especially in cases of overfitting or insufficient data.
    normal_matrix = jacobian.T @ jacobian + regularization_lambda * np.eye(jacobian.shape[1])

    # Step 3: Build the right-hand side of the normal equation
    # This is J.T @ residuals, representing the projection of residuals onto the parameter space.
    rhs = jacobian.T @ residuals

    # Step 4: Solve the normal equation to find the parameter update
    # Solving normal_matrix @ delta = rhs for delta, where delta is the parameter update.
    parameter_update = np.linalg.solve(normal_matrix, rhs)

    return parameter_update


# Example usage
def task_4_parameter_update(features, targets, degree, regularization_lambda=1e-5):
    """
    Wrapper for Task 4 to demonstrate parameter update calculation.

    Parameters:
        features (DataFrame): Feature data extracted in Task 1.
        targets (DataFrame): Target data extracted in Task 1.
        degree (int): Polynomial degree.
        regularization_lambda (float): Regularization term to prevent singular matrices.

    Returns:
        numpy.ndarray: Optimal parameter update vector.
    """
    # Convert features and targets to numpy arrays
    features_array = features.to_numpy()
    target_vector = targets["Heating load"].to_numpy()  # Example for Heating Load

    # Generate random coefficients and calculate predictions and Jacobian
    n_features = features_array.shape[1]
    coefficient_size = calculate_coefficient_size(degree, n_features)
    coefficients = np.random.rand(coefficient_size)  # Random initialization for demonstration
    estimated_vector, jacobian = calculate_jacobian(degree, features_array, coefficients)

    # Calculate the parameter update
    parameter_update = calculate_parameter_update(
        target_vector, estimated_vector, jacobian, regularization_lambda
    )
    return parameter_update

# Task 4 example with degree 2 polynomial
degree = 2
parameter_update = task_4_parameter_update(features, targets, degree)
#print("Optimal Parameter Update (Task 4):", parameter_update)


def fit_polynomial_model(features, targets, degree, max_iterations=1000, tolerance=1e-6, regularization_lambda=1e-5):
    """
    Fits a polynomial regression model to the training data by iteratively updating coefficients.

    Parameters:
        features (numpy.ndarray): Feature data extracted in Task 1 with shape (n_samples, n_features).
        targets (numpy.ndarray): Target data extracted in Task 1 with shape (n_samples,).
        degree (int): Degree of the polynomial.
        max_iterations (int): Maximum number of iterations for the optimization procedure (default: 1000).
        tolerance (float): Convergence tolerance for stopping the iterative procedure (default: 1e-6).
        regularization_lambda (float): Regularization term to prevent singular matrices (default: 1e-5).

    Returns:
        numpy.ndarray: Coefficient vector that best fits the training data with shape (n_coefficients,).
    """
    # Step 1: Initialize the coefficient vector with zeros
    n_features = features.shape[1]
    n_coefficients = calculate_coefficient_size(degree, n_features)
    coefficients = np.zeros(n_coefficients)  # Initial coefficient vector

    for iteration in range(max_iterations):
        # Step 3: Calculate predictions and Jacobian matrix at the current coefficients
        estimated_vector, jacobian = calculate_jacobian(degree, features, coefficients)

        # Step 4: Calculate residuals
        residuals = targets - estimated_vector

        # Step 5: Calculate the parameter update
        normal_matrix = jacobian.T @ jacobian + regularization_lambda * np.eye(jacobian.shape[1])
        rhs = jacobian.T @ residuals
        parameter_update = np.linalg.solve(normal_matrix, rhs)

        # Step 6: Update coefficients
        coefficients += parameter_update

        # Step 7: Check for convergence
        # If the magnitude of the parameter update is smaller than the tolerance, stop the iterations
        if np.linalg.norm(parameter_update) < tolerance:
            print(f"Converged in {iteration + 1} iterations.")
            break
    else:
        print(f"Reached maximum iterations ({max_iterations}) without full convergence.")

    return coefficients


# Example usage
def task_5_fit_model(features, targets, degree):
    """
    Wrapper for Task 5 to fit a polynomial regression model and return the best coefficients.

    Parameters:
        features (DataFrame): Feature data extracted in Task 1.
        targets (DataFrame): Target data extracted in Task 1.
        degree (int): Polynomial degree.

    Returns:
        numpy.ndarray: Best fitting coefficient vector.
    """
    # Convert features to numpy array
    features_array = features.to_numpy()

    # Fit the polynomial regression model
    coefficients = fit_polynomial_model(features_array, targets["Heating load"], degree)
    return coefficients

# Task 5 example with degree 2 polynomial
degree = 2
best_coefficients = task_5_fit_model(features, targets, degree)
#print("Best Fitting Coefficients (Task 5):", best_coefficients)




def cross_validate_model(features, targets, degree, n_splits=5, regularization_lambda=1e-5):
    """
    Perform cross-validation for a polynomial regression model and calculate mean absolute errors.

    Parameters:
        features (numpy.ndarray): Feature data extracted in Task 1 with shape (n_samples, n_features).
        targets (numpy.ndarray): Target data (e.g., heating or cooling load) with shape (n_samples,).
        degree (int): Polynomial degree to evaluate.
        n_splits (int): Number of cross-validation folds (default: 5).
        regularization_lambda (float): Regularization term to prevent singular matrices (default: 1e-5).

    Returns:
        float: Mean absolute error across all cross-validation folds.
    """
    kf = KFold(n_splits=n_splits, shuffle=True, random_state=42)
    mean_absolute_errors = []

    for train_index, test_index in kf.split(features):
        # Split the data into training and testing sets for the current fold
        X_train, X_test = features[train_index], features[test_index]
        y_train, y_test = targets[train_index], targets[test_index]

        # Fit the model on the training set
        coefficients = fit_polynomial_model(X_train, y_train, degree, regularization_lambda=regularization_lambda)

        # Predict on the test set
        design_matrix_test = create_design_matrix(X_test, degree)
        y_pred = np.dot(design_matrix_test, coefficients)

        # Calculate the mean absolute error for this fold
        mae = np.mean(np.abs(y_test - y_pred))
        mean_absolute_errors.append(mae)

    # Return the mean of the mean absolute errors across all folds
    return np.mean(mean_absolute_errors)


def create_design_matrix(features, degree):
    """
    Create the design matrix for the polynomial regression model.

    Parameters:
        features (numpy.ndarray): Feature data with shape (n_samples, n_features).
        degree (int): Polynomial degree.

    Returns:
        numpy.ndarray: Design matrix with shape (n_samples, n_coefficients).
    """
    n_samples, n_features = features.shape
    design_matrix = np.ones((n_samples, 1))  # Start with bias term (intercept)

    for d in range(1, degree + 1):
        for combination in np.ndindex(*(d + 1,) * n_features):
            if sum(combination) == d:
                term = np.prod(features ** np.array(combination), axis=1, keepdims=True)
                design_matrix = np.hstack((design_matrix, term))
    return design_matrix


def task_6_cross_validation(features, targets):
    """
    Perform cross-validation to select the optimal polynomial degree for heating and cooling loads.

    Parameters:
        features (DataFrame): Feature data extracted in Task 1.
        targets (DataFrame): Target data extracted in Task 1.

    Returns:
        tuple: Optimal degrees for heating and cooling loads, and their respective mean absolute errors.
    """
    features_array = features.to_numpy()
    heating_targets = targets["Heating load"].to_numpy()
    cooling_targets = targets["Cooling load"].to_numpy()

    degrees = range(0, 3)  # Polynomial degrees to evaluate: 0, 1, 2
    results = {"Heating load": {}, "Cooling load": {}}

    # Evaluate each degree for both heating and cooling loads
    for degree in degrees:
        heating_mae = cross_validate_model(features_array, heating_targets, degree)
        cooling_mae = cross_validate_model(features_array, cooling_targets, degree)
        results["Heating load"][degree] = heating_mae
        results["Cooling load"][degree] = cooling_mae

    # Find the optimal degree for each load
    optimal_heating_degree = min(results["Heating load"], key=results["Heating load"].get)
    optimal_cooling_degree = min(results["Cooling load"], key=results["Cooling load"].get)

    print("Cross-Validation Results:")
    print(results)
    print(f"Optimal Degree for Heating load: {optimal_heating_degree}")
    print(f"Optimal Degree for Cooling load: {optimal_cooling_degree}")

    return optimal_heating_degree, results["Heating load"][optimal_heating_degree], \
        optimal_cooling_degree, results["Cooling load"][optimal_cooling_degree]

# Task 6 cross-validation
optimal_degrees = task_6_cross_validation(features, targets)
#print("Optimal Degrees and MAEs (Task 6):", optimal_degrees)



def task_7_final_model_evaluation(features, targets, optimal_heating_degree, optimal_cooling_degree):
    """
    Estimate model parameters for heating and cooling loads using the full dataset.
    Predict heating and cooling loads, plot results, and calculate mean absolute differences.

    Parameters:
        features (DataFrame): Feature data extracted in Task 1.
        targets (DataFrame): Target data extracted in Task 1.
        optimal_heating_degree (int): Optimal polynomial degree for heating load.
        optimal_cooling_degree (int): Optimal polynomial degree for cooling load.

    Returns:
        tuple: Mean absolute differences for heating and cooling loads.
    """
    # Convert features and targets to numpy arrays
    features_array = features.to_numpy()
    heating_targets = targets["Heating load"].to_numpy()
    cooling_targets = targets["Cooling load"].to_numpy()

    # Estimate coefficients for heating load
    heating_coefficients = fit_polynomial_model(features_array, heating_targets, optimal_heating_degree)
    heating_design_matrix = create_design_matrix(features_array, optimal_heating_degree)
    heating_predictions = np.dot(heating_design_matrix, heating_coefficients)

    # Estimate coefficients for cooling load
    cooling_coefficients = fit_polynomial_model(features_array, cooling_targets, optimal_cooling_degree)
    cooling_design_matrix = create_design_matrix(features_array, optimal_cooling_degree)
    cooling_predictions = np.dot(cooling_design_matrix, cooling_coefficients)

    # Calculate mean absolute differences
    heating_mae = np.mean(np.abs(heating_targets - heating_predictions))
    cooling_mae = np.mean(np.abs(cooling_targets - cooling_predictions))

    # Plot results
    plt.figure(figsize=(14, 6))

    # Heating Load
    plt.subplot(1, 2, 1)
    plt.scatter(heating_targets, heating_predictions, alpha=0.7, label="Predicted vs. True")
    plt.plot([heating_targets.min(), heating_targets.max()],
             [heating_targets.min(), heating_targets.max()],
             color='red', linestyle='--', label="Ideal Fit")
    plt.title("Heating load: Predicted vs. True")
    plt.xlabel("True Heating load")
    plt.ylabel("Predicted Heating load")
    plt.legend()

    # Cooling Load
    plt.subplot(1, 2, 2)
    plt.scatter(cooling_targets, cooling_predictions, alpha=0.7, label="Predicted vs. True")
    plt.plot([cooling_targets.min(), cooling_targets.max()],
             [cooling_targets.min(), cooling_targets.max()],
             color='red', linestyle='--', label="Ideal Fit")
    plt.title("Cooling load: Predicted vs. True")
    plt.xlabel("True Cooling load")
    plt.ylabel("Predicted Cooling load")
    plt.legend()

    plt.tight_layout()
    plt.show()

    # Output results
    print(f"Mean Absolute Difference (Heating load): {heating_mae}")
    print(f"Mean Absolute Difference (Cooling load): {cooling_mae}")

    return heating_mae, cooling_mae

# Using optimal degrees from Task 6
optimal_heating_degree = 2
optimal_cooling_degree = 2

# Task 7 evaluation
heating_mae, cooling_mae = task_7_final_model_evaluation(
    features, targets, optimal_heating_degree, optimal_cooling_degree
)
