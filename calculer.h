#ifndef CALCULER_H
#define CALCULER_H

#include <QMainWindow>

namespace Ui {
class Calculer;
}

class Calculer : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculer(QWidget *parent = nullptr);
    ~Calculer();

private:
    Ui::Calculer *ui;

private slots :
    void NumPressed();
    void MathButtonPressed();
    void EqualButtonPressed();
    void ChangeNumberSign();
    //void on_Calculer_iconSizeChanged(const QSize &iconSize);
};

#endif // CALCULER_H
