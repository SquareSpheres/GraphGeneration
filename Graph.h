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
#include <iostream>


/**
 * \brief simple edge representation
 */
struct Edge
{
	int from;
	int to;

	inline bool operator < (const Edge &e) const
	{
		return from < e.from || (from == e.from && to < e.to);
	}

	inline bool operator >(const Edge &e) const
	{
		return from > e.from || (from == e.from && to > e.to);
	}

	inline bool operator ==(const Edge &e) const
	{
		return from == e.from && to == e.to;
	}

	friend  std::ostream& operator << (std::ostream &stream, const Edge &e)
	{
		return stream << "[" << e.from << "->" << e.to << "]";
	}
};


/**
 * \brief simple hash function for edges
 */
struct EdgeHash
{
	inline size_t operator()(const Edge &e) const
	{
		const int x = e.from;
		const int y = e.to;
		return ((x + y)*(x + y + 1) / 2 + y);
	}
};

typedef Edge edge;
typedef std::vector<edge> edge_list;


/**
 * \brief print out every edge in the list
 * \param list list of edges
 */
void PrintEdgeList(edge_list &list);

/**
* \brief calculate number of edges in a graph given a probability and number of vertices
* \param numVertices number of vertices
* \param prob probablity of an edge between vertices
* \return number of edges in the graph
*/
int NumEdgesFromProb(const int numVertices, const double prob = 0.5);

/**
 * Simple Graph representation
 */
class Graph
{

	const int num_vertices_;
	int num_edges_;
	std::vector<int> *adj_;

	void validateVertex(const int v) const;
public:
	explicit Graph(const int numVertices);
	Graph(const int numVertices, edge_list &list);
	~Graph();

	/**
	 * \brief get number of edges
	 * \return number of edges
	 */
	int numEdges() const;
	/**
	 * \brief get number of vertices
	 * \return number of vertices
	 */
	int numVertices() const;
	/**
	 * \brief get the degree of a vertex
	 * \param v a vertex
	 * \return the degree of vertex
	 */
	int degree(const int v) const;
	/**
	 * \brief add an edge to the graph
	 * \param from edge from
	 * \param to edge to
	 */
	void addEdge(const int from, const int to);
	/**
	 * \brief remove an edge from the graph
	 * \param from edge from
	 * \param to edge to
	 * \note Complexity : removing an edge is a very expensive operation as it has to search through the adjacency lists for the vertices.
	 *  The adjacency list also has to shift their elements if an item was removed.\n\n Behaviour : if the edge does not exist nothing will happen.
	 *   If there are parallel edges only the first occurance will be removed.
	 */
	void removeEdge(const int from, const int to);
	/**
	 * \brief create a list of all the edges in the graph
	 * \return graph edge list
	 */
	edge_list getEdgeList() const;
};

