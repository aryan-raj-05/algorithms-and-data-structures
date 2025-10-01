import numpy as np

class LogisticRegressor:
    def __init__(self, X_train, y_train, alpha=0.001, iters=10000):
        self.X_train = X_train
        self.y_train = y_train
        self.mu, self.std = self._calc_norm_params()
        self._apply_norm()
        self.alpha = alpha
        self.iters = iters
        self.w = np.zeros((X_train.shape[1],))
        self.b = 0.0
        self.j_hist = []
        self.p_hist = []

    def predict(self, X_pred):
        X_norm = self.normalize(X_pred)
        y = self.sigmoid(np.dot(X_norm, self.w) + self.b)
        y_pred = (y >= 0.5).astype(int)
        return y_pred

    def cost_func(self):
        m, n = self.X_train.shape
        cost = 0
        z = np.dot(self.X_train, self.w) + self.b
        f_wb = self.sigmoid(z)
        cost = np.sum(
            - self.y_train * np.log(f_wb)
            - (1 - self.y_train) * np.log(1 - f_wb)
        )
        return (cost / m)
    
    def compute_gradient(self):
        m = self.X_train.shape[0]
        z = np.dot(self.X_train, self.w) + self.b
        f_wb = self.sigmoid(z)
        err = f_wb - self.y_train
        dj_dw = np.dot(self.X_train.T, err) / m  # why the transpose ??
        dj_db = np.sum(err) / m
        return dj_dw, dj_db

    def gradient_descent(self):
        for i in range(self.iters):
            dj_dw, dj_db = self.compute_gradient()
            self.w = self.w - self.alpha * dj_dw
            self.b = self.b - self.alpha * dj_db

            if i < 100000:
                self.j_hist.append(self.cost_func())
                self.p_hist.append([self.w, self.b])

            if i % (self.iters // 10) == 0:
                print(f'Iteration {i:4d}    Cost {self.j_hist[-1]}')

    @staticmethod
    def sigmoid(z):
        return 1 / (1 + np.exp(-z))

    def _calc_norm_params(self):
        mu = np.mean(self.X_train, axis=0)
        std = np.std(self.X_train, axis=0)
        std[std == 0] = 1e-8
        return mu, std
    
    def _apply_norm(self):
        self.X_train = (self.X_train - self.mu) / self.std

    def normalize(self, X_pred):
        return (X_pred - self.mu) / self.std