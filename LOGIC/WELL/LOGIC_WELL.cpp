#include "LOGIC_WELL.h"

LOGIC_WELL::LOGIC_WELL()
{
    table_name = "[Well]";

    primary_key_column = 0;

    column_name.push_back("[id]");
    column_name.push_back("[wellNumber]");
    column_name.push_back("[wellType]");
    column_name.push_back("[nameOfEnterprises]");
    column_name.push_back("[location]");
    column_name.push_back("[area]");
    column_name.push_back("[loggingUnit]");
    column_name.push_back("[creatorID]");
    column_name.push_back("[Time]");
    column_name.push_back("[foreign_stratum_ids]");
    column_name.push_back("[foreign_neighbour_ids]");
    column_name.push_back("[foreign_realtime_ids]");
    column_name.push_back("[foreign_wellpath_ids]");
    column_name.push_back("[foreign_target_ids]");
    column_name.push_back("[foreign_basic_id]");
}
