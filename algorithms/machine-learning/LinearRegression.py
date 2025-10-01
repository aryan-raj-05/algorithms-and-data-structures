import numpy as np

class LinearRegression:
    def __init__(self, X_train, y_train, alpha=9e-4, num_iters=10000):
        self.X_train = X_train
        self.y_train = y_train
        self.mu, self.sigma = self._calc_norm_params()
        self._apply_norm()
        self.w = np.zeros((X_train.shape[1]))
        self.b = 0.0
        self.alpha = alpha
        self.num_iters = num_iters
        self.j_hist = []
        self.p_hist = []

    def fit(self):
        for i in range(self.num_iters):
            dj_dw, dj_db = self.compute_gradient()
            self.w = self.w - self.alpha * dj_dw
            self.b = self.b - self.alpha * dj_db

            if i < 100000:
                self.j_hist.append(self.compute_cost())
                self.p_hist.append([self.w, self.b])

            if i % (self.num_iters // 10) == 0:
                print(f"Iteration: {i:4}, Cost: {self.j_hist[-1]: 0.2e}")

    def predict(self, X_pred):
        X_pred = self.norm(X_pred)
        f_wb = np.dot(X_pred, self.w) + self.b
        return f_wb

    def compute_cost(self):
        m, n = self.X_train.shape
        f_wb = np.dot(self.X_train, self.w) + self.b
        cost = np.sum((f_wb - self.y_train)**2) / (2*m)
        return cost
    
    def compute_gradient(self):
        m, n = self.X_train.shape
        f_wb = np.dot(self.X_train, self.w) + self.b
        error = f_wb - self.y_train
        dj_dw = np.dot(error, self.X_train) / m
        dj_db = np.sum(error) / m
        return dj_dw, dj_db
    
    def _calc_norm_params(self):
        mu = np.mean(self.X_train, axis=0)
        sigma = np.std(self.X_train, axis=0)
        return mu, sigma
    
    def _apply_norm(self):
        self.X_train = (self.X_train - self.mu) / self.sigma

    def norm(self, X_pred):
        return (X_pred - self.mu) / self.sigma