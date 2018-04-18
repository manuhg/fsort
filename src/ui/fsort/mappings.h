#ifndef MAPPINGS_H
#define MAPPINGS_H
#include "deps.h"
#include <QDialog>

namespace Ui {
class Mappings;
}

class Mappings : public QDialog
{
    Q_OBJECT

public:
    explicit Mappings(QWidget *parent=nullptr,QMap<QString,QVector<double>> *map=nullptr) ;
    ~Mappings();

private:
    Ui::Mappings *ui;
    QGraphicsScene *scene;
    QGraphicsPixmapItem* item;
    QMap<QString,QVector<double>>::Iterator i;
};

#endif // MAPPINGS_H
