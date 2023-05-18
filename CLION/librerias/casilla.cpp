#include "casilla.h"

casilla::casilla() {
    coordenada();
    setEstado(false);
}

void casilla::setEstado(bool _estado) {
    estado = _estado;
}

bool casilla::getEstado() {
    return estado;
}
