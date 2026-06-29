#include <iostream>
#include <map>
#include "Schedule.h"

using namespace std;

Schedule::Schedule(string name)
{
    mName = name;
}

bool Schedule::dropCourse(std::string name)
{
    // TO DO: if the course was not already in the map, return false
    // otherwise, remove it from the map and return true!
    if(courseMap.find(name) == courseMap.end()) 
    {
         return false;
    }

    courseMap.erase(name);
    return true;
}


bool Schedule::addCourse(Course* c)
{
    // TO DO: if the course was already in the map, return false
    // otherwise, add it to the map and return true!

     if(courseMap.find(c->getCourseName()) != courseMap.end()) 
     {
        return false;
    }

    courseMap[c->getCourseName()] = c;
    return true;
}

void Schedule::printAllAssignments()
{
    // TO DO: print out the name of each course, followed by the set of assignments.
    // for each assignment, display its name, its type (essay vs hw vs exam), and whether or not it was completed.
    // formatting is up to you, but make sure it's easy to read!
    for(std::map<std::string, Course*>::iterator it = courseMap.begin();
        it != courseMap.end(); ++it)
    {
        std::cout << it->first << std::endl;

        std::set<Assignment*> assignments = it->second->getAssignmentSet();

        for(std::set<Assignment*>::iterator a = assignments.begin();
            a != assignments.end(); ++a)
        {
            std::cout << (*a)->getName() << " "
                      << (*a)->getType() << " ";

            if((*a)->isComplete()) {
                std::cout << "Complete";
            }
            else {
                std::cout << "Incomplete";
            }

            std::cout << std::endl;
        }
    }
}

std::map<std::string, Course*> Schedule::getCourses()
{
    return courseMap;
}