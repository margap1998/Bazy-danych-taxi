#ifndef SZUKAJOBSLUGI_H
#define SZUKAJOBSLUGI_H

#include <QDialog>
#include <QSqlRelationalTableModel>

namespace Ui {
class szukajObslugi;
}

class szukajObslugi : public QDialog
{
    Q_OBJECT

public:
    explicit szukajObslugi(QSqlRelationalTableModel *model, QWidget *parent = nullptr);
    ~szukajObslugi();

private:
    Ui::szukajObslugi *ui;
    QSqlRelationalTableModel *modelR;
};

#endif // SZUKAJOBSLUGI_H
