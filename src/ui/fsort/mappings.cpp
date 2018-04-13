#include "mappings.h"
#include "ui_mappings.h"

Mappings::Mappings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mappings)
{
    ui->setupUi(this);

}

Mappings::~Mappings()
{
    delete ui;
}
