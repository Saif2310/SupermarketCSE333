#include "CurrentCustomer.h"

CurrentCustomer* CurrentCustomer::m_instance = nullptr;

CurrentCustomer& CurrentCustomer::instance() {
    if (!m_instance) {
        m_instance = new CurrentCustomer;
    }
    return *m_instance;
}

CurrentCustomer::CurrentCustomer() : m_userName("") {} // Initialize member variable

