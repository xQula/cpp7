#include "myGraphic.h"

MyGraphic::MyGraphic( uint size)
{
    ptr_graph_.reserve(size);
    for(auto i = 0; i < size; ++i){
        ptr_graph_.emplaceBack(new QLineSeries(this));
    }
}

void MyGraphic::add_data_graph(const QVector<double> &x, const QVector<double> &y, uint num_graph)
{
    uint32_t max_size = x.size() > y.size() ? y.size() : x.size();
    for(uint32_t i = 0 ; i < max_size; ++i){
        ptr_graph_[num_graph]->append(x[i], y[i]);
    }

}

void MyGraphic::clear_graph(QChart *chart)
{
    for(auto &&i: ptr_graph_){
        i->clear();
        chart->removeSeries(i);
    }
}

void MyGraphic::update_graph(QChart *chart)
{
    for(auto &&i: ptr_graph_){
        chart->addSeries(i);
    }
}
