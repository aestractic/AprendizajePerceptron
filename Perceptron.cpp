#include <iostream>

struct Vector2D {
    double x;
    double y;
};

double W[2];
double b;

int Hardlim(double r) {
    if (r > 0) return 1;
    return 0;
}

double dot(double* w, double* p) {
    return w[0] * p[0] + w[1] * p[1];
}

void initializeRandomWeights() {
    unsigned int seed = 123;
    double temp;
    
    temp = (double)((seed * 1103515245 + 12345) % 2147483648) / 1073741824.0 - 1.0;
    W[0] = temp;
    
    seed = (seed * 1103515245 + 12345) % 2147483648;
    temp = (double)((seed * 1103515245 + 12345) % 2147483648) / 1073741824.0 - 1.0;
    W[1] = temp;
    
    seed = (seed * 1103515245 + 12345) % 2147483648;
    temp = (double)((seed * 1103515245 + 12345) % 2147483648) / 1073741824.0 - 1.0;
    b = temp;
}

int main() {
    Vector2D mango1 = {1.5, -0.3};
    Vector2D mango2 = {0.9, 0.05};
    Vector2D mango3 = {2.1, 0.2};
    Vector2D manzana1 = {0.24, -0.87};
    Vector2D manzana2 = {0.45, -0.60};
    Vector2D manzana3 = {0.15, -0.43};
    
    double P[2][6];
    P[0][0] = mango1.x;
    P[0][1] = mango2.x;
    P[0][2] = mango3.x;
    P[0][3] = manzana1.x;
    P[0][4] = manzana2.x;
    P[0][5] = manzana3.x;
    
    P[1][0] = mango1.y;
    P[1][1] = mango2.y;
    P[1][2] = mango3.y;
    P[1][3] = manzana1.y;
    P[1][4] = manzana2.y;
    P[1][5] = manzana3.y;
    
    int t[6] = {1, 1, 1, 0, 0, 0};
    int a[6] = {-1, -1, -1, -1, -1, -1};
    int e[6] = {-1, -1, -1, -1, -1, -1};
    
    std::cout << "P: [";
    for (int i = 0; i < 6; ++i) {
        std::cout << "(" << P[0][i] << ", " << P[1][i] << ")";
        if (i < 5) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
    
    std::cout << "Clases reales (t <Clase 1 = mango>, <Clase 0 = manzana> ): ";
    for (int i = 0; i < 6; ++i) {
        std::cout << t[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Vector inicial de salidas a (clase predicha): ";
    for (int i = 0; i < 6; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Vector inicial de errores e: ";
    for (int i = 0; i < 6; ++i) {
        std::cout << e[i] << " ";
    }
    std::cout << std::endl;
    
    initializeRandomWeights();
    
    std::cout << "W inicial (aleatorio): " << W[0] << ", " << W[1] << std::endl;
    std::cout << "b inicial (aleatorio): " << b << std::endl;
    
    for (int epoch = 1; epoch <= 2; ++epoch) {
        for (int q = 0; q < 6; ++q) {
            std::cout << "-------------------------------------------------------" << std::endl;
            std::cout << "Época : " << epoch << std::endl;
            std::cout << "Ejemplo de entrenamiento q: " << q << std::endl;
            
            double p_q[2] = {P[0][q], P[1][q]};
            double r = dot(W, p_q) + b;
            std::cout << "Entrada neta r: " << r << std::endl;
            
            a[q] = Hardlim(r);
            
            std::cout << "Clases reales (t): ";
            for (int i = 0; i < 6; ++i) {
                std::cout << t[i] << " ";
            }
            std::cout << std::endl;

            std::cout << "Clases predichas (a): ";
            for (int i = 0; i < 6; ++i) {
                std::cout << a[i] << " ";
            }
            std::cout << std::endl;
            
            e[q] = t[q] - a[q];
            
            std::cout << "Vector de errores (e): ";
            for (int i = 0; i < 6; ++i) {
                std::cout << e[i] << " ";
            }
            std::cout << std::endl;
            
            W[0] = W[0] + e[q] * p_q[0];
            W[1] = W[1] + e[q] * p_q[1];
            b = b + e[q];
            
            std::cout << "W actual: " << W[0] << ", " << W[1] << std::endl;
            std::cout << "b actual: " << b << std::endl;
            
            std::cout << "Vector de errores (e): ";
            for (int i = 0; i < 6; ++i) {
                std::cout << e[i] << " ";
            }
            std::cout << std::endl;
        }
    }
    
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "Hemos terminado de entrenar al perceptrón" << std::endl;
    std::cout << "W final: " << W[0] << ", " << W[1] << std::endl;
    std::cout << "b final: " << b << std::endl;
    
    double frutaX[2] = {0, 2};
    double r = dot(W, frutaX) + b;
    int a_result = Hardlim(r);
    
    if (a_result == 1) {
        std::cout << "Es un mango" << std::endl;
    } else {
        std::cout << "Es una manzana" << std::endl;
    }
    
    return 0;
}
