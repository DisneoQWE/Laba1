#include "company.h"

company::company(QString &name, QList<QString> &owners,
                 double income, double area, int employeeNumber)
{
    this->name = name;
    this->owners = owners;
    this->income = income;
    this->area = area;
    this->employeeNumber = employeeNumber;
}


company::type LocalCompany::getType()
{
    return type::Local;
}

LocalCompany::LocalCompany(QString &name, QList<QString> &owners,
    double income, double area, int employeeNumber)
    : company(name, owners, income, area, employeeNumber) {}

double LocalCompany::getTaxPerMonth()
{
    return getEmployeeNumber() * getArea() / getIncome() * 2.5;
}


MultinationalCompany::MultinationalCompany(QString &name,
QList<QString> &owners, double income, double area,
int employeeNumber): company(name, owners, income, area, employeeNumber) {}

company::type MultinationalCompany::getType()
{
    return type::Multinational;
}

double MultinationalCompany::getTaxPerMonth()
{
    return getEmployeeNumber() * getArea() / getIncome() * 3;
}


GovernmentCompany::GovernmentCompany(QString &name,
QList<QString> &owners,double income, double area,
int numberOfEmployees): company(name, owners, income, area, numberOfEmployees) {}

company::type GovernmentCompany::getType()
{
    return type::Government;
}

double GovernmentCompany::getTaxPerMonth()
{
    return getEmployeeNumber() * getArea() / getIncome() * 1;
;
}
