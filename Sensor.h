#ifndef SENSOR_H
#define SENSOR_H

#include <QtSerialPort>
#include "Parser.h"


class QTimer;

class Sensor
{
public:
    Sensor(std::string serialport = "ttyACM0");

    ///
    /// \brief open
    /// operation for device
    void open();

    ///
    /// \brief close
    ///
    void close();

    void updateStates();

    void calibration();

    bool isCalibrated() const;

    void setIsCalibrated(bool isCalibrated);

    bool isConnected() const;

    void setIsConnected(bool isConnected);

    QSerialPort comPort_;

    TactileStates sensorStates_;

    TactileStates calibratedStates_;

    std::vector<bool> isContacted_;
private:

    bool isCalibrated_;

    bool isConnected_;

    void init();

    std::string portName_;

    QByteArray inputStreamCut_;

    QByteArray inputStreamLeft_;

    QByteArray outputStream_;

    QByteArray inputStream_;

    QTimer* receivedInterval_;


};

#endif // SENSOR_H




