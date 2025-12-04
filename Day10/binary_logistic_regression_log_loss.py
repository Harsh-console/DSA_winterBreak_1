import numpy as np

def generate_logistic_training_testing_data(m, n, m_t, noise):
    X = np.c_[np.ones((m, 1)), np.random.rand(m, n)]
    

m = 1000 # number of training data
n = 10 # number of features
m_t = 1000
noise = 0.1

# generate training and testing data
(X, y), (X_t, y_t) = generate_logistic_training_testing_data(m, n, m_t)

# hypothsis
theta = np.random.rand(n+1, 1)

# hyper parameters
learning_rate = 0.01
n_iters = 10000

for i in range(n_iters):
    grad = (1/m) * X.T.dot(X.dot(theta) - y)
    theta -= learning_rate * grad

# testing
y_hat = X_t.dot(theta)
accuracy = np.mean(y_t == y_hat)
print("Accuracy: ", accuracy)
