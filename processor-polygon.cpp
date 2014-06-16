#include "processor-polygon.hpp"

#include <boost/format.hpp>

processor_polygon::processor_polygon(int srid, bool enable_multi) : geometry_processor(srid, "GEOMETRY", interest_way | interest_relation), enable_multi(enable_multi)
{
}

processor_polygon::~processor_polygon()
{
}

geometry_builder::maybe_wkt_t processor_polygon::process_way(const osmNode *nodes, const size_t node_count)
{
    //have the builder make the wkt
    geometry_builder::maybe_wkt_t wkt = builder.get_wkt_simple(nodes, node_count, true);
    //hand back the wkt
    return wkt;
}

geometry_builder::maybe_wkts_t processor_polygon::process_relation(const osmNode * const * nodes, const int* node_counts)
{
    //the hard word was already done for us in getting at the node data for each way. at this point just make the geom
    geometry_builder::maybe_wkts_t wkts  = builder.build_polygons(nodes, node_counts, enable_multi, -1);
    return wkts;
}
