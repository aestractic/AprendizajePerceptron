# Implementación del Perceptron

Este proyecto presenta una implementación completa del algoritmo del Perceptron, uno de los modelos fundamentales en el aprendizaje automático, desarrollado en múltiples lenguajes de programación para fines educativos y de investigación.

## Descripción

El Perceptron es un algoritmo de aprendizaje supervisado que implementa un clasificador binario lineal. Este proyecto ofrece:

- **Implementación en Python**: Una versión moderna y eficiente utilizando NumPy para operaciones vectoriales
- **Implementación en C++**: Una versión optimizada para rendimiento y uso en sistemas embebidos
- **Documentación Teórica**: Un documento detallado que explica los fundamentos matemáticos y el funcionamiento del algoritmo ([Ver Documentación](Aprendizaje%20del%20perceptrón.pdf))

### Características Principales

- Implementación del algoritmo de aprendizaje del Perceptron
- Visualización de la línea de decisión
- Soporte para datos de múltiples dimensiones
- Métricas de evaluación del modelo
- Documentación detallada del proceso de aprendizaje

## Requisitos

### Python
- Python 3.x
- NumPy
- Matplotlib (para visualizaciones)

### C++
- Compilador C++ (g++ o similar)
- Make (opcional)

## Instalación

### Python
```bash
# Instalar dependencias
pip install numpy matplotlib
```

### C++
```bash
# Compilar el proyecto
g++ Perceptron.cpp -o Perceptron
```

## Uso

### Python
```bash
python AprendizajePerceptron.py
```

### C++
```bash
./Perceptron
```

## Estructura del Proyecto

```
.
├── AprendizajePerceptron.py    # Implementación en Python con visualizaciones
├── Perceptron.cpp             # Implementación en C++ optimizada
├── [Aprendizaje del perceptrón.pdf](Aprendizaje%20del%20perceptrón.pdf)  # Documentación teórica detallada
├── LICENSE                    # Licencia MIT
└── README.md                  # Este archivo
```

## Características Técnicas

### Implementación Python
- Uso de NumPy para operaciones vectoriales eficientes
- Visualización de la línea de decisión
- Métricas de rendimiento
- Soporte para datos de múltiples dimensiones

### Implementación C++
- Optimización para rendimiento
- Estructuras de datos eficientes
- Manejo de memoria optimizado
- Interfaz de línea de comandos

## Contribución

Las contribuciones son bienvenidas. Por favor, sigue estos pasos:

1. Haz fork del proyecto
2. Crea una rama para tu feature (`git checkout -b feature/AmazingFeature`)
3. Haz commit de tus cambios (`git commit -m 'Add some AmazingFeature'`)
4. Push a la rama (`git push origin feature/AmazingFeature`)
5. Abre un Pull Request

## Licencia

Este proyecto está bajo la Licencia MIT - ver el archivo [LICENSE](LICENSE) para más detalles.

## Autor

Jairo Santiago Aburto

## Agradecimientos

- A la comunidad de código abierto por su inspiración y recursos
- A los desarrolladores de NumPy y las herramientas de C++ por su excelente documentación 