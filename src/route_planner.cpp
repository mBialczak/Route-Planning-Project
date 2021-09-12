#include "route_planner.h"
#include <algorithm>

RoutePlanner::RoutePlanner(RouteModel &model, float start_x, float start_y,
                           float end_x, float end_y)
    : m_Model(model) {
  // Convert inputs to percentage:
  start_x *= 0.01;
  start_y *= 0.01;
  end_x *= 0.01;
  end_y *= 0.01;

  // TODO 2:
  start_node = &m_Model.FindClosestNode(start_x, start_y);
  end_node = &m_Model.FindClosestNode(end_x, end_y);
}

// TODO 3:
float RoutePlanner::CalculateHValue(RouteModel::Node const *node) {
  return node->distance(*end_node);
}

// TODO 4:
void RoutePlanner::AddNeighbors(RouteModel::Node *current_node) {
  current_node->FindNeighbors();
  for (auto neighbour : current_node->neighbors) {
    if (!(neighbour->visited)) {
      neighbour->parent = current_node;
      neighbour->g_value =
          current_node->g_value + neighbour->distance(*current_node);
      neighbour->h_value = CalculateHValue(neighbour);
      AddToOpen(neighbour); // adds to open_list and sets visited = true;
    }
  }
}

// TODO 5: the NextNode method:
//- sorts the open list
//- returns the node the next node with the lowest f-value (g + h)
RouteModel::Node *RoutePlanner::NextNode() {
  std::sort(open_list.begin(), open_list.end(),
            [](const RouteModel::Node *node1, const RouteModel::Node *node2) {
              return (node1->g_value + node1->h_value >
                      node2->g_value + node2->h_value);
            });
  // due to descending order last element has lowest f-value
  RouteModel::Node *best = open_list.back();
  open_list.pop_back();
  return best;
}

void RoutePlanner::AddToOpen(RouteModel::Node *node) {
  open_list.emplace_back(node);
  node->visited = true;
}

// TODO 6:
std::vector<RouteModel::Node>
RoutePlanner::ConstructFinalPath(RouteModel::Node *current_node) {
  // Create path_found vector
  distance = 0.0f;
  std::vector<RouteModel::Node> path_found;
  //  iteratively follow the chain of parents of nodes until the starting node
  //  is found (node without a parent)
  while (current_node->parent) {
    path_found.emplace_back(*current_node);
    distance += current_node->distance(*(current_node->parent));
    current_node = current_node->parent;
  }
  // need to add starting node to the path as well
  path_found.emplace_back(*start_node);
  // put the returned vector in the correct order
  std::reverse(path_found.begin(), path_found.end());
  // Multiply the distance by the scale of the map to get meters.
  distance *= m_Model.MetricScale();
  return path_found;
}

// TODO 7:
void RoutePlanner::AStarSearch() {
  RouteModel::Node *current_node = start_node;
  AddToOpen(current_node);

  while (!open_list.empty()) {
    if (current_node == end_node) {
      m_Model.path = ConstructFinalPath(current_node);
      return;
    }
    current_node = NextNode();
    AddNeighbors(current_node);
  }
}