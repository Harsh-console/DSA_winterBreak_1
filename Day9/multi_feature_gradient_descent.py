import numpy as np

n = 5 # number of features
real_b = np.random.rand()
real_theta = np.random.rand(n, 1)
real_theta_b = np.r_[real_b*np.ones((1, 1)), real_theta] # shape (n+1, 1)

#linear regression model ( gradient descent )
theta = np.random.rand(n, 1)
m = 1000 # number of data points
X = np.random.rand(m, n) # shape (m, n)
X_b = np.c_[np.ones((m, 1)), X] # shape(m, n+1)
y = X_b.dot(real_theta_b)
b = np.random.rand()
theta_b = np.r_[b*np.ones((1, 1)), theta]

#hyper parameters
learning_rate = 0.01
n_iters = 10000

for i in range(n_iters):
    grad = (2 / m) * (X_b.T.dot(X_b.dot(theta_b) - y))
    theta_b -= learning_rate * grad

print("Final Parameters : \n")
print(theta)
print("Expected Parameters : \n")
print(real_theta)
input("Press Enter to exit...")
