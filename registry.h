#ifndef REGISTRY_H
#define REGISTRY_H
#include <QList>
#include"company.h"
/*
 * Реестр предприятий представляет собой класс
 * Singleton, содержащий список (QList) предприятий
 * и методы, необходимые для работы со списком:*/
class registry{
private:
    QList<company* > companyList;
    registry(const QList<company* >& cl) :
        companyList(cl) {}
    registry() {}
public:
    registry(registry& re) = delete;
    void operator=(const registry& re) = delete;
    static registry& getInstance();
    void AddCompany(company& c);
    company* getCompanyByIndex(int index) const;
    int getRegistrySize() const;
};

#endif // REGISTRY_H
