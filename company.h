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
        Local, Multinational, Government
    };
    company(QString &name, QVector<QString> &owners,
            double income = 0, double area = 0, int numOfEmps = 0); //конструктор
    virtual ~company() {} //деструктор

    /*Для каждого из этих свойств должны быть реализованы
     * методы их получения/изменения.*/
    virtual type getType() = 0;
    virtual double getTaxPerMonth() = 0;
    double getIncome() const{
        return income;
    }
    double getArea() const{
        return area;
    }
    int getEmployeeNumber() const{
        return employeeNumber;
    }
    QList<QString> getOwners() const{
        return owners;
    }
    QString getName() const{
        return name;
    }
};


/*Далее, требуется реализовать три класса предприятий различных типов.*/
class LocalCompany: public company{
public:
    LocalCompany(QString &name, QList<QString> &owners,
    double income    = 0, double area = 0, int numberOfEmployees = 0);
    type getType();
    double getTaxPerMonth();
};
class MultinationalCompany: public company{
public:
    MultinationalCompany(QString &name, QList<QString> &owners,
                         double income = 0, double area = 0, int numberOfEmployees = 0);
    type getType();
    double getTaxPerMonth();
};
class GovernmentCompany : public company{
public:
   GovernmentCompany(QString &name, QList<QString> &owners,
                     double income = 0, double area = 0, int numberOfEmployees = 0);
   type getType();
   double getTaxPerMonth();
};

#endif // COMPANY_H
