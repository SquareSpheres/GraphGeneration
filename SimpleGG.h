/*
* This is free and unencumbered software released into the public domain.
*
* Anyone is free to copy, modify, publish, use, compile, sell, or
* distribute this software, either in source code form or as a compiled
* binary, for any purpose, commercial or non-commercial, and by any
* means.
*
* In jurisdictions that recognize copyright laws, the author or authors
* of this software dedicate any and all copyright interest in the
* software to the public domain.We make this dedication for the benefit
* of the public at large and to the detriment of our heirs and
* successors.We intend this dedication to be an overt act of
* relinquishment in perpetuity of all present and future rights to this
* software under copyright law.
*
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
* OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
* OTHER DEALINGS IN THE SOFTWARE.
*
* For more information, please refer to<http://unlicense.org>
*/

#pragma once
#include <vector>
#include "Graph.h"

class SimpleGG
{

public:

	/**
	 * \brief generate a random graph by connecting vertices with probability p
	 * \param numVertices number of vertices in the graph
	 * \param prob probability of an edge between vertices
	 * \return an \ref edge_list
	 * \note Do not use this for graph with a large amount of vertices. The Running time of the algortihm is O(n^2), or n(n-1)/2.
	 */
	static edge_list generateGraph(const int numVertices, const double prob = 0.5);

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

