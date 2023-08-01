#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDataStream>
#include <QMessageBox>
#include <QtGlobal>
#include <QtConcurrent>
#include <algorithm>


///Подключаем все что нужно для графиков
#include <QLineSeries>
#include <QtCharts>
#include <QChartView>
#include "myGraphic.h"

#include <QTimer>

#define FD 1000.0 //частота дискретизации

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //Метод считывает данные из исходного файла
    QVector<uint32_t> ReadFile(QString path, uint8_t numberChannel);
    //Метод преобразует данные физические величины, В?
    QVector<double> ProcessFile(QVector<uint32_t> dataFile);
    //Метод ищет Максимумы
    QVector<double> FindMax(QVector<double> resultData);
    //Метод ищет минимумы
    QVector<double> FindMin(QVector<double> resultData);
    //Метод отображает результаты
    void DisplayResult(QVector<double> mins, QVector<double> maxs);
    void show_graphic();
    void update_graphic(QVector<double> readData);

signals:
    void sg_start_graphic();
private slots:
    void on_pb_path_clicked();
    void on_pb_start_clicked();

    void on_pb_clearResult_clicked();
    void sl_update_graphic(QVector<double> readData);
    void get_copy_data();


private:
    Ui::MainWindow *ui;
    QString pathToFile = "";
    uint8_t numberSelectChannel = 0xEA;

    QVector<uint32_t> readData;
    QVector<uint32_t> readData_copy;
    QVector<double> procesData;
    QVector<double> mins, maxs;

    MyGraphic *graphic_class_;
    QChart *chart_;
    QChartView * chart_view_;
    QGridLayout *layout;

    QTimer *timer_;
};
#endif // MAINWINDOW_H