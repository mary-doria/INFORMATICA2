#ifndef OBJETOFISICO_H
#define OBJETOFISICO_H
#include <string>
using namespace std;

class ObjetoFisico
{protected:
    float x;
    float y;
    string tipoObjeto;
public:
    ObjetoFisico();
    ObjetoFisico(float x_,float y_);
    float getX() const;
    void setX(float value);
    float getY() const;
    void setY(float value);
    string getTipoObjeto() const;
    void setTipoObjeto(const string &value);
};


#endif // OBJETOFISICO_H
