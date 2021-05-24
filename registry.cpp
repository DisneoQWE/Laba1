#include "registry.h"

void registry::setCompanyList(const QList<company *> &companyList)
{
    this->companyList = companyList;
}

void registry::changeCompany(company &c, int index)
{
    if(!companyList.empty()){
        companyList.replace(index, &c);
    }
}

registry& registry::getInstance()
{
    static registry instance;
    return instance;
}

void registry::AddCompany(company& c)
{
    companyList.append(&c);
}

company* registry::getCompanyByIndex(int index) const
{
    return companyList.at(index);
}

int registry::getRegistrySize() const
{
    return companyList.size();
}



