import numpy as np

m = 1000 # number of training data
n = 10 # number of features

# training data
X_design = np.c_[np.ones((m, 1)), np.random.rand(m, n)]
real_theta = np.random.rand(n+1, 1)
noise = 0.1
y = X_design.dot(real_theta) + noise * np.random.randn(m, 1)

#feature - scaling : standardization 
mu = X_design[:, 1:].mean(axis = 0)
sigma = X_design[:, 1:].std(axis = 0)
sigma[sigma == 0] = 1
X_design_scaled = X_design.copy()
X_design_scaled[:, 1:] = (X_design[:, 1:] - mu) / sigma 
# hypotesis function - root mean sqaure cost function
theta = np.random.rand(n+1, 1)
theta_scaling = np.random.rand(n+1, 1)
# hyper parameters
learning_rate = 0.01
n_iters = 10000

for i in range(n_iters):
    grad = (1 / m) * X_design.T.dot(X_design.dot(theta) - y)
    theta -= learning_rate * grad

    grad_scaling = (1/m) * X_design_scaled.T.dot(X_design_scaled.dot(theta_scaling) - y)
    theta_scaling -= learning_rate * grad_scaling

# unscaling theta_scaling
theta_unscaled = theta_scaling.copy()
theta_unscaled[1:] = theta_scaling[1:] / sigma.reshape(-1 ,1)
theta_unscaled[0] = theta_scaling[0] - np.sum(mu / sigma * theta_scaling[1:].flatten())

print("Final Parameters (without scaling) : ")
print(theta)
print("Final parameters (with scaling) : ")
print(theta_unscaled)
print("Expected Pararmeters: ")
print(real_theta)
input("Press Enter to Exit...")

