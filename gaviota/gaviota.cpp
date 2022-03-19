#include "gaviota.h"

int main()
{
    Gaviota::LogManager::Init();
    GAVIOTA_LEVEL_CORE_TRACE("Hello gaviota!");
    return 0;
}