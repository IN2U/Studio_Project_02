#ifndef OBJECT_MANAGER_H
#define OBJECT_MANAGER_H

#include "Mesh_Generation/Mesh.h"
#include "Object.h"
#include <vector>
#include <string>

class ObjectManager
{
private:

	static ObjectManager* instance;
	ObjectManager();
	std::vector< Object* > objectLib;

public:

	~ObjectManager();
	static ObjectManager* getInstance();
	Object* getObject(std::string ID);
	std::vector< Object* > &getLib();
	Object* AddObject(std::string ID, Mesh* object, bool light);
	Object* AddObject(std::string ID, Mesh* object, bool light, std::string parentID);
	void RemoveObject(std::string ID);
	void Update();

};
#endif
