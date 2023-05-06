#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID getComponentID() {

	static ComponentID lastID = 0;
	return lastID++;

}

template <typename T> inline ComponentID getComponentID() noexcept {

	static ComponentID typeID = getComponentID();
	return typeID();

}

constexpr std::size_t maxComponents = 32;
using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array < Component*, maxComponents >;

class Component {

public:
	//reference to its owner
	Entity* entity;
	virtual void init() {}
	virtual void update(){}
	virtual void draw(){}
	virtual ~Component(){}
};

class Entity {
public:
	void update() {
		for (auto& c : components) c->update();
		for (auto& c : components) c->draw();
	}

	void draw() {}
	bool isActive() const { return active; }
	void destroy() { active = false; }
private:
	// to remove entity 
	bool active;
	std::vector<std::unique_ptr<Component>> components;
	ComponentArray componentArray;
	ComponentBitSet componentBitSet;
};

// 11:00 minute rewatch for explanation