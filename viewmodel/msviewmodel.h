#ifndef MSVIEWMODEL_H
#define MSVIEWMODEL_H
#include"../common/etlbase.h"

class MSViewModel : public Proxy_CommandNotification<MSViewModel>, public Proxy_PropertyNotification<MSViewModel>
{
public:
    MSViewModel();
};

#endif // MSVIEWMODEL_H
