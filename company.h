#ifndef COMPANY_H
#define COMPANY_H
#include <QList>
#include <QString>



/*
Программа должна быть спроектирована таким образом,
чтобы добавление новых типов предприятий не требовало внесения
изменений в класс реестра.
Для этого потребуется реализовать абстрактный класс предприятия,
который будет содержать следующие данные:
*/
class company
{
private:

    QString name; //название предприятия
    QList<QString> owners; //список владельцев предприятия
    double income; //доход предприятия
    double area; //площадь предприятия
    int employeeNumber; //количество сотрудников предприятия

public:
    /*
     * Помимо этого, в базовом классе содержится
     * объявление перечисления (enum),
     * значениями которого являются возможные типы предприятий.
*/
    enum type{
        Private, Multinational, Government
    };
    company(QString &name, QVector<QString> &owners,
            double income = 0, double area = 0, int numOfEmps = 0); //конструктор
    virtual ~company() {} //деструктор

    /*Для каждого из этих свойств должны быть реализованы
     * методы их получения/изменения.*/
    double getIncome() const;
    double getArea() const;
    void setArea(double value);
    int getEmployeeNumber() const;
    void setEmployeeNumber(int value);
    QList<QString> getOwners() const;
    void setOwners(const QList<QString> &value);
    QString getName() const;
    void setName(const QString &value);
};

#endif // COMPANY_H
