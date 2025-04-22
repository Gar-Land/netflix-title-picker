#ifndef RANDOM_H
#define RANDOM_H

#include <chrono>
#include <random>

/* Un header file de una sola funcionalidad, la funcionalidad de generar
un número pseudo-aleatorio por el GNPA (generador de números aleatorios)
Mersenne Twister, de la librería random de la librería estándar de C++.

El GNPA es "plantado" (se inicializa el estado del algortimo con un valor)
al que se le llama "semilla") con un std::seed_seq que acompleta a el
tamaño de la semilla (argumento de seed_seq) para que coinicida lo mejor 
posible con el tamaño del estado del algroitmo (624 bytes para Mersenne 
Twister).

Luego el número aleatorio retornado por nuestro GNPA, es usado como argumento, 
transferido por valor, a la distribución uniforme que convierte a su argumento
en un valor posible dentro de un rango qué queremos, un rango más pequeño, 
entre un valor X y un valor Y (tanto X como Y son parámetros).  */

namespace
{
  inline std::mt19937 numberGenerator()
  {
    std::random_device systemGeneratedNumber {};

    std::seed_seq seed {
      static_cast<std::seed_seq::result_type>(
        std::chrono::steady_clock::now().time_since_epoch().count()
      ), systemGeneratedNumber(), systemGeneratedNumber(), 
      systemGeneratedNumber(), systemGeneratedNumber(), systemGeneratedNumber(), 
      systemGeneratedNumber(), systemGeneratedNumber()
    };

    return std::mt19937(seed);
  }

  inline std::mt19937 mt (numberGenerator());

  inline int backupContent(int lower, int upper)
  {
    return std::uniform_int_distribution{lower, upper}(mt);
  }
}

#endif