#ifndef STATISTIQUES_H
#define STATISTIQUES_H
#include "employee.h"
#include <QDialog>

namespace Ui {
class statistiques;
}

class statistiques : public QDialog
{
    Q_OBJECT
protected:
   void paintEvent(QPaintEvent *);
public:
    explicit statistiques(QWidget *parent = nullptr);
    ~statistiques();

private slots:
   void on_pushButton_11_clicked();

private:
    Ui::statistiques *ui;
    Employee V;
};

#endif // STATISTIQUES_H
