/*
 * Resource.h
 *
 *  Created on: Oct 5, 2008
 *      Author: swgemu
 */

#ifndef RESOURCEITEMIMPLEMENTATION_H_
#define RESOURCEITEMIMPLEMENTATION_H_

#include "engine/engine.h"

class ResourceItemImplementation : public ResourceItemServant {
private:
	uint64 objectId;
	uint64 spawnId;
	time_t spawnExpireTimestamp;
	string name;
	string type;

	int density;

public:
	ResourceItemImplementation() {
		objectId = 0;
		spawnId = 0;
		name = "";
		type = "";
		density = 0;
	}
	ResourceItemImplementation(uint64 oid, uint64 sid, time_t stamp, const string& n, const string& t, int d) {
		objectId = oid;
		spawnId = sid;
		spawnExpireTimestamp = stamp;
		name = n;
		type = t;
		density = d;
	}

	inline void setObjectID(uint64 oid) {
		objectId = oid;
	}
	inline void setSpawnID(uint64 sid) {
		spawnId = sid;
	}
	inline void setSpawnExpireTimestamp(time_t stamp) {
		spawnExpireTimestamp = stamp;
	}
	inline void setName(const string& n) {
		name = n;
	}
	inline void setType(const string& t) {
		type = t;
	}
	inline void setDensity(int d) {
		density = d;
	}


	inline uint64 getObjectID() {
		return objectId;
	}
	inline uint64 getSpawnID() {
		return spawnId;
	}
	inline time_t getSpawnExpireTimestamp() {
		return spawnExpireTimestamp;
	}
	inline string& getName() {
		return name;
	}
	inline string& getType() {
		return type;
	}
	inline int getDensity() {
		return density;
	}
};

#endif /* RESOURCEITEMIMPLEMENTATION_H_ */
