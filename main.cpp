#include <QTextStream>
#include"registry.h"
#include <QCoreApplication>

/*В main.cpp требуется реализовать следующие функции:
1. Вывести в консоль информацию о предприятиях
определённого типа.
2. Вывести в консоль все предприятия,
принадлежащие определённому владельцу.
3. Вывести в консоль средние показатели
(доход, площадь, число сотрудников) предприятий для
каждого из типов. А также заполнить реестр
(добавить несколько предприятий различных типов) и
продемонстрировать на нём работу этих функций.*/

void getInfoByType(company::type flag, registry& r, QTextStream& out)
{
    switch (flag) {
    case company::type::Local:
        out << "Local companies: " << Qt::endl;
        break;
    case company::type::Multinational:
        out << "Multinational companies: " << Qt::endl;
        break;
    case company::type::Government:
        out << "Government companies: " << Qt::endl;
        break;
    }

    for (int i = 0; i < r.getRegistrySize(); i++) {
        if (r.getCompanyByIndex(i)->getType() == flag) {
            out << "Name: " << r.getCompanyByIndex(i)->getName() << Qt::endl;
            out << "Owners: ";
            for (int j = 0; j < r.getCompanyByIndex(i)->getOwners().size(); j++)
            {
                out << r.getCompanyByIndex(i)->getOwners().operator[](j);
                if (j != r.getCompanyByIndex(i)->getOwners().size() - 1)
                    out << ", ";
            }
            out << Qt::endl;
            out << "Income: " << r.getCompanyByIndex(i)->getIncome() << Qt::endl;
            out << "Area: " << r.getCompanyByIndex(i)->getArea() << Qt::endl;
            out << "Number of employees: " << r.getCompanyByIndex(i)->getEmployeeNumber() << Qt::endl;
        }
    }
}
void getAverageValues(company::type flag, registry& cr, QTextStream& out)
{
    int n = 0;
    float sumIncome = 0;
    float sumArea = 0;
    float sumNumberOfEmployees = 0;
    for (int i = 0; i < cr.getRegistrySize(); i++) {
        if (flag == cr.getCompanyByIndex(i)->getType()) {
            sumIncome += cr.getCompanyByIndex(i)->getIncome();
            sumArea += cr.getCompanyByIndex(i)->getArea();
            sumNumberOfEmployees += cr.getCompanyByIndex(i)->getEmployeeNumber();
            n++;
        }
    }
    out << "Average income = " << sumIncome / n << Qt::endl;
    out << "Average area = " << sumArea / n << Qt::endl;
    out << "Average number of employees = " << sumNumberOfEmployees / n << Qt::endl;
}

void getCompaniesByOwner(QString&& owner, registry& cr, QTextStream& out)
{
    bool found = false;
    if (!owner.isEmpty()) {
        int companies_per_owner = 0;
        for (int i = 0; i < cr.getRegistrySize(); i++) {
            for (int j = 0; j < cr.getCompanyByIndex(i)->getOwners().size(); j++) {
                if (owner == cr.getCompanyByIndex(i)->getOwners().at(j)) {
                    if (companies_per_owner > 0)
                        out << ", " << cr.getCompanyByIndex(i)->getName();
                    else
                        out << owner << " owns " << cr.getCompanyByIndex(i)->getName();
                    companies_per_owner++;
                    found = true;
                }
            }
        }
    }
    if (!found)
        out << "Nothing found!";
    out << Qt::endl;
}


int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QTextStream out(stdout);
    /* данные Microsoft */
    QList<QString> microsoftOwners;
    QString microsoftName = "Microsoft";
    /* данные Apple Inc. */
    QList<QString> appleOwners;
    QString appleName = "Apple Inc.";
    /*данные JetBrains*/
    QList<QString> JetBrainsOwners;
    QString JetBrainsName = "JetBrains";
    /* данные Speedwagon Foundation*/
    QList<QString> speedFoundOwners;
    QString speedFoundName = "Speedwagon Foundation";
    /*Пуш данных Microsoft в коллекцию*/
    microsoftOwners.append(QString::fromUtf8("Bill Gates"));
    microsoftOwners.append(QString::fromUtf8("Paul Allen"));
    /*Пуш данных Apple Inc. в коллекцию*/
    appleOwners.append(QString::fromUtf8("Bill Gates"));
    /*Пуш данных JetBrains в коллекцию*/
    JetBrainsOwners.append(QString::fromUtf8("Ingvar Kamprad"));
    /*Пуш данных Speedwagon Foundation в коллекцию*/
    speedFoundOwners.append(QString::fromUtf8("Alexey Miller"));
    /*Создание обьекты классов*/
    company* microsoftCompany = new MultinationalCompany(microsoftName, microsoftOwners, 100000, 40000, 300);
    company* appleCompany = new LocalCompany(appleName , appleOwners, 40000, 10000, 250);
    company* JetBrainsCompany = new LocalCompany(JetBrainsName, JetBrainsOwners, 60000, 20000, 450);
    company* speedFoundCompany = new GovernmentCompany(speedFoundName , speedFoundOwners, 80000, 40000, 300);
    /*Реестр*/
    registry& cr = registry::getInstance();
    /*добавление компаний в реестр*/
    cr.AddCompany(*microsoftCompany );
    cr.AddCompany(*appleCompany );
    cr.AddCompany(*JetBrainsCompany);
    cr.AddCompany(*speedFoundCompany);

    /*Вывести в консоль информацию о предприятиях определённого типа.*/
    getInfoByType(company::type::Multinational, cr, out);
    /* 2. Вывести в консоль все предприятия, принадлежащие определённому владельцу.*/
    out << Qt::endl;
    getCompaniesByOwner(QString::fromUtf8("Bill Gates"), cr, out);
    /* 3. Вывести в консоль средние показатели (доход, площадь, число сотрудников) предприятий для каждого из типов.*/
    out << Qt::endl;
    getAverageValues(company::type::Local, cr, out);
    /*очистка памяти*/
    delete microsoftCompany ;
    delete appleCompany;
    delete JetBrainsCompany;
    delete speedFoundCompany;
    return 0;
}

