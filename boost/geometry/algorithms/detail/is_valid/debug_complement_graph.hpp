// Boost.Geometry (aka GGL, Generic Geometry Library)

// Copyright (c) 2014, Oracle and/or its affiliates.

// Contributed and/or modified by Menelaos Karavelas, on behalf of Oracle

// Licensed under the Boost Software License version 1.0.
// http://www.boost.org/users/license.html

#ifndef BOOST_GEOMETRY_ALGORITHMS_DETAIL_IS_VALID_DEBUG_COMPLEMENT_GRAPH_HPP
#define BOOST_GEOMETRY_ALGORITHMS_DETAIL_IS_VALID_DEBUG_COMPLEMENT_GRAPH_HPP

#ifdef BOOST_GEOMETRY_TEST_DEBUG
#include <iostream>
#endif

namespace boost { namespace geometry
{

namespace detail { namespace is_valid
{


#ifdef BOOST_GEOMETRY_TEST_DEBUG
template <typename OutputStream, typename Vertex>
inline void debug_print_complement_graph(OutputStream& os,
                                         complement_graph<Vertex> const& graph)
{
    typedef typename complement_graph<Vertex>::vertex_handle vertex_handle;

    os << "num rings: " << graph.m_num_rings << std::endl;
    os << "vertex ids: {";
    for (vertex_handle it = graph.m_vertices.begin();
         it != graph.m_vertices.end(); ++it)
    {
        os << " " << it->id();
    }
    os << " }" << std::endl;        

    for (vertex_handle it = graph.m_vertices.begin();
         it != graph.m_vertices.end(); ++it)
    {
        os << "neighbors of " << it->id() << ": {";
        for (typename Vertex::neighbor_iterator nit = it->neighbors_begin();
             nit != it->neighbors_end(); ++nit)
        {
            os << " " << (*nit)->id();
        }
        os << "}" << std::endl;        
    }
}
#else
template <typename OutputStream, typename Vertex>
void debug_print_complement_graph(OutputStream&,
                                  complement_graph<Vertex> const&)
{
}
#endif


}} // namespace detail::is_valid

}} // namespace boost::geometry

#endif // BOOST_GEOMETRY_ALGORITHMS_DETAIL_IS_VALID_COMPLEMENT_GRAPH_HPP
