# Python code to demonstrate Linear Regression from scratch
# This will:
# 1. Implement Normal Equation (closed-form)
# 2. Implement Batch Gradient Descent
# 3. Implement Stochastic Gradient Descent (simple version)
# 4. Compare predictions and RMSE on a small synthetic dataset and plot results
# Note: This code is pure NumPy (no sklearn). It uses matplotlib for a single plot.

import numpy as np
import matplotlib.pyplot as plt

np.random.seed(42)

def add_bias(X):
    """Add column of ones to X for the intercept term."""
    return np.hstack([np.ones((X.shape[0], 1)), X])

def rmse(y_true, y_pred):
    return np.sqrt(np.mean((y_true - y_pred) ** 2))

# Closed-form solution (Normal Equation)
def fit_normal_equation(X, y, l2=0.0):
    """
    X: (n_samples, n_features) without bias column
    y: (n_samples,)
    l2: L2 regularization strength (lambda). If 0 -> no regularization.
    Returns: theta vector (including bias)
    """
    Xb = add_bias(X)
    n_features = Xb.shape[1]
    # Regularization: add lambda * I (but not for bias -> set first diag element to 0)
    A = Xb.T @ Xb
    if l2 > 0:
        reg = l2 * np.eye(n_features)
        reg[0, 0] = 0.0
        A = A + reg
    theta = np.linalg.pinv(A) @ Xb.T @ y
    return theta

# Batch Gradient Descent
def fit_gradient_descent(X, y, lr=0.01, epochs=1000, l2=0.0, verbose=False):
    Xb = add_bias(X)
    n, d = Xb.shape
    theta = np.zeros(d)
    for ep in range(epochs):
        preds = Xb @ theta
        error = preds - y
        grad = (Xb.T @ error) / n
        if l2 > 0:
            reg_grad = l2 * np.r_[0, theta[1:]]  # don't regularize bias
            grad = grad + reg_grad
        theta = theta - lr * grad
        if verbose and (ep % (epochs // 10 or 1) == 0):
            print(f"Epoch {ep}, RMSE: {rmse(y, Xb @ theta):.5f}")
    return theta

# Stochastic Gradient Descent (simple epoch-based)
def fit_sgd(X, y, lr=0.01, epochs=10, l2=0.0, shuffle=True):
    Xb = add_bias(X)
    n, d = Xb.shape
    theta = np.zeros(d)
    for ep in range(epochs):
        indices = np.arange(n)
        if shuffle:
            np.random.shuffle(indices)
        for i in indices:
            xi = Xb[i:i+1]
            yi = y[i]
            pred = xi @ theta
            error = pred - yi
            grad = (xi.T.flatten() * error)  # shape (d,)
            if l2 > 0:
                grad = grad + l2 * np.r_[0, theta[1:]]
            theta = theta - lr * grad
    return theta

# Create synthetic linear data with noise
n = 100
X = 2 * np.random.rand(n, 1)
true_theta = np.array([4.0, 3.5])  # bias=4.0, slope=3.5
y = true_theta[0] + true_theta[1] * X[:, 0] + np.random.randn(n) * 0.8

# Fit models
theta_normal = fit_normal_equation(X, y)
theta_gd = fit_gradient_descent(X, y, lr=0.1, epochs=2000, l2=0.0)
theta_sgd = fit_sgd(X, y, lr=0.01, epochs=50)

# Predictions
Xb = add_bias(X)
pred_normal = Xb @ theta_normal
pred_gd = Xb @ theta_gd
pred_sgd = Xb @ theta_sgd

# Print results
print("True theta (bias, slope):", true_theta)
print("Normal Equation theta:", np.round(theta_normal, 4))
print("Batch GD theta:", np.round(theta_gd, 4))
print("SGD theta:", np.round(theta_sgd, 4))

print("\nRMSEs:")
print("Normal Equation RMSE:", rmse(y, pred_normal))
print("Batch GD RMSE:", rmse(y, pred_gd))
print("SGD RMSE:", rmse(y, pred_sgd))

# Plot data and fitted lines (single plot per tool rules)
plt.figure(figsize=(8,6))
plt.scatter(X[:,0], y, label="Data", alpha=0.7)
# Create line points
xs = np.linspace(X.min(), X.max(), 100).reshape(-1,1)
xb_line = add_bias(xs)
plt.plot(xs[:,0], xb_line @ theta_normal, label="Normal Eq. fit")
plt.plot(xs[:,0], xb_line @ theta_gd, label="Batch GD fit", linestyle='--')
plt.plot(xs[:,0], xb_line @ theta_sgd, label="SGD fit", linestyle=':')
plt.xlabel("x")
plt.ylabel("y")
plt.title("Linear Regression: closed-form vs gradient methods")
plt.legend()
plt.grid(True)
plt.show()

