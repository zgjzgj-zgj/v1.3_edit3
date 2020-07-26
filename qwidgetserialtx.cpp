#include "qwidgetserialtx.h"
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>
#include <QTimer>
#include <QDebug>

int ecgWaveData[]=
{
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2008, 2016, 2016, 2016, 2024, 2032, 2048,
    2064, 2064, 2064, 2072, 2080, 2080, 2080, 2088, 2096, 2104,
    2112, 2112, 2112, 2112, 2112, 2112, 2104, 2096, 2088,
    2080, 2080, 2080, 2072, 2064, 2064, 2064, 2048, 2032, 2032,
    2032, 2016, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 1992, 1984, 1976,
    1968, 1960, 1952, 1944, 1936, 1944, 1952, 2016, 2080, 2136,
    2192, 2256, 2320, 2376, 2432, 2488, 2544, 2568, 2592, 2536,
    2480, 2424, 2368, 2304, 2240, 2184, 2128, 2072, 2016, 1968,
    1920, 1928, 1936, 1944, 1952, 1960, 1968, 1984, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2008, 2016, 2024, 2032, 2032,
    2032, 2048, 2064, 2064, 2064, 2072, 2080, 2088, 2096, 2104,
    2112, 2112, 2112, 2120, 2128, 2136, 2144, 2152, 2160, 2160,
    2160, 2160, 2160, 2168, 2176, 2176, 2176, 2184, 2192,
    2192, 2192, 2192, 2200, 2208, 2208, 2208, 2208, 2208, 2208,
    2208, 2200, 2192, 2192, 2192, 2184, 2176, 2176, 2176, 2168,
    2160, 2160, 2160, 2144, 2128, 2128, 2128, 2128, 2128, 2112,
    2096, 2088, 2080, 2072, 2064, 2064, 2064, 2048, 2032, 2024,
    2016, 2016, 2016, 2008, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000//, 2000, 2000
};

int spo2WaveData[]=
{
    0x21, 0x21, 0x22, 0x22, 0x23, 0x22, 0x22, 0x21, 0x21,
        0x20, 0x20, 0x1f, 0x1e, 0x1d, 0x1c, 0x1b, 0x1b, 0x1a,
        0x19, 0x18, 0x18, 0x17, 0x16, 0x15, 0x14, 0x13, 0x12,
        0x11, 0x11, 0x10, 0x10, 0x0f, 0x0f, 0x0e, 0x0d, 0x0c,
        0x0c, 0x0b, 0x0a, 0x09, 0x09, 0x08, 0x07, 0x06, 0x06,
        0x05, 0x05, 0x04, 0x04, 0x03, 0x03, 0x02, 0x02, 0x01,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x01, 0x03, 0x06, 0x0a, 0x0e, 0x13, 0x18, 0x1d,
        0x23, 0x28, 0x2d, 0x32, 0x37, 0x3b, 0x40, 0x44, 0x49,
        0x4d, 0x51, 0x54, 0x57, 0x58, 0x5a, 0x5a, 0x5a, 0x59,
        0x59, 0x57, 0x55, 0x52, 0x50, 0x4c, 0x49, 0x45, 0x42,
        0x3e, 0x3b, 0x37, 0x34, 0x31, 0x2f, 0x2c, 0x29, 0x26,
        0x24, 0x22, 0x20, 0x1f, 0x1f, 0x1e, 0x1e, 0x1d, 0x1d,
        0x1e, 0x1f, 0x20, 0x21, 0x21, 0x22, 0x22, 0x23, 0x22,
        0x22, 0x21, 0x21, 0x20, 0x20, 0x1f, 0x1e, 0x1d, 0x1c,
        0x1b, 0x1b, 0x1a, 0x19, 0x18, 0x18, 0x17, 0x16, 0x15,
        0x14, 0x13, 0x12, 0x11, 0x11, 0x10, 0x10, 0x0f, 0x0f,
        0x0e, 0x0d, 0x0c, 0x0c, 0x0b, 0x0a, 0x09, 0x09, 0x08,
        0x07, 0x06, 0x06, 0x05, 0x05, 0x04, 0x04, 0x03, 0x03,
        0x02, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x06, 0x0a, 0x0e,
        0x13, 0x18, 0x1d, 0x23, 0x28, 0x2d, 0x32, 0x37, 0x3b,
        0x40, 0x44, 0x49, 0x4d, 0x51, 0x54, 0x57, 0x58, 0x5a,
        0x5a, 0x5a, 0x59, 0x59, 0x57, 0x55, 0x52, 0x50, 0x4c,
        0x49, 0x45, 0x42, 0x3e, 0x3b, 0x37, 0x34, 0x31, 0x2f,
        0x2c, 0x29, 0x26, 0x24, 0x22, 0x20, 0x1f, 0x1f, 0x1e,
        0x1e, 0x1d, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x21, 0x22,
        0x22, 0x23, 0x22, 0x22, 0x21
};

int ibp2WaveData[]=
{
    0x0f, 0x10, 0x10, 0x11, 0x12, 0x12, 0x12, 0x13, 0x13,
    0x14, 0x14, 0x14, 0x14, 0x15, 0x17, 0x17, 0x17, 0x18,
    0x18, 0x19, 0x19, 0x19, 0x19, 0x1a, 0x19, 0x1a, 0x1a,
    0x1b, 0x1b, 0x1b, 0x1c, 0x1c, 0x1b, 0x1b, 0x1a, 0x1a,
    0x1a, 0x19, 0x19, 0x18, 0x18, 0x18, 0x17, 0x17, 0x15,
    0x15, 0x15, 0x14, 0x15, 0x14, 0x14, 0x14, 0x15, 0x15,
    0x14, 0x14, 0x15, 0x14, 0x14, 0x14, 0x15, 0x17, 0x17,
    0x17, 0x17, 0x18, 0x18, 0x19, 0x19, 0x19, 0x1a, 0x1b,
    0x1c, 0x1d, 0x1f, 0x20, 0x21, 0x22, 0x23, 0x24, 0x24,
    0x24, 0x26, 0x26, 0x26, 0x26, 0x24, 0x23, 0x23, 0x23,
    0x23, 0x22, 0x21, 0x20, 0x1d, 0x1d, 0x1c, 0x1c, 0x1c,
    0x1c, 0x1c, 0x1c, 0x1c, 0x1b, 0x1c, 0x1b, 0x1a, 0x1a,
    0x19, 0x18, 0x17, 0x15, 0x14, 0x12, 0x12, 0x11, 0x10,
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f
};


QWidgetSerialTx::QWidgetSerialTx(QWidget *parent) : QWidget(parent)
{
    this->serialInit();

    // 创建定时器
    this->timer = new QTimer();
    // 定时器溢出信号与发送ecg数据包函数关联
    connect(this->timer, &QTimer::timeout, this, &QWidgetSerialTx::serialTx);
    // 启动定时器
    this->timer->start(10);
}



unsigned int QWidgetSerialTx::getEcg2Data()
{
    this->index1 += 1;
    if(this->index1 >= sizeof(ecgWaveData)/sizeof(int))
        this->index1 = 0;
    return ecgWaveData[this->index1];
}

unsigned int QWidgetSerialTx::getSpo2Data()
{
    this->index2 += 1;
    if(this->index2 >= sizeof(spo2WaveData)/sizeof(int))
        this->index2 = 0;
    return spo2WaveData[this->index2];
}

unsigned int QWidgetSerialTx::getIbp2Data()
{
    this->index3 += 1;
    if(this->index3 >= sizeof(ibp2WaveData)/sizeof(int))
        this->index3 = 0;
    return ibp2WaveData[this->index3];
}

void QWidgetSerialTx::serialTx()
{
    //ecg************************************************************************
    char dataBuf[10];
    unsigned int ecgData[3];
    int i;
    char byteH, byteL;

    // 取心电数据/获取ADC数据
    ecgData[0] = this->getEcg2Data();
    ecgData[1] = this->getEcg2Data();
    ecgData[2] = this->getEcg2Data();


    // 数据包格式：ID + 数据头 + 数据 + 校验
    // 数据打包
    dataBuf[0] = 0x08;
    dataBuf[1] = 0x80; // 最高位总是1
    // 添加数据
    for(i = 0; i < 3; i++)
    {
        byteH = (char)((ecgData[i]&0xFF00) >> 8);
        byteL = (char)(ecgData[i]&0xFF);
        // 字节最高位存入数据头
        dataBuf[1] = dataBuf[1] | ((byteH&0x80) >> (7 - i*2));
        dataBuf[1] = dataBuf[1] | ((byteL&0x80) >> (7 - i*2 - 1));
        // 添加数据
        dataBuf[2 + i*2] = 0x80 | byteH;
        dataBuf[2 + i*2 + 1] = 0x80 | byteL;
    }
    dataBuf[8] = 0x80; //数据状态字段暂时不用
    dataBuf[9] = 0xFF; //暂时不用

    this->com->write(dataBuf, 10);

    //spo******************************************************************
    char dataBuf2[5];
    unsigned int spoData;

    spoData = this->getSpo2Data();

    // 数据包格式：ID + 数据头 + 数据 + 校验
    // 数据打包
    dataBuf2[0] = 0x09;
    dataBuf2[1] = 0x80; // 最高位总是1
    // 添加数据
        byteH = (char)((spoData&0xFF00) >> 8);
        byteL = (char)(spoData&0xFF);
        // 字节最高位存入数据头
        dataBuf2[1] = dataBuf2[1] | ((byteH&0x80) >> (7));
        dataBuf2[1] = dataBuf2[1] | ((byteL&0x80) >> (6));
        // 添加数据
        dataBuf2[2] = 0x80 | byteH;
        dataBuf2[3] = 0x80 | byteL;

//    dataBuf2[3] = 0x80; //数据状态字段暂时不用
    dataBuf2[4] = 0xFF; //校验位暂时不用

    this->com->write(dataBuf2, 5);


    //ibp*******************************************************************send
    char dataBuf3[5];
    unsigned int ibpData;

    ibpData = this->getIbp2Data();

    // 数据包格式：ID + 数据头 + 数据 + 校验
    // 数据打包
    dataBuf3[0] = 0x0a;
    dataBuf3[1] = 0x80; // 最高位总是1
    // 添加数据

        byteH = (char)((ibpData&0xFF00) >> 8);
        byteL = (char)(ibpData&0xFF);
        // 字节最高位存入数据头
        dataBuf3[1] = dataBuf3[1] | ((byteH&0x80) >> (7));
        dataBuf3[1] = dataBuf3[1] | ((byteL&0x80) >> (6));
        // 添加数据
        dataBuf3[2] = 0x80 | byteH;
        dataBuf3[3] = 0x80 | byteL;

//    dataBuf3[3] = 0x80; //数据状态字段暂时不用
    dataBuf3[4] = 0xFF; //暂时不用

    this->com->write(dataBuf3, 5);
}


int QWidgetSerialTx::serialInit()
{
    // 查看设备串口信息
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        qDebug() << "Name : " << info.portName();
        qDebug() << "Description : " << info.description();
        qDebug() << "Manufacturer: " << info.manufacturer();
        qDebug() << "Serial Number: " << info.serialNumber();
    }

    // 创建串口对象
    this->com = new QSerialPort();
    // 打开串口
    this->com->setPortName("COM4");
    // 尝试打开
    if(!this->com->open(QIODevice::ReadWrite))
    {
       qDebug()<<"open serial error"<<this->com->portName();
       return -1;
    }
    else
       qDebug()<<"open serial success";

    // 串口参数配置
    this->com->setBaudRate(QSerialPort::Baud115200);
    this->com->setDataBits(QSerialPort::Data8);
    this->com->setFlowControl(QSerialPort::NoFlowControl);
    this->com->setParity(QSerialPort::NoParity);
    this->com->setStopBits(QSerialPort::OneStop);

    return 0;
}
