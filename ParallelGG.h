#pragma once
#include "Graph.h"

class ParallelGG
{
public:

	/**
	* \brief generate a random graph by connecting n random edges
	* \param numVertices number of vertices in the graph
	* \param numEdges number of edges in the graph
	* \param parallelEdges allow parallel edges
	* \return an \ref edge_list
	* \note the algorithm will not produce self loops.
	*/
	static edge_list generateGraph(const int numVertices, const int numEdges, const bool parallelEdges = false);
};

