#include "tcp.h"

#include <ActiveQt/QAxFactory>

tcp::tcp(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
}

QAXFACTORY_DEFAULT(tcp,
    "{34d279df-1005-4d81-8ef2-ebd63518b35d}",
    "{20e81351-b289-4d44-93fc-67d37f73d355}",
    "{b296f033-b25f-4865-a7dd-021c300c8e90}",
    "{26c5819d-8c51-436b-914a-4fe57e8f0702}",
    "{1efa9e9d-8546-48cc-8c12-0ef09d4e64ad}"
)
