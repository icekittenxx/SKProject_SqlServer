#include "LOGIC_WELL_BASIC.h"

LOGIC_WELL_BASIC::LOGIC_WELL_BASIC()
{
    table_name = "[Well_Basic]";

    primary_key_column = 0;

    column_name.push_back("[id]");
    column_name.push_back("[wellHeadGeodeticCoordinateX]");
    column_name.push_back("[wellHeadGeodeticCoordinateY]");
    column_name.push_back("[kickOffPointTrueVerticalDepth]");
    column_name.push_back("[targetLayerTrueVerticalDepth]");
    column_name.push_back("[DrilledTrueVerticalDepth]");
    column_name.push_back("[geocenterAltitude]");
    column_name.push_back("[rotaryKellyHigh]");
    column_name.push_back("[inclinationCalculationMethod]");
    column_name.push_back("[doglegCalculationMethod]");
    column_name.push_back("[signalLength]");
    column_name.push_back("[levelDisplacement]");
    column_name.push_back("[Time]");
}
