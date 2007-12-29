/*
Copyright (C) 2007 <SWGEmu>

This File is part of Core3.

This program is free software; you can redistribute
it and/or modify it under the terms of the GNU Lesser
General Public License as published by the Free Software
Foundation; either version 2 of the License,
or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for
more details.

You should have received a copy of the GNU Lesser General
Public License along with this program; if not, write to
the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Linking Engine3 statically or dynamically with other modules
is making a combined work based on Engine3.
Thus, the terms and conditions of the GNU Lesser General Public License
cover the whole combination.

In addition, as a special exception, the copyright holders of Engine3
give you permission to combine Engine3 program with free software
programs or libraries that are released under the GNU LGPL and with
code included in the standard release of Core3 under the GNU LGPL
license (or modified versions of such code, with unchanged license).
You may copy and distribute such a system following the terms of the
GNU LGPL for Engine3 and the licenses of the other code concerned,
provided that you include the source code of that other code when
and as the GNU LGPL requires distribution of source code.

Note that people who make modified versions of Engine3 are not obligated
to grant this special exception for their modified versions;
it is their choice whether to do so. The GNU Lesser General Public License
gives permission to release a modified version without this exception;
this exception also makes it possible to release a modified version
which carries forward this exception.
*/

/*
 *	server/zone/objects/creature/Creature.h generated by Engine3 IDL compiler 0.51
 */

#ifndef CREATURE_H_
#define CREATURE_H_

#include "engine/orb/ObjectRequestBroker.h"

class CreatureObject;

class CreatureGroup;

class Zone;

class Player;

class LairObject;

#include "CreatureObject.h"

class Creature : public CreatureObject {
public:
	Creature();
	Creature(ORBObjectServant* obj);
	Creature(Creature& ref);

	Creature* clone();

	virtual ~Creature();

	void init();

	void unload();

	void insertToZone(Zone* zone);

	void updateZone();

	void lightUpdateZone();

	void removeFromZone(bool doLock = true);

	void loadItems();

	bool activate();

	bool isActive();

	bool doMovement();

	void doIncapacitate();

	void doStandUp();

	void doAttack(CreatureObject* target, int damage);

	bool attack(CreatureObject* target);

	void activateRecovery();

	bool doRecovery();

	void doStatesRecovery();

	void createLoot();

	void lootCorpse(Player* player);

	void addPatrolPoint(float x, float y, bool doLock = true);

	void resetPatrolPoints(bool doLock = true);

	int compareTo(Creature* creature);

	void setLair(LairObject* Lair);

	void setCreatureGroup(CreatureGroup* group);

	void setObjectFileName(string& name);

	void setType(int tp);

	void setRespawnTimer(unsigned int seconds);

	int getType();

	bool isTrainer();

	bool isRecruiter();

	bool isMount();

	string& getName();

	int getZoneIndex();

	Zone* getZone();

	unsigned long long getNewItemID();

	unsigned int getRespawnTimer();

	LairObject* getLair();

protected:
	string _return_getName;

};

class CreatureImplementation;

class CreatureAdapter : public CreatureObjectAdapter {
public:
	CreatureAdapter(CreatureImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, ORBMethodInvocation* inv);

	void init();

	void unload();

	void insertToZone(Zone* zone);

	void updateZone();

	void lightUpdateZone();

	void removeFromZone(bool doLock);

	void loadItems();

	bool activate();

	bool isActive();

	bool doMovement();

	void doIncapacitate();

	void doStandUp();

	void doAttack(CreatureObject* target, int damage);

	bool attack(CreatureObject* target);

	void activateRecovery();

	bool doRecovery();

	void doStatesRecovery();

	void createLoot();

	void lootCorpse(Player* player);

	void addPatrolPoint(float x, float y, bool doLock);

	void resetPatrolPoints(bool doLock);

	int compareTo(Creature* creature);

	void setLair(LairObject* Lair);

	void setCreatureGroup(CreatureGroup* group);

	void setObjectFileName(string& name);

	void setType(int tp);

	void setRespawnTimer(unsigned int seconds);

	int getType();

	bool isTrainer();

	bool isRecruiter();

	bool isMount();

	string& getName();

	int getZoneIndex();

	Zone* getZone();

	unsigned long long getNewItemID();

	unsigned int getRespawnTimer();

	LairObject* getLair();

protected:
	string _param0_setObjectFileName__string_;
};

class CreatureHelper : public ORBClassHelper {
	static ORBClassHelper* instance;

public:
	CreatureHelper();

	static ORBClassHelper* getInstance();

	ORBObject* instantiateObject();

	ORBObjectAdapter* createAdapter(ORBObjectServant* obj);

};

#include "CreatureObjectImplementation.h"

class CreatureServant : public CreatureObjectImplementation {
public:
	Creature* _this;

public:
	CreatureServant(unsigned long long oid);
	virtual ~CreatureServant();

	void _setStub(ORBObjectStub* stub);
	ORBObjectStub* _getStub();

};

#endif /*CREATURE_H_*/
