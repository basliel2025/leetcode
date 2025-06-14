#include <iostream>
#include <vector>
#include<map>
#include <set>
#include<queue>
using namespace std;
int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        bool sameStop = false;
        if (source == target) {
            sameStop = true;
        }
        if (sameStop) {
            return 0;
        }
        map<int, vector<int>> stopToRoutes;
        int routeCount = routes.size();
        int i = 0;
        while (i < routeCount) {
            int routeIndex = i;
            int stopCount = routes[routeIndex].size();
            int j = 0;
            while (j < stopCount) {
                int stop = routes[routeIndex][j];
                if (stopToRoutes.find(stop) == stopToRoutes.end()) {
                    stopToRoutes[stop] = vector<int>();
                }
                stopToRoutes[stop].push_back(routeIndex);
                j++;
            }
            i++;
        }

        if (stopToRoutes.find(source) == stopToRoutes.end() || stopToRoutes.find(target) == stopToRoutes.end()) {
            return -1;
        }

        queue<pair<int, int>> bus;
        set<int> visitedStops;
        set<int> visitedRoutes;

        int initialRouteCount = stopToRoutes[source].size();
        int k = 0;
        while (k < initialRouteCount) {
            int route = stopToRoutes[source][k];
            if (visitedRoutes.find(route) == visitedRoutes.end()) {
                visitedRoutes.insert(route);
                int stopCount = routes[route].size();
                int l = 0;
                while (l < stopCount) {
                    int stop = routes[route][l];
                    if (visitedStops.find(stop) == visitedStops.end()) {
                        visitedStops.insert(stop);
                        bus.push(make_pair(stop, 1));
                    }
                    l++;
                }
            }
            k++;
        }

        while (bus.size()==0 == false) {
            pair<int, int> current = bus.front();
            bus.pop();
            int currentStop = current.first;
            int busCount = current.second;

            if (currentStop == target) {
                return busCount;
            }

            vector<int> connectedRoutes = stopToRoutes[currentStop];
            int m = 0;
            while (m < connectedRoutes.size()) {
                int route = connectedRoutes[m];
                if (visitedRoutes.find(route) == visitedRoutes.end()) {
                    visitedRoutes.insert(route);
                    int stopCount = routes[route].size();
                    int n = 0;
                    while (n < stopCount) {
                        int nextStop = routes[route][n];
                        if (visitedStops.find(nextStop) == visitedStops.end()) {
                            visitedStops.insert(nextStop);
                            bus.push({nextStop, busCount + 1});
                        }
                        n++;
                    }
                }
                m++;
            }
        }

        return -1;

    };