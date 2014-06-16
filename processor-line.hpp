#ifndef PROCESSOR_LINE_HPP
#define PROCESSOR_LINE_HPP

#include "geometry-processor.hpp"

struct processor_line : public geometry_processor {
    processor_line(int srid);
    virtual ~processor_line();

    geometry_builder::maybe_wkt_t process_way(const osmNode *nodes, size_t node_count);

private:
    geometry_builder builder;
};

#endif /* PROCESSOR_LINE_HPP */
