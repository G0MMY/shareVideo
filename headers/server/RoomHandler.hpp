#ifndef ROOMHANDLER_HPP
#define ROOMHANDLER_HPP

#include <string>
#include "../../util/Json.hpp"

using namespace std;


class RoomHandler {
public:
    static string AddRoom(char* buffer, int length);
};

#endif
