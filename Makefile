
CC=g++ -std=c++2a
CF=-Wall -g
BUILD=build/

Game8: ${BUILD}Game8
	cp ${BUILD}Game8 Game8.app

${BUILD}Game8: Game8/main.cpp ${BUILD}Node8.o ${BUILD}BreadFirstSearch.o ${BUILD}DepthFirstSearch.o ${BUILD}SortFirstSearch.o ${BUILD}SearchFactory.o
	${CC} ${CF} Game8/main.cpp ${BUILD}Node8.o ${BUILD}BreadFirstSearch.o ${BUILD}DepthFirstSearch.o ${BUILD}SortFirstSearch.o ${BUILD}SearchFactory.o -o ${BUILD}Game8

${BUILD}Node8.o: Game8/Node8.cpp core/Node.hpp Game8/Node8.hpp
	${CC} ${CF} -c Game8/Node8.cpp -o ${BUILD}Node8.o

PathPlan: ${BUILD}PathPlan
	cp ${BUILD}PathPlan PathPlan.app

${BUILD}PathPlan: PathPlan/main.cpp ${BUILD}NodePath.o ${BUILD}Map.o ${BUILD}BreadFirstSearch.o ${BUILD}DepthFirstSearch.o ${BUILD}SortFirstSearch.o ${BUILD}SearchFactory.o
	${CC} ${CF} PathPlan/main.cpp ${BUILD}NodePath.o ${BUILD}Map.o ${BUILD}BreadFirstSearch.o ${BUILD}DepthFirstSearch.o ${BUILD}SortFirstSearch.o ${BUILD}SearchFactory.o -o ${BUILD}PathPlan

${BUILD}NodePath.o: PathPlan/NodePath.cpp core/Node.hpp PathPlan/NodePath.hpp PathPlan/Map.hpp
	${CC} ${CF} -c PathPlan/NodePath.cpp -o ${BUILD}NodePath.o

${BUILD}Map.o: PathPlan/Map.cpp PathPlan/Map.hpp
	${CC} ${CF} -c PathPlan/Map.cpp -o ${BUILD}Map.o

# CORE
${BUILD}SearchFactory.o: core/SearchFactory.cpp core/SearchFactory.hpp core/SearchAlgorithm.hpp
	${CC} ${CF} -c core/SearchFactory.cpp -o ${BUILD}SearchFactory.o

${BUILD}BreadFirstSearch.o: core/SearchAlgorithms/BreadFirstSearch.cpp core/Node.hpp core/SearchAlgorithm.hpp core/SearchAlgorithms/BreadFirstSearch.hpp
	${CC} ${CF} -c core/SearchAlgorithms/BreadFirstSearch.cpp -o ${BUILD}BreadFirstSearch.o

${BUILD}DepthFirstSearch.o: core/SearchAlgorithms/DepthFirstSearch.cpp core/Node.hpp core/SearchAlgorithm.hpp core/SearchAlgorithms/DepthFirstSearch.hpp
	${CC} ${CF} -c core/SearchAlgorithms/DepthFirstSearch.cpp -o ${BUILD}DepthFirstSearch.o

${BUILD}SortFirstSearch.o: core/SearchAlgorithms/SortFirstSearch.cpp core/Node.hpp core/SearchAlgorithm.hpp core/SearchAlgorithms/SortFirstSearch.hpp
	${CC} ${CF} -c core/SearchAlgorithms/SortFirstSearch.cpp -o ${BUILD}SortFirstSearch.o

.PHONY: clean
clean:
	rm -fr *.o
	rm -fr build/*