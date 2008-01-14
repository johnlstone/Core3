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
 *	server/zone/objects/tangible/weapons/Weapon.cpp generated by Engine3 IDL compiler 0.51
 */

#include "../../scene/SceneObject.h"

#include "../TangibleObject.h"

#include "../../player/Player.h"

#include "Weapon.h"

#include "WeaponImplementation.h"

/*
 *	WeaponStub
 */

Weapon::Weapon() : TangibleObject(NULL) {
}

Weapon::Weapon(ORBObjectServant* obj) : TangibleObject(obj) {
}

Weapon::Weapon(Weapon& ref) : TangibleObject(ref) {
}

Weapon::~Weapon() {
}

Weapon* Weapon::clone() {
	return new Weapon(*this);
}


void Weapon::sendTo(Player* player, bool doClose) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 6);
		invocation.addObjectParameter(player);
		invocation.addBooleanParameter(doClose);

		invocation.executeWithVoidReturn();
	} else
		((WeaponImplementation*) _impl)->sendTo(player, doClose);
}

void Weapon::generateAttributes(SceneObject* obj) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 7);
		invocation.addObjectParameter(obj);

		invocation.executeWithVoidReturn();
	} else
		((WeaponImplementation*) _impl)->generateAttributes(obj);
}

void Weapon::decayWeapon(int decayRate) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 8);
		invocation.addSignedIntParameter(decayRate);

		invocation.executeWithVoidReturn();
	} else
		((WeaponImplementation*) _impl)->decayWeapon(decayRate);
}

void Weapon::setWeaponStats(int modifier) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 9);
		invocation.addSignedIntParameter(modifier);

		invocation.executeWithVoidReturn();
	} else
		((WeaponImplementation*) _impl)->setWeaponStats(modifier);
}

void Weapon::sliceWeapon(Player* player) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 10);
		invocation.addObjectParameter(player);

		invocation.executeWithVoidReturn();
	} else
		((WeaponImplementation*) _impl)->sliceWeapon(player);
}

bool Weapon::decreaseDot0Uses() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 11);

		return invocation.executeWithBooleanReturn();
	} else
		return ((WeaponImplementation*) _impl)->decreaseDot0Uses();
}

bool Weapon::decreaseDot1Uses() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 12);

		return invocation.executeWithBooleanReturn();
	} else
		return ((WeaponImplementation*) _impl)->decreaseDot1Uses();
}

bool Weapon::decreaseDot2Uses() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 13);

		return invocation.executeWithBooleanReturn();
	} else
		return ((WeaponImplementation*) _impl)->decreaseDot2Uses();
}

bool Weapon::isSliced() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 14);

		return invocation.executeWithBooleanReturn();
	} else
		return ((WeaponImplementation*) _impl)->isSliced();
}

bool Weapon::isJedi() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 15);

		return invocation.executeWithBooleanReturn();
	} else
		return ((WeaponImplementation*) _impl)->isJedi();
}

bool Weapon::isMelee() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 16);

		return invocation.executeWithBooleanReturn();
	} else
		return ((WeaponImplementation*) _impl)->isMelee();
}

bool Weapon::isRanged() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 17);

		return invocation.executeWithBooleanReturn();
	} else
		return ((WeaponImplementation*) _impl)->isRanged();
}

void Weapon::setDot0Uses(int uses) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 18);
		invocation.addSignedIntParameter(uses);

		invocation.executeWithVoidReturn();
	} else
		((WeaponImplementation*) _impl)->setDot0Uses(uses);
}

void Weapon::setDot1Uses(int uses) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 19);
		invocation.addSignedIntParameter(uses);

		invocation.executeWithVoidReturn();
	} else
		((WeaponImplementation*) _impl)->setDot1Uses(uses);
}

void Weapon::setDot2Uses(int uses) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 20);
		invocation.addSignedIntParameter(uses);

		invocation.executeWithVoidReturn();
	} else
		((WeaponImplementation*) _impl)->setDot2Uses(uses);
}

int Weapon::getType() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 21);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getType();
}

int Weapon::getCategory() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 22);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getCategory();
}

int Weapon::getDamageType() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 23);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getDamageType();
}

float Weapon::getMinDamage() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 24);

		return invocation.executeWithFloatReturn();
	} else
		return ((WeaponImplementation*) _impl)->getMinDamage();
}

float Weapon::getMaxDamage() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 25);

		return invocation.executeWithFloatReturn();
	} else
		return ((WeaponImplementation*) _impl)->getMaxDamage();
}

float Weapon::getAttackSpeed() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 26);

		return invocation.executeWithFloatReturn();
	} else
		return ((WeaponImplementation*) _impl)->getAttackSpeed();
}

int Weapon::getHealthAttackCost() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 27);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getHealthAttackCost();
}

int Weapon::getActionAttackCost() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 28);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getActionAttackCost();
}

int Weapon::getMindAttackCost() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 29);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getMindAttackCost();
}

int Weapon::getPointBlankRange() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 30);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getPointBlankRange();
}

int Weapon::getPointBlankAccuracy() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 31);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getPointBlankAccuracy();
}

int Weapon::getMaxRange() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 32);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getMaxRange();
}

int Weapon::getMaxRangeAccuracy() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 33);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getMaxRangeAccuracy();
}

int Weapon::getIdealRange() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 34);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getIdealRange();
}

int Weapon::getIdealAccuracy() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 35);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getIdealAccuracy();
}

int Weapon::getWoundsRatio() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 36);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getWoundsRatio();
}

int Weapon::getArmorPiercing() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 37);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getArmorPiercing();
}

int Weapon::getDot0Type() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 38);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getDot0Type();
}

int Weapon::getDot0Attribute() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 39);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getDot0Attribute();
}

int Weapon::getDot0Strength() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 40);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getDot0Strength();
}

int Weapon::getDot0Duration() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 41);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getDot0Duration();
}

int Weapon::getDot0Potency() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 42);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getDot0Potency();
}

int Weapon::getDot0Uses() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 43);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getDot0Uses();
}

int Weapon::getDot1Type() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 44);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getDot1Type();
}

int Weapon::getDot1Attribute() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 45);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getDot1Attribute();
}

int Weapon::getDot1Strength() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 46);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getDot1Strength();
}

int Weapon::getDot1Duration() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 47);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getDot1Duration();
}

int Weapon::getDot1Potency() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 48);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getDot1Potency();
}

int Weapon::getDot1Uses() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 49);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getDot1Uses();
}

int Weapon::getDot2Type() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 50);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getDot2Type();
}

int Weapon::getDot2Attribute() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 51);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getDot2Attribute();
}

int Weapon::getDot2Strength() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 52);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getDot2Strength();
}

int Weapon::getDot2Duration() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 53);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getDot2Duration();
}

int Weapon::getDot2Potency() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 54);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getDot2Potency();
}

int Weapon::getDot2Uses() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 55);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((WeaponImplementation*) _impl)->getDot2Uses();
}

/*
 *	WeaponAdapter
 */

WeaponAdapter::WeaponAdapter(WeaponImplementation* obj) : TangibleObjectAdapter(obj) {
}

Packet* WeaponAdapter::invokeMethod(uint32 methid, ORBMethodInvocation* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		sendTo((Player*) inv->getObjectParameter(), inv->getBooleanParameter());
		break;
	case 7:
		generateAttributes((SceneObject*) inv->getObjectParameter());
		break;
	case 8:
		decayWeapon(inv->getSignedIntParameter());
		break;
	case 9:
		setWeaponStats(inv->getSignedIntParameter());
		break;
	case 10:
		sliceWeapon((Player*) inv->getObjectParameter());
		break;
	case 11:
		resp->insertBoolean(decreaseDot0Uses());
		break;
	case 12:
		resp->insertBoolean(decreaseDot1Uses());
		break;
	case 13:
		resp->insertBoolean(decreaseDot2Uses());
		break;
	case 14:
		resp->insertBoolean(isSliced());
		break;
	case 15:
		resp->insertBoolean(isJedi());
		break;
	case 16:
		resp->insertBoolean(isMelee());
		break;
	case 17:
		resp->insertBoolean(isRanged());
		break;
	case 18:
		setDot0Uses(inv->getSignedIntParameter());
		break;
	case 19:
		setDot1Uses(inv->getSignedIntParameter());
		break;
	case 20:
		setDot2Uses(inv->getSignedIntParameter());
		break;
	case 21:
		resp->insertSignedInt(getType());
		break;
	case 22:
		resp->insertSignedInt(getCategory());
		break;
	case 23:
		resp->insertSignedInt(getDamageType());
		break;
	case 24:
		resp->insertFloat(getMinDamage());
		break;
	case 25:
		resp->insertFloat(getMaxDamage());
		break;
	case 26:
		resp->insertFloat(getAttackSpeed());
		break;
	case 27:
		resp->insertSignedInt(getHealthAttackCost());
		break;
	case 28:
		resp->insertSignedInt(getActionAttackCost());
		break;
	case 29:
		resp->insertSignedInt(getMindAttackCost());
		break;
	case 30:
		resp->insertSignedInt(getPointBlankRange());
		break;
	case 31:
		resp->insertSignedInt(getPointBlankAccuracy());
		break;
	case 32:
		resp->insertSignedInt(getMaxRange());
		break;
	case 33:
		resp->insertSignedInt(getMaxRangeAccuracy());
		break;
	case 34:
		resp->insertSignedInt(getIdealRange());
		break;
	case 35:
		resp->insertSignedInt(getIdealAccuracy());
		break;
	case 36:
		resp->insertSignedInt(getWoundsRatio());
		break;
	case 37:
		resp->insertSignedInt(getArmorPiercing());
		break;
	case 38:
		resp->insertSignedInt(getDot0Type());
		break;
	case 39:
		resp->insertSignedInt(getDot0Attribute());
		break;
	case 40:
		resp->insertSignedInt(getDot0Strength());
		break;
	case 41:
		resp->insertSignedInt(getDot0Duration());
		break;
	case 42:
		resp->insertSignedInt(getDot0Potency());
		break;
	case 43:
		resp->insertSignedInt(getDot0Uses());
		break;
	case 44:
		resp->insertSignedInt(getDot1Type());
		break;
	case 45:
		resp->insertSignedInt(getDot1Attribute());
		break;
	case 46:
		resp->insertSignedInt(getDot1Strength());
		break;
	case 47:
		resp->insertSignedInt(getDot1Duration());
		break;
	case 48:
		resp->insertSignedInt(getDot1Potency());
		break;
	case 49:
		resp->insertSignedInt(getDot1Uses());
		break;
	case 50:
		resp->insertSignedInt(getDot2Type());
		break;
	case 51:
		resp->insertSignedInt(getDot2Attribute());
		break;
	case 52:
		resp->insertSignedInt(getDot2Strength());
		break;
	case 53:
		resp->insertSignedInt(getDot2Duration());
		break;
	case 54:
		resp->insertSignedInt(getDot2Potency());
		break;
	case 55:
		resp->insertSignedInt(getDot2Uses());
		break;
	default:
		return NULL;
	}

	return resp;
}

void WeaponAdapter::sendTo(Player* player, bool doClose) {
	return ((WeaponImplementation*) impl)->sendTo(player, doClose);
}

void WeaponAdapter::generateAttributes(SceneObject* obj) {
	return ((WeaponImplementation*) impl)->generateAttributes(obj);
}

void WeaponAdapter::decayWeapon(int decayRate) {
	return ((WeaponImplementation*) impl)->decayWeapon(decayRate);
}

void WeaponAdapter::setWeaponStats(int modifier) {
	return ((WeaponImplementation*) impl)->setWeaponStats(modifier);
}

void WeaponAdapter::sliceWeapon(Player* player) {
	return ((WeaponImplementation*) impl)->sliceWeapon(player);
}

bool WeaponAdapter::decreaseDot0Uses() {
	return ((WeaponImplementation*) impl)->decreaseDot0Uses();
}

bool WeaponAdapter::decreaseDot1Uses() {
	return ((WeaponImplementation*) impl)->decreaseDot1Uses();
}

bool WeaponAdapter::decreaseDot2Uses() {
	return ((WeaponImplementation*) impl)->decreaseDot2Uses();
}

bool WeaponAdapter::isSliced() {
	return ((WeaponImplementation*) impl)->isSliced();
}

bool WeaponAdapter::isJedi() {
	return ((WeaponImplementation*) impl)->isJedi();
}

bool WeaponAdapter::isMelee() {
	return ((WeaponImplementation*) impl)->isMelee();
}

bool WeaponAdapter::isRanged() {
	return ((WeaponImplementation*) impl)->isRanged();
}

void WeaponAdapter::setDot0Uses(int uses) {
	return ((WeaponImplementation*) impl)->setDot0Uses(uses);
}

void WeaponAdapter::setDot1Uses(int uses) {
	return ((WeaponImplementation*) impl)->setDot1Uses(uses);
}

void WeaponAdapter::setDot2Uses(int uses) {
	return ((WeaponImplementation*) impl)->setDot2Uses(uses);
}

int WeaponAdapter::getType() {
	return ((WeaponImplementation*) impl)->getType();
}

int WeaponAdapter::getCategory() {
	return ((WeaponImplementation*) impl)->getCategory();
}

int WeaponAdapter::getDamageType() {
	return ((WeaponImplementation*) impl)->getDamageType();
}

float WeaponAdapter::getMinDamage() {
	return ((WeaponImplementation*) impl)->getMinDamage();
}

float WeaponAdapter::getMaxDamage() {
	return ((WeaponImplementation*) impl)->getMaxDamage();
}

float WeaponAdapter::getAttackSpeed() {
	return ((WeaponImplementation*) impl)->getAttackSpeed();
}

int WeaponAdapter::getHealthAttackCost() {
	return ((WeaponImplementation*) impl)->getHealthAttackCost();
}

int WeaponAdapter::getActionAttackCost() {
	return ((WeaponImplementation*) impl)->getActionAttackCost();
}

int WeaponAdapter::getMindAttackCost() {
	return ((WeaponImplementation*) impl)->getMindAttackCost();
}

int WeaponAdapter::getPointBlankRange() {
	return ((WeaponImplementation*) impl)->getPointBlankRange();
}

int WeaponAdapter::getPointBlankAccuracy() {
	return ((WeaponImplementation*) impl)->getPointBlankAccuracy();
}

int WeaponAdapter::getMaxRange() {
	return ((WeaponImplementation*) impl)->getMaxRange();
}

int WeaponAdapter::getMaxRangeAccuracy() {
	return ((WeaponImplementation*) impl)->getMaxRangeAccuracy();
}

int WeaponAdapter::getIdealRange() {
	return ((WeaponImplementation*) impl)->getIdealRange();
}

int WeaponAdapter::getIdealAccuracy() {
	return ((WeaponImplementation*) impl)->getIdealAccuracy();
}

int WeaponAdapter::getWoundsRatio() {
	return ((WeaponImplementation*) impl)->getWoundsRatio();
}

int WeaponAdapter::getArmorPiercing() {
	return ((WeaponImplementation*) impl)->getArmorPiercing();
}

int WeaponAdapter::getDot0Type() {
	return ((WeaponImplementation*) impl)->getDot0Type();
}

int WeaponAdapter::getDot0Attribute() {
	return ((WeaponImplementation*) impl)->getDot0Attribute();
}

int WeaponAdapter::getDot0Strength() {
	return ((WeaponImplementation*) impl)->getDot0Strength();
}

int WeaponAdapter::getDot0Duration() {
	return ((WeaponImplementation*) impl)->getDot0Duration();
}

int WeaponAdapter::getDot0Potency() {
	return ((WeaponImplementation*) impl)->getDot0Potency();
}

int WeaponAdapter::getDot0Uses() {
	return ((WeaponImplementation*) impl)->getDot0Uses();
}

int WeaponAdapter::getDot1Type() {
	return ((WeaponImplementation*) impl)->getDot1Type();
}

int WeaponAdapter::getDot1Attribute() {
	return ((WeaponImplementation*) impl)->getDot1Attribute();
}

int WeaponAdapter::getDot1Strength() {
	return ((WeaponImplementation*) impl)->getDot1Strength();
}

int WeaponAdapter::getDot1Duration() {
	return ((WeaponImplementation*) impl)->getDot1Duration();
}

int WeaponAdapter::getDot1Potency() {
	return ((WeaponImplementation*) impl)->getDot1Potency();
}

int WeaponAdapter::getDot1Uses() {
	return ((WeaponImplementation*) impl)->getDot1Uses();
}

int WeaponAdapter::getDot2Type() {
	return ((WeaponImplementation*) impl)->getDot2Type();
}

int WeaponAdapter::getDot2Attribute() {
	return ((WeaponImplementation*) impl)->getDot2Attribute();
}

int WeaponAdapter::getDot2Strength() {
	return ((WeaponImplementation*) impl)->getDot2Strength();
}

int WeaponAdapter::getDot2Duration() {
	return ((WeaponImplementation*) impl)->getDot2Duration();
}

int WeaponAdapter::getDot2Potency() {
	return ((WeaponImplementation*) impl)->getDot2Potency();
}

int WeaponAdapter::getDot2Uses() {
	return ((WeaponImplementation*) impl)->getDot2Uses();
}

/*
 *	WeaponHelper
 */

ORBClassHelper* WeaponHelper::instance = new WeaponHelper();

WeaponHelper::WeaponHelper() {
	className = "Weapon";

	ObjectRequestBroker::instance()->registerClass(className, this);
}

ORBClassHelper* WeaponHelper::getInstance() {
	if (instance == NULL)
		return instance = new WeaponHelper();
	else
		return instance;
}

ORBObject* WeaponHelper::instantiateObject() {
	return new Weapon();
}

ORBObjectAdapter* WeaponHelper::createAdapter(ORBObjectServant* obj) {
	ORBObjectAdapter* adapter = new WeaponAdapter((WeaponImplementation*)obj);

	ORBObjectStub* stub = new Weapon(obj);
	stub->_setORBClassName(className);
	stub->_setClassHelper(this);

	adapter->setStub(stub);

	obj->_setStub(stub);

	return adapter;
}

/*
 *	WeaponServant
 */

WeaponServant::WeaponServant(unsigned long long oid, int tp) : TangibleObjectImplementation(oid, tp) {
	_classHelper = WeaponHelper::getInstance();
}

WeaponServant::WeaponServant(unsigned long long oid, const unicode& name, const string& tempname, unsigned int tempcrc, int tp) : TangibleObjectImplementation(oid, name, tempname, tempcrc, tp) {
	_classHelper = WeaponHelper::getInstance();
}

WeaponServant::~WeaponServant() {
}
void WeaponServant::_setStub(ORBObjectStub* stub) {
	_this = (Weapon*) stub;
	TangibleObjectServant::_setStub(stub);
}

ORBObjectStub* WeaponServant::_getStub() {
	return _this;
}

