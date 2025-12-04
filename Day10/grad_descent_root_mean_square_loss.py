import numpy as np

m = 1000 # number of training data
n = 10 # number of features

# training data
X_design = np.c_[np.ones((m, 1)), np.random.rand(m, n)]
real_theta = np.random.rand(n+1, 1)
noise = 0.1
y = X_design.dot(real_theta) + noise * np.random.randn(m, 1)

# hypotesis function - root mean sqaure cost function
theta = np.random.rand(n+1, 1)

# hyper parameters
learning_rate = 0.01
n_iters = 10000

for i in range(n_iters):
    grad = (1 / m) * X_design.T.dot(X_design.dot(theta) - y)
    theta -= learning_rate * grad

print("Final Parameters : ")
print(theta)
print("Expected Pararmeters : ")
print(real_theta)
input("Press Enter to Exit...")

