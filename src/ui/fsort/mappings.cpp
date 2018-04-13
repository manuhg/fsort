#include "mappings.h"
#include "ui_mappings.h"

Mappings::Mappings(QWidget *parent,QMap<QString,QVector<double>> *map) :   QDialog(parent),  ui(new Ui::Mappings)
{
    ui->setupUi(this);

}

Mappings::~Mappings()
{
    delete ui;
}
