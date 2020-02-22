#include "ObjectManager.h"

ObjectManager::ObjectManager() {

}

ObjectManager::~ObjectManager() {
	for (int i = 0; i < objectLib.size(); i++) {
		delete objectLib[i];
	}
}

ObjectManager* ObjectManager::instance = nullptr;

ObjectManager* ObjectManager::getInstance() {
	if (instance == nullptr) {
		instance = new ObjectManager;
	}
	return instance;
}

std::vector< Object* >& ObjectManager::getLib() {
	return objectLib;
}

Object* ObjectManager::GetObject(std::string ID) {
	for (int i = 0; i < objectLib.size(); i++) {
		if (objectLib[i]->getID() == ID) {
			return objectLib[i];
			break;
		}
	}
}

Object* ObjectManager::AddObject(std::string ID, Mesh* object, bool light) {
	Object* temp = new Object(ID, object, light);
	return temp;
}

Object* ObjectManager::AddObject(std::string ID, Mesh* object, bool light, std::string parentID) {
	Object* parent = this->GetObject(parentID);
	Object* temp = new Object(ID, object, light, parent);
	return temp;
}

void ObjectManager::RemoveObject(std::string ID) {
	for (int i = 0; i < objectLib.size(); i++) {
		if (objectLib[i]->getID() == ID) {
			delete objectLib[i];
			break;
		}
	}
}

void ObjectManager::Update() {
	for (int i = 0; i < objectLib.size(); i++) {
		delete objectLib[i];
	}
	objectLib.clear();
}