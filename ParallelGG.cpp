#include "stdafx.h"
#include "ParallelGG.h"
#include <omp.h>
#include <random>
#include <unordered_set>
#include <cassert>

edge_list ParallelGG::generateGraph(const int numVertices, const int numEdges, const bool parallelEdges)
{
	assert(numEdges <= numEdgesFromProb(numVertices, 1));

	edge_list edgeList;

#pragma omp parallel
	{
		//TODO
	}

	return edgeList;
}
