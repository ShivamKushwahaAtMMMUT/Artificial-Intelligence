#include<iostream>
#include<queue>
#include<list>
#include<array>
#include<vector>
#include<memory>
#include<stack>

#include"Vertex.h"
#include"SimulatedAnnealing.h"

int main()
{
	/*std::shared_ptr<Vertex> v1 = std::make_shared<Vertex>(1);
	std::shared_ptr<Vertex> v2 = std::make_shared<Vertex>(2);
	std::shared_ptr<Vertex> v3 = std::make_shared<Vertex>(3);
	std::shared_ptr<Vertex> v4 = std::make_shared<Vertex>(4);
	std::shared_ptr<Vertex> v5 = std::make_shared<Vertex>(5);

	v1->addNeighbour(v2);
	v1->addNeighbour(v3);
	v1->addNeighbour(v4);
	v2->addNeighbour(v1);
	v4->addNeighbour(v3);
	v5->addNeighbour(v3);
	v5->addNeighbour(v2);*/

	/*----------------- BFS -----------------*/
	/*std::cout << "------------------------BFS--------------------------" << std::endl;
	std::queue<std::shared_ptr<Vertex>> bfsQueue;
	bfsQueue.push(v5);
	while (!bfsQueue.empty())
	{
		std::shared_ptr<Vertex> temp = bfsQueue.front();
		bfsQueue.pop();
		if (temp->getVisited() == false)
		{
			std::cout << temp->getData() << "  ";
			temp->setVisited(true);
			for (std::shared_ptr<Vertex> v : temp->getNeighbours())
			{
				bfsQueue.push(v);
			}
		}
	}
	std::cout << "\n-----------------------------------------------------" << std::endl;*/
	/*---------------------------------------------------------------*/

	/*------------------------ DFS ----------------------------------*/
	/*std::cout << "------------------------DFS--------------------------" << std::endl;
	std::stack < std::shared_ptr<Vertex>> dfsStack;
	dfsStack.push(v5);
	while (!dfsStack.empty())
	{
		std::shared_ptr<Vertex> temp = dfsStack.top();
		dfsStack.pop();
		if (temp->getVisited() == false)
		{
			std::cout << temp->getData() << "  ";
			temp->setVisited(true);
			for (std::shared_ptr<Vertex> v : temp->getNeighbours())
			{
				dfsStack.push(v);
			}
		}
	}
	std::cout << "\n-----------------------------------------------------" << std::endl;*/
	/*----------------------------------------------------------------------*/

	/*-----------------------Simulated Annealing--------------------------------*/
	std::cout << "--------------------------Simulated Annealing----------------------------" << std::endl;
	SimulatedAnnealing sa;
	double bestCoordX = sa.findOptimum();
	std::cout << "Optimum value is " << sa.f(bestCoordX) << " at " << bestCoordX << std::endl;
	std::cout << "-------------------------------------------------------------------------" << std::endl;

	std::cout << "\n\nPress any key to continue..." << std::endl;
	getchar();
    return 0;
}