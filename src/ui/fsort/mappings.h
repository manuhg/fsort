#ifndef MAPPINGS_H
#define MAPPINGS_H

#include <QDialog>

namespace Ui {
class Mappings;
}

class Mappings : public QDialog
{
    Q_OBJECT

public:
    explicit Mappings(QWidget *parent = 0);
    Mappings(/*recieve a dictionary when the object is invoked*/);
    ~Mappings();

private:
    Ui::Mappings *ui;
};

#endif // MAPPINGS_H
