import numpy as np

# get training data
m = 1000 # number of training data
n = 10 # number of features
X = np.random.rand(m,n)
X_design = np.c_[np.ones((m, 1)), X] # 1's for bias

real_theta = np.random.rand(n+1, 1)
noise_factor = 0.02
y = X_design.dot(real_theta) + noise_factor*np.random.randn(m, 1)

# hypothesis function
theta = np.random.rand(n+1, 1)

# hyper parameters
learning_rate = 0.001
n_iters = 100000

for i in range(n_iters):
    grad = (1/m) * X_design.T.dot(np.tanh(X_design.dot(theta) - y))
    theta -= learning_rate * grad

print("Expected parameters : ")
print(real_theta)
print("Final paramters : ")
print(theta)
input("Press Enter to exit...")
