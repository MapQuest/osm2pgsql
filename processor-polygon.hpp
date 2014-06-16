#ifndef PROCESSOR_POLYGON_HPP
#define PROCESSOR_POLYGON_HPP

#include "geometry-processor.hpp"

struct processor_polygon : public geometry_processor {
    processor_polygon(int srid, bool enable_multi);
    virtual ~processor_polygon();

    geometry_builder::maybe_wkt_t process_way(const osmNode *nodes, const size_t node_count);
    geometry_builder::maybe_wkts_t process_relation(const osmNode * const * nodes, const int* node_counts);

private:
    bool enable_multi;
    geometry_builder builder;
};

#endif /* PROCESSOR_POLYGON_HPP */
