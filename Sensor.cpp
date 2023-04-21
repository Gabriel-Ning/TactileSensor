#include "Sensor.h"
#include <QDebug>
#include <QTimer>

Sensor::Sensor(std::string serialport) :
    comPort_(),
    sensorStates_(),
    calibratedStates_(),
    isContacted_(),
    isCalibrated_(false),
    isConnected_(false),
    portName_(serialport),
    receivedInterval_(new QTimer())

{
    init();

}

void Sensor::init()
{
    comPort_.setPortName(portName_.data());
    comPort_.setBaudRate(QSerialPort::Baud115200);
    comPort_.setDataBits(QSerialPort::Data8);
    comPort_.setParity(QSerialPort::NoParity);
    comPort_.setStopBits(QSerialPort::OneStop);
    comPort_.setFlowControl(QSerialPort::NoFlowControl);

    // 1ms
    QObject::connect(receivedInterval_,&QTimer::timeout, [this] ()
    {

            receivedInterval_->stop();

            if(inputStream_.contains('#'))
            {
                int start = inputStream_.toStdString().find_first_of('#');
                int end = inputStream_.toStdString().substr(start).find_first_of('\n');
                if(end > -1)
                {

                    inputStreamCut_.append(inputStream_.toStdString().substr(start,end).data());
                    sensorStates_.fromMessage(inputStreamCut_.data());
                    inputStreamCut_.clear();
                }
            }

            inputStream_.clear();

    });

}


void Sensor::open()
{
    if(isConnected())
    {
        // do nothing
    }
    else
    {
        if (comPort_.portName() != portName_.data())
        {
            comPort_.close();
            comPort_.setPortName(portName_.data());
        }

        if (!comPort_.open(QIODevice::ReadWrite))
        {

            qDebug()<< (QString("Can't open %1, error code %2")
                        .arg(comPort_.portName()).arg(comPort_.error()));
            return;
        }
        else
        {
            setIsConnected(true);

        }
    }
}

void Sensor::close()
{
    setIsConnected(false);
    comPort_.close();
}


// Update State with fixed time interval
void Sensor::updateStates()
{

    if(receivedInterval_->isActive() == false)
    {
        receivedInterval_->start(10);
    }

    inputStream_.append(comPort_.readAll());
}

void Sensor::calibration()
{
    if(!isCalibrated())
    {
        calibratedStates_.setState(this->sensorStates_);
        setIsCalibrated(true);
    }
}

bool Sensor::isCalibrated() const
{
    return isCalibrated_;
}

void Sensor::setIsCalibrated(bool isCalibrated)
{
    isCalibrated_ = isCalibrated;
}

bool Sensor::isConnected() const
{
    return isConnected_;
}

void Sensor::setIsConnected(bool isConnected)
{
    isConnected_ = isConnected;
}









