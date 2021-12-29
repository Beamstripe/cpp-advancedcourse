#include "train.h"
#include <ctime>
Time_t Train::getArrivalTime() const{
    return getDepartureTime().getDis(duration);
}
