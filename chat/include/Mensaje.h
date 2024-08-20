#ifndef MONITORCHAT_H
#define MONITORCHAT_H

#include <vector>
#include <string>
#include <mutex>

struct EstadoServidor {
    std::string direccionIP;
    int puerto;
    bool conectado;
    int usuariosConectados;
};

class MonitorChat {
public:
    MonitorChat(const std::vector<std::string>& direccionesIP, const std::vector<int>& puertos);
    void recolectarInformacion();
    void mostrarEstado();

private:
    void conectarYRevisarServidor(const std::string& direccionIP, int puerto);
    void actualizarEstadoServidor(const std::string& direccionIP, int puerto, bool conectado, int usuariosConectados);

    std::vector<std::string> direccionesIP;
    std::vector<int> puertos;
    std::vector<EstadoServidor> estadoServidores;
    std::mutex mutexEstado;
};

#endif // MONITORCHAT_H
