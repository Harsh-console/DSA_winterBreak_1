import numpy as np

n = 100 # number of data points
X = np.random.rand(n, 1)
c = 3
m = 4
y = c + m*X + np.random.randn(n, 1)

#add bias
X_b = np.c_[np.ones((n, 1)), X]

# linear regression model ( gradient descent )
theta = np.random.rand(2, 1)

# hyper parameters
learning_rate = 0.01
n_iters = 100000

for i in range(n_iters):
    grad = (2 / n) * X_b.T.dot(X_b.dot(theta) - y) # gradient using root mean square cost function
    theta -= learning_rate * grad

print("Final predicted parameter are (theta) :- \n")
print(theta)
print("Expected Paramter is : \n")
print([[3], [4]])
input("Press Enter to exit...")
