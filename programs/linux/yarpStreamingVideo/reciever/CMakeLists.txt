# yarpStreamingVideo: Reciever
cmake_minimum_required(VERSION 2.8)  # Versión mínima que exigimos de CMake, que va ampliando sus capacidades
add_executable(yarpStreamingVideoReciever main.cpp)  # Compilar main.cpp y other.cpp, enlazarlos, y llamar ejecutable al binario generado
find_package(YARP REQUIRED)  # Nombre de la librería, buscará un módulo de CMake (que define las variables utilizadas a continuación) con este nombre. REQUIRED indica que lo exigimos.
find_package(OpenCV REQUIRED)  # Nombre de la librería, buscará un módulo de CMake (que define las variables utilizadas a continuación) con este nombre. REQUIRED indica que lo exigimos.
target_link_libraries(yarpStreamingVideoReciever ${OpenCV_LIBS})
target_link_libraries(yarpStreamingVideoReciever ${YARP_LIBRARIES})

