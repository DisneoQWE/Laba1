#include "company.h"

QList<QString> company::getOwners() const
{
    return owners;
}

void company::setOwners(const QList<QString> &value)
{
    owners = value;
}

QString company::getName() const
{
    return name;
}

void company::setName(const QString &value)
{
    name = value;
}

company::company()
{

}

double company::getArea() const
{
    return area;
}

void company::setArea(double value)
{
    area = value;
}

int company::getEmployeeNumber() const
{
    return employeeNumber;
}

void company::setEmployeeNumber(int value)
{
    employeeNumber = value;
}

double company::getIncome() const
{
    return income;
}

void company::setIncome(double value)
{
    income = value;
}
