#include "Vertex.h"

Vertex::Vertex(int data)
{
	this->data = data;
	this->visited = false;
}

Vertex::~Vertex()
{
}

int Vertex::getData() const
{
	return this->data;
}

void Vertex::setData(int data)
{
	this->data = data;
}

std::vector<std::shared_ptr<Vertex>> Vertex::getNeighbours() const
{
	return this->neighbours;
}

void Vertex::setNeighbours(std::vector<std::shared_ptr<Vertex>> neighbours)
{
	this->neighbours = neighbours;
}

void Vertex::addNeighbour(std::shared_ptr<Vertex> neighbour)
{
	this->neighbours.push_back(neighbour);
}

bool Vertex::getVisited() const
{
	return this->visited;
}

void Vertex::setVisited(bool visited)
{
	this->visited = visited;
}