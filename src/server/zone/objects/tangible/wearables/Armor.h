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
 *	server/zone/objects/tangible/wearables/Armor.h generated by Engine3 IDL compiler 0.51
 */

#ifndef ARMOR_H_
#define ARMOR_H_

#include "engine/orb/ObjectRequestBroker.h"

class Wearable;

class Player;

class SceneObject;

#include "Wearable.h"

class Armor : public Wearable {
public:
	Armor();
	Armor(ORBObjectServant* obj);
	Armor(Armor& ref);

	Armor* clone();

	virtual ~Armor();

	void sendTo(Player* player, bool doClose = true);

	void generateAttributes(SceneObject* obj);
	
	void setArmorStats(int modifier);

	int getRating();

	int getCondition();

	int getMaxCondition();

	int getHealthEncumbrance();

	int getActionEncumbrance();

	int getMindEncumbrance();

	float getKinetic();

	bool isKineticSpecial();

	float getEnergy();

	bool isEnergySpecial();

	float getElectricity();

	bool isElectricitySpecial();

	float getStun();

	bool isStunSpecial();

	float getBlast();

	bool isBlastSpecial();

	float getHeat();

	bool isHeatSpecial();

	float getCold();

	bool isColdSpecial();

	float getAcid();

	bool isAcidSpecial();

	float getLightSaber();

	bool isLightSaberSpecial();
	
	void setRating(int rat);
	
	void setMaxCondition(int maxCond);

	void setHealthEncumbrance(int healthEnc);

	void setActionEncumbrance(int actionEnc);

	void setMindEncumbrance(int mindEnc);

	void setKinetic(float kin);

	void setKineticIsSpecial(bool kineticSpec);

	void setEnergy(float ene);

	void setEnergyIsSpecial(bool energySpec);

	void setElectricity(float ele);

	void setElectricityIsSpecial(bool electricitySpec);

	void setStun(float stu);

	void setStunIsSpecial(bool stunSpec);

	void setBlast(float blst);

	void setBlastIsSpecial(bool blastSpec);

	void setHeat(float hot);

	void setHeatIsSpecial(bool heatSpec);

	void setCold(float notHot);

	void setColdIsSpecial(bool coldSpec);

	void setAcid(float aci);

	void setAcidIsSpecial(bool acidSpec);

	void setLightSaber(float lightSab);

	void setLightSaberIsSpecial(bool lightSaberSpec);

protected:
};

class ArmorImplementation;

class ArmorAdapter : public WearableAdapter {
public:
	ArmorAdapter(ArmorImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, ORBMethodInvocation* inv);

	void sendTo(Player* player, bool doClose);

	void generateAttributes(SceneObject* obj);
	
	void setArmorStats(int modifier);

	int getRating();

	int getCondition();

	int getMaxCondition();

	int getHealthEncumbrance();

	int getActionEncumbrance();

	int getMindEncumbrance();

	float getKinetic();

	bool isKineticSpecial();

	float getEnergy();

	bool isEnergySpecial();

	float getElectricity();

	bool isElectricitySpecial();

	float getStun();

	bool isStunSpecial();

	float getBlast();

	bool isBlastSpecial();

	float getHeat();

	bool isHeatSpecial();

	float getCold();

	bool isColdSpecial();

	float getAcid();

	bool isAcidSpecial();

	float getLightSaber();

	bool isLightSaberSpecial();
	
	void setRating(int rat);
	
	void setMaxCondition(int maxCond);

	void setHealthEncumbrance(int healthEnc);

	void setActionEncumbrance(int actionEnc);

	void setMindEncumbrance(int mindEnc);

	void setKinetic(float kin);

	void setKineticIsSpecial(bool kineticSpec);

	void setEnergy(float ene);

	void setEnergyIsSpecial(bool energySpec);

	void setElectricity(float ele);

	void setElectricityIsSpecial(bool electricitySpec);

	void setStun(float stu);

	void setStunIsSpecial(bool stunSpec);

	void setBlast(float blst);

	void setBlastIsSpecial(bool blastSpec);

	void setHeat(float hot);

	void setHeatIsSpecial(bool heatSpec);

	void setCold(float notHot);

	void setColdIsSpecial(bool coldSpec);

	void setAcid(float aci);

	void setAcidIsSpecial(bool acidSpec);

	void setLightSaber(float lightSab);

	void setLightSaberIsSpecial(bool lightSaberSpec);

};

class ArmorHelper : public ORBClassHelper {
	static ORBClassHelper* instance;

public:
	ArmorHelper();

	static ORBClassHelper* getInstance();

	ORBObject* instantiateObject();

	ORBObjectAdapter* createAdapter(ORBObjectServant* obj);

};

#include "WearableImplementation.h"

class ArmorServant : public WearableImplementation {
public:
	Armor* _this;

public:
	ArmorServant(unsigned long long oid, unsigned int tempCRC, const unicode& name, const string& tempn, bool eqp);
	ArmorServant(CreatureObject* creature, unsigned int tempCRC, const unicode& n, const string& tempn, bool eqp);
	virtual ~ArmorServant();

	void _setStub(ORBObjectStub* stub);
	ORBObjectStub* _getStub();

};

#endif /*ARMOR_H_*/
