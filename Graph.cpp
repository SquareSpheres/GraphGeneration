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

#include "stdafx.h"
#include "Graph.h"
#include <cassert>
#include <iostream>


void PrintEdgeList(edge_list& list)
{
	for (size_t i = 0; i < list.size(); ++i)
	{
		std::cout << list[i] << std::endl;
	}
}

int NumEdgesFromProb(const int numVertices, const double prob)
{
	return (numVertices*(numVertices - 1) / 2)*prob;
}

void Graph::validateVertex(const int v) const
{
	assert(v > 0 && v < num_vertices_);
}

Graph::Graph(const int numVertices) : num_vertices_(numVertices), num_edges_(0)
{
	adj_ = new std::vector<int>[numVertices];
}

Graph::Graph(const int numVertices, edge_list& list) : num_vertices_(numVertices), num_edges_(list.size())
{
	adj_ = new std::vector<int>[numVertices];
	for (const auto pair : list)
	{
		addEdge(pair.from, pair.to);
	}
}

Graph::~Graph()
{
	delete[] adj_;
}

int Graph::numEdges() const
{
	return num_edges_;
}

int Graph::numVertices() const
{
	return num_vertices_;
}

int Graph::degree(const int v) const
{
	validateVertex(v);
	return adj_[v].size();
}

void Graph::addEdge(const int from, const int to)
{
	validateVertex(from);
	validateVertex(to);
	adj_[from].push_back(to);
	adj_[to].push_back(from);
	num_edges_++;
}

void Graph::removeEdge(const int from, const int to)
{
	validateVertex(from);
	validateVertex(to);

	const auto it1 = std::find(adj_[from].begin(), adj_[from].end(), to);
	const auto it2 = std::find(adj_[to].begin(), adj_[to].end(), from);

	if (it1 != adj_[from].end() && it2 != adj_[to].end())
	{
		adj_[from].erase(it1);
		adj_[to].erase(it2);
		num_edges_--;
	}
}

edge_list Graph::getEdgeList() const
{

	std::vector<bool> checked(num_vertices_, false);
	edge_list el(num_edges_);

	for (size_t i = 0; i < num_vertices_; ++i)
	{
		if (checked[i])continue;

		
	}

	return el;
}
