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
#include "SimpleGG.h"
#include <random>
#include <cassert>
#include <unordered_set>

edge_list SimpleGG::generateGraph(const int numVertices, const double prob)
{
	assert(prob > 0 && prob <= 1);

	edge_list edgeList;

	std::random_device randomDevice;
	std::mt19937 prng(randomDevice());
	const std::bernoulli_distribution bernoulliDistribution(prob);

	for (auto i = 0; i < numVertices; ++i) {
		for (auto j = i + 1; j < numVertices; ++j) {
			if (bernoulliDistribution(prng)) {
				edgeList.push_back({ i,j });
			}
		}
	}

	return edgeList;
}

edge_list SimpleGG::generateGraph(const int numVertices, const int numEdges, const bool parallelEdges)
{
	assert(numEdges <= numEdgesFromProb(numVertices,1));

	edge_list edgeList;
	std::unordered_set<edge,EdgeHash> unqEl;

	std::random_device randomDevice;
	std::mt19937 prng(randomDevice());
	const std::uniform_int_distribution<> uniformIntDistribution(0, numVertices);

	while (edgeList.size() < numEdges)
	{
		const auto from = uniformIntDistribution(prng);
		const auto to = uniformIntDistribution(prng);
		if (from == to) continue;
		if (parallelEdges)
		{
			edgeList.push_back({ from,to });
		}
		else if (unqEl.find({ from,to }) == unqEl.end())
		{
			edgeList.push_back({ from,to });
			unqEl.insert({ from,to });
		}
	}

	return edgeList;
}
