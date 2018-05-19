#pragma once
#include<iostream>
#include<list>
#include<array>
#include<vector>
#include<queue>
#include<memory>

class Vertex
{
private:
	std::vector<std::shared_ptr<Vertex>> neighbours;
	int data;
	bool visited;

public:
	Vertex(int data);
	int getData() const;
	void setData(int data);
	std::vector<std::shared_ptr<Vertex>> getNeighbours() const;
	void setNeighbours(std::vector<std::shared_ptr<Vertex>> neighbours);
	void addNeighbour(std::shared_ptr<Vertex> neighbour);
	bool getVisited() const;
	void setVisited(bool visited);
	~Vertex();
};