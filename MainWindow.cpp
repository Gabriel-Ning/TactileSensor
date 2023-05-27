#include "MainWindow.h"
#include "./ui_MainWindow.h"

bool compare(int c, int m)
{
    return abs(c-m) > 500;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , tacSensor_()
{
    ui->setupUi(this);


    connect(ui->Button_open,&QPushButton::clicked, [this] (){
        this->tacSensor_.open();
        this->ui->textBrowser->insertPlainText(QString("Tac Sensor is Connected!\n"));
    });

    connect(ui->Button_close,&QPushButton::clicked, [this] (){
        this->tacSensor_.close();
        this->ui->textBrowser->insertPlainText(QString("Tac Sensor is Disconnected!\n"));
    });

    connect(ui->Button_calibrate, &QPushButton::clicked, [this] ()
    {
        this->tacSensor_.calibration();
        if(this->tacSensor_.isCalibrated())
        {
            this->ui->textBrowser->insertPlainText(QString("Tac Sensor is Calibrated!\n"));

            // SHIT !!!
            this->ui->lineEdit_c11->setText(QString("%1").arg(this->tacSensor_.calibratedStates_.impedence_[0]));
            this->ui->lineEdit_c11->setEnabled(false);
            this->ui->lineEdit_c12->setText(QString("%1").arg(this->tacSensor_.calibratedStates_.impedence_[1]));
            this->ui->lineEdit_c12->setEnabled(false);

            this->ui->lineEdit_c21->setText(QString("%1").arg(this->tacSensor_.calibratedStates_.impedence_[2]));
            this->ui->lineEdit_c21->setEnabled(false);
            this->ui->lineEdit_c22->setText(QString("%1").arg(this->tacSensor_.calibratedStates_.impedence_[3]));
            this->ui->lineEdit_c22->setEnabled(false);

            this->ui->lineEdit_c31->setText(QString("%1").arg(this->tacSensor_.calibratedStates_.impedence_[4]));
            this->ui->lineEdit_c31->setEnabled(false);
            this->ui->lineEdit_c32->setText(QString("%1").arg(this->tacSensor_.calibratedStates_.impedence_[5]));
            this->ui->lineEdit_c32->setEnabled(false);

            this->ui->lineEdit_c41->setText(QString("%1").arg(this->tacSensor_.calibratedStates_.impedence_[6]));
            this->ui->lineEdit_c41->setEnabled(false);
            this->ui->lineEdit_c42->setText(QString("%1").arg(this->tacSensor_.calibratedStates_.impedence_[7]));
            this->ui->lineEdit_c42->setEnabled(false);

            this->ui->lineEdit_c51->setText(QString("%1").arg(this->tacSensor_.calibratedStates_.impedence_[8]));
            this->ui->lineEdit_c51->setEnabled(false);
            this->ui->lineEdit_c52->setText(QString("%1").arg(this->tacSensor_.calibratedStates_.impedence_[9]));
            this->ui->lineEdit_c52->setEnabled(false);

            this->ui->lineEdit_c61->setText(QString("%1").arg(this->tacSensor_.calibratedStates_.impedence_[10]));
            this->ui->lineEdit_c61->setEnabled(false);
            this->ui->lineEdit_c62->setText(QString("%1").arg(this->tacSensor_.calibratedStates_.impedence_[11]));
            this->ui->lineEdit_c62->setEnabled(false);

            this->ui->lineEdit_c71->setText(QString("%1").arg(this->tacSensor_.calibratedStates_.impedence_[12]));
            this->ui->lineEdit_c71->setEnabled(false);
            this->ui->lineEdit_c72->setText(QString("%1").arg(this->tacSensor_.calibratedStates_.impedence_[13]));
            this->ui->lineEdit_c72->setEnabled(false);

            this->ui->lineEdit_c81->setText(QString("%1").arg(this->tacSensor_.calibratedStates_.impedence_[14]));
            this->ui->lineEdit_c81->setEnabled(false);
            this->ui->lineEdit_c82->setText(QString("%1").arg(this->tacSensor_.calibratedStates_.impedence_[15]));
            this->ui->lineEdit_c82->setEnabled(false);

        }
    });

    connect(&this->tacSensor_.comPort_, &QSerialPort::readyRead, [this]()
    {
        this->tacSensor_.updateStates();
        if(this->tacSensor_.isCalibrated())
        {
            // SHIT !!!
            this->ui->lineEdit_m11->setText(QString("%1").arg(this->tacSensor_.sensorStates_.impedence_[0]));
            this->ui->lineEdit_m12->setText(QString("%1").arg(this->tacSensor_.sensorStates_.impedence_[1]));


            this->ui->lineEdit_m21->setText(QString("%1").arg(this->tacSensor_.sensorStates_.impedence_[2]));
            this->ui->lineEdit_m22->setText(QString("%1").arg(this->tacSensor_.sensorStates_.impedence_[3]));


            this->ui->lineEdit_m31->setText(QString("%1").arg(this->tacSensor_.sensorStates_.impedence_[4]));
            this->ui->lineEdit_m32->setText(QString("%1").arg(this->tacSensor_.sensorStates_.impedence_[5]));


            this->ui->lineEdit_m41->setText(QString("%1").arg(this->tacSensor_.sensorStates_.impedence_[6]));
            this->ui->lineEdit_m42->setText(QString("%1").arg(this->tacSensor_.sensorStates_.impedence_[7]));


            this->ui->lineEdit_m51->setText(QString("%1").arg(this->tacSensor_.sensorStates_.impedence_[8]));
            this->ui->lineEdit_m52->setText(QString("%1").arg(this->tacSensor_.sensorStates_.impedence_[9]));


            this->ui->lineEdit_m61->setText(QString("%1").arg(this->tacSensor_.sensorStates_.impedence_[10]));
            this->ui->lineEdit_m62->setText(QString("%1").arg(this->tacSensor_.sensorStates_.impedence_[11]));

            this->ui->lineEdit_m71->setText(QString("%1").arg(this->tacSensor_.sensorStates_.impedence_[12]));
            this->ui->lineEdit_m72->setText(QString("%1").arg(this->tacSensor_.sensorStates_.impedence_[13]));

            this->ui->lineEdit_m81->setText(QString("%1").arg(this->tacSensor_.sensorStates_.impedence_[14]));
            this->ui->lineEdit_m82->setText(QString("%1").arg(this->tacSensor_.sensorStates_.impedence_[15]));


            QString text {};
            if(compare(this->tacSensor_.calibratedStates_.impedence_[0],this->tacSensor_.sensorStates_.impedence_[0]))
            {
                text.append(QString("+i1"));
            }

            if(compare(this->tacSensor_.calibratedStates_.impedence_[1],this->tacSensor_.sensorStates_.impedence_[1]))
            {
                text.append(QString("+q1"));
            }

            if(compare(this->tacSensor_.calibratedStates_.impedence_[2],this->tacSensor_.sensorStates_.impedence_[2]))
            {
                text.append(QString("+i2"));
            }

            if(compare(this->tacSensor_.calibratedStates_.impedence_[3],this->tacSensor_.sensorStates_.impedence_[3]))
            {
                text.append(QString("+q2"));
            }

            if(compare(this->tacSensor_.calibratedStates_.impedence_[4],this->tacSensor_.sensorStates_.impedence_[4]))
            {
                text.append(QString("+i3"));
            }

            if(compare(this->tacSensor_.calibratedStates_.impedence_[5],this->tacSensor_.sensorStates_.impedence_[5]))
            {
                text.append(QString("+q3"));
            }

            if(compare(this->tacSensor_.calibratedStates_.impedence_[6],this->tacSensor_.sensorStates_.impedence_[6]))
            {
                text.append(QString("+i4"));
            }

            if(compare(this->tacSensor_.calibratedStates_.impedence_[7],this->tacSensor_.sensorStates_.impedence_[7]))
            {
                text.append(QString("+q4"));
            }

            if(compare(this->tacSensor_.calibratedStates_.impedence_[8],this->tacSensor_.sensorStates_.impedence_[8]))
            {
                text.append(QString("+i5"));
            }

            if(compare(this->tacSensor_.calibratedStates_.impedence_[9],this->tacSensor_.sensorStates_.impedence_[9]))
            {
                text.append(QString("+q5"));
            }

            if(compare(this->tacSensor_.calibratedStates_.impedence_[10],this->tacSensor_.sensorStates_.impedence_[10]))
            {
                text.append(QString("+i6"));
            }

            if(compare(this->tacSensor_.calibratedStates_.impedence_[11],this->tacSensor_.sensorStates_.impedence_[11]))
            {
                text.append(QString("+q6"));
            }

            if(compare(this->tacSensor_.calibratedStates_.impedence_[12],this->tacSensor_.sensorStates_.impedence_[12]))
            {
                text.append(QString("+i7"));
            }
            if(compare(this->tacSensor_.calibratedStates_.impedence_[13],this->tacSensor_.sensorStates_.impedence_[13]))
            {
                text.append(QString("+q7"));
            }

            if(compare(this->tacSensor_.calibratedStates_.impedence_[14],this->tacSensor_.sensorStates_.impedence_[14]))
            {
                text.append(QString("+i8"));
            }
            if(compare(this->tacSensor_.calibratedStates_.impedence_[15],this->tacSensor_.sensorStates_.impedence_[15]))
            {
                text.append(QString("+q8"));
            }

            this->ui->touchPoint_1->setStyleSheet("QLabel { background-color : white }");
            this->ui->touchPoint_2->setStyleSheet("QLabel { background-color : white }");
            this->ui->touchPoint_3->setStyleSheet("QLabel { background-color : white }");
            this->ui->touchPoint_4->setStyleSheet("QLabel { background-color : white }");
            this->ui->touchPoint_5->setStyleSheet("QLabel { background-color : white }");
            this->ui->touchPoint_6->setStyleSheet("QLabel { background-color : white }");
            this->ui->touchPoint_7->setStyleSheet("QLabel { background-color : white }");
            this->ui->touchPoint_8->setStyleSheet("QLabel { background-color : white }");
            this->ui->touchPoint_9->setStyleSheet("QLabel { background-color : white }");
            this->ui->touchPoint_10->setStyleSheet("QLabel { background-color : white }");
            this->ui->touchPoint_11->setStyleSheet("QLabel { background-color : white }");
            this->ui->touchPoint_12->setStyleSheet("QLabel { background-color : white }");
            this->ui->touchPoint_13->setStyleSheet("QLabel { background-color : white }");
            this->ui->touchPoint_14->setStyleSheet("QLabel { background-color : white }");
            this->ui->touchPoint_15->setStyleSheet("QLabel { background-color : white }");
            this->ui->touchPoint_16->setStyleSheet("QLabel { background-color : white }");

            if(compare(this->tacSensor_.calibratedStates_.impedence_[6],this->tacSensor_.sensorStates_.impedence_[6]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[7],this->tacSensor_.sensorStates_.impedence_[7]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[8],this->tacSensor_.sensorStates_.impedence_[8]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[9],this->tacSensor_.sensorStates_.impedence_[9]))
            {
                this->ui->touchPoint_1->setStyleSheet("QLabel { background-color : red }");
            }

            if(compare(this->tacSensor_.calibratedStates_.impedence_[4],this->tacSensor_.sensorStates_.impedence_[4]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[5],this->tacSensor_.sensorStates_.impedence_[5]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[8],this->tacSensor_.sensorStates_.impedence_[8]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[9],this->tacSensor_.sensorStates_.impedence_[9]))
            {
                this->ui->touchPoint_2->setStyleSheet("QLabel { background-color : blue }");
            }

            if(compare(this->tacSensor_.calibratedStates_.impedence_[2],this->tacSensor_.sensorStates_.impedence_[2]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[3],this->tacSensor_.sensorStates_.impedence_[3]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[8],this->tacSensor_.sensorStates_.impedence_[8]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[9],this->tacSensor_.sensorStates_.impedence_[9]))
            {
                this->ui->touchPoint_3->setStyleSheet("QLabel { background-color : blue }");
            }


            if(compare(this->tacSensor_.calibratedStates_.impedence_[0],this->tacSensor_.sensorStates_.impedence_[0]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[1],this->tacSensor_.sensorStates_.impedence_[1]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[8],this->tacSensor_.sensorStates_.impedence_[8]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[9],this->tacSensor_.sensorStates_.impedence_[9]))
            {
                this->ui->touchPoint_4->setStyleSheet("QLabel { background-color : blue }");
            }

            if(compare(this->tacSensor_.calibratedStates_.impedence_[6],this->tacSensor_.sensorStates_.impedence_[6]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[7],this->tacSensor_.sensorStates_.impedence_[7]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[10],this->tacSensor_.sensorStates_.impedence_[10]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[11],this->tacSensor_.sensorStates_.impedence_[11]))
            {
                this->ui->touchPoint_5->setStyleSheet("QLabel { background-color : blue }");
            }

            if(compare(this->tacSensor_.calibratedStates_.impedence_[4],this->tacSensor_.sensorStates_.impedence_[4]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[5],this->tacSensor_.sensorStates_.impedence_[5]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[10],this->tacSensor_.sensorStates_.impedence_[10]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[11],this->tacSensor_.sensorStates_.impedence_[11]))
            {
                this->ui->touchPoint_6->setStyleSheet("QLabel { background-color : blue }");
            }

            if(compare(this->tacSensor_.calibratedStates_.impedence_[2],this->tacSensor_.sensorStates_.impedence_[2]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[3],this->tacSensor_.sensorStates_.impedence_[3]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[10],this->tacSensor_.sensorStates_.impedence_[10]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[11],this->tacSensor_.sensorStates_.impedence_[11]))
            {
                this->ui->touchPoint_7->setStyleSheet("QLabel { background-color : blue }");
            }

            if(compare(this->tacSensor_.calibratedStates_.impedence_[0],this->tacSensor_.sensorStates_.impedence_[0]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[1],this->tacSensor_.sensorStates_.impedence_[1]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[10],this->tacSensor_.sensorStates_.impedence_[10]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[11],this->tacSensor_.sensorStates_.impedence_[11]))
            {
                this->ui->touchPoint_8->setStyleSheet("QLabel { background-color : blue }");
            }


            if(compare(this->tacSensor_.calibratedStates_.impedence_[6],this->tacSensor_.sensorStates_.impedence_[6]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[7],this->tacSensor_.sensorStates_.impedence_[7]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[14],this->tacSensor_.sensorStates_.impedence_[14]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[15],this->tacSensor_.sensorStates_.impedence_[15]))
            {
                this->ui->touchPoint_9->setStyleSheet("QLabel { background-color : blue }");
            }

            if(compare(this->tacSensor_.calibratedStates_.impedence_[4],this->tacSensor_.sensorStates_.impedence_[4]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[5],this->tacSensor_.sensorStates_.impedence_[5]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[14],this->tacSensor_.sensorStates_.impedence_[14]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[15],this->tacSensor_.sensorStates_.impedence_[15]))
            {
                this->ui->touchPoint_10->setStyleSheet("QLabel { background-color : blue }");
            }

            if(compare(this->tacSensor_.calibratedStates_.impedence_[2],this->tacSensor_.sensorStates_.impedence_[2]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[3],this->tacSensor_.sensorStates_.impedence_[3]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[14],this->tacSensor_.sensorStates_.impedence_[14]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[15],this->tacSensor_.sensorStates_.impedence_[15]))
            {
                this->ui->touchPoint_11->setStyleSheet("QLabel { background-color : blue }");
            }

            if(compare(this->tacSensor_.calibratedStates_.impedence_[0],this->tacSensor_.sensorStates_.impedence_[0]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[1],this->tacSensor_.sensorStates_.impedence_[1]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[14],this->tacSensor_.sensorStates_.impedence_[14]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[15],this->tacSensor_.sensorStates_.impedence_[15]))
            {
                this->ui->touchPoint_12->setStyleSheet("QLabel { background-color : blue }");
            }


            if(compare(this->tacSensor_.calibratedStates_.impedence_[6],this->tacSensor_.sensorStates_.impedence_[6]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[7],this->tacSensor_.sensorStates_.impedence_[7]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[12],this->tacSensor_.sensorStates_.impedence_[12]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[13],this->tacSensor_.sensorStates_.impedence_[13]))
            {
                this->ui->touchPoint_13->setStyleSheet("QLabel { background-color : blue }");
            }


            if(compare(this->tacSensor_.calibratedStates_.impedence_[4],this->tacSensor_.sensorStates_.impedence_[4]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[5],this->tacSensor_.sensorStates_.impedence_[5]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[12],this->tacSensor_.sensorStates_.impedence_[12]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[13],this->tacSensor_.sensorStates_.impedence_[13]))
            {
                this->ui->touchPoint_14->setStyleSheet("QLabel { background-color : blue }");
            }


            if(compare(this->tacSensor_.calibratedStates_.impedence_[2],this->tacSensor_.sensorStates_.impedence_[2]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[3],this->tacSensor_.sensorStates_.impedence_[3]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[12],this->tacSensor_.sensorStates_.impedence_[12]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[13],this->tacSensor_.sensorStates_.impedence_[13]))
            {
                this->ui->touchPoint_15->setStyleSheet("QLabel { background-color : blue }");
            }

            if(compare(this->tacSensor_.calibratedStates_.impedence_[0],this->tacSensor_.sensorStates_.impedence_[0]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[1],this->tacSensor_.sensorStates_.impedence_[1]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[12],this->tacSensor_.sensorStates_.impedence_[12]) &&
                    compare(this->tacSensor_.calibratedStates_.impedence_[13],this->tacSensor_.sensorStates_.impedence_[13]))
            {
                this->ui->touchPoint_16->setStyleSheet("QLabel { background-color : blue }");
            }


        }
    }  );

}

MainWindow::~MainWindow()
{
    delete ui;
}

