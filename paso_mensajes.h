/**
 * Universidad de Costa Rica
 * Escuela de Ciencias de la Computación e Informática
 * Investigación de Operaciones
 * Profesora: Ileana Alpizar
 * Proyecto de simulación I: PROTOCOLO PARA ENVÍO DE MENSAJES EN UNA RED DE DOS COMPUTADORAS
 * @author Fabián Rodríguez Obando
 * @author Luis Diego Hernandez Herrera
 * I Semestre 2015
 */

#ifndef PASO_MENSAJES_H
#define PASO_MENSAJES_H

#include <QMainWindow>
#include <iostream>
#include <QDebug>
#include <vector>
#include <QThread>
#include <QString>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <math.h>
#include <list>


struct frame{
    bool error;
    int numSecuencia;   //va a ser el mismo que le mensaje
};

struct mensaje{
    bool seEnvio;
    int numSecuencia;
    double venceTimer;
};


namespace Ui {
class Paso_Mensajes;
}

class Paso_Mensajes : public QMainWindow
{
    Q_OBJECT

public:
    explicit Paso_Mensajes(QWidget *parent = 0);
    ~Paso_Mensajes();

private slots:
    void on_btnStart_clicked();

private:
    void correSimulacion();
    void A_recibeMensaje();
    void A_seLibera();
    void A_recibeACK();
    void expiraTTL();
    void B_recibeFrame();
    void B_seLibera();

    int getMsjFaltante();

    void sigEvento();

    Ui::Paso_Mensajes *ui;

    // Miembros de la clase
    int m_numVeces;
    double m_maxTime;
    double m_timer;
    bool m_modoLento;

    int totMensajesRecibidos;

    double m_A_recibeMensaje;
    double m_A_seLibera;
    double m_A_recibeACK;
    double m_expiraTTL;
    double m_B_recibeFrame;
    double m_B_seLibera;

    std::vector<mensaje> colaA;
    std::vector<mensaje> ventana;
    std::vector<frame> colaB;
    std::vector<double> colaTimer;

    bool A_Ocupado;
    bool B_Ocupado;
    int numMensajes;
    int mensajeActual;

    int ACK;

    double infinity;

    //Estadisticas

    double m_reloj;
    QString m_ultimoACKA;
    int m_totFramesB;
    QString m_eventoCorriendo;
    int m_longColaA;
    QString m_datosCPUB;
    int m_recibidosCorrectosB;

};

#endif // PASO_MENSAJES_H
