#ifndef MYGRAPHIC_H
#define MYGRAPHIC_H
#include <QObject>
#include <QLineSeries>
#include <QtCharts>
#include <QChartView>

class MyGraphic : public QObject{
    Q_OBJECT
private:
    QVector<QLineSeries*> ptr_graph_;
public:
    MyGraphic( uint size);
    void add_data_graph(const QVector<double> &x, const QVector<double> &y, uint num_graph);
    void clear_graph(QChart* chart);
    void update_graph(QChart* chart);
};


#endif // MYGRAPHIC_H
